#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define N 1000
int minThree(int a, int b, int c){
    if(a < b && a < c)
        return a;
    else if( b < a && b < c)
        return b;
    else
        return c;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[N][N];
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                dp[i][j] = 0;

        int n = word1.length();
        int m = word2.length();

        //Word1 -> Word2 conversion, Word1 is along the rows, Word2 is along the columns

        //Defining 0th row - empty string converted to word 2 using insertions
        for(int j = 0;j <=m;j++)
            dp[0][j] = j;

        //Defining 0th column - word1 slowly converted to empty string, using deletions
        for(int i = 1; i <= n;i++)
            dp[i][0] = i;

        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= m;j++){
                if(word1[i - 1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + minThree(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
