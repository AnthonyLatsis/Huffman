//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

class HuffmanCoder {

public:

/// Joins the encoded tree and string
	static const std::vector<bool> encodedMessage(std::vector<char> inputString,
												  bool registerSensitive);
/// Encodes the string
	static const std::vector<bool> encodedString(const std::vector<char> inputString,
												 const CHashtable<int,
												 const SymbolCode * const> * const codes);
/// Encodes the tree
	static const std::vector<bool> encodedTree(const HuffmanTree * const tree);

	static void ignoreRegister(std::vector<char>& inputString);
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
