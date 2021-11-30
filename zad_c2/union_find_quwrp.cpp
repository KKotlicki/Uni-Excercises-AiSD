/*************************************************************************
*
*  Weighted by rank quick union implementation of union-find algotithm
*  with path compression
*
*  A reference implementation
*
*
*  Author: Jacek Marciniak
*  Date: 2015-11-07
*
*************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


// data
int cc;		  // number of components
int N;		  // number of elements
vector<int> id;   // id[i] = parent of i
vector<int> rnk;  // rnk[i] = hight of subtree rooted at i

// initializes data structures
void init(int size)
{
	cc = size;
	N = size;

	id.resize(size);
	rnk.resize(size);

	for (int i = 0; i < N; i++)
	{
		id[i] = i;
		rnk[i] = 1;
	}
}

// gets component's identifier of the element
int find(int p)
{
	while (p != id[p])
	{
		id[p] = id[id[p]];    // path compression by halving
		p = id[p];
	}
	return p;
}

// check if 2 elements belongs to the same component
bool connected(int p, int q)
{
	return find(p) == find(q);
}

// connect components
void make_union(int p, int q)
{
	int pid = find(p);
	int qid = find(q);

	if (pid == qid) return;

	// root of shorter tree point to higher one
	if (rnk[pid] < rnk[qid])
	{
		id[pid] = qid;
	}
	else if (rnk[pid] > rnk[qid])
	{
		id[qid] = pid;
	}
	else
	{
		id[pid] = qid;
		rnk[qid]++;
	}

	cc--;
}

// print an array
void print_id()
{
	cout << "[";
	for (int i = 0; i < N; i++)
	{
		cout << (i > 0 ? "," : "") << id[i];
	}
	cout << "]" << endl;
}

// main entry to the program - union-find algoritm testing
int main(int argc, char* argv[])
{
	// parameter
	bool verbose = argc > 1 && !strcmp(argv[1], "-v");

	// read number of elements
	int N;
	cin >> N;
	init(N);

	// read unions
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int a, b;
		cin >> a >> b;
		make_union(a, b);

		if (verbose) print_id();
	}

	// write number of components
	cout << cc << endl;
	return 0;
}
