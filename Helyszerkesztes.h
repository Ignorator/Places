#pragma once
#include <fstream>
#include "database.h"
#include "String.h"
#include <iostream>
#include <ctime>
#include <exception>
#include <filesystem>
#include "windows.h"
#include <atlstr.h>
#include "ListViewDrawer.h"
#include "RecordToFilesystem.h"
#include "RecordFromFilesystem.h"

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3 (void)
		{
			InitializeComponent ();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm3 (FuB::DataBase* dataBase, System::Windows::Forms::ListView^  listView) : dataBase (dataBase), listView (listView)
		{
			InitializeComponent ();
			isdeletepicture = false;
		}
	private: bool isdeletepicture;
	private: System::Windows::Forms::Label^  label6;
	private: FuB::DataBase* dataBase;
	private: System::Windows::Forms::ListView^  listView;
	private: void SaveToDataBase () {
		FuB::Data* dataAcessor = dataBase->GetData ();

		String^ str = textBox1->Text;
		dataAcessor[dataBase->GetSelectedIndex()].SetDataName (str, str->Length);

		str = textBox2->Text;
		dataAcessor[dataBase->GetSelectedIndex ()].SetClientName (str, str->Length);

		str = textBox3->Text;
		dataAcessor[dataBase->GetSelectedIndex ()].SetAddress (str, str->Length);

		str = textBox4->Text;
		dataAcessor[dataBase->GetSelectedIndex ()].SetPhoneNumber (str, str->Length);

		str = dateTimePicker1->Value.ToString ();
		dataAcessor[dataBase->GetSelectedIndex ()].SetDate (str, str->Length);

		str = textBox6->Text;
		dataAcessor[dataBase->GetSelectedIndex ()].SetNotes (str, str->Length);

		if (textBox5->Text->Length > 0) {
			int buffsize;
			_wremove (dataAcessor[dataBase->GetSelectedIndex ()].GetFilePathTo (buffsize));
			str = textBox5->Text;
			dataAcessor[dataBase->GetSelectedIndex ()].SetFilePathFrom (str, str->Length);
			CopyImageToRecordDirectory (dataBase, dataBase->GetSelectedIndex ());
		}
		else if (textBox5->Text->Length == 0 && isdeletepicture) {
			int buffsize;
			_wremove (dataAcessor[dataBase->GetSelectedIndex ()].GetFilePathTo (buffsize));
			std::string es;
			System::String^ emptyString = gcnew String (es.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetFilePathFrom (emptyString, 0);
			dataAcessor[dataBase->GetSelectedIndex ()].SetFilePathTo (emptyString, 0);
		}

		RemoveRecordFromFilesystem (dataBase, (dataBase->GetSelectedIndex ()));
		SaveRecordToFilesystem (dataBase, (dataBase->GetSelectedIndex ()));
		ReDrawListView (dataBase, listView);
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm3 ()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent (void)
		{
			int size;

			FuB::Data* dataAcessor = dataBase->GetData ();
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->label2 = (gcnew System::Windows::Forms::Label ());
			this->label3 = (gcnew System::Windows::Forms::Label ());
			this->label4 = (gcnew System::Windows::Forms::Label ());
			this->label5 = (gcnew System::Windows::Forms::Label ());
			this->button2 = (gcnew System::Windows::Forms::Button ());
			this->button1 = (gcnew System::Windows::Forms::Button ());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox ());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox ());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox ());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox ());
			this->label6 = (gcnew System::Windows::Forms::Label ());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox ());
			this->button3 = (gcnew System::Windows::Forms::Button ());
			this->button4 = (gcnew System::Windows::Forms::Button ());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox ());
			this->label8 = (gcnew System::Windows::Forms::Label ());
			this->SuspendLayout ();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point (20, 467);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size (254, 22);
			this->dateTimePicker1->TabIndex = 7;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler (this, &MyForm3::dateTimePicker1_ValueChanged);

			std::wstring m_date (dataAcessor[dataBase->GetSelectedIndex ()].GetDate (size));
			System::String^ s_date = gcnew String (m_date.c_str ());


			System::DateTime dt = DateTime::Parse(s_date);
			this->dateTimePicker1->Value = dt;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point (12, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size (73, 17);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Elnevezés";
			this->label1->Click += gcnew System::EventHandler (this, &MyForm3::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point (12, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size (33, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Név";
			this->label2->Click += gcnew System::EventHandler (this, &MyForm3::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point (12, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size (31, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Cím";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point (12, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size (89, 17);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Telefonszám";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point (17, 444);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size (49, 17);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Dátum";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point (12, 240);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size (33, 17);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Kép";
			this->label6->Click += gcnew System::EventHandler (this, &MyForm3::label6_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point (295, 500);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size (104, 48);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Mentés";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler (this, &MyForm3::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point (408, 500);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size (104, 48);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Mégsem";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler (this, &MyForm3::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point (12, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size (316, 22);
			this->textBox1->TabIndex = 22;
			this->textBox1->TextChanged += gcnew System::EventHandler (this, &MyForm3::textBox1_TextChanged);
			std::wstring m_dataName (dataAcessor[dataBase->GetSelectedIndex ()].GetDataName (size));
			System::String^ s_dataName = gcnew String (m_dataName.c_str ());
			this->textBox1->Text = s_dataName;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point (12, 96);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size (316, 22);
			this->textBox2->TabIndex = 23;
			this->textBox2->TextChanged += gcnew System::EventHandler (this, &MyForm3::textBox2_TextChanged);
			std::wstring m_clientName (dataAcessor[dataBase->GetSelectedIndex ()].GetClientName (size));
			System::String^ s_clientName = gcnew String (m_clientName.c_str ());
			this->textBox2->Text = s_clientName;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point (12, 151);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size (316, 22);
			this->textBox3->TabIndex = 24;
			this->textBox3->TextChanged += gcnew System::EventHandler (this, &MyForm3::textBox3_TextChanged);
			std::wstring m_address (dataAcessor[dataBase->GetSelectedIndex ()].GetAdress (size));
			System::String^ s_address = gcnew String (m_address.c_str ());
			this->textBox3->Text = s_address;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point (12, 204);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size (316, 22);
			this->textBox4->TabIndex = 25;
			this->textBox4->TextChanged += gcnew System::EventHandler (this, &MyForm3::textBox4_TextChanged);
			std::wstring m_phonenumber (dataAcessor[dataBase->GetSelectedIndex ()].GetPhoneNumber (size));
			System::String^ s_phonenumber = gcnew String (m_phonenumber.c_str ());
			this->textBox4->Text = s_phonenumber;
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point (12, 264);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size (316, 22);
			this->textBox5->TabIndex = 27;
			this->textBox5->TextChanged += gcnew System::EventHandler (this, &MyForm3::textBox5_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point (334, 258);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size (91, 35);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Megnyitás";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler (this, &MyForm3::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point (430, 258);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size (91, 35);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Kép törlése";
			this->button4->UseVisualStyleBackColor = false;
			button4->BackColor = Color::White;
			std::wstring imgpath (dataAcessor[dataBase->GetSelectedIndex ()].GetFilePathFrom (size));
			if (size > 0) {
				this->button4->Visible = true;
			} else {
				this->button4->Visible = false;
			}
			this->button4->Click += gcnew System::EventHandler (this, &MyForm3::button4_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point (12, 324);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size (316, 117);
			this->textBox6->TabIndex = 32;
			std::wstring m_jegyzetek (dataAcessor[dataBase->GetSelectedIndex ()].GetNotes (size));
			System::String^ s_jegyzetek = gcnew String (m_jegyzetek.c_str ());
			this->textBox6->Text = s_jegyzetek;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point (12, 300);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size (98, 17);
			this->label8->TabIndex = 31;
			this->label8->Text = L"Megjegyzések";
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (525, 567);
			this->Controls->Add (this->textBox6);
			this->Controls->Add (this->label8);
			this->Controls->Add (this->label6);
			this->Controls->Add (this->button3);
			this->Controls->Add (this->button4);
			this->Controls->Add (this->textBox5);
			this->Controls->Add (this->textBox4);
			this->Controls->Add (this->textBox3);
			this->Controls->Add (this->textBox2);
			this->Controls->Add (this->textBox1);
			this->Controls->Add (this->button1);
			this->Controls->Add (this->button2);
			this->Controls->Add (this->label5);
			this->Controls->Add (this->label4);
			this->Controls->Add (this->label3);
			this->Controls->Add (this->label2);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->dateTimePicker1);
			this->Margin = System::Windows::Forms::Padding (4);
			this->Name = L"MyForm3";
			this->Text = L"Hely szerkesztése";
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void label1_Click (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click (System::Object^  sender, System::EventArgs^  e) {
		SaveToDataBase ();
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close ();
	}
	private: System::Void button1_Click (System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close ();
	}
	private: System::Void textBox2_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox3_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox4_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dateTimePicker1_ValueChanged (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label6_Click (System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox5_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button3_Click (System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = "C:\\";
	openFileDialog->Filter = "jpg files (*.jpg)|*.jpg|jpeg files (*.jpeg)|*.jpeg|png files (*.png)|*.png|pdf files (*.pdf)|*.pdf";
	openFileDialog->FilterIndex = 4;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog () == System::Windows::Forms::DialogResult::OK) {
		textBox5->Text = openFileDialog->FileName;
	}
}
private: System::Void button4_Click (System::Object^  sender, System::EventArgs^  e) {
	if (isdeletepicture) {
		isdeletepicture = false;
		button4->BackColor = Color::White;
	} else{
		isdeletepicture = true;
		button4->BackColor = Color::Red;
	}
	textBox5->Text = L"";
}
	};
}
