//Time Complexity: O(sum*n),
//Auxiliary Space: O(sum*n)

#include<bits/stdc++.h>
using namespace std;

bool issubsetsum(int arr[], int n, int sum)
{
    bool t[n+1][sum+1];
    //initialization of matrix
    //if sum=0 mark all true
    for(int i=0; i<=n; i++)
        t[i][0]=true;
    
    //if sum!=0 and n=0 mark all false
    for(int i=1; i<=sum; i++)
        t[0][i]=false;

    //fill the table
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)//j is remaining sum
        {
            if(j < arr[i-1])
                t[i][j] = t[i-1][j];
            else
            {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }
    }
return t[n][sum];
}


int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 14; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (issubsetsum(arr, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
}
