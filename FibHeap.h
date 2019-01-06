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

public:
	FibHeap();
	~FibHeap();
};

