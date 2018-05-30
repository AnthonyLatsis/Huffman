
template <typename T>
void VectorExtension :: printVector(const std::vector<T> vector,
 									const char * message,
  									void (* function)(T),
  							 		bool trail) {
	if (message)
		std::cout << "\n" << message;

	for (auto elt: vector) {
		if (!function)
			std::cout << elt;
		else
			function(elt);
	}
	if (trail)
		std::cout << "\n\n<><><><><><><><><><><><><>\n";
}