#pragma once
#include <iostream>

using namespace std;

struct node
{
	node *p, *c, *left, *right;
	int key;
	int deg;
	bool mark;
};

class FibHeap
{
private:
	int n;
	node *ptr;
	bool min;
	friend node* make_node(int key);


public:
	void init();
	void print();
	int get();
	void unite(FibHeap &h, int &steps);
	void add(int elem, int &steps);
	void destroy();
	FibHeap();
	~FibHeap();
};

