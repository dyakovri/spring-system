#include "Window.h"

namespace springsystem {
	bool paused;

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

		box_h = Math::Abs((double)dy_val->Value) + 10;
		box_w = Math::Abs((double)dx_val->Value) + 10;
		
		mass_x = (double)dx_val->Value;
		mass_y = (double)dy_val->Value;

		p = new springsys((double)massm_val->Value / 1000.0, (double)boxm_val->Value / 1000.0, (double)k1_val->Value, (double)k2_val->Value, (double)k3_val->Value, (double)k4_val->Value, (double)mu_val->Value, (double)dx_val->Value, (double)dy_val->Value, box_w, box_h);

		timer1->Start();

		start_button->Enabled = false;
		pause_button->Enabled = true;
		stop_button->Enabled = true;


		paused = false;
	}

	System::Void Window::pause_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (paused) {
			paused = false;
			timer1->Start();
		}
		else {
			paused = true;
			timer1->Stop();
		}
	}

	System::Void Window::stop_button_Click(System::Object^  sender, System::EventArgs^  e) {
		paused = false;
		timer1->Stop();

		chart1->Series["Mass"]->Points->Clear();
		chart1->Series["Box"]->Points->Clear();
		chart1->Series["Traj"]->Points->Clear();
		chart1->Series["Spring1"]->Points->Clear();
		chart1->Series["Spring2"]->Points->Clear();
		chart1->Series["Spring3"]->Points->Clear();
		chart1->Series["Spring4"]->Points->Clear();

		start_button->Enabled = true;
		pause_button->Enabled = false;
		stop_button->Enabled = false;

		delete p; p = 0;
	}

	System::Void Window::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		p->NextStep(((double)timer1->Interval) / 1000.0);

		chart1->Series["Mass"]->Points->Clear();
		chart1->Series["Mass"]->Points->AddXY(p->get_x(), p->get_y());
		chart1->Series["Traj"]->Points->AddXY(p->get_x(), p->get_y());

		chart1->Series["Box"]->Points->Clear();
		chart1->Series["Box"]->Points->AddXY(p->get_X() + box_w, p->get_Y() + box_h);
		chart1->Series["Box"]->Points->AddXY(p->get_X() + box_w, p->get_Y() - box_h);
		chart1->Series["Box"]->Points->AddXY(p->get_X() - box_w, p->get_Y() - box_h);
		chart1->Series["Box"]->Points->AddXY(p->get_X() - box_w, p->get_Y() + box_h);
		chart1->Series["Box"]->Points->AddXY(p->get_X() + box_w, p->get_Y() + box_h);


		chart1->Series["Spring1"]->Points->Clear();
		chart1->Series["Spring1"]->Points->AddXY(p->get_spring_begin(0)[0], p->get_spring_begin(0)[1]);
		chart1->Series["Spring1"]->Points->AddXY(p->get_x(), p->get_y());

		chart1->Series["Spring2"]->Points->Clear();
		chart1->Series["Spring2"]->Points->AddXY(p->get_spring_begin(1)[0], p->get_spring_begin(1)[1]);
		chart1->Series["Spring2"]->Points->AddXY(p->get_x(), p->get_y());

		chart1->Series["Spring3"]->Points->Clear();
		chart1->Series["Spring3"]->Points->AddXY(p->get_spring_begin(2)[0], p->get_spring_begin(2)[1]);
		chart1->Series["Spring3"]->Points->AddXY(p->get_x(), p->get_y());

		chart1->Series["Spring4"]->Points->Clear();
		chart1->Series["Spring4"]->Points->AddXY(p->get_spring_begin(3)[0], p->get_spring_begin(3)[1]);
		chart1->Series["Spring4"]->Points->AddXY(p->get_x(), p->get_y());

	}
}