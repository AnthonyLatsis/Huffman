#include "CHashtable.h"

//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
CHashtable <Tkey, Tdata> :: CHashtable(size_t size, size_t (* _mapper)(Tkey))
{
	if (_mapper == nullptr) {
		std::cout <<"hash function does not exist"<< std::endl;
		exit(EXIT_FAILURE);
	}
	tblsize = size;
	table   = new CList <Tdata, Tkey> [size];
	mapper  = _mapper;
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
CHashtable <Tkey, Tdata> :: ~CHashtable()
{
	tblsize  = ZERO;
	delete [] table;
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
void CHashtable <Tkey, Tdata> :: insert(Tkey key, Tdata data)
{
	table[(* mapper)(key) % tblsize] . insert_last(key, data);
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
void CHashtable <Tkey, Tdata> :: remove(Tkey key)
{
   	table[(* mapper)(key) % tblsize] . remove(key);
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata> 
bool CHashtable <Tkey, Tdata> :: contains(Tkey key) const
{
	if (table[(* mapper)(key) % tblsize] . contains(key)) return true;

	else return false;
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
void CHashtable <Tkey, Tdata> :: set(Tkey key, Tdata data)
{
	table[(* mapper)(key) % tblsize] . set(key, data);
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
Tdata CHashtable <Tkey, Tdata> :: operator [] (Tkey key) const
{
	return table[(* mapper)(key) % tblsize][key];
}
//_______________________________________________________________________________________

template <typename Tkey, typename Tdata>
void CHashtable <Tkey, Tdata> :: print(void (* function)(Tdata)) const
{
	for (int counter = ZERO; counter < tblsize; counter ++) {
		table[counter] . print(function);
	}
}


