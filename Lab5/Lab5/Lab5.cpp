// Lab5.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include "intBinaryTree.h"

int main()
{
	intBinaryTree x;
	x.insertNode(23, x.root);
	x.insertNode(3, x.root);
	x.insertNode(1, x.root);
	x.insertNode(15, x.root);
	x.insertNode(50, x.root);
	x.insertNode(28, x.root);
	x.insertNode(221, x.root);
	x.deleteNode(x.getNode(221));
	x.printPreOrder(x.root);
	std::cout << " " << std::endl;
	x.printInOrder(x.root);
	std::cout << " " << std::endl;
	x.printPostOrder(x.root);
	std::cout << " " << std::endl;
	std::cout << x.findParent(1)->data << std::endl;
	std::cout << x.getSmallestInSubTree(x.getNode(1)) << std::endl;
	x.~intBinaryTree();
    return 0;
}