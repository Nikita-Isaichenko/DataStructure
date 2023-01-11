#pragma once
#include "BinaryTreeNode.h"
#include <cstddef>

/**
 * ��������� ��������� ������.
 */
struct BinaryTree
{
	/**
	 * ������ ��������� ������.
	 */
	BinaryTreeNode* Root = nullptr;
};

/**
 * ������� ������ � ���������� ����������.
 */
void AddRandomValues(BinaryTree* tree, int count);

/**
 * ��������� �������.
 */
bool AddElement(BinaryTree* tree, int data);

/**
 * ����� ������������� ����, � ������� ����� �������� �������� ����.
 */
BinaryTreeNode* FindParentNode(BinaryTreeNode* node, int data);

/**
 * ������� �������.
 */
bool RemoveElement(BinaryTreeNode*& root, int data);

/**
 * ���������� ��������.
 */
extern BinaryTreeNode* tempTreeNode;

/**
 * ������ ��������.
 */
BinaryTreeNode* FindElement(BinaryTreeNode* node, int data, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * ������� ����������� ��������.
 */
BinaryTreeNode* FindMin(BinaryTreeNode* node, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * ������� ������������ ��������.
 */
BinaryTreeNode* FindMax(BinaryTreeNode* node, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * ������� ������.
 */
void DeleteTree(BinaryTree* tree)




