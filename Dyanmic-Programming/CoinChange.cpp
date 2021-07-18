#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int MAX_NUM = 2147483647;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>minAmount;
        int currAmount, remains;
        for(int i = 0;i <=amount;i++)
            minAmount.push_back(MAX_NUM);

        for(int i = 0;i < coins.size();i++)
            minAmount[coins[i]] = 1;

        for(int i = 1; i <= amount;i++){
            //minAmount[i] = 1 + min( minAmount[i - coins[0]], minAmount[i - coins[1]], minAmount[i - coins[2]],.... minAmount[i - coins[n-1]])
            currAmount = minAmount[i];
            for(int j = 0;j < coins.size(); j++){
                remains = i - coins[j];
                if(remains > 0){
                   if(1 + minAmount[remains] < currAmount)
                    currAmount = 1 + minAmount[remains];
                }
            }
            minAmount[i] = currAmount;
        }
        if(amount == 0)
            return 0;

        else if(minAmount[amount] == MAX_NUM)
            return -1;
        else
            return minAmount[amount];
    }
};

int main(){
}
