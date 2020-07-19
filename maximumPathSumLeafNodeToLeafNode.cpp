/*
Given a binary tree in which each node element contains a number. 
Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root. For example, 
in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10).
Expected time complexity is O(n).

                      -15
                    /     \
                   5       6
                 /   \    /  \
               -8     1  3     9
              /   \             \
             2     6             0
                               /    \
                              4      -1
                                    /
                                   10
*/
////////////////////////////////////////////////////////////////
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
    int temp =  (max(left_sum, right_sum) + root ->data);
    //if node is leafe node
    if(root ->left == NULL && root ->right == NULL)
    {
        temp = max(temp, root ->data);
    }
    //Path passes through that node and left and right of that
    temp = max(temp,  left_sum + right_sum + root->data); 
    ans = max(ans, temp);
    
    return  (max(left_sum, right_sum) + root ->data);
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
    struct Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 
    cout << "Max pathSum of the given binary tree is "
         << maxPathSum(root); 
    return 0; 
} 