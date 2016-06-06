//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "HuffmanTree.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

HuffmanTree::HuffmanTree(const std::vector<char> inputString, HuffmanTreeOrientation orientation):
	root(buildDelegate.tree(inputString)) {
	this -> orientation = orientation;
	root -> printTree("Это дерево Хаффмана. Синопсис: [узел[левая ветка][правая ветка]]\n\n");
}

//____________________________________________________

HuffmanTree::HuffmanTree(const std::vector<bool> encodedTree): root(nullptr) {

}

//____________________________________________________

HuffmanTree::~HuffmanTree() {
	deleteTree(root);
}

//____________________________________________________

void HuffmanTree::deleteTree(const Node * const node) {
	if (node -> left != nullptr) {
		deleteTree(node -> left);
	}
	if (node -> right != nullptr) {
		deleteTree(node -> right);
	}
	delete node;
}

//____________________________________________________

const CHashtable<int, const SymbolCode * const> * HuffmanTree::findSymbolCodes(const std::vector<char> inputString) const {
	const auto tblsize = ::hashTableSize(inputString);
	CHashtable<int, const SymbolCode * const> * codes = new CHashtable<int, const SymbolCode * const>(tblsize, &::mapper);
	std::vector<bool> code;
	findSymbolCodes(root, code, * codes);
	return codes;
}

//____________________________________________________

const std::vector<bool> HuffmanTree::encode() const {
	std::vector<bool> code;
	encode(root, code);
	return code;
}

//____________________________________________________

void HuffmanTree::image(const char * message) const {
	std::cout << message << "\n\n";
	imageDelegate.treeImage(root);
	std::cout << "<><><><><><><><><><><><><>\n";
}

//____________________________________________________

void HuffmanTree::findSymbolCodes(const Node * const node, std::vector<bool>& code, CHashtable<int, const SymbolCode * const>& codes) {
	if (node -> left != nullptr) {
		code.push_back(false);
		findSymbolCodes(node -> left, code, codes);
	}
	if (node -> right != nullptr) {
		code.push_back(true);
		findSymbolCodes(node -> right, code, codes);
	}
	if (node -> left == nullptr && node -> right == nullptr) {
		codes.insert((int)!(node -> symbol), new const SymbolCode(!(node -> symbol), code));
	}
	code.erase(code.end());
}

//____________________________________________________

void HuffmanTree::encode(const Node * const node, std::vector<bool>& code) {
	if (node -> left != nullptr) {
		encode(node -> left, code);
	}
	if (node -> right != nullptr) {
		encode(node -> right, code);
	}
	if (node -> left == nullptr && node -> right == nullptr) {
		code.push_back(true);
		std::vector<bool> symbol = encodeLeaf(node);
		code.insert(code.end(), symbol.begin(), symbol.end());
	}
	code.push_back(false);

}

//____________________________________________________

const std::vector<bool> HuffmanTree::encodeLeaf(const Node * const node) {
	std::vector<bool> code;
	int symbol = !(node -> symbol);	
	while (symbol != 0) {
		code.push_back(symbol % 2 == 1);
		symbol = symbol / 2;
	}
	while (code.size() < 8) {
		code.push_back(false);
	}
	std::reverse(code.begin(), code.end());
	return code;
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
