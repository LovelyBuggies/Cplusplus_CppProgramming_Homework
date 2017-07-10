# [algorithm]Beautiful Tree (eden)

## Before
`Please read words and pictures carefully, I promise that all the information you need could be found below`
###  Huffman Tree & Huffman Coding
Given a sequence of weight, then build a Huffman Tree with this sequence. Or Given a sequence of string(only from 'a' to 'z'), then build a Huffman Tree with each char's frequency.

### Something you need to know about Huffman Coding:
When you get the information, you need to find a best way to coding it, then you can try Huffman coding. Because it can make the coding very short. Now, I gonnan tell you the how to build a Huffman Tree and coding.
Such as {2, 4, 5, 7}, this is the sequence of weight you get, and now you are going to build a best binary tree.
* step_1: find out two smallest weights in the sequence;
* step_2: make the smaller one be the left-node, the other the right-node, and the weight of their parent is the sum of its two child-node.
* step_3: put this set of tree you make at the back of the sequence.
* step_4: loop back to step_1 untill the tree is built up.  

![file](/api/users/image?path=1043/images/1495031062707.png)

When you get string input, you need to remove all the space in it, and count the frequency of all letters appeared in the string, and make it to a sequence of weight (in the order of alphabet). Then build the Huffman Tree in the same way.
Such as 'abbbccdddddeeeeff', you should tansfer the string to the weight sequence: {1, 3, 2, 5, 4, 2}

![file](/api/users/image?path=1043/images/1495031132308.png)


### About the class HFM::HuffmanCode  
* HuffmanCode(string &str): constructor with string  
* HuffmanCode(int w[], int n): w[] is the sequence of weight, n is the length of
* the sequence  
* DisplayCode(): the output format is as the following


```
Format_1 [if construct with {2, 3, 4, 5, 7} and 5]  
Weight = 2; Code = 011  
Weight = 3; Code = 010  
Weight = 4; Code = 11  
Weight = 5; Code = 10  
Weight = 7; Code = 00  
Huffman's codeLength = 47

Format_2 [if construct with string 'you are the apple in my eyes']  
(h) Weight = 1; Code = 00011  
(i) Weight = 1; Code = 00010  
(l) Weight = 1; Code = 00001  
(m) Weight = 1; Code = 00000  
(n) Weight = 1; Code = 1111  
(o) Weight = 1; Code = 1110  
(r) Weight = 1; Code = 1101  
(s) Weight = 1; Code = 1100  
(t) Weight = 1; Code = 0111  
(u) Weight = 1; Code = 0110  
(a) Weight = 2; Code = 0011  
(p) Weight = 2; Code = 0010  
(y) Weight = 3; Code = 010  
(e) Weight = 5; Code = 10  
Huffman's codeLength = 79  
Origin Text: youaretheappleinmyeyes  
Huffman's Code: 0101110011000111101100111000111000110010001000001100001011110000001010010101100
```

### Some notes:  
The order of weight you print is in ascending order.
### More details about Huffman Coding:
https://en.wikipedia.org/wiki/Huffman_coding

From: *林楚庭*

