# [Inheritance]Collection with Inheritance (eden)

## Knowledge points

inheritance polymorphism virtual functions interface memory management dynamic
casts

## Introduction

True object-orient programming requires objects to support three qualities:
encapsulation, inheritance, and polymorphism.Polymorphism enables one common
interface for many implementations, and for objects to act differently under
different circumstances.

C++ supports several kinds of static (compile-time) and dynamic (run-time)
polymorphisms, supported by the language features described above. Compile-
time polymorphism does not allow for certain run-time decisions, while run-
time polymorphism typically incurs a performance penalty.

Static polymorphism is not true polymorphism including function overloading,
operator overloading and templates which is not what we are going to work
on(in this question).

Dynamic polymorphism:

Variable pointers (and references) to a base class type in C++ can refer to
objects of any derived classes of that type in addition to objects exactly
matching the variable type. This allows arrays and other kinds of containers
to hold pointers to objects of differing types. Because assignment of values
to variables usually occurs at run-time, this is necessarily a run-time
phenomenon.

C++ also provides a dynamic_cast operator, which allows the program to safely
attempt conversion of an object into an object of a more specific object type
(as opposed to conversion to a more general type, which is always allowed).
This feature relies on run-time type information (RTTI). Objects known to be
of a certain specific type can also be cast to that type with static_cast, a
purely compile-time construct that has no runtime overhead and does not
require RTTI.

Ordinarily, when a function in a derived class overrides a function in a base
class, the function to call is determined by the type of the object. A given
function is overridden when there exists no difference in the number or type
of parameters between two or more definitions of that function. Hence, at
compile time, it may not be possible to determine the type of the object and
therefore the correct function to call, given only a base class pointer; the
decision is therefore put off until runtime. This is called dynamic dispatch.
Virtual member functions or methods[43] allow the most specific implementation
of the function to be called, according to the actual run-time type of the
object. In C++ implementations, this is commonly done using virtual function
tables. If the object type is known, this may be bypassed by prepending a
fully qualified class name before the function call, but in general calls to
virtual functions are resolved at run time.

In addition to standard member functions, operator overloads and destructors
can be virtual. As a rule of thumb, if any function in the class is virtual,
the destructor should be as well. As the type of an object at its creation is
known at compile time, constructors, and by extension copy constructors,
cannot be virtual. Nonetheless a situation may arise where a copy of an object
needs to be created when a pointer to a derived object is passed as a pointer
to a base object. In such a case, a common solution is to create a clone() (or
similar) virtual function that creates and returns a copy of the derived class
when called.

A member function can also be made "pure virtual" by appending it with = 0
after the closing parenthesis and before the semicolon. A class containing a
pure virtual function is called an abstract data type. Objects cannot be
created from abstract data types; they can only be derived from. Any derived
class inherits the virtual function as pure and must provide a non-pure
definition of it (and all other pure virtual functions) before objects of the
derived class can be created. A program that attempts to create an object of a
class with a pure virtual member function or inherited pure virtual member
function is ill-formed.

_from wikipedia_

## Assignment

As we all know Java is a pure obejct oriented programming language and it also
provide polymorphism.

In JDK(1.7) architecture, java has its standar container classes. We can have
a snapshot with a class diagram to show the relationship between containers.

Note that: 1. A straight line with a circle show that the class is an
interface. 2. A straight line with a hollow arrow indicates generalization
relationship or in order word, inheritance. 3. A straight line with an
unfilled diamon indicates composition relations. 4. Some detials that are
irrelevant have been admitted.


Collection is a basic interface. It's the root of the collection hierarchy. A
collection represents a group of objects known as its elements.TheCollection
interface is the least common denominator that all collections implement and
is used to pass collections around and to manipulate them when maximum
generality is desired. Some types of collections allow duplicate elements, and
others do not. Some are ordered and others are unordered. The Java platform
doesn't provide any direct implementations of this interface but provides
implementations of more specific subinterfaces, such asSet and List.

Set is a collection which dose not have order and it can not have duplicate
elements.

Sorted Set is a set that is sorted.

These two classed are implemented with RB-Tree. If you are insterested in it,
you can implement it.

List is collection that carries order, and it's also a abstract class.

Arraylist is an implantation for list using dynamic extending array.

Vector is thread-safe Arraylist.

Linked list is an implantation for list using nodes which are store in the
memory discretely.

**Now you job is to implement the classes in java using c++.**

## More

What is the C++ equivalent of inheriting a Java collection interface (Set,
Map, List etc.)? Or extending AbstractCollection?

_from stack overflow_

I've started coding in C++, coming from a Java background (actually I'd
studied C++ at my university, but we never got to the STL etc.)

Anyway, I've gotten to the point where I'm arranging data in all sorts of
collections, and I immediately tell myself "Ok, this is a kind of a Set; and
this is a List, or an ArrayList; and this is a map etc." In Java, I would
simply have whatever class I'm writing implement the Set or Map or List
interface; but I would probably not go as far as inheriting ArrayList or
HashSet or what-not, the implementations there are kind of involved and I
wouldn't want to mess them up.

Now, what do I do in C++ (with the Standard Library)? There do not seem to be
abstract base classes for Sets, Maps, Lists etc - the equivalent of Java
interfaces; on the other hand, the implementations for the standard containers
look pretty horrid. Ok, maybe they're not so horrid once you get to know them,
but suppose I just wanted to write something like a non-virtual class
extending AbstractSet in C++? Something I would be able to pass it to any
function which takes a Set? How should I go about doing that?

Just to clarify - I don't necessarily want to do what's common practice in
Java. But, on the other hand, if I have an object which, conceptually, is a
kind of set, I want to inherit something appropriate, get default
implementations gratis, and be guided by my IDE to implement those methods
which I should implement.

## Links

[Answer:What is the C++ equivalent of inheriting a Java collection interface
(Set, Map, List etc.)? Or extending
AbstractCollection?](https://stackoverflow.com/questions/20829860/what-is-
the-c-equivalent-of-inheriting-a-java-collection-interface-set-map)

[Robert C. Martin. Java vs. C++: A Critical
Comparison](http://www.objectmentor.com/resources/articles/javacpp.pdf)

## Hint

Collection和List是两个抽象类，声明支持的接口。  
Collection应支持的接口：add、clear、contain、isEmpty、remove、size  
List应支持的接口：get、operator[]、indexOf、sort  
**List is a Collection.  
ArrayList and LinkedList are Lists.**  

已禁用 std algorithm vector list

对于数组排序，请最好使用快速排序，其他有可能会超时

The steps are:

  1. Pick an element, called a _pivot_, from the array.
  2. _Partitioning_: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the _partition_ operation.
  3. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
    
```
algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p - 1)
        quicksort(A, p + 1, hi)  
  



algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo        _// place for swapping_
    for j := lo to hi - 1 do
        if A[j] ≤ pivot then
            swap A[i] with A[j]
            i := i + 1
    swap A[i] with A[hi]
    return i  
```

对于链表排序，请最好使用归并排序，其他有可能会超时
```
MergeSort(li):

 if(li.size() > 1)

    split li into li1 and li2 at position li1.size() / 2

    li1.sort()

    li2.sort()

    li.merge(li1,li2)
```


**注意浅复制的应用，因为如果采用深复制运行mergeSort会产生大量内存副本，使得程序效率大幅度降低。**    
*出题人：叶嘉琪*
