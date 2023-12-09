#pragma once

#include "Algo.h"
#include "Book.h"
#include "Database.h"
#include "HashTable.h"
#include "RBTree.h"
#include <sstream>
#include <string>
#include <msclr/marshal_cppstd.h>

tree_elem_generic<int>* nullnode_int = null_init_generic<int>();
tree_elem_generic<std::string>* nullnode = null_init_generic<std::string>();
tree_elem_generic<std::string>* genreTree = root_init_generic(nullnode);
tree_elem_generic<std::string>* authorTree = root_init_generic(nullnode);
tree_elem_generic<std::string>* nameTree = root_init_generic(nullnode);
tree_elem_generic<int>* yearTree = root_init_generic(nullnode_int);

bool download = false;
std::vector<Book> books;
Database database;
int size = database.loadFromDatabaseFile("books.txt");
HashTable ht(size);

namespace code {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Button^ ExportButton;
	private: System::Media::SoundPlayer^ successSound;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ YearFrom;
	private: System::Windows::Forms::TextBox^ AuthorBox;
	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::TextBox^ GenreBox;
	private: System::Windows::Forms::TextBox^ YearTo;
	private: System::Windows::Forms::Button^ SearchGenre;
	private: System::Windows::Forms::Button^ SearchYear;
	private: System::Windows::Forms::Button^ SearchAuthor;
	private: System::Windows::Forms::Button^ SearchName;
	private: System::Windows::Forms::TextBox^ addYear;
	private: System::Windows::Forms::TextBox^ addAuthor;
	private: System::Windows::Forms::TextBox^ addName;
	private: System::Windows::Forms::TextBox^ addGenre;
	private: System::Windows::Forms::Button^ Del;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ comboSearchAuthor;
	private: System::Windows::Forms::TextBox^ comboSearchName;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ clearFind;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BookName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FIO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Genre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::Button^ clearCombo;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::Button^ ImportButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->successSound = (gcnew System::Media::SoundPlayer());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			   this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->ExportButton = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->ImportButton = (gcnew System::Windows::Forms::Button());
			   this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			   this->clearFind = (gcnew System::Windows::Forms::Button());
			   this->Del = (gcnew System::Windows::Forms::Button());
			   this->Add = (gcnew System::Windows::Forms::Button());
			   this->addYear = (gcnew System::Windows::Forms::TextBox());
			   this->addAuthor = (gcnew System::Windows::Forms::TextBox());
			   this->addName = (gcnew System::Windows::Forms::TextBox());
			   this->addGenre = (gcnew System::Windows::Forms::TextBox());
			   this->SearchYear = (gcnew System::Windows::Forms::Button());
			   this->SearchAuthor = (gcnew System::Windows::Forms::Button());
			   this->SearchName = (gcnew System::Windows::Forms::Button());
			   this->SearchGenre = (gcnew System::Windows::Forms::Button());
			   this->YearTo = (gcnew System::Windows::Forms::TextBox());
			   this->YearFrom = (gcnew System::Windows::Forms::TextBox());
			   this->AuthorBox = (gcnew System::Windows::Forms::TextBox());
			   this->NameBox = (gcnew System::Windows::Forms::TextBox());
			   this->GenreBox = (gcnew System::Windows::Forms::TextBox());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->BookName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->FIO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Genre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			   this->clearCombo = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->comboSearchAuthor = (gcnew System::Windows::Forms::TextBox());
			   this->comboSearchName = (gcnew System::Windows::Forms::TextBox());
			   this->label15 = (gcnew System::Windows::Forms::Label());
			   this->label16 = (gcnew System::Windows::Forms::Label());
			   this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			   this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			   this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->tabControl1->SuspendLayout();
			   this->tabPage1->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   this->tabPage2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->tabPage3->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->tabPage4->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			   this->tabPage5->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // successSound
			   // 
			   this->successSound->LoadTimeout = 10000;
			   this->successSound->SoundLocation = L"resourses\\success.wav";
			   this->successSound->Stream = nullptr;
			   this->successSound->Tag = nullptr;
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 1;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel1->Controls->Add(this->tabControl1, 0, 0);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 1;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1120, 777);
			   this->tableLayoutPanel1->TabIndex = 5;
			   // 
			   // tabControl1
			   // 
			   this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->tabControl1->Controls->Add(this->tabPage1);
			   this->tabControl1->Controls->Add(this->tabPage2);
			   this->tabControl1->Controls->Add(this->tabPage3);
			   this->tabControl1->Controls->Add(this->tabPage4);
			   this->tabControl1->Controls->Add(this->tabPage5);
			   this->tabControl1->Location = System::Drawing::Point(3, 3);
			   this->tabControl1->Multiline = true;
			   this->tabControl1->Name = L"tabControl1";
			   this->tabControl1->SelectedIndex = 0;
			   this->tabControl1->Size = System::Drawing::Size(1114, 771);
			   this->tabControl1->TabIndex = 5;
			   // 
			   // tabPage1
			   // 
			   this->tabPage1->Controls->Add(this->groupBox1);
			   this->tabPage1->Location = System::Drawing::Point(4, 22);
			   this->tabPage1->Name = L"tabPage1";
			   this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage1->Size = System::Drawing::Size(1106, 745);
			   this->tabPage1->TabIndex = 0;
			   this->tabPage1->Text = L"Файлы";
			   this->tabPage1->UseVisualStyleBackColor = true;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Controls->Add(this->ExportButton);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->ImportButton);
			   this->groupBox1->Location = System::Drawing::Point(284, 40);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(505, 446);
			   this->groupBox1->TabIndex = 12;
			   this->groupBox1->TabStop = false;
			   // 
			   // label3
			   // 
			   this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label3->Location = System::Drawing::Point(77, 73);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(361, 18);
			   this->label3->TabIndex = 11;
			   this->label3->Text = L"Путь \"Книги\": ./books.txt";
			   this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // ExportButton
			   // 
			   this->ExportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			   this->ExportButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->ExportButton->Location = System::Drawing::Point(196, 248);
			   this->ExportButton->MaximumSize = System::Drawing::Size(125, 30);
			   this->ExportButton->Name = L"ExportButton";
			   this->ExportButton->Size = System::Drawing::Size(125, 30);
			   this->ExportButton->TabIndex = 5;
			   this->ExportButton->Text = L"Экспортировать";
			   this->ExportButton->UseVisualStyleBackColor = true;
			   this->ExportButton->Click += gcnew System::EventHandler(this, &MyForm::exportButton_Click);
			   // 
			   // label2
			   // 
			   this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label2->Location = System::Drawing::Point(77, 214);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(361, 18);
			   this->label2->TabIndex = 10;
			   this->label2->Text = L"Путь \"Книги\": ./books.txt";
			   this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // ImportButton
			   // 
			   this->ImportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			   this->ImportButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->ImportButton->Location = System::Drawing::Point(196, 105);
			   this->ImportButton->MaximumSize = System::Drawing::Size(125, 30);
			   this->ImportButton->Name = L"ImportButton";
			   this->ImportButton->Size = System::Drawing::Size(125, 30);
			   this->ImportButton->TabIndex = 3;
			   this->ImportButton->Text = L"Импортировать";
			   this->ImportButton->UseVisualStyleBackColor = true;
			   this->ImportButton->Click += gcnew System::EventHandler(this, &MyForm::ImportButton_Click);
			   // 
			   // tabPage2
			   // 
			   this->tabPage2->Controls->Add(this->clearFind);
			   this->tabPage2->Controls->Add(this->Del);
			   this->tabPage2->Controls->Add(this->Add);
			   this->tabPage2->Controls->Add(this->addYear);
			   this->tabPage2->Controls->Add(this->addAuthor);
			   this->tabPage2->Controls->Add(this->addName);
			   this->tabPage2->Controls->Add(this->addGenre);
			   this->tabPage2->Controls->Add(this->SearchYear);
			   this->tabPage2->Controls->Add(this->SearchAuthor);
			   this->tabPage2->Controls->Add(this->SearchName);
			   this->tabPage2->Controls->Add(this->SearchGenre);
			   this->tabPage2->Controls->Add(this->YearTo);
			   this->tabPage2->Controls->Add(this->YearFrom);
			   this->tabPage2->Controls->Add(this->AuthorBox);
			   this->tabPage2->Controls->Add(this->NameBox);
			   this->tabPage2->Controls->Add(this->GenreBox);
			   this->tabPage2->Controls->Add(this->label14);
			   this->tabPage2->Controls->Add(this->label13);
			   this->tabPage2->Controls->Add(this->label12);
			   this->tabPage2->Controls->Add(this->label11);
			   this->tabPage2->Controls->Add(this->label10);
			   this->tabPage2->Controls->Add(this->label9);
			   this->tabPage2->Controls->Add(this->label8);
			   this->tabPage2->Controls->Add(this->label7);
			   this->tabPage2->Controls->Add(this->label6);
			   this->tabPage2->Controls->Add(this->label5);
			   this->tabPage2->Controls->Add(this->label4);
			   this->tabPage2->Controls->Add(this->dataGridView1);
			   this->tabPage2->Location = System::Drawing::Point(4, 22);
			   this->tabPage2->Name = L"tabPage2";
			   this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage2->Size = System::Drawing::Size(1106, 745);
			   this->tabPage2->TabIndex = 1;
			   this->tabPage2->Text = L"Книги";
			   this->tabPage2->UseVisualStyleBackColor = true;
			   // 
			   // clearFind
			   // 
			   this->clearFind->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->clearFind->Location = System::Drawing::Point(730, 131);
			   this->clearFind->Name = L"clearFind";
			   this->clearFind->Size = System::Drawing::Size(263, 32);
			   this->clearFind->TabIndex = 28;
			   this->clearFind->Text = L"Очистить поиск";
			   this->clearFind->UseVisualStyleBackColor = true;
			   this->clearFind->Click += gcnew System::EventHandler(this, &MyForm::clearFind_Click);
			   // 
			   // Del
			   // 
			   this->Del->Location = System::Drawing::Point(738, 568);
			   this->Del->Name = L"Del";
			   this->Del->Size = System::Drawing::Size(156, 33);
			   this->Del->TabIndex = 27;
			   this->Del->Text = L"Удалить";
			   this->Del->UseVisualStyleBackColor = true;
			   this->Del->Click += gcnew System::EventHandler(this, &MyForm::Del_Click);
			   // 
			   // Add
			   // 
			   this->Add->Location = System::Drawing::Point(545, 568);
			   this->Add->Name = L"Add";
			   this->Add->Size = System::Drawing::Size(156, 33);
			   this->Add->TabIndex = 26;
			   this->Add->Text = L"Добавить";
			   this->Add->UseVisualStyleBackColor = true;
			   this->Add->Click += gcnew System::EventHandler(this, &MyForm::Add_Click);
			   // 
			   // addYear
			   // 
			   this->addYear->ForeColor = System::Drawing::Color::Gray;
			   this->addYear->Location = System::Drawing::Point(738, 485);
			   this->addYear->Name = L"addYear";
			   this->addYear->Size = System::Drawing::Size(55, 20);
			   this->addYear->TabIndex = 25;
			   this->addYear->Text = L"ex. 2023";
			   this->addYear->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->addYear->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->addYear->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // addAuthor
			   // 
			   this->addAuthor->ForeColor = System::Drawing::Color::Gray;
			   this->addAuthor->Location = System::Drawing::Point(738, 451);
			   this->addAuthor->Name = L"addAuthor";
			   this->addAuthor->Size = System::Drawing::Size(132, 20);
			   this->addAuthor->TabIndex = 23;
			   this->addAuthor->Text = L"ex. Ivanov Ivan Ivanovich";
			   this->addAuthor->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->addAuthor->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->addAuthor->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // addName
			   // 
			   this->addName->ForeColor = System::Drawing::Color::Gray;
			   this->addName->Location = System::Drawing::Point(738, 414);
			   this->addName->Name = L"addName";
			   this->addName->Size = System::Drawing::Size(132, 20);
			   this->addName->TabIndex = 22;
			   this->addName->Text = L"ex. Master i Margarita";
			   this->addName->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->addName->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->addName->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // addGenre
			   // 
			   this->addGenre->ForeColor = System::Drawing::Color::Gray;
			   this->addGenre->Location = System::Drawing::Point(738, 518);
			   this->addGenre->Name = L"addGenre";
			   this->addGenre->Size = System::Drawing::Size(132, 20);
			   this->addGenre->TabIndex = 21;
			   this->addGenre->Text = L"ex. Fantasy";
			   this->addGenre->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->addGenre->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->addGenre->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // SearchYear
			   // 
			   this->SearchYear->Location = System::Drawing::Point(920, 308);
			   this->SearchYear->Name = L"SearchYear";
			   this->SearchYear->Size = System::Drawing::Size(71, 20);
			   this->SearchYear->TabIndex = 20;
			   this->SearchYear->Text = L"Найти";
			   this->SearchYear->UseVisualStyleBackColor = true;
			   this->SearchYear->Click += gcnew System::EventHandler(this, &MyForm::SearchYear_Click);
			   // 
			   // SearchAuthor
			   // 
			   this->SearchAuthor->Location = System::Drawing::Point(920, 267);
			   this->SearchAuthor->Name = L"SearchAuthor";
			   this->SearchAuthor->Size = System::Drawing::Size(72, 20);
			   this->SearchAuthor->TabIndex = 19;
			   this->SearchAuthor->Text = L"Найти";
			   this->SearchAuthor->UseVisualStyleBackColor = true;
			   this->SearchAuthor->Click += gcnew System::EventHandler(this, &MyForm::SearchAuthor_Click);
			   // 
			   // SearchName
			   // 
			   this->SearchName->Location = System::Drawing::Point(920, 227);
			   this->SearchName->Name = L"SearchName";
			   this->SearchName->Size = System::Drawing::Size(73, 20);
			   this->SearchName->TabIndex = 18;
			   this->SearchName->Text = L"Найти";
			   this->SearchName->UseVisualStyleBackColor = true;
			   this->SearchName->Click += gcnew System::EventHandler(this, &MyForm::SearchName_Click);
			   // 
			   // SearchGenre
			   // 
			   this->SearchGenre->Location = System::Drawing::Point(920, 187);
			   this->SearchGenre->Name = L"SearchGenre";
			   this->SearchGenre->Size = System::Drawing::Size(73, 20);
			   this->SearchGenre->TabIndex = 17;
			   this->SearchGenre->Text = L"Найти";
			   this->SearchGenre->UseVisualStyleBackColor = true;
			   this->SearchGenre->Click += gcnew System::EventHandler(this, &MyForm::SearchGenre_Click);
			   // 
			   // YearTo
			   // 
			   this->YearTo->ForeColor = System::Drawing::Color::Gray;
			   this->YearTo->Location = System::Drawing::Point(815, 308);
			   this->YearTo->Name = L"YearTo";
			   this->YearTo->Size = System::Drawing::Size(55, 20);
			   this->YearTo->TabIndex = 16;
			   this->YearTo->Text = L"ex. 2023";
			   this->YearTo->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->YearTo->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->YearTo->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // YearFrom
			   // 
			   this->YearFrom->ForeColor = System::Drawing::Color::Gray;
			   this->YearFrom->Location = System::Drawing::Point(738, 308);
			   this->YearFrom->Name = L"YearFrom";
			   this->YearFrom->Size = System::Drawing::Size(55, 20);
			   this->YearFrom->TabIndex = 15;
			   this->YearFrom->Text = L"ex. 1943";
			   this->YearFrom->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->YearFrom->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->YearFrom->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // AuthorBox
			   // 
			   this->AuthorBox->ForeColor = System::Drawing::Color::Gray;
			   this->AuthorBox->Location = System::Drawing::Point(738, 267);
			   this->AuthorBox->Name = L"AuthorBox";
			   this->AuthorBox->Size = System::Drawing::Size(132, 20);
			   this->AuthorBox->TabIndex = 14;
			   this->AuthorBox->Text = L"ex. Ivanov Ivan Ivanovich";
			   this->AuthorBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->AuthorBox->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->AuthorBox->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // NameBox
			   // 
			   this->NameBox->ForeColor = System::Drawing::Color::Gray;
			   this->NameBox->Location = System::Drawing::Point(738, 227);
			   this->NameBox->Name = L"NameBox";
			   this->NameBox->Size = System::Drawing::Size(132, 20);
			   this->NameBox->TabIndex = 13;
			   this->NameBox->Text = L"ex. Master i Margarita";
			   this->NameBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->NameBox->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->NameBox->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // GenreBox
			   // 
			   this->GenreBox->ForeColor = System::Drawing::Color::Gray;
			   this->GenreBox->Location = System::Drawing::Point(738, 187);
			   this->GenreBox->Name = L"GenreBox";
			   this->GenreBox->Size = System::Drawing::Size(132, 20);
			   this->GenreBox->TabIndex = 12;
			   this->GenreBox->Text = L"ex. Fantasy";
			   this->GenreBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->GenreBox->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->GenreBox->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label14->Location = System::Drawing::Point(542, 518);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(48, 20);
			   this->label14->TabIndex = 11;
			   this->label14->Text = L"Жанр";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label13->Location = System::Drawing::Point(541, 483);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(33, 20);
			   this->label13->TabIndex = 10;
			   this->label13->Text = L"Год";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label12->Location = System::Drawing::Point(541, 449);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(98, 20);
			   this->label12->TabIndex = 9;
			   this->label12->Text = L"Автор (ФИО)";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label11->Location = System::Drawing::Point(542, 412);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(77, 20);
			   this->label11->TabIndex = 8;
			   this->label11->Text = L"Название";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label10->Location = System::Drawing::Point(541, 355);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(266, 32);
			   this->label10->TabIndex = 7;
			   this->label10->Text = L"Добавление/Удаление";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label9->Location = System::Drawing::Point(543, 308);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(33, 20);
			   this->label9->TabIndex = 6;
			   this->label9->Text = L"Год";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label8->Location = System::Drawing::Point(543, 267);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(51, 20);
			   this->label8->TabIndex = 5;
			   this->label8->Text = L"Автор";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label7->Location = System::Drawing::Point(542, 227);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(77, 20);
			   this->label7->TabIndex = 4;
			   this->label7->Text = L"Название";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label6->Location = System::Drawing::Point(543, 187);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(48, 20);
			   this->label6->TabIndex = 3;
			   this->label6->Text = L"Жанр";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label5->Location = System::Drawing::Point(540, 131);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(82, 32);
			   this->label5->TabIndex = 2;
			   this->label5->Text = L"Поиск";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label4->Location = System::Drawing::Point(538, 38);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(107, 45);
			   this->label4->TabIndex = 1;
			   this->label4->Text = L"Книги";
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->AllowUserToOrderColumns = true;
			   this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->Column6,
					   this->BookName, this->FIO, this->Year, this->Genre
			   });
			   this->dataGridView1->GridColor = System::Drawing::SystemColors::Window;
			   this->dataGridView1->Location = System::Drawing::Point(3, 3);
			   this->dataGridView1->MinimumSize = System::Drawing::Size(500, 350);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->RowHeadersWidth = 40;
			   this->dataGridView1->Size = System::Drawing::Size(500, 350);
			   this->dataGridView1->TabIndex = 0;
			   // 
			   // Column6
			   // 
			   this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			   this->Column6->Frozen = true;
			   this->Column6->HeaderText = L"№";
			   this->Column6->MinimumWidth = 30;
			   this->Column6->Name = L"Column6";
			   this->Column6->ReadOnly = true;
			   this->Column6->Width = 43;
			   // 
			   // BookName
			   // 
			   this->BookName->DividerWidth = 1;
			   this->BookName->Frozen = true;
			   this->BookName->HeaderText = L"Название";
			   this->BookName->MinimumWidth = 150;
			   this->BookName->Name = L"BookName";
			   this->BookName->ReadOnly = true;
			   this->BookName->Width = 150;
			   // 
			   // FIO
			   // 
			   this->FIO->DividerWidth = 1;
			   this->FIO->Frozen = true;
			   this->FIO->HeaderText = L"ФИО";
			   this->FIO->MinimumWidth = 180;
			   this->FIO->Name = L"FIO";
			   this->FIO->ReadOnly = true;
			   this->FIO->Width = 180;
			   // 
			   // Year
			   // 
			   this->Year->DividerWidth = 1;
			   this->Year->Frozen = true;
			   this->Year->HeaderText = L"Год";
			   this->Year->MinimumWidth = 60;
			   this->Year->Name = L"Year";
			   this->Year->ReadOnly = true;
			   this->Year->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			   this->Year->Width = 60;
			   // 
			   // Genre
			   // 
			   this->Genre->DividerWidth = 1;
			   this->Genre->Frozen = true;
			   this->Genre->HeaderText = L"Жанр";
			   this->Genre->MinimumWidth = 70;
			   this->Genre->Name = L"Genre";
			   this->Genre->ReadOnly = true;
			   this->Genre->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			   this->Genre->Width = 70;
			   // 
			   // tabPage3
			   // 
			   this->tabPage3->Controls->Add(this->pictureBox2);
			   this->tabPage3->Controls->Add(this->label1);
			   this->tabPage3->Location = System::Drawing::Point(4, 22);
			   this->tabPage3->Name = L"tabPage3";
			   this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage3->Size = System::Drawing::Size(1106, 745);
			   this->tabPage3->TabIndex = 2;
			   this->tabPage3->Text = L"Покупки";
			   this->tabPage3->UseVisualStyleBackColor = true;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(44, 18);
			   this->pictureBox2->MinimumSize = System::Drawing::Size(391, 416);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(936, 610);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox2->TabIndex = 3;
			   this->pictureBox2->TabStop = false;
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->Location = System::Drawing::Point(317, 654);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(368, 21);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Данный справочник находится в разработке";
			   this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // tabPage4
			   // 
			   this->tabPage4->Controls->Add(this->clearCombo);
			   this->tabPage4->Controls->Add(this->button3);
			   this->tabPage4->Controls->Add(this->comboSearchAuthor);
			   this->tabPage4->Controls->Add(this->comboSearchName);
			   this->tabPage4->Controls->Add(this->label15);
			   this->tabPage4->Controls->Add(this->label16);
			   this->tabPage4->Controls->Add(this->dataGridView3);
			   this->tabPage4->Location = System::Drawing::Point(4, 22);
			   this->tabPage4->Name = L"tabPage4";
			   this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage4->Size = System::Drawing::Size(1106, 745);
			   this->tabPage4->TabIndex = 3;
			   this->tabPage4->Text = L"Поиск";
			   this->tabPage4->UseVisualStyleBackColor = true;
			   // 
			   // clearCombo
			   // 
			   this->clearCombo->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->clearCombo->Location = System::Drawing::Point(438, 516);
			   this->clearCombo->Name = L"clearCombo";
			   this->clearCombo->Size = System::Drawing::Size(166, 60);
			   this->clearCombo->TabIndex = 25;
			   this->clearCombo->Text = L"Очистить";
			   this->clearCombo->UseVisualStyleBackColor = true;
			   this->clearCombo->Click += gcnew System::EventHandler(this, &MyForm::clearCombo_Click);
			   // 
			   // button3
			   // 
			   this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button3->Location = System::Drawing::Point(438, 424);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(166, 60);
			   this->button3->TabIndex = 24;
			   this->button3->Text = L"Найти";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::SearchCombo_Click);
			   // 
			   // comboSearchAuthor
			   // 
			   this->comboSearchAuthor->ForeColor = System::Drawing::Color::Gray;
			   this->comboSearchAuthor->Location = System::Drawing::Point(260, 464);
			   this->comboSearchAuthor->Name = L"comboSearchAuthor";
			   this->comboSearchAuthor->Size = System::Drawing::Size(132, 20);
			   this->comboSearchAuthor->TabIndex = 23;
			   this->comboSearchAuthor->Text = L"ex. Ivanov Ivan Ivanovich";
			   this->comboSearchAuthor->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->comboSearchAuthor->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->comboSearchAuthor->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // comboSearchName
			   // 
			   this->comboSearchName->ForeColor = System::Drawing::Color::Gray;
			   this->comboSearchName->Location = System::Drawing::Point(260, 424);
			   this->comboSearchName->Name = L"comboSearchName";
			   this->comboSearchName->Size = System::Drawing::Size(132, 20);
			   this->comboSearchName->TabIndex = 22;
			   this->comboSearchName->Text = L"ex. Master i Margarita";
			   this->comboSearchName->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox_TextChanged);
			   this->comboSearchName->Enter += gcnew System::EventHandler(this, &MyForm::TextBox_Enter);
			   this->comboSearchName->Leave += gcnew System::EventHandler(this, &MyForm::TextBox_Leave);
			   // 
			   // label15
			   // 
			   this->label15->AutoSize = true;
			   this->label15->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label15->Location = System::Drawing::Point(65, 464);
			   this->label15->Name = L"label15";
			   this->label15->Size = System::Drawing::Size(51, 20);
			   this->label15->TabIndex = 21;
			   this->label15->Text = L"Автор";
			   // 
			   // label16
			   // 
			   this->label16->AutoSize = true;
			   this->label16->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label16->Location = System::Drawing::Point(64, 424);
			   this->label16->Name = L"label16";
			   this->label16->Size = System::Drawing::Size(77, 20);
			   this->label16->TabIndex = 20;
			   this->label16->Text = L"Название";
			   // 
			   // dataGridView3
			   // 
			   this->dataGridView3->AllowUserToAddRows = false;
			   this->dataGridView3->AllowUserToDeleteRows = false;
			   this->dataGridView3->AllowUserToOrderColumns = true;
			   this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::Window;
			   this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->dataGridViewTextBoxColumn1,
					   this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			   });
			   this->dataGridView3->GridColor = System::Drawing::SystemColors::Window;
			   this->dataGridView3->Location = System::Drawing::Point(0, 0);
			   this->dataGridView3->Name = L"dataGridView3";
			   this->dataGridView3->ReadOnly = true;
			   this->dataGridView3->RowHeadersVisible = false;
			   this->dataGridView3->RowHeadersWidth = 51;
			   this->dataGridView3->Size = System::Drawing::Size(577, 376);
			   this->dataGridView3->TabIndex = 3;
			   // 
			   // dataGridViewTextBoxColumn1
			   // 
			   this->dataGridViewTextBoxColumn1->HeaderText = L"Номер";
			   this->dataGridViewTextBoxColumn1->MinimumWidth = 65;
			   this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			   this->dataGridViewTextBoxColumn1->ReadOnly = true;
			   this->dataGridViewTextBoxColumn1->Width = 65;
			   // 
			   // dataGridViewTextBoxColumn2
			   // 
			   this->dataGridViewTextBoxColumn2->HeaderText = L"Название";
			   this->dataGridViewTextBoxColumn2->MinimumWidth = 150;
			   this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			   this->dataGridViewTextBoxColumn2->ReadOnly = true;
			   this->dataGridViewTextBoxColumn2->Width = 150;
			   // 
			   // dataGridViewTextBoxColumn3
			   // 
			   this->dataGridViewTextBoxColumn3->HeaderText = L"Автор";
			   this->dataGridViewTextBoxColumn3->MinimumWidth = 180;
			   this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			   this->dataGridViewTextBoxColumn3->ReadOnly = true;
			   this->dataGridViewTextBoxColumn3->Width = 180;
			   // 
			   // dataGridViewTextBoxColumn4
			   // 
			   this->dataGridViewTextBoxColumn4->HeaderText = L"Год";
			   this->dataGridViewTextBoxColumn4->MinimumWidth = 60;
			   this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			   this->dataGridViewTextBoxColumn4->ReadOnly = true;
			   this->dataGridViewTextBoxColumn4->Width = 60;
			   // 
			   // dataGridViewTextBoxColumn5
			   // 
			   this->dataGridViewTextBoxColumn5->HeaderText = L"Жанр";
			   this->dataGridViewTextBoxColumn5->MinimumWidth = 70;
			   this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			   this->dataGridViewTextBoxColumn5->ReadOnly = true;
			   this->dataGridViewTextBoxColumn5->Width = 125;
			   // 
			   // tabPage5
			   // 
			   this->tabPage5->Controls->Add(this->treeView1);
			   this->tabPage5->Controls->Add(this->button5);
			   this->tabPage5->Controls->Add(this->button7);
			   this->tabPage5->Controls->Add(this->button4);
			   this->tabPage5->Controls->Add(this->button2);
			   this->tabPage5->Controls->Add(this->button8);
			   this->tabPage5->Controls->Add(this->button6);
			   this->tabPage5->Controls->Add(this->dataGridView2);
			   this->tabPage5->Controls->Add(this->button1);
			   this->tabPage5->Location = System::Drawing::Point(4, 22);
			   this->tabPage5->Name = L"tabPage5";
			   this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage5->Size = System::Drawing::Size(1106, 745);
			   this->tabPage5->TabIndex = 4;
			   this->tabPage5->Text = L"Отладка";
			   this->tabPage5->UseVisualStyleBackColor = true;
			   // 
			   // treeView1
			   // 
			   this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->treeView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->treeView1->ItemHeight = 16;
			   this->treeView1->Location = System::Drawing::Point(579, 12);
			   this->treeView1->MaximumSize = System::Drawing::Size(700, 600);
			   this->treeView1->Name = L"treeView1";
			   this->treeView1->Size = System::Drawing::Size(514, 472);
			   this->treeView1->TabIndex = 14;
			   // 
			   // button5
			   // 
			   this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button5->Location = System::Drawing::Point(754, 575);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(160, 23);
			   this->button5->TabIndex = 13;
			   this->button5->Text = L"Дерево (ключ - год)";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &MyForm::debugYear);
			   // 
			   // button7
			   // 
			   this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button7->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button7->Location = System::Drawing::Point(754, 547);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(160, 23);
			   this->button7->TabIndex = 12;
			   this->button7->Text = L"Дерево (ключ - ФИО)";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &MyForm::debugAuthor);
			   // 
			   // button4
			   // 
			   this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button4->Location = System::Drawing::Point(754, 520);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(160, 23);
			   this->button4->TabIndex = 11;
			   this->button4->Text = L"Дерево (ключ - название)";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &MyForm::debugName);
			   // 
			   // button2
			   // 
			   this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button2->Location = System::Drawing::Point(754, 491);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(160, 23);
			   this->button2->TabIndex = 10;
			   this->button2->Text = L"Дерево (ключ - жанр)";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::debugGenre);
			   // 
			   // button8
			   // 
			   this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button8->AutoSize = true;
			   this->button8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button8->Location = System::Drawing::Point(754, 609);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(160, 45);
			   this->button8->TabIndex = 9;
			   this->button8->Text = L"Очистить";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &MyForm::debugTreedel);
			   // 
			   // button6
			   // 
			   this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->button6->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button6->Location = System::Drawing::Point(201, 604);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(160, 50);
			   this->button6->TabIndex = 7;
			   this->button6->Text = L"Очистить";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &MyForm::debugHTdel);
			   // 
			   // dataGridView2
			   // 
			   this->dataGridView2->AllowUserToAddRows = false;
			   this->dataGridView2->AllowUserToDeleteRows = false;
			   this->dataGridView2->AllowUserToOrderColumns = true;
			   this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Window;
			   this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				   this->Column1,
					   this->Column2, this->Column3, this->Column4, this->Column5, this->Column7
			   });
			   this->dataGridView2->GridColor = System::Drawing::SystemColors::Window;
			   this->dataGridView2->Location = System::Drawing::Point(-4, 12);
			   this->dataGridView2->Name = L"dataGridView2";
			   this->dataGridView2->ReadOnly = true;
			   this->dataGridView2->RowHeadersVisible = false;
			   this->dataGridView2->RowHeadersWidth = 51;
			   this->dataGridView2->Size = System::Drawing::Size(577, 473);
			   this->dataGridView2->TabIndex = 2;
			   // 
			   // button1
			   // 
			   this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button1->Location = System::Drawing::Point(201, 491);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(160, 23);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Хеш-таблица (Книга+ФИО)";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::debugHT);
			   // 
			   // Column1
			   // 
			   this->Column1->HeaderText = L"Index";
			   this->Column1->MinimumWidth = 40;
			   this->Column1->Name = L"Column1";
			   this->Column1->ReadOnly = true;
			   this->Column1->Width = 40;
			   // 
			   // Column2
			   // 
			   this->Column2->HeaderText = L"Key";
			   this->Column2->MinimumWidth = 6;
			   this->Column2->Name = L"Column2";
			   this->Column2->ReadOnly = true;
			   this->Column2->Width = 160;
			   // 
			   // Column3
			   // 
			   this->Column3->HeaderText = L"Value";
			   this->Column3->MinimumWidth = 6;
			   this->Column3->Name = L"Column3";
			   this->Column3->ReadOnly = true;
			   this->Column3->Width = 130;
			   // 
			   // Column4
			   // 
			   this->Column4->HeaderText = L"Status";
			   this->Column4->MinimumWidth = 40;
			   this->Column4->Name = L"Column4";
			   this->Column4->ReadOnly = true;
			   this->Column4->Width = 40;
			   // 
			   // Column5
			   // 
			   this->Column5->HeaderText = L"Hash";
			   this->Column5->MinimumWidth = 6;
			   this->Column5->Name = L"Column5";
			   this->Column5->ReadOnly = true;
			   // 
			   // Column7
			   // 
			   this->Column7->HeaderText = L"Second hash";
			   this->Column7->Name = L"Column7";
			   this->Column7->ReadOnly = true;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				   static_cast<System::Int32>(static_cast<System::Byte>(15)));
			   this->ClientSize = System::Drawing::Size(1120, 777);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MinimumSize = System::Drawing::Size(540, 658);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Онлайн библиотека";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tabControl1->ResumeLayout(false);
			   this->tabPage1->ResumeLayout(false);
			   this->groupBox1->ResumeLayout(false);
			   this->tabPage2->ResumeLayout(false);
			   this->tabPage2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->tabPage3->ResumeLayout(false);
			   this->tabPage3->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->tabPage4->ResumeLayout(false);
			   this->tabPage4->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			   this->tabPage5->ResumeLayout(false);
			   this->tabPage5->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			   this->ResumeLayout(false);

		   }
	#pragma endregion

		private: static void ShowErrorAndReturn(System::String^ errorMessage) {
			System::Windows::Forms::MessageBox::Show(errorMessage, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		private: System::String^ ConvertBookToString(const Book& book, char r) {
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			if (r != 'b') {
				sb->Append(gcnew System::String(book.bookname.c_str()));
				sb->Append(":");
			}
			if (r != 'a') {
				sb->Append(gcnew System::String((book.fio.surname.substr(0, 4) + " " + book.fio.name.substr(0, 4) + " " + book.fio.patronymic.substr(0, 4) + " ").c_str()));
				sb->Append(":");
			}
			if (r != 'y') {
				sb->Append(book.year.ToString());
				sb->Append(":");
			}
			if (r != 'g') {
				sb->Append(gcnew System::String(book.genre.c_str()));
			}
			return sb->ToString();
		}

		private: System::Void exportButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (download) {
				try {
					System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(Convert::ToString("books.txt"));
					if (writer) {
						for (int i = 0; i < books.size(); i++) {
							System::String^ line = gcnew System::String(books[i].bookname.c_str()) + ":" +
								gcnew System::String((books[i].fio.surname + " " + books[i].fio.name + " " + books[i].fio.patronymic).c_str()) + ":" +
								gcnew System::String(books[i].year.ToString()) + ":" +
								gcnew System::String(books[i].genre.c_str());
							writer->WriteLine(line);
						}
						successSound->Play();
						System::Windows::Forms::MessageBox::Show("Данные успешно записаны в файл.", "Успех", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
					}
				}
				catch (System::Exception^ ex) {
					System::Windows::Forms::MessageBox::Show("Не удалось открыть файл для записи. " + ex->Message, "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				}
			}
			else {
				System::Windows::Forms::MessageBox::Show("Загрузите файл перед записью!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		private: System::Void ImportButton_Click(System::Object^ sender, System::EventArgs^ e) {
			download = true;
			ht.clear();
			genreTree = root_init_generic<std::string>(nullnode);
			authorTree = root_init_generic(nullnode);
			nameTree = root_init_generic(nullnode);
			yearTree = root_init_generic(nullnode_int);
			successSound->Play();
			System::Windows::Forms::MessageBox::Show("Данные успешно загружены!", "Успех", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
			books.clear();
			books = database.getAllBooks();
			dataGridView1->Rows->Clear();
			int num = 0;
			for (Book& book : books) {
				book.index = num;
				num++;
				dataGridView1->Rows->Add(gcnew array<String^> {
					gcnew String(Convert::ToString(num)),
						gcnew String(book.bookname.c_str()),
						gcnew String((book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic).c_str()), Convert::ToString(book.year),
						gcnew String(book.genre.c_str())
				});
				ht.add(book.bookname, book.fio.surname, book.fio.name, book.fio.patronymic, book.year, book.genre, num - 1);
				insert(genreTree, nullnode, book.genre, num - 1);
				insert(authorTree, nullnode, book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic, num - 1);
				insert(nameTree, nullnode, book.bookname, num - 1);
				insert(yearTree, nullnode_int, book.year, num - 1);
			}
		}

		private: System::String^ GetPlaceholderText(System::String^ elementName) {
				if (elementName == "GenreBox" || elementName == "addGenre") {
					return "ex. Fantasy";
				}
				if (elementName == "AuthorBox" || elementName == "addAuthor" || elementName == "comboSearchAuthor") {
					return "ex. Ivanov Ivan Ivanovich";
				}
				if (elementName == "NameBox" || elementName == "addName" || elementName == "comboSearchName") {
					return "ex. Master i Margarita";
				}
				if (elementName == "YearFrom") {
					return "ex. 1943";
				}
				if (elementName == "YearTo" || elementName == "addYear") {
					return "ex. 2023";
				}
				return ""; // Если нет совпадений
		}

		private: System::Void UpdateTextBox(System::Windows::Forms::TextBox^ textBox, System::String^ fill, System::Drawing::Color textColor) {
			textBox->Text = fill;
			textBox->ForeColor = textColor;
		}

		private: System::Void TextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(sender);
			System::String^ elementName = textBox->Name;
			System::String^ fill = GetPlaceholderText(elementName);

			if (textBox->Text == fill)
			{
				UpdateTextBox(textBox, "", SystemColors::WindowText);
			}
		}

		private: System::Void TextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(sender);

			if (System::String::IsNullOrWhiteSpace(textBox->Text))
			{
				System::String^ elementName = textBox->Name;
				System::String^ fill = GetPlaceholderText(elementName);

				UpdateTextBox(textBox, fill, System::Drawing::Color::Gray);
			}
		}

		private: System::Void TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(sender);
			System::String^ elementName = textBox->Name;
			System::String^ fill = GetPlaceholderText(elementName);

			if (textBox->Text != fill)
			{
				textBox->ForeColor = SystemColors::WindowText;
			}
		}

		private: System::Void clearCombo_Click(System::Object^ sender, System::EventArgs^ e) {
			dataGridView3->Rows->Clear();
			this->comboSearchName->ForeColor = System::Drawing::Color::Gray;
			this->comboSearchName->Text = L"ex. Master i Margarita";
			this->comboSearchAuthor->ForeColor = System::Drawing::Color::Gray;
			this->comboSearchAuthor->Text = L"ex. Ivanov Ivan Ivanovich";
		}

		private: System::Void PerformSearch(tree_elem_generic<std::string>* tree, System::Windows::Forms::TextBox^ textBox, Func<String^, bool>^ isValid, std::string prompt) {
			System::String^ searchText = textBox->Text;
			if (isValid(searchText)) {
				print(tree, nullnode, 3, 1);
				std::string searchStr = msclr::interop::marshal_as<std::string>(searchText);
				tree_elem_generic<std::string>* result = search(tree, nullnode, searchStr);

				if (result != nullnode) {
					dataGridView1->Rows->Clear();
					list_elem* temp = result->list;

					do {
						int i = temp->key;
						dataGridView1->Rows->Add(gcnew array<String^> {
							gcnew String(Convert::ToString(i + 1)),
								gcnew String(books[i].bookname.c_str()),
								gcnew String((books[i].fio.surname + " " + books[i].fio.name + " " + books[i].fio.patronymic).c_str()),
								Convert::ToString(books[i].year),
								gcnew String(books[i].genre.c_str())
						});
						temp = temp->next;
					} while (temp != result->list);

					successSound->Play();
					textBox->Text = gcnew String(prompt.c_str());
					textBox->ForeColor = System::Drawing::Color::Gray;
				}
				else {
					textBox->Text = gcnew String(prompt.c_str());
					textBox->ForeColor = System::Drawing::Color::Gray;
					System::Windows::Forms::MessageBox::Show("Записи не найдены.", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
							   
				}
			}
		}

		private: System::Void SearchGenre_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			PerformSearch(genreTree, GenreBox, gcnew Func<String^, bool>(IsValidGenre), "ex. Fantasy");
		}

		private: System::Void SearchName_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			PerformSearch(nameTree, NameBox, gcnew Func<String^, bool>(IsValidBookTitle), "ex. Master i Margarita");
		}

		private: System::Void SearchAuthor_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			PerformSearch(authorTree, AuthorBox, gcnew Func<String^, bool>(IsValidFIO), "ex. Ivanov Ivan Ivanovich");
		}

		private: System::Void SearchYear_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			System::String^ yearFromText = YearFrom->Text;
			System::String^ yearToText = YearTo->Text;

			if (IsValidYear(yearFromText) && IsValidYear(yearToText)) {
				int yearFrom, yearTo;
				System::Int32::TryParse(yearFromText, yearFrom);
				System::Int32::TryParse(yearToText, yearTo);

				if (yearFrom <= yearTo) {
					list_elem* result_list = list_init();
					search_between(yearTree, nullnode_int, yearFrom, yearTo, result_list);

					if (result_list != nullptr) {
						dataGridView1->Rows->Clear();
						int count = 0;
						list_elem* temp = result_list;

						do {
							int i = temp->key;
							temp = temp->next;
							count++;
						} while (temp != result_list);

						int* indices = new int[count];
						temp = result_list;

						for (int i = 0; i < count; i++) {
							indices[i] = temp->key;
							temp = temp->next;
						}

						for (int i = 0; i < count - 1; i++) {
							for (int j = 0; j < count - i - 1; j++) {
								if (indices[j] > indices[j + 1]) {
									int temp = indices[j];
									indices[j] = indices[j + 1];
									indices[j + 1] = temp;
								}
							}
						}

						for (int i = 0; i < count; i++) {
							int index = indices[i];
							dataGridView1->Rows->Add(gcnew array<String^> {
								gcnew String(Convert::ToString(index + 1)),
									gcnew String(books[index].bookname.c_str()),
									gcnew String((books[index].fio.surname + " " + books[index].fio.name + " " + books[index].fio.patronymic).c_str()),
									Convert::ToString(books[index].year),
									gcnew String(books[index].genre.c_str())
							});
						}

						successSound->Play();
						this->YearFrom->Text = "ex. 1943";
						this->YearTo->Text = "ex. 2023";
						YearFrom->ForeColor = System::Drawing::Color::Gray;
						YearTo->ForeColor = System::Drawing::Color::Gray;
						delete[] indices;
					}
					else {
						this->YearFrom->Text = "ex. 1943";
						this->YearTo->Text = "ex. 2023";
						YearFrom->ForeColor = System::Drawing::Color::Gray;
						YearTo->ForeColor = System::Drawing::Color::Gray;
						System::Windows::Forms::MessageBox::Show("Записи не найдены.", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
				}
				else {
					System::Windows::Forms::MessageBox::Show("Год 'с' не может быть больше года 'до'.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				System::Windows::Forms::MessageBox::Show("Пожалуйста, введите допустимые года в формате от 0 до 2023.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void Update_Combo() {
			this->comboSearchAuthor->ForeColor = System::Drawing::Color::Gray;
			this->comboSearchName->ForeColor = System::Drawing::Color::Gray;
			comboSearchAuthor->Text = "ex. Ivanov Ivan Ivanovich";
			comboSearchName->Text = "ex. Master i Margarita";
		}

		private: System::Void SearchCombo_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			System::String^ authorText = comboSearchAuthor->Text;
			System::String^ bookTitleText = comboSearchName->Text;
			std::string authorTextstr;
			std::string bookTitleTextstr;
			bool found = false;
			for each (char c in authorText)
			{
				authorTextstr.push_back(static_cast<char>(c));
			}
			for each (char c in bookTitleText)
			{
				bookTitleTextstr.push_back(static_cast<char>(c));
			}
			std::istringstream iss(authorTextstr);
			std::vector<std::string> words;
			do {
				std::string word;
				iss >> word;
				words.push_back(word);
			} while (iss);
			if (IsValidBookTitle(bookTitleText))
			{
				if (IsValidFIO(authorText)) {
					if (words.size() >= 3) {
						Book book = ht.search(words[0], words[1], words[2], bookTitleTextstr);
						if (book.bookname != "" && book.fio.name != "" && book.fio.patronymic != "" && book.fio.surname != "" && book.genre != "") {
							found = true;
							dataGridView3->Rows->Add(gcnew array<String^> {
								gcnew String(Convert::ToString(book.index + 1)),
									gcnew String(book.bookname.c_str()),
									gcnew String((book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic).c_str()), Convert::ToString(book.year),
									gcnew String(book.genre.c_str())
							});
							System::Windows::Forms::MessageBox::Show("Запись найдена!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
					}
					else {
						Update_Combo();
						return;
					}
				}
				else {
					Update_Combo();
					return;
				}
			}
			else {
				Update_Combo();
				return; 
			}
			if (!found) System::Windows::Forms::MessageBox::Show("Запись не найдена!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Update_Combo();
		}

		private: System::Void clearFind_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			dataGridView1->Rows->Clear();
			int num = 0;
			for (Book& book : books) {
				num++;
				book.index = num - 1;
				dataGridView1->Rows->Add(gcnew array<String^> {
					gcnew String(Convert::ToString(num)),
						gcnew String(book.bookname.c_str()),
						gcnew String((book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic).c_str()), Convert::ToString(book.year),
						gcnew String(book.genre.c_str())
				});
			}
			this->GenreBox->Text = "ex. Fantasy";
			this->GenreBox->ForeColor = System::Drawing::Color::Gray;
			this->AuthorBox->Text = "ex. Ivanov Ivan Ivanovich";
			this->AuthorBox->ForeColor = System::Drawing::Color::Gray;
			this->YearFrom->Text = "ex. 1943";
			this->YearFrom->ForeColor = System::Drawing::Color::Gray;
			this->YearTo->Text = "ex. 2023";
			this->YearTo->ForeColor = System::Drawing::Color::Gray;
			this->NameBox->Text = "ex. Master i Margarita";
			this->NameBox->ForeColor = System::Drawing::Color::Gray;
		}

		private: System::Void UpdateForm() {
			addAuthor->Text = L"ex. Ivanov Ivan Ivanovich";
			addName->Text = L"ex. Master i Margarita";
			addGenre->Text = L"ex. Fantasy";
			addYear->Text = L"ex. 2023";
			addAuthor->ForeColor = System::Drawing::Color::Gray;
			addName->ForeColor = System::Drawing::Color::Gray;
			addGenre->ForeColor = System::Drawing::Color::Gray;
			addYear->ForeColor = System::Drawing::Color::Gray;
		}

		private: System::Void action(std::string act) {
			System::String^ author = this->addAuthor->Text;
			System::String^ name = this->addName->Text;
			System::String^ genre = this->addGenre->Text;
			System::String^ year = this->addYear->Text;
			
			if (!IsValidBookTitle(name)) 
				return ShowErrorAndReturn("Пожалуйста, введите корректное название книги с первой заглавной буквой (или цифрой) и буквами английского алфавита, разделенное пробелом.");
			
			if (!IsValidFIO(author))
				return ShowErrorAndReturn("Пожалуйста, введите корректное ФИО, где каждое слово начинается с заглавной буквы, и слова разделены пробелами.");

			if (act == "add") {
				if (!IsValidYear(year)) return ShowErrorAndReturn("Пожалуйста, введите допустимый год в формате от 0 до 2023.");
			}

			if (act == "add") {
				if (!IsValidGenre(genre)) return ShowErrorAndReturn("Пожалуйста, введите корректный жанр с первой заглавной буквой и буквами английского алфавита, разделенный одним пробелом.");
			}
			std::string aut = msclr::interop::marshal_as<std::string>(author);
			std::istringstream iss(aut);
			std::vector<std::string> words;
			while (iss) {
				std::string word;
				iss >> word;
				words.push_back(word);
			}

			Book book;
			book.bookname = msclr::interop::marshal_as<std::string>(name);
			book.fio.surname = words[0];
			book.fio.name = words[1];
			book.fio.patronymic = words[2];
			if (act == "add") {
				book.year = System::Convert::ToInt32(year);
				book.genre = msclr::interop::marshal_as<std::string>(genre);
			}

			Book bookcheck = ht.search(words[0], words[1], words[2], book.bookname);

			if (act == "add") {
				if (bookcheck.bookname != "" && bookcheck.fio.name != "" && bookcheck.fio.patronymic != "" && bookcheck.fio.surname != "" && bookcheck.genre != "") {
					
					return ShowErrorAndReturn("Данная книга уже существует в справочнике.");
				}

				book.index = static_cast<int>(books.size());
				books.push_back(book);
				ht.add(book.bookname, book.fio.surname, book.fio.name, book.fio.patronymic, book.year, book.genre, book.index);
				insert(genreTree, nullnode, book.genre, book.index);
				insert(authorTree, nullnode, book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic, book.index);
				insert(nameTree, nullnode, book.bookname, book.index);
				insert(yearTree, nullnode_int, book.year, book.index);
				UpdateForm();
				System::Windows::Forms::MessageBox::Show("Запись успешно добавлена!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				if (bookcheck.bookname == "" && bookcheck.fio.name == "" && bookcheck.fio.patronymic == "" && bookcheck.fio.surname == "" && bookcheck.genre == "") {
					UpdateForm();
					return ShowErrorAndReturn("Книга не найдена!");
				}
				else {
					std::cout << "Before removal: books.size() = " << books.size() << std::endl;
					std::cout << "index " << bookcheck.index << std::endl;
					int index_to_remove = bookcheck.index;
					if (!books.empty() && index_to_remove >= 0 && index_to_remove < books.size()) {
						if (index_to_remove != books.size() - 1) {
							books[index_to_remove] = std::move(books.back());
							books[index_to_remove].index = index_to_remove;
						}
						books.pop_back();
					}
					ht.remove(book.bookname, book.fio.surname, book.fio.name, book.fio.patronymic);
					erase(genreTree, nullnode, bookcheck.genre, index_to_remove);
					erase(authorTree, nullnode, book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic, index_to_remove);
					erase(nameTree, nullnode, book.bookname, index_to_remove);
					erase(yearTree, nullnode_int, bookcheck.year, index_to_remove);
					if (!books.empty() && index_to_remove != books.size()) {
						ht.updateIndex(index_to_remove);
						index_update(genreTree, nullnode, index_to_remove, static_cast<int>(books.size()));
						index_update(authorTree, nullnode, index_to_remove, static_cast<int>(books.size()));
						index_update(nameTree, nullnode, index_to_remove, static_cast<int>(books.size()));
						index_update(yearTree, nullnode_int, index_to_remove, static_cast<int>(books.size()));
					}
					UpdateForm();
					System::Windows::Forms::MessageBox::Show("Запись успешно удалена!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			dataGridView1->Rows->Clear();
			int num = 0;
			for (Book& book : books) {
				books[num].index = num;
				dataGridView1->Rows->Add(gcnew array<String^> {
					gcnew String(Convert::ToString(book.index + 1)),
						gcnew String(book.bookname.c_str()),
						gcnew String((book.fio.surname + " " + book.fio.name + " " + book.fio.patronymic).c_str()), Convert::ToString(book.year),
						gcnew String(book.genre.c_str())
				});
				num++;
			}
		}

		private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			action("add");
		}

		private: System::Void Del_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!download) {
				System::Windows::Forms::MessageBox::Show("Загрузите файл!", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			action("delete");
		}

		private: System::Void ApplyColorAndReplace(System::String^ line, System::Windows::Forms::TreeNode^ node, char replacementType) {
			if (line->Contains("BLACK")) {
				node->ForeColor = System::Drawing::Color::Black;
			}
			else if (line->Contains("RED")) {
				node->ForeColor = System::Drawing::Color::Red;
			}

			line = line->Replace("RED", "")->Replace("BLACK", "");
			array<System::String^>^ words = line->Split(' ');

			for (int i = 0; i < words->Length; ++i) {
				int value;
				if (Int32::TryParse(words[i], value)) {
					if (value >= 0 && value < static_cast<int>(books.size())) {
						System::String^ replacement = ConvertBookToString(books[value], replacementType);
						words[i] = replacement;
					}
				}
			}
			line = String::Join(" ", words)->Replace("[ ", "[")->Replace(" ]", "]");
			node->Text = line;
		}

		private: System::Void UpdateTreeView(String^ res, char replacementType) {
			array<System::String^>^ lines = res->Split(gcnew array<wchar_t>{'\n'}, StringSplitOptions::RemoveEmptyEntries);

			for each (System::String ^ line in lines) {
				System::Windows::Forms::TreeNode^ node = gcnew System::Windows::Forms::TreeNode(line);
				ApplyColorAndReplace(line, node, replacementType);
				treeView1->Nodes->Add(node);
			}

			if (res == "") {
				treeView1->Nodes->Add("Tree is empty.");
			}
			treeView1->Nodes->Add("");
		}

		private: System::Void debugGenre(System::Object^ sender, System::EventArgs^ e) {
			System::String^ res = msclr::interop::marshal_as <System::String^>(print(genreTree, nullnode, 4, 1).c_str());
			UpdateTreeView(res, 'g');
		}

		private: System::Void debugName(System::Object^ sender, System::EventArgs^ e) {
			System::String^ res = msclr::interop::marshal_as <System::String^>(print(nameTree, nullnode, 4, 1).c_str());
			UpdateTreeView(res, 'b');
		}

		private: System::Void debugAuthor(System::Object^ sender, System::EventArgs^ e) {
			System::String^ res = msclr::interop::marshal_as <System::String^>(print(authorTree, nullnode, 4, 1).c_str());
			UpdateTreeView(res, 'a');
		}

		private: System::Void debugYear(System::Object^ sender, System::EventArgs^ e) {
			System::String^ res = msclr::interop::marshal_as <System::String^>(print(yearTree, nullnode_int, 4, 1).c_str());
			UpdateTreeView(res, 'y');
		}

		private: System::Void debugTreedel(System::Object^ sender, System::EventArgs^ e) {
			treeView1->Nodes->Clear();
		}

		private: System::Void debugHT(System::Object^ sender, System::EventArgs^ e) {
			int num = 0;
			std::vector<Book> books = ht.returnTable();

			for (const Book& book : books) {
				System::String^ status = (book.bookname != "N/A") ? "[1]" : "[0]";
				System::String^ hash = (book.bookname != "N/A") ? gcnew System::String(Convert::ToString(ht.hashF(book.bookname + book.fio.surname + book.fio.name + book.fio.patronymic))) : "";
				System::String^ result = (book.bookname != "N/A") ? System::String::Format("{0}{1}", book.year, gcnew System::String(book.genre.c_str())) : "N/A";
				int hash_int = (book.bookname != "N/A") ? ht.hashF(book.bookname + book.fio.surname + book.fio.name + book.fio.patronymic) : 0;
				int secondaryhash_int = hash_int;
				int k = ht.returnK();
				System::String^ secondaryhash = "";
				if (book.bookname != "N/A") {
					while (num != (secondaryhash_int % ht.returnSize())) {
						secondaryhash_int += k;
						secondaryhash += gcnew System::String(Convert::ToString(secondaryhash_int % ht.returnSize()) + " ");
					}
				}
				dataGridView2->Rows->Add(gcnew array<String^> {
					gcnew String(Convert::ToString(num)),
						gcnew String((book.bookname + book.fio.surname + book.fio.name + book.fio.patronymic).c_str()),
						result,
						status,
						hash,
						secondaryhash
				});
				num++;
			}

			dataGridView2->Rows->Add(gcnew array<String^> { "", "", "", "", "", "" });
		}

		private: System::Void debugHTdel(System::Object^ sender, System::EventArgs^ e) {
			dataGridView2->Rows->Clear();
		}
};
}


