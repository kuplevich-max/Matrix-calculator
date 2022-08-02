#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Matrix;

[STAThread]
void Main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Matrix::MyForm form; //WinFormsTest - имя вашего проекта
	Application::Run(%form);
}

Matrixs *matrix = new Matrixs();

void MyForm::Delete()
{
	RemoveList(textBox3);
	RemoveList(textBox2);
	this->Controls->Remove(lab_1);
	this->Controls->Remove(equal);
	equal = nullptr;
}

System::Void Matrix::MyForm:: MyForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 1; i < 6; i++)
	{
		comboBox1->Items->Add(Convert::ToString(i));
		comboBox2->Items->Add(Convert::ToString(i));
	}
	textBox = gcnew List<TextBox^>;
	textBox2 = gcnew List<TextBox^>;
	textBox3 = gcnew List<TextBox^>;	
}

void MyForm::Equiality()
{
	if (sign->Text == "+" || sign->Text == "-")
	{
		matrix->AddMatrix1(textBox, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
		matrix->AddMatrix2(textBox2, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
		matrix->Perform(sign);
		textBox3 = matrix->Result(textBox3);
	}
	
	if (sign->Text == "*")
	{
		if (textBox2->Count > 1)
		{
			matrix->AddMatrix1(textBox, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
			matrix->AddMatrix2(textBox2, rows, colons);
			matrix->Perform(sign);
			textBox3 = matrix->Result(textBox3);
		}
		else
		{
			matrix->AddMatrix1(textBox, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
			matrix->AddMatrix2(textBox2, 1, 1);
			matrix->Perform(sign);
			textBox3 = matrix->Result(textBox3);
		}
	}
	if (sign->Text == "=")
	{
		matrix->AddMatrix1(textBox, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
		if (textBox3->Count > 1)
		{
			matrix->Transponse();
			textBox3 = matrix->Result(textBox3);
		}
		else
		{		
			textBox3[0]->Text = Convert::ToString(Functions::Determinant(matrix->GetMatrix1()->data, Convert::ToInt32(comboBox1->Text)));
		}
	}
}

TextBox^ MyForm::Parametrs(TextBox^ T, int top, int left)
{
	T->Height = 20;
	T->Width = 20;
	T->Top = top;
	T->Left = left;
	T->Parent = this;
	return T;
}

ComboBox^ MyForm::CMBox(ComboBox^ cmbox, int left)
{
	cmbox->Height = 30;
	cmbox->Width = 40;
	cmbox->Left = left;
	cmbox->Top = 60;
	cmbox->Items->Add("1");
	cmbox->Items->Add("2");
	cmbox->Items->Add("3");
	cmbox->Items->Add("4");
	cmbox->Items->Add("5");
	return cmbox;
}

void MyForm::SignInit()
{
	sign = gcnew TextBox();
	sign->Height = 20;
	sign->Width = 20;
	sign->Left = textBox[textBox->Count - 1]->Left + 30;
	sign->Top = (textBox[textBox->Count - 1]->Top + textBox[0]->Top) / 2;
	sign->Text = "";
	this->Controls->Add(sign);
}

void MyForm::RemoveList(List<TextBox^> ^list)
{
	while (list->Count > 0)
	{
		this->Controls->Remove(list[list->Count - 1]);
		list->RemoveAt(list->Count - 1);
	}
}

List<TextBox^>^ MyForm::NewList(List<TextBox^> ^list, int left, int top)
{
	RemoveList(list);
	if (sign->Text == "+" || sign->Text == "-")
	{
		int i = 0, j = 0;
		while (i < Convert::ToInt32(comboBox1->Text))
		{
			j = 0;
			while (j < Convert::ToInt32(comboBox2->Text))
			{
				TextBox^ T = gcnew TextBox();
				T = Parametrs(T, top + i*25, left + j*25);
				list->Add(T);
				j++;
			}
			i++;
		}
		return list;
	}
	if (sign->Text == "*")
	{
		if (equal == nullptr)
		{
			int i = 0, j = 0;
			while (i < rows)
			{
				j = 0;
				while (j < colons)
				{
					TextBox^ T = gcnew TextBox();
					T = Parametrs(T, top + i*25, left + j*25);
					list->Add(T);
					j++;
				}
				i++;
			}
		}
		else
		{
			if (textBox2->Count == 1)
				colons = Convert::ToInt32(comboBox2->Text);
			int i = 0, j = 0;
			while (i < Convert::ToInt32(comboBox1->Text))
			{
				j = 0;
				while (j < colons) 
				{
					TextBox^ T = gcnew TextBox();
					T = Parametrs(T, top + i*25, left + j*25);
					list->Add(T);
					j++;
				}
				i++;
			}			
		}
		return list;
	}
	if (sign->Text == "=")
	{
		int i = 0, j = 0;
		while (i < Convert::ToInt32(comboBox1->Text))
		{
			j = 0;
			while (j < colons)
			{
				TextBox^ T = gcnew TextBox();
				T = Parametrs(T, top + i*25, left + j*25);
				list->Add(T);
				j++;
			}
			i++;
		}
		return list;
	}
}

System::Void MyForm::button10_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox);
	for (int i = 0; i < Functions::Convertation(comboBox1->Text); i++)
	{
		for (int j = 0; j < Functions::Convertation(comboBox2->Text); j++)
		{
			TextBox^ T = gcnew TextBox();
			T = Parametrs(T, 100 + i*25, 50 + j*25);
			textBox->Add(T);
		}
	}

	SignInit();

}

System::Void MyForm::comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (lab_1 != nullptr) delete lab_1;
	RemoveList(textBox2);
	RemoveList(textBox3);	
	this->Controls->Remove(lab_1);
	int left = 50, top = 100;
	if (comboBox2->Text == "")
	{
		int i = 0;
			RemoveList(textBox);
		while (i < Functions::Convertation(comboBox1->Text))
		{
			TextBox^ T = gcnew TextBox();
			T = Parametrs(T, top + i*25, left);
			textBox->Add(T);
			i++;
		}
	}
	else
	{
		rows = Convert::ToInt32(comboBox1->Text);
		colons = Convert::ToInt32(comboBox2->Text);
		int i = 0, j = 0;
		RemoveList(textBox);
		while (i < Convert::ToInt32(comboBox1->Text))
		{
			j = 0;
			while (j < Convert::ToInt32(comboBox2->Text))
			{
				TextBox^ T = gcnew TextBox();
				T = Parametrs(T, top + i * 25, left + j * 25);
				textBox->Add(T);
				j++;
			}
			i++;
		}
		if (sign == nullptr)
			SignInit();
		else
		{
			sign->Left = textBox[textBox->Count - 1]->Left + 30;
			sign->Top = (textBox[textBox->Count - 1]->Top + textBox[0]->Top) / 2;
		}
	}
}

System::Void MyForm::comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (lab_1 != nullptr) delete lab_1;
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(lab_1);
	int left = 50, top = 100;
	if (comboBox1->Text == "")
	{
		int i = 0;
		RemoveList(textBox);		
		while (i < Convert::ToInt32(comboBox2->Text))
		{
			TextBox^ T = gcnew TextBox();
			T = Parametrs(T, top, left + i*25);
			textBox->Add(T);
			i++;
		}
	}
	else
	{
		rows = Convert::ToInt32(comboBox1->Text);
		colons = Convert::ToInt32(comboBox2->Text);
		int i = 0, j = 0;
		RemoveList(textBox);
		while (i < Convert::ToInt32(comboBox1->Text))
		{
			j = 0;
			while (j < Convert::ToInt32(comboBox2->Text))
			{
				TextBox^ T = gcnew TextBox();
				T = Parametrs(T, top + i * 25, left + j * 25);
				textBox->Add(T);
				j++;
			}
			i++;
		}
		if (sign == nullptr)
			SignInit();
		else
		{
			sign->Left = textBox[textBox->Count - 1]->Left + 30;
			sign->Top = (textBox[textBox->Count - 1]->Top + textBox[0]->Top) / 2;
		}
	}
}

System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (sign == nullptr)
	{
		sign = gcnew TextBox();
		sign = Parametrs(sign, (textBox[textBox->Count - 1]->Top + textBox[0]->Top) / 2, textBox[textBox->Count - 1]->Left + 30);
	}
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(lab_1);
	sign->Text = "+";
	textBox2 = NewList(textBox2, sign->Left + 30, textBox[0]->Top);
}

