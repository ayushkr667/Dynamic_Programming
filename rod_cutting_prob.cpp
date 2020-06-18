/*
Given a rod of length n inches and an array of prices that contains prices of all pieces
of size smaller than n. Determine the maximum value obtainable by cutting up the rod and
selling the pieces. For example, if length of the rod is 8 and the values of different
pieces are given as following, then the maximum obtainable value is 22 
(by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 
(by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

*/

///////////////////////////////////////////////////////////////////////////////////////////
//dp approach using unbounden knapsack

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

#define ll long long
#define pb push_back

ll cutrod(ll price[], ll n) 
{ 
   ll val[n+1]; 
   val[0] = 0; 
   ll i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       ll max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]);

       val[i] = max_val; 
   } 
  
   return val[n]; 
} 



int main() 
{ 
    ll arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    ll size = sizeof(arr)/sizeof(arr[0]); 
    cout<<cutrod(arr, size); 
    return 0; 
} 