#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string>ans;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        generateParanth(n,n);
        return ans;
    }
}

void generateParanth(string current, int open,int close){
    string s1,s2;
    if(close == 0){
        ans.push_back(current);
        return;
    }
    if(open < close){
        if(open == 0){
            current.push_back(')');
            generateParanth(current, open, close - 1);
        }
        else{
            s1 = s2 = current;
            s1.push_back('(');
            s2.push_back(')');
            generateParanth(s1,open - 1,close);
            generateParanth(s2,open,close - 1);
        }
    }
    else if(open == close){
        current.push_back('(');
        generateParanth(current,open - 1, close);
    }

}
