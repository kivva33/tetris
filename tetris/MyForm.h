#pragma once
#include "kivva's_func.h"
#include "Details.h"
#include <cmath>
#include <random>
#include <windows.h>
#include "MyDialog.h"
//bad version
namespace tetris {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dlg = gcnew MyDialog();

			pb_main->Image = gcnew Bitmap(pb_main->Width, pb_main->Height);
			pb_next->Image = gcnew Bitmap(pb_next->Width, pb_next->Height);

			det = generate_detail();
			det_next = generate_detail();

			main_mat = gcnew array<float, 2>(10, 21);	
			mat_for_copy = gcnew array<float, 2>(10, 21);
			mat_next = gcnew array<float, 2>(4, 4);

			need = true;
			pos = false;
			mir = true;

			br_fon = gcnew SolidBrush(Color::Azure);
			br_back = gcnew SolidBrush(Color::LightGray);
			br_front = gcnew SolidBrush(Color::Black);

			pn_back = gcnew Pen(Color::LightGray, 3);
			pn_front = gcnew Pen(Color::Black, 3);


		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pb_main;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btn_left;
	private: System::Windows::Forms::Button^ btn_up;
	private: System::Windows::Forms::Button^ btn_right;
	private: System::Windows::Forms::Button^ btn_down;
	private: System::Windows::Forms::Timer^ timer1;




