#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
    Node(){
        data = 0;
    }
    Node(int x){
        data = x;
    }


};
class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        int currCarry = 0;
        int currSum = 0;
        Node *l3, *ans;

        //Initialising the first node

        currSum = l1->data + l2->data + currCarry;
        currCarry = currSum/10;
        currSum = currSum %10;
        l3 = new Node(currSum);
        ans = l3;
        //cout<<l3->data<<'\t';
        l1 = l1->next;
        l2 = l2->next;

        while(l1 != NULL && l2 != NULL){
            currSum = l1->data + l2->data + currCarry;
            currCarry = currSum/10;
            currSum = currSum % 10;
            l3->next = new Node(currSum);
            l3 = l3->next;
            //cout<<l3->data<<'\t';
            l1 = l1->next;
            l2 = l2->next;
        }
        if( l1 != NULL){
            while(l1 != NULL){
                currSum = l1->data + currCarry;
                currCarry = currSum/10;
                currSum = currSum % 10;
                l3->next = new Node(currSum);
                l3 = l3->next;
                //cout<<l3->data<<'\t';
                l1 = l1->next;
            }
        }
        else if(l2 != NULL){
            while(l2 != NULL){
                currSum = l2->data + currCarry;
                currCarry = currSum/10;
                currSum = currSum % 10;
                l3->next = new Node(currSum);
                l3 = l3->next;
                //cout<<l3->data<<'\t';
                l2 = l2->next;
            }
        }
        if(currCarry != 0){
            l3->next = new Node(currCarry);
            //cout<<l3->data<<'\t';
        }
        //cout<<endl;
        return ans;
    }
};
void printLL(Node *ll){
    while(ll != NULL){
        cout<<ll->data<<'\t';
        ll = ll->next;
    }
    cout<<endl;
}

int main(){

    Node *l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    Node *l2 = new Node(5);
    l2->next = new Node(6);
    //l2->next->next = new Node(4);
    //342 + 65 = 407

    Solution s;
    Node *l3;

    cout<<"First linked list"<<endl;
    printLL(l1);

    cout<<"Second linked list"<<endl;
    printLL(l2);



    l3 = s.addTwoNumbers(l1,l2);
    cout<<"Linked list obtained by adding the two numbers"<<endl;
    printLL(l3);

    //cout<<"Answer : "<<l3->data<<"->"<<l3->next->data<<"->"<<l3->next->next->data;

}

