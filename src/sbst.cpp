#include "sbst.h"

namespace SDI
{
	stringBinarySearchTree::stringBinarySearchTree()
	{
		root = nullptr;
	}

	stringBinarySearchTree::~stringBinarySearchTree()
	{
		if (!isEmpty(root))
		{
			deleteSubTree(root);
		}
	}

	void stringBinarySearchTree::deleteSubTree(node* head)
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

	bool stringBinarySearchTree::isEmpty(node* node)
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

	stringBinarySearchTree::node* stringBinarySearchTree::newNode(string value)
	{
		node *x = new node();
		x->data = value;
		x->leftChild = nullptr;
		x->rightChild = nullptr;
		return x;
	}

	void stringBinarySearchTree::insertNode(string value, node* location)
	{
		if (isEmpty(location))
		{
			root = newNode(value);
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
			throw std::invalid_argument("Node cannot be inserted");
		}
	}

	void stringBinarySearchTree::vecPostOrder(node* node, vector<string>& vector)
	{
		if (isEmpty(node))
		{
			return;
		}

		vector.push_back(node->data);

		vecPostOrder(node->leftChild, vector);

		vecPostOrder(node->rightChild, vector);
	}

	void stringBinarySearchTree::vecPreOrder(node* node, vector<string>& vector)
	{
		if (isEmpty(node))
		{
			return;
		}

		vector.push_back(node->data);

		vecPreOrder(node->leftChild, vector);

		vecPreOrder(node->rightChild, vector);
	}

	void stringBinarySearchTree::vecInOrder(node* node, vector<string>& vector)
	{
		if (isEmpty(node))
		{
			return;
		}

		vector.push_back(node->data);

		vecInOrder(node->leftChild, vector);

		vecInOrder(node->rightChild, vector);
	}

	void stringBinarySearchTree::deleteNode(node* nodeD)
	{
		if ((isEmpty(nodeD->leftChild)) && (isEmpty(nodeD->rightChild)))
		{
			deleteSubTree(nodeD);
			return;
		}
		if ((isEmpty(nodeD->leftChild)) != (isEmpty(nodeD->rightChild)))
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
			node* switcher = getSmallestInSubTree(nodeD->rightChild);
			node* parent = findParent(switcher->data);
			nodeD->data = switcher->data;
			if (parent->leftChild == switcher)
			{
				parent->leftChild = nullptr;
				delete switcher;
				return;
			}
			if (parent->rightChild == switcher)
			{
				parent->rightChild = nullptr;
				delete switcher;
				return;
			}
		}
	}

	stringBinarySearchTree::node* stringBinarySearchTree::getSmallestInSubTree(node* node)
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

	bool stringBinarySearchTree::isParent(node* parent, string childData)
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

	bool stringBinarySearchTree::isNode(node* check, string data)
	{
		if ((check->data) == data)
		{
			return 1;
		}
		return 0;
	}

	stringBinarySearchTree::node* stringBinarySearchTree::findParent(string childData, node* subtree)
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

	stringBinarySearchTree::node* stringBinarySearchTree::getNode(string data, node* subtree)
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
}