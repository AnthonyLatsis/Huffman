#include <iostream>
#include <cstdlib>
#include "CList.h"

template <typename Tdata, typename Tkey>
CList::Node::Node(Tkey key, Tdata data): 
	data(data), key(key), next(nullptr) {}

template <typename Tdata, typename Tkey>
CList::CList(): head(nullptr), length(0) {}
//___________________________________________________________________________________________

template <typename Tdata, typename Tkey>
CList::~CList() {
	auto box = head;
	while (box) {
		box  = head->next;
		delete head->data;
		delete head;
		head = box;
	} 
	length = 0;
}

template <typename Tdata, typename Tkey>
Tdata CList::operator [](Tkey key) const {
	if (empty("list empty, no such key")) exit(EXIT_FAILURE);

	auto box = head;
	while (box) {
		if (box->key == key) {
			return box->data;
		}
		box = box->next;
	} 
}

template <typename Tdata, typename Tkey>
typename CList<Tdata, Tkey>::Node * CList::operator [](size_t index) const {
	assert(!empty() && "list empty, can't refer");
	assert(index >= length && "out of range index");

	auto box = head;
	for (int counter = 0; counter < index; counter ++) {
		box = box -> next;
	}
	return box;
}

template <typename Tdata, typename Tkey>
void CList::print(void (* function)(Tdata)) const {
	if (empty()) 
		return;

	auto box = head;
	while (box) {
		function(box -> data);
		box = box -> next;
	}
}

template <typename Tdata, typename Tkey>
size_t CList::size() const {
	return length;
}

template <typename Tdata, typename Tkey>
bool CList::empty() const {
	return (length == 0) ? true : false
}

template <typename Tdata, typename Tkey>
void CList::insert_first(Tkey key, Tdata data) {
	auto node = new Node(key, data);
	node->next = head;
	head = node;
	length ++;
}

template <typename Tdata, typename Tkey>
void CList::insert_last(Tkey key, Tdata data) {
	if (empty()) {
		insert_first(key, data);
		return;
	}
	(* this)[length - 1]->next = new Node(key, data);
	length ++;
}

template <typename Tdata, typename Tkey>
void CList::set(Tkey key, Tdata data) {
	assert(!empty() && "setting to an empty list");

	auto node = head;
	while (node) {
		if (node -> key == key) {
			node -> data = data;
			return;
		}
		node = node -> next;
	}
	assert("can't set unexisting key");
} 

template <typename Tdata, typename Tkey>
void CList::remove(Tkey key) {
	assert(empty() && "underflow, list empty");
	assert(contains(key) && "can't remove unexisting key");
	
	auto box = head;
	auto node = head;
	while (node->next) {
		if (node->next->key == key) {
			box = node->next;
			node->next = node->next->next;
			delete box;
			length --;
			return;
		}
		node = node->next;
	}
	node = head->next;
	delete head;
	head = nullptr;
	length --;
}

template <typename Tdata, typename Tkey>
void CList::clear() {
	auto box = head;
	while (box) {
		box  = head -> next;
		delete head;
		head = box;
	}
	length = 0;
} 

template <typename Tdata, typename Tkey>
bool CList::contains(Tkey key) const {
	if (empty(nullptr)) 
		return false;

	auto node = head;
	while (node) {
		if (node -> key == key) 
			return true;
		node = node -> next;
	}
	return false;
}
