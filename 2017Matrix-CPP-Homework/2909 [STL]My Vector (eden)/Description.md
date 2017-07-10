# [STL]My Vector (eden)

# MyVector

## Descrption
Given a Class definition below:
```
template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
    public:
        // Constructor
        myVector();
         myVector(const std::size_t & size, const T & val,
                 Alloc a = Alloc());
        template<typename InputIterator>
            myVector(InputIterator begin, InputIterator end,
                     Alloc a = Alloc());
        myVector(const myVector & other);
        ~myVector();
         // Copy Operator
        myVector & operator=(const myVector & other);
         // Iterator
        typedef T *         iterator;
        typedef const T *   const_iterator;
        inline iterator begin();
        inline const_iterator begin() const;
        inline iterator end();
        inline const_iterator end() const;
         // Capacity
        inline std::size_t size();
        void resize(const std::size_t & newSize);
        void resize(const std::size_t & newSize, const T & val);
        inline std::size_t capacity() const;
        inline bool empty() const;
        void reserve(const std::size_t & newCapacity);
         // Element Access
        inline T & operator[](const std::size_t & index);
        inline const T & operator[](const std::size_t & index) const;
        inline T & front();
        inline const T & front() const;
        inline T & back();
        inline const T & back() const;
        inline T * data();
        inline const T * data() const;
         // Modifiers
        template<typename InputIterator>
        void assign(InputIterator begin, InputIterator end);
        void assign(const std::size_t & newSize, const T & val);
        void push_back(const T & val);
        void pop_back();
        void clear();
     private:
        T * _data;
        std::size_t _size, _capacity;
};
```


### Your Job is to finish it.

### Be Careful
`You should include the "base.h" and the class mVector should inherit from the
class Base.`



### I will be very happy if you have better idea than the standard answer. If so,please mail to [me@citron.moe](mailto:me@citron.moe)

### Some Tips:
[About Allocator](http://www.cplusplus.com/reference/memory/allocator)

[Allocator\(with an example\)](http://en.cppreference.com/w/cpp/memory/allocator)

[Wiki About Allocator](https://en.wikipedia.org/wiki/Allocator_%28C%2B%2B%29)

From：*彭勃*

