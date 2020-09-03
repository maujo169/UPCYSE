#pragma once
#include "LIBRERIAS.h"
using namespace System;
using namespace System::Windows::Forms;
class MUNDO
{
protected:
	JUGADOR* jugador;
	int cant;
	ENEMIGO** enemigos;

	int cant_balas;
	BALA** balasEnems;

	int numENEMIGOS;
	int nALFA, nBETA, nGAMMA;
public:

	MUNDO()
	{
		Random j;
		//JUGADOR
		jugador = new JUGADOR();

		//ENEMIGOS
		cant = 0;
		cant_balas = 0;
		balasEnems = new BALA * [cant_balas];
		enemigos = new ENEMIGO * [cant];
		numENEMIGOS = j.Next(11, 30);
		nALFA = numENEMIGOS / 3;
		nBETA = numENEMIGOS / 3;
		nGAMMA = numENEMIGOS / 3;
		
		AgregarENEMIGOS(1, nALFA);
		AgregarENEMIGOS(2, nBETA);
		AgregarENEMIGOS(3, nGAMMA);
	}
	~MUNDO() {}

	//JUGADOR
	void Disparar()
	{
		jugador->CrearBALA();
	}
	void JugadorMovimiento(Keys key, Graphics^ g)
	{
		if (key == Keys::Up)
		{
			jugador->Mover(DIRECCION::ARRIBA, g);
		}
		if (key == Keys::Down)
		{
			jugador->Mover(DIRECCION::ABAJO, g);
		}
		if (key == Keys::Left)
		{
			jugador->Mover(DIRECCION::IZQUIERDA, g);
		}
		if (key == Keys::Right)
		{
			jugador->Mover(DIRECCION::DERECHA, g);
		}
	}
	void MostrarJugador(Graphics^ g, Bitmap^ imgV)
	{
		jugador->Mostrar(g, imgV);
	}
	void MostrarBalasJugador(Graphics^ g, Bitmap^ imgBala)
	{
		jugador->MostrarBALAS(g, imgBala);
	}
	void MoverBalasJugador()
	{
		jugador->MoverBALAS();
	}

	//ENEMIGOS
	int GetCantEnemigos() { return cant; }
	void SetCantEnemigos(int n) { cant = n; }
	void MoverEnemigos(Graphics^ g, bool visible)
	{
		for (int i = 0; i < cant; i++)
		{
			enemigos[i]->MoverAlfa(g);
			enemigos[i]->MoverBeta(g);
			enemigos[i]->MoverGamma(g, jugador, visible);

		}
	}
	void MostrarEnemigos(Graphics^ g, Bitmap^ imgNormal, Bitmap^ imgBeta,
		Bitmap^ imgInvisible, bool enemVisible, bool enemColor)
	{
		for (int i = 0; i < cant; i++)
		{
			enemigos[i]->Mostrar(g, imgNormal, imgBeta, imgInvisible, enemVisible, enemColor);
		}
	}
	void AgregarENEMIGOS(int id, int n)
	{
		for (int j = 0; j <= n; j++)
		{
			ENEMIGO** aux = new ENEMIGO * [cant + 1];
			for (int i = 0; i < cant; i++)
			{
				aux[i] = enemigos[i];
			}
			aux[cant] = new ENEMIGO(id);
			cant++;
			enemigos = aux;
		}
	}
	void EliminarENEMIGO(int pos)
	{
		ENEMIGO** aux = new ENEMIGO * [cant - 1];
		delete enemigos[pos];
		for (int i = 0; i < pos; i++)
		{
			aux[i] = enemigos[i];
		}
		for (int i = pos; i < cant - 1; i++)
		{
			aux[i] = enemigos[i + 1];
		}
		cant--;
		enemigos = aux;
	}
	void DispararEnemigo()
	{
		for (int j = 0; j < cant; j++)
		{
			BALA** aux = new BALA * [cant_balas + 1];
			int dx = 0, dy = 0;
			switch (enemigos[j]->getDir())
			{
			case DIRECCION::ARRIBA:  dy = -10; break;
			case DIRECCION::ABAJO:   dy = 10; break;
			case DIRECCION::IZQUIERDA:  dx = -10; break;
			case DIRECCION::DERECHA:    dx = 10; break;
			}
			for (int i = 0; i < cant_balas; i++)
			{
				aux[i] = balasEnems[i];
			}
			aux[cant_balas] = new BALA(enemigos[j]->getX(), enemigos[j]->getY(), dx, dy);
			cant_balas++;
			balasEnems = aux;
		}
	}
	void EliminarBalaEnemigo(int pos)
	{
		BALA** aux = new BALA * [cant_balas - 1];
		delete balasEnems[pos];
		for (int i = 0; i < pos; i++)
		{
			aux[i] = balasEnems[i];
		}
		for (int i = pos; i < cant_balas - 1; i++)
		{
			aux[i] = balasEnems[i + 1];
		}
		cant_balas--;
		balasEnems = aux;
	}
	void MostrarBalasEnemigo(Graphics^ g, Bitmap^ bit)
	{
		for (int i = 0; i < cant_balas; i++)
		{
			balasEnems[i]->Mostrar(g, bit);
		}
	}
	void MoverBalasEnemigo()
	{
		for (int i = 0; i < cant_balas; i++)
		{
			balasEnems[i]->Mover();
		}
	}
	int GetCantBalas() { return cant_balas; }

