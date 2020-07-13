/*
Given a string A, we may represent it as a binary tree by partitioning
it to two non-empty substrings recursively.
Below is one possible representation of A = “great”:
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node “gr” and swap its two children, it produces a 
scrambled string “rgeat”.
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.
Similarly, if we continue to swap the children of nodes “eat” and “at”, 
it produces a scrambled string “rgtae”.
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.
Given two strings A and B of the same length, determine if B is a scrambled
string of S.*/
/////////////////////////////////////////////////////////////////////////////
//Recursion with memoization approach
#include<bits/stdc++.h>
using namespace std;


map <string , int > mp;

int isScramble(const string a, const string b) 
{
    if(a.compare(b) == 0)
        return 1;
    if(a.size() < 1 )
        return 0;
        
    string key = a ;
    key.push_back(' ');
    key.append(b);
    
    if(mp.find(key) != mp.end())
        return mp[key];
    
    int n = a.size();
    int flag = 0;
    
    for( int i =1; i<=n-1; i++)
    {
        if((isScramble(a.substr(0, i), b.substr(n-i,i)) == 1
            && isScramble(a.substr(i,n-i), b.substr(0, n-i)) == 1) || 
            ((isScramble(a.substr(0,i), b.substr(0,i)) == 1) && 
            isScramble(a.substr(i, n-i), b.substr(i, n-i)) ==1 ))
            {
                flag =1;
                break;
            }
    }
    mp[key] = flag;
    return flag;
}


int main()
{
    string a = "great";
    string b = "rgtae";
    if(isScramble)
        cout<<"both strings are scramble";
    else
    {
        cout<<"these are not scramble";
    }
    return 0;
}