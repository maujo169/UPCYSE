#pragma once

enum DIRECCION
{
	ARRIBA,
	ABAJO,
	IZQUIERDA,
	DERECHA
};

using namespace System;
using namespace System::Drawing;

class BASE
{
protected:
	int x, y, vx, vy, largo, ancho, fila, columna;
	DIRECCION d;
public:
	BASE() {}
	~BASE() {}

	int getX() { return x; }
	int getY() { return y; }
	int getVX() { return vx; }
	int getVY() { return vy; }
	int getLARGO() { return largo; }
	int getANCHO() { return ancho; }
	int getFILA() { return fila; }
	int getCOLUMNA() { return columna; }
	DIRECCION getDir() { return d; }

	void setX(int n) { x = n; }
	void setY(int n) { y = n; }
	void setVX(int n) { vx = n; }
	void setVY(int n) { vy = n; }
	void setLARGO(int n) { largo = n; }
	void setANCHO(int n) { ancho = n; }
	void setFILA(int n) { fila = n; }
	void setCOLUMNA(int n) { columna = n; }

	virtual void Mostrar(Graphics^ g, Bitmap^ bit) {}
	virtual void Mover(Graphics^ g, DIRECCION direccion) {}
};

