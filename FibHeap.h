#pragma once
class FibHeap
{
	struct node
	{
		node *p, *c, *left, *right;
		int key;
		int deg;
		bool mark;
	};
	int n;
	node *ptr;
	bool min;
	

public:
	void init();
	int get();
	void unite(FibHeap h, int &steps);
	void add(int elem, int &steps);
	FibHeap();
	~FibHeap();
};

