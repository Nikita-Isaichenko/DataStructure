#include "BinaryTree.h"
#include "Validation.h"
#include <iostream>
#include "Treap.h"

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

void MenuBinaryTree()
{
	cout << "Бинарное дерево." << endl;

	BinaryTree* tree = new BinaryTree();

	while (true)
	{
		cout << "1. Заполнить рандомными значениями." << endl;
		cout << "2. Добавить." << endl;
		cout << "3. Удалить." << endl;
		cout << "4. Поиск." << endl;
		cout << "5. Поиск минимального." << endl;
		cout << "6. Поиск максимального." << endl;
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
				break;
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
				break;
			}

			cout << "Минимальное значение: " << FindMin(tree->Root)->Data << endl;
			break;
		}
		case 6:
		{
			if (!tree->Root)
			{
				cout << "Дерево пустое." << endl;
				break;
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
				//delete tempTreeNode;
			}
			return;
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

void PrintTreap(TreapNode* node, int level)
{
	if (node)
	{
		PrintTreap(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "	";
		}
		cout << '(' << node->Data << "; " << node->Priority << ')' << endl;
		PrintTreap(node->Left, level + 1);
	}
}

void MenuTreap()
{
	cout << "Декартово дерево." << endl;
	Treap* treap = new Treap;

	while (true)
	{
		cout << "1. Инициализировать декартово дерево рандомными значениями" << endl;
		cout << "2. Добавить элемент оптимизированным алгоритмом" << endl;
		cout << "3. Добавить элемент НЕ оптимизированным алгоритмом" << endl;
		cout << "4. Удалить элемент из дерева оптимизированным алгоритмом" << endl;
		cout << "5. Удалить элемент из дерева НЕ оптимизированным алгоритмом" << endl;
		cout << "6. Поиск" << endl;
		cout << "7. Выйти в главное меню" << endl;

		int number = CheckingForDigit("Выберите действие: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (number)
		{
		case 1:
		{
			int count = CheckingForDigit("Введите кол-во элементов: ");
			AddRandomValues(treap, count);
			PrintTreap(treap->Root, 0);

			break;
		}
		case 2:
		{
			int data = CheckingForDigit("Введите добавляемое значение: ");

			AddOptimized(treap->Root, data, rand() % treap->MaxPriority);
			PrintTreap(treap->Root, 0);
			break;
		}
		case 3:
		{
			int data = CheckingForDigit("Введите добавляемое значение: ");

			AddNotOptimized(treap->Root, data, rand() % treap->MaxPriority);
			PrintTreap(treap->Root, 0);
			break;
		}
		case 4:
		{
			int data = CheckingForDigit("Введите удаляемое значение: ");

			if (RemoveOptimized(treap->Root, data))
			{
				cout << "Успешно удалено" << endl;
			}
			else
			{
				cout << "Ошибка удаления" << endl;
			}

			PrintTreap(treap->Root, 0);
			break;
		}
		case 5:
		{
			int data = CheckingForDigit("Введите удаляемое значение: ");

			if (RemoveNotOptimized(treap->Root, data))
			{
				cout << "Успешно удалено" << endl;
			}
			else
			{
				cout << "Ошибка удаления" << endl;
			}
			
			PrintTreap(treap->Root, 0);
			break;
		}
		case 6:
		{
			int data = CheckingForDigit("Введите искомое значение: ");

			if (FindElement(treap->Root, data))
			{
				cout << "Элемент найден" << endl;
			}
			else
			{
				cout << "Элемент не найден" << endl;
			}

			break;
		}
		case 7:
		{
			DeleteTreap(treap->Root);
			delete treap;
			return;
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


int main()
{
    setlocale(LC_ALL, "ru");

	while (true)
	{
		cout << "Выберите с чем работать:" << endl;
		cout << "1. Бинарное дерево." << endl;
		cout << "2. Декартово дерево." << endl;
		cout << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		switch (key)
		{
		case 1:
			system("cls");
			MenuBinaryTree();
			break;
		case 2:
			system("cls");
			MenuTreap();
			break;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}
	}
	
}
