//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

template <typename dataType>
class CStack {
	std::vector<dataType> data;

	CStack();
	~CStack();

	dataType pop();

	void push(dataType data);

	bool empty();
};

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
