 

//
// ******** by the way, Huffman Tree Not Beautiful **********
// 

#ifndef _BEAUTIFULTREE_HPP_
#define _BEAUTIFULTREE_HPP_

#define ALPHA_NUM 26
#define MAX_NODE_NUM 2000

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

namespace HFM {

typedef struct TreeNode { 
	int val; 
	int id; 
	TreeNode* left; 
	TreeNode* right; 
	TreeNode(int value = 0, int ids = 0, 
			TreeNode* l = 0, TreeNode* r = 0) : 
			val(value), id(ids), left(l), right(r) { }
}TreeNode;

typedef struct HuffNode {
	int weight;
	bool flag;
	int par, lChild, rChild;
	HuffNode() {
		par = weight = flag = 0;
		lChild = rChild = -1;
	}
}HuffNode;

typedef struct Code {
	int bit[100];
	int position;
	int weight;
	Code() {
		position = weight = 0;
		memset(bit, 0, 100);
	}
}Code;

class HuffmanCode
{
public:
	explicit HuffmanCode(const string &str) {
		int type[ALPHA_NUM] = {0};
		LeafNode = 0;
		original = "";
		// throw the unexpected
		for(int i =0; i < str.length(); ++i) {
			if(!isalpha(str[i])) continue;
			type[str[i]-'a']++;
			original += str[i];
		}
		for(int i = 0; i < ALPHA_NUM; ++i) 
			if(type[i]) {
			node[LeafNode++].weight = type[i];
			nodeChar[LeafNode-1] = 'a' + i;
		}
		hasStr = true;
	}

	explicit HuffmanCode(int w[], int n) {
		for(int i = 0; i < 2 * n - 1; ++i)
			if(i < n)  node[i].weight = w[i];
		    else node[i].weight = 0;
		LeafNode = n;
		hasStr = false;
		original = "";
	}

	~HuffmanCode() { }

	// build the HuffmanTree
	void CreatTree() {
		int min1, min2, pos1, pos2;
		for(int i = 0; i < LeafNode-1; ++i) {
			// find the two minimal node
			min1 = min2 = 9999;
			pos1 = pos2 = 0;
			for(int j = 0; j < LeafNode + i; ++j) {
				if(node[j].weight < min2 && node[j].flag == 0) {
					min1 = min2;
					pos1 = pos2;
					min2 = node[j].weight;
					pos2 = j;
				}
				else if(node[j].weight < min1 && node[j].flag == 0) {
					min1 = node[j].weight;
					pos1 = j;
				}
			}
			// construct relation
			node[pos1].par = node[pos2].par = LeafNode + i;
			node[pos1].flag = node[pos2].flag = true;
			node[LeafNode + i].weight = node[pos1].weight + node[pos2].weight;
			node[LeafNode + i].lChild = pos1;
			node[LeafNode + i].rChild = pos2;
	 	}
	}

	// generate cod for the node
	void getHuffmanCode() {
		Code* temp_ptr = new Code;
		int childPos, parPos;
		for(int i = 0; i < LeafNode; ++i) {
			temp_ptr->position = 0;
			temp_ptr->weight = node[i].weight;
			childPos = i;
			parPos = node[i].par;
			while(parPos != 0) {
				if(node[parPos].lChild == childPos)
					temp_ptr->bit[temp_ptr->position] = 0;
				else  temp_ptr->bit[temp_ptr->position] = 1;
				temp_ptr->position++;
				childPos = parPos;
				parPos = node[childPos].par;
			}
			for(int j = temp_ptr->position - 1; j >= 0; --j)
				code[i].bit[temp_ptr->position-j-1] = temp_ptr->bit[j];
			code[i].position = temp_ptr->position;
			code[i].weight = temp_ptr->weight;
		}
		delete temp_ptr;
	}

	// display code
	void DisplayCode() {
		CreatTree();
		getHuffmanCode();
		int codeLength = 0;
		bool isVisit[MAX_NODE_NUM];
		memset(isVisit, true, MAX_NODE_NUM);
		for(int i = 0; i < LeafNode; ++i) {
			int min = MAX_NODE_NUM, pos_max = -1;
			for(int j = 0; j < LeafNode; ++j) {
				if(isVisit[j] && node[j].weight < min) {
					min = node[j].weight;
					pos_max = j;
				}
			}
			isVisit[pos_max] = false;
			if(hasStr)  cout << "(" << nodeChar[pos_max] << ") ";
			cout << "Weight = " << node[pos_max].weight << "; Code = ";
			for(int j = 0; j < code[pos_max].position; ++j) 
				cout << code[pos_max].bit[j];
			codeLength += code[pos_max].weight * code[pos_max].position;
			cout << endl;
	    }
	    cout << "Huffman's codeLength = " << codeLength << endl;
	    if(!hasStr) return ;
	    cout << "Origin Text: " << original << endl;
	    cout << "Huffman's Code: ";
	    for(int i = 0; i < original.length(); ++i)
	    	for(int j = 0; j < LeafNode; ++j) 
	    		if(nodeChar[j] == original[i])
	    			for(int p = 0; p < code[j].position; p++) 
	    				cout << code[j].bit[p];
	    cout << endl;
	}

private:
	HuffNode node[MAX_NODE_NUM];        // HuffNode array
	Code code[MAX_NODE_NUM];            // the huffmancode of the node
	char nodeChar[MAX_NODE_NUM];        // the char in the original string   
	string original;            // the original string 
	bool hasStr;                // whether the sample is a str
	int LeafNode;               // the number of LeafNode
};

};

#endif