#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int N = 1001;
        int dp[N][N];
        int maxLength = 0, n = s.length(),i,j;
        string pal;

        //Initialising all the single letters as palindromes
        for(int i = 0; i < n;i++){
            dp[i][i] = 1;
            if(i == 0)
                pal = s.substr(0,1);
        }
        //Deciding if all the double letters are palindromes
        for(int i = 0,j = 1; j < n;i++,j++){
            if(s[j] == s[i]){
                dp[i][j] = 1;
                maxLength = 2;
                pal = s.substr(i,2);
            }

            else
                dp[i][j] = 0;
        }
        for(int diff = 2;diff < n;diff++){
            i = 0; j = diff;
            while(j < n){
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    maxLength = diff + 1;
                    pal = s.substr(i,maxLength);
                }
                i++;
                j++;
            }
        }
        return pal;
    }
};
