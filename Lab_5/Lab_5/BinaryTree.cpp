#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include <time.h>
#include <stdlib.h>

void AddRandomValues(BinaryTree* tree, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		AddElement(tree, rand() % 100);
	}
}

bool AddElement(BinaryTree* tree, int data)
{
	BinaryTreeNode* node = new BinaryTreeNode();
	node->Data = data;

	if (tree->Root == nullptr)
	{
		tree->Root = node;
		return true;
	}
	
	BinaryTreeNode* parentNode = FindParentNode(tree->Root, data);

	if (data >= parentNode->Data)
	{
		parentNode->Right = node;
	}
	else
	{
		parentNode->Left = node;
	}

	return true;
}

BinaryTreeNode* FindParentNode(BinaryTreeNode* node, int data)
{
	if ((node->Data <= data) && (node->Right == nullptr)
		|| (node->Data > data) && (node->Left == nullptr))
	{
		return node;
	}

	if (node->Data <= data)
	{
		FindParentNode(node->Right, data);
	}
	else
	{
		FindParentNode(node->Left, data);
	}
}

bool RemoveElement(BinaryTreeNode*& root, int data)
{
	if (root == nullptr)
	{
		return false;
	}

	BinaryTreeNode* parentNode = nullptr;
	BinaryTreeNode* foundNode = FindElement(root, data, parentNode);

	if (!foundNode) 
	{
		return false;
	}
	
	if (foundNode->Left == nullptr && foundNode->Right == nullptr)
	{
		if (!parentNode)
		{
			delete foundNode;
			root = nullptr;
			return true;
		}
		else if (parentNode->Data <= data)
		{
			parentNode->Right = nullptr;
		}
		else
		{
			parentNode->Left = nullptr;
		}

		delete foundNode;
		return true;
	}
	else if (foundNode->Left && foundNode->Right)
	{
		BinaryTreeNode* parentMinNode = nullptr;
		BinaryTreeNode* tempMinNode = FindMin(foundNode->Right, parentMinNode);
		foundNode->Data = tempMinNode->Data;
		RemoveElement(foundNode->Right, tempMinNode->Data);
		//delete parentMinNode;
		return true;
	}
	else if (foundNode->Right)
	{
		if (!parentNode)
		{
			BinaryTreeNode* temp = foundNode->Right;
			delete foundNode;
			root = nullptr;

			root = temp;

			return true;
		}

		if (parentNode->Data <= foundNode->Data)
		{
			parentNode->Right = foundNode->Right;
		}
		else
		{
			parentNode->Left = foundNode->Right;
		}
		

		delete foundNode;
		return true;
	}
	else if (foundNode->Left)
	{
		if (!parentNode)
		{
			BinaryTreeNode* temp = foundNode->Left;
			delete foundNode;
			root = nullptr;

			root = temp;

			return true;
		}

		if (parentNode->Data <= foundNode->Data)
		{
			parentNode->Right = foundNode->Left;
		}
		else
		{
			parentNode->Left = foundNode->Left;
		}
		

		delete foundNode;
		return true;
	}

	delete parentNode;
}

BinaryTreeNode* FindElement(BinaryTreeNode* node, int data, BinaryTreeNode*& parentNode)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Data == data)
	{
		
		return node;
	}

	if (node->Data > data)
	{
		parentNode = node;
		FindElement(node->Left, data, parentNode);
	}
	else
	{
		parentNode = node;
		FindElement(node->Right, data, parentNode);
	}
}

BinaryTreeNode* FindMin(BinaryTreeNode* node, BinaryTreeNode*& parentNode)
{
	if (!node)
	{
		return nullptr;
	}

	while (node->Left != nullptr)
	{
		parentNode = node;
		node = node->Left;
	}

	return node;
}

BinaryTreeNode* FindMax(BinaryTreeNode* node, BinaryTreeNode*& parentNode)
{
	if (!node)
	{
		return nullptr;
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

void DeleteBinaryTree(BinaryTreeNode* currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}

	DeleteBinaryTree(currentNode->Left);
	DeleteBinaryTree(currentNode->Right);
	delete currentNode;
}