//				"="

System::Void MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (textBox2->Count != 0 && equal == nullptr)
	{
		equal = gcnew TextBox();
		equal = Parametrs(equal, (textBox[textBox->Count - 1]->Top + textBox[0]->Top) / 2, textBox2[textBox2->Count - 1]->Left + 30);
		equal->Text = "=";		
		textBox3 = NewList(textBox3, equal->Left + 30, textBox[0]->Top);
		Equiality();
	}
	else
	{
		if (sign->Text != "=")
		{
			equal->Left = textBox2[textBox2->Count - 1]->Left + 30;
			equal->Text = "=";
			this->Controls->Add(equal);
			textBox3 = NewList(textBox3, equal->Left + 30, textBox[0]->Top);
			Equiality();
		}
		else
		{
			Equiality();
		}
	}
}

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(lab_1);
	this->Controls->Remove(equal);
	equal = nullptr;
	sign->Text = "-";
	textBox2 = NewList(textBox2, sign->Left + 30, textBox[0]->Top);
}


// *****
System::Void MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(lab_1);
	this->Controls->Remove(equal);
	equal = nullptr;
	sign->Text = "*";
	//
	// new form
	//
	form = gcnew Form();
	form->Height = 200;
	form->Width = 150;
	form->Left = 350;
	form->Top = 400;
	//
	// rows of the second grid
	//
	cmbox1 = gcnew ComboBox();
	cmbox1 = CMBox(cmbox1, 30);
	cmbox1->Parent = form;
	cmbox1->Text = comboBox2->Text;
	cmbox1->Enabled = false;
	//
	// colons of the second grid
	//
	cmbox2 = gcnew ComboBox();
	cmbox2 = CMBox(cmbox2, 80);
	cmbox2->Parent = form;
	//
	// button of creating new grid
	//
	but = gcnew Button();
	but->Left = 30;
	but->Top = 100;
	but->Height = 30;
	but->Width = 70;
	but->Text = "Ок";
	but->Parent = form;
	but->Click += gcnew System::EventHandler(this, &MyForm::butClick);

	form->Show();
}

