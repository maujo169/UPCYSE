#pragma once
#include "LIBRERIAS.h"
class ENEMIGO :
	public BASE
{
private:
	int id;
	int dir;
	BALA** balas;
	DIRECCION direccion;
	int cant;
public:
	ENEMIGO(int _id)
	{
		id = _id;
		Random j;
		ancho = 45;
		largo = 45;
		vx = vy = 5;
		x = j.Next(250, 600) - vx - ancho;
		System::Threading::Thread::Sleep(50);
		y = j.Next(130, 600) - vy - largo;
		System::Threading::Thread::Sleep(50);
		fila = columna = 0;
		dir = 1;
	}
	~ENEMIGO() {}

	int getID() { return id; }
	void setID(int n) { id = n; }
	int getDIR() { return dir; }
	void setDIR(int n) { dir = n; }

	void Mostrar(Graphics^ g, Bitmap^ bitNormal, Bitmap^ bitBeta,
		Bitmap^ bitInvisible, bool visible, bool betaNormal)
	{
		if (id == 3) // GAMMA
		{
			if (visible == true)
			{
				largo = bitNormal->Height / 4;
				ancho = bitNormal->Width / 3;
				Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
				largo = 50;
				ancho = 50;
				Rectangle TAM = Rectangle(x, y, ancho, largo);
				bitNormal->MakeTransparent(bitNormal->GetPixel(0, 0));
				g->DrawImage(bitNormal, TAM, molde, GraphicsUnit::Pixel);
			}
			else
			{
				largo = bitInvisible->Height / 4;
				ancho = bitInvisible->Width / 3;
				Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
				largo = 50;
				ancho = 50;
				Rectangle TAM = Rectangle(x, y, ancho, largo);
				bitInvisible->MakeTransparent(bitInvisible->GetPixel(0, 0));
				g->DrawImage(bitInvisible, TAM, molde, GraphicsUnit::Pixel);
			}
		}
		if (id == 2) // BETA
		{
			if (betaNormal)
			{
				largo = bitNormal->Height / 4;
				ancho = bitNormal->Width / 3;
				Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
				largo = 50;
				ancho = 50;
				Rectangle TAM = Rectangle(x, y, ancho, largo);
				bitNormal->MakeTransparent(bitNormal->GetPixel(0, 0));
				g->DrawImage(bitNormal, TAM, molde, GraphicsUnit::Pixel);
			}
			else
			{
				largo = bitBeta->Height / 4;
				ancho = bitBeta->Width / 3;
				Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
				largo = 50;
				ancho = 50;
				Rectangle TAM = Rectangle(x, y, ancho, largo);
				bitBeta->MakeTransparent(bitBeta->GetPixel(0, 0));
				g->DrawImage(bitBeta, TAM, molde, GraphicsUnit::Pixel);
			}
		}
		if (id == 1)
		{
			largo = bitNormal->Height / 4;
			ancho = bitNormal->Width / 3;
			Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
			largo = 50;
			ancho = 50;
			Rectangle TAM = Rectangle(x, y, ancho, largo);
			bitNormal->MakeTransparent(bitNormal->GetPixel(0, 0));
			g->DrawImage(bitNormal, TAM, molde, GraphicsUnit::Pixel);
		}
		columna++;
		if (columna == 3)
		{
			columna = 0;
		}
	}
	void Mover(DIRECCION direccion, Graphics^ g)
	{
		switch (direccion)
		{
		case ARRIBA:
			y -= vy;
			fila = 3;
			this->direccion = DIRECCION::ARRIBA;
			d = DIRECCION::ARRIBA;
			break;
		case ABAJO:
			y += vy;
			fila = 0;
			this->direccion = DIRECCION::ABAJO;
			d = DIRECCION::ABAJO;
			break;
		case IZQUIERDA:
			x -= vx;
			fila = 1;
			this->direccion = DIRECCION::IZQUIERDA;
			d = DIRECCION::IZQUIERDA;
			break;
		case DERECHA:
			x += vx;
			fila = 2;
			this->direccion = DIRECCION::DERECHA;
			d = DIRECCION::DERECHA;
			break;
		default:
			break;
		}
	}
	void MoverAlfa(Graphics^ g)
	{
		if (id == 1)
		{
			if (dir == 0)
			{
				x += vx;
				fila = 2;
				d = DIRECCION::DERECHA;
				if (x + vx + ancho > g->VisibleClipBounds.Width)
				{
					dir = 1;
				}
			}
			else if (dir == 1)
			{
				x -= vx;
				fila = 1;
				d = DIRECCION::IZQUIERDA;
				if (x - vx < 0)
				{
					dir = 0;
				}
			}
		}
	}
	void MoverBeta(Graphics^ g)
	{
		if (id == 2)
		{
			if (dir == 0)
			{
				y += vy;
				fila = 0;
				d = DIRECCION::ABAJO;
				if (y + vy + largo > g->VisibleClipBounds.Height)
				{
					dir = 1;
				}
			}
			else if (dir == 1)
			{
				y -= vy;
				fila = 3;
				d = DIRECCION::ARRIBA;
				if (y - vy < 0)
				{
					dir = 0;
				}
			}
		}
	}
	void MoverGamma(Graphics^ g, JUGADOR* periodista, bool visible)
	{
		if (id == 3)
		{
			if (visible)
			{
				if (x > periodista->getX())
				{
					Mover(DIRECCION::IZQUIERDA, g);
				}
				else if (x < periodista->getX())
				{
					Mover(DIRECCION::DERECHA, g);
				}

				if (y > periodista->getY())
				{
					Mover(DIRECCION::ARRIBA, g);
				}
				else if (y < periodista->getY())
				{
					Mover(DIRECCION::ABAJO, g);
				}
			}
			else
			{
				if (x < periodista->getX())
				{
					Mover(DIRECCION::IZQUIERDA, g);
				}
				else if (x > periodista->getX())
				{
					Mover(DIRECCION::DERECHA, g);
				}

				if (y < periodista->getY())
				{
					Mover(DIRECCION::ARRIBA, g);
				}
				else if (y > periodista->getY())
				{
					Mover(DIRECCION::ABAJO, g);
				}

			}
		}
	}
};
