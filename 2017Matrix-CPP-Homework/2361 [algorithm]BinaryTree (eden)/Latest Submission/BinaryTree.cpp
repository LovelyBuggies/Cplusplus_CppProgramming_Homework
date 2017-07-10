//
//  BinaryTree.hpp
//  C++
//
//  Created by Nino on 17/4/24.
//  Copyright © 2017年 leo. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iterator>
#include <iostream>
using namespace std;


// assistants
// CopyTree assistant
void CopyTree(BinaryTree::Node* Source_Root, BinaryTree::Node* &Target_Root) {
	if(!Source_Root) return;
	if(Source_Root->val == '#') return;
	Target_Root = new BinaryTree::Node(Source_Root->val, 0, 0);
	CopyTree(Source_Root->left, Target_Root->left);
	CopyTree(Source_Root->right, Target_Root->right);
}
// BFSCreat assistant
void BFSCreatTree(BinaryTree::Node* &root, char a[], int len, int index) {
    if(index > len -1) return;
    if(a[index] == '#') return;
    root = new BinaryTree::Node(a[index], 0, 0);
    BFSCreatTree(root->left, a, len, 2*index+1);
    BFSCreatTree(root->right, a, len, 2*index+2);
}
// DFSCreat assistant
void DFSCreatTree(BinaryTree::Node* &root, char* a_pre_start, char* a_pre_end, char* a_in_start, char* a_in_end) {
	// construct a root
	char val_root = *a_pre_start;
    root = new BinaryTree::Node(val_root, 0, 0);
    if(a_pre_start == a_pre_end) return;
    // find the value of root in the inorder array
    char *root_inorder;
    for(root_inorder = a_in_start; root_inorder <= a_in_end; root_inorder++)
    	if(*root_inorder == val_root)
    		break;
    if(root_inorder == a_in_end && *root_inorder != val_root) 
    	return;
    // construct left subtree
    int len_left = root_inorder - a_in_start;
    int len_right = a_in_end - root_inorder;
    if(len_left > 0)
    	DFSCreatTree(root->left, a_pre_start+1, a_pre_start+len_left, a_in_start, root_inorder-1);
    if(len_right > 0)
    	DFSCreatTree(root->right, a_pre_start+len_left+1, a_pre_end, root_inorder+1, a_in_end);
}
// clear assistant
void DeleteNode(BinaryTree::Node* &root) {
	if(!root) return;
	DeleteNode(root->left);
	DeleteNode(root->right);
	delete root;
	root = NULL;
}



// Copy tree
BinaryTree::BinaryTree(const BinaryTree& other) {
	root = NULL;
	CopyTree(other.root, root);
}
// Breadth first Search to creat
BinaryTree::BinaryTree(std::vector<char>& arr) {
	root = NULL;
	int len = arr.size();
	if(len != 0) {
        std::vector<char>::size_type sz = arr.size();
        char a[15];
        for(unsigned k = 0; k < 15; k++)
        	a[k] = '#';
        for(unsigned i = 0; i < sz; i++)
        	a[i] = arr[i];
        for(unsigned pos = 0; pos < len; pos++)
            if(a[pos] == '#' && (a[2*pos+1] != '#' || a[2*pos+2] != '#')) {
                for(unsigned i = len-1; i >= 2*pos+1; i--)
                a[i+2] = a[i];
                a[2*pos+1] = '#';
                a[2*pos+2] = '#';
            }
        BFSCreatTree(root, a, len, 0);
	}
}
// Depth first Search to creat with preorder and inorder
BinaryTree::BinaryTree(const std::vector<char>& preOrder, const std::vector<char>& inOrder) {
    root = NULL;
    if(preOrder.size() != 0) {
        char a_pre[preOrder.size()];
        char a_in[inOrder.size()];
        std::vector<char>::size_type sz = preOrder.size();
        for(unsigned i = 0; i < sz; i++)
        	a_pre[i] = preOrder[i];
        for(unsigned i = 0; i < sz; i++)
        	a_in[i] = inOrder[i];
        DFSCreatTree(root, a_pre, a_pre+preOrder.size()-1, a_in, a_in+inOrder.size()-1);
    }
}
// destructor
BinaryTree::~BinaryTree() {
	clear();
	root = NULL;
}



// deep copy
BinaryTree::Node * BinaryTree::copyNode(Node * oldNode, Node * newNode) {
	if(!oldNode) return NULL;
	newNode = new BinaryTree::Node(oldNode->val, 0, 0);
	return newNode;
}
// overload
BinaryTree& BinaryTree::operator=(const BinaryTree& temp) {
	if(&temp == this) return *this;
	this->clear();
	CopyTree(temp.root, this->root);
	return *this;
}
// root
BinaryTree::Node* BinaryTree::getRoot() const {
	return root;
}
void BinaryTree::clear() {
    if(!root) return;
    DeleteNode(root);
}
    
void BinaryTree::preOrder(void (*visite)(BinaryTree::Node* argument), Node* target) {
	if(!target) return;
	(*visite)(target);
	if(target->left)
		preOrder(*visite, target->left);
	if(target->right)
		preOrder(*visite, target->right);
}
void BinaryTree::inOrder(void (*visite)(BinaryTree::Node*), Node* target) {
	if(!target) return;
	if(target->left)
		inOrder(*visite, target->left);
	(*visite)(target);
	if(target->right)
		inOrder(*visite, target->right);
}
void BinaryTree::postOrder(void (*visite)(BinaryTree::Node*), Node* target) {
    if(!target) return;
    if(target->left)
		postOrder(*visite, target->left);
	if(target->right)
		postOrder(*visite, target->right);
	(*visite)(target);
}