#include "BinaryTree.h"
#include "Validation.h"
#include <iostream>

using namespace std;


void PrintTree(BinaryTreeNode* currentNode, int level)
{
	if (currentNode)
	{
		PrintTree(currentNode->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << currentNode->Data << endl;
		PrintTree(currentNode->Left, level + 1);
	}
}


int main()
{
    setlocale(LC_ALL, "ru");

	BinaryTree* tree = new BinaryTree();

	while (true)
	{
		cout << "1. Заполнить рандомными значениями." << endl;
		cout << "2. Добавить." << endl;
		cout << "3. Удалить." << endl;
		cout << "4. Поиск." << endl;
		cout << "5. Поиск максимального." << endl;
		cout << "6. Поиск минимального." << endl;
		cout << "7. Назад." << endl;

		int number = CheckingForDigit("Выберите действие: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (number)
		{
			case 1:
			{
				int count = CheckingForDigit("Введите кол-во добавляемых элементов: ");

				AddRandomValues(tree, count);
				PrintTree(tree->Root, 0);
				break;
			}
			case 2:
			{
				int data = CheckingForDigit("Введите добавляемое значение: ");

				AddElement(tree, data);
				cout << "------------------------------------------" << endl;
				PrintTree(tree->Root, 0);
				break;
			}
			case 3:
			{
				if (!tree->Root)
				{
					cout << "Дерево пустое." << endl;
				
					break;
				}

				int data = CheckingForDigit("Введите удаляемое значение: ");

				if (RemoveElement(tree->Root, data))
				{
					cout << "Элемент успешно удален" << endl;
				}
				else
				{
					cout << "Ошибка удаления" << endl;
				}

				cout << "------------------------------------------" << endl;
				PrintTree(tree->Root, 0);
			
			
				break;
			}
			case 4:
			{
				if (!tree->Root)
				{
					cout << "Дерево пустое." << endl;
					return 0;
				}

				int data = CheckingForDigit("Введите искомое значение: ");

				if (FindElement(tree->Root, data))
				{
					cout << "Элемент найден." << endl;
				}
				else
				{
					cout << "Элемент не найден" << endl;
				}

				break;
			}
			case 5:
			{
				if (!tree->Root)
				{
					cout << "Дерево пустое." << endl;
					return 0;
				}

				cout << "Минимальное значение: " << FindMin(tree->Root)->Data << endl;
				break;
			}
			case 6:
			{
				if (!tree->Root)
				{
					cout << "Дерево пустое." << endl;
					return 0;
				}

				cout << "Максимальное значение: " << FindMax(tree->Root)->Data << endl;
				break;
			}
			case 7:
			{
				if (tree != nullptr)
				{
					DeleteBinaryTree(tree->Root);
					delete tree;
					delete tempTreeNode;
				}
				return 0;
			}
			default:
			{
				cout << "Неверный номер задание." << endl;
				break;
			}
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}
