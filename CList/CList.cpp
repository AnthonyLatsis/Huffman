#include <iostream>
#include <cstdlib>

int ZERO = 0;
int ONE  = 1;
int TWO  = 2;

#include "CList.h"

//___________________________________________________________________________________________
//________________________CONSTRUCTOR_AND_DESTRUCTOR_________________________________________

template <typename Tdata, typename Tkey>
CList <Tdata, Tkey> :: Node :: Node(Tkey _key, Tdata _data): data(_data)
{
	key  = _key;
	next = nullptr;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
CList <Tdata, Tkey> :: CList()
{
	head   = nullptr;
	length = ZERO;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
CList <Tdata, Tkey> :: ~CList()
{
	Node * box = head;
	while (box != nullptr) {
		box  = head -> next;
		delete head -> data;
		delete head;
		head = box;
	} 
	length = ZERO;
}
//___________________________________________________________________________________________
//_____________________________OPERATOR_OVERLOAD_____________________________________________

template <typename Tdata, typename Tkey>
Tdata CList <Tdata, Tkey> :: operator [] (Tkey key) const
{
	if (empty("list empty, no such key")) exit(EXIT_FAILURE);

	Node * box = head;
	while (box != nullptr) {
		if (box -> key == key) {
			 return box -> data;
		}
		box = box -> next;
	} 
	exit(EXIT_FAILURE);
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
typename CList <Tdata, Tkey> :: Node * CList <Tdata, Tkey> :: operator [] (size_t index) const
{
	if (empty("list empty, can't refer")) exit(EXIT_FAILURE);

	if (index >= length) std::cout << "out of range index" << std::endl;

	Node * box = head;

	for (int counter = ZERO; counter < index; counter ++) {
		box = box -> next;
	}
	return box;
}

//___________________________________________________________________________________________
//_____________________________LIST_MANIPULATION_____________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: print(void (* function)(Tdata)) const
{
	if (empty(nullptr)) return;

	Node * box = head;
	while (box != nullptr) {
		function(box -> data);
		box = box -> next;
	}
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
size_t CList <Tdata, Tkey> :: size() const
{
	return length;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
bool CList <Tdata, Tkey> :: empty(const char * message) const
{
	if (length == ZERO) {
		if (message != nullptr) {
			std::cout << message << std::endl;
		} return true;
	} else return false;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: insert_first(Tkey key, Tdata data)
{
	Node * node  = new Node(key, data);
	node -> next = head;
	head         = node;

	length ++;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: insert_last(Tkey key, Tdata data) 
{
	if (empty(nullptr)) {
		insert_first(key, data);
		return;
	}
	(* this)[length - ONE] -> next = new Node(key, data);

	length ++;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: set(Tkey key, Tdata data)
{
	if (empty("list empty, can't set")) return;

	Node * node = head;
	while (node != nullptr) {
		if (node -> key == key) {
			node -> data = data;
			return;
		}
		node = node -> next;
	}
	std::cout << "can't set unexisting key" << std::endl;
} 
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: remove(Tkey key)
{
	if (empty("underflow, list empty"))  return;

	if (!contains(key)) {
		std::cout << "can't remove unexisting key" << std::endl;
		return;
	}	
	Node * box  = head;
	Node * node = head;
	while (node -> next != nullptr) {
		if (node -> next -> key == key) {
			box = node -> next;
			node -> next = node -> next -> next;
			delete box;
			length --;
			return;
		}
		node = node -> next;
	}
	node = head -> next;
	delete head;
	head = nullptr;
	length --;
}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
void CList <Tdata, Tkey> :: clear()
{
	Node * box = head;
	while (box != nullptr) {
		box  = head -> next;
		delete head;
		head = box;
	}
	length = ZERO;
} 
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
bool CList <Tdata, Tkey> :: contains(Tkey key) const
{
	if (empty(nullptr)) return false;

	Node * node = head;
	while (node != nullptr) {
		if (node -> key == key) return true;
		node = node -> next;
	}
	return false;
}

//___________________________________________________________________________________________

