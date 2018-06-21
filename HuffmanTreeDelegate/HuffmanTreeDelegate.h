class HuffmanTreeDelegate {

public:
	static const Node * const tree(std::vector<char> inputString);

	static std::vector<const Node *> leaves(std::vector<char> inputString);

	static const Node * const buildTree(std::vector<const Node *> frequencies);

	static void sortFrequencies(std::vector<const Node *>& frequencies);

	static bool compareNodesByPriority(const Node * const first, const Node * const second);
};
