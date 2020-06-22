/*
Given two sequences, find the length of longest 
subsequence present in both of them. A subsequence
is a sequence that appears in the same relative order,
but not necessarily contiguous. For example,
“abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
 are subsequences of “abcdefg”.*/

////////////////////////////////////////////////////////////////
//tabulation method

# include<bits/stdc++.h>
using namespace std;


int lcs( string x, string y, int m, int n)
{
    int t[m+1][n+1];// row is for length of x, column is for length of y
    memset ( t , -1, sizeof(t)); 
    //initialization
    //if either length of x or y = 0 it will return 0
    for(int i = 0 ; i<=m; i++)
    {
        t[0][i] = 0;
    }
    for(int i = 1; i<=n; i++)
    {
        t[i][0] = 0;
    }

    for (int i=1; i<=m; i++) //i for m
    {
        for(int j=1; j<=n; j++)//j for n
        {
            if (x[i-1] == y[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max( t[i-1][j], t[i][j-1]);
            }
        } 
    }
    return t[m][n];
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