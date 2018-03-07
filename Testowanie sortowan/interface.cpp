#include "interface.h"

using namespace std;

Interface::Interface(vector<Algorythm>& sortings) : sortings(sortings), programInfo("Krzysztof Dabrowski gr. 1I2\nProjekt 1 - Testowanie szybkosci algorytmow sortujacych\n-------------------------------------------------------\n"), maxi(INT_MAX), mini(0)
{
	tab.resize(1000);
	Generator generator;
	generator.fill(tab, mini, maxi);

	tableAjustmentMenuContent =
		"W tym miejscu mozesz dostosowac tablice, ktora bedzie sortowana\n"
		"1. Zmien rozmiar tablicy\n"
		"2. Zmien zakres generowanych wartosci\n"
		"3. Wprowadz wlasna tablice\n"
		"4. Losuj ponownie wartosci\n"
		"q - wroc do glownego menue";
}

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
			tableAjustmentMenu();
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

void Interface::tableAjustmentMenu()
{
	char decision;
	while (true)
	{
		cout << endl << tableAjustmentMenuContent << endl << endl;

		cin >> decision;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Wyczyszczenie strumienia

		switch (decision)
		{
		case '1':
			cout << "Aktualny rozmiar tablicy to: " << tab.size() << endl << "Wprowadz nowy rozmiar" << endl;
			int size;
			cin >> size;
			if(!cin)
			{
				cout << "Niepoprawny rozmiar" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			
			tab.resize(size);
			regenerateTable();
			break;; 
		case '2':
			int a, b;
			if (!(cin >> a >> b))
			{
				cout << "Niepoprawna wielkosc. Zmiany anulowane" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			if (b > a) swap(a, b);
			
			mini = a;
			maxi = b;
			regenerateTable();
			break;;
		case '3':
			readTableFromUser();
			break;;
		case '4':
			regenerateTable();
			break;;
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

void Interface::regenerateTable()
{
	Generator generator;
	generator.fill(tab, mini, maxi);
}

void Interface::readTableFromUser()
{
	tab.clear();

	cout << "Podowaj kolejne liczby calkowite. Wpisanie \"q\" zakonczy wprowadzaie danych" << endl << endl;

	int liczba;
	while (true)
	{
		cin >> liczba;
		if (!cin)
		{
			cin.clear();
			if (cin.peek() == 'q')
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
				
			cout << "Niepoprawna liczba" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			tab.push_back(liczba);
		}
	}

	cout << "Tablica zostala zapisana" << endl;
}
