/*
    Given a list of numbers nums and a number k, return whether any two elements from the list add up to k. You may not use the same element twice.

    Note: Numbers can be negative or 0.
*/


#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int v,n,k,isFound = 0, startInd = -1,endInd = -1,searchEle,index;
    vector<int>arr;

    //cout<<"Enter the number of elements in the array";
    cin>>n;
    //cout<<"Enter the elements in the array"<<endl;

    for(int i = 0;i < n;i++){
        cin>>v;
        arr.push_back(v);
    }
    //cout<<"Enter the number k to check whether any 2 elements in the  array add up to k";
    cin>>k;

    sort(arr.begin(),arr.end());

    /*
        printing the array
        for(int i = 0;i < n;i++){
        cout<<arr[i]<<"\t";
        }
    */

    for(int i = 0; i < n; i++){
        searchEle = k - arr[i];
        index = lower_bound(arr.begin(),arr.end(),searchEle) - arr.begin();

        //Element found
        if(arr[index] == searchEle && index != i){
            isFound = 1;
            startInd = i;
            endInd = index;
            //cout<<arr[startInd]<<" + "<<arr[endInd]<<" = "<<k;
            cout<<"true"<<endl;
            break;
        }
    }
    if(isFound == 0){
        //cout<<"There are no two elements in the array which add up to "<<k<<endl;;
        cout<<"false"<<endl;
    }


}

