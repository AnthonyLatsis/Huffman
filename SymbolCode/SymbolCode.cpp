#include "SymbolCode.h"

SymbolCode::SymbolCode(): symbol(0) {
	this -> code = std::vector<bool>();
}

SymbolCode::SymbolCode(char symbol, const std::vector<bool> code): symbol(symbol) {
	this -> code = code;
}

void SymbolCode::print(const SymbolCode * const symbolCode) {
	std::cout << "'" << symbolCode -> symbol;
	std::cout << "' : ";
	VectorExtension::printVector(symbolCode -> code, nullptr, (void (*)(bool))nullptr, false);
	std::cout << "\n";
}

SymbolCode :: ~SymbolCode() {
	code.erase(code.begin(), code.end());
}
