#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main9(){
    ListNode x = ListNode(5);
    cout<<x.val<<endl;
}
