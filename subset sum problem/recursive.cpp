#include<bits/stdc++.h>
using namespace std;

bool issubsetsum(int arr[], int n, int sum)
{
    if(sum==0)
        return true;
    if(sum!=0 && n ==0)
        return false;
    else
    {
        //not included in subset for sure
        if(arr[n-1]>sum)
            return issubsetsum( arr, n-1, sum);

        else//either include or not
        {
            return issubsetsum(arr, n-1, sum-arr[n-1])
                || issubsetsum(arr, n-1, sum);
        }
        
    } 
}


int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 13; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (issubsetsum(arr, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 

    return 0;
}
