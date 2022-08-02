#include "EquationForm.h"

Label^ ToLabel(Label^ lab, int left, int top)
{
	lab->Width = 7 * lab->Text->Length;
	lab->Left = left;
	lab->Top = top;
	return lab;
}

EquationForm::EquationForm()
{
	form = gcnew Form();
	form->Height = 400;
	form->Width = 600;

	rows1 = gcnew ComboBox();
	rows1 = ToComboBox(50, 100);
	rows1->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationForm::Rows1_SelectedIndex);

	colons1 = gcnew ComboBox();
	colons1 = ToComboBox(120, 100);
	colons1->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationForm::Colons1_SelectedIndex);

	rows2 = gcnew ComboBox();
	rows2 = ToComboBox(250, 100);
	rows2->Enabled = false;
	

	colons2 = gcnew ComboBox();
	colons2 = ToComboBox(320, 100);
	colons2->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationForm::Colons2_SelectedIndex);

	Perform = ToButton(350, 20);
	Perform->Text = "Выполнить";
	Perform->Click += gcnew System::EventHandler(this, &EquationForm::Perform_Click);

	X = gcnew Label();	
	X->Width = 70;	

	listBox = ToListBox(170, 20);
	listBox->Items->Add("AX = B");
	listBox->Items->Add("XA = B");
	listBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationForm::ListBox_SelectedIndex);
	
	Rows1 = gcnew Label();
	Rows1->Text = "Число строк";

	Colons1 = gcnew Label();
	Colons1->Text = "Число столбцов";
	
	Rows2 = gcnew Label();
	Rows2->Text = "Число строк";
	
	Colons2 = gcnew Label();
	Colons2->Text = "Число столбцов";

	MatrixA = gcnew Label();
	MatrixA->Text = "Матрица А";

	MatrixB = gcnew Label();
	MatrixB->Text = "Матрица В";

	Choose = gcnew Label();
	Choose->Text = "Вид уравнения";
	Choose = ToLabel(Choose, listBox->Left - 100, listBox->Top);
	
	
	form->Controls->Add(Choose);
	form->Controls->Add(listBox);
	
	
	
	textBox1 = gcnew List<TextBox^>();
	textBox2 = gcnew List<TextBox^>();
	textBox3 = gcnew List<TextBox^>();
	mat = new Matrixs();
}



TextBox^ EquationForm::ToTextBox(int left, int top)
{
	TextBox^ T = gcnew TextBox();
	T->Height = 20;
	T->Width = 20;
	T->Left = left;
	T->Top = top;
	T->Parent = form;
	return T;
}

Button^ EquationForm::ToButton(int left, int top)
{
	Button^ But = gcnew Button();
	But->Left = left;
	But->Top = top;
	But->Height = 30;
	But->Width = 100;
	return But;
}

ComboBox^ EquationForm::ToListBox(int left, int top)
{
	ComboBox^ L = gcnew ComboBox();
	L->Left = left;
	L->Top = top;
	L->Height = 30;
	L->Width = 80;
	return L;
}

ComboBox^ EquationForm::ToComboBox(int left, int top)
{
	ComboBox^ C = gcnew ComboBox();
	C->Left = left;
	C->Top = top;
	C->Height = 30;
	C->Width = 30;
	for (int i = 1; i < 6; i++)
	{
		C->Items->Add(Convert::ToString(i));
	}
	return C;
}

Form^ EquationForm::GetForm()
{
	return form;
}

List<TextBox^>^ EquationForm::TextList(int Rows, int Colons, int left, int top)
{
	List<TextBox^>^ L = gcnew List<TextBox^>();	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colons; j++)
		{
			TextBox^ T = gcnew TextBox();
			T = ToTextBox(left + j * 25, top + i * 25);
			L->Add(T);
		}
	}
	return L;
}


System::Void EquationForm::Rows1_SelectedIndex(System::Object^  sender, System::EventArgs^  e)
{
	textBox3 = RemoveList(textBox3);
	form->Controls->Remove(Res);
	form->Controls->Remove(Det);
	colons1->Text = rows1->Text;
	form->Controls->Remove(Eq);
	form->Controls->Remove(X);
	textBox1 = RemoveList(textBox1);	
	textBox2 = RemoveList(textBox2);
	textBox1 = TextList(Functions::Convertation(rows1->Text), Functions::Convertation(colons1->Text), rows1->Left + 30, rows1->Top + 30);		
	if (listBox->Text == "AX = B")
	{
		X->Text = "*  X       =";
		X->Left = textBox1[textBox1->Count - 1]->Left + 20;
		X->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		X->Parent = form;
	}
	if (listBox->Text == "XA = B")
	{
		X->Text = "X  *  ";
		X->Width = 15;
		X->Left = textBox1[0]->Left - 20;
		X->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		X->Parent = form;
		Eq = gcnew Label();
		Eq->Text = "=";
		Eq->Width = 10;
		Eq->Left = textBox1[textBox1->Count - 1]->Left + 60;
		Eq->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		Eq->Parent = form;
	}
	
}

List<TextBox^>^ EquationForm::RemoveList(List<TextBox^>^ list)
{
	while (list->Count > 0)
	{
		form->Controls->Remove(list[list->Count - 1]);
		list->RemoveAt(list->Count - 1);
	}
	return list;
}

