/*
As an example, if the given sequence is “BBABCBCAB”,
then the output should be 7 as “BABCBAB” is the longest
palindromic subseuqnce in it. “BBBBB” and “BBCBB” 
are also palindromic subsequences of the given sequence,
but not the longest ones.*/
////////////////////////////////////////////////////////////
//DP approach
#include<bits/stdc++.h>
using namespace std;

int lps(string seq )
{
    int n = seq.size();
    //reverse of that string
    string rev = string(seq.rbegin(),seq.rend());
    //now longest pallindromic subsequence
    //is longest common subsequence of seq and itss reverse
    int t[n+1][n+1];

    //initialization
    for(int i=0; i<=n; i++)
    {
        t[0][i] =  0;
        t[i][0] = 0;
    }

    //updation of table 
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(seq[i-1] == rev[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }  
        }
    }
return t[n][n];
}


int main() 
{ 
    string seq = "GEEKSFORGEEKS"; 
    int n = seq.size(); 
    cout << "The length of the LPS is " 
         << lps(seq); 
    return 0; 
} 
