//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "HuffmanCoder.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

const std::vector<bool> HuffmanCoder::encodedMessage(const std::vector<char> inputString) {
	const HuffmanTree * const tree = new HuffmanTree(inputString);

	tree -> image("\nОно же, теперь наглядно");

    const CHashtable<int, const SymbolCode * const> * const codes = tree -> findSymbolCodes(inputString);

	std::vector<bool> treeCode         = encodedTree(tree);
	const std::vector<bool> stringCode = encodedString(inputString, codes);

	treeCode.insert(treeCode.end(), stringCode.begin(), stringCode.end());

	std::cout << "\nДлина исходной строки: " << inputString.size() * 8 << "\n";
	std::cout << "Длина закодированной строки:" << treeCode.size() << "\n\n";
	std::cout << "Коэффициент сжатия: ";
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
	VectorExtension::printVector(stringCode, "Это закодированная строка\n\n");
	std::cout << "\nЭто коды символов\n\n";
	codes -> print(&SymbolCode::print);
	std::cout << "\n<><><><><><><><><><><><><>\n";
	return stringCode;
}

//____________________________________________________

const std::vector<bool> HuffmanCoder::encodedTree(const HuffmanTree * const tree) {
	const std::vector<bool> treeCode = tree -> encode();
	VectorExtension::printVector(treeCode, "Это закодированное дерево\n\n");
	return treeCode;
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
