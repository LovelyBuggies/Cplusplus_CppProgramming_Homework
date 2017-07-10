//
// TreePremiere.cpp
// C++
//
// Created by Nino Leo on 2017/4/24.
// Copyright © Nino 2017. All rights reserved.
//

#include "BinaryTree.hpp"


void BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root) {
	if(!Source_Root) return;
	Target_Root = new node(Source_Root->ele);
	BuildTree(Source_Root->left, Target_Root->left);
	BuildTree(Source_Root->right, Target_Root->right);
}
void BinaryTree::BuildTree(const int* arr,int len, node* &root) {
	if(root) {
		if(*arr < root->ele) 
			BuildTree(arr, len, root->left);
		else if(*arr > root->ele)
			BuildTree(arr, len, root->right);
	}
	else root = new node(*arr);
}
void BinaryTree::preorder(const node* p) {
	if(!p) return;
	cout << p->ele << " ";
	preorder(p->left);
	preorder(p->right);
}



//Creat Tree
BinaryTree::BinaryTree() {
	root = NULL;
}
BinaryTree::BinaryTree(const BinaryTree& Source) {
	//it is necessarily needed 
	//for compiler may not deal root as NULL value
	root = NULL;
	BuildTree(Source.root, root);
}
BinaryTree::BinaryTree(const int* arr, int len) {
	//it is necessarily needed 
	//for compiler may not deal root as NULL value
	root = NULL;
	for(int i = 0; i < len; i++)
	    BuildTree(arr+i, len, root);
}
void BinaryTree::ResetTree(const int* arr, int len) {
	clear();
	for(int i = 0; i < len; i++)
	    BuildTree(arr+i, len, root);
}
BinaryTree::~BinaryTree() {
	clear();
}
void clear_aux(node* &p) {
	if(!p) return;
	clear_aux(p->left);
	clear_aux(p->right);
	delete p;
	p = NULL;
}
void BinaryTree::MemoryDelete(node* p) {}
void BinaryTree::clear() {
	clear_aux(root);
}
void insert_aux(node* &root, int ele) {
	if(!root) {
		root = new node(ele);
		return;
	}
	if(ele < root->ele)
		insert_aux(root->left, ele);
	else if(ele > root->ele)
		insert_aux(root->right, ele);
}
void BinaryTree::insert(int ele) {
	insert_aux(root, ele);
}

node* maximum(node* root) {
	if(!root) return NULL;
	node* max = root;
	while(max->right) {
		max = max->right;
	}
	return max;
}

void delete_aux(node* &root, int &ele) {
	if(!root) return;
	if(ele < root->ele)
		delete_aux(root->left, ele);
	else if(ele > root->ele)
		delete_aux(root->right, ele);
	else {
		if(root->left) {
			node* max = maximum(root->left);
			root->ele = max->ele;
      delete_aux(root->left, max->ele);
		}
		else {
			node *temp = root;
			root = root->right;
			delete temp;
			temp = NULL;
		}
	}
}
void BinaryTree::Delete(int ele) {
	delete_aux(this->root, ele);
}
void BinaryTree::print() {
	//standardlize the empty output
	preorder(root);
	cout << endl;
}