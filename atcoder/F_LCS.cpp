/*-------------------------------*
| Name: Ayush Kumar              |
| Site: CSES                     |
| Email: ayushkr667@gmail.com    |
*-------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF (ll) 1e18
const double PI = 3.141592653589793238460;
string s1, s2;
int dp[3001][3001];

void solve(int l1, int l2)
{
    //if l1 or l2 =0 it is already initialized with 0
    for (ll i = 1; i <= l1 ; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if( s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
                dp[i][j] =  max( dp[i][j-1], dp[i-1][j] );
        }    
    }
}

void lcs(int l1, int l2)
{
    string result ="";
    while (l1 > 0 && l2 > 0)
    {
        if( s1[l1-1] == s2[l2-1] )
        {
            result.pb(s1[l1-1]);
            l1--, l2--;
        }
        else
        {
            if(dp[l1-1][l2] > dp[l1][l2-1])
            {
                l1--;
            }
            else
            {
                l2--;
            }  
        }
    }
    reverse(result.begin(), result.end());
    cout<<result;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin>>s1>>s2;
    int l1 = s1.size();
    int l2 = s2.size();
    solve(l1, l2);
    lcs(l1, l2);
    return 0;
}
