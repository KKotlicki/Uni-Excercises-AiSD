/*************************************************************************
*
*  Weighted quick union implementation of union-find algotithm
*  with path compression by halving
* 
*  A reference implementation in C++
*
*  Based on book "Algorytmy" by R. Sedgewick, K. Weyne, wydanie IV
*
*  Author: Jacek Marciniak
*  Date: 2015-11-07
*  
*************************************************************************/


class union_find
{
private:
	int count;	// number of components
	int N;		// number of elements
	int* id;	// id[i] = parent of i
	int* sz;	// sz[i] = number of elements in subtree rooted at i

public:
	union_find(int N) : count(N), N(N), id (0), sz(0)
	{
		id = new int[N];
		sz = new int[N];

		for (int i = 0; i < N; i++)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}

	~union_find()
	{
		delete[] id;
		delete[] sz;
	}

	// gets number of components
	int get_count() const
	{
		return count;
	}

	// gets component's identifier of the element
	int find(int p) const 
	{
		while (p != id[p])
		{
			id[p] = id[id[p]];    // path compression by halving
			p = id[p];
		}

		return p;
	}

	// check if 2 elements belongs to the same component
	bool connected(int p, int q) const
	{
		return find(p) == find(q);
	}

	// connect components
	void make_union(int p, int q)
	{
		int pid = find(p);
		int qid = find(q);
		
		if (pid == qid) return;

		// make smaller root point to larger one
		if (sz[qid] < sz[pid])
		{
			id[qid] = pid;
			sz[pid] += sz[qid];
		}
		else
		{
			id[pid] = qid;
			sz[qid] += sz[pid];
		}

		count--;
	}
};
