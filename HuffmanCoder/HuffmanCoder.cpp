//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "HuffmanCoder.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

const std::vector<bool> HuffmanCoder::encodedMessage(std::vector<char> inputString,
																										 bool registerSensitive) {
	if (registerSensitive) {
		ignoreRegister(inputString);
	}
	const auto *const tree = new HuffmanTree(inputString);
	tree->image("\nThe same tree, visualized");
  const auto *const codes = tree -> findSymbolCodes(inputString);

	auto treeCode = encodedTree(tree);
  auto stringCode = encodedString(inputString, codes);

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

const std::vector<bool> HuffmanCoder::encodedString(const std::vector<char> inputString,
 																										const CHashtable<int,
 																										const SymbolCode * const> * const codes) {
	std::vector<bool> stringCode;
	for (int count = 0; count < inputString.size(); count ++) {
		stringCode.insert(stringCode.end(), (* codes)[(int)inputString[count]]->code.begin(),
			(* codes)[(int)inputString[count]]->code.end());
	}
	VectorExtension::printVector(stringCode, "This is the encoded string:\n\n");
	std::cout << "\nThese are the symbol codes:\n\n";
	codes -> print(&SymbolCode::print);
	std::cout << "\n<><><><><><><><><><><><><>\n";
	return stringCode;
}

const std::vector<bool> HuffmanCoder::encodedTree(const HuffmanTree * const tree) {
	const auto treeCode = tree->encode();
	VectorExtension::printVector(treeCode, "This is the encoded tree:\n\n");
	return treeCode;
}

void HuffmanCoder::ignoreRegister(std::vector<char>& inputString) {
	for (auto elt: inputString) {
		if (elt >= 65 && elt <= 90) {
			elt = (char)((int)elt + 32);
		}
	}
}
