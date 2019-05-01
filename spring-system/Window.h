#pragma once
#include "springsystem.h"

namespace springsystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			
			chart1->ChartAreas[0]->AxisX->Maximum = Math::Abs((double)dx_val->Value) + 25;
			chart1->ChartAreas[0]->AxisY->Maximum = Math::Abs((double)dy_val->Value) + 25;
			chart1->ChartAreas[0]->AxisX->Minimum = -Math::Abs((double)dx_val->Value) - 25;
			chart1->ChartAreas[0]->AxisY->Minimum = -Math::Abs((double)dy_val->Value) - 25;

			chart1->Series["Mass"]->Points->Clear();
			chart1->Series["Mass"]->Points->AddXY((double)dx_val->Value, (double)dy_val->Value);

			chart1->Series["Box"]->Points->Clear();
			chart1->Series["Box"]->Points->AddXY(Math::Abs((double)dx_val->Value) + 10, Math::Abs((double)dy_val->Value) + 10);
			chart1->Series["Box"]->Points->AddXY(Math::Abs((double)dx_val->Value) + 10, -Math::Abs((double)dy_val->Value) - 10);
			chart1->Series["Box"]->Points->AddXY(-Math::Abs((double)dx_val->Value) - 10, -Math::Abs((double)dy_val->Value) - 10);
			chart1->Series["Box"]->Points->AddXY(-Math::Abs((double)dx_val->Value) - 10, Math::Abs((double)dy_val->Value) + 10);
			chart1->Series["Box"]->Points->AddXY(Math::Abs((double)dx_val->Value) + 10, Math::Abs((double)dy_val->Value) + 10);
		}

	protected:
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  start_button;
	private: System::Windows::Forms::NumericUpDown^  k1_val;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  k2_val;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  k3_val;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  k4_val;
	private: System::Windows::Forms::Button^  pause_button;
	private: System::Windows::Forms::Button^  stop_button;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::NumericUpDown^  dx_val;
	private: System::Windows::Forms::NumericUpDown^  dy_val;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::NumericUpDown^  massm_val;
	private: System::Windows::Forms::NumericUpDown^  boxm_val;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::NumericUpDown^  mu_val;




	private: System::ComponentModel::IContainer^  components;



	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::CustomLabel^  customLabel1 = (gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel());
			System::Windows::Forms::DataVisualization::Charting::CustomLabel^  customLabel2 = (gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				0));
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->k1_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->k2_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->k3_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->k4_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->pause_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dx_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->dy_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->massm_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->boxm_val = (gcnew System::Windows::Forms::NumericUpDown());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->mu_val = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k1_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k2_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k3_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k4_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dx_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dy_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->massm_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxm_val))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mu_val))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->CustomLabels->Add(customLabel1);
			chartArea1->AxisX->MajorGrid->Interval = 5;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisX->MinorGrid->Enabled = true;
			chartArea1->AxisX->MinorGrid->Interval = 1;
			chartArea1->AxisX->MinorGrid->LineColor = System::Drawing::Color::Gainsboro;
			chartArea1->AxisY->CustomLabels->Add(customLabel2);
			chartArea1->AxisY->MajorGrid->Interval = 5;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::Gray;
			chartArea1->AxisY->MinorGrid->Enabled = true;
			chartArea1->AxisY->MinorGrid->Interval = 1;
			chartArea1->AxisY->MinorGrid->LineColor = System::Drawing::Color::Gainsboro;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(12, 119);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 5;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Black;
			series1->MarkerColor = System::Drawing::Color::Black;
			series1->Name = L"Box";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->MarkerColor = System::Drawing::Color::DimGray;
			series2->MarkerSize = 15;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series2->Name = L"Mass";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series3->MarkerColor = System::Drawing::Color::Transparent;
			series3->MarkerSize = 0;
			series3->Name = L"TransparentCenter";
			series3->Points->Add(dataPoint1);
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series4->Name = L"Traj";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(474, 339);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"k1 = ";
			// 
			// start_button
			// 
			this->start_button->Location = System::Drawing::Point(347, 7);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(139, 23);
			this->start_button->TabIndex = 10;
			this->start_button->Text = L"Start";
			this->start_button->UseVisualStyleBackColor = true;
			this->start_button->Click += gcnew System::EventHandler(this, &Window::start_button_Click);
			// 
			// k1_val
			// 
			this->k1_val->DecimalPlaces = 2;
			this->k1_val->Location = System::Drawing::Point(46, 15);
			this->k1_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->k1_val->Name = L"k1_val";
			this->k1_val->Size = System::Drawing::Size(80, 20);
			this->k1_val->TabIndex = 1;
			this->k1_val->ThousandsSeparator = true;
			this->k1_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(132, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"N/m";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"k2 = ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(132, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"N/m";
			// 
			// k2_val
			// 
			this->k2_val->DecimalPlaces = 2;
			this->k2_val->Location = System::Drawing::Point(46, 41);
			this->k2_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->k2_val->Name = L"k2_val";
			this->k2_val->Size = System::Drawing::Size(80, 20);
			this->k2_val->TabIndex = 2;
			this->k2_val->ThousandsSeparator = true;
			this->k2_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 69);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"k3 = ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(132, 69);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"N/m";
			// 
			// k3_val
			// 
			this->k3_val->DecimalPlaces = 2;
			this->k3_val->Location = System::Drawing::Point(46, 67);
			this->k3_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->k3_val->Name = L"k3_val";
			this->k3_val->Size = System::Drawing::Size(80, 20);
			this->k3_val->TabIndex = 3;
			this->k3_val->ThousandsSeparator = true;
			this->k3_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"k4 = ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(132, 95);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"N/m";
			// 
			// k4_val
			// 
			this->k4_val->DecimalPlaces = 2;
			this->k4_val->Location = System::Drawing::Point(46, 93);
			this->k4_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->k4_val->Name = L"k4_val";
			this->k4_val->Size = System::Drawing::Size(80, 20);
			this->k4_val->TabIndex = 4;
			this->k4_val->ThousandsSeparator = true;
			this->k4_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			// 
			// pause_button
			// 
			this->pause_button->Enabled = false;
			this->pause_button->Location = System::Drawing::Point(347, 33);
			this->pause_button->Name = L"pause_button";
			this->pause_button->Size = System::Drawing::Size(139, 23);
			this->pause_button->TabIndex = 11;
			this->pause_button->Text = L"Pause";
			this->pause_button->UseVisualStyleBackColor = true;
			this->pause_button->Click += gcnew System::EventHandler(this, &Window::pause_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->stop_button->Enabled = false;
			this->stop_button->Location = System::Drawing::Point(347, 59);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(139, 23);
			this->stop_button->TabIndex = 12;
			this->stop_button->Text = L"Stop";
			this->stop_button->UseVisualStyleBackColor = true;
			this->stop_button->Click += gcnew System::EventHandler(this, &Window::stop_button_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(186, 95);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"dX = ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(344, 95);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"dY = ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(309, 95);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(21, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"cm";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(467, 95);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 13);
			this->label12->TabIndex = 1;
			this->label12->Text = L"cm";
			// 
			// dx_val
			// 
			this->dx_val->Location = System::Drawing::Point(223, 93);
			this->dx_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->dx_val->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, System::Int32::MinValue });
			this->dx_val->Name = L"dx_val";
			this->dx_val->Size = System::Drawing::Size(80, 20);
			this->dx_val->TabIndex = 8;
			this->dx_val->ThousandsSeparator = true;
			this->dx_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->dx_val->ValueChanged += gcnew System::EventHandler(this, &Window::d_change);
			// 
			// dy_val
			// 
			this->dy_val->Location = System::Drawing::Point(381, 93);
			this->dy_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->dy_val->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, System::Int32::MinValue });
			this->dy_val->Name = L"dy_val";
			this->dy_val->Size = System::Drawing::Size(80, 20);
			this->dy_val->TabIndex = 9;
			this->dy_val->ThousandsSeparator = true;
			this->dy_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->dy_val->ValueChanged += gcnew System::EventHandler(this, &Window::d_change);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &Window::timer1_Tick);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(186, 17);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(27, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"m = ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(186, 43);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(28, 13);
			this->label14->TabIndex = 1;
			this->label14->Text = L"M = ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(309, 17);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(13, 13);
			this->label15->TabIndex = 1;
			this->label15->Text = L"g";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(309, 43);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(13, 13);
			this->label16->TabIndex = 1;
			this->label16->Text = L"g";
			// 
			// massm_val
			// 
			this->massm_val->Location = System::Drawing::Point(223, 15);
			this->massm_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->massm_val->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, System::Int32::MinValue });
			this->massm_val->Name = L"massm_val";
			this->massm_val->Size = System::Drawing::Size(80, 20);
			this->massm_val->TabIndex = 5;
			this->massm_val->ThousandsSeparator = true;
			this->massm_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->massm_val->ValueChanged += gcnew System::EventHandler(this, &Window::d_change);
			// 
			// boxm_val
			// 
			this->boxm_val->Location = System::Drawing::Point(223, 41);
			this->boxm_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->boxm_val->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, System::Int32::MinValue });
			this->boxm_val->Name = L"boxm_val";
			this->boxm_val->Size = System::Drawing::Size(80, 20);
			this->boxm_val->TabIndex = 6;
			this->boxm_val->ThousandsSeparator = true;
			this->boxm_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 800, 0, 0, 0 });
			this->boxm_val->ValueChanged += gcnew System::EventHandler(this, &Window::d_change);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(186, 69);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(33, 13);
			this->label17->TabIndex = 1;
			this->label17->Text = L"mu = ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(309, 69);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 13);
			this->label18->TabIndex = 1;
			// 
			// mu_val
			// 
			this->mu_val->DecimalPlaces = 2;
			this->mu_val->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->mu_val->Location = System::Drawing::Point(223, 67);
			this->mu_val->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->mu_val->Name = L"mu_val";
			this->mu_val->Size = System::Drawing::Size(80, 20);
			this->mu_val->TabIndex = 7;
			this->mu_val->ThousandsSeparator = true;
			this->mu_val->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			this->mu_val->ValueChanged += gcnew System::EventHandler(this, &Window::d_change);
			// 
			// Window
			// 
			this->AcceptButton = this->start_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->stop_button;
			this->ClientSize = System::Drawing::Size(498, 470);
			this->Controls->Add(this->k4_val);
			this->Controls->Add(this->k3_val);
			this->Controls->Add(this->mu_val);
			this->Controls->Add(this->boxm_val);
			this->Controls->Add(this->dy_val);
			this->Controls->Add(this->k2_val);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->massm_val);
			this->Controls->Add(this->dx_val);
			this->Controls->Add(this->k1_val);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->pause_button);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Name = L"Window";
			this->Text = L"Window";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k1_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k2_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k3_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->k4_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dx_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dy_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->massm_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxm_val))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mu_val))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		private: double box_w, box_h, mass_x, mass_y;
		private: double k1, k2, k3, k4;
		private: springsys* p;

		private: System::Void d_change(System::Object^  sender, System::EventArgs^  e);
		private: System::Void start_button_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void pause_button_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void stop_button_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}