System::Void MyForm::butClick(System::Object^  sender, System::EventArgs^  e)
{
	rows = Convert::ToInt32(comboBox2->Text);
	colons = Convert::ToInt32(cmbox2->Text);
	textBox2 = NewList(textBox2, sign->Left + 30, textBox[0]->Top);
	form->Close();
}

// TRANSPONSE
System::Void MyForm::button7_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(lab_1);
	sign->Text = "=";
	int i = 0, j;
	while (i < Convert::ToInt32(comboBox2->Text))
	{
		j = 0;
		while (j < Convert::ToInt32(comboBox1->Text))
		{
			TextBox^ T = gcnew TextBox();
			T = Parametrs(T, textBox[0]->Top + i * 25, sign->Left + 30 + j * 25);
			textBox3->Add(T);
			j++;
		}
		i++;
	}
	matrix->AddMatrix1(textBox, Convert::ToInt32(comboBox1->Text), Convert::ToInt32(comboBox2->Text));
	matrix->Transponse();
	textBox3 = matrix->Result(textBox3);
}

System::Void MyForm::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox);
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(sign);
	//sign = nullptr;
	this->Controls->Remove(lab_1);
	lab_1 = nullptr;
}

System::Void MyForm::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox3);
	RemoveList(textBox2);
	this->Controls->Remove(lab_1);
	this->Controls->Remove(equal);
	equal = nullptr;
	TextBox^ T = gcnew TextBox();
	T->Height = 30;
	T->Width = 25;
	T->Left = sign->Left + 25;
	T->Top = sign->Top;
	T->Parent = this;
	textBox2->Add(T);
	sign->Text = "*";
}

