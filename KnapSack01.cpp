#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int myMax(int a,int b){
    a > b ? a: b;
}
#define N 300
int solve(vector<int>& weights, vector<int>& values, int capacity) {
    int dp[N][N];
    //Defining 0th column - when total weight is 0 all amounts will be 0
    for(int i = 0;i < weights.size();i++)
        dp[i][0] = 0;

    //Defining 0th row - when total amount is less than weight of first item the answer will be 0, otherwise the answer = value[0th item]
    for(int j = 0; j <= capacity;j++){
        if(weights[0] > j)
            dp[0][j] = 0;
        else
            dp[0][j] = values[0];
    }

    //Traversing through the entire dp table
    for(int i = 1;i < weights.size();i++){
        for(int j = 1;j <= capacity;j++){
            if(j - weights[i] >= 0){
                dp[i][j] = myMax(dp[i-1][j - weights[i]] + values[i], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[weights.size() - 1][capacity];
}
