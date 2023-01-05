#pragma once
#include "database.h"
#include <string>
#include "windows.h"
#include "Megerosites.h"
#include "Helyszerkesztes.h"
#include "OpenImage.h"
#include "csvexport.h"

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Kereses
	/// </summary>
	public ref class Kereses : public System::Windows::Forms::Form
	{
	public:
		Kereses(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Kereses (FuB::DataBase* dataBase) : dataBase (dataBase) {
			dataBaseFound = new FuB::DataBase ();
			prevMultipleSelectedCount = 0;
			InitializeComponent ();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Kereses()
		{
			dataBase->SetSelectedIndex (-1);
			dataBase->SetMultipleSelected (false);
			if (components)
			{
				delete components;
			}
		}
	private: int prevMultipleSelectedCount;
	private: FuB::DataBase* dataBase;
	private: FuB::DataBase* dataBaseFound;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::ColumnHeader^  helyNeve;
	private: System::Windows::Forms::ColumnHeader^  helyCime;
	private: System::Windows::Forms::ColumnHeader^  alanyNeve;
	private: System::Windows::Forms::ColumnHeader^  telefonSzam;
	private: System::Windows::Forms::ColumnHeader^  datum;
	private: System::Windows::Forms::ColumnHeader^  hozzaadva;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  exportálásToolStripMenuItem;




	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listView2 = (gcnew System::Windows::Forms::ListView ());
			this->helyNeve = (gcnew System::Windows::Forms::ColumnHeader ());
			this->helyCime = (gcnew System::Windows::Forms::ColumnHeader ());
			this->alanyNeve = (gcnew System::Windows::Forms::ColumnHeader ());
			this->telefonSzam = (gcnew System::Windows::Forms::ColumnHeader ());
			this->datum = (gcnew System::Windows::Forms::ColumnHeader ());
			this->hozzaadva = (gcnew System::Windows::Forms::ColumnHeader ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->label2 = (gcnew System::Windows::Forms::Label ());
			this->button3 = (gcnew System::Windows::Forms::Button ());
			this->button2 = (gcnew System::Windows::Forms::Button ());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox ());
			this->button1 = (gcnew System::Windows::Forms::Button ());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox ());
			this->button5 = (gcnew System::Windows::Forms::Button ());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip ());
			this->exportálásToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit ();
			this->menuStrip1->SuspendLayout ();
			this->SuspendLayout ();
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange (gcnew cli::array< System::Windows::Forms::ColumnHeader^  > (6) {
				this->helyNeve, this->helyCime,
					this->alanyNeve, this->telefonSzam, this->datum, this->hozzaadva
			});
			this->listView2->FullRowSelect = true;
			this->listView2->GridLines = true;
			this->listView2->Location = System::Drawing::Point (12, 215);
			this->listView2->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size (1581, 280);
			this->listView2->TabIndex = 20;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			this->listView2->SelectedIndexChanged += gcnew System::EventHandler (this, &Kereses::listView2_SelectedIndexChanged);
			// 
			// helyNeve
			// 
			this->helyNeve->Text = L"Elnevezés";
			this->helyNeve->Width = 200;
			// 
			// helyCime
			// 
			this->helyCime->DisplayIndex = 2;
			this->helyCime->Text = L"Cím";
			this->helyCime->Width = 334;
			// 
			// alanyNeve
			// 
			this->alanyNeve->DisplayIndex = 1;
			this->alanyNeve->Text = L"Név";
			this->alanyNeve->Width = 216;
			// 
			// telefonSzam
			// 
			this->telefonSzam->Text = L"Telefonszám";
			this->telefonSzam->Width = 253;
			// 
			// datum
			// 
			this->datum->Text = L"Dátum";
			this->datum->Width = 312;
			// 
			// hozzaadva
			// 
			this->hozzaadva->Text = L"Hozzáadva";
			this->hozzaadva->Width = 312;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point (12, 188);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size (135, 17);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Keresés eredménye";
			this->label1->Click += gcnew System::EventHandler (this, &Kereses::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point (12, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size (126, 17);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Keresendõ szöveg";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point (139, 99);
			this->button3->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size (107, 75);
			this->button3->TabIndex = 24;
			this->button3->Text = L"Hely törlése";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler (this, &Kereses::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point (15, 99);
			this->button2->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size (107, 75);
			this->button2->TabIndex = 23;
			this->button2->Text = L"Hely szerkesztése";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler (this, &Kereses::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point (12, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size (421, 22);
			this->textBox1->TabIndex = 25;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point (439, 61);
			this->button1->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size (91, 27);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Keresés";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler (this, &Kereses::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point (579, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size (297, 140);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 28;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler (this, &Kereses::pictureBox1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point (783, 168);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size (93, 42);
			this->button5->TabIndex = 27;
			this->button5->Text = L"Megtekint";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler (this, &Kereses::button5_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size (20, 20);
			this->menuStrip1->Items->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (1) { this->exportálásToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point (0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size (1620, 28);
			this->menuStrip1->TabIndex = 29;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exportálásToolStripMenuItem
			// 
			this->exportálásToolStripMenuItem->Name = L"exportálásToolStripMenuItem";
			this->exportálásToolStripMenuItem->Size = System::Drawing::Size (90, 24);
			this->exportálásToolStripMenuItem->Text = L"Exportálás";
			this->exportálásToolStripMenuItem->Click += gcnew System::EventHandler (this, &Kereses::exportálásToolStripMenuItem_Click);
			// 
			// Kereses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (1620, 520);
			this->Controls->Add (this->pictureBox1);
			this->Controls->Add (this->button5);
			this->Controls->Add (this->button1);
			this->Controls->Add (this->textBox1);
			this->Controls->Add (this->button3);
			this->Controls->Add (this->button2);
			this->Controls->Add (this->label2);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->listView2);
			this->Controls->Add (this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Kereses";
			this->Text = L"Keresés";
			this->Load += gcnew System::EventHandler (this, &Kereses::Kereses_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit ();
			this->menuStrip1->ResumeLayout (false);
			this->menuStrip1->PerformLayout ();
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void label1_Click (System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void listView2_SelectedIndexChanged (System::Object^  sender, System::EventArgs^  e) {
	if (listView2->SelectedItems->Count > 0 && listView2->SelectedItems->Count < 2)
	{
		int var;
		for (int lcount = 0; lcount <= listView2->Items->Count - 1; lcount++)
		{
			if (listView2->Items[lcount]->Selected == true)
			{
				var = lcount;
				break;
			}
		}
		int size;
		std::wstring m_filePathTo (dataBaseFound->GetData ()[var].GetFilePathTo (size));
		System::String^ s_filePathTo = gcnew String (m_filePathTo.c_str ());
		if (s_filePathTo->Length > 1 && s_filePathTo[m_filePathTo.size () - 1] != 'f' && s_filePathTo[m_filePathTo.size () - 1] != 'F') {
			button5->Enabled = true;
			this->button5->Visible = true;
			pictureBox1->ImageLocation = s_filePathTo;
		}
		else if (s_filePathTo->Length > 1 && (s_filePathTo[m_filePathTo.size () - 1] == 'f' || s_filePathTo[m_filePathTo.size () - 1] == 'F')) {
			button5->Enabled = true;
			this->button5->Visible = true;
			//pictureBox1->ImageLocation = s_filePathTo;
			//default pdf kep megjelenitese
		}
		else {
			this->button5->Visible = false;
			button5->Enabled = false;
			pictureBox1->ImageLocation = nullptr;
		}
		dataBaseFound->SetSelectedIndex (var);
		FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
		dataBase->SetSelectedIndex (dataBaseFoundAccessor[var].GetSecondaryIndex ());
		dataBaseFound->SetMultipleSelected (false);
		dataBase->SetMultipleSelected (false);
	}
	else if (listView2->SelectedItems->Count > 1) {
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBaseFound->SetSelectedIndex (-1);
		dataBase->SetSelectedIndex (-1);
		if (listView2->SelectedItems->Count < prevMultipleSelectedCount) {
			dataBaseFound->SetMultipleSelected (false);
			dataBase->SetMultipleSelected (false);
		}
		prevMultipleSelectedCount = listView2->SelectedItems->Count;
		int var;
		for (int lcount = 0; lcount <= listView2->Items->Count - 1; lcount++)
		{
			if (listView2->Items[lcount]->Selected == true)
			{
				var = lcount;
				dataBaseFound->AddToMultipleSelect (var);
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBase->AddToMultipleSelect (dataBaseFoundAccessor[var].GetSecondaryIndex ());
			}
		}
	}
	else {
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBaseFound->SetSelectedIndex (-1);
		dataBaseFound->SetMultipleSelected (false);
	}
}
private: System::Void button1_Click (System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->Text->Length > 0) {
		if (dataBaseFound->GetSize () > 0) {
			delete dataBaseFound;
			dataBaseFound = new FuB::DataBase();
		}
		System::String^ searchBy = textBox1->Text;
		wchar_t sb[1000];
		for (int i = 0; i < textBox1->Text->Length; i++) {
			sb[i] = searchBy[i];
		}
		sb[textBox1->Text->Length] = '\0';
		//kereses a dataBaseben
		FuB::Data* dataAcessor = dataBase->GetData ();
		int size;
		for (int i = 0; i < dataBase->GetSize (); i++) {
			std::wstring m_dataName (dataAcessor[i].GetDataName (size));
			std::wstring m_clientName (dataAcessor[i].GetClientName (size));
			std::wstring m_address (dataAcessor[i].GetAdress (size));
			std::wstring m_phonenumber (dataAcessor[i].GetPhoneNumber (size));
			std::wstring m_date (dataAcessor[i].GetDate (size));
			std::wstring m_hozzaadva (dataAcessor[i].GetHozzaAdva (size));

			if (m_dataName.find (sb) !=  std::string::npos) {
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			} else if(m_clientName.find (sb) != std::string::npos){
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			} else if(m_address.find (sb) != std::string::npos){
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			} else if(m_phonenumber.find (sb) != std::string::npos){
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			} else if(m_date.find (sb) != std::string::npos){
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			} else if(m_hozzaadva.find (sb) != std::string::npos){
				dataBaseFound->AddData ();
				FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1] = dataAcessor[i];
				dataBaseFoundAccessor[dataBaseFound->GetSize () - 1].SetSecondaryIndex (i);
			}
		}
		ReDrawListView (dataBaseFound, listView2);
	}
}
private: System::Void pictureBox1_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Show Picture
	ShowPicture (dataBase);
	dataBase->SetSelectedIndex (-1);
	dataBase->SetMultipleSelected (false);
}
private: System::Void button5_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Show Picture
	ShowPicture (dataBase);
	dataBase->SetSelectedIndex (-1);
	dataBase->SetMultipleSelected (false);
}
private: System::Void button2_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Search
	if (!dataBaseFound->IsMultipleselected () && dataBaseFound->GetSelectedIndex () != -1) {
		MyForm3 f (dataBaseFound, listView2);
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		if (f.ShowDialog () == System::Windows::Forms::DialogResult::OK) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			FuB::Data* dataBaseFoundAccessor = dataBaseFound->GetData ();

			int size;
			std::wstring m_dataName = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex()].GetDataName (size);
			System::String^ s_dataName = gcnew String (m_dataName.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetDataName (s_dataName, s_dataName->Length);

			std::wstring m_address = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetAdress (size);
			System::String^ s_address = gcnew String (m_address.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetAddress (s_address, s_address->Length);

			std::wstring m_clientName = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetClientName (size);
			System::String^ s_clientName = gcnew String (m_clientName.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetClientName (s_clientName, s_clientName->Length);

			std::wstring m_phoneNumber = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetPhoneNumber (size);
			System::String^ s_phoneNumber = gcnew String (m_phoneNumber.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetPhoneNumber (s_phoneNumber, s_phoneNumber->Length);

			std::wstring m_Date = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetDate (size);
			System::String^ s_Date = gcnew String (m_Date.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetDate (s_Date, s_Date->Length);

			std::wstring m_dirPath= dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetDirPath (size);
			System::String^ s_dirPath = gcnew String (m_dirPath.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetDirPath (s_dirPath, s_dirPath->Length);

			std::wstring m_filePathFrom = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetFilePathFrom (size);
			System::String^ s_filePathFrom = gcnew String (m_filePathFrom.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetFilePathFrom (s_filePathFrom, s_filePathFrom->Length);

			std::wstring m_filePathTo = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetFilePathTo (size);
			System::String^ s_filePathTo = gcnew String (m_filePathTo.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetFilePathTo (s_filePathTo, s_filePathTo->Length);

			std::wstring m_jegyzetek = dataBaseFoundAccessor[dataBaseFound->GetSelectedIndex ()].GetNotes (size);
			System::String^ s_jegyzetek = gcnew String (m_jegyzetek.c_str ());
			dataAcessor[dataBase->GetSelectedIndex ()].SetNotes (s_jegyzetek, s_jegyzetek->Length);

		}
		dataBase->SetSelectedIndex (-1);
		dataBaseFound->SetSelectedIndex (-1);
	}
}
private: System::Void button3_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Delete
	if (dataBaseFound->IsMultipleselected () || dataBaseFound->GetSelectedIndex () != -1) {
		MyForm1 f (dataBase, listView2);
		if (f.ShowDialog () == System::Windows::Forms::DialogResult::OK) {
			int indextoremove = dataBaseFound->GetSelectedIndex ();
			if (!dataBaseFound->IsMultipleselected ()) {
				dataBaseFound->DeleteData (indextoremove);
			}
			else {
				for (int i = 0; i < dataBaseFound->GetMultiNum (); i++) {
					indextoremove = dataBaseFound->GetMultipleSelect ()[i] - i;
					dataBaseFound->DeleteData (indextoremove);
				}
				dataBaseFound->SetMultipleSelected (false);
			}
			pictureBox1->ImageLocation = nullptr;
			this->button5->Visible = false;
			button5->Enabled = false;
		}
		ReDrawListView (dataBaseFound, listView2);
	}
}
private: System::Void Kereses_Load (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripDropDownButton1_Click (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void exportálásToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	if (dataBaseFound->IsMultipleselected () || dataBaseFound->GetSelectedIndex () != -1) {
		SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog ();
		saveFileDialog->Filter = "CSV file (*.csv)|*.csv";
		saveFileDialog->Title = "Exportálás";
		saveFileDialog->FileName = ".csv";

		if (dataBaseFound->GetSelectedIndex () != -1 && !dataBaseFound->IsMultipleselected ()) {
			if (saveFileDialog->ShowDialog () == System::Windows::Forms::DialogResult::OK)
				CsvExportOneRecord (dataBaseFound, saveFileDialog->FileName);
		}
		else if (dataBaseFound->GetSelectedIndex () == -1 && dataBaseFound->IsMultipleselected ()) {
			if (saveFileDialog->ShowDialog () == System::Windows::Forms::DialogResult::OK)
				CsvExportMultipleRecord (dataBaseFound, saveFileDialog->FileName);
		}
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBaseFound->SetSelectedIndex (-1);
	}
}
};
}
