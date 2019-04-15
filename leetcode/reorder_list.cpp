//
// Created by xuyou on 19-4-14.
//
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL) {}
};
ListNode* reverse(ListNode*);
ListNode* reorderList1(ListNode* head) {
    if(head==NULL||head->next==NULL||head->next->next==NULL)
        return head;
    ListNode* tail=head,*nexthead=head->next;
    while(tail->next->next)
        tail=tail->next;
    head->next=tail->next;
    tail->next=NULL;
    head->next->next=reorderList1(nexthead);
    return head;
}
void reorderList(ListNode*head){
    head=reorderList1(head);
}

ListNode* reverse(ListNode*h){
    if(h==NULL||h->next==NULL)
        return h;
    ListNode*n=h->next,*nn,*cur=h;
    if(n->next){
        nn=n->next;
    } else{
        n->next=cur;
        cur->next=NULL;
        return n;
    }
    while(nn->next){
        n->next=cur;
        cur=n;
        n=nn;
        nn=nn->next;
    }
    n->next=cur;
    h->next=NULL;
    nn->next=n;
    return nn;
}
void reorderList2(ListNode*head) {
    if (head == NULL||head->next==NULL)
        return;
    int lens = 0;
    ListNode*tail=head;
    while (tail!=NULL){
        lens++;
        tail=tail->next;
    }
    ListNode*reversehead=head;
    for(int i=0;i<(lens+1)/2;i++)
        reversehead=reversehead->next;
    reversehead=reverse(reversehead);
    tail=head;
    ListNode *nt,*nh;
    while(tail->next&&reversehead->next){
        nt=tail->next;
        nh=reversehead->next;
        tail->next=reversehead;
        reversehead->next=nt;
        tail=nt;
        reversehead=nh;
    }
    if(!tail->next&&!reversehead->next) {
        tail->next = reversehead;
        reversehead->next=NULL;
    }
    else{
        nt=tail->next;
        tail->next=reversehead;
        reversehead->next=nt;
        nt->next=NULL;
    }
}
int main(){
    ListNode*h=new ListNode(1),*tail=h;
    for(int i=2;i<=8;i++){
        ListNode*t=new ListNode(i);
        tail->next=t;
        tail=t;
    }
    reorderList2(h);
    return 0;
}