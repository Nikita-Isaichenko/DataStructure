#pragma once

/**
 * Хранит данные о стеке.
 */
struct Stack 
{
	int* Buffer;
	int Top;
	int Capacity;
	const int GrowthFactor = 2;
};

/**
 * \brief Инициализирует стек.
 * \return Указатель на инициализированный стек.
 */
Stack* InitStack(int size);

/**
 * Добавляет значение в конец стека.
 */
void Push(Stack* stack, int data);

/**
 * Достает значение из конца стека и убирая его оттуда.
 */
int Pop(Stack* stack);

/**
 * \brief Увеличивает или уменьшает размер стека.
 */
void Resize(Stack* stack);

/**
 * \brief Проверяет нужно ли увеличить или уменьшить размер стека.
 */
void CheckResize(Stack* stack);

/**
 * \brief Проверяет, является ли стек пустым.
 */
bool IsEmptyStack(Stack* stack);

/**
 * \brief Удаляет стек.
 */
void Delete(Stack* stack);