	void Ganar(Graphics^ g, Bitmap^ img)
	{
		jugador->Mostrar(g, img);
		jugador->MoverGanar(g);
	}

	//COLISIONES
	//Enemigos con Jugador
	bool ColisionExJ(bool jugVISIBLE)
	{
		bool verificar = false;
		Rectangle personaje = Rectangle(jugador->getX(), jugador->getY(), jugador->getANCHO(),
			jugador->getLARGO());
		Rectangle enems;
		for (int i = 0; i < cant; i++)
		{
			enems = Rectangle(enemigos[i]->getX(), enemigos[i]->getY(), enemigos[i]->getANCHO(),
				enemigos[i]->getLARGO());
			if (personaje.IntersectsWith(enems))
			{
				if (jugVISIBLE)
				{
					verificar = true;
					if (jugador->getX() > 400)
						jugador->setX(100);
					else
						jugador->setX(700);
					jugador->setY(320);
				}
				else
					verificar = false;
			}
		}
		return verificar;
	}

	//BalasJugador con Enemigos
	bool ColisionBxE(bool enemVISIBLE)
	{
		Rectangle bala;
		Rectangle enems;
		BALA* b;
		bool verificar = false;
	inicio:
		for (int i = 0; i < jugador->GetCantBALAS(); i++)
		{
			b = jugador->getBALA(i);
			bala = Rectangle(b->getX(), b->getY(), b->getANCHO(), b->getLARGO());
			for (int j = 0; j < cant; j++)
			{
				enems = Rectangle(enemigos[j]->getX(), enemigos[j]->getY(), enemigos[j]->getANCHO(),
					enemigos[j]->getLARGO());

				if (bala.IntersectsWith(enems))
				{
					if (enemigos[j]->getID() == 3 && enemVISIBLE)
					{
						EliminarENEMIGO(j);
						jugador->EliminarBALA(i);
						verificar = true;
						goto inicio;
					}
					else
					{
						verificar = false;
					}
					if (enemigos[j]->getID() == 2 || enemigos[j]->getID() == 1)
					{
						EliminarENEMIGO(j);
						jugador->EliminarBALA(i);
						verificar = true;
						goto inicio;
					}
				}
			}
		}
		return verificar;
	}

	//Jugador con Balas de Enemigo
	bool ColisionJxBE(bool jugVISIBLE)
	{
		bool verificar = false;
		Rectangle bE;
		Rectangle jug = Rectangle(jugador->getX(), jugador->getY(),
			jugador->getANCHO(), jugador->getLARGO());
		for (int i = 0; i < cant_balas; i++)
		{
			bE = Rectangle(balasEnems[i]->getX(), balasEnems[i]->getY(),
				balasEnems[i]->getANCHO(), balasEnems[i]->getLARGO());
			if (jug.IntersectsWith(bE))
			{
				if (jugVISIBLE)
				{
					jugador->setX(150);
					jugador->setY(320);
					verificar = true;
				}
				else
				{
					verificar = false;
				}

			}
		}
		return verificar;
	}

	//Funcion valida solo para NIVEL 2 para que el jugador pueda recoger los desechos
	//del gato y asi ganar el juego
	bool RecogerCaca()
	{
		bool verificar = false;
		Rectangle recg; Rectangle caca;
		recg = Rectangle(jugador->getX(), jugador->getY(), jugador->getANCHO(),
			jugador->getLARGO());
	inicio:
		for (int i = 0; i < cant_balas; i++)
		{
			caca = Rectangle(balasEnems[i]->getX(), balasEnems[i]->getY(),
				balasEnems[i]->getANCHO(), balasEnems[i]->getLARGO());
			if (recg.IntersectsWith(caca))
			{
				EliminarBalaEnemigo(i);
				verificar = true;
				goto inicio;
			}
		}
		return verificar;
	}

	void EliminarDesechosFueraDeLaVentana(Graphics^ g)
	{
		for (int i = 0; i < cant_balas; i++)
		{
			if (balasEnems[i]->getX() - balasEnems[i]->getVX() < 0 ||
				balasEnems[i]->getX() + balasEnems[i]->getVX() + balasEnems[i]->getANCHO() > g->VisibleClipBounds.Width ||
				balasEnems[i]->getY() - balasEnems[i]->getVY() < 0 ||
				balasEnems[i]->getY() + balasEnems[i]->getVY() + balasEnems[i]->getLARGO() > g->VisibleClipBounds.Height)
			{
				EliminarBalaEnemigo(i);
			}
		}
	}

};

