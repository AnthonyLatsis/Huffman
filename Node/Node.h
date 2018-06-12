
struct Node {
	const Optional_char symbol;

	int priority;

	const Node * left;
	const Node * right;

	Node(Optional_char symbol, int priority);

	Node(const Node * const left, const Node * const right);

	static void printLeaf(Node * node);

	static void printTree(const Node * const node);

	void printTree(const std::string message) const; 
};
