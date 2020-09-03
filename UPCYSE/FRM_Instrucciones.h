#pragma once

namespace UPCYSE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FRM_Instrucciones : public System::Windows::Forms::Form
	{
	public:
		FRM_Instrucciones(void)
		{
			InitializeComponent();
		}

	protected:
		~FRM_Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblInstrucciones;
	private: System::Windows::Forms::Button^ btnComenzar;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblMundo3;
	private: System::Windows::Forms::Label^ lblMundo2;
	private: System::Windows::Forms::Label^ lblMundo1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FRM_Instrucciones::typeid));
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->btnComenzar = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblMundo3 = (gcnew System::Windows::Forms::Label());
			this->lblMundo2 = (gcnew System::Windows::Forms::Label());
			this->lblMundo1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->AutoSize = true;
			this->lblInstrucciones->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInstrucciones->ForeColor = System::Drawing::Color::Yellow;
			this->lblInstrucciones->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->lblInstrucciones->Location = System::Drawing::Point(32, 22);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(364, 107);
			this->lblInstrucciones->TabIndex = 5;
			this->lblInstrucciones->Text = resources->GetString(L"lblInstrucciones.Text");
			// 
			// btnComenzar
			// 
			this->btnComenzar->BackColor = System::Drawing::SystemColors::Control;
			this->btnComenzar->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnComenzar->Location = System::Drawing::Point(495, 476);
			this->btnComenzar->Name = L"btnComenzar";
			this->btnComenzar->Size = System::Drawing::Size(159, 41);
			this->btnComenzar->TabIndex = 9;
			this->btnComenzar->Text = L"COMENZAR";
			this->btnComenzar->UseVisualStyleBackColor = false;
			this->btnComenzar->Click += gcnew System::EventHandler(this, &FRM_Instrucciones::btnComenzar_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(260, 398);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(395, 52);
			this->label3->TabIndex = 15;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(260, 278);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(406, 78);
			this->label2->TabIndex = 14;
			this->label2->Text = resources->GetString(L"label2.Text");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(260, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(394, 78);
			this->label1->TabIndex = 13;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// lblMundo3
			// 
			this->lblMundo3->AutoSize = true;
			this->lblMundo3->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMundo3->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->lblMundo3->Location = System::Drawing::Point(27, 409);
			this->lblMundo3->Name = L"lblMundo3";
			this->lblMundo3->Size = System::Drawing::Size(191, 25);
			this->lblMundo3->TabIndex = 12;
			this->lblMundo3->Text = L"MUNDO CRIMINAL";
			// 
			// lblMundo2
			// 
			this->lblMundo2->AutoSize = true;
			this->lblMundo2->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMundo2->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblMundo2->Location = System::Drawing::Point(27, 288);
			this->lblMundo2->Name = L"lblMundo2";
			this->lblMundo2->Size = System::Drawing::Size(211, 50);
			this->lblMundo2->TabIndex = 11;
			this->lblMundo2->Text = L"MUNDO SALVEMOS\r\nAL MEDIO AMBIENTE";
			this->lblMundo2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblMundo1
			// 
			this->lblMundo1->AutoSize = true;
			this->lblMundo1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMundo1->ForeColor = System::Drawing::Color::Red;
			this->lblMundo1->Location = System::Drawing::Point(27, 181);
			this->lblMundo1->Name = L"lblMundo1";
			this->lblMundo1->Size = System::Drawing::Size(200, 25);
			this->lblMundo1->TabIndex = 10;
			this->lblMundo1->Text = L"MUNDO CORRUPTO";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(420, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(48, 50);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Q";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(420, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(48, 50);
			this->button2->TabIndex = 17;
			this->button2->Text = L"W";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DarkViolet;
			this->label4->Location = System::Drawing::Point(511, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 25);
			this->label4->TabIndex = 18;
			this->label4->Text = L"DISPARAR";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkViolet;
			this->label5->Location = System::Drawing::Point(474, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 25);
			this->label5->TabIndex = 19;
			this->label5->Text = L"RECOGER (NIVEL 2)";
			// 
			// FRM_Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(683, 539);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMundo3);
			this->Controls->Add(this->lblMundo2);
			this->Controls->Add(this->lblMundo1);
			this->Controls->Add(this->btnComenzar);
			this->Controls->Add(this->lblInstrucciones);
			this->Name = L"FRM_Instrucciones";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"INSTRUCCIONES";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnComenzar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}
