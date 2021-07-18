#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<pair>

using namespace std;

int myBinSearch(vector< pair<int,int> > v, int searchEle,int low, int high){
    if( low > high)
        return -1;
    int mid = (low + high)/2;
    if(v[mid].first == searchEle)
        return mid;
    else if(v[mid].first > searchEle)
        return myBinSearch(v,searchEle,low,mid-1);
    else
        return myBinSearch(v,searchEle,mid+1,high);

}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int,int> > v;
        vector<int>ans;
        int searchEle, n = nums.size(),index;
        for(int i = 0;i < nums.size();i++)
            v.push_back(make_pair(nums[i],i));

        sort(v.begin(),v.end());

        for (pair<int, int>& x : v)
            cout << x.first << '\t' << x.second << endl;

        for(int i = 0;i < v.size(); i++){
            searchEle = target - v[i];
            index = myBinSearch(v,searchEle,0,n-1);
            ans.push_back(i);
            ans.push_back(index);
        }
        return ans;
    }
};
