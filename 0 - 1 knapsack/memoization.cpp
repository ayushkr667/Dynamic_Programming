//memorization method
//dp technique
//Time Complexity: O(N*W).
//Auxiliary Space: O(N*W).

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int knapsack_recursive(int w, int wt[], int val[],
                                int i, int** memory)
{
    if(i==0 || w==0)
        return 0;
    if(memory[i][w] != -1)
        return memory[i][w];

    if(wt[i] > w)
    {
    memory[i][w]= knapsack_recursive(w, wt, val, i-1, memory);
    return memory[i][w];
    }

    else
    {
    memory[i][w] = max(val[i] + knapsack_recursive(w-wt[i],wt, val, i-1, memory),
        knapsack_recursive(w, wt, val, i-1, memory));
    return memory[i][w]; 
    }
    
    

}


int knapsack(int w, int wt[], int val[], int n)
{
    int** memory;
    memory = new int*[n+1];

    for(int  i=0; i<n+1; i++)
    {
        memory[i] = new int[w+1];
    }

    //fill all with -1
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<w+1; j++)
        {
            memory[i][j]= -1;
        }
    }
    return knapsack_recursive(w, wt, val, n-1, memory);

}
int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {1, 1, 1};
    int w=2;
    int n=3;
    cout<<knapsack(w, wt, val, n);
    return 0;
}