#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

#define N 301
#define M 5001

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[N][M];
        //Defining 0th column - the number of ways of getting the amount 0 is always 1 no matter how many elements you include
        for(int i = 0;i <=coins.size();i++)
             dp[i][0] = 1;

        //Defining 0th row - the number of ways of getting the amounts when there is no item is 0
        for(int j = 1;j <= amount;j++)
            dp[0][j] = 0;

        //Defining answers for the rest of the table
        for(int i = 1;i <= coins.size(); i++){
            for(int j = 1;j <= amount;j++){
                if(j - coins[i-1] >= 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};
