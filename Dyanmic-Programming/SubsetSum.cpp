#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define M 20001
#define N 201

int TotalSum(vector<int>& nums){
    int n = a.size(),sum = 0;
    for(int i = 0;i < n;i++)
        sum+=nums[i];
    return sum;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int arraySum = TotalSum(nums);
        int n = nums.size(),currEle;
        bool dp[N][M];
        //If arraySum is odd you can't partition into 2 subsets with equal sum
        if(arraySum % 2 != 0)
            return false;

        //If arraySum is even we implement the dynamic programming solution to fill all possible subset sums

        //Initialise the 0th column as all true ( you can always get the sum 0 no matter how many elements are considered )
        for(int i = 0;i <= n;i++)
            dp[i][0] = true;

        //Initialise all elements in the 0th row except dp[0][0] to be false ( you can only get the sum 0 if you have 0 elements )
        for(int j = 1;j <= arraySum;j++)
            dp[0][j] = false;

        //Start filling all elements in the dp table
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= arraySum;j++){
                currEle = nums[i - 1];
                if(j - currEle >= 0)
                    dp[i][j] = dp[i-1][j - currEle] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][arraySum/2];
    }
};



