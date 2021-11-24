#include <iostream>

using namespace std;


int main()
{
	// odczytaj rozmiar tablicy
	int N;
	cin >> N;

	// suma
	int sum = 0;
	int a;

	// czytaj kolejne elementy tablicy
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		sum += a;
	}
	
	// wypisz wynik na konsole
	cout << sum << endl;

	return 0;
}
