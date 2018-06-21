
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(const std::vector<char> inputString,
								 				 HuffmanTreeOrientation orientation):
	root(buildDelegate.tree(inputString)), orientation(orientation) {
	root->printTree("This is the Huffman tree. Synopsis: [node[left branch][right branch]]\n\n");
}

HuffmanTree::HuffmanTree(const std::vector<bool> encodedTree): root(nullptr) {}

HuffmanTree::~HuffmanTree() {
	deleteTree(root);
}

void HuffmanTree::deleteTree(const Node *const node) {
	if (node->left)
		deleteTree(node -> left);
	if (node->right)
		deleteTree(node -> right);
	delete node;
}

const CHashtable<int, const SymbolCode * const> * HuffmanTree::findSymbolCodes(const std::vector<char> inputString) const {
	const auto tblsize = ::hashTableSize(inputString);
	auto codes = new CHashtable<int, const SymbolCode * const>(tblsize, &::mapper);
	std::vector<bool> code;
	findSymbolCodes(root, code, *codes);
	return codes;
}

const std::vector<bool> HuffmanTree::encode() const {
	std::vector<bool> code;
	encode(root, code);
	return code;
}

void HuffmanTree::image(const char * message) const {
	std::cout << message << "\n\n";
	imageDelegate.treeImage(root);
	std::cout << "<><><><><><><><><><><><><>\n";
}

void HuffmanTree::findSymbolCodes(const Node * const node,
																  std::vector<bool>& code,
																  CHashtable<int, const SymbolCode * const>& codes) {
	if (node->left) {
		code.push_back(false);
		findSymbolCodes(node->left, code, codes);
	}
	if (node->right) {
		code.push_back(true);
		findSymbolCodes(node->right, code, codes);
	}
	if (!(node->left || node->right))
		codes.insert((int)!(node->symbol), new const SymbolCode(!(node->symbol), code));
	code.erase(code.end());
}

void HuffmanTree::encode(const Node * const node, std::vector<bool>& code) {
	if (node->left)
		encode(node->left, code);
	if (node->right)
		encode(node->right, code);

	if (!(node->left || node->right)) {
		code.push_back(true);
		auto symbol = encodeLeaf(node);
		code.insert(code.end(), symbol.begin(), symbol.end());
	}
	code.push_back(false);
}

const std::vector<bool> HuffmanTree::encodeLeaf(const Node * const node) {
	std::vector<bool> code;
	int symbol = !(node->symbol);	
	while (symbol != 0) {
		code.push_back(symbol % 2 == 1);
		symbol = symbol / 2;
	}
	while (code.size() < 8)
		code.push_back(false);
	std::reverse(code.begin(), code.end());
	return code;
}
