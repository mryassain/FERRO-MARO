#include "StdAfx.h"
#include "Form0.h"

bool passesok = false;

System::Void Tchoutchou::Form0::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (textBox1->Text == String::Concat(Convert::ToString(DateTime::Now.Hour),Convert::ToString(DateTime::Now.Minute)))
		button1->Text = "OK",button1->Enabled = false;

	if (button2->Enabled == false)
		InitForm1();

}

System::Void Tchoutchou::Form0::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (textBox2->Text == String::Concat(Convert::ToString(DateTime::Now.Minute),Convert::ToString(DateTime::Now.Hour)))
		button2->Text = "OK",button2->Enabled = false;

	if (button1->Enabled == false)
		InitForm1();
}

System::Void Tchoutchou::Form0::InitForm1()
{
	passesok = true;
	this->~Form0();
}