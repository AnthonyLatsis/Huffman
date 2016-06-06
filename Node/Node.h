//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

struct Node {
	const Optional_char symbol;

	const int priority;

	const Node * left;
	const Node * right;

/* Конструктор, создающий лист с соответствующими параметрами */

	Node(Optional_char symbol, int priority);

/* Конструктор, содающий узел с соотвествующими левым и правым узлами */

	Node(const Node * const left, const Node * const right);

/* Функция печати листов */

	static void printLeaf(const Node * const node);

/* Метод и смежная ему функция для печати в виде дерева, постфиксно */

	static void printTree(const Node * const node);

	void printTree(const std::string message) const; 
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