//Determinant
System::Void MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(lab_1);
	if(lab_1 != nullptr) delete lab_1;
	if (Convert::ToInt32(comboBox1->Text) == Convert::ToInt32(comboBox2->Text))
	{
		TextBox^ T = gcnew TextBox();
		T->Height = 30;
		T->Width = 40;
		T->Left = sign->Left + 30;
		T->Top = sign->Top;
		T->Parent = this;
		textBox3->Add(T);
		sign->Text = "=";
		lab_1 = gcnew Label();
		lab_1->Left = textBox[0]->Left - 30;
		lab_1->Top = sign->Top;
		lab_1->Text = "Det";
		lab_1->Parent = this;
		Equiality();
	}
	else
		MessageBox::Show("Определители считаются только у квадратных матриц!");
}

System::Void MyForm::button9_Click(System::Object^  sender, System::EventArgs^  e)
{
	RemoveList(textBox2);
	RemoveList(textBox3);
	this->Controls->Remove(equal);
	equal = nullptr;
	this->Controls->Remove(lab_1);
	if (Convert::ToInt32(comboBox1->Text) == Convert::ToInt32(comboBox2->Text))
	{
		sign->Text = "=";
		delete lab_1;
		lab_1 = gcnew Label();
		lab_1->Left = sign->Left + 30;
		lab_1->Top = sign->Top;
		int ord = Convert::ToInt32(comboBox1->Text);
		matrix->AddMatrix1(textBox, ord, ord);
		int D = Functions::Determinant(matrix->GetMatrix1()->data, ord);
		if (D != 0)
		{
			textBox3 = NewList(textBox3, sign->Left + 80, textBox[0]->Top);
			lab_1->Text = "1/" + Convert::ToString(D);
			lab_1->Parent = this;
			matrix->Invers();
			textBox3 = matrix->Result(textBox3);
		}
		else
		{
			lab_1->Width = 150;
			lab_1->Parent = this;
			lab_1->Text = "Вырожденная матрица";
		}
	}
	else
	{
		MessageBox::Show("Обратная матрица доступна только для квадратных, невырожденных матриц!");
	}
}

System::Void MyForm::button11_Click(System::Object^  sender, System::EventArgs^  e)
{
	newForm = gcnew EquationForm();
	newForm->GetForm()->Show();
}

System::Void MyForm::button12_Click(System::Object^  sender, System::EventArgs^  e)
{
	Delete();
	if (Convert::ToInt32(comboBox1->Text) == Convert::ToInt32(comboBox2->Text))
	{
		form = gcnew Form();
		form->Height = 180;
		form->Width = 200;
		form->Left = 300;
		Pow = gcnew TextBox();
		Pow = Parametrs(Pow, 30, 40);
		Pow->Width = 60;
		Pow->Text = "Степень";
		Pow->Parent = form;

		Button^ B = gcnew Button();
		B->Left = 50;
		B->Top = 70;
		B->Text = "Выполнить";
		B->Parent = form;
		B->Click += gcnew System::EventHandler(this, &MyForm::BClick);

		form->Show();
	}
	else
		MessageBox::Show("Матрицы должна быть квадратной");
}

System::Void MyForm::BClick(System::Object^  sender, System::EventArgs^  e)
{
	matrix->AddMatrix1(textBox, Functions::Convertation(comboBox1->Text), Functions::Convertation(comboBox2->Text));
	matrix->Power(Functions::Convertation(Pow->Text));
	sign->Text = "=";
	textBox3 = NewList(textBox3, sign->Left + 30, textBox[0]->Top);
	textBox3 = matrix->Result(textBox3);
	
}