#include "CHashtable.h"


template <typename Tkey, typename Tdata>
CHashtable::CHashtable(size_t size, size_t (* mapper)(Tkey)) {
	assert(mapper && "null hash function pointer");
	
	tblsize = size;
	table   = new CList<Tdata, Tkey>[size];
	this->mapper = mapper;
}

template <typename Tkey, typename Tdata>
CHashtable:: ~CHashtable() {
	tblsize = ZERO;
	delete [] table;
}

template <typename Tkey, typename Tdata>
void CHashtable::insert(Tkey key, Tdata data) {
	table[(* mapper)(key) % tblsize].insert_last(key, data);
}

template <typename Tkey, typename Tdata>
void CHashtable::remove(Tkey key) {
  table[(* mapper)(key) % tblsize].remove(key);
}

template <typename Tkey, typename Tdata> 
bool CHashtable::contains(Tkey key) const {
	if (table[(* mapper)(key) % tblsize].contains(key))
		return true;
	return false;
}

template <typename Tkey, typename Tdata>
void CHashtable::set(Tkey key, Tdata data) {
	table[(* mapper)(key) % tblsize].set(key, data);
}

template <typename Tkey, typename Tdata>
Tdata CHashtable::operator [] (Tkey key) const {
	return table[(* mapper)(key) % tblsize][key];
}

template <typename Tkey, typename Tdata>
void CHashtable::print(void (* function)(Tdata)) const {
	std::cout << '\n';
	for (int counter = ZERO; counter < tblsize; counter ++) {
		table[counter] . print(function);
	}
}
