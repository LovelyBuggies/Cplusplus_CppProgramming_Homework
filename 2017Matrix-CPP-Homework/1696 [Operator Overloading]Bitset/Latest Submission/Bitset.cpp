
//
// Bitset.cpp
// C++ Bitset reminderification
//
// Created by Nino Leo on 2017/07/08.
// tempright © Nino 2017/07. All rights reserved.
//

#include "Bitset.h"
#include <cmath>
#define INT_LEN 32

bitset :: bitset() {
    for (int i = 0; i < N; i++) 
        a[i] = 0;
}

void bitset :: set(int pos) {
    int i = pos / INT_LEN;
    int j = pos % INT_LEN;
    a[i] = a[i] | (1 << j);
}

void bitset :: reset(int pos) {
    int i = pos / INT_LEN;
    int j = pos % INT_LEN;
    bool value = 0;
    a[i] &= (~value ^ (1 << j));
}

int bitset :: count() const {
    int count = 0;
    for (int i = 0; i < N; i++) {
      int num = a[i];
      while (num) {
            count++;
            num &= num - 1;
      }
    }
    return count;
}

bool bitset :: test(int pos) const {
    int i = pos / INT_LEN;
    int j = pos % INT_LEN;
    if (a[i] & (1 << j))
      return true;
    return false;
}

bool bitset :: any() const {
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < INT_LEN; j++) 
        if (a[i] & (1 << j)) 
          return true;
    return false;
}

bool bitset :: none() const {
    for (int i = 0; i < N; i++)
      if (a[i] != 0)
        return false;
    return true;
}

bool bitset :: all() const {
    for (int i = 0; i < N; i++)
      if (~a[i] != 0)
        return false;
    return true;
}

bitset& bitset :: operator&= (const bitset& b) {
    for (int i = 0; i < N; i++)
      a[i] &= b.a[i];
    return *this;
}

bitset& bitset :: operator|= (const bitset& b) {
    for (int i = 0; i < N; i++)
        a[i] |= b.a[i];
    return *this;
}

bitset& bitset :: operator^= (const bitset& b) {
    for (int i = 0; i < N; i++)
      a[i] ^= b.a[i];
    return *this;
}

bitset& bitset :: operator= (const bitset& b) {
    for (int i = 0; i < N; i++)
      a[i] = b.a[i];
    return *this;
}

bitset& bitset :: operator <<= (int pos) {
    for (int i = N-1; i > 0; i--) {
      a[i] <<= pos;
      for (int j = 0; j < pos; j++) {
        if (test(i*INT_LEN+j-pos)) 
          (*this).set(i*INT_LEN+j);
        else 
          (*this).reset(i*INT_LEN+j);
        }
    }
    a[0] <<= pos;
    for (int i = 0; i < pos; i++)
      (*this).reset(i);
}

bitset& bitset :: operator >>= (int pos) {
    for (int i = 0; i < N-1; i++) {
      a[i] >>= pos;
      for (int j = 0; j < pos; j++) {
        if (test((i+1)*INT_LEN+j))
          (*this).set((i+1)*INT_LEN+j-pos);
          else 
            (*this).reset((i+1)*INT_LEN+j-pos);
        }
    }
    a[N-1] >>= pos;
    for (int i = 0; i < pos; i++)
      (*this).set(INT_LEN*N-1-i);
}

bitset bitset :: operator~() const {
    bitset temp;
    for (int i = 0; i < N; i++)
      temp.a[i] = ~a[i];
    return temp;
}

bitset bitset :: operator&(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++)
      temp.a[i] = a[i] & b.a[i];
    return temp;
}

bitset bitset :: operator|(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++)
      temp.a[i] = a[i] | b.a[i];
    return temp;
}

bitset bitset :: operator^(const bitset& b) const {
    bitset temp;
    for (int i = 0; i < N; i++) {
        temp.a[i] = a[i] ^ b.a[i];
    }
    return temp;
}

bitset bitset :: operator<<(int pos) const {
    bitset temp;
    temp = *this;
    for (int i = N-1; i >= 1; i--) {
      temp.a[i] <<= pos;
      for (int j = 0; j < pos; j++) {
        if (temp.test(i * INT_LEN + j - pos))
          temp.set(i * INT_LEN+j);
        else
          temp.reset(i * INT_LEN + j);
      }
    }
    temp.a[0] <<= pos;
    for (int i = 0; i < pos; i++)
      temp.reset(i);
    return temp;
}

bitset bitset :: operator>>(int pos) const {
    bitset temp;
    temp = *this;
    for (int i = 0; i < N-1; i++) {
      temp.a[i] >>= pos;
        for (int j = 0; j < pos; j++) {
          if (temp.test((i + 1) * INT_LEN + j))
            temp.set((i + 1) * INT_LEN + j - pos);
          else 
            temp.reset((i + 1) * INT_LEN + j - pos);
        }
    }
    temp.a[N-1] >>= pos;
    for (int i = 0; i < pos; i++)
        temp.set(INT_LEN * N - 1 - i);
    return temp;
}

bool bitset :: operator== (const bitset& b) const {
    for (int i = 0; i < N; i++) 
        if (a[i] != b.a[i]) 
            return false;
    return true;
}

bool bitset :: operator!= (const bitset& b) const {
    int count = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == b.a[i])
            count++;
    if (count == N)
        return false;
    return true;
}

bool bitset :: operator[] (int pos) const {
    int i = pos / INT_LEN;
    int j = pos % INT_LEN;
    if (a[i] & (1 << j))
        return true;
    return false;
}