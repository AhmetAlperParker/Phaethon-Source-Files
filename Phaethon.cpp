// Phaethon.cpp : main project file.

#include "stdafx.h"
#include "F_Main.h"

using namespace Phaethon;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew F_Main());
	return 0;
}
