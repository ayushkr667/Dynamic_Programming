//Time Complexity = O(n*sum) 
// s1 and s2 are two subsets
// range= sum of all elements of array
// now we have to minimese range-(2*s1)
//s1 is minimum of two subset
//so we will make table of range+1 but
//will check only for range/2

#include<bits/stdc++.h>
using namespace std;

int find_min(int arr[], int n)
{
    int range = 0;
    //sum of all elements of array is range
    for(int i=0; i<n; i++)
        range+=arr[i];

    //table matrix to store dp
    bool t[n+1][range+1];

    //if range or sum of subset = 0, true
    for(int i=0; i<=n; i++)
        t[i][0] = true;

    //if n=0; nand sum != 0 not possible any sum
    for(int i=0; i<=range; i++)
        t[0][i] = false;

    //fill remaining table
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=range; j++)
        {
            //if j or sum is lesser than array value
            if(j < arr[i-1])
                t[i][j] = t[i-1][j];

            else
            {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }   
        }
    }
    ///in above table t[n][0,range] will give all possible
    //subset sum in given range when all array is in function
    //vector to store 
    int diff = INT_MAX;
    //we will check only in half range to 
    //so that diff will not occur negative
    for(int i= range/2; i>=0; i--)
    {
        //if table value is true from last
        if(t[n][i])
        {
            diff = range-(2*i);
            break;
        }
    }
    return diff;
}


int main() 
{ 
    int arr[] = {3, 1, 4, 2, 2, 1}; 
    //int arr[] = {3,5,7,4};
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "The minimum difference between 2 sets is "
         << find_min(arr, n); 
    return 0; 
} 