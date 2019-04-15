//
// Created by xuyou on 19-3-31.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL) {}

};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val<l2->val){
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    } else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }

}
ListNode* reverseList1(ListNode* head) {
    ListNode *nhead=NULL,*cur;
    if(head->next==NULL)
        return head;
    if(head)
        nhead=reverseList1(head->next);
    cur=nhead;
    head->next=NULL;
    while(cur->next){
        cur=cur->next;
    }
    cur->next=head;
    return nhead;
}
ListNode* reverseList(ListNode* head) {
    if(!head||!head->next)
        return head;
    ListNode *cur=head,*n=head->next,*nn=n->next;
    head->next=NULL;
    while (nn){
        n->next=cur;
        cur=n;
        n=nn;
        nn=n->next;
    }
    n->next=cur;
    return n;
}
void print_list(ListNode*l){
    ListNode*c=l;
    while (c){
        cout<<c->val;
        c=c->next;
    }
}
int main(){
    ListNode*h1=new ListNode(5);
    ListNode*h2=new ListNode(7);
    h1->next=h2;
    h2->next=new ListNode(8);
    //ListNode *res=mergeTwoLists(h1,h2);
    ListNode *res=reverseList(h1);
    print_list(res);
    return 0;
}