#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define N 1001
int dp[N][N];

int myMax(int a , int b){
    return a > b ? a : b;
}

int maxThree(int a, int b, int c){
    if( a > b && a > c)
        return a;
    else if(b > a && b > c)
        return b;
    else
        return c;
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        cout<<"Inside function"<<endl;

        for(int i = 0;i < N;i++)
            for(int j = 0; j < N;j++)
                dp[i][j]  = 0;

        int n = text1.length();
        int m = text2.length();

        //Defining elements in the 0th row
        for(int j = 0;j < m;j++){
            if(text1[0] == text2[j])
                dp[0][j] = 1;
            else{
                if(j != 0 )
                    dp[0][j] = dp[0][j-1];
                else
                    dp[0][j] = 0;
            }
        }
        cout<<"Defined 0th row elements"<<endl;
        //Defining elements in the 0th column
        for(int i = 1;i < n;i++){
            if(text1[i] == text2[0])
                dp[i][0] = 1;
            else{
                dp[i][0] = dp[i-1][0];
            }
        }
        cout<<"Defined 0th column elements"<<endl;

        for(int i = 1; i < n;i++){
            for(int j = 1;j < m;j++){
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = myMax(dp[i-1][j],dp[i][j-1]);

                if(text1[i] == text2[j])
                    cout<<"i : "<<i<<" j : "<<j<<" : Letter : "<<text1[i]<<" dp[i][j]: "<<dp[i][j]<<endl;
            }

        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        return dp[n-1][m-1];
    }
};

int main(){
    Solution s;
    string text1 = "kvwrkharmnqpwxyhejgvybifmncdorglsfqlidupyvcnypwvglormj";
    string text2 = "irmdqnwnelyturkdobypezwvonqpubedetansrkjgzyzgpuxajgdaji";
    cout<<text1<<endl;
    cout<<text2<<endl;

    cout<<"Before calling function"<<endl;
    s.longestCommonSubsequence(text1,text2);
}


