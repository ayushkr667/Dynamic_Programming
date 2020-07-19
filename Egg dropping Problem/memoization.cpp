/*
Problem statement: You are given N floor and K eggs.
You have to minimize the number of times you have to drop the eggs
to find the critical floor where critical floor means the floor 
beyond which eggs start to break. Assumptions of the problem:

If egg breaks at ith floor then it also breaks at all greater floors.
If egg does not break at ith floor then it does not break at all lower floors.
Unbroken egg can be used again.
Note: You have to find minimum trials required to find the critical floor not 
the critical floor.

Example:
Input:
    4
    2
    
Output:
Number of trials when number of eggs is 2 and number of floors is 4: 3
For the Input 1,

Case 1. Drop at first floor:

Egg does not break:
If egg does not break then we have three floors left and two eggs. 
We can either choose 2nd or 3rd floor and proceed similarly but we 
can easily see we have to do atleast 3 trials.
Egg breaks:
If egg breaks then we found the critical floor in only 1 trial.
In case 1, the worst possibility is that egg does not break 
so trials will be 3 for case 1*/
/////////////////////////////////////////////////////////////////////
//Memoization Approach
#include<bits/stdc++.h>
using namespace std;

int t[100][3000]; //t[egg][floor]
int solve(int e, int f)
{
    //base case
    //if number of floor is 1 or 0 same floor wii be answer
    if( f == 1 || f == 0)
        return f;

    //if egg = 1 we have to check from base floor to k th floor
    if( e == 1)
        return f;

    //check in table if it is present
    if( t[e][f] != -1)
        return t[e][f];
    
    int result  = INT_MAX;//minimum no. of trials

    for(int k  = 1; k<=f; k++)
    {
        //1  for that try if it is broken, we  have to check k-1 floors with
        //remaining e-1 eggs
        //otherwise, f-k floors would be checked by e, eggs
        int temp = 1 + max( solve(e-1, k-1), solve(e, f-k));
        result = min( result, temp);
    }
    t[e][f] = result;
    return t[e][f];
}

int main()
{
    //initalize table with -1
    memset( t, -1, sizeof(t));
    int floor = 4;
    int egg = 2;
    cout<<"Number of trials when number of eggs is ";
    cout<<egg<<" and number of floors is "<<floor<<" : ";
    cout<<solve(egg, floor);
}
