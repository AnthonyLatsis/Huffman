
template <typename Tkey, typename Tdata>
class CHashtable {
	CList <Tdata, Tkey> * table;
	size_t tblsize;
	size_t (* mapper)(Tkey);
public:
	CHashtable (size_t size, size_t (* _mapper)(Tkey));
	~CHashtable();

	void  insert      (Tkey key, Tdata data);
	void  set         (Tkey key, Tdata data);
	void  remove      (Tkey key);
	void  print       (void (* function)(Tdata)) const;
	bool  contains    (Tkey key)        const;
	Tdata operator [] (Tkey key)		const;
};


