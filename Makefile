

HuffmanTree.o: HuffmanTree.cpp 
	g++ -c HuffmanTree.cpp

Optional_char.o: Optional_char.cpp
	g++ -c Optional_char.cpp

huffman: Optional_char.o HuffmanTree.o
	g++ Optional_char.o HuffmanTree.o -o huffman
