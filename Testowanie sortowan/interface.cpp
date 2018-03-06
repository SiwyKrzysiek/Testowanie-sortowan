#include "interface.h"

using namespace std;

void Interface::mainMenu()
{
	char decision;
	while (true)
	{
		cout << endl << mainMenuContent() << endl << endl;

		cin >> decision;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Wyczyszczenie strumienia

		switch (decision)
		{
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
#ifdef _DEBUG
		case '4':

			break;
#endif
		case 'q':
			return;
		default:
			cout << "Nierozpoznay znak. Sprobuj ponownie" << endl;
		}
	}
}

string Interface::mainMenuContent() const
{
	return "Wybierz akcje:\n"
		"1. Przeprowadz test wszystkich sortowan\n"
		"2. Dostosuj dane do sortowania\n"
		"3. Testuj wybrane sortowanie\n"
#ifdef _DEBUG
		"4. Testowanie manualne\n"
#endif
		"q - wyjdz";
}
