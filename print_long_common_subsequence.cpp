/*
Given two sequences, print the longest subsequence present in both of them.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.*/

////////////////////////////////////////////////////////////////
//DP approach

# include<bits/stdc++.h>
using namespace std;


string lcs( string x, string y, int m, int n)
{
    int t[m+1][n+1];// row is for length of x, colimn is for length of y
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

    // fill the remaining table
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

    ///back track the table
    string s=""; 
    int i=m, j=n;
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if( t[i-1][j] > t[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    return s;
}



int main()  
{

    string x = "ABCDGH";  
    string y = "AEDFHR";  
      
    int m = x.size();  
    int n = y.size();  
      
    cout << "Longest Common Subsequence is " 
         << lcs( x, y, m, n );  
      
    return 0;  
}  