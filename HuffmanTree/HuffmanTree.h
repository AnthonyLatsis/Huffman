//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

/* Определяет ориентацию дерева. По умолчанию Left 
*/
enum HuffmanTreeOrientation { Left, Right };

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

class HuffmanTree {

/* Делегат дерева, занимающийся его постройкой 
*/
	static const HuffmanTreeDelegate buildDelegate;
	static const TreeImageDelegate imageDelegate;

	const Node * const root;

	HuffmanTreeOrientation orientation;

public:
	HuffmanTree(const std::vector<char> inputString, HuffmanTreeOrientation orientation = Left);
	HuffmanTree(const std::vector<bool> encodedTree);

	~HuffmanTree();

	const CHashtable<int, const SymbolCode * const> * findSymbolCodes(const std::vector<char> inputString) const; //	(*) 
	const std::vector<bool> encode() const; 					   						     					  // 	[*]				                                 

	void image(const char * message = nullptr) const;

private:
/* Рекурсивно удаляет дерево деструктору
*/
	static void deleteTree(const Node * const node);

/* Метод (*), возвращающий вектор с парами (символ, код) и вспомогательная функция постфиксного обхода
*/
	static void findSymbolCodes(const Node * const node, std::vector<bool>& code, CHashtable<int, const SymbolCode * const>& codes);

/* Метод [*], возвращающий вектор закодированного дерева и вспомогательная функция постфиксного обхода
*/
	static void encode(const Node * const node, std::vector<bool>& code);

/* Функция, записывающая в вектор бинарный код листа с символом
*/
	static const std::vector<bool> encodeLeaf(const Node * const node);
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
