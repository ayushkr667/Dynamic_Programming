/*
Given two sequences, find the length of longest 
subsequence present in both of them. A subsequence
is a sequence that appears in the same relative order,
but not necessarily contiguous. For example,
“abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
 are subsequences of “abcdefg”.*/

////////////////////////////////////////////////////////////////


//memoization with recursive call

# include<bits/stdc++.h>
using namespace std;

int t[1000][1000];//to store memoized value

int lcs( string x, string y, int m, int n)
{
    t[m+1][n+1];
    //initialization
    //if either length of x or y = 0 it will return 0
    if(m==0 || n==0)
        t[m][n] = 0;

    // if value of that cell is already filled
    if(t[m][n] != -1)
        return t[m][n];

    //both has common characrer
    else if (x[m-1] == y[n-1])
        return t[m][n] = 1 + lcs( x, y, m-1, n-1);

    // find max of leaving 1 char from each alternatively
    else
        return t[m][n] = max( lcs(x, y, m-1, n), lcs(x, y, m, n-1)); 

}



int main()  
{
    //initialization of table with -1
    memset ( t , -1, sizeof(t));  
    string x = "AGGTAB";  
    string y = "GXTXAYB";  
      
    int m = x.size();  
    int n = y.size();  
      
    cout << "Length of Longest Common Subsequence is " 
         << lcs( x, y, m, n );  
      
    return 0;  
}  
