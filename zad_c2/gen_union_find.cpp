/*************************************************************************
*
*  Generator of test cases for union find algorithm
*
*  Author: Jacek Marciniak
*  Date: 2016-11-12
*  
*************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <random>

using namespace std;



// Random number generator
struct UniRand
{
	mt19937 g;
	uniform_int_distribution<int> d;
	UniRand(int m, int n) : g(chrono::system_clock::now().time_since_epoch().count()), d(m, n) {}
	int next() { return d(g); }
	static int rand(int m, int n) { return UniRand(m, n).next();}
};

int print_info()
{
	cout << "Use:" << endl;
	cout << "gen_union_find r 100 10 - 10 random unions for 100 elements" << endl;
	cout << "gen_union_find h 100 - maximize tree hight" << endl;
	cout << "gen_union_find w 100 - maximize number of operations for weighted tree" << endl;
	return -1;
}

int random(int N, int M)
{
	UniRand r(0, N - 1);
	
	cout << N << endl;
	cout << M << endl;
	for (int i = 0; i < M; i++)
	{
		cout << r.next() << " " << r.next() << endl;
	}
	return 0;
}

int max_height(int N)
{
	cout << N << endl;
	cout << N - 1 << endl;
	for (int i = 1; i < N; i++)
	{
		cout << "0 " << i << endl;
	}
	return 0;
}

int max_weighted(int N)
{
	cout << N << endl;
	cout << N - 1 << endl;

	int M = 0;

	for (int sz = 1; sz < N; sz += sz)
	{
		for (int p = 0; p < N - sz; p += sz + sz)
		{
			int q = p + sz;
			if (q > N - 1) continue;
			cout << p << " " << q << " " << endl;
			M++;
		}
	}

	if (M != N - 1)
	{
		cerr << "Logical error: " << N << " " << M << endl;
		return -1;
	}

	return 0;
}

// main
int main(int argc, char* argv[])
{
	int N = argc < 3 ? 0 : atoi(argv[2]);
	int M = argc < 4 ? 0 : atoi(argv[3]);

	if (argc > 2)
	{
		if (!strcmp(argv[1], "w")) return max_weighted(N);
		if (!strcmp(argv[1], "h")) return max_height(N);
	}
	if (argc > 3)
	{
		if (!strcmp(argv[1], "r")) return random(N, M);
	}
	
	return print_info();
}

