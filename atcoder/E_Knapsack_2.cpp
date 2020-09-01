/*-------------------------------*
| Name: Ayush Kumar              |
| Site: atcoder                  |
| Email: ayushkr667@gmail.com    |
*-------------------------------*/

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
#define mod 1000000007
#define ll long long 
 
ll n,w, weigh[100001], val[100001];
ll dp[101][100001];
 
ll solve(int r, int idx) 
{
    if(idx > n)
        return r == 0 ? 0 : INT_MAX;
 
    if(dp[idx][r] != -1)
    	return dp[idx][r];
 
    ll ans = solve(r, idx + 1);
    if(val[idx] <= r)
    	ans = min(ans, weigh[idx] + solve(r - val[idx], idx + 1));
 
    return dp[idx][r] = ans;
}
 
int Ans(int v_max) 
{
 
	for(int i = v_max; i >= 0; i--) 
    {
		if(solve(i, 1) <= w)
			return i;
	}
	return 0;
}
 
int main() 
{
 
    cin>>n>>w;
    memset(dp, -1, sizeof(dp));
 
    int max_value = 0;
 
    for(int i = 1; i <= n; i++) 
    {
        cin>>weigh[i]>>val[i];
        max_value += val[i];
    }
    cout<<Ans(max_value);
}