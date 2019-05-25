//
// Created by xuyou on 19-4-24.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode*prehead=NULL,*nexttail=head;
    if(m>1){
        prehead=head;
        for(int i=0;i<m-2;i++)
            prehead=prehead->next;
    }
    for(int i=0;i<n;i++)
        nexttail=nexttail->next;
    if(n-m<1)
        return head;

    ListNode *pre;
    if(prehead)
        pre=prehead->next;
    else
        pre=head;
    ListNode*cur=pre->next,*ntail=pre;
    ListNode*nxt;
    for(int i=0;i<n-m-1;i++){
        nxt=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
        if(nxt)
            nxt=nxt->next;
    }
    cur->next=pre;
    if(prehead)
        prehead->next=cur;
    ntail->next=nexttail;
    if(m>1)
        return head;
    else
        return cur;
}
int main(){
    ListNode*head=new ListNode(1);
    ListNode*tail=head;
    for(int i=2;i<=5;i++){
        ListNode*h=new ListNode(i);
        tail->next=h;
        tail=h;
    }
    ListNode*a=new ListNode(3);
    ListNode *b=new ListNode(5);
    a->next=b;
    ListNode*ret=reverseBetween(a,1,2);
    return 0;
}
