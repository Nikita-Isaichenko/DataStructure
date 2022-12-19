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
 * \brief Добавляет значение в стек.
 */
void PushStack(Stack* stack);

/**
 * \brief Достает значение из стека.
 */
void PopStack(Stack* stack);

/**
 * \brief Выводит стек.
 */
void PrintStack(Stack* stack);

/**
 * \brief Создает стек.
 */
Stack* CreateStack(Stack* stack);

/**
 * \brief Проверяет, создан ли стек.
 */
bool IsCreated(Stack* stack);

/**
 * \brief Удаляет стек.
 */
void DeleteStack(Stack* stack);




