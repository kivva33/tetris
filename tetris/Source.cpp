#include "MyForm.h"

using namespace tetris;

[STAThreadAttribute]
int main(array<String^>^ arsv) {
	srand(time(NULL));
	Application::Run(gcnew MyForm());
	return 0;
}