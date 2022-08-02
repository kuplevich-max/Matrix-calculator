#pragma once

#include "Matrixs.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class EquationForm : public Form
{
private:
	Matrixs *mat;
	Form^ form;
	ComboBox^ rows1;
	ComboBox^ colons1;
	ComboBox^ rows2;
	ComboBox^ colons2;
	List<TextBox^>^ textBox1;
	List<TextBox^>^ textBox2;
	List<TextBox^>^ textBox3;
	Button^ Perform;
	ComboBox^ listBox;
	Label^ X;
	Label^ Eq;
	Label^ Res;
	Label^ Det;
	Label^ Rows1;
	Label^ Colons1;
	Label^ Rows2;
	Label^ Colons2;
	Label^ MatrixA;
	Label^ MatrixB;
	Label^ Choose;

public:
	EquationForm();
	Form^ GetForm();
	ComboBox^ ToComboBox(int left, int top);
	TextBox^ ToTextBox(int left, int top);
	Button^ ToButton(int left, int top);
	ComboBox^ ToListBox(int left, int top);
	List<TextBox^>^ TextList(int Rows, int Colons, int left, int top);
	System::Void Rows1_SelectedIndex(System::Object^  sender, System::EventArgs^  e);
	System::Void Colons1_SelectedIndex(System::Object^  sender, System::EventArgs^  e);
	List<TextBox^>^ RemoveList(List<TextBox^>^ list);
	System::Void Colons2_SelectedIndex(System::Object^  sender, System::EventArgs^  e);	
	System::Void ListBox_SelectedIndex(System::Object^  sender, System::EventArgs^  e);
	System::Void EquationForm::Perform_Click(System::Object^  sender, System::EventArgs^  e);
};

