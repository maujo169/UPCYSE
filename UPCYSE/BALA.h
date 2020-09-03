#pragma once
#include "BASE.h"
class BALA :
	public BASE
{
public:
	BALA(int x, int y, int vx, int vy)
	{
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		largo = ancho = 45;
		fila = columna = 0;
	}
	~BALA() {}

	void Mostrar(Graphics^ g, Bitmap^ bit)
	{
		largo = bit->Height;
		ancho = bit->Width;
		Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
		ancho = 35;
		largo = 35;
		Rectangle TAM = Rectangle(x, y, ancho, largo);
		g->DrawImage(bit, TAM, molde, GraphicsUnit::Pixel);
	}
	void Mover()
	{
		x += vx;
		y += vy;
	}
};

