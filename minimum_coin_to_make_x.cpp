/*
Given a value V, if we want to make change for V cents, 
and we have infinite supply of each of C = { C1, C2, .. , Cm}
valued coins, what is the minimum number of coins to make the change?

Examples:
Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents*/

/////////////////////////////////////////////////////////////////////////////////
//DP approach

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long
#define pb push_back

ll mincoins( ll coin[], ll n, ll sum)
{

    ll t[n+1][sum+1];//to store dp
    //initailization
    // when no(value) of coin is 0 and sum is anyting
    // we need INFINITE no of coins to get sum
    ll INF = INT_MAX - 1; //we add 1 for each included case later
    for(ll i=0; i<=sum; i++)
    {
        t[0][i] = INF;
    }

    //when reqd. sum is 0 we have 1 ways min possible always
    for(ll i=1; i<=n; i++)
    {
        t[i][0] = 1;
    } 

    //2nd row initilaization is as 1st has all infinity
    // when n=1; so coin[0] will fill only those sum which are
    // divisible by coin[0]
    for(ll j=1; j<=sum; j++)
    {
        if( j % coin[0] == 0)
        {
            t[1][j] =  j / coin[0]; //if only 1 coin is the case 1st one is that 
        }
        else
        {
            t[1][j] = INF;
        }
    } 

    //filling of remaining cells
    for(ll i=2; i<=n; i++)
    {
        for(ll j=1 ; j<=sum; j++ )
        {
            if(j >= coin[i-1]) //// for this case two chice either choose it or not
            {
                //        selected                   // not selected
                t[i][j] = min(t[i][j-coin[i-1]] + 1 , t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i][j-1]; ///we cant select this
            }
            
        }
    }
return t[n][sum];
}


int main() 
{ 
    ll coin[] =  {25, 10, 5}; 
    ll n = sizeof(coin)/sizeof(coin[0]); 
    ll V = 15;

    cout << "Minimum coins required is "
         << mincoins(coin, n, V); 
    return 0; 
} 



///////
//OUTPUT = Minimum coins required is 2
