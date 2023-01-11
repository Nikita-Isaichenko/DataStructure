#pragma once
#include "BinaryTreeNode.h"
#include <cstddef>

/**
 * Структура бинарного дерева.
 */
struct BinaryTree
{
	/**
	 * Корень бинарного дерева.
	 */
	BinaryTreeNode* Root = nullptr;
};

/**
 * Создает дерево с рандомными элементами.
 */
void AddRandomValues(BinaryTree* tree, int count);

/**
 * Добавляет элемент.
 */
bool AddElement(BinaryTree* tree, int data);

/**
 * Поиск родительского узла, в который можно добавить дочерний узел.
 */
BinaryTreeNode* FindParentNode(BinaryTreeNode* node, int data);

/**
 * Удаляет элемент.
 */
bool RemoveElement(BinaryTreeNode*& root, int data);

/**
 * Переменная заглушка.
 */
extern BinaryTreeNode* tempTreeNode;

/**
 * Поиска элемента.
 */
BinaryTreeNode* FindElement(BinaryTreeNode* node, int data, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * Находит минимальное значение.
 */
BinaryTreeNode* FindMin(BinaryTreeNode* node, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * Находит максимальное значение.
 */
BinaryTreeNode* FindMax(BinaryTreeNode* node, BinaryTreeNode*& parentNode = tempTreeNode);

/**
 * Удаляет дерево.
 */
void DeleteTree(BinaryTree* tree)




