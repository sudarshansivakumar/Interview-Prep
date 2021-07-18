#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int myMax(int a, int b){
    a > b ? a : b;
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = 3000;
        int maxSub[N], longSubSeq = 1;
        for(int i = 0;i < N;i++)
            maxSub[i] = 1;

        int n = nums.size();
        for(int i  = n-1; i >= 0 ;i--){
            for(int j = i + 1;j < n;j++){
                if(nums[j] > nums[i])
                    maxSub[i] = myMax(maxSub[i], 1 + maxSub[j]);
            }
            if(maxSub[i] > longSubSeq)
                longSubSeq = maxSub[i];
        }
        return longSubSeq;
    }

};
