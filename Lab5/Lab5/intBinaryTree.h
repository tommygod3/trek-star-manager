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
	void deleteNode(node* node);
	node* findParent(int childData,node* subtree = nullptr);//default subtree is root
	bool isParent(node* parent, int childData);
	bool isNode(node* check, int data);
	node* getNode(int data, node* subtree = nullptr);
	node* getSmallestInSubTree(node* node);
};