	private: System::Windows::Forms::Button^ btn_rotate;
	private: System::Windows::Forms::PictureBox^ pb_next;
	private: System::Windows::Forms::Button^ btn_pause;




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pb_main = (gcnew System::Windows::Forms::PictureBox());
			this->btn_left = (gcnew System::Windows::Forms::Button());
			this->btn_up = (gcnew System::Windows::Forms::Button());
			this->btn_right = (gcnew System::Windows::Forms::Button());
			this->btn_down = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_rotate = (gcnew System::Windows::Forms::Button());
			this->pb_next = (gcnew System::Windows::Forms::PictureBox());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_main))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_next))->BeginInit();
			this->SuspendLayout();
			// 
			// pb_main
			// 
			this->pb_main->BackColor = System::Drawing::Color::AliceBlue;
			this->pb_main->Location = System::Drawing::Point(12, 12);
			this->pb_main->Name = L"pb_main";
			this->pb_main->Size = System::Drawing::Size(430, 790);
			this->pb_main->TabIndex = 0;
			this->pb_main->TabStop = false;
			// 
			// btn_left
			// 
			this->btn_left->BackColor = System::Drawing::Color::White;
			this->btn_left->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_left->Location = System::Drawing::Point(458, 468);
			this->btn_left->Name = L"btn_left";
			this->btn_left->Size = System::Drawing::Size(60, 40);
			this->btn_left->TabIndex = 1;
			this->btn_left->Text = L"<";
			this->btn_left->UseVisualStyleBackColor = false;
			this->btn_left->Click += gcnew System::EventHandler(this, &MyForm::btn_left_Click);
			// 
			// btn_up
			// 
			this->btn_up->BackColor = System::Drawing::Color::White;
			this->btn_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_up->Location = System::Drawing::Point(524, 422);
			this->btn_up->Name = L"btn_up";
			this->btn_up->Size = System::Drawing::Size(60, 40);
			this->btn_up->TabIndex = 2;
			this->btn_up->Text = L"/\\";
			this->btn_up->UseVisualStyleBackColor = false;
			// 
			// btn_right
			// 
			this->btn_right->BackColor = System::Drawing::Color::White;
			this->btn_right->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_right->Location = System::Drawing::Point(590, 468);
			this->btn_right->Name = L"btn_right";
			this->btn_right->Size = System::Drawing::Size(60, 40);
			this->btn_right->TabIndex = 3;
			this->btn_right->Text = L">";
			this->btn_right->UseVisualStyleBackColor = false;
			this->btn_right->Click += gcnew System::EventHandler(this, &MyForm::btn_right_Click);
			// 
			// btn_down
			// 
			this->btn_down->BackColor = System::Drawing::Color::White;
			this->btn_down->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_down->Location = System::Drawing::Point(524, 514);
			this->btn_down->Name = L"btn_down";
			this->btn_down->Size = System::Drawing::Size(60, 40);
			this->btn_down->TabIndex = 4;
			this->btn_down->Text = L"\\/";
			this->btn_down->UseVisualStyleBackColor = false;
			this->btn_down->Click += gcnew System::EventHandler(this, &MyForm::btn_down_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btn_rotate
			// 
			this->btn_rotate->BackColor = System::Drawing::Color::White;
			this->btn_rotate->Location = System::Drawing::Point(524, 468);
			this->btn_rotate->Name = L"btn_rotate";
			this->btn_rotate->Size = System::Drawing::Size(60, 40);
			this->btn_rotate->TabIndex = 9;
			this->btn_rotate->Text = L" ";
			this->btn_rotate->UseVisualStyleBackColor = false;
			this->btn_rotate->Click += gcnew System::EventHandler(this, &MyForm::btn_rotate_Click);
			// 
			// pb_next
			// 
			this->pb_next->BackColor = System::Drawing::Color::Azure;
			this->pb_next->Location = System::Drawing::Point(490, 12);
			this->pb_next->Name = L"pb_next";
			this->pb_next->Size = System::Drawing::Size(170, 160);
			this->pb_next->TabIndex = 10;
			this->pb_next->TabStop = false;
			// 
			// btn_pause
			// 
			this->btn_pause->BackColor = System::Drawing::Color::White;
			this->btn_pause->Location = System::Drawing::Point(490, 190);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(75, 23);
			this->btn_pause->TabIndex = 11;
			this->btn_pause->Text = L"Pause";
			this->btn_pause->UseVisualStyleBackColor = false;
			this->btn_pause->Click += gcnew System::EventHandler(this, &MyForm::btn_pause_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(679, 817);
			this->Controls->Add(this->btn_pause);
			this->Controls->Add(this->pb_next);
			this->Controls->Add(this->btn_rotate);
			this->Controls->Add(this->btn_down);
			this->Controls->Add(this->btn_right);
			this->Controls->Add(this->btn_up);
			this->Controls->Add(this->btn_left);
			this->Controls->Add(this->pb_main);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Tetris";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_main))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_next))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		MyDialog^ dlg;

		array<float, 2> ^main_mat, ^mat_for_copy, ^mat_next;

		Brush^ br_fon, ^br_back, ^br_front;
		Pen^ pn_back, ^pn_front;

		Detail^ det, ^det_next;

		bool need, pos, mir;
		int width = 32, len_x = 4, len_y = 0;

		void paint_square(Image^ img, Brush^ b, Pen^ p, int x, int y, int Width) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(br_fon, x * width, y * width, width, width);
			gr->DrawRectangle(pn_back, x * width + 3, y * width + 3, width - 6, width - 6);
			gr->FillRectangle(br_back, x * width + 9, y * width + 9, width - 18, width - 18);
			gr->DrawRectangle(p, x * width + 3 + width / 2 - Width / 2, y * width + 3 + (width - Width) / 2,
				Width - 6, Width - 6);
			gr->FillRectangle(b, x * width + 9 + width / 2 - Width / 2, y * width + 9 + (width - Width) / 2,
				Width - 18, Width - 18);
		}
		void print_mat(Image^ img, array<float, 2>^ A, int x, int y) {
			for (int i = 0; i < A->GetLength(0); i++)
				for (int j = 0; j < A->GetLength(1); j++) {
					if (A[i, j]) {
						paint_square(img, br_front, pn_front, i + x, j + y, width);
						continue;
					}
					paint_square(img, br_back, pn_back, i + x, j + y, width);
				}
		}
		void print_mat_detail(Image^ img, array<float, 2>^ A, int x, int y) {
			for (int i = 0; i < A->GetLength(0); i++)
				for (int j = 0; j < A->GetLength(1); j++) {
					if (A[i, j]) {
						paint_square(img, br_front, pn_front, i + x, j + y, width);
					}
				}
		}
		void Set_mat(Detail^ d, array<float, 2>^ ar, int x, int y) {
			for(int i = 0; i < d->GetSize(); i++)
				for (int j = 0; j < d->GetSize(); j++) {
					if (d->Get_mat()[i, j]) {
						ar[i + x, j + y - 1] = d->Get_mat()[i, j];
					}
				}
		}

		bool info_down(Detail^ d, array<float, 2>^ ar, int x, int y) {
			bool ok = true;//можем двигать
			for(int i = 0; i < d->GetSize(); i++)
				for (int j = 0; j < d->GetSize(); j++) {
					if ((d->Get_mat()[i, j] && j + y == ar->GetLength(1) - 1)||
						(d->Get_mat()[i, j] && ar[i + x, y + j])) {
						ok = false;
					}
				}
			return ok;
		}
		bool info_left(Detail^ d, array<float, 2>^ ar, int x, int y) {
			bool ok = true;//можем двигать
			for (int i = 0; i < d->GetSize(); i++)
				for (int j = 0; j < d->GetSize(); j++) {
					if ((d->Get_mat()[i, j] && i + x == 0) ||
						(d->Get_mat()[i, j] && ar[i + x - 1, y + j]))
						ok = false;
				}
			return ok;
		}
		bool info_right(Detail^ d, array<float, 2>^ ar, int x, int y) {
			bool ok = true;//можем двигать
			for (int i = 0; i < d->GetSize(); i++)
				for (int j = 0; j < d->GetSize(); j++) {
					if ((d->Get_mat()[i, j] && i + x == ar->GetLength(0) - 1) ||
						(d->Get_mat()[i, j] && ar[i + x + 1, y + j]))
						ok = false;
				}
			return ok;
		}
		bool info_rotate(Detail^ d, array<float, 2>^ ar, int% x, int% y) {
			bool ok = true;//можем повернуть
			int this_x = x, this_y = y;
			if (x < 0)
				x = 0;
			if ((x + d->GetSize()) > ar->GetLength(0))
				x = ar->GetLength(0) - d->GetSize();
			if (y + d->GetSize() > ar->GetLength(1) - 1) {
				ok = false;
				return ok;
			}
			for(int i = 0; i < d->GetSize(); i++)
				for (int j = 0; j < d->GetSize(); j++) {
					if (ar[i + x, j + y]) {
						x = this_x;
						y = this_y;
						ok = false;
						return ok;
					}
				}
			return ok;
		}
		void info_full(array<float, 2>^ ar) {
			bool ok = true;
			for (int j = 0; j < ar->GetLength(1); j++) {
				ok = false;
				if (ar[0, j]) {
					ok = true;
					for (int i = 0; i < ar->GetLength(0); i++)
						if (!ar[i, j]) {
							ok = false;
							continue;
						}
				}
				if (ok)
					delete_line(main_mat, j);
			}
		}
		void delete_line(array<float, 2>^ ar, int y) {
			PointF center(width / 2, y * width + width / 2);
			float real_width = 0.8 * width;
			for (int i = 0; i < 10; i++) {
				print_mat(pb_main->Image, main_mat, 0, 0);
				for (int j = 0; j < ar->GetLength(0); j++) {
					paint_square(pb_main->Image, br_front, pn_front, j, y, real_width);
				}
				real_width *= 0.8;
				pb_main->Refresh();
				Sleep(32);
			}
			for (int j = y; j > 0; j--) {
				for (int i = 0; i < ar->GetLength(0); i++) {
					ar[i, j] = ar[i, j - 1];
				}
			}
			for (int i = 0; i < ar->GetLength(0); i++)
				ar[i, 0] = 0;
			clear(pb_main->Image, br_fon);
			print_mat(pb_main->Image, main_mat, 0, 0);
			print_mat_detail(pb_main->Image, det->Get_mat(), len_x, len_y++);
			pb_main->Refresh();
		}
		void info_finish(array<float, 2>^ ar) {
			for(int i = 0; i < ar->GetLength(0); i++)
				if (ar[i, 0]) {
					timer1->Enabled = false;
					len_x = 4;
					len_y = 0;
					need = true;
					mir = false;
					pos = false;
					MessageBox::Show("Вы проиграли", "Кажется, Вы чайник");
					array<int, 2>::Copy(mat_for_copy, main_mat, mat_for_copy->Length);
				}
		}
		bool info_generate(Detail^ d, array<float, 2>^ ar) {
			bool ok = true;
			for (int j = 0; j < d->GetSize(); j++) {
				for (int i = 0; i < ar->GetLength(0); i++) {
					if (ar[i, j]) {
						timer1->Enabled = false;
						len_x = 4;
						len_y = 0;
						need = true;
						mir = false;
						pos = false;
						MessageBox::Show("Вы проиграли", "Кажется, Вы чайник");
						array<int, 2>::Copy(mat_for_copy, main_mat, mat_for_copy->Length);
						ok = false;
					}
				}
			}
			return ok;
		}

private: System::Void btn_rotate_Click(System::Object^ sender, System::EventArgs^ e) {
	float phi = -1.57;
	det->rotate(phi);
	clear(pb_main->Image, br_fon);
	print_mat(pb_main->Image, main_mat, 0, 0);
	print_mat_detail(pb_main->Image, det->Get_mat(), len_x, len_y);
	pb_main->Refresh();
}

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (need && (info_generate(det, main_mat)))
	{
		det = det_next;
		det_next = generate_detail();
		clear(pb_next->Image, br_fon);
		print_mat(pb_next->Image, mat_next, 0, 0);
		print_mat_detail(pb_next->Image, det_next->Get_mat(), 0, 0);
		need = false;
		len_y = 0;
		len_x = 5;
		pb_next->Refresh();
		return;
	}
	if (!(info_down(det, main_mat, len_x, len_y))) {
		need = true;
		pos = false;
		Set_mat(det, main_mat, len_x, len_y);
		info_full(main_mat);
		info_finish(main_mat);
		return;
	}
	else {
		pos = true;
		clear(pb_main->Image, br_fon);
		print_mat(pb_main->Image, main_mat, 0, 0);
		print_mat_detail(pb_main->Image, det->Get_mat(), len_x, len_y++);
		pb_main->Refresh();
	}
}
	private: System::Void btn_left_Click(System::Object^ sender, System::EventArgs^ e) {
		if (info_left(det, main_mat, len_x, len_y)) {
			clear(pb_main->Image, br_fon);
			print_mat(pb_main->Image, main_mat, 0, 0);
			print_mat_detail(pb_main->Image, det->Get_mat(), --len_x, len_y);
			pb_main->Refresh();
		}
	}
