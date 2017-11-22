#pragma once
#include <iostream>

class intBinaryTree
{
public:
	struct node
	{
		int data;
		node* leftChild;
		node* rightChild;
		~node()
		{
			std::cout << "Node deleted" << std::endl;
		}
	};
	node* root;
	intBinaryTree();
	~intBinaryTree();
	node* newNode(int value);
	void insertNode(int value,node* location);
	bool isEmpty(node* child);
	void printPostOrder(node* node);
	void printPreOrder(node* node);
	void printInOrder(node* node);
	void deleteSubTree(node* head);
};