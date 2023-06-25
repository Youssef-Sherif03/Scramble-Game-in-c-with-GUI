#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <algorithm>

// Global variables
std::string todaysWord, category;

std::string parent[100];
std::string password[100];
std::string players[100];

std::string username;

int leaderboard_animals[100];
int leaderboard_food[100];
int leaderboard_countries[100];

int playerCount = 0;

namespace Scramble {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(string ctg)
		{
			InitializeComponent();
			category = ctg;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ scrambleWord;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->scrambleWord = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(156, 86);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(321, 62);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Game::pictureBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(52, 257);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(329, 37);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Unscramble the word:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// scrambleWord
			// 
			this->scrambleWord->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->scrambleWord->AutoSize = true;
			this->scrambleWord->BackColor = System::Drawing::Color::Transparent;
			this->scrambleWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scrambleWord->Location = System::Drawing::Point(51, 295);
			this->scrambleWord->Margin = System::Windows::Forms::Padding(150, 0, 150, 0);
			this->scrambleWord->Name = L"scrambleWord";
			this->scrambleWord->Size = System::Drawing::Size(232, 61);
			this->scrambleWord->TabIndex = 0;
			this->scrambleWord->Text = L"example";
			this->scrambleWord->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(318, 482);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(320, 48);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Game::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(318, 549);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(322, 62);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Check";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Game::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(18, 18);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 55);
			this->button2->TabIndex = 4;
			this->button2->Text = L"←";
			this->button2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Game::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(314, 457);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Enter your guess here:";
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(658, 635);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->scrambleWord);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Scramble - Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void addScore() {
		for (int i = 0; i < playerCount; i++) {
			if (players[i] == username) {
				if (category == "animals")
					leaderboard_animals[i]++;
				else if (category == "food")
					leaderboard_food[i]++;
				else
					leaderboard_countries[i]++;
			}
		}
	}
	void saveScores() {
		StreamWriter^ lb2_animals = gcnew StreamWriter("Data\\lb_animals.txt");
		StreamWriter^ lb2_food = gcnew StreamWriter("Data\\lb_food.txt");
		StreamWriter^ lb2_countries = gcnew StreamWriter("Data\\lb_countries.txt");

		for (int i = 0; i < playerCount; i++) {
			lb2_animals->WriteLine(leaderboard_animals[i]);
			lb2_food->WriteLine(leaderboard_food[i]);
			lb2_countries->WriteLine(leaderboard_countries[i]);

		}

		lb2_animals->Close();
		lb2_food->Close();
		lb2_countries->Close();
	}
	int getScore() {
		int score = 0;
		for (int i = 0; i < playerCount; i++) {
			if (players[i] == username) {
				score += leaderboard_animals[i];
				score += leaderboard_food[i];
				score += leaderboard_countries[i];
			}
		}
		return score;
	}
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
		string words[500];

		// Enter words from the current level category txt file into array
		int i = 0;
		string line;
		ifstream file("Data\\words_" + category + ".txt");
		srand(time(NULL));
		if (file.is_open()) {
			while (std::getline(file, line)) {
				words[i] = line;
				i++;
			}
			file.close();

			// Pick random word
			todaysWord = words[rand() % i];

			// Shuffle word, and make sure the shuffled version isn't the same as original
			string shuffledWord = todaysWord;
			while (shuffledWord == todaysWord) {
				random_shuffle(shuffledWord.begin(), shuffledWord.end()); // built-in function
			}

			// Place shuffled word into label
			scrambleWord->Text = gcnew String(shuffledWord.c_str());
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Handle incorrect guess
		if ((textBox1->Text)->ToUpper() != gcnew String(todaysWord.c_str())) {
			textBox1->Text = gcnew String("");
			label1->Show();
			label1->Text = "Incorrect guess! Try again.";
		}
		// Handle correct guess with progression
		else {
			addScore();
			saveScores();

			string response = "Congratulations! You have guessed the word right!\n\n";
			if (getScore() == 3) response += "You have unlocked the Food level!";
			else if (getScore() == 6) response += "You have unlocked the Countries level!";

			MessageBox::Show(gcnew String(response.c_str()));

			this->Close();
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		label1->Hide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
