//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "HuffmanCoder.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

const std::vector<bool> HuffmanCoder::encodedMessage(std::vector<char> inputString, bool registerSensitive) {

	if (registerSensitive) {
		ignoreRegister(inputString);
	}

	const HuffmanTree * const tree = new HuffmanTree(inputString);

	tree -> image("\nThe same tree, visualized");

    const CHashtable<int, const SymbolCode * const> * const codes = tree -> findSymbolCodes(inputString);

	std::vector<bool> treeCode         = encodedTree(tree);
    const std::vector<bool> stringCode = encodedString(inputString, codes);

	treeCode.insert(treeCode.end(), stringCode.begin(), stringCode.end());

	std::cout << "\nInput string length: " << inputString.size() * 8 << "\n";
	std::cout << "Encoded string length:" << treeCode.size() << "\n\n";
	std::cout << "Compression coefficient: ";
	printf("%f\n\n", ((float)(inputString.size() * 8) / (float)treeCode.size()));
	std::cout << "<><><><><><><><><><><><><>\n";

	delete tree;
	delete codes;
	return treeCode;
}

//____________________________________________________

const std::vector<bool> HuffmanCoder::encodedString(const std::vector<char> inputString, const CHashtable<int, const SymbolCode * const> * const codes) {
	std::vector<bool> stringCode;
	for (int count = 0; count < inputString.size(); count ++) {
		stringCode.insert(stringCode.end(), (* codes)[(int)inputString[count]] -> code.begin(),
			(* codes)[(int)inputString[count]] -> code.end());
	}
	VectorExtension::printVector(stringCode, "This is the encoded string:\n\n");
	std::cout << "\nThese are the symbol codes:\n\n";
	codes -> print(&SymbolCode::print);
	std::cout << "\n<><><><><><><><><><><><><>\n";
	return stringCode;
}

//____________________________________________________

const std::vector<bool> HuffmanCoder::encodedTree(const HuffmanTree * const tree) {
	const std::vector<bool> treeCode = tree -> encode();
	VectorExtension::printVector(treeCode, "This is the encoded tree:\n\n");
	return treeCode;
}

//____________________________________________________

void HuffmanCoder::ignoreRegister(std::vector<char>& inputString) {
	for (int counter = 0; counter < inputString.size(); counter ++) {
		if (inputString[counter] >= 65 && inputString[counter] <= 90) {
			inputString[counter] = (char)((int)inputString[counter] + 32);
		}
	}
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
