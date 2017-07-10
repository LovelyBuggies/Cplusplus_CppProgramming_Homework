#include "array.hpp"

array::array(array::size_t size) {
  _size = size;
  _data = new data_type[size + 1];
}

array::~array() { delete [] _data; }

array::size_t array::max_size(void) { return _size; }

array::data_type& array::at(const array::data_type& i) { return *(_data+i); }

array::data_type& array::front() { return *_data; }

array::data_type& array::back() { return *(_data + _size -1); }

array::pointer array::data() { return _data; }

void array::fill(const array::data_type& value)
{
  for(int i = 0; i < _size; i++)
     *(_data + i) = value;
}

void array::resize(int newSize)
{
  data_type *p = new data_type [newSize + 1]; 
  for(int i=0;i < _size;i++)
  *(p+i)=*(_data+i);
  delete [] _data;
  _data = p;
  _size = newSize;
}

void array::sort(int from, int to)
{
  int len = to - from;
  for(int i = 0;i < len; i++)
  	for(int j = i + 1; j < len; j++)
  		if(*(_data+from + i) > *(_data+from + j)) {
   			int temp = *(_data + from + j);
   			*(_data + from + j) = *(_data + from + i);
   			*(_data + from + i) = temp;
  }
}