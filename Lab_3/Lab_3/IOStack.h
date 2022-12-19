#pragma once
#include "Stack.h"

/*****************************************************************//**
 * \file   IOStack.h
 * \brief  
 * 
 * \author nikit
 * \date   December 2022
 *********************************************************************/

/**
 * \brief ��������� �������� � ����.
 */
void PushStack(Stack* stack);

/**
 * \brief ������� �������� �� �����.
 */
void PopStack(Stack* stack);

/**
 * \brief ������� ����.
 */
void PrintStack(Stack* stack);

/**
 * \brief ������� ����.
 */
Stack* CreateStack(Stack* stack);

/**
 * \brief ���������, ������ �� ����.
 */
bool IsCreated(Stack* stack);

/**
 * \brief ������� ����.
 */
void DeleteStack(Stack* stack);




