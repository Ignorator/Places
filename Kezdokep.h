#pragma once
#include "Ujhely.h"
#include "Megerosites.h"
#include "Helyszerkesztes.h"
#include "database.h"
#include "Sorts.h"
#include "Kereses.h"
#include "ListViewDrawer.h"
#include "OpenImage.h"
#include "RecordToFilesystem.h"
#include "RecordFromFilesystem.h"
#include "csvexport.h"

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: FuB::DataBase* dataBase;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ToolStripMenuItem^  rendez�sToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elnevez�sSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cs�kken�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  n�vekv�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  n�vSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cs�kken�ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  n�vekv�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  c�mSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cs�kken�ToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  n�vekv�ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  d�tumSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cs�kken�ToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  n�vekv�ToolStripMenuItem2;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColumnHeader^  hozzaadva;
	private: System::Windows::Forms::ToolStripMenuItem^  hozz�ad�sD�tumaSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cs�kken�ToolStripMenuItem4;

	private: System::Windows::Forms::ToolStripMenuItem^  n�vekv�ToolStripMenuItem3;
	private: System::Windows::Forms::ColumnHeader^  Megjegyzesek;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;


	private: int prevMultipleSelectedCount;
	public:
		MyForm(void)
		{
			dataBase = new FuB::DataBase ();
			CreateDefaultDirectories ();
			std::vector<std::wstring> dirList = GetDirList ();
			FillUpDataBaseFromRecords (dataBase, dirList);
			prevMultipleSelectedCount = 0;
			InitializeComponent ();
			if (dataBase->GetSize () > 0) {
				ReDrawListView (dataBase, listView2);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;



	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;




	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;




	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::BindingSource^  bindingSource2;
	private: System::Windows::Forms::BindingSource^  bindingSource3;
	private: System::Windows::Forms::BindingSource^  bindingSource4;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �jId�pontFelv�teleToolStripMenuItem;






	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::ColumnHeader^  helyNeve;
	private: System::Windows::Forms::ColumnHeader^  helyCime;
	private: System::Windows::Forms::ColumnHeader^  alanyNeve;
	private: System::Windows::Forms::ColumnHeader^  telefonSzam;
	private: System::Windows::Forms::ColumnHeader^  datum;


	private: System::Windows::Forms::ToolStripMenuItem^  inform�ci�kToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kil�p�sToolStripMenuItem;
	private: System::Data::DataSet^  dataSet1;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->components = (gcnew System::ComponentModel::Container ());
			this->button1 = (gcnew System::Windows::Forms::Button ());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip (this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker ());
			this->button2 = (gcnew System::Windows::Forms::Button ());
			this->button3 = (gcnew System::Windows::Forms::Button ());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource (this->components));
			this->bindingSource2 = (gcnew System::Windows::Forms::BindingSource (this->components));
			this->bindingSource3 = (gcnew System::Windows::Forms::BindingSource (this->components));
			this->bindingSource4 = (gcnew System::Windows::Forms::BindingSource (this->components));
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip ());
			this->�jId�pontFelv�teleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->rendez�sToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->elnevez�sSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->cs�kken�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vekv�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->cs�kken�ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vekv�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->c�mSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->cs�kken�ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vekv�ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->d�tumSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->cs�kken�ToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vekv�ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->hozz�ad�sD�tumaSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->cs�kken�ToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->n�vekv�ToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->inform�ci�kToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->kil�p�sToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->listView2 = (gcnew System::Windows::Forms::ListView ());
			this->helyNeve = (gcnew System::Windows::Forms::ColumnHeader ());
			this->helyCime = (gcnew System::Windows::Forms::ColumnHeader ());
			this->alanyNeve = (gcnew System::Windows::Forms::ColumnHeader ());
			this->telefonSzam = (gcnew System::Windows::Forms::ColumnHeader ());
			this->datum = (gcnew System::Windows::Forms::ColumnHeader ());
			this->hozzaadva = (gcnew System::Windows::Forms::ColumnHeader ());
			this->Megjegyzesek = (gcnew System::Windows::Forms::ColumnHeader ());
			this->dataSet1 = (gcnew System::Data::DataSet ());
			this->button4 = (gcnew System::Windows::Forms::Button ());
			this->button5 = (gcnew System::Windows::Forms::Button ());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox ());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->contextMenuStrip1->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource2))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource3))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource4))->BeginInit ();
			this->menuStrip1->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit ();
			this->SuspendLayout ();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point (12, 48);
			this->button1->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size (107, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�j hely felv�tele";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler (this, &MyForm::button1_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size (20, 20);
			this->contextMenuStrip1->Items->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (1) { this->toolStripMenuItem1 });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size (150, 28);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler (this, &MyForm::contextMenuStrip1_Opening);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size (149, 24);
			this->toolStripMenuItem1->Text = L"�j id�pont";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point (165, 48);
			this->button2->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size (107, 75);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Hely szerkeszt�se";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler (this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point (319, 48);
			this->button3->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size (107, 75);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Hely t�rl�se";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler (this, &MyForm::button3_Click);
			// 
			// bindingSource2
			// 
			this->bindingSource2->CurrentChanged += gcnew System::EventHandler (this, &MyForm::bindingSource2_CurrentChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point (16, 206);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size (102, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Kor�bbi helyek";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size (20, 20);
			this->menuStrip1->Items->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (5) {
				this->�jId�pontFelv�teleToolStripMenuItem,
					this->rendez�sToolStripMenuItem, this->inform�ci�kToolStripMenuItem, this->kil�p�sToolStripMenuItem, this->toolStripMenuItem2
			});
			this->menuStrip1->Location = System::Drawing::Point (0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding (5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size (1800, 28);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �jId�pontFelv�teleToolStripMenuItem
			// 
			this->�jId�pontFelv�teleToolStripMenuItem->Name = L"�jId�pontFelv�teleToolStripMenuItem";
			this->�jId�pontFelv�teleToolStripMenuItem->Size = System::Drawing::Size (127, 24);
			this->�jId�pontFelv�teleToolStripMenuItem->Text = L"�j hely felv�tele";
			this->�jId�pontFelv�teleToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::�jId�pontFelv�teleToolStripMenuItem_Click);
			// 
			// rendez�sToolStripMenuItem
			// 
			this->rendez�sToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (5) {
				this->elnevez�sSzerintToolStripMenuItem,
					this->n�vSzerintToolStripMenuItem, this->c�mSzerintToolStripMenuItem, this->d�tumSzerintToolStripMenuItem, this->hozz�ad�sD�tumaSzerintToolStripMenuItem
			});
			this->rendez�sToolStripMenuItem->Name = L"rendez�sToolStripMenuItem";
			this->rendez�sToolStripMenuItem->Size = System::Drawing::Size (84, 24);
			this->rendez�sToolStripMenuItem->Text = L"Rendez�s";
			// 
			// elnevez�sSzerintToolStripMenuItem
			// 
			this->elnevez�sSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->cs�kken�ToolStripMenuItem,
					this->n�vekv�ToolStripMenuItem
			});
			this->elnevez�sSzerintToolStripMenuItem->Name = L"elnevez�sSzerintToolStripMenuItem";
			this->elnevez�sSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->elnevez�sSzerintToolStripMenuItem->Text = L"Elnevez�s szerint";
			// 
			// cs�kken�ToolStripMenuItem
			// 
			this->cs�kken�ToolStripMenuItem->Name = L"cs�kken�ToolStripMenuItem";
			this->cs�kken�ToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->cs�kken�ToolStripMenuItem->Text = L"Cs�kken�";
			this->cs�kken�ToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::cs�kken�ToolStripMenuItem_Click);
			// 
			// n�vekv�ToolStripMenuItem
			// 
			this->n�vekv�ToolStripMenuItem->Name = L"n�vekv�ToolStripMenuItem";
			this->n�vekv�ToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->n�vekv�ToolStripMenuItem->Text = L"N�vekv�";
			this->n�vekv�ToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::n�vekv�ToolStripMenuItem_Click);
			// 
			// n�vSzerintToolStripMenuItem
			// 
			this->n�vSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->cs�kken�ToolStripMenuItem1,
					this->n�vekv�ToolStripMenuItem
			});
			this->n�vSzerintToolStripMenuItem->Name = L"n�vSzerintToolStripMenuItem";
			this->n�vSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->n�vSzerintToolStripMenuItem->Text = L"N�v szerint";
			// 
			// cs�kken�ToolStripMenuItem1
			// 
			this->cs�kken�ToolStripMenuItem1->Name = L"cs�kken�ToolStripMenuItem1";
			this->cs�kken�ToolStripMenuItem1->Size = System::Drawing::Size (147, 26);
			this->cs�kken�ToolStripMenuItem1->Text = L"Cs�kken�";
			this->cs�kken�ToolStripMenuItem1->Click += gcnew System::EventHandler (this, &MyForm::cs�kken�ToolStripMenuItem1_Click);
			// 
			// n�vekv�ToolStripMenuItem
			// 
			this->n�vekv�ToolStripMenuItem->Name = L"n�vekv�ToolStripMenuItem";
			this->n�vekv�ToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->n�vekv�ToolStripMenuItem->Text = L"N�vekv�";
			this->n�vekv�ToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::n�vekv�ToolStripMenuItem_Click);
			// 
			// c�mSzerintToolStripMenuItem
			// 
			this->c�mSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->cs�kken�ToolStripMenuItem2,
					this->n�vekv�ToolStripMenuItem1
			});
			this->c�mSzerintToolStripMenuItem->Name = L"c�mSzerintToolStripMenuItem";
			this->c�mSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->c�mSzerintToolStripMenuItem->Text = L"C�m szerint";
			// 
			// cs�kken�ToolStripMenuItem2
			// 
			this->cs�kken�ToolStripMenuItem2->Name = L"cs�kken�ToolStripMenuItem2";
			this->cs�kken�ToolStripMenuItem2->Size = System::Drawing::Size (147, 26);
			this->cs�kken�ToolStripMenuItem2->Text = L"Cs�kken�";
			this->cs�kken�ToolStripMenuItem2->Click += gcnew System::EventHandler (this, &MyForm::cs�kken�ToolStripMenuItem2_Click);
			// 
			// n�vekv�ToolStripMenuItem1
			// 
			this->n�vekv�ToolStripMenuItem1->Name = L"n�vekv�ToolStripMenuItem1";
			this->n�vekv�ToolStripMenuItem1->Size = System::Drawing::Size (147, 26);
			this->n�vekv�ToolStripMenuItem1->Text = L"N�vekv�";
			this->n�vekv�ToolStripMenuItem1->Click += gcnew System::EventHandler (this, &MyForm::n�vekv�ToolStripMenuItem1_Click);
			// 
			// d�tumSzerintToolStripMenuItem
			// 
			this->d�tumSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->cs�kken�ToolStripMenuItem3,
					this->n�vekv�ToolStripMenuItem2
			});
			this->d�tumSzerintToolStripMenuItem->Name = L"d�tumSzerintToolStripMenuItem";
			this->d�tumSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->d�tumSzerintToolStripMenuItem->Text = L"D�tum szerint";
			// 
			// cs�kken�ToolStripMenuItem3
			// 
			this->cs�kken�ToolStripMenuItem3->Name = L"cs�kken�ToolStripMenuItem3";
			this->cs�kken�ToolStripMenuItem3->Size = System::Drawing::Size (147, 26);
			this->cs�kken�ToolStripMenuItem3->Text = L"Cs�kken�";
			this->cs�kken�ToolStripMenuItem3->Click += gcnew System::EventHandler (this, &MyForm::cs�kken�ToolStripMenuItem3_Click);
			// 
			// n�vekv�ToolStripMenuItem2
			// 
			this->n�vekv�ToolStripMenuItem2->Name = L"n�vekv�ToolStripMenuItem2";
			this->n�vekv�ToolStripMenuItem2->Size = System::Drawing::Size (147, 26);
			this->n�vekv�ToolStripMenuItem2->Text = L"N�vekv�";
			this->n�vekv�ToolStripMenuItem2->Click += gcnew System::EventHandler (this, &MyForm::n�vekv�ToolStripMenuItem2_Click);
			// 
			// hozz�ad�sD�tumaSzerintToolStripMenuItem
			// 
			this->hozz�ad�sD�tumaSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->cs�kken�ToolStripMenuItem4,
					this->n�vekv�ToolStripMenuItem3
			});
			this->hozz�ad�sD�tumaSzerintToolStripMenuItem->Name = L"hozz�ad�sD�tumaSzerintToolStripMenuItem";
			this->hozz�ad�sD�tumaSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->hozz�ad�sD�tumaSzerintToolStripMenuItem->Text = L"Hozz�ad�s d�tuma szerint";
			// 
			// cs�kken�ToolStripMenuItem4
			// 
			this->cs�kken�ToolStripMenuItem4->Name = L"cs�kken�ToolStripMenuItem4";
			this->cs�kken�ToolStripMenuItem4->Size = System::Drawing::Size (147, 26);
			this->cs�kken�ToolStripMenuItem4->Text = L"Cs�kken�";
			this->cs�kken�ToolStripMenuItem4->Click += gcnew System::EventHandler (this, &MyForm::cs�kken�ToolStripMenuItem4_Click);
			// 
			// n�vekv�ToolStripMenuItem3
			// 
			this->n�vekv�ToolStripMenuItem3->Name = L"n�vekv�ToolStripMenuItem3";
			this->n�vekv�ToolStripMenuItem3->Size = System::Drawing::Size (147, 26);
			this->n�vekv�ToolStripMenuItem3->Text = L"N�vekv�";
			this->n�vekv�ToolStripMenuItem3->Click += gcnew System::EventHandler (this, &MyForm::n�vekv�ToolStripMenuItem3_Click);
			// 
			// inform�ci�kToolStripMenuItem
			// 
			this->inform�ci�kToolStripMenuItem->Name = L"inform�ci�kToolStripMenuItem";
			this->inform�ci�kToolStripMenuItem->Size = System::Drawing::Size (100, 24);
			this->inform�ci�kToolStripMenuItem->Text = L"Inform�ci�k";
			this->inform�ci�kToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::inform�ci�kToolStripMenuItem_Click);
			// 
			// kil�p�sToolStripMenuItem
			// 
			this->kil�p�sToolStripMenuItem->Name = L"kil�p�sToolStripMenuItem";
			this->kil�p�sToolStripMenuItem->Size = System::Drawing::Size (69, 24);
			this->kil�p�sToolStripMenuItem->Text = L"Kil�p�s";
			this->kil�p�sToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::kil�p�sToolStripMenuItem_Click);
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange (gcnew cli::array< System::Windows::Forms::ColumnHeader^  > (7) {
				this->helyNeve, this->helyCime,
					this->alanyNeve, this->telefonSzam, this->datum, this->hozzaadva, this->Megjegyzesek
			});
