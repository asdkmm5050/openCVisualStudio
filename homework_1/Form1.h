#include<opencv/cv.hpp>
#pragma once

namespace CppCLRWinformsProjekt
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	cv::VideoCapture vc;
	cv::Mat input;
	cv::Mat output;
	cv::Mat output_2; 
	cv::Mat output_3;
	cv::Mat first_image;
	cv::Mat last_image;
	long frame_counts;
	double fps;

	/// <summary>
	/// Zusammenfassung f Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: Bitmap^ gray;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: ColorPalette^ cp;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f die Designerunterstzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge鄚dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 16);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(400, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(425, 18);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(400, 75);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Play";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(833, 18);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(400, 75);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(17, 100);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(288, 375);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->Location = System::Drawing::Point(313, 100);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(316, 375);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox3->Location = System::Drawing::Point(637, 100);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(297, 375);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox4->Location = System::Drawing::Point(942, 100);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(297, 375);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1251, 491);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void OpenFile()
	{
		openFileDialog1->FileName = "";
		openFileDialog1->Filter = "All file|*.*";
		openFileDialog1->FilterIndex = 1;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName != "")
		{
			const char* sc = (char*)((void*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer()));
			std::string s = sc;
			vc = cv::VideoCapture(s);
			fps = vc.get(cv::CAP_PROP_FPS);
			frame_counts = vc.get(cv::CAP_PROP_FRAME_COUNT);
			timer1->Interval = 5;
		}
	}
	private: void Reset()
	{
		const char* sc = (char*)((void*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer()));
		std::string s = sc;
		vc = cv::VideoCapture(s);
	}
	private: Bitmap^ MatToBitmap(cv::Mat mat)
	{
		if (mat.channels() == 3)
		{
			return gcnew Bitmap(mat.cols, mat.rows, mat.step, PixelFormat::Format24bppRgb, (IntPtr)mat.data);
		}
		else
		{
			Bitmap^ b = gcnew Bitmap(mat.cols, mat.rows, mat.step, PixelFormat::Format8bppIndexed, (IntPtr)mat.data);;
			b->Palette = cp;
			return b;
		}
	}
	private: void ToGray(cv::Mat input, cv::Mat& output)
	{
		if (input.channels() == 1)
		{
			output = input.clone();
		}
		cv::Mat process = cv::Mat(input.rows, input.cols, CV_8UC1);
		uchar* idata = input.data;
		uchar* pdata = process.data;
		for (int y = 0; y < input.rows; y++)
		{
			for (int x = 0; x < input.cols; x++)
			{
				int pixel = 0.114 * idata[0] + 0.587 * idata[1] + 0.299 * idata[2];
				pdata[0] = (uchar)pixel;
				idata += 3;
				pdata += 1;
			}
		}
		output = process.clone();
	}
	private: void BackgroundSubtraction(cv::Mat input)
	{

		cv::Mat process = input.clone();
		uchar* idata = input.data;
		uchar* pdata = process.data;
		uchar* fdata = first_image.data;
		int data;
		for (int y = 0; y < process.rows; y++)
		{
			for (int x = 0; x < process.cols; x++)
			{
				data = &idata[0] - &fdata[0];
				pdata[0] = abs(data);
				fdata++;
				pdata++;
				idata++;
			}
		}
		output_2 = process.clone();
	}
	private: void WTF(cv::Mat input)
	{
		cv::Mat process = input.clone();
		uchar* idata = input.data;
		uchar* pdata = process.data;
		uchar* ldata = last_image.data;
		int data;
		for (int y = 0; y < process.rows; y++)
		{
			for (int x = 0; x < process.cols; x++)
			{
				data = &idata[0] - &ldata[0];
				pdata[0] = abs(data);
				ldata++;
				pdata++;
				idata++;
			}
		}
		output_3 = process.clone();
	}
		   //-------------------------------------------------------------------------自動生成-------------------------------------------------------------
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e)
	{
		gray = gcnew Bitmap(1, 1, PixelFormat::Format8bppIndexed);
		cp = gray->Palette;
		for (int i = 0; i < 256; i++)
		{
			cp->Entries[i] = Color::FromArgb(i, i, i);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFile();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (button2->Text == "Play")
		{
			timer1->Enabled = true;
			button2->Text = "Stop";
		}
		else
		{
			timer1->Enabled = false;
			button2->Text = "Play";
		}

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		long pos_now = vc.get(cv::CAP_PROP_POS_FRAMES);
		if (pos_now >= frame_counts - 1)
		{
			button2_Click(nullptr, nullptr);
			vc.set(cv::CAP_PROP_POS_FRAMES, 0);
		}

		vc >> input;
		ToGray(input, output);
		if (first_image.empty())
		{
			first_image = output.clone();
			last_image = output.clone();
		}
		output.copyTo(output_2);
		output.copyTo(output_3);
		BackgroundSubtraction(output_2);
		WTF(output_3);
		pictureBox1->Image = MatToBitmap(output);
		pictureBox2->Image = MatToBitmap(output_2);
		pictureBox3->Image = MatToBitmap(output_3);
		last_image = output.clone();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Reset();
	}
	};
}
