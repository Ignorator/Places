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
	private: System::Windows::Forms::ToolStripMenuItem^  rendezésToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elnevezésSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  csökkenõToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  növekvõToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  névSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  csökkenõToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  nõvekvõToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  címSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  csökkenõToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  nõvekvõToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  dátumSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  csökkenõToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  nõvekvõToolStripMenuItem2;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColumnHeader^  hozzaadva;
	private: System::Windows::Forms::ToolStripMenuItem^  hozzáadásDátumaSzerintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  csökkenõToolStripMenuItem4;

	private: System::Windows::Forms::ToolStripMenuItem^  nõvekvõToolStripMenuItem3;
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
	private: System::Windows::Forms::ToolStripMenuItem^  újIdõpontFelvételeToolStripMenuItem;






	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::ColumnHeader^  helyNeve;
	private: System::Windows::Forms::ColumnHeader^  helyCime;
	private: System::Windows::Forms::ColumnHeader^  alanyNeve;
	private: System::Windows::Forms::ColumnHeader^  telefonSzam;
	private: System::Windows::Forms::ColumnHeader^  datum;


	private: System::Windows::Forms::ToolStripMenuItem^  információkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kilépésToolStripMenuItem;
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
			this->újIdõpontFelvételeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->rendezésToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->elnevezésSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->csökkenõToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->növekvõToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->névSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->csökkenõToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->nõvekvõToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->címSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->csökkenõToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->nõvekvõToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->dátumSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->csökkenõToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->nõvekvõToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->hozzáadásDátumaSzerintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->csökkenõToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->nõvekvõToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->információkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
			this->kilépésToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem ());
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
			this->button1->Text = L"Új hely felvétele";
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
			this->toolStripMenuItem1->Text = L"Új idõpont";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point (165, 48);
			this->button2->Margin = System::Windows::Forms::Padding (3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size (107, 75);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Hely szerkesztése";
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
			this->button3->Text = L"Hely törlése";
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
			this->label1->Text = L"Korábbi helyek";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size (20, 20);
			this->menuStrip1->Items->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (5) {
				this->újIdõpontFelvételeToolStripMenuItem,
					this->rendezésToolStripMenuItem, this->információkToolStripMenuItem, this->kilépésToolStripMenuItem, this->toolStripMenuItem2
			});
			this->menuStrip1->Location = System::Drawing::Point (0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding (5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size (1800, 28);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// újIdõpontFelvételeToolStripMenuItem
			// 
			this->újIdõpontFelvételeToolStripMenuItem->Name = L"újIdõpontFelvételeToolStripMenuItem";
			this->újIdõpontFelvételeToolStripMenuItem->Size = System::Drawing::Size (127, 24);
			this->újIdõpontFelvételeToolStripMenuItem->Text = L"Új hely felvétele";
			this->újIdõpontFelvételeToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::újIdõpontFelvételeToolStripMenuItem_Click);
			// 
			// rendezésToolStripMenuItem
			// 
			this->rendezésToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (5) {
				this->elnevezésSzerintToolStripMenuItem,
					this->névSzerintToolStripMenuItem, this->címSzerintToolStripMenuItem, this->dátumSzerintToolStripMenuItem, this->hozzáadásDátumaSzerintToolStripMenuItem
			});
			this->rendezésToolStripMenuItem->Name = L"rendezésToolStripMenuItem";
			this->rendezésToolStripMenuItem->Size = System::Drawing::Size (84, 24);
			this->rendezésToolStripMenuItem->Text = L"Rendezés";
			// 
			// elnevezésSzerintToolStripMenuItem
			// 
			this->elnevezésSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->csökkenõToolStripMenuItem,
					this->növekvõToolStripMenuItem
			});
			this->elnevezésSzerintToolStripMenuItem->Name = L"elnevezésSzerintToolStripMenuItem";
			this->elnevezésSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->elnevezésSzerintToolStripMenuItem->Text = L"Elnevezés szerint";
			// 
			// csökkenõToolStripMenuItem
			// 
			this->csökkenõToolStripMenuItem->Name = L"csökkenõToolStripMenuItem";
			this->csökkenõToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->csökkenõToolStripMenuItem->Text = L"Csökkenõ";
			this->csökkenõToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::csökkenõToolStripMenuItem_Click);
			// 
			// növekvõToolStripMenuItem
			// 
			this->növekvõToolStripMenuItem->Name = L"növekvõToolStripMenuItem";
			this->növekvõToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->növekvõToolStripMenuItem->Text = L"Növekvõ";
			this->növekvõToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::növekvõToolStripMenuItem_Click);
			// 
			// névSzerintToolStripMenuItem
			// 
			this->névSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->csökkenõToolStripMenuItem1,
					this->nõvekvõToolStripMenuItem
			});
			this->névSzerintToolStripMenuItem->Name = L"névSzerintToolStripMenuItem";
			this->névSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->névSzerintToolStripMenuItem->Text = L"Név szerint";
			// 
			// csökkenõToolStripMenuItem1
			// 
			this->csökkenõToolStripMenuItem1->Name = L"csökkenõToolStripMenuItem1";
			this->csökkenõToolStripMenuItem1->Size = System::Drawing::Size (147, 26);
			this->csökkenõToolStripMenuItem1->Text = L"Csökkenõ";
			this->csökkenõToolStripMenuItem1->Click += gcnew System::EventHandler (this, &MyForm::csökkenõToolStripMenuItem1_Click);
			// 
			// nõvekvõToolStripMenuItem
			// 
			this->nõvekvõToolStripMenuItem->Name = L"nõvekvõToolStripMenuItem";
			this->nõvekvõToolStripMenuItem->Size = System::Drawing::Size (147, 26);
			this->nõvekvõToolStripMenuItem->Text = L"Nõvekvõ";
			this->nõvekvõToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::nõvekvõToolStripMenuItem_Click);
			// 
			// címSzerintToolStripMenuItem
			// 
			this->címSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->csökkenõToolStripMenuItem2,
					this->nõvekvõToolStripMenuItem1
			});
			this->címSzerintToolStripMenuItem->Name = L"címSzerintToolStripMenuItem";
			this->címSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->címSzerintToolStripMenuItem->Text = L"Cím szerint";
			// 
			// csökkenõToolStripMenuItem2
			// 
			this->csökkenõToolStripMenuItem2->Name = L"csökkenõToolStripMenuItem2";
			this->csökkenõToolStripMenuItem2->Size = System::Drawing::Size (147, 26);
			this->csökkenõToolStripMenuItem2->Text = L"Csökkenõ";
			this->csökkenõToolStripMenuItem2->Click += gcnew System::EventHandler (this, &MyForm::csökkenõToolStripMenuItem2_Click);
			// 
			// nõvekvõToolStripMenuItem1
			// 
			this->nõvekvõToolStripMenuItem1->Name = L"nõvekvõToolStripMenuItem1";
			this->nõvekvõToolStripMenuItem1->Size = System::Drawing::Size (147, 26);
			this->nõvekvõToolStripMenuItem1->Text = L"Nõvekvõ";
			this->nõvekvõToolStripMenuItem1->Click += gcnew System::EventHandler (this, &MyForm::nõvekvõToolStripMenuItem1_Click);
			// 
			// dátumSzerintToolStripMenuItem
			// 
			this->dátumSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->csökkenõToolStripMenuItem3,
					this->nõvekvõToolStripMenuItem2
			});
			this->dátumSzerintToolStripMenuItem->Name = L"dátumSzerintToolStripMenuItem";
			this->dátumSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->dátumSzerintToolStripMenuItem->Text = L"Dátum szerint";
			// 
			// csökkenõToolStripMenuItem3
			// 
			this->csökkenõToolStripMenuItem3->Name = L"csökkenõToolStripMenuItem3";
			this->csökkenõToolStripMenuItem3->Size = System::Drawing::Size (147, 26);
			this->csökkenõToolStripMenuItem3->Text = L"Csökkenõ";
			this->csökkenõToolStripMenuItem3->Click += gcnew System::EventHandler (this, &MyForm::csökkenõToolStripMenuItem3_Click);
			// 
			// nõvekvõToolStripMenuItem2
			// 
			this->nõvekvõToolStripMenuItem2->Name = L"nõvekvõToolStripMenuItem2";
			this->nõvekvõToolStripMenuItem2->Size = System::Drawing::Size (147, 26);
			this->nõvekvõToolStripMenuItem2->Text = L"Nõvekvõ";
			this->nõvekvõToolStripMenuItem2->Click += gcnew System::EventHandler (this, &MyForm::nõvekvõToolStripMenuItem2_Click);
			// 
			// hozzáadásDátumaSzerintToolStripMenuItem
			// 
			this->hozzáadásDátumaSzerintToolStripMenuItem->DropDownItems->AddRange (gcnew cli::array< System::Windows::Forms::ToolStripItem^  > (2) {
				this->csökkenõToolStripMenuItem4,
					this->nõvekvõToolStripMenuItem3
			});
			this->hozzáadásDátumaSzerintToolStripMenuItem->Name = L"hozzáadásDátumaSzerintToolStripMenuItem";
			this->hozzáadásDátumaSzerintToolStripMenuItem->Size = System::Drawing::Size (259, 26);
			this->hozzáadásDátumaSzerintToolStripMenuItem->Text = L"Hozzáadás dátuma szerint";
			// 
			// csökkenõToolStripMenuItem4
			// 
			this->csökkenõToolStripMenuItem4->Name = L"csökkenõToolStripMenuItem4";
			this->csökkenõToolStripMenuItem4->Size = System::Drawing::Size (147, 26);
			this->csökkenõToolStripMenuItem4->Text = L"Csökkenõ";
			this->csökkenõToolStripMenuItem4->Click += gcnew System::EventHandler (this, &MyForm::csökkenõToolStripMenuItem4_Click);
			// 
			// nõvekvõToolStripMenuItem3
			// 
			this->nõvekvõToolStripMenuItem3->Name = L"nõvekvõToolStripMenuItem3";
			this->nõvekvõToolStripMenuItem3->Size = System::Drawing::Size (147, 26);
			this->nõvekvõToolStripMenuItem3->Text = L"Nõvekvõ";
			this->nõvekvõToolStripMenuItem3->Click += gcnew System::EventHandler (this, &MyForm::nõvekvõToolStripMenuItem3_Click);
			// 
			// információkToolStripMenuItem
			// 
			this->információkToolStripMenuItem->Name = L"információkToolStripMenuItem";
			this->információkToolStripMenuItem->Size = System::Drawing::Size (100, 24);
			this->információkToolStripMenuItem->Text = L"Információk";
			this->információkToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::információkToolStripMenuItem_Click);
			// 
			// kilépésToolStripMenuItem
			// 
			this->kilépésToolStripMenuItem->Name = L"kilépésToolStripMenuItem";
			this->kilépésToolStripMenuItem->Size = System::Drawing::Size (69, 24);
			this->kilépésToolStripMenuItem->Text = L"Kilépés";
			this->kilépésToolStripMenuItem->Click += gcnew System::EventHandler (this, &MyForm::kilépésToolStripMenuItem_Click);
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
			this->hozzaadva->Width = 164;
			// 
			// Megjegyzesek
			// 
			this->Megjegyzesek->Text = L"Megjegyzések";
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
			this->button4->Text = L"Keresés";
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
			this->toolStripMenuItem2->Text = L"Exportálás";
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
			this->Text = L"Korábbi helyek";
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
private: System::Void újIdõpontFelvételeToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void kilépésToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void információkToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void csökkenõToolStripMenuItem4_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddedDateDown ();
	ReDrawListView (dataBase, listView2);
}

private: System::Void nõvekvõToolStripMenuItem3_Click (System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void csökkenõToolStripMenuItem3_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDateDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void nõvekvõToolStripMenuItem2_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddedDateUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void csökkenõToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDataNameDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void növekvõToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByDataNameUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void csökkenõToolStripMenuItem1_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByNameDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void nõvekvõToolStripMenuItem_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByNameUp ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void csökkenõToolStripMenuItem2_Click (System::Object^  sender, System::EventArgs^  e) {
	FuB::Sorts s (dataBase);
	s.SortByAddressDown ();
	ReDrawListView (dataBase, listView2);
}
private: System::Void nõvekvõToolStripMenuItem1_Click (System::Object^  sender, System::EventArgs^  e) {
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
		saveFileDialog->Title = "Exportálás";
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
