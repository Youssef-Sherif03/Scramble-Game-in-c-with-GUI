#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
#include <msclr/marshal_cppstd.h>

#include "Start.h"

namespace Scramble {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing; 
	using namespace System::IO;
	using namespace Globalization;

	/// <sum
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^ panel4;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ rusername;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void signup(TextBox^ b2, TextBox^ b3, TextBox^ b4)
		{
			// Save all signup form values to database
			StreamWriter^ outputfile = gcnew StreamWriter("Data\\signup_logs.txt", true);
			outputfile->WriteLine(b2->Text);
			outputfile->WriteLine(b3->Text);
			outputfile->WriteLine(b4->Text);
			outputfile->Close();

		}
		void parentID(TextBox^ b3)
		{
			// Add parent ID to database
			StreamWriter^ outputfile = gcnew StreamWriter("Data\\parentID.txt", true);
			outputfile->WriteLine(b3->Text);
			outputfile->Close();

		}
		void parentPass(TextBox^ b3)
		{
			// Add parent password to database
			StreamWriter^ outputfile = gcnew StreamWriter("Data\\parentPass.txt", true);
			outputfile->WriteLine(b3->Text);
			outputfile->Close();

		}

		void playerID(TextBox^ b3)
		{
			// Add player ID to database
			StreamWriter^ outputfile = gcnew StreamWriter("Data\\playerID.txt", true);
			outputfile->WriteLine(b3->Text);
			outputfile->Close();

			// Set default game values of all levels to 0
			StreamWriter^ lb_animals = gcnew StreamWriter("Data\\lb_animals.txt", true);
			StreamWriter^ lb_food = gcnew StreamWriter("Data\\lb_food.txt", true);
			StreamWriter^ lb_countries = gcnew StreamWriter("Data\\lb_countries.txt", true);

			lb_animals->WriteLine(0);
			lb_food->WriteLine(0);
			lb_countries->WriteLine(0);

			lb_animals->Close();
			lb_food->Close();
			lb_countries->Close();

			players[playerCount] = username;

			leaderboard_animals[playerCount] = 0;
			leaderboard_food[playerCount] = 0;
			leaderboard_countries[playerCount] = 0;

			playerCount++;
		}

