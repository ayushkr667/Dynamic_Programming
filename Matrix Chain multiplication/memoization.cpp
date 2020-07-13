/*Given an array p[] which represents the chain of matrices such
that the ith matrix Ai is of dimension p[i-1] x p[i].
We need to write a function MatrixChainOrder() that should return
the minimum number of multiplications needed to multiply the chain.

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
*/
////////////////////////////////////////////////////////////////////////
//Recursive Memoized version 
#include<bits/stdc++.h>
using namespace std;

int t[10001][10001];
int matrixchain(int arr[], int i, int j)
{
    //base case array is sub parted in two only tiil i<j
    if( i >= j )
    {
        return 0;
    }

    //check if function is called with same i and j previously
    if( t[i][j] != -1)
    {
        return t[i][j];
    }

    int k;// used in sub part the array to set j value
    int min = INT_MAX; // store minimum value 

    //sub part int i to k and k+1 to j
    for (k = i; k <= j-1; k++) 
    { 
        //add temporary return with multiplication cost of both
        // i.e arr[i-1]* arr[k] * arr[j]
        int count = matrixchain( arr, i, k) + matrixchain( arr, k + 1, j) + 
                arr[i - 1] * arr[k] * arr[j];

        //update the minimum
        if (count < min) 
            min = count; 
    } 
    //store calculated value
    t[i][j] = min;
    // Return minimum 
    return t[i][j]; 
}


int main() 
{ 
    memset(t, -1, sizeof(t));
    int arr[] = {40, 20, 30, 10, 30}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << matrixchain(arr, 1, n - 1); // i= 1, j= n-1;
} 