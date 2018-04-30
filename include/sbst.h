#ifndef SBST_H
#define SBST_H

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cctype>

namespace SDI
{
	using std::vector;
	using std::string;

	class stringBinarySearchTree
	{
	public:
		struct node
		{
			string data;
			node* leftChild;
			node* rightChild;
		};
		node* root;
		stringBinarySearchTree();
		~stringBinarySearchTree();
		node* newNode(string value);
		void insertNode(string value, node* location);
		bool isEmpty(node* child);
		void vecPostOrder(node* node, vector<string>& vector);
		void vecPreOrder(node* node, vector<string>& vector);
		void vecInOrder(node* node, vector<string>& vector);
		void deleteSubTree(node* head);
		void deleteNode(node* node);
		//Default subtree is root
		node* findParent(string childData, node* subtree = nullptr);
		bool isParent(node* parent, string childData);
		bool isNode(node* check, string data);
		node* getNode(string data, node* subtree = nullptr);
		node* getSmallestInSubTree(node* node);
	};
}
	

#endif