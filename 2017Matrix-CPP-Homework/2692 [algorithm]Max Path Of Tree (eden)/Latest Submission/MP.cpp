 //
// MP.cpp
// CPP
// 
// Created by Nino Leo on 17/05/24.
// Copyright © Nino 2017. All rights reserveed.



#include "MP.hpp"

using namespace MP;

MP::MaxPath::MaxPath() {}

int MP::MaxPath::weight(TreeNode* root) {
	if(!root) return -1;
	return root->val;
}

int MP::MaxPath::findMaxPath(TreeNode* root) {
	if(!root) return 0;
	int self_val = root->val;
	if(weight(root->left) == -1 && weight(root->right) == -1)
		return self_val;
	if(findMaxPath(root->left) >= findMaxPath(root->right))
		return findMaxPath(root->left)+self_val;
	else
		return findMaxPath(root->right)+self_val;
}