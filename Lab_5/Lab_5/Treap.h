#pragma once
#include "TreapNode.h"

/**
 * ��������� ����������� ������.
 */
struct Treap
{
	/**
	 * ������������ ��������.
	 */
	const int MaxPriority = 100;

	/**
	 * ������ ������.
	 */
	TreapNode* Root = nullptr;
};

/**
 * ��������� ������ �� �����.
 */
void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right);

/**
 * ��������� ��� ������.
 */
TreapNode* Merge(TreapNode* left, TreapNode* right);

/**
 * ���������������� ����������.
 */
void AddOptimized(TreapNode*& root, int data, int priority);

/**
 * �� ���������������� ����������.
 */
void AddNotOptimized(TreapNode*& root, int data, int priority);

/**
 * �� ���������������� ��������.
 */
TreapNode* RemoveNotOptimized(TreapNode*& root, int data);

/**
 * ���������������� ��������.
 */
bool RemoveOptimized(TreapNode*& root, int data);

/**
 * ������� ������.
 */
void DeleteTreap(TreapNode*& node);

/**
 * ����� ��������.
 */
TreapNode* FindElement(TreapNode* node, int data);

/**
 * ��������� ��������� ��������.
 */
void AddRandomValues(Treap* treap, int count);




