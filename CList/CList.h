template <typename Tdata, typename Tkey>
class CList {
	struct Node {
		Tkey   key;
		Tdata  data;
		Node * next;
		
		Node(Tkey key, Tdata data);
	};
	Node * head;
	size_t length;

public:
	CList();
	~CList();

	void print(void (* function)(Tdata)) const;
	size_t size() const;

	CList merge(const CList &other) const;

	void set         (Tkey key, Tdata data);
	void insert_first(Tkey key, Tdata data);
	void insert_last (Tkey key, Tdata data);
	bool contains    (Tkey key) const;
	void remove      (Tkey key);
	void clear       ();

	Tdata  operator [](Tkey key) const;
private:
	Node * operator [](size_t index) const;

	bool empty() const;
};