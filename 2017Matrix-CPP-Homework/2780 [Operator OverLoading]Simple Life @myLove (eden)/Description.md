# [Operator OverLoading]Simple Life @myLove (eden)

## Description
An **iterator** is any object that, pointing to some element in a range of
elements (such as an array or a container), has the ability to iterate through
the elements of that range using a set of operators (with at least the
increment (++) and dereference (*) operators).

The most obvious form of iterator is a pointer: A pointer can point to
elements in an array, and can iterate through them using the increment
operator (++). But other kinds of iterators are possible. For example, each
container type (such as a list) has a specific iterator type designed to
iterate through its elements.

**Details about iterator:**  
C PLUS PLUS http://www.cplusplus.com/reference/iterator/  
WIKIPEDIA https://en.wikipedia.org/wiki/Iterator

Now we are going to make an iterator and find fun!

Carson has written the "simple_vector", it realizes a little of the functions
in STL_Vector, he invites all of you to design the "simple_iterator.h".

**What is simple_vector:**  
It is a data structure to store data dynamically.  
member: char* data; long long int size, capacity;  
function: pushBack(char); Begin(); End(); rBegin(); rEnd();

**What is simple_iterator:**  
member: char* pointer;  
function: char& base(), <C++11 prev(), next(), begin(), end()>;  
overload: * / ++ / -- / == / != / < / > / <= / >= / + / - ;

**Note:** all the input data are from 'a' to 'z', and the vector's size is no less than 5 in this test.

From: *林楚庭*


