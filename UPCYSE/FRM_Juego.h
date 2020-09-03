#pragma once
#include "AJUSTES.h"
#include "MUNDO.h"
#include "FRM_Instrucciones.h"
#include "iostream"

namespace UPCYSE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FRM_Juego : public System::Windows::Forms::Form
	{
	public:
		FRM_Juego(void)
		{
			InitializeComponent();
			ajustes = new AJUSTES();
			vidas = 0;
			indice = 0;
			tiempoMIN = 0;
			tiempoVisibleJug = 0;
			tiempoVisibleEnem = 0;
			tiempoColorEnemBeta = 0;
			a = 0;

			//LIENZO
			canvas = this->CreateGraphics();

			//SANGRE
			finJUEGO = gcnew Bitmap("FIN_JUEGO.jpg");

			//NIVEL 1
			mundo1 = new MUNDO();
			jugador = gcnew Bitmap("Jugador.png");
			jugadorInvisible = gcnew Bitmap("JugadorInvisible.png");
			policia = gcnew Bitmap("Policia.png"); // Policias Enemigos
			policiaBeta = gcnew Bitmap("PoliciaBeta.png"); // Policia Beta Color Distinto
			policiaGammaInvisible = gcnew Bitmap("PoliciaGammaInvisible.png"); // Policia Gamma Invisible
			balaJug = gcnew Bitmap("Bala.png"); // Balas jugador
			balaEnem = gcnew Bitmap("balaEnem.png"); //Balas enemigo

			//NIVEL 2
			mundo2 = new MUNDO();
			fondo = gcnew Bitmap("fondo.png");
			jugador2 = gcnew Bitmap("jugador2.png");
			jugadorInvisible2 = gcnew Bitmap("jugadorInvisible2.png");
			gato = gcnew Bitmap("gato.png");
			gatoBeta = gcnew Bitmap("gatoBeta.png");
			gatoGammaInvisible = gcnew Bitmap("gatoGammaInvisible.png");
			balaJug2 = gcnew Bitmap("balaJug2.png");
			balaEnem2 = gcnew Bitmap("balaEnem2.png");

			//NIVEL 3
			mundo3 = new MUNDO();
			fondoCriminal = gcnew Bitmap("PrisonMap.png");
			jugador3 = gcnew Bitmap("jugador3.png");
			jugadorInvisible3 = gcnew Bitmap("jugadorInvisible3.png");
			balaJug3 = gcnew Bitmap("balaJug3.png");
		}

	protected:
		
		~FRM_Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

		//LIENZO
		Graphics^ canvas;
		BufferedGraphicsContext^ espacioBuffer;
		BufferedGraphics^ buffer;

		//INFO JUEGO
		String^ strP;
		String^ valP;
		String^ strV;
		String^ valV;
		String^ strT;
		String^ valT;

		//AJUSTES JUEGO
		AJUSTES* ajustes;
		int vidas;
		int indice;
		int tiempoMIN;
		int seg = 590;
		bool morir = true;
		bool jugVISIBLE = true;
		bool enemVISIBLE = true;
		bool enemColor = true;

		int cantEnemigosMundo2;

		//INVISIBILIDAD, DISPAROS random
		Random r;
		int tiempoVisibleEnem;
		int tiempoVisibleJug;
		int tiempoColorEnemBeta;
		int a;

		//SANGRE NIVEL 1 y 3
		Bitmap^ finJUEGO;

		//NIVEL 1
		MUNDO* mundo1;
		Bitmap^ jugador;
		Bitmap^ jugadorInvisible;
		Bitmap^ policia;
		Bitmap^ policiaBeta;
		Bitmap^ policiaGammaInvisible;
		Bitmap^ balaJug;
		Bitmap^ balaEnem;

		//NIVEL 2
		MUNDO* mundo2;
		Bitmap^ fondo;
		Bitmap^ jugador2;
		Bitmap^ jugadorInvisible2;
		Bitmap^ gato;
		Bitmap^ gatoBeta;
		Bitmap^ gatoGammaInvisible;
		Bitmap^ balaJug2;
		Bitmap^ balaEnem2;
		int z;
		int b;


		//NIVEL 3
		MUNDO* mundo3;
		Bitmap^ fondoCriminal;
		Bitmap^ jugador3;
		Bitmap^ jugadorInvisible3;
		Bitmap^ balaJug3;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ TBXVidas;
	private: System::Windows::Forms::TextBox^ TBXTiempo;
	private: System::Windows::Forms::ComboBox^ cboxDIFICULTAD;
	private: System::Windows::Forms::Button^ btnINICIAR;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ lblVIDAS;
	private: System::Windows::Forms::Label^ lblTIEMPO;
	private: System::Windows::Forms::Timer^ NIVEL1;
	private: System::Windows::Forms::Timer^ NIVEL2;
	private: System::Windows::Forms::Timer^ NIVEL3;
	private: System::Windows::Forms::Timer^ Ganar;
	private: System::Windows::Forms::Label^ lblNIVEL;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FRM_Juego::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TBXVidas = (gcnew System::Windows::Forms::TextBox());
			this->TBXTiempo = (gcnew System::Windows::Forms::TextBox());
			this->cboxDIFICULTAD = (gcnew System::Windows::Forms::ComboBox());
			this->btnINICIAR = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblVIDAS = (gcnew System::Windows::Forms::Label());
			this->lblTIEMPO = (gcnew System::Windows::Forms::Label());
			this->lblNIVEL = (gcnew System::Windows::Forms::Label());
			this->NIVEL1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->NIVEL2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->NIVEL3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Ganar = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(438, 274);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// TBXVidas
			// 
			this->TBXVidas->Location = System::Drawing::Point(564, 85);
			this->TBXVidas->MaxLength = 2;
			this->TBXVidas->Name = L"TBXVidas";
			this->TBXVidas->Size = System::Drawing::Size(100, 20);
			this->TBXVidas->TabIndex = 5;
			this->TBXVidas->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FRM_Juego::TBXVidas_KeyPress);
			// 
			// TBXTiempo
			// 
			this->TBXTiempo->Location = System::Drawing::Point(564, 129);
			this->TBXTiempo->MaxLength = 2;
			this->TBXTiempo->Name = L"TBXTiempo";
			this->TBXTiempo->Size = System::Drawing::Size(100, 20);
			this->TBXTiempo->TabIndex = 6;
			this->TBXTiempo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FRM_Juego::TBXTiempo_KeyPress);
			// 
			// cboxDIFICULTAD
			// 
			this->cboxDIFICULTAD->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboxDIFICULTAD->FormattingEnabled = true;
			this->cboxDIFICULTAD->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Principiante", L"Avanzado" });
			this->cboxDIFICULTAD->Location = System::Drawing::Point(564, 170);
			this->cboxDIFICULTAD->Name = L"cboxDIFICULTAD";
			this->cboxDIFICULTAD->Size = System::Drawing::Size(100, 21);
			this->cboxDIFICULTAD->TabIndex = 7;
			// 
			// btnINICIAR
			// 
			this->btnINICIAR->BackColor = System::Drawing::SystemColors::Control;
			this->btnINICIAR->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnINICIAR->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 20.25F));
			this->btnINICIAR->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnINICIAR->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnINICIAR->Location = System::Drawing::Point(478, 218);
			this->btnINICIAR->Name = L"btnINICIAR";
			this->btnINICIAR->Size = System::Drawing::Size(190, 58);
			this->btnINICIAR->TabIndex = 8;
			this->btnINICIAR->Text = L"SIGUIENTE";
			this->btnINICIAR->UseVisualStyleBackColor = false;
			this->btnINICIAR->Click += gcnew System::EventHandler(this, &FRM_Juego::btnINICIAR_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 26.25F));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(497, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 44);
			this->label1->TabIndex = 9;
			this->label1->Text = L"UPCYSE";
			// 
			// lblVIDAS
			// 
			this->lblVIDAS->AutoSize = true;
			this->lblVIDAS->Font = (gcnew System::Drawing::Font(L"Cooper Black", 8.25F));
			this->lblVIDAS->ForeColor = System::Drawing::SystemColors::Control;
			this->lblVIDAS->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lblVIDAS->Location = System::Drawing::Point(484, 91);
			this->lblVIDAS->Name = L"lblVIDAS";
			this->lblVIDAS->Size = System::Drawing::Size(46, 13);
			this->lblVIDAS->TabIndex = 10;
			this->lblVIDAS->Text = L"VIDAS";
			// 
			// lblTIEMPO
			// 
			this->lblTIEMPO->AutoSize = true;
			this->lblTIEMPO->Font = (gcnew System::Drawing::Font(L"Cooper Black", 8.25F));
			this->lblTIEMPO->ForeColor = System::Drawing::SystemColors::Control;
			this->lblTIEMPO->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lblTIEMPO->Location = System::Drawing::Point(470, 135);
			this->lblTIEMPO->Name = L"lblTIEMPO";
			this->lblTIEMPO->Size = System::Drawing::Size(88, 13);
			this->lblTIEMPO->TabIndex = 11;
			this->lblTIEMPO->Text = L"TIEMPO(min)";
			// 
			// lblNIVEL
			// 
			this->lblNIVEL->AutoSize = true;
			this->lblNIVEL->Font = (gcnew System::Drawing::Font(L"Cooper Black", 8.25F));
			this->lblNIVEL->ForeColor = System::Drawing::SystemColors::Control;
			this->lblNIVEL->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->lblNIVEL->Location = System::Drawing::Point(475, 177);
			this->lblNIVEL->Name = L"lblNIVEL";
			this->lblNIVEL->Size = System::Drawing::Size(83, 13);
			this->lblNIVEL->TabIndex = 12;
			this->lblNIVEL->Text = L"DIFICULTAD";
			// 
			// NIVEL1
			// 
			this->NIVEL1->Tick += gcnew System::EventHandler(this, &FRM_Juego::NIVEL1_Tick);
			// 
			// NIVEL2
			// 
			this->NIVEL2->Tick += gcnew System::EventHandler(this, &FRM_Juego::NIVEL2_Tick);
			// 
			// NIVEL3
			// 
			this->NIVEL3->Tick += gcnew System::EventHandler(this, &FRM_Juego::NIVEL3_Tick);
			// 
			// Ganar
			// 
			this->Ganar->Tick += gcnew System::EventHandler(this, &FRM_Juego::Ganar_Tick);
			// 
			// FRM_Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(684, 297);
			this->Controls->Add(this->lblNIVEL);
			this->Controls->Add(this->lblTIEMPO);
			this->Controls->Add(this->lblVIDAS);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnINICIAR);
			this->Controls->Add(this->cboxDIFICULTAD);
			this->Controls->Add(this->TBXTiempo);
			this->Controls->Add(this->TBXVidas);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FRM_Juego";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UPCYSE";
			this->Load += gcnew System::EventHandler(this, &FRM_Juego::FRM_Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FRM_Juego::FRM_Juego_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &FRM_Juego::FRM_Juego_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		//Funciones Para Empezar Juego
		void ValidacionDeDatosDePartida()
		{
			if (TBXVidas->Text == "" || TBXTiempo->Text == "")
			{
				MessageBox::Show("Completar datos");
			}
			else
			{
				vidas = Int16::Parse(TBXVidas->Text);
				tiempoMIN = Int64::Parse(TBXTiempo->Text);
				indice = cboxDIFICULTAD->SelectedIndex; // Variable de tipo entero
				if (indice == -1)
				{
					MessageBox::Show("Seleccionar dificultad");
				}
				else
				{
					ajustes->setVIDAS(vidas);
					ajustes->setTIEMPO(tiempoMIN);
					ajustes->setDIFICULTAD(indice);
					ajustes->setMUNDO(1);
					FRM_Instrucciones^ instrucciones = gcnew FRM_Instrucciones();
					instrucciones->ShowDialog();
					delete pictureBox1;
					delete btnINICIAR;
					delete label1;
					delete TBXVidas;
					delete lblVIDAS;
					delete lblTIEMPO;
					delete lblNIVEL;
					delete TBXTiempo;
					delete cboxDIFICULTAD;
				}
			}

			if (ajustes->getMUNDO() == 1)
			{
				this->Width = 800;
				this->Height = 640;
				this->CenterToScreen();
				MessageBox::Show("DERROTA A LOS POLICIAS CORRUPTOS CON LAS PIEDRAS QUE TE HAN SIDO OTORGADAS POR LOS DESARROLLADORES DEL JUEGO");
				NIVEL1->Enabled = true;
			}
		}
		void CrearInfoPartida()
		{
			strP = "PUNTAJE";
			valP = "" + ajustes->getPUNTAJE();
			strV = "VIDAS";
			valV = "" + ajustes->getVIDAS();
		}
		void MostrarInfoPartida()
		{
			this->Text = strV + ": " + valV + "   " + strP + ": " + valP + "   TIEMPO: " + valT;
		}
		bool CalcularTiempo()
		{
			bool verificar = false;
			if (tiempoMIN < 10)
			{
				if (seg / 10 < 10)
				{
					valT = "0" + (tiempoMIN - 1) + " : 0" + seg / 10;
				}
				else
				{
					valT = "0" + (tiempoMIN - 1) + " : " + seg / 10;
				}
			}
			else
			{
				valT = "" + (tiempoMIN - 1) + " : " + seg / 10;
			}
			seg--;
			if (seg / 10 == 0)
			{
				tiempoMIN--;
				seg = 590;
			}
			if (tiempoMIN == 0)
			{
				verificar = true;
			}
			return verificar;
		}
		void ValidacionDeInvisibilidadJugador()
		{
			//JUGADOR INVISIBLE AL HACER 90 PUNTOS
			if (ajustes->getPUNTAJE() == 90 && tiempoVisibleJug < 85)
			{
				jugVISIBLE = (false);
			}
			if (jugVISIBLE == false)
			{
				tiempoVisibleJug++;
			}
			if (tiempoVisibleJug == 85)
			{
				jugVISIBLE = (true);
				tiempoVisibleJug = 0;
			}
		}
		void ValidacionDeInvisibilidadEnemigoGamma(int random)
		{
			//Programar Invisibilidad del Enemigo
			//ENEMIGO GAMMA INVISIBLE EN TIEMPO ALEATORIO
			if (enemVISIBLE)
			{
				tiempoVisibleEnem++;
			}
			if (tiempoVisibleEnem == random)
			{
				enemVISIBLE = false;
				z = r.Next(20, 30);
			}
			if (enemVISIBLE == false)
			{
				tiempoVisibleEnem--;
			}
			if (tiempoVisibleEnem == 0)
			{
				enemVISIBLE = true;
			}
		}
		void ValidacionDeCambioDeColorEnemigoBeta(int random)
		{
			//Programar Invisibilidad del Enemigo
			//ENEMIGO GAMMA INVISIBLE EN TIEMPO ALEATORIO
			if (enemColor)
			{
				tiempoColorEnemBeta++;
			}
			if (tiempoColorEnemBeta == random)
			{
				enemColor = false;
				b = r.Next(5, 10);
			}
			if (enemColor == false)
			{
				tiempoColorEnemBeta--;
			}
			if (tiempoColorEnemBeta == 0)
			{
				enemColor = true;
			}
		}
		void GanarMundo1()
		{
			if (mundo1->GetCantEnemigos() == 0)
			{
				this->SuspendLayout();
				this->BackColor = System::Drawing::Color::Aquamarine;
				this->ResumeLayout(false);
				this->PerformLayout();
				NIVEL1->Enabled = false;
				MessageBox::Show("FELICITACIONES LLEVASTE LAS EVIDENCIAS A UN LUGAR SEGURO, PASASTE AL NIVEL 2");
				NIVEL2->Enabled = true;
				ajustes->setPUNTAJE(0);
				ajustes->setMUNDO(2);
				jugVISIBLE = true;
				enemVISIBLE = true;
				enemColor = true;
				tiempoVisibleJug = 0;
				tiempoVisibleEnem = 0;
				tiempoColorEnemBeta = 0;
			}
		}
		void GanarMundo2()
		{
			if (ajustes->getDIFICULTAD() == 0)
			{
				if (mundo2->GetCantEnemigos() == 0 && mundo2->GetCantBalas() == 0)
				{
					this->SuspendLayout();
					this->BackColor = System::Drawing::Color::Aquamarine;
					this->ResumeLayout(false);
					this->PerformLayout();
					NIVEL2->Enabled = false;
					MessageBox::Show("FELICITACIONES LIMPIASTE EL PARQUE, PASASTE AL NIVEL 3");
					NIVEL3->Enabled = true;
					ajustes->setPUNTAJE(0);
					ajustes->setMUNDO(3);
					jugVISIBLE = true;
					enemVISIBLE = true;
					enemColor = true;
					tiempoVisibleJug = 0;
					tiempoVisibleEnem = 0;
					tiempoColorEnemBeta = 0;
				}
			}
			else
			{
				if (mundo2->GetCantEnemigos() == 0)
				{
					this->SuspendLayout();
					this->BackColor = System::Drawing::Color::Aquamarine;
					this->ResumeLayout(false);
					this->PerformLayout();
					NIVEL2->Enabled = false;
					MessageBox::Show("FELICITACIONES LIMPIASTE EL PARQUE, PASASTE AL NIVEL 3");
					NIVEL3->Enabled = true;
					ajustes->setPUNTAJE(0);
					ajustes->setMUNDO(3);
					jugVISIBLE = true;
					enemVISIBLE = true;
					enemColor = true;
					tiempoVisibleJug = 0;
					tiempoVisibleEnem = 0;
					tiempoColorEnemBeta = 0;
				}
			}
		}
		void GanarMundo3()
		{
			if (mundo3->GetCantEnemigos() == 0)
			{
				this->ResumeLayout(false);
				this->PerformLayout();
				NIVEL3->Enabled = false;
				MessageBox::Show("PASASTE EL NIVEL 3\nFelicidades terminaste el juego!!!!");
				Ganar->Enabled = true;
				this->SuspendLayout();
				this->BackColor = System::Drawing::Color::White;
			}
		}
		void Perder()
		{
			if (ajustes->getVIDAS() == 0)
			{
				NIVEL1->Enabled = false;
				NIVEL2->Enabled = false;
				NIVEL3->Enabled = false;
				MessageBox::Show("PERDISTE");
				this->Close();
			}
		}

		//MUNDO CORRUPTO
		void MostrarLineasPista_Mundo1() //MUNDO 1
		{
			buffer->Graphics->FillRectangle(Brushes::Yellow, 50, 200, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 250, 200, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 450, 200, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 650, 200, 80, 10);

			buffer->Graphics->FillRectangle(Brushes::Yellow, 50, 440, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 250, 440, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 450, 440, 80, 10);
			buffer->Graphics->FillRectangle(Brushes::Yellow, 650, 440, 80, 10);
		}
		void MostrarMundo1()
		{
			MostrarInfoPartida();
			MostrarLineasPista_Mundo1();

			if (jugVISIBLE == true)
				mundo1->MostrarJugador(buffer->Graphics, jugador);
			else
				mundo1->MostrarJugador(buffer->Graphics, jugadorInvisible);

			mundo1->MostrarBalasJugador(buffer->Graphics, balaJug);
			mundo1->MostrarBalasEnemigo(buffer->Graphics, balaEnem);
			mundo1->MostrarEnemigos(buffer->Graphics, policia, policiaBeta,
				policiaGammaInvisible, enemVISIBLE, enemColor);
		}
		void MoverMundo1()
		{
			mundo1->MoverEnemigos(buffer->Graphics, jugVISIBLE);
			mundo1->MoverBalasJugador();
			mundo1->MoverBalasEnemigo();
		}
		void ColisionesMundo1()
		{
			if (mundo1->ColisionBxE(enemVISIBLE))
			{
				ajustes->setPUNTAJE(ajustes->getPUNTAJE() + 10);
			}

			if (mundo1->ColisionExJ(jugVISIBLE))
			{
				_beep(500, 50); _beep(400, 50);
				_beep(300, 50); _beep(200, 50);
				_beep(100, 100);
				ajustes->setVIDAS(ajustes->getVIDAS() - 1);
			}

			if (mundo1->ColisionJxBE(jugVISIBLE))
			{
				_beep(500, 50); _beep(400, 50);
				_beep(300, 50); _beep(200, 50);
				_beep(100, 100);
				ajustes->setVIDAS(ajustes->getVIDAS() - 1);
			}
		}

		//MUNDO SALVEMOS AL MEDIO AMBIENTE
		void MostrarMundo2()
		{
			buffer->Graphics->DrawImage(fondo, 0, 0, 800, 640);
			MostrarInfoPartida();
			if (jugVISIBLE == true)
				mundo2->MostrarJugador(buffer->Graphics, jugador2);
			else
				mundo2->MostrarJugador(buffer->Graphics, jugadorInvisible2);
			mundo2->MostrarBalasJugador(buffer->Graphics, balaJug2);
			mundo2->MostrarBalasEnemigo(buffer->Graphics, balaEnem2);
			mundo2->MostrarEnemigos(buffer->Graphics, gato, gatoBeta,
				gatoGammaInvisible, enemVISIBLE, enemColor);
		}
		void MoverMundo2()
		{
			mundo2->MoverEnemigos(buffer->Graphics, jugVISIBLE);
			mundo2->MoverBalasJugador();
		}
		void ColisionesMundo2()
		{
			if (mundo2->ColisionBxE(enemVISIBLE))
				ajustes->setPUNTAJE(ajustes->getPUNTAJE() + 10);

			if (mundo2->ColisionExJ(jugVISIBLE))
			{
				_beep(500, 50); _beep(400, 50);
				_beep(300, 50); _beep(200, 50);
				_beep(100, 100);
				ajustes->setVIDAS(ajustes->getVIDAS() - 1);
			}
		}

		//MUNDO CRIMINAL
		void MostrarMundo3()
		{
			buffer->Graphics->DrawImage(fondoCriminal, 0, 0, 800, 640);
			MostrarInfoPartida();
			if (jugVISIBLE == true)
				mundo3->MostrarJugador(buffer->Graphics, jugador3);
			else
				mundo3->MostrarJugador(buffer->Graphics, jugadorInvisible3);

			mundo3->MostrarBalasJugador(buffer->Graphics, balaJug3);
			mundo3->MostrarBalasEnemigo(buffer->Graphics, balaEnem);
			mundo3->MostrarEnemigos(buffer->Graphics, policia, policiaBeta,
				policiaGammaInvisible, enemVISIBLE, enemColor);
		}
		void MoverMundo3()
		{
			mundo3->MoverEnemigos(buffer->Graphics, jugVISIBLE);
			mundo3->MoverBalasJugador();
			mundo3->MoverBalasEnemigo();
		}
		void ColisionesMundo3()
		{
			if (mundo3->ColisionBxE(enemVISIBLE))
				ajustes->setPUNTAJE(ajustes->getPUNTAJE() + 10);

			if (mundo3->ColisionExJ(jugVISIBLE))
			{
				_beep(500, 50); _beep(400, 50);
				_beep(300, 50); _beep(200, 50);
				_beep(100, 100);
				ajustes->setVIDAS(ajustes->getVIDAS() - 1);
			}

			if (mundo3->ColisionJxBE(jugVISIBLE))
			{
				_beep(500, 50); _beep(400, 50);
				_beep(300, 50); _beep(200, 50);
				_beep(100, 100);
				ajustes->setVIDAS(ajustes->getVIDAS() - 1);
			}
		}

		private: Void btnINICIAR_Click(Object^ sender, EventArgs^ e) 
		{ ValidacionDeDatosDePartida(); }
		private: Void FRM_Juego_KeyDown(Object^ sender, KeyEventArgs^ e)
		{
			if (ajustes->getMUNDO() == 1)
			{
				mundo1->JugadorMovimiento(e->KeyCode, canvas);
				if (e->KeyCode == Keys::Q)
				{
					_beep(530, 50);
					mundo1->Disparar();
				}	
			}
			if (ajustes->getMUNDO() == 2)
			{
				mundo2->JugadorMovimiento(e->KeyCode, canvas);
				if (e->KeyCode == Keys::Q)
				{
					_beep(530, 50);
					mundo2->Disparar();
				}
				if (e->KeyCode == Keys::W)
				{
					if (mundo2->RecogerCaca())
					{
						_beep(150, 100);
						ajustes->setPUNTAJE(ajustes->getPUNTAJE() + 5);
					}
				}
			}
			if (ajustes->getMUNDO() == 3)
			{
				mundo3->JugadorMovimiento(e->KeyCode, canvas);
				if (e->KeyCode == Keys::Q)
				{
					_beep(530, 50);
					mundo3->Disparar();
				}
			}

			e->SuppressKeyPress = true;

			if (e->KeyCode == Keys::NumPad1)
			{
				ajustes->setMUNDO(1);
				NIVEL1->Enabled = true;
				NIVEL2->Enabled = false;
				NIVEL3->Enabled = false;
				Ganar->Enabled = false;
			}

			if (e->KeyCode == Keys::NumPad2)
			{
				ajustes->setMUNDO(2);
				NIVEL1->Enabled = false;
				NIVEL2->Enabled = true;
				NIVEL3->Enabled = false;
				Ganar->Enabled = false;
			}

			if (e->KeyCode == Keys::NumPad3)
			{
				ajustes->setMUNDO(3);
				NIVEL1->Enabled = false;
				NIVEL2->Enabled = false;
				NIVEL3->Enabled = true;
				Ganar->Enabled = false;
			}
			if (e->KeyCode == Keys::NumPad4)
			{
				ajustes->setMUNDO(4);
				Ganar->Enabled = true;
				NIVEL1->Enabled = false;
				NIVEL2->Enabled = false;
				NIVEL3->Enabled = false;
			}
			if (e->KeyCode == Keys::NumPad5)
			{
				morir = false;
			}
		}
		private: Void NIVEL1_Tick(Object^ sender, EventArgs^ e) 
		{
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);
			CrearInfoPartida();
			if (ajustes->getMUNDO() == 1)
			{
				buffer->Graphics->Clear(Color::Gray);
				ValidacionDeInvisibilidadEnemigoGamma(z);
				ValidacionDeCambioDeColorEnemigoBeta(b);
				MoverMundo1();
				MostrarMundo1();
				if (ajustes->getDIFICULTAD() == 1) // AVANZADA
				{
					a++;
					if (a % 20 == 0)
					{
						System::Threading::Thread::Sleep(50);
						mundo1->DispararEnemigo();
					}
				}
				buffer->Render(canvas);
				ValidacionDeInvisibilidadJugador();
				ColisionesMundo1();
				GanarMundo1();
				if (morir == true)
				{
					Perder();
				}
			}
			if (CalcularTiempo() == true)
			{
				NIVEL1->Stop();
				MessageBox::Show("SE TE ACABO EL TIEMPO");
			}
		}
		private: Void NIVEL2_Tick(Object^ sender, EventArgs^ e) 
		{
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);
			CrearInfoPartida();
			if (ajustes->getMUNDO() == 2)
			{
				ValidacionDeInvisibilidadEnemigoGamma(z);
				ValidacionDeCambioDeColorEnemigoBeta(b);
				MoverMundo2();
				MostrarMundo2();
				a++;
				if (a % 30 == 0)
				{
					mundo2->DispararEnemigo();
					a = 0;
				}
				if (ajustes->getDIFICULTAD() == 1)
				{
					mundo2->MoverBalasEnemigo();
					if (mundo2->ColisionJxBE(jugVISIBLE))
					{
						_beep(500, 100); _beep(400, 100);
						_beep(300, 100); _beep(200, 100);
						_beep(100, 200);
						ajustes->setVIDAS(ajustes->getVIDAS() - 1);
					}
				}
				else if (ajustes->getDIFICULTAD() == 0)
				{
					mundo2->ColisionJxBE(0);
				}
				buffer->Render(canvas);
				ValidacionDeInvisibilidadJugador();
				ColisionesMundo2();
				GanarMundo2();
				mundo2->EliminarDesechosFueraDeLaVentana(buffer->Graphics);
				if (morir == true)
				{
					Perder();
				}
			}
			if (CalcularTiempo() == true)
			{
				NIVEL2->Stop();
				MessageBox::Show("SE TE ACABO EL TIEMPO");
				this->Close();
			}
		}
		private: Void NIVEL3_Tick(Object^ sender, EventArgs^ e) 
		{
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);
			CrearInfoPartida();
			if (ajustes->getMUNDO() == 3)
			{
				buffer->Graphics->Clear(Color::Gray);
				ValidacionDeInvisibilidadEnemigoGamma(z);
				ValidacionDeCambioDeColorEnemigoBeta(b);
				MoverMundo3();
				MostrarMundo3();
				if (ajustes->getDIFICULTAD() == 1) // AVANZADA
				{
					a++;
					if (a % 20 == 0)
					{
						System::Threading::Thread::Sleep(50);
						mundo3->DispararEnemigo();
					}
				}
				buffer->Render(canvas);
				ValidacionDeInvisibilidadJugador();
				ColisionesMundo3();
				GanarMundo3();
				if (morir == true)
				{
					Perder();
				}
			}
			if (CalcularTiempo() == true)
			{
				NIVEL3->Stop();
				MessageBox::Show("SE TE ACABO EL TIEMPO");
			}
		}
		private: Void Ganar_Tick(Object^ sender, EventArgs^ e) 
		{
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);
			CrearInfoPartida();
			buffer->Graphics->DrawImage(finJUEGO, 0, 0, 800, 640);
			MostrarInfoPartida();
			mundo1->Ganar(buffer->Graphics, jugador);
			mundo2->Ganar(buffer->Graphics, jugador2);
			mundo3->Ganar(buffer->Graphics, jugador3);
			buffer->Render(canvas);
		}
		private: Void FRM_Juego_Resize(Object^ sender, EventArgs^ e) 
		{
			canvas = this->CreateGraphics();
		}
		private: Void TBXVidas_KeyPress(Object^ sender, KeyPressEventArgs^ e) 
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		private: Void TBXTiempo_KeyPress(Object^ sender, KeyPressEventArgs^ e) 
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		private: Void FRM_Juego_Load(Object^ sender, EventArgs^ e) 
		{
			z = r.Next(20, 30);
			b = r.Next(10, 20);
		}
	};
}