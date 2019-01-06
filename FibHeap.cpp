#include "FibHeap.h"

void FibHeap::init()
{
	ptr = NULL;
	n = 0;
	cin << min;
}

void FibHeap::add(int elem, int &steps)
{
	steps = 1;
	node *new_node = make_node(elem);
	if(ptr != NULL)
	{
		node *left = ptr->left;
		node *right = new_node->right;
		
		ptr->left = new_node;
		new_node->right = ptr;
		
		left->right = right;
		right->left = left;
		
	}
	
	bool flag = (ptr->key < new_node->key);
	
	if((min && flag) || (!min && !flaf) || ptr == NULL) ptr = new_node;
	
}
int FibHeap::get()
{
	return ptr->key;
}

void unite(FibHeap h, int &steps)
{
	
	node *new_node = h.ptr;
	if(ptr != NULL)
	{
		node *left = ptr->left;
		ptr->left = new_node;
		left->right = new_node;
		
		new_node->right = ptr;
		new_node->left = left;
	}
	
	bool flag = (ptr->key < new_node->key);
	
	if((min && flag) || (!min && !flaf) || ptr == NULL) ptr = new_node;
}

FibHeap::FibHeap()
{
}


FibHeap::~FibHeap()
{
}
