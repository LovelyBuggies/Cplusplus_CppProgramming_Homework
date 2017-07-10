 //
// MP.hpp
// CPP
// 
// Created by Nino Leo on 17/05/24.
// Copyright © Nino 2017. All rights reserveed.


#ifndef MP_HPP
#define MP_HPP

namespace MP {


typedef struct TreeNode
{
    int val, id;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, int i) {
        val = x;
        id = i;
        left = 0;
        right = 0;
    }
} TreeNode;


class MaxPath
{
public:
    MaxPath();
    int weight(TreeNode* root);
    int findMaxPath(TreeNode* root);
};

}

#endif