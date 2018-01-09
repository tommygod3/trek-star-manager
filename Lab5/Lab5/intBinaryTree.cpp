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
			node* parent = findParent(head->data);
			if (parent->leftChild == head)
			{
				parent->leftChild = nullptr;
				delete head;
				return;
			}
			if (parent->rightChild == head)
			{
				parent->rightChild = nullptr;
				delete head;
				return;
			}
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

void intBinaryTree::deleteNode(node* nodeD)
{
	if ((isEmpty(nodeD->leftChild)) && (isEmpty(nodeD->rightChild)))
	{
		deleteSubTree(nodeD);
		return;
	}
	if ((isEmpty(nodeD->leftChild))!=(!isEmpty(nodeD->rightChild)))
	{
		node* parent = findParent(nodeD->data);
		if (parent->leftChild == nodeD)
		{
			if (!isEmpty(nodeD->leftChild))
			{
				parent->leftChild = nodeD->leftChild;
			}
			if (!isEmpty(nodeD->rightChild))
			{
				parent->leftChild = nodeD->rightChild;
			}
			delete nodeD;
			return;
		}
		if (parent->rightChild == nodeD)
		{
			if (!isEmpty(nodeD->leftChild))
			{
				parent->rightChild = nodeD->leftChild;
			}
			if (!isEmpty(nodeD->rightChild))
			{
				parent->rightChild = nodeD->rightChild;
			}
			delete nodeD;
			return;
		}
	}
	if ((!isEmpty(nodeD->leftChild)) && (!isEmpty(nodeD->rightChild)))
	{
		//
		return;
	}
}

intBinaryTree::node* intBinaryTree::getSmallestInSubTree(node* node)
{
	if (node->leftChild == nullptr)
	{
		return node;
	}
	else
	{
		return getSmallestInSubTree(node->leftChild);
	}
}

bool intBinaryTree::isParent(node* parent, int childData)
{
	if ((parent->leftChild) != nullptr)
	{
		if (parent->leftChild->data == childData)
		{
			return 1;
		}
	}
	if ((parent->rightChild) != nullptr)
	{
		if (parent->rightChild->data == childData)
		{
			return 1;
		}
	}
	return 0;
}

bool intBinaryTree::isNode(node* check, int data)
{
	if ((check->data) == data)
	{
		return 1;
	}
	return 0;
}

intBinaryTree::node* intBinaryTree::findParent(int childData, node* subtree)
{
	node* parent = subtree;
	node* parent1;
	if (subtree == nullptr)
	{
		parent = root;
	}
	parent1 = parent;

	if (isParent(parent, childData))
	{
		return parent;
	}
	if (parent->leftChild != nullptr)
	{
		if ((((parent->leftChild->leftChild) != nullptr) || ((parent->leftChild->rightChild) != nullptr)) && ((parent == subtree) || (parent == root)))
		{
			parent = findParent(childData, parent->leftChild);
			if (isParent(parent, childData))
			{
				return parent;
			}
			else
			{
				parent = parent1;
			}
		}
	}
	if (parent->rightChild != nullptr)
	{
		if ((((parent->rightChild->leftChild) != nullptr) || ((parent->rightChild->rightChild) != nullptr)) && ((parent == subtree) || (parent == root)))
		{
			parent = findParent(childData, parent->rightChild);
			if (isParent(parent, childData))
			{
				return parent;
			}
			else
			{
				parent = parent1;
			}
		}
	}
}

intBinaryTree::node* intBinaryTree::getNode(int data,node* subtree)
{
	node* search = subtree;
	node* search1;
	if (subtree == nullptr)
	{
		search = root;
	}
	search1 = search;
	
	if (isNode(search, data))
	{
		return search;
	}
	if ((search->leftChild) != nullptr)
	{
		search = getNode(data, search->leftChild);
		if (isNode(search, data))
		{
			return search;
		}
		else
		{
			search = search1;
		}
	}
	if ((search->rightChild) != nullptr)
	{
		search = getNode(data, search->rightChild);
		if (isNode(search, data))
		{
			return search;
		}
		else
		{
			search = search1;
		}
	}
}