
struct Node
{
	int Value;
	Node* Next = nullptr;
	Node* Previos = nullptr;
};

struct List
{
	Node* Head = nullptr;
	Node* Tail = nullptr;
};

void Add(List* list, int value);
void Show(List* list);