		void fillarray()
		{
			ifstream fileParentID ("Data\\parentID.txt");
			ifstream fileParentPass("Data\\parentPass.txt");
			ifstream filePlayerID("Data\\playerID.txt");

			ifstream fileLeaderboardAnimals("Data\\lb_animals.txt");
			ifstream fileLeaderboardFood("Data\\lb_food.txt");
			ifstream fileLeaderboardCountries("Data\\lb_countries.txt");


			for (int i = 0; i < 100; i++)
			{
				fileParentID >> parent[i];
				fileParentPass >> password[i];
				filePlayerID >> players[i];

				fileLeaderboardAnimals >> leaderboard_animals[i];
				fileLeaderboardFood >> leaderboard_food[i];
				fileLeaderboardCountries >> leaderboard_countries[i];

				if (!players[i].empty()) playerCount++;
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->rusername = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4->SuspendLayout();
			this->panel9->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->button3);
			this->panel4->Controls->Add(this->panel8);
			this->panel4->Controls->Add(this->textBox4);
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->textBox1);
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->rusername);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(8, 8);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(423, 538);
			this->panel4->TabIndex = 10;
			this->panel4->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(217, 236);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Username already taken";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label6->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(196, 352);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(140, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Passwords are not the same";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Visible = false;
			this->label3->Click += gcnew System::EventHandler(this, &Login::label3_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(25, 19);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(53, 36);
			this->button3->TabIndex = 12;
			this->button3->Text = L"←";
			this->button3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Login::button3_Click);
			// 
			// panel8
			// 
			this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			this->panel8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel8->Location = System::Drawing::Point(92, 318);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(37, 34);
			this->panel8->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::Black;
			this->textBox4->Location = System::Drawing::Point(132, 320);
			this->textBox4->Name = L"textBox4";
			this->textBox4->PasswordChar = '*';
			this->textBox4->Size = System::Drawing::Size(200, 28);
			this->textBox4->TabIndex = 11;
			this->textBox4->Text = L"123456";
			this->textBox4->UseSystemPasswordChar = true;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Login::textBox4_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(82, 397);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(254, 44);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Register";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Login::button2_Click);
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel5->Location = System::Drawing::Point(92, 263);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(37, 34);
			this->panel5->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(132, 265);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(200, 28);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"123456";
			this->textBox1->UseSystemPasswordChar = true;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Login::textBox1_TextChanged_1);
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel6->Location = System::Drawing::Point(91, 205);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(37, 34);
			this->panel6->TabIndex = 3;
			// 
			// rusername
			// 
			this->rusername->BackColor = System::Drawing::Color::WhiteSmoke;
			this->rusername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rusername->ForeColor = System::Drawing::Color::Black;
			this->rusername->Location = System::Drawing::Point(132, 205);
			this->rusername->Name = L"rusername";
			this->rusername->Size = System::Drawing::Size(200, 28);
			this->rusername->TabIndex = 2;
			this->rusername->Text = L"Username";
			this->rusername->TextChanged += gcnew System::EventHandler(this, &Login::rusername_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(132, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 39);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Sign Up";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Transparent;
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel9->Controls->Add(this->label11);
			this->panel9->Controls->Add(this->groupBox1);
			this->panel9->Controls->Add(this->label10);
			this->panel9->Controls->Add(this->label9);
			this->panel9->Controls->Add(this->label8);
			this->panel9->Controls->Add(this->label7);
			this->panel9->Controls->Add(this->comboBox1);
			this->panel9->Controls->Add(this->textBox2);
			this->panel9->Controls->Add(this->button5);
			this->panel9->Location = System::Drawing::Point(8, 8);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(423, 538);
			this->panel9->TabIndex = 15;
			this->panel9->Visible = false;
			this->panel9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Login::panel9_Paint);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(210, 224);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(122, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Username already taken";
			this->label11->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(201, 303);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(84, 72);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->ForeColor = System::Drawing::Color::Black;
			this->radioButton2->Location = System::Drawing::Point(13, 36);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(49, 22);
			this->radioButton2->TabIndex = 18;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Girl";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->ForeColor = System::Drawing::Color::Black;
			this->radioButton1->Location = System::Drawing::Point(13, 11);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(52, 22);
			this->radioButton1->TabIndex = 17;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Boy";
			this->radioButton1->UseVisualStyleBackColor = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(133, 91);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(169, 39);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Lets Play";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(159, 315);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 17);
			this->label9->TabIndex = 15;
			this->label9->Text = L"I\'m a";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(107, 256);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(134, 17);
			this->label8->TabIndex = 14;
			this->label8->Text = L"How old are you\?";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(107, 173);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 17);
			this->label7->TabIndex = 13;
			this->label7->Text = L"What\'s your name\?";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->ForeColor = System::Drawing::Color::Black;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16"
			});
			this->comboBox1->Location = System::Drawing::Point(110, 274);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(217, 25);
			this->comboBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->Location = System::Drawing::Point(110, 193);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(217, 28);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Login::textBox2_TextChanged);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Transparent;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(92, 383);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(254, 44);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Play";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Login::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(134, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"W E L C O M E   T O ";
			// 
			// Username
			// 
			this->Username->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username->ForeColor = System::Drawing::Color::Black;
			this->Username->Location = System::Drawing::Point(129, 219);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(199, 28);
			this->Username->TabIndex = 2;
			this->Username->Text = L"Username";
			this->Username->TextChanged += gcnew System::EventHandler(this, &Login::Username_TextChanged);
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel2->Location = System::Drawing::Point(86, 216);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(37, 39);
			this->panel2->TabIndex = 3;
			// 
			// Password
			// 
			this->Password->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password->ForeColor = System::Drawing::Color::Black;
			this->Password->Location = System::Drawing::Point(129, 277);
			this->Password->Name = L"Password";
			this->Password->PasswordChar = '*';
			this->Password->Size = System::Drawing::Size(199, 28);
			this->Password->TabIndex = 4;
			this->Password->Text = L"123456";
			this->Password->UseSystemPasswordChar = true;
			this->Password->TextChanged += gcnew System::EventHandler(this, &Login::Password_TextChanged);
			// 
			// panel3
			// 
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel3->Location = System::Drawing::Point(86, 275);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(37, 39);
			this->panel3->TabIndex = 5;
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->linkLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel2->ForeColor = System::Drawing::Color::Black;
			this->linkLabel2->LinkColor = System::Drawing::Color::Black;
			this->linkLabel2->Location = System::Drawing::Point(142, 441);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(140, 20);
			this->linkLabel2->TabIndex = 8;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Create an account";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Login::linkLabel2_LinkClicked);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(167, 312);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(161, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Incorrect Username or Password";
			this->label5->Visible = false;
			this->label5->Click += gcnew System::EventHandler(this, &Login::label5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(95, 111);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(214, 40);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->linkLabel2);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->Password);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->Username);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(8, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(423, 538);
			this->panel1->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(129, 384);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(164, 43);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Sign In";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Login::button4_Click);
			// 
			// Login
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(439, 553);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Scramble - Get Started";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
		fillarray();
		this->panel1->BringToFront();


	}
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text;
	}//pass
	private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		panel1->Visible = false;
		panel4->Visible = true;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		panel4->Visible = false;
		panel1->Visible = true;
	}
	private: System::Void rusername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->rusername->Text;
	}//Username
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->textBox4->Text;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		bool checkpass = false;
		bool checkuser = true;
		if (textBox1->Text != textBox4->Text)
		{
			this->label3->Visible = true;

		}
		else
		{
			checkpass = true;
			this->label3->Visible = false;
		}
		for (int i = 0; i < 100; i++)
		{
			if (rusername->Text == gcnew String(parent[i].c_str()))
			{
				checkuser = false;
				this->label6->Visible = true;
			}
		}
		if (checkuser == true)
		{
			this->label6->Visible = false;
		}
		if (checkuser == true && checkpass == true)
		{
			signup(rusername, textBox1, textBox4);
			parentID(rusername);
			parentPass(textBox1);
			this->label6->Visible = false;
			this->panel4->Visible = false;
			this->panel9->Visible = true;
		}
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label3->Visible = false;
	}
	private: System::Void Username_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Username->Text;
	}
	private: System::Void Password_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Password->Text;
	}

	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
		label5->Visible = false;
	}
	private: System::Void panel9_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->textBox2->Text;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		bool found = false;
		for (int i = 0; i < 100; i++)
		{
			if (textBox2->Text == gcnew String(players[i].c_str()))
			{
				label11->Visible = true;
				found = true;
				break;
			}
			else
			{
				label11->Visible = false;
			}
		}
		if (found == false)
		{
			// Convert System::String to std::string
			username = msclr::interop::marshal_as< std::string >(textBox2->Text);
			playerID(textBox2);

			// Show next form
			Start^ main_menu = gcnew Start();
			main_menu->Show();
			this->Hide();
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 100; i++)
		{
			if (Username->Text == gcnew String(parent[i].c_str()) && Password->Text == gcnew String(password[i].c_str()))
			{
				label5->Visible = false;
				this->panel1->Visible = false;
				this->panel9->Visible = true;
				break;
			}
			else
			{
				label5->Visible = true;
			}
		}
	}
};
}