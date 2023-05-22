#pragma once

#include "Functional.h"
#include "EditForm.h"
#include "NewForm.h"
#include <msclr\marshal_cppstd.h>

namespace Coliving {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			func = CFunctional::getInstance();
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			delete func;
		}
	private: CFunctional* func;
	private: String^ filter = L"";
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(180, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(278, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Список людей по общежитиям";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Location = System::Drawing::Point(134, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(450, 257);
			this->dataGridView1->TabIndex = 1;
			// 
			// radioButton1
			// 
			this->radioButton1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(12, 137);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(51, 23);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Все";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(12, 161);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(116, 23);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"2 общежитие";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(12, 185);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(116, 23);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"3 общежитие";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton4->Location = System::Drawing::Point(12, 209);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(116, 23);
			this->radioButton4->TabIndex = 5;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"8 общежитие";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 268);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(11, 37);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 28);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(12, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 28);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(11, 105);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 26);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 21);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Фильтр:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 333);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"Общежития";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		radioButton1->Checked = 1;
		radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
		MainForm::Update();

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		filter = textBox1->Text;
		radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		DataGridViewColumn^ c = gcnew DataGridViewColumn();
		DataGridViewCell^ td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Комната";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Имя";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		int* roomlist;
		wchar_t** namelist;
		int size = 0;
		if (radioButton1->Checked) {
			func->getAllStudents(size, roomlist, namelist, msclr::interop::marshal_as<std::wstring>(filter->ToString()), 0);
		}
		else if (radioButton2->Checked) {
			func->getAllStudents(size, roomlist, namelist, msclr::interop::marshal_as<std::wstring>(filter->ToString()), 1);
		}
		else if (radioButton3->Checked) {
			func->getAllStudents(size, roomlist, namelist, msclr::interop::marshal_as<std::wstring>(filter->ToString()), 2);
		}
		else if (radioButton4->Checked) {
			func->getAllStudents(size, roomlist, namelist, msclr::interop::marshal_as<std::wstring>(filter->ToString()), 3);
		}
		for (int i = 0; i < size; ++i) {
			DataGridViewRow^ r = gcnew DataGridViewRow();
			r->HeaderCell->Value = L"";
			r->CreateCells(dataGridView1);
			cli::array<String^>^ Values = gcnew cli::array<String^>(dataGridView1->ColumnCount);
			Values[0] = roomlist[i].ToString();
			Values[1] = msclr::interop::marshal_as<String^>(namelist[i]);
			r->SetValues(Values);
			dataGridView1->Rows->Add(r);
			dataGridView1->RowHeadersWidth = 200;
		}
		for (int i = 0; i < size; ++i) {
			delete namelist[i];
		}
		delete roomlist;
		delete namelist;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Coliving::NewForm newform;
		newform.ShowDialog();
		if (newform.room->Length != 0 && newform.name->Length != 0) {
			String^ room = newform.room;
			String^ name = newform.name;
			int^ number = newform.number;
			func->addStudent(stoi(msclr::interop::marshal_as<std::wstring>(room)), msclr::interop::marshal_as<std::wstring>(name), (int) number);
			radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
			MainForm::Update();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int tempid = dataGridView1->CurrentCell->RowIndex;
		if (tempid >= 0 && tempid < dataGridView1->RowCount) {
			Coliving::EditForm editform(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString(), this->dataGridView1->Rows[tempid]->Cells[1]->Value->ToString(), func->getNumber(stoi(msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString())), msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[1]->Value->ToString())));
			editform.ShowDialog();
			if (editform.room->Length != 0 || editform.name->Length != 0) {
				String^ room = editform.room;
				String^ name = editform.name;
				int^ number = editform.number;
				func->editStudent(stoi(msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString())), msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[1]->Value->ToString()),
					stoi(msclr::interop::marshal_as<std::wstring>(room)), msclr::interop::marshal_as<std::wstring>(name), (int) number);
				radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
				MainForm::Update();
			}
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int tempid = dataGridView1->CurrentCell->RowIndex;
		if (tempid >= 0 && tempid < dataGridView1->RowCount) {
			System::Windows::Forms::DialogResult dialogRes = MessageBox::Show(this, L"Вы уверены, что хотите удалить проживающего?", "Подтверждение", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			if (System::Windows::Forms::DialogResult::OK == dialogRes) {
				func->deleteStudent(stoi(msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString())), msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[1]->Value->ToString()));
				radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
				MainForm::Update();
			}
		}
	}
};
}
