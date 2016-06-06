//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

class HuffmanCoder {

public:

/* Соединяет кодированные дерево и строку и возвращает сообщение
*/
	static const std::vector<bool> encodedMessage(std::vector<char> inputString, bool registerSensitive);

/* Кодирует строку
*/
	static const std::vector<bool> encodedString(const std::vector<char> inputString, const CHashtable<int, const SymbolCode * const> * const codes);

/* Кодирует дерево
*/
	static const std::vector<bool> encodedTree(const HuffmanTree * const tree);

	static void ignoreRegister(std::vector<char>& inputString);
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
