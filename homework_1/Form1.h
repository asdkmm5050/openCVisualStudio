#include<opencv/cv.hpp>
#include<vector>
#include <algorithm> 
#include"box.h"
#pragma once
Box::Box(int a, int b, int c, int d)
{
	this->top = a;
	this->down = b;
	this->left = c;
	this->right = d;
};
Box::~Box()
{

};

namespace CppCLRWinformsProjekt
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Collections::Generic;

	cv::VideoCapture vc;
	cv::Mat input;
	cv::Mat output;
	cv::Mat output_2;
	cv::Mat output_3;
	cv::Mat output_4;
	cv::Mat output_5;
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
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
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
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(300, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(319, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(300, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Play";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(625, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(300, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(13, 77);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(172, 300);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->Location = System::Drawing::Point(191, 76);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(206, 300);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox3->Location = System::Drawing::Point(403, 76);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(203, 300);
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
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 50);
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox5->Location = System::Drawing::Point(612, 76);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(138, 300);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 6;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox6->Location = System::Drawing::Point(756, 76);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(170, 300);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 393);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
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
			timer1->Interval = 1;
			first_image.release();
			last_image.release();
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
			Bitmap^ b = gcnew Bitmap(mat.cols, mat.rows, mat.step, PixelFormat::Format8bppIndexed, (IntPtr)mat.data);
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

		cv::Mat process = cv::Mat(input.rows, input.cols, CV_8UC1);
		uchar* idata = input.data;
		uchar* pdata = process.data;
		uchar* fdata = first_image.data;
		int data;
		for (int y = 0; y < process.rows; y++)
		{
			for (int x = 0; x < process.cols; x++)
			{
				data = abs(idata[0] - fdata[0]);
				if (data > 40)
				{
					data = 255;
				}
				else
				{
					data = 0;
				}
				pdata[0] = (uchar)data;
				fdata++;
				pdata++;
				idata++;
			}
		}
		output_2 = process.clone();
	}
	private: void WTF(cv::Mat input)
	{
		cv::Mat process = cv::Mat(input.rows, input.cols, CV_8UC1);
		uchar* idata = input.data;
		uchar* pdata = process.data;
		uchar* ldata = last_image.data;
		int data;
		for (int y = 0; y < process.rows; y++)
		{
			for (int x = 0; x < process.cols; x++)
			{
				data = abs(idata[0] - ldata[0]);
				if (data > 30)
				{
					data = 255;
				}
				else
				{
					data = 0;
				}
				pdata[0] = data;
				ldata++;
				pdata++;
				idata++;
			}
		}
		//std::vector<Box> box = Scanner(process.clone());
		process = DrawBox(process.clone());
		output_3 = process;
	}
	private: std::vector<Box>CreateBox(std::vector<int>process_x, std::vector<int>process_y, cv::Mat input)
	{
		button3->Text = "CreateBox";
		std::vector<Box>boxes;
		int ii = -1, jj = -1;
		for (int i = 0; i < process_x.size(); i++)
		{
			for (int j = i; j < process_x.size(); j++)
			{
				for (int x = process_x[i]; x < process_x[j]; x++)
				{
					for (int y = 0; y < input.rows; y++)
					{
						if (input.data[y * input.cols + x] != 0 && ii != i && jj != j)
						{
							Box box(0, 0, process_x[i], process_x[j]);
							boxes.push_back(box);
							ii = i;
							jj = j;
						}
					}
				}
			}
		}
		ii = -1, jj = -1;
		for (int i = 0; i < process_y.size(); i++)
		{
			for (int j = i; j < process_y.size(); j++)
			{
				for (int k = 0; k < boxes.size(); k++)
				{
					for (int x = boxes[k].left; x < boxes[k].right; x++)
					{
						for (int y = process_y[i]; y < process_y[j]; y++)
						{
							if (input.data[y * input.cols + x] != 0 && ii != i && jj != j)
							{
								boxes[k].top = process_y[i];
								boxes[k].down = process_y[j];
							}
						}
					}
				}
			}
		}
		return boxes;
	}
	private: std::vector<Box> Scanner(cv::Mat& input)
	{
		button3->Text = "Scanner";
		std::vector<Box> boxes;
		std::vector<int>process_x;
		std::vector<int>process_y;
		auto idata = input.data;


		for (int y = 0; y < input.rows; y++)
		{
			for (int x = 0; x < input.cols; x++)
			{
				if ((idata[0] == 0 && idata[1] != 0) || (x == 0 && idata[0] != 0))
				{
					process_y.push_back(x);
				}
				if ((idata[0] != 0 && idata[1] == 0) || (x == input.rows && idata[0] != 0))
				{
					process_y.push_back(x);
				}
				idata++;
			}
		}
		idata = input.data;
		for (int x = 0; x < input.cols; x++)
		{
			for (int y = 0; y < input.rows; y++)
			{
				if ((idata[0] == 0 && idata[input.cols] != 0) || (y == 0 && idata[0] != 0))
				{
					process_x.push_back(y);
				}
				if ((idata[0] != 0 && idata[input.cols] == 0) || (y == input.cols && idata[0] != 0))
				{
					process_x.push_back(y);
				}
				idata = input.data + x + y * input.cols;
			}

		}
		std::sort(process_x.begin(), process_x.end());
		std::sort(process_y.begin(), process_y.end());

		boxes = CreateBox(process_x, process_y, input);


		return boxes;
	}
	private: cv::Mat DrawBox(cv::Mat input_mat/*, std::vector<Box>box*/)
	{
		button3->Text = "drawbox";
		auto process = input_mat.clone();
		auto idata = input_mat.data;
		auto pdata = process.data;
		List<int>^ process_x = gcnew List<int>();
		for (int i = 0; i < input.cols; i++)
		{
			process_x->Add(0);
		}
		std::vector<int>process_y;
		for (int y = 0; y < input.rows; y++)
		{
			for (int x = 0; x < input.cols - 1; x++)
			{
				if ((idata[0] == 0 && idata[1] != 0) || (x == 0 && idata[0] != 0))
				{
					process_x[x] = 1;
				}
				if ((idata[0] != 0 && idata[1] == 0) || (x == input.rows && idata[0] != 0))
				{
					process_x[x] = 1;
				}
				idata++;
			}
		}
		idata = input.data;
		/*for (int x = 0; x < input.cols; x++)
		{
			for (int y = 0; y < input.rows - 1; y++)
			{
				idata = input.data + x + y * input.cols;
				if ((idata[0] == 0 && idata[input.cols] != 0) || (y == 0 && idata[0] != 0))
				{
					process_y.push_back(y);
				}
				if ((idata[0] != 0 && idata[input.cols] == 0) || (y == input.cols && idata[0] != 0))
				{
					process_y.push_back(y);
				}
			}

		}
		idata = input.data;*/
		for (int y = 0; y < input_mat.rows; y++)
		{
			for (int x = 0; x < input_mat.cols; x++)
			{
				/*for (int i = 0; i < box.size(); i++)
				{
					if (y > box[i].top && y < box[i].down)
					{
						if (x > box[i].left && x < box[i].right)
						{
							pdata[0] = 255;
						}
						else
						{
							pdata[0] = 0;
						}
					}
				}*/
				for (int i = 0; i < input.cols; i++)
				{
					if (process_x[x])
					{
						pdata[0] = 255;
					}
					else
					{
						pdata[0] = 0;
					}
				}

				pdata += 1;
			}
		}
		return process;
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
		//pictureBox5->Image = MatToBitmap(output_4);
		//pictureBox6->Image = MatToBitmap(output_5);
		last_image = output.clone();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Reset();
	}
	};

}

