#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project1::LoginForm^ login = gcnew Project1::LoginForm();
    Application::Run(login);
}