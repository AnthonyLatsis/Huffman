#include "Optional_char.h"


Optional_char :: Optional_char() {
	value = None;
}

Optional_char :: Optional_char(char symbol) {
	value = Some;
	this->symbol = symbol;
}

bool Optional_char :: operator == (char * nil) const {
	if (this->value == None && !nil) {
		return true;
	return false;	
}

bool Optional_char :: operator == (char symbol) const {
	if (this->value == Some && this->symbol == symbol) {
		return true;
	return false;
}

void Optional_char :: operator = (char * nil) {
	if (!nil)
		value = None;
}

void Optional_char :: operator = (char symbol) {
	value = Some;
	this->symbol = symbol;
}

void Optional_char :: print() const{
	if (value == None)
		std::cout << "nil";
	else
		std::cout << symbol;
}

char Optional_char::get() const {
	if (value == None)
		return ' ';
	return symbol;
}

char Optional_char::operator ! () const {
	if (value == None)
		exit(EXIT_FAILURE);
	return symbol;
}