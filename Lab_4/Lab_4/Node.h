#pragma once
#include <string>
/**
 * Узел.
 */
struct Node 
{
	/**
	 * Указатель на следующий узел.
	 */
	Node* Next = nullptr;

	/**
	 * Значение.
	 */
	std::string Value;

	/**
	 * Ключ.
	 */
	std::string Key;
};