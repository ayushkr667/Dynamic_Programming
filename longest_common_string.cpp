/*Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples :

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd”
Output : 4*/
/////////////////////////////////////////////////////////////////////////////////////
//DP approach
# include<bits/stdc++.h>
using namespace std;


int LCSubStr(string x, string y, int m, int n)
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
    int result =0;
    for (int i=1; i<=m; i++) //i for m
    {
        for(int j=1; j<=n; j++)//j for n
        {
            if (x[i-1] == y[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
                result = max(result, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        } 
    }
    //return t[m][n];
    return result;
} 



int main() 
{ 
    string X = "OldSite:GeeksforGeeks.org"; 
    string Y = "NewSite:GeeksQuiz.com"; 
  
    int m = X.size(); 
    int n = Y.size(); 
  
    cout << "Length of Longest Common Substring is " 
         << LCSubStr(X, Y, m, n); 
    return 0; 
} 
