#pragma once
#include "TreapNode.h"

/**
 * Структура декартового дерева.
 */
struct Treap
{
	/**
	 * Максимальный приориет.
	 */
	const int MaxPriority = 100;

	/**
	 * Корень дерева.
	 */
	TreapNode* Root = nullptr;
};

/**
 * Разделяет дерево по ключу.
 */
void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right);

/**
 * Соединяет два дерева.
 */
TreapNode* Merge(TreapNode* left, TreapNode* right);

/**
 * Оптимизированное добавление.
 */
void AddOptimized(TreapNode*& root, int data, int priority);

/**
 * Не оптимизированное добавление.
 */
void AddNotOptimized(TreapNode*& root, int data, int priority);

/**
 * Не оптимизированное удаление.
 */
TreapNode* RemoveNotOptimized(TreapNode*& root, int data);

/**
 * Оптимизированное удаление.
 */
bool RemoveOptimized(TreapNode*& root, int data);

/**
 * Удаляет дерево.
 */
void DeleteTreap(TreapNode*& node);

/**
 * Поиск элемента.
 */
TreapNode* FindElement(TreapNode* node, int data);

/**
 * Добавляет рандомные значения.
 */
void AddRandomValues(Treap* treap, int count);