System::Void EquationForm::Colons1_SelectedIndex(System::Object^  sender, System::EventArgs^  e)
{	
	textBox3 = RemoveList(textBox3);
	form->Controls->Remove(Res);
	form->Controls->Remove(Det);
	rows1->Text = colons1->Text;
	rows2->Text = colons1->Text;
	textBox1 = RemoveList(textBox1);	
	textBox2 = RemoveList(textBox2);
	form->Controls->Remove(Eq);
	form->Controls->Remove(X);
	textBox1 = TextList(Functions::Convertation(rows1->Text), Functions::Convertation(colons1->Text), rows1->Left + 30, rows1->Top + 30);
	if (listBox->Text == "AX = B")
	{
		X->Text = "*  X       =";
		X->Left = textBox1[textBox1->Count - 1]->Left + 20;
		X->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		X->Parent = form;
	}
	if (listBox->Text == "XA = B")
	{
		X->Text = "X  *  ";
		X->Width = 15;
		X->Left = textBox1[0]->Left - 40;
		X->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		X->Parent = form;
		Eq = gcnew Label();
		Eq->Text = "=";
		Eq->Width = 10;
		Eq->Left = textBox1[textBox1->Count - 1]->Left + 60;
		Eq->Top = (textBox1[0]->Top + textBox1[textBox1->Count - 1]->Top) / 2;
		Eq->Parent = form;
	}
}

System::Void EquationForm::Colons2_SelectedIndex(System::Object^  sender, System::EventArgs^  e)
{
	textBox3 = RemoveList(textBox3);
	form->Controls->Remove(Res);
	form->Controls->Remove(Det);
	textBox2 = RemoveList(textBox2);	
	textBox2 = TextList(Functions::Convertation(rows2->Text), Functions::Convertation(colons2->Text), textBox1[textBox1->Count - 1]->Left + 100, rows1->Top + 30);	
}



System::Void EquationForm::ListBox_SelectedIndex(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox->Text == "AX = B" || listBox->Text == "XA = B")
	{			
		form->Controls->Add(rows1);
		form->Controls->Add(colons1);
		form->Controls->Add(rows2);
		form->Controls->Add(colons2);

		Rows1 = ToLabel(Rows1, rows1->Left - 25, rows1->Top - 20);
		Rows1->Parent = form;
		Colons1 = ToLabel(Colons1, colons1->Left - 15, colons1->Top - 20);
		Colons1->Parent = form;

		Rows2 = ToLabel(Rows2, rows2->Left - 25, rows2->Top - 20);
		Rows2->Parent = form;
		Colons2 = ToLabel(Colons2, colons2->Left - 15, colons2->Top - 20);
		Colons2->Parent = form;

		MatrixA = ToLabel(MatrixA, Rows1->Left + 10, Rows1->Top - 20);
		MatrixB = ToLabel(MatrixB, Rows2->Left + 10, Rows2->Top - 20);
		form->Controls->Add(MatrixA);
		form->Controls->Add(MatrixB);
	}
	form->Controls->Add(Perform);
	
}

System::Void EquationForm::Perform_Click(System::Object^  sender, System::EventArgs^  e)
{
	textBox3 = RemoveList(textBox3);
	form->Controls->Remove(Res);
	form->Controls->Remove(Det);

	Res = gcnew Label();
	Res->Text = "X  =  ";
	Res->Width = 40;

	Det = gcnew Label();
	
	Det->Width = 40;
	mat->AddMatrix1(textBox1, Functions::Convertation(rows1->Text), Functions::Convertation(colons1->Text));
	mat->AddMatrix2(textBox2, Functions::Convertation(rows2->Text), Functions::Convertation(colons2->Text));
	if (Functions::Determinant(mat->GetMatrix1()->data, mat->GetMatrix1()->rows) == 0)
	{
		Det->Width = 150;
		Det->Text = "Вырожденная матрица А";	
		Det->Top = 270;
		Det->Left = 200;
		form->Controls->Add(Det);
		return;
	}
	else
	Det->Text = "1/" + Convert::ToString(Functions::Determinant(mat->GetMatrix1()->data, mat->GetMatrix1()->rows));
	

	if (listBox->Text == "AX = B")
	{
		textBox3 = TextList(Functions::Convertation(rows1->Text), Functions::Convertation(colons2->Text), textBox1[0]->Left + 80, textBox1[textBox1->Count - 1]->Top + 60);
		mat->AXB();
	}
	if (listBox->Text == "XA = B")
	{
		textBox3 = TextList(Functions::Convertation(rows1->Text), Functions::Convertation(colons2->Text), textBox1[0]->Left + 80, textBox1[textBox1->Count - 1]->Top + 60);
		mat->XAB();
	}
		Res->Left = textBox1[0]->Left;
		Res->Top = (textBox3[0]->Top + textBox3[textBox3->Count - 1]->Top) / 2;
		Res->Parent = form;
		Det->Top = Res->Top;
		Det->Left = Res->Left + 35;
		Det->Parent = form;		
		
		textBox3 = mat->Result(textBox3);
}