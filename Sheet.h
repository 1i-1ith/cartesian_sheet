#pragma once
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */

namespace CartesianSheet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CartesianSheet;

	/// <summary>
	/// Сводка для Sheet
	/// </summary>
	public ref class Sheet : public System::Windows::Forms::Form
	{ 
	private: 
		Graphics^ graphic;
		Bitmap^ bitmap;
		//диалоговые окна для выбора цветов
		ColorDialog^ colorDialogLine; //линии
		ColorDialog^ colorDialogBack; //фона
	public:
		Sheet(void)
		{
			InitializeComponent();

			//создание изображения на котором будет строится графика
			bitmap = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
			//создание объекта для графики
			graphic = Graphics::FromImage(bitmap);

			//создание объектов для выбора цвета
			colorDialogLine = gcnew ColorDialog();
			colorDialogBack = gcnew ColorDialog();

			//установка цветов по умолчанию
			colorDialogLine->Color = Color::HotPink; 
			colorDialogBack->Color = Color::White;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Sheet()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ but_build;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Button^ but_save;
	private: System::Windows::Forms::Button^ but_color_back;
	private: System::Windows::Forms::Button^ but_color_lines;
	private: System::Windows::Forms::Button^ but_quit;

	private: System::Windows::Forms::NumericUpDown^ step_choice;
	private: System::Windows::Forms::NumericUpDown^ scale_choice;
	private: System::Windows::Forms::NumericUpDown^ line_size_choice;
	private: System::Windows::Forms::NumericUpDown^ parameter_choice;

	private: System::Windows::Forms::Label^ step_label;
	private: System::Windows::Forms::Label^ scale_label;
	private: System::Windows::Forms::Label^ parameter_label;
	private: System::Windows::Forms::Label^ size_label;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->but_build = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->but_save = (gcnew System::Windows::Forms::Button());
			this->but_color_back = (gcnew System::Windows::Forms::Button());
			this->but_color_lines = (gcnew System::Windows::Forms::Button());
			this->but_quit = (gcnew System::Windows::Forms::Button());
			this->step_choice = (gcnew System::Windows::Forms::NumericUpDown());
			this->scale_choice = (gcnew System::Windows::Forms::NumericUpDown());
			this->line_size_choice = (gcnew System::Windows::Forms::NumericUpDown());
			this->parameter_choice = (gcnew System::Windows::Forms::NumericUpDown());
			this->step_label = (gcnew System::Windows::Forms::Label());
			this->scale_label = (gcnew System::Windows::Forms::Label());
			this->parameter_label = (gcnew System::Windows::Forms::Label());
			this->size_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->step_choice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scale_choice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->line_size_choice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parameter_choice))->BeginInit();
			this->SuspendLayout();
			// 
			// but_build
			// 
			this->but_build->Location = System::Drawing::Point(344, 427);
			this->but_build->Name = L"but_build";
			this->but_build->Size = System::Drawing::Size(182, 69);
			this->but_build->TabIndex = 0;
			this->but_build->Text = L"Построить фигуру";
			this->but_build->UseVisualStyleBackColor = true;
			this->but_build->Click += gcnew System::EventHandler(this, &Sheet::but_build_click);
			// 
			// pictureBox
			// 
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox->Location = System::Drawing::Point(623, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(765, 590);
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// but_save
			// 
			this->but_save->Location = System::Drawing::Point(85, 427);
			this->but_save->Name = L"but_save";
			this->but_save->Size = System::Drawing::Size(182, 69);
			this->but_save->TabIndex = 2;
			this->but_save->Text = L"Сохранить фигуру";
			this->but_save->UseVisualStyleBackColor = true;
			this->but_save->Click += gcnew System::EventHandler(this, &Sheet::but_save_click);
			// 
			// but_color_back
			// 
			this->but_color_back->Location = System::Drawing::Point(344, 320);
			this->but_color_back->Name = L"but_color_back";
			this->but_color_back->Size = System::Drawing::Size(182, 69);
			this->but_color_back->TabIndex = 3;
			this->but_color_back->Text = L"Выбрать цвет фона";
			this->but_color_back->UseVisualStyleBackColor = true;
			this->but_color_back->Click += gcnew System::EventHandler(this, &Sheet::but_сhange_color_back_click);
			// 
			// but_color_lines
			// 
			this->but_color_lines->Location = System::Drawing::Point(85, 320);
			this->but_color_lines->Name = L"but_color_lines";
			this->but_color_lines->Size = System::Drawing::Size(182, 69);
			this->but_color_lines->TabIndex = 4;
			this->but_color_lines->Text = L"Выбрать цвет линий";
			this->but_color_lines->UseVisualStyleBackColor = true;
			this->but_color_lines->Click += gcnew System::EventHandler(this, &Sheet::but_сhange_color_lines_click);
			// 
			// but_quit
			// 
			this->but_quit->Location = System::Drawing::Point(213, 537);
			this->but_quit->Name = L"but_quit";
			this->but_quit->Size = System::Drawing::Size(182, 65);
			this->but_quit->TabIndex = 6;
			this->but_quit->Text = L"Выйти";
			this->but_quit->UseVisualStyleBackColor = true;
			this->but_quit->Click += gcnew System::EventHandler(this, &Sheet::but_quit_click);
			// 
			// step_choice
			// 
			this->step_choice->DecimalPlaces = 4;
			this->step_choice->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->step_choice->Location = System::Drawing::Point(84, 85);
			this->step_choice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->step_choice->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 262144 });
			this->step_choice->Name = L"step_choice";
			this->step_choice->Size = System::Drawing::Size(120, 22);
			this->step_choice->TabIndex = 9;
			this->step_choice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			// 
			// scale_choice
			// 
			this->scale_choice->Location = System::Drawing::Point(85, 138);
			this->scale_choice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->scale_choice->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->scale_choice->Name = L"scale_choice";
			this->scale_choice->Size = System::Drawing::Size(120, 22);
			this->scale_choice->TabIndex = 10;
			this->scale_choice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			// 
			// line_size_choice
			// 
			this->line_size_choice->Location = System::Drawing::Point(84, 237);
			this->line_size_choice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->line_size_choice->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->line_size_choice->Name = L"line_size_choice";
			this->line_size_choice->Size = System::Drawing::Size(120, 22);
			this->line_size_choice->TabIndex = 11;
			this->line_size_choice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// parameter_choice
			// 
			this->parameter_choice->Location = System::Drawing::Point(85, 188);
			this->parameter_choice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->parameter_choice->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->parameter_choice->Name = L"parameter_choice";
			this->parameter_choice->Size = System::Drawing::Size(120, 22);
			this->parameter_choice->TabIndex = 12;
			this->parameter_choice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// step_label
			// 
			this->step_label->AutoSize = true;
			this->step_label->Location = System::Drawing::Point(210, 87);
			this->step_label->Name = L"step_label";
			this->step_label->Size = System::Drawing::Size(162, 16);
			this->step_label->TabIndex = 13;
			this->step_label->Text = L"Точность (шаг графика)";
			// 
			// scale_label
			// 
			this->scale_label->AutoSize = true;
			this->scale_label->Location = System::Drawing::Point(210, 140);
			this->scale_label->Name = L"scale_label";
			this->scale_label->Size = System::Drawing::Size(124, 16);
			this->scale_label->TabIndex = 14;
			this->scale_label->Text = L"Масштаб графика";
			// 
			// parameter_label
			// 
			this->parameter_label->AutoSize = true;
			this->parameter_label->Location = System::Drawing::Point(210, 190);
			this->parameter_label->Name = L"parameter_label";
			this->parameter_label->Size = System::Drawing::Size(84, 16);
			this->parameter_label->TabIndex = 15;
			this->parameter_label->Text = L"Параметр a";
			// 
			// size_label
			// 
			this->size_label->AutoSize = true;
			this->size_label->Location = System::Drawing::Point(210, 239);
			this->size_label->Name = L"size_label";
			this->size_label->Size = System::Drawing::Size(101, 16);
			this->size_label->TabIndex = 16;
			this->size_label->Text = L"Ширина линии";
			// 
			// Sheet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1400, 618);
			this->Controls->Add(this->size_label);
			this->Controls->Add(this->parameter_label);
			this->Controls->Add(this->scale_label);
			this->Controls->Add(this->step_label);
			this->Controls->Add(this->parameter_choice);
			this->Controls->Add(this->line_size_choice);
			this->Controls->Add(this->scale_choice);
			this->Controls->Add(this->step_choice);
			this->Controls->Add(this->but_quit);
			this->Controls->Add(this->but_color_lines);
			this->Controls->Add(this->but_color_back);
			this->Controls->Add(this->but_save);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->but_build);
			this->Name = L"Sheet";
			this->Text = L"Sheet";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->step_choice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scale_choice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->line_size_choice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->parameter_choice))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 

	//вычисление координаты графика по оси абцисс
	float x(float a, float fi) {
		return 3 * a * tan(fi) / (1 + pow(tan(fi), 3));
	}
	
	//вычисление координаты графика по оси ординат
	float y(float a, float fi) {
		return 3 * a * tan(fi) * tan(fi) / (1 + pow(tan(fi), 3));
	}

	//уменьшение ширины линии
	void decreaseSize(float& size) {
		if (size > 2) size -= 1;
		else if (size > 3) size -= 2;
	}

	//кнопка для построения фигуры
	private: System::Void but_build_click(System::Object^ sender, System::EventArgs^ e) {

		//получение выбора цветов из выпадающих списков
		Color colorFigure = colorDialogLine->Color;
		Color colorBack = colorDialogBack->Color;
				
		graphic->Clear(colorBack); //заполнение фона цветом

		//определение ширины и высоты простанства,
		//которое будет использоваться для изображения графика
		const float width = pictureBox->Width;
		const float height = pictureBox->Height;

		//определение значений переменных из соответсвующих numericUpDown
		float scale = (float)scale_choice->Value; //масштаб
		float parameter = (float)parameter_choice->Value; //параметр а
		float step = (float)step_choice->Value; //шаг по оси X (точность)
		float size = (float)line_size_choice->Value; //ширина линии

		//объявление координат точки
		float temp_x, temp_y;
		
		//объявление и инициализация классов, которые будут использоваться для рисования
		Pen^ pen = gcnew Pen(colorFigure, size);
		SolidBrush^ brush = gcnew SolidBrush(colorFigure);

		//цикл для прорисовки графика
		for (float i = 0; i < 2 * M_PI; i += step) {
			//определение координат точки
			temp_x = width / 2 + scale * x(parameter, i);
			temp_y = height / 2 - scale * y(parameter, i);

			//отрисовка точки
			graphic->FillEllipse(brush, temp_x - size/2, temp_y - size/2, size, size);
		}

		decreaseSize(size); //уменьшение ширины для использования при прорисовке асимптоты

		float last_x = 0;
		float last_y = scale * parameter;
		float tmp_x, tmp_y;

		//цикл для отрисовки асимптоты
		for (int i = 1; i <= width; ++i) {
			tmp_x = i;
			tmp_y = i + scale * parameter;
			if (i % 7 * size < 4 * size) //условие для прорисовки асимптоты пунктиром
				graphic->DrawLine(pen, tmp_x, tmp_y, last_x, last_y);
			last_x = tmp_x;
			last_y = tmp_y;
		}

		//отображение построенной графики в pictureBox
		pictureBox->Image = bitmap;

	}

	//выбор цвета линий
	private: System::Void but_сhange_color_lines_click(System::Object^ sender, System::EventArgs^ e) {
		colorDialogLine->ShowDialog(); //открытие окна для выбора цвета
	}

	//выбор цвета фона
	private: System::Void but_сhange_color_back_click(System::Object^ sender, System::EventArgs^ e) {
		colorDialogBack->ShowDialog(); //открытие окна для выбора цвета
	}
	
	//закрытие программы
	private: System::Void but_quit_click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	//сохранение фигуры
	private: System::Void but_save_click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		//возможность выбора нескольких расширений
		saveFileDialog->Filter = ".jpeg|*.jpeg|.bmp|*.bmp|.png|*.png|.gif|*.gif";
		if(saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) { //если нажали сохранить
			bitmap->Save(saveFileDialog->FileName);                        //то изображение сохраняется в файл с введенным названием
		}                                                                      //и выбранным пользователем расширением

	}

};
}
