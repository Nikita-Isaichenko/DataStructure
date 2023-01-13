#include "Treap.h"
#include <time.h>
#include <stdlib.h>

void AddRandomValues(Treap* treap, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		AddOptimized(treap->Root, rand() % 100, rand() % treap->MaxPriority);
	}
}

void Split(TreapNode* node, int data, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
		left = right = nullptr;
	else
	{
		if (node->Data > data)
		{
			Split(node->Left, data, left, node->Left);
			right = node;
		}
		else
		{
			Split(node->Right, data, node->Right, right);
			left = node;
		}
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}

	right->Left = Merge(left, right->Left);
	return right;
}

void AddNotOptimized(TreapNode*& root, int data, int priority)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(root, data, left, right);
	TreapNode* newNode = new TreapNode;
	newNode->Data = data;
	newNode->Priority = priority;
	root = Merge(Merge(left, newNode), right);
}

void AddOptimized(TreapNode*& root, int data, int priority)
{
	TreapNode* current = root;

	if (current != nullptr)
	{
		/*while ((current->Left != nullptr || current->Right != nullptr) 
			&& current->Priority > priority)
		{
			if (current->Data > data)
			{
				if (current->Left == nullptr) break;

				current = current->Left;
			}
			else
			{
				if (current->Right == nullptr) break;

				current = current->Right;
			}
		}*/
		while (current->Priority > priority)
		{
			if (current->Data > data)
			{
				if (current->Left == nullptr) break;

				if (current->Left->Priority < priority) break;

				current = current->Left;
			}
			else
			{
				if (current->Right == nullptr) break;

				if (current->Right->Priority < priority) break;

				current = current->Right;
			}
		}
	}
	

	TreapNode* newNode = new TreapNode;
	newNode->Data = data;
	newNode->Priority = priority;

	if (root == nullptr || root->Priority < newNode->Priority)
	{
		Split(current, data, newNode->Left, newNode->Right);
		root = newNode;
	}
	else if (current->Data > newNode->Data)
	{
		Split(current->Left, data, newNode->Left, newNode->Right);
		current->Left = newNode;
	}
	else
	{
		Split(current->Right, data, newNode->Left, newNode->Right);
		current->Right = newNode;
	}
}

TreapNode* RemoveNotOptimized(TreapNode*& root, int data)
{
	TreapNode* left;
	TreapNode* right;
	TreapNode* deleteNode;
	Split(root, data - 1, left, right);
	Split(right, data, deleteNode, right);
	delete deleteNode;
	root = Merge(left, right);
	//TODO: неявное зло(done)
	return deleteNode;
}

bool RemoveOptimized(TreapNode*& root, int data)
{
	if (root == nullptr)
	{
		return false;
	}

	TreapNode* current = root;
	while (current != nullptr && current->Data != data)
	{
		if (current->Data > data)
		{
			if (current->Left == nullptr ||
				current->Left->Data == data) break;

			current = current->Left;
		}
		else
		{
			if (current->Right == nullptr ||
				current->Right->Data == data) break;

			current = current->Right;
		}
	}

	TreapNode* deleteNode;

	if (current == root && current->Data == data)
	{
		deleteNode = current;
		root = Merge(deleteNode->Left, deleteNode->Right);
	}
	else if (current->Data > data)
	{
		if (current->Left == nullptr)
		{
			return false;
		}
		deleteNode = current->Left;
		current->Left = Merge(deleteNode->Left, deleteNode->Right);		
	}
	else
	{
		if (current->Right == nullptr)
		{
			return false;
		}
		deleteNode = current->Right;
		current->Right = Merge(deleteNode->Left, deleteNode->Right);
	}
	delete deleteNode;
	return true;
}

void DeleteTreap(TreapNode*& node)
{
	if (node->Left)
	{
		DeleteTreap(node->Left);
	}
	if (node->Right)
	{
		DeleteTreap(node->Right);
	}
	delete node;
}

TreapNode* FindElement(TreapNode* node, int data)
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
		FindElement(node->Left, data);
	}
	else
	{
		FindElement(node->Right, data);
	}
}