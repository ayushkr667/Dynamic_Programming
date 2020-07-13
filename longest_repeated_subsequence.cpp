/*
Given a string, print the longest repeating subsequence 
such that the two subsequence don’t have same string character
at same position, i.e., any i’th character in the two subsequences
shouldn’t have the same index in the original string.

Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.*/

//////////////////////////////////////////////////////////////////////
//DP method
//This problem is just the modification of "Longest Common Subsequence problem."
//The idea is to find the LCS(str, str) where str is the input string
//with the restriction that when both the characters are same
//they shouldn’t be on the same index in the two strings.

# include<bits/stdc++.h>
using namespace std;


int longestRepeatedSubSeq( string x)
{
    string y = x;
    int m = x.size();
    int t[m+1][m+1];
    //initialization
    //if either length of x or y = 0 it will return 0
    for(int i = 0 ; i<=m; i++)
    {
        t[0][i] = 0;
        t[i][0] = 0;
    }

    for (int i=1; i<=m; i++) //i for m
    {
        for(int j=1; j<=m; j++)//j for n
        {
            if ( (x[i-1] == y[j-1]) && (i != j))
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max( t[i-1][j], t[i][j-1]);
            }
        } 
    }
    return t[m][m];
}



int main()  
{

    string x = "AABEBCDD";
      
    int m = x.size();  
      
    cout << longestRepeatedSubSeq(x); 

    return 0;   
}  

//note:- for printing we use same approach as 
//used to print longest common subsequence