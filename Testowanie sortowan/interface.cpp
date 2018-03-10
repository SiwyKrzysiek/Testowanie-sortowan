#include "interface.h"

using namespace std;

Interface::Interface(vector<Algorythm>& sortings) : sortings(sortings), programInfo("Krzysztof Dabrowski gr. 1I2\nProjekt 1 - Testowanie szybkosci algorytmow sortujacych\n-------------------------------------------------------\n"), maxi(INT_MAX), mini(0)
{
	tab.resize(5000);
	Generator generator;
	generator.fill(tab, maxi, mini);

	tableAjustmentMenuContent =
		"W tym miejscu mozesz dostosowac tablice, ktora bedzie sortowana\n"
		"1. Zmien rozmiar tablicy\n"
		"2. Zmien zakres generowanych wartosci\n"
		"3. Wprowadz wlasna tablice\n"
		"4. Losuj ponownie wartosci\n"
		"q - wroc do glownego menu";
}

void Interface::mainMenu()
{
	while (true)
	{
		cout << endl << mainMenuContent() << endl << endl;

		char decision;
		cin >> decision;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Wyczyszczenie strumienia

		switch (decision)
		{
		case '1':
			testAllSortings();
			break;
		case '2':
			tableAjustmentMenu();
			break;
		case '3':
			testGivenSorting();
			break;
#ifdef _DEBUG
		case '4':
			Test::testingMenu();
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

void Interface::testAllSortings()
{
	vector<pair<string, double>> namesAndTimes;

	for (Algorythm& sorting : sortings)
	{
		double time = Timer::timeOfSorting(sorting, tab);
		cout << sorting << "\nCzas sortowania " << tab.size() << " elementow: " <<  time << "s\n\n";

		namesAndTimes.push_back(make_pair(sorting.getName(), time));
	}

	sort(namesAndTimes.begin(), namesAndTimes.end(), [](pair<string, double> a, pair<string, double> b) {return a.second < b.second; });

	cout << "Ranking algorytmow wzgledem czasu sortwoania:" << endl;
	int i = 1;
	for (pair<string, double>& info : namesAndTimes)
	{
		cout << i++ << ". " << info.first << endl;
	}

	cout << endl;
}

void Interface::testGivenSorting()
{
	cout << "Wybierz, ktore sortowanie chcesz przetestowac: " << endl;

	int i = 1;
	for (Algorythm& sorting : sortings)
		cout << i++ << ". " << sorting.getName() << endl;
	cout << endl;
	
	int choice;
	cin >> choice;
	if (!cin || choice > sortings.size() || choice <= 0)
	{
		cout << "Niepoprawny numer algorytmu" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	cout << sortings[choice-1] << "\nCzas sortowania " << tab.size() << " elementow: " << Timer::timeOfSorting(sortings[choice - 1], tab) << "s\n";
}