private: System::Void btn_right_Click(System::Object^ sender, System::EventArgs^ e) {
	if (info_right(det, main_mat, len_x, len_y)) {
		clear(pb_main->Image, br_fon);
		print_mat(pb_main->Image, main_mat, 0, 0);
		print_mat_detail(pb_main->Image, det->Get_mat(), ++len_x, len_y);
		pb_main->Refresh();
	}
}
private: System::Void btn_down_Click(System::Object^ sender, System::EventArgs^ e) {
	if (info_down(det, main_mat, len_x, len_y)) {
		clear(pb_main->Image, br_fon);
		print_mat(pb_main->Image, main_mat, 0, 0);
		print_mat_detail(pb_main->Image, det->Get_mat(), len_x, ++len_y);
		pb_main->Refresh();
	}
}

private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::P) {
		timer1->Enabled = !timer1->Enabled;
		pos = !pos;
		/*if (dlg->ShowDialog() == Windows::Forms::DialogResult::OK && pos) {
			timer1->Enabled = !timer1->Enabled;
			pos = !pos;
		}*/
	}
}
private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (pos) {
		switch (e->KeyChar)
		{
		case 'a'://Лево
			if (info_left(det, main_mat, len_x, len_y) && !need) {
				clear(pb_main->Image, br_fon);
				print_mat(pb_main->Image, main_mat, 0, 0);
				print_mat_detail(pb_main->Image, det->Get_mat(), --len_x, len_y);
				pb_main->Refresh();
			}
			break;
		case 'd'://Право
			if (info_right(det, main_mat, len_x, len_y) && !need) {
				clear(pb_main->Image, br_fon);
				print_mat(pb_main->Image, main_mat, 0, 0);
				print_mat_detail(pb_main->Image, det->Get_mat(), ++len_x, len_y);
				pb_main->Refresh();
			}
			break;
		case 's'://Низ
			if ((info_down(det, main_mat, len_x, len_y)) && !need) {
				clear(pb_main->Image, br_fon);
				print_mat(pb_main->Image, main_mat, 0, 0);
				print_mat_detail(pb_main->Image, det->Get_mat(), len_x, len_y++);
				pb_main->Refresh();
			}
			break;
		case 'l':
			if (info_rotate(det, main_mat, len_x, len_y)) {
				float phi = -1.57;
				det->rotate(phi);
				clear(pb_main->Image, br_fon);
				print_mat(pb_main->Image, main_mat, 0, 0);
				print_mat_detail(pb_main->Image, det->Get_mat(), len_x, len_y);
				pb_main->Refresh();
			}
			break;
		}
	}

}

private: System::Void btn_pause_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = !timer1->Enabled;
	pos = !pos;
	/*if (dlg->ShowDialog() == Windows::Forms::DialogResult::OK && pos) {
		timer1->Enabled = !timer1->Enabled;
		pos = !pos;
	}*/
}

};
}
/*
неправильный поворот вблизи закрашенных кубиров
неправильное окончание игры(есть место, нет генерации фигур)
при стирании рядов пустые блоки на пару тиков закрашиваются, а после становятся как были
*/