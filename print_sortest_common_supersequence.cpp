/*
Given two strings X and Y, print the shortest string
that has both X and Y as subsequences. If multiple
shortest supersequence exists, print any one of them.
Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y*/
///////////////////////////////////////////////////////////////////////
//DP approach..back track the dp table used to
// fill the longest commons subsequence 
// with some modification

#include<bits/stdc++.h>
using namespace std;

string printShortestSuperSeq(string x, string y)
{
    int m = x.size();
    int n = y.size();
    /////////////////////////////
    //table filling for longest common subsequence
    int t[m+1][n+1];

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

    //////////////////////////////////////////////
    //back track the table from last;
    string result = "";
    int i = m, j = n;
    while( i>0 && j >0)
    {
        if(x[i-1] == y[j-1])
        {
            result.push_back( x[i-1] );
            i--; j--;
        }

        else
        {
            if( x[i-1] > y[j-1] )
            {
                result.push_back ( x[i-1] );
                i--;
            }

            else
            {
                result.push_back ( y[j-1] );
                j--;
            }
        }
    }

    //now push the remaining indices of if any 
    while(i > 0)
    {
        result.push_back( x[i-1] );
        i--;
    }

    while(j > 0)
    {
        result.push_back( y[j-1] );
        j--;
    }

    //finally reverse and return the string to get actual output.
    reverse(result.begin(), result.end());
    return result;
}

int main() 
{ 
    //string X = "AGGTAB"; 
    string X = "HELLO";
    //string Y = "GXTXAYB"; 
    string Y = "GEEK";
  
    cout << printShortestSuperSeq(X, Y); 
  
    return 0; 
} 
