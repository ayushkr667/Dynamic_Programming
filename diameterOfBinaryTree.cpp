/*
The diameter of a tree is the number of nodes on the longest path between
two leaves in the tree. The diagram below shows two trees each with 
diameter nine, the leaves that form the ends of the longest path are 
colored (note that there may be more than one path in the tree of the same diameter).
Examples:
Input :     1
          /   \
        2      3
      /  \
    4     5

Output : 4

Input :     1
          /   \
        2      3
      /  \ .    \
    4     5 .    6

Output : 5*/
///////////////////////////////////////////////////////////////////////////
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

int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 

int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 

int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Diameter is %d\n", diameter(root)); 
  
    return 0; 
} 
