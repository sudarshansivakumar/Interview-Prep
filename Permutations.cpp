#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int> >ans;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        vector<int>curr;
        permutations(curr,nums,n);
        return ans;
    }
};
void permutations(vector<int> current, vector<int> remaining, int n){
    vector<int>v1,v2;
    if(current.size() == n){
        ans.push_back(current);
        return;
    }
    for(int i = 0;i < remaining.size();i++){
        v1 = current;
        v1.push_back(remaining[i]);
        v2 = remaining;
        for(int j = i; j < remaining.size() - 1;j++){
            v2[j] = v2[j+1];
        }
        v2.pop_back();
        permute(v1,v2,n);
    }

}
int main(){
    vector<int>a,b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    permute(a,b,4);
}
