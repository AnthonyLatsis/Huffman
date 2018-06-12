#include "Picture.h"


Picture::Picture(size_t height, size_t length):
	_height(height), _length(length) {
	array   = allocateArray(height, length);
}

Picture :: ~Picture(){
	for (int count = 0; count < _height; count ++) {
		delete [] array[count];
	}
	delete [] array;
}

char ** Picture::allocateArray(size_t height, size_t length) {
	char ** array = (char **)calloc(height, sizeof(char *));
	for (int counter = 0; counter < height; counter ++) {
		array[counter] = (char *)calloc(length, sizeof(char));
	}
	return array;
}

char * Picture::operator [] (const size_t index) const {
	return array[index];
}

size_t Picture::length() const {
	return _length;
}

size_t Picture::height() const {
	return _height;
}

size_t Picture::depth() const {
	return (_height - 3) / 4;
}

