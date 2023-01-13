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
 * ������ ��������.
 */
BinaryTreeNode* FindElement(BinaryTreeNode* node, int data, BinaryTreeNode*& parentNode);

/**
 * ������� ����������� ��������.
 */
BinaryTreeNode* FindMin(BinaryTreeNode* node, BinaryTreeNode*& parentNode);

/**
 * ������� ������������ ��������.
 */
BinaryTreeNode* FindMax(BinaryTreeNode* node, BinaryTreeNode*& parentNode);

/**
 * ������� ������.
 */
void DeleteBinaryTree(BinaryTreeNode* currentNode);




