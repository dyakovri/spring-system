#include "Window.h"

namespace springsystem {

	System::Void Window::d_change(System::Object^  sender, System::EventArgs^  e) {
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

	System::Void Window::start_button_Click(System::Object^  sender, System::EventArgs^  e) {
		k1 = (double)k1_val->Value;
		k2 = (double)k2_val->Value;
		k3 = (double)k3_val->Value;
		k4 = (double)k4_val->Value;

		box_w = 2 * Math::Abs((double)dx_val->Value) + 20;
		box_h = 2 * Math::Abs((double)dy_val->Value) + 20;

		box_x = 0;
		box_y = 0;

		mass_x = (double)dx_val->Value;
		mass_y = (double)dy_val->Value;

		//p = new springsys();

		timer1->Start();
	}

	System::Void Window::pause_button_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}

	System::Void Window::stop_button_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		//delete p; p = 0;
	}

	System::Void Window::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//p->NextStep(((double)timer1->Interval) / 1000.0);
	}
}