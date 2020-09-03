#pragma once
#include "LIBRERIAS.h"
class JUGADOR :
	public BASE
{
private:
	DIRECCION direccion;
	BALA** balas;
	int cant;
public:
	JUGADOR()
	{
		x = 150;
		y = 320;
		vx = vy = 15;
		largo = ancho = 45;
		fila = 0; columna = 0;
		cant = 0;
	}
	~JUGADOR() {}

	void CrearBALA()
	{
		BALA** aux = new BALA * [cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = balas[i];

		int dx = 0, dy = 0;
		switch (direccion)
		{
		case DIRECCION::ARRIBA:  dy = -16; break;
		case DIRECCION::ABAJO:   dy = 16; break;
		case DIRECCION::IZQUIERDA:  dx = -16; break;
		case DIRECCION::DERECHA:    dx = 16; break;
		}

		aux[cant] = new BALA(x + ancho / 2, y + largo / 2, dx, dy);
		cant++;
		balas = aux;
	}
	void EliminarBALA(int p)
	{
		BALA** aux = new BALA * [cant - 1];

		delete balas[p];

		for (int i = 0; i < p; i++)
			aux[i] = balas[i];

		for (int i = p; i < cant - 1; i++)
			aux[i] = balas[i + 1];

		cant--;
		balas = aux;
	}
	void MostrarBALAS(Graphics^ g, Bitmap^ bit)
	{
		for (int i = 0; i < cant; i++)
			balas[i]->Mostrar(g, bit);
	}
	void MoverBALAS()
	{
		for (int i = 0; i < cant; i++)
			balas[i]->Mover();
	}

	int GetCantBALAS() { return cant; }
	BALA* getBALA(int i) { return balas[i]; }

	void Mostrar(Graphics^ g, Bitmap^ bitJUGvisible)
	{
		largo = bitJUGvisible->Height / 4;
		ancho = bitJUGvisible->Width / 3;
		Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
		largo = 45;
		ancho = 45;
		Rectangle TAM = Rectangle(x, y, ancho, largo);
		g->DrawImage(bitJUGvisible, TAM, molde, GraphicsUnit::Pixel);
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
			if (y - vy > 0)
			{
				y -= vy;
			}
			this->direccion = DIRECCION::ARRIBA;
			fila = 3;
			break;
		case ABAJO:
			if (y + vy + largo < g->VisibleClipBounds.Height)
			{
				y += vy;
			}
			this->direccion = DIRECCION::ABAJO;
			fila = 0;
			break;
		case IZQUIERDA:
			if (x - vx > 0)
			{
				x -= vx;
			}
			this->direccion = DIRECCION::IZQUIERDA;
			fila = 1;
			break;
		case DERECHA:
			if (x + vx + ancho < g->VisibleClipBounds.Width)
			{
				x += vx;
			}
			this->direccion = DIRECCION::DERECHA;
			fila = 2;
			break;
		default:
			break;
		}
	}
	void MoverGanar(Graphics^ g)
	{
		if (x + vx + ancho > g->VisibleClipBounds.Width || x + vx < 0) vx *= -1;
		if (y + vy + largo > g->VisibleClipBounds.Height || y + vy < 0) vy *= -1;
		x += vx;
		y += vy;
	}
};
