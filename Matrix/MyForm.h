#pragma once

#include "Matrixs.h"
#include "EquationForm.h"

namespace Matrix
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		EquationForm^ newForm = gcnew EquationForm();
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::ComboBox^  comboBox1;
		System::Windows::Forms::ComboBox^  comboBox2;
		List<TextBox^> ^textBox;
		System::ComponentModel::BackgroundWorker^  backgroundWorker1;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button3;
		System::Windows::Forms::Button^  button4;
		TextBox^ sign;
		List<TextBox^> ^textBox2;
		System::Windows::Forms::Button^  button5;
		TextBox^ equal;
		List<TextBox^> ^textBox3;
		Form^ form;
		ComboBox^ cmbox1;
		ComboBox^ cmbox2;
		Button^ but;
		int rows;
		int colons;
		System::Windows::Forms::Button^  button6;
		System::Windows::Forms::Button^  button7;
		Label^ lab_1;
		TextBox^ Pow;

		System::Windows::Forms::Button^  button9;
		System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;













	public:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(90, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"„исло строк";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"„исло столбцов";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(110, 69);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(37, 24);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(232, 69);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(37, 24);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 375);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 26);
			this->button1->TabIndex = 4;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 375);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 26);
			this->button2->TabIndex = 5;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(264, 375);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(46, 26);
			this->button3->TabIndex = 6;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(345, 418);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(64, 26);
			this->button4->TabIndex = 7;
			this->button4->Text = L"|A|";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(442, 418);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 25);
			this->button5->TabIndex = 8;
			this->button5->Text = L"=";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(99, 420);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(47, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"k*A";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(178, 420);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(132, 23);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Transponse";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(345, 375);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(64, 26);
			this->button9->TabIndex = 12;
			this->button9->Text = L"A^-1";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(599, 374);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 27);
			this->button8->TabIndex = 13;
			this->button8->Text = L"CE";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(345, 63);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(100, 34);
			this->button10->TabIndex = 14;
			this->button10->Text = L"—оздать";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(519, 414);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(130, 35);
			this->button11->TabIndex = 15;
			this->button11->Text = L"”равнени€";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(442, 374);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(51, 26);
			this->button12->TabIndex = 16;
			this->button12->Text = L"A^n";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 464);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e);
		void Equiality();
		ComboBox^ CMBox(ComboBox^ cmbox, int left);
		void SignInit();
		List<TextBox^>^ NewList(List<TextBox^> ^list, int left, int top);
		System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void butClick(System::Object^  sender, System::EventArgs^  e);
		System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
		void RemoveList(List<TextBox^>^ list);
		TextBox^ Parametrs(TextBox^ T, int top, int left);
		System::Void button10_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void MyForm::BClick(System::Object^  sender, System::EventArgs^  e);
		System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);	
		System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);
		void Delete();
	};
}
