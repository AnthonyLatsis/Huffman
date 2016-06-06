//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "VectorExtension.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

template <typename vectorType>
void VectorExtension :: printVector(const std::vector<vectorType> someVector, const char * message, void (* function)(vectorType), bool trail) {
	if (message != nullptr) {
		std::cout << "\n" << message;
	}
	for (int counter = 0; counter < someVector.size(); counter ++) {
		if (function == nullptr) {
			std::cout << someVector[counter];
		} else {
			function(someVector[counter]);
		}
	}
	if (trail) {
		std::cout << "\n\n<><><><><><><><><><><><><>\n";
	}
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
