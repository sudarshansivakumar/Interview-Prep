#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


int sortedStrCommon(string sorts1, string sorts2){
    int isCommon = 0;
    int l1 = sorts1.length();
    int l2 = sorts2.length();
    int i = 0,j = 0;
    while((i < l1) && (j < l2)){
        if(sorts1[i] == sorts2[j]){
            isCommon = 1;
            break;
        }
        else if(sorts1[i] < sorts2[j] ){
            i++;
        }
        else if(sorts2[j] < sorts1[i]){
            j++;
        }
    }
    return isCommon;
}

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), maxProd = 0,currProd = 0;
        //Sorting each word in the vector of strings
        for(int i = 0;i < n;i++){
            sort(words[i].begin(),words[i].end());
        }

        for(int i = 0;i < n-1;i++){
            for(int j = i+1; j < n;j++){
                if(sortedStrCommon(words[i],words[j]) == 0){
                    currProd = words[i].length() * words[j].length();
                    if(currProd > maxProd)
                        maxProd = currProd;
                }
            }
        }

        return maxProd;

    }
};

int main(){
    string s1 = "abcw";
    string s2 = "baz";
    string s3 = "foo";
    string s4 = "bar";
    string s5 = "xtfn";
    string s6 = "abcdef";

    vector<string>words;
    words.push_back(s1);
    words.push_back(s2);
    words.push_back(s3);
    words.push_back(s4);
    words.push_back(s5);
    words.push_back(s6);

    cout<<"Do "<<s1<<" and "<<s2<<"have a common letter "<<sortedStrCommon(s1,s2)<<endl;
    cout<<"Do "<<s1<<" and "<<s3<<" have a common letter "<<sortedStrCommon(s1,s3)<<endl;

    Solution s;
    cout<<"Maximum product in the given vector of strings is "<<s.maxProduct(words);


}
