#include <cstring>
template<typename T>
bool cmp(T a, T b) {
     if (a == b)
         return true;
     else
         return false;
}
 bool cmp(char* a, char* b) {
     if (strcmp(a, b) == 0)
         return true;
     else
         return false;
}
 template<typename T>
bool cmp(T* a, T* b) {
     if (*a == *b)
         return true;
     else
         return false;
}
 