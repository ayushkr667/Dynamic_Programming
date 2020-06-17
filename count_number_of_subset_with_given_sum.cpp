#include<bits/stdc++.h>
using namespace std;

int find_cnt(int arr[], int n, int sum)
{
    int t[n+1][sum+1];

    //if sum=0 1 subset possible null
    for(int i=0; i<=n; i++)
        t[i][0]=1;

    //if n=0, there are no sum possible except sum 0
    for(int i=1; i<=sum; i++)
        t[0][i]=0;

    //fill the remaining table
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            //if sum< array value
            if(j < arr[i-1])
                t[i][j]= t[i-1][j];

            else
            {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
            
        }
    }
return t[n][sum];
}


int main()
{
    int arr[] = { 3, 3, 3, 3, 3 }; 
    int sum = 15; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << find_cnt(arr, n, sum)<<"\n";
}