#pragma once

/**
 * Вершина бинарного дерева.
 */
struct BinaryTreeNode 
{
	/**
	 * Значение.
	 */
	int Data;

	/**
	 * Указатель на левую вершину.
	 */
	BinaryTreeNode* Left = nullptr;

	/**
	 * Указатель на правую вершину.
	 */
	BinaryTreeNode* Right = nullptr;
};

