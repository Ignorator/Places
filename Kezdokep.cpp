#include "Kezdokep.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main (array<String^>^ args) {
	Application::EnableVisualStyles ();
	Application::SetCompatibleTextRenderingDefault (false);
	Project11::MyForm form;
	Application::Run (%form);
}