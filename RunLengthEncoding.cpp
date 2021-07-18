#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string convDecToStr(int cnt){
    string strRev,str;
    int dup = cnt,n = 0;
    while(dup > 0){
        n++;
        dup = dup/10;
    }
    while(cnt > 0){
        strRev.push_back('0' + cnt%10);
        cnt = cnt/10;
    }
    for(int i = 0;i < n;i++){
        str.push_back(strRev[n-i-1]);
    }

    return str;
}
int main(){
    string s,runLength,countStr;
    cin>>s;
    int n = s.size(),currCount = 0;

    for(int i = 0;i < n;i++){
        currCount++;
        if( i != n-1){
            while(s[i] == s[i+1]){
                currCount++;
                i++;
                if(i == n-1)
                    break;
            }
        }
        countStr = convDecToStr(currCount);
        runLength+=countStr;
        runLength.push_back(s[i]);
        currCount = 0;
    }
    cout<<runLength;

    /*countStr = convDecToStr(976);
    cout<<"Converted String is "<<countStr;*/

}
