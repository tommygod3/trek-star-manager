#include "node.h"

node* node::newNode(int value)
{
	node* x = new node;
	x->data = value;
	return x;
}