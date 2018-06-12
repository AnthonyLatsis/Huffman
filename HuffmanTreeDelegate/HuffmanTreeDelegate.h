class HuffmanTreeDelegate {

public:
/* Oсновная функция постройки дерева
*/	
	static const Node * const tree(std::vector<char> inputString);

/* Создает вектор с готовыми листами будущего дерева
*/
	static std::vector<const Node *> leaves(std::vector<char> inputString);

/* строит дерево с помощью вектора, содержащего листы, возвращает его обратно
*/
	static const Node * const buildTree(std::vector<const Node *> frequencies);

/* Сортирует вектор с листами по возрастанию приоритета
*/
	static void sortFrequencies(std::vector<const Node *>& frequencies);

/* Функция сравнения для сортировки вектора, содержащего листы, по приоритету ]
*/
	static bool compareNodesByPriority(const Node * const first, const Node * const second);
};
