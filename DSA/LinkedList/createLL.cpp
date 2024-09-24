#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data=data1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};
// Print a Head
Node* covertArrToLL(vector<int> &arr){
    Node*head=new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void traverseLL(Node*head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int LengthOfLL(Node*head){
    int cnt=0;
    Node*temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
bool checkValueIsPrestest(Node*head,int value){
    Node* mover=head;
    while(mover){
        int i=mover->data;
        if(i==value){
            return true;
        }
        mover=mover->next;
    }
    return false;
}
Node* deleteHead(Node*head){
    traverseLL(head);
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    Node*head=covertArrToLL(arr);
    traverseLL(head);
    // cout<<head->data<<endl;
    cout<<LengthOfLL(head)<<endl;
    string checkValue=checkValueIsPrestest(head,1)?"true":"false";
    cout<<checkValue<<endl;
    cout<<"Old head: "<<head->data<<endl;
    Node*newHead=deleteHead(head);
    traverseLL(newHead);
    cout<<"New head: "<<newHead->data<<endl;
}