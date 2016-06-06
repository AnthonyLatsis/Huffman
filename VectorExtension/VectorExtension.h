//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

class VectorExtension {
	
public:
/* Функция печати для вектора, принимающая сам вектор, какое-либо сообщение
   к напечатанному и функцию, осуществляющую печать элемента определенного типа/класса
*/
   
template <typename vectorType>
static void printVector(const std::vector<vectorType> someVector, const char * message, void (* function)(vectorType) = nullptr, bool trail = true);

};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
