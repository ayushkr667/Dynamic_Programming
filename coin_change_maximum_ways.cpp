/*
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} 
valued coins, how many ways can we make the change? The order 
of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions:
{1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10
and S = {2, 5, 3, 6}, there are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.*/

///////////////////////////////////////////////////////////////////////////////////
//Dp approach

#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define pb push_back


ll count(ll arr[], ll m, int sum)
{
//table to store dp
ll t[m+1][sum+1];
//initialization of dp
//if sum = 0 ; there is always 1 possible value
for(ll j=0; j<=m; j++)
{
    t[j][0] = 1;
}

//if m = 0 ; there is not possible any sum except 0
for(ll i=1; i<=sum; i++)
{
    t[0][i] = 0;
}

for(ll i=1; i<=m; i++)
{
    for(ll j=1; j<=sum; j++)
    {
        if(j >= arr[i-1])
        {
            t[i][j] = t[i][j - arr[i-1]] + t[i-1][j];
        }
        else
        {
            t[i][j] =  t[i-1][j];
        }
        
    }
}
return t[m][sum];
}


using namespace std;
int main() 
{ 

    ll arr[] = {2, 5, 3, 6}; 
    ll m = sizeof(arr)/sizeof(arr[0]); 

    cout<< count(arr, m, 10); 
    return 0; 
} 


///////////////////////////////////
//OUTPUT = 5;
