//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

/* Для хранения символов с их кодами
*/

struct SymbolCode {
	const char symbol;

	std::vector<bool> code;

	SymbolCode();
	SymbolCode(char symbol, const std::vector<bool> code);
	~SymbolCode();
	
	static void print(const SymbolCode * const symbolCode);
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
