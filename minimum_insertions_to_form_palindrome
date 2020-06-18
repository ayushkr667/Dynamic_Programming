/*
Given a string of size ‘n’. The task is to remove 
or delete minimum number of characters from the
string so that the resultant string is palindrome.
Note: The order of characters should be maintained.
Examples :
Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string
Input : geeksforgeeks
Output : 8*/
//////////////////////////////////////////////////////////////////////////////
// DP approach
//  as number of insertion or deletion is same to make a string pallindrome

//minimum deletion inversly proportional to
//(size of pallindromic subsequence)

//so basically we have to find longest pallindromic subsequence
// 1- lps is answer
#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfDeletions(string str)
{
    //reverse of a string
    string rev = string(str.rbegin(), str.rend());
    int n = str.size();
    // to store dp
    int t[n+1][n+1];

    //initalization to find longest pallindromic subsequence
    //if size of any substring is 0 then no substring possible
    for(int i=0; i<=n; i++)
    {
        t[i][0] = 0;
        t[0][i] = 0;
    }

    //updation of table
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(str[i-1] == rev[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1]; 
            }

            else
            {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
            
        }
    }
    //length of longest pallindromic subsequence
    //is t[n][n]
// so minimum deletion is equal to n- lps
return n- t[n][n];
}



int main() 
{ 
    string str = "geeksforgeeks"; 
    cout << "Minimum number of insertions = "
         << minimumNumberOfDeletions(str); 
    return 0; 
} 
