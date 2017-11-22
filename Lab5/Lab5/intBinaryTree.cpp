#include "stdafx.h"
#include "intBinaryTree.h"

intBinaryTree::intBinaryTree()
{
	root = nullptr;
}

intBinaryTree::~intBinaryTree()
{
	std::cout << "Deleting tree" << std::endl;
	if (!isEmpty(root))
	{
		deleteSubTree(root);
	}
	std::cout << "Tree successfully deleted" << std::endl;
}

void intBinaryTree::deleteSubTree(node* head)
{
	if (!isEmpty(head->leftChild))
	{
		deleteSubTree(head->leftChild);
		head->leftChild = nullptr;
	}
	if (!isEmpty(head->rightChild))
	{
		deleteSubTree(head->rightChild);
		head->rightChild = nullptr;
	}
	if ((isEmpty(head->leftChild)) && (isEmpty(head->rightChild)))
	{
		std::cout << head->data << std::endl;
		if (head == root)
		{
			delete head;
			root = nullptr;
			return;
		}
		else
		{
			delete head;
		}
	}
}

bool intBinaryTree::isEmpty(node* node)
{
	if (node == nullptr)
	{
		return true;
	}
	else if (node != nullptr)
	{
		return false;
	}
}

intBinaryTree::node* intBinaryTree::newNode(int value)
{
	node *x = new node();
	x->data = value;
	x->leftChild = nullptr;
	x->rightChild = nullptr;
	return x;
}

void intBinaryTree::insertNode(int value,node* location)
{
	if (isEmpty(location))
	{
		root=newNode(value);
	}
	else if (value<location->data)
	{
		if (isEmpty(location->leftChild))
		{
			//new left node
			location->leftChild = newNode(value);
		}
		else
		{
			insertNode(value, location->leftChild);
		}
	}
	else if (value > location->data)
	{
		if (isEmpty(location->rightChild))
		{
			//new right node
			location->rightChild = newNode(value);
		}
		else
		{
			insertNode(value, location->rightChild);
		}
	}
	else if (value == location->data)
	{
		if (isEmpty(location->rightChild))
		{
			//new right node
			location->rightChild = newNode(value);
		}
		else
		{
			insertNode(value, location->rightChild);
		}
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
}

void intBinaryTree::printPostOrder(node* node)
{
	if (isEmpty(node))
	{
		return;
	}
	printPostOrder(node->leftChild);

	printPostOrder(node->rightChild);

	std::cout << node->data << " " << std::endl;
}

void intBinaryTree::printPreOrder(node* node)
{
	if (isEmpty(node))
	{
		return;
	}
	std::cout << node->data << " " << std::endl;

	printPreOrder(node->leftChild);

	printPreOrder(node->rightChild);
}

void intBinaryTree::printInOrder(node* node)
{
	if (isEmpty(node))
	{
		return;
	}
	printInOrder(node->leftChild);

	std::cout << node->data << " " << std::endl;

	printInOrder(node->rightChild);
}
