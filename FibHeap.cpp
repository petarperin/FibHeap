#include "FibHeap.h"
#include <stack>
using namespace std;

void FibHeap::init()
{
	ptr = NULL;
	n = 0;
	cout << " Unesite za: MAX - 0, MIN - 1" << endl;
	cin >> min;
}

void FibHeap::print()
{
	if (ptr == NULL) return;
	node *tmp = ptr->left;
	while (tmp != ptr)
	{
		cout << tmp->key << ' ';
		tmp = tmp->left;
	}

	cout << tmp->key << ' ';
	cout << endl;

}

node * make_node(int key)
{
	node *a = new node;

	a->p = a->c = NULL;
	a->left = a->right = a;
	a->key = key;
	a->deg = 0;
	a->mark = 0;

	return a;
}

void FibHeap::add(int elem, int &steps)
{
	steps = 1;
	node *new_node = make_node(elem);
	if (ptr != NULL)
	{
		node *left = ptr->left;
		node *right = new_node->right;

		ptr->left = new_node;
		new_node->right = ptr;

		left->right = right;
		right->left = left;

	}

	bool flag = ptr && (ptr->key > new_node->key);

	if ((min && flag) || (!min && !flag) || ptr == NULL) ptr = new_node;
	n++;
}
void FibHeap::destroy()
{
	delete(this);
	this->init();
}
int FibHeap::get()
{
	return ptr->key;
}

void FibHeap::unite(FibHeap &h, int &steps)
{

	if (h.ptr == NULL || h.min != min) {
		cout << "greska" << endl; return;
	}

	node *new_node = h.ptr;
	if (ptr != NULL)
	{
		node *left = ptr->left;
		node *right = new_node->right;
		ptr->left = new_node;
		new_node->right = ptr;

		left->right = right;
		right->left = left;
	}

	bool flag = ptr && (ptr->key > new_node->key);

	if ((min && flag) || (!min && !flag) || ptr == NULL) ptr = new_node;
	n += h.n;
	h.ptr = NULL;
	h.n = 0;
}

FibHeap::FibHeap()
{
}


FibHeap::~FibHeap()
{
	if (ptr == NULL) return;
	stack <node*> s;
	node *tmp = ptr->left;
	node *tmp2;
	while (tmp != ptr)
	{
		if (tmp->c != NULL)
		{
			s.push(tmp->c);
		}
		tmp2 = tmp->left;
		delete(tmp);
		tmp = tmp2;
	}

	if (tmp->c != NULL)
	{
		s.push(tmp->c);
	}
	delete(tmp);

	while (!s.empty())
	{
		tmp = s.top();
		s.pop();

		if (tmp->c)
			s.push(tmp->c);

		if (tmp->left != tmp)
			while (tmp->left)
			{
				tmp2 = tmp->left;
				delete(tmp);
				tmp = tmp2;
				if (tmp->c)
					s.push(tmp->c);
			}
		else
			delete tmp;

	}
	
}

