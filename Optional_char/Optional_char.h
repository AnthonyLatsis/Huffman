
enum Optional { Some, None };

class Optional_char {
	Optional value;

	char symbol;

public:
	Optional_char();
	Optional_char(char symbol);

	bool operator == (char * nil)  const;
	bool operator == (char symbol) const;
	void operator = (char * nil);
	void operator = (char symbol);

	char operator ! () const;

	void print() const;

	char get() const;
};