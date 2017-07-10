# [Operator Overloading]Bitset

## Description:

Please complete this class.

The class bitset is just like a big number which can have bit operations and some other operations.

You can read main.cpp to understand how I check your program.

## Hint:

这并不是真正的bitset，只是用一些简单的c++知识来模仿bitset。

```
#define N 5
const int max_length = 32 * N;//这个数字共有32*5位。从第0位到第max_length-1位，第0位是最低位。
class bitset {
private:
int a[N];//一个int32位，所以只用开N个int
public:
bitset();//默认构造函数，所有位初始化为0
void set(int pos);//把位置pos设置成1
void reset(int pos);//将位置pos设置成0
int count() const;//输出一共有多少个为1的位
bool test(int pos) const;//位置pos是否是1
bool any() const;//是否有是1的位
bool none() const;//是否没有是1的位
bool all() const;//是否所有位都是1

//位运算部分和普通数字的位运算相同。
bitset& operator&= (const bitset& b);
bitset& operator|= (const bitset& b);
bitset& operator^= (const bitset& b);
bitset& operator= (const bitset& b);
bitset& operator <<= (int pos);
bitset& operator >>= (int pos);
bitset operator~() const;
bitset operator&(const bitset& b) const;
bitset operator|(const bitset& b) const;
bitset operator^(const bitset& b) const;
bitset operator<<(int pos) const;
bitset operator>>(int pos) const;
bool operator== (const bitset& b) const;
bool operator!= (const bitset& b) const;
bool operator[] (int pos) const;//返回位置pos是不是1.

//输出部分已经实现
```

*出题人： 王毅峰*