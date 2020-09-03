#pragma once
class AJUSTES
{
private:
	int VIDAS;
	int DIFICULTAD;
	int TiempoMinutos;
	int MUNDO;
	int puntaje;
public:
	AJUSTES()
	{
		MUNDO = 0;
		VIDAS = 0;
		DIFICULTAD = 0; // Si nivel es igual que 0 PRINCIPIANTE
				   // Si nivel es igual que 1 AVANZADO
		TiempoMinutos = 0;
		puntaje = 0;
	}

	~AJUSTES() {}

	int getVIDAS() { return VIDAS; }
	int getDIFICULTAD() { return DIFICULTAD; }
	int getTIEMPO() { return TiempoMinutos; }
	int getMUNDO() { return MUNDO; }
	int getPUNTAJE() { return puntaje; }

	void setVIDAS(int n) { VIDAS = n; }
	void setDIFICULTAD(int n) { DIFICULTAD = n; }
	void setTIEMPO(int n) { TiempoMinutos = n; }
	void setMUNDO(int n) { MUNDO = n; }
	void setPUNTAJE(int n) { puntaje = n; }

};

