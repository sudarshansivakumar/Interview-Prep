#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int lengthLL(ListNode *head){
    int count = 0;
    ListNode *trav = head;

    while(trav != NULL){
        count++;
        trav = trav->next;
    }
    return count;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lengthLL(head);
        int remIndex = len - n + 1;
        int i = 1;
        ListNode *prev = NULL,*curr = head,*after = head->next;

        while(i != remIndex){
            i++;
            prev = curr;
            curr = curr->next;
            after = after->next;
        }
        if(prev == NULL && after == NULL)
            head = NULL;
        else if(prev == NULL){
            head = head->next;
        }
        else if(after == NULL){
            prev->next = NULL;
        }
        else{
            prev->next = after;
        }
        return head;
    }
};

void printLL(ListNode *ll){
    while(ll != NULL){
        cout<<ll->val<<'\t';
        ll = ll->next;
    }
    cout<<endl;
}


int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);

    l1->next = l2;l2->next = l3;l3->next = l4;l4->next = l5;
    printLL(l1);

    Solution s;
    l1 = s.removeNthFromEnd(l1,2);

    printLL(l1);


}
