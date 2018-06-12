#include "Node.h"


Node::Node(Optional_char symbol, int priority): 
	symbol(symbol), priority(priority), left(nullptr), right(nullptr) {}

Node::Node(const Node * const left, const Node * const right): 
	priority(left->priority + right->priority), symbol(Optional_char()) {
	this->left  = left;
	this->right = right; 
}

void Node::printLeaf(Node * node) {
	if (node == nullptr) return; 
	std::cout << "'";
	node->symbol.print();
	std::cout << "' : " << node->priority << "\n";
}

void Node::printTree(const Node * const node) {
	if (node == nullptr) return; 
	std::cout << "[";
	node->symbol.print();
	
	printTree(node -> left);
	printTree(node -> right);

	std::cout << "]";
}

void Node::printTree(const std::string message) const {
	std::cout << "\n" << message;
	printTree(this);
	std::cout << "\n\n<><><><><><><><><><><><><>\n";
}
