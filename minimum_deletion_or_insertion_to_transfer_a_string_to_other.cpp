/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
The task is to remove/delete and insert minimum number of 
characters from/in str1 so as to transform it into str2.
It could be possible that the same character needs to be 
removed/deleted from one point of str1 and inserted to some another point.

Examples:

Input : str1 = "heap", str2 = "pea" 
Output : Minimum Deletion = 2 and
         Minimum Insertion = 1
p and h deleted from heap Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.

Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0  */

/////////////////////////////////////////////////////////////////
//DP_approach
#include<bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int m, int n)
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
            if (str1[j-1] == str2[i-1])
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




void print_result(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    int length_of_lcs = LCS(str1, str2, m, n);
    cout<<length_of_lcs<<"\n";

    cout<< "number of deletion is "<<m-length_of_lcs<<"\n";
    cout<< "number of insertion is "<<n-length_of_lcs<<"\n";

}


int main() 
{ 
  string str1 = "heap"; 
  string str2 = "pea";   
  print_result(str1, str2);  
  return 0; 
}  
