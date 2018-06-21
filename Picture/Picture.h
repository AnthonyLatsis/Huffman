
struct Picture {
  char ** array;

  const size_t _length;
  const size_t _height;

  Picture(size_t height, size_t length);
  ~Picture();

  char * operator [] (const size_t index) const;

  size_t length() const;
  size_t height() const;
  size_t depth() const;

private:
    static char ** allocateArray(size_t height, size_t length);
};
