#pragma once
#include <string>
/**
 * ����.
 */
struct Node 
{
	/**
	 * ��������� �� ��������� ����.
	 */
	Node* Next = nullptr;

	/**
	 * ��������.
	 */
	std::string Value;

	/**
	 * ����.
	 */
	std::string Key;
};