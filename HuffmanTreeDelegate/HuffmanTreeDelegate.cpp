
#include "HuffmanTreeDelegate.h"

const Node * const HuffmanTreeDelegate::tree(std::vector<char> inputString) {
	VectorExtension::printVector(inputString, "This is the input string: ");
	std::vector<const Node *> frequencies = leaves(inputString);
	return buildTree(frequencies);
}

std::vector<const Node *> HuffmanTreeDelegate::leaves(std::vector<char> inputString) {
	std::vector<const Node *> frequencies;

	const auto tblsize = ::hashTableSize(inputString); 
	CHashtable<int, Node *> frequenciesTable = CHashtable<int, Node *>(tblsize, &::mapper);

	for (int counter = 0; counter < inputString.size(); counter ++) {
		if (frequenciesTable.contains((int)inputString[counter])) {
			frequenciesTable[(int)inputString[counter]] -> priority ++;
			continue;
		} else {
			Node * node = new Node(Optional_char((int)inputString[counter]), 1);
			frequenciesTable.insert((int)inputString[counter], node);
		}
	}
	frequenciesTable.print(&Node::printLeaf);

	for (int counter = 0; counter < inputString.size(); counter ++) {
		if (frequenciesTable.contains((int)inputString[counter])) {
			const Node * node = new Node(Optional_char(inputString[counter]),
				frequenciesTable[(int)inputString[counter]] -> priority);
			frequencies.push_back(node);
			frequenciesTable.remove((int)inputString[counter]);
		}
	}
	sortFrequencies(frequencies);
	return frequencies;
}

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

void HuffmanTreeDelegate::sortFrequencies(std::vector<const Node *>& frequencies) {
	std::sort(frequencies.begin(), f
            requencies.end(), 
            &HuffmanTreeDelegate::compareNodesByPriority);
}

bool HuffmanTreeDelegate::compareNodesByPriority(const Node * const first, const Node * const second) {
	return (first->priority < second->priority);
}