/*			this->listView2->Resize = true;*/
			this->listView2->FullRowSelect = true;
			this->listView2->GridLines = true;
			this->listView2->Location = System::Drawing::Point (12, 224);
			this->listView2->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size (1772, 381);
			this->listView2->TabIndex = 19;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			this->listView2->SelectedIndexChanged += gcnew System::EventHandler (this, &MyForm::listView2_SelectedIndexChanged);
			// 
			// helyNeve
			// 
			this->helyNeve->Text = L"Elnevez�s";
			this->helyNeve->Width = 200;
			// 
			// helyCime
			// 
			this->helyCime->DisplayIndex = 2;
			this->helyCime->Text = L"C�m";
			this->helyCime->Width = 334;
			// 
			// alanyNeve
			// 
			this->alanyNeve->DisplayIndex = 1;
			this->alanyNeve->Text = L"N�v";
			this->alanyNeve->Width = 216;
			// 
			// telefonSzam
			// 
			this->telefonSzam->Text = L"Telefonsz�m";
			this->telefonSzam->Width = 253;
			// 
			// datum
			// 
			this->datum->Text = L"D�tum";
			this->datum->Width = 312;
			// 
			// hozzaadva
			// 
			this->hozzaadva->Text = L"Hozz�adva";
			this->hozzaadva->Width = 164;
			// 
			// Megjegyzesek
			// 
			this->Megjegyzesek->Text = L"Megjegyz�sek";
			this->Megjegyzesek->Width = 284;
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point (475, 48);
			this->button4->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size (107, 75);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Keres�s";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler (this, &MyForm::button4_Click_1);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point (822, 177);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size (93, 42);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Megtekint";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler (this, &MyForm::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point (618, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size (297, 140);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 22;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler (this, &MyForm::pictureBox1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size (90, 24);
			this->toolStripMenuItem2->Text = L"Export�l�s";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler (this, &MyForm::toolStripMenuItem2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (1800, 617);
			this->Controls->Add (this->pictureBox1);
			this->Controls->Add (this->button5);
			this->Controls->Add (this->button4);
			this->Controls->Add (this->listView2);
			this->Controls->Add (this->menuStrip1);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->button3);
			this->Controls->Add (this->button2);
			this->Controls->Add (this->button1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Kor�bbi helyek";
			this->Load += gcnew System::EventHandler (this, &MyForm::MyForm_Load);
			this->contextMenuStrip1->ResumeLayout (false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource2))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource3))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource4))->EndInit ();
			this->menuStrip1->ResumeLayout (false);
			this->menuStrip1->PerformLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit ();
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void button1_Click (System::Object^  sender, System::EventArgs^  e) {
		MyForm2 f(dataBase, listView2);
		f.ShowDialog ();
		dataBase->SetSelectedIndex (-1);
		dataBase->SetMultipleSelected (false);
	}
	private: System::Void textBox1_TextChanged (System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void listBox1_SelectedIndexChanged (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void contextMenuStrip1_Opening (System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void bindingNavigator1_RefreshItems (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bindingSource2_CurrentChanged (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void �jId�pontFelv�teleToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	MyForm2 f(dataBase, listView2);
	f.ShowDialog ();
	dataBase->SetMultipleSelected (false);
	dataBase->SetSelectedIndex (-1);
}
private: System::Void dataGridView1_CellContentClick (System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void textBox1_TextChanged_1 (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click (System::Object^  sender, System::EventArgs^  e) {
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
		FuB::Data* dataAcessor = dataBase->GetData ();
		int size;
		std::wstring m_filePathTo (dataAcessor[var].GetFilePathTo (size));
		System::String^ s_filePathTo = gcnew String (m_filePathTo.c_str ());
		if (s_filePathTo->Length > 1 && s_filePathTo[m_filePathTo.size () - 1] != 'f' && s_filePathTo[m_filePathTo.size () - 1] != 'F') {
			button5->Enabled = true;
			this->button5->Visible = true;
			pictureBox1->ImageLocation = s_filePathTo;
		} else if (s_filePathTo->Length > 1 && (s_filePathTo[m_filePathTo.size () - 1] == 'f' || s_filePathTo[m_filePathTo.size () - 1] == 'F')) {
			button5->Enabled = true;
			this->button5->Visible = true;
			//pictureBox1->ImageLocation = s_filePathTo;
			//default pdf kep megjelenitese
		} else {
			this->button5->Visible = false;
			button5->Enabled = false;
			pictureBox1->ImageLocation = nullptr;
		}
		dataBase->SetSelectedIndex (var);
		dataBase->SetMultipleSelected (false);
	}
	else if (listView2->SelectedItems->Count > 1) {
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBase->SetSelectedIndex (-1);
		if (listView2->SelectedItems->Count < prevMultipleSelectedCount) {
			dataBase->SetMultipleSelected (false);
		}
		prevMultipleSelectedCount = listView2->SelectedItems->Count;
		int var;
		for (int lcount = 0; lcount <= listView2->Items->Count - 1; lcount++)
		{
			if (listView2->Items[lcount]->Selected == true)
			{
				var = lcount;
				dataBase->AddToMultipleSelect (var);
			}
		}
	} else {
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBase->SetSelectedIndex (-1);
		dataBase->SetMultipleSelected (false);
	}

}
private: System::Void kil�p�sToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	this->Close ();
}
private: System::Void button3_Click (System::Object^  sender, System::EventArgs^  e) {
	if (dataBase->IsMultipleselected () || dataBase->GetSelectedIndex () != -1) {
		MyForm1 f (dataBase, listView2);
		f.ShowDialog ();
		pictureBox1->ImageLocation = nullptr;
		button5->Enabled = false;
		this->button5->Visible = false;
		ReDrawListView (dataBase, listView2);
	} else {
		//printf: nincs mit torolni
	}
}
private: System::Void button2_Click (System::Object^  sender, System::EventArgs^  e) {
	if (!dataBase->IsMultipleselected () && dataBase->GetSelectedIndex () != -1) {
		MyForm3 f (dataBase, listView2);
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		f.ShowDialog ();
		dataBase->SetSelectedIndex (-1);
	}
}
private: System::Void inform�ci�kToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void folderBrowserDialog1_HelpRequest (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click_1 (System::Object^  sender, System::EventArgs^  e) {
	button5->Enabled = false;
	this->button5->Visible = false;
	pictureBox1->ImageLocation = nullptr;
	Kereses k (dataBase);
	k.ShowDialog ();
	ReDrawListView (dataBase, listView2);
	dataBase->SetSelectedIndex (-1);
	dataBase->SetMultipleSelected (false);
}
private: System::Void cs�kken�ToolStripMenuItem4_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddedDateDown ();
	ReDrawListView (dataBase, listView2);
}

private: System::Void n�vekv�ToolStripMenuItem3_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddedDateUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void button5_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Show Picture
	ShowPicture (dataBase);
	dataBase->SetSelectedIndex (-1);
	dataBase->SetMultipleSelected (false);
}
private: System::Void pictureBox1_Click (System::Object^  sender, System::EventArgs^  e) {
	//Clicked action: Show Picture
	ShowPicture (dataBase);
	dataBase->SetSelectedIndex (-1);
	dataBase->SetMultipleSelected (false);
}
private: System::Void cs�kken�ToolStripMenuItem3_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDateDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void n�vekv�ToolStripMenuItem2_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddedDateUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void cs�kken�ToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDataNameDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void n�vekv�ToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDataNameUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void cs�kken�ToolStripMenuItem1_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByNameDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void n�vekv�ToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByNameUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void cs�kken�ToolStripMenuItem2_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddressDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void n�vekv�ToolStripMenuItem1_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddressUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void dateTimePicker1_ValueChanged (System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripMenuItem2_Click (System::Object^  sender, System::EventArgs^  e) {
	if (dataBase->IsMultipleselected () || dataBase->GetSelectedIndex () != -1) {
		SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog ();
		saveFileDialog->Filter = "CSV file (*.csv)|*.csv";
		saveFileDialog->Title = "Export�l�s";
		saveFileDialog->FileName = ".csv";

		if (dataBase->GetSelectedIndex () != -1 && !dataBase->IsMultipleselected()) {
			if(saveFileDialog->ShowDialog () == System::Windows::Forms::DialogResult::OK)
				CsvExportOneRecord (dataBase, saveFileDialog->FileName);
		} else if(dataBase->GetSelectedIndex () == -1 && dataBase->IsMultipleselected ()){
			if (saveFileDialog->ShowDialog () == System::Windows::Forms::DialogResult::OK)
				CsvExportMultipleRecord (dataBase, saveFileDialog->FileName);
		}
		this->button5->Visible = false;
		button5->Enabled = false;
		pictureBox1->ImageLocation = nullptr;
		dataBase->SetSelectedIndex (-1);
	}
}
};
}
