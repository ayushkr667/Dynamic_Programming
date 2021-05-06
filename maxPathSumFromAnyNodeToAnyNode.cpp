/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes
from some starting node to any node in the tree along the 
parent-child connections. The path must contain at least 
one node and does not need to go through the root.
Example 1:
Input: [1,2,3]

       1
      / \
     2   3
Output: 6
Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42*/

/////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 
using namespace std; 
  
/* Tree node structure used in the program */
struct Node { 
    int data; 
    Node* left, *right; 
}; 

struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
  
    return (node); 
} 


int sum(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_sum = sum(root->left, ans); 
  
    int right_sum = sum(root->right, ans); 
  
    // update the answer, because max sum of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height )+ root), and root itself
    // for each node 
    int temp = max ( (max(left_sum, right_sum) + root ->data), root->data);
    temp = max(temp,  left_sum + right_sum + root->data); 
    ans = max(ans, temp);
    
    return max ( (max(left_sum, right_sum) + root ->data), root->data);
} 


int maxPathSum(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = sum(root, ans); 
    return ans; 
} 

int main() 
{ 
    struct Node* root = newNode(-10); 
    root->left = newNode(9); 
    root->right = newNode(20); 
    root->right->left = newNode(15); 
    root->right->right = newNode(7); 
  
    printf("max path sum is %d\n", maxPathSum(root)); 
  
    return 0; 
} 
