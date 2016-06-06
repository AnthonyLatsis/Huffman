//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "CStack.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

template <typename dataType>
CStack <dataType> :: CStack(){
	data = std::vector<dataType>();
}

//____________________________________________________

template <typename dataType>
CStack <dataType> :: ~CStack(){
	data.clear();
}

//____________________________________________________

template <typename dataType>
dataType CStack <dataType> :: pop(){
	dataType element = * (data.end());
	data.erase(data.end());
	return element;
}

//____________________________________________________

template <typename dataType>
void CStack <dataType> :: push(dataType element){
	data.push_back(element);
}

//____________________________________________________

template <typename dataType>
bool CStack <dataType> :: empty(){
	return (data.size() == 0);
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
