/********************
*             __    *
*   OHM   |__|__    *
*          __|  |   *
*                   *
*********************/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF (ll) 1e18
const double PI = 3.141592653589793238460;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
double dp[3000][3000];
long double solve( int  n, long double h[])
{
    dp[0][0] = (long double)1; //0 head with 0 coin
    for (int i = 1; i <=n ; i++)// i represents no of coin
    {
        for (int j = 0; j <=n ; j++)//j represtent no of head
        {
            if(j == 0)
                dp[i][j] = (1.0 - h[i]) * (dp[i-1][j]);//all tails
            
            else
            {
                        //i th is head        //i th is tail 
                dp[i][j] = (h[i]*dp[i-1][j-1]) + ((1.0-h[i])*dp[i-1][j]);
            }
            
        }
        
    }
    int reqd_h = n/2+1; long double res = 0.0;
    for (int i = reqd_h; i <= n; i++)
    {
        res+=dp[n][i];
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;  cin>>n;
    memset(dp, 0, sizeof(dp));
    long double h[n+1]; //probability of head
    for (int i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    cout<< fixed << setprecision(10)<< solve(n, h);
    return 0;
}
