#pragma once

class node
{
public:
	int data;
	node* leftChild;
	node* rightChild;
	node* newNode(int value);
};