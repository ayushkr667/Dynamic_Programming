/*
Given a string, a partitioning of the string is a palindrome
partitioning if every substring of the partition is a palindrome.
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of
“ababbbabbababa”. Determine the fewest cuts needed for palindrome
partitioning of a given string. 
For example, minimum 3 cuts are needed for “ababbbabbababa”. 
The three cuts are “a|babbbab|b|ababa”. If a string is palindrome,
then minimum 0 cuts are needed. If a string of length n containing
all different characters, then minimum n-1 cuts are needed.
palindrome-partitioning*/
/////////////////////////////////////////////////////////////////////////
//Recursive Approach with Optmised memoized version
//
//basically when we call two function in for loop with different k
//it is possible they occured previously there we need to check .
#include<bits/stdc++.h>
using namespace std;

int  t[10001][10001]; //to store previous finded value corresponding to i j
int ispallindrome(string str, int i, int j)
{
    // Start from leftmost and rightmost corners of str 
    int l = i; 
    int h = j; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        {  
            return 0; 
        } 
    } 
    return 1;
}

int minpalpartion( string str, int i, int j)
{
    //base case array is sub parted in two only tiil i<j
    if( i >= j )
        return 0;

    
    //sub  given string is already pallindrome no partiotion needed
    if( ispallindrome(str, i, j) == 1)
        return 0;

    //check if corresponding to i j is calculated previously
    if( t[i][j] != -1)
        return t[i][j];

    int k;// used in sub part the array to set j value
    int min = INT_MAX; // store minimum value 

    //sub part int i to k and k+1 to j
    for (k = i; k <= j-1; k++) 
    { 
        //add temporary return with number of partition and add 1 for this partition
        //int count = minpalpartion( str, i, k) + minpalpartion( str, k + 1, j) + 1;
        int left_val, right_val, count;
        if( t[i][k] != -1)
            left_val = t[i][k];
        else
        {
            left_val = minpalpartion( str, i, k);
            t[i][k] = left_val;
        }

        if( t[k+1][j] != -1)
            right_val = t[k+1][j];
        else
        {
            right_val = minpalpartion (str, k+1, j);
            t[k+1][j] = right_val;
        }
        
        count = left_val + right_val + 1;
        //update the minimum
        if (count < min) 
        {
            min = count; 
        }
    } 
    t[i][j] = min;
    return min;
}


int main()  
{  
    memset(t, -1, sizeof(t) );
    string str = "ababbbabbababa";  
    //string str = "nitin";
    int n = str.size() ;
    cout<<"Min cuts needed for Palindrome Partitioning is "<<minpalpartion(str, 0, n-1);  
    return 0;  
}  

