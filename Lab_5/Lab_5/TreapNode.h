#pragma once

/**
 * Структура узла декартового дерева.
 */
struct TreapNode
{
	/**
	 * Значение.
	 */
	int Data;

	/**
	 * Приоритет.
	 */
	int Priority;

	/**
	 * Указатель на левый элемент.
	 */
	TreapNode* Left = nullptr;

	/**
	 * Указатель на правый элемент.
	 */
	TreapNode* Right = nullptr;

};



