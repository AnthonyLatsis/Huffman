//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "HuffmanTreeDelegate.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

const Node * const HuffmanTreeDelegate::tree(std::vector<char> inputString) {
	VectorExtension::printVector(inputString, "Это исходная строка : ");
	std::vector<const Node *> frequencies = leaves(inputString);
	return buildTree(frequencies);
}

//____________________________________________________

//сделать  с хештаблицей
std::vector<const Node *> HuffmanTreeDelegate::leaves(std::vector<char> inputString) {
	std::vector<const Node *> frequencies;

	auto repeat = 0;

	std::vector<char>::const_iterator timer;
	std::vector<char>::iterator counter;
	std::vector<char>::iterator pointer;

	for (counter = inputString.begin(); counter != inputString.end(); ++counter) {
		pointer = std::find(inputString.begin(), counter, *counter);
		if (pointer != counter && counter != inputString.begin()) {
			continue;
		}
		for (timer = inputString.begin(); timer != inputString.end(); ++timer) {
			if (*timer == *counter) {
				repeat ++;
			}
		}
		const Node * node = new Node(Optional_char(*counter), repeat);
		frequencies.push_back(node);
		repeat = 0;
	}
	sortFrequencies(frequencies);
	VectorExtension::printVector(frequencies, "Это таблица частотности символов для исходной строки :\n\n", &Node::printLeaf);
	return frequencies;
}

//____________________________________________________

const Node * const HuffmanTreeDelegate::buildTree(std::vector<const Node *> frequencies) {
	if (frequencies.size() == 1) {
		return *(frequencies.begin());
	}
	std::vector<const Node *>::const_iterator counter = frequencies.begin();

	const Node * const left  = *(counter ++);
	const Node * const right = *(counter);

	const Node * const newNode = new Node(left, right);	

	frequencies.erase(frequencies.begin());
	frequencies.erase(frequencies.begin());
	frequencies.push_back(newNode);

	sortFrequencies(frequencies);

	return buildTree(frequencies);
}
//____________________________________________________

void HuffmanTreeDelegate::sortFrequencies(std::vector<const Node *>& frequencies) {
	std::sort(frequencies.begin(), frequencies.end(), &HuffmanTreeDelegate::compareNodesByPriority);
}

//____________________________________________________

bool HuffmanTreeDelegate::compareNodesByPriority(const Node * const first, const Node * const second) {
	return (first -> priority < second -> priority);
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
