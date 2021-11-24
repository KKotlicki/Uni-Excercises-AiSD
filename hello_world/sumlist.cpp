#include <iostream>

using namespace std;


int main()
{
	// suma
	int sum = 0;
	int a;
	
	// czytaj wszystkie liczby ze standardowego wejscia
	while (cin >> a)
	{
		sum += a;
	}
	
	// wypisz wynik na konsole
	cout << sum << endl;

	return 0;
}
