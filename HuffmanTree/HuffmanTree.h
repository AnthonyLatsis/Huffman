

enum HuffmanTreeOrientation { Left, Right };

class HuffmanTree {

	static const HuffmanTreeDelegate buildDelegate;
	static const TreeImageDelegate imageDelegate;

	const Node * const root;

	HuffmanTreeOrientation orientation;

public:
	HuffmanTree(const std::vector<char> inputString, HuffmanTreeOrientation orientation = Left);
	HuffmanTree(const std::vector<bool> encodedTree);

	~HuffmanTree();

	const CHashtable<int, const SymbolCode * const> * findSymbolCodes(const std::vector<char> inputString) const; 
	const std::vector<bool> encode() const; 				                                 

	void image(const char * message = nullptr) const;

private:
	static void deleteTree(const Node *const node);

	/// Populates a hashtable with the symbol codes.
	static void findSymbolCodes(const Node *const node, std::vector<bool>& code, CHashtable<int, const SymbolCode * const>& codes);

	/// Return the tree as a binary sequence.
	static void encode(const Node *const node, std::vector<bool>& code);

	/// Return the encoded node as a binary sequence.
	static const std::vector<bool> encodeLeaf(const Node * const node);
};
