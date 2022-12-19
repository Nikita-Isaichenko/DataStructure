#pragma once

/**
 * ������ ������ � �����.
 */
struct Stack 
{
	int* Buffer;
	int Top;
	int Capacity;
	const int GrowthFactor = 2;
};

/**
 * \brief �������������� ����.
 * \return ��������� �� ������������������ ����.
 */
Stack* InitStack(Stack* stack);

/**
 * ��������� �������� � ����� �����.
 */
void Push(Stack* stack, int data);

/**
 * ������� �������� �� ����� ����� � ������ ��� ������.
 */
int Pop(Stack* stack);

/**
 * \brief ����������� ��� ��������� ������ �����.
 */
void Resize(Stack* stack);

/**
 * \brief ��������� ����� �� ��������� ��� ��������� ������ �����.
 */
void CheckResize(Stack* stack);

/**
 * \brief ���������, �������� �� ���� ������.
 */
bool IsEmpty(Stack* stack);

/**
 * \brief ������� ����.
 */
void Delete(Stack* stack);




