//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "Optional_char.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

Optional_char :: Optional_char() {
	value = None;
}

//____________________________________________________

Optional_char :: Optional_char(char symbol) {
	value 		   = Some;
	this -> symbol = symbol;
}

//____________________________________________________

bool Optional_char :: operator == (char * nil) const {
	if (this -> value == None && nil == nullptr) {
		return true;
	} else {
		return false;
	}	
}

//____________________________________________________

bool Optional_char :: operator == (char symbol) const {
	if (this -> value == Some && this -> symbol == symbol) {
		return true;
	} else { 
		return false;
	}
}

//____________________________________________________

void Optional_char :: operator = (char * nil) {
	if (nil == nullptr) {
		value = None;
	}
}

//____________________________________________________

void Optional_char :: operator = (char symbol) {
	value = Some;
	this -> symbol = symbol;
}

//____________________________________________________

void Optional_char :: print() const{
	if (value == None) {
		std::cout << "nil";
	} else {
		std::cout << symbol;
	}
}

//____________________________________________________

char Optional_char::get() const {
	if (value == None) {
		return ' ';
	} else {
		return symbol;
	}
}

//____________________________________________________

char Optional_char::operator ! () const {
	if (value == None) {
		exit(EXIT_FAILURE);
	} else {
		return symbol;
	}
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//