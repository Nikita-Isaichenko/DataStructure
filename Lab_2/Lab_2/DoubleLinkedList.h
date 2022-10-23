
struct Node
{
	int Value;
	Node* Next;
	Node* Previos;
};

struct List
{
	int Length;
	Node* Head;
	Node* Tail;
};

void InitList(List* list);
void Add(List* list, int value);
void Show(List* list);
void Remove(List* list, int index);

