#include <iostream>
#include <cmath>
#include <string>
#include <vector> 
#include <fstream>

size_t mapper(int key) {
	return std::abs(key);
}

size_t hashTableSize(std::vector<char> str) {
	auto tblsize = 0;
	for (int count = 0; count < str.size(); count ++) {
		if (str[count] > tblsize) {
			tblsize = str[count];
		}
	}
	return tblsize;	
}

#include "CList/CList.cpp"
#include "CStack/CStack.cpp"
#include "CHashTable/CHashTable.cpp"
#include "VectorExtension/VectorExtension.cpp"
#include "Optional_char/Optional_char.cpp"
#include "Node/Node.cpp"
#include "Picture/Picture.cpp"
#include "TreeImageDelegate/TreeImageDelegate.cpp"
#include "HuffmanTreeDelegate/HuffmanTreeDelegate.cpp"
#include "SymbolCode/SymbolCode.cpp"
#include "HuffmanTree/HuffmanTree.cpp"
#include "HuffmanCoder/HuffmanCoder.cpp"

int main() {

/*============== Из файла ================
	           |
              \|/
*/
	std::vector<char> input;
	std::ifstream file;
	file.open ("text.txt");
    char ch;
	while (file >> std::noskipws >> ch) {
    	input.push_back(ch);
	}
	file.close();

/*============ Самому вбивать ============
	           |
              \|/
*/

	/*char character;
	for (int counter = 0; counter >= 0; counter ++){
		scanf("%c", &character);
		if (character == '\n') break;
		else input.push_back(character);
	}*/

/*========== Оставить, это нужно ==========
			   |
              \|/
*/
	std::vector<char> inputString;

	for (int counter = 0; counter < input.size(); counter ++) {
		if ((int)input[counter] >= 0) {
			inputString.push_back(input[counter]);
		}
	}
	input.clear();


	std::vector<bool> code;
	code = HuffmanCoder::encodedMessage(inputString, false); // в code как раз будет лежать закодированный текст
	return 0;
}




