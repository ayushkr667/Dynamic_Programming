/*
Given two sequences, find the length of longest 
subsequence present in both of them. A subsequence
is a sequence that appears in the same relative order,
but not necessarily contiguous. For example,
“abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
 are subsequences of “abcdefg”.*/

////////////////////////////////////////////////////////////////
//recursive approach

# include<bits/stdc++.h>
using namespace std;

int lcs( string x, string y, int m, int n)
{
    //base case 
    //if either length of x or y = 0 it will return 0
    if(m==0 || n==0)
        return 0;

    //both has common characrer
    if (x[m-1] == y[n-1])
        return 1 + lcs( x, y, m-1, n-1);

    // find max of leaving 1 char from each alternatively
    else
        return max( lcs(x, y, m-1, n), lcs(x, y, m, n-1)); 

}



int main()  
{  
    string x = "AGGTAB";  
    string y = "GXTXAYB";  
      
    int m = x.size();  
    int n = y.size();  
      
    cout << "Length of Longest Common Subsequence is " 
         << lcs( x, y, m, n );  
      
    return 0;  
}  
