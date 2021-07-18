#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int max(int a,int b){
    return (a > b) ? a : b;
}

string revString(string a){
    string ans;

    int n = a.length();
    for(int i = n-1;i >= 0;i--){
        ans.push_back(a[i]);
    }
    return ans;
}
string solve(string a, string b){
    string ans,c;
    int l1 = a.length();
    int l2 = b.length();
    int n,currCarry = 0,currSum = 0;
    n = max(l1,l2);

    if(l1 > l2){
        for(int i = 0;i < (l1 - l2);i++){
            c.push_back('0');
        }
        b.insert(0,c);
    }
    else if(l2 > l1){
        for(int i = 0;i < (l2 - l1);i++){
            c.push_back('0');
        }
        a.insert(0,c);
    }
    for(int i = n; i >= 1;i--){
        currSum = (a[i-1] - '0') + (b[i-1] - '0') + currCarry;
        if(currSum == 2){
            ans.push_back('0');
            currCarry = 1;
        }
        else if(currSum == 3){
            ans.push_back('1');
            currCarry = 1;
        }
        else{
            ans.push_back('0' + currSum);
            currCarry = 0;
        }
    }
    ans.push_back('0' + currCarry);
    cout<<"Ans before erase : "<<ans<<endl;
    if(currCarry == 0){
        ans[ans.length() - 1]  = '\0';
        ans.erase(ans.end()-1);
    }
    cout<<"Ans after erase,before reverse : "<<ans<<endl;
    ans = revString(ans);

    cout<<"String 1 : "<<a<<endl;
    cout<<"String 2 : "<<b<<endl;
    return ans;
}

int main(){
    string x,y,ans;
    cout<<"Enter string 1 :"<<endl;
    cin>>x;
    cout<<"Enter string 2 :"<<endl;
    cin>>y;

    ans = solve(x,y);

    cout<<"The addition of the two binary digits gives :"<<ans;
}
