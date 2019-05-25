//
// Created by xuyou on 19-4-24.
//
#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

    bool hasCycle(ListNode *head) {
        ListNode*first=head,*second=head;
        if(!first)
            return false;
        while(second){
            second=second->next;
            if(!second)
                return false;
            second=second->next;
            if(!second)
                return false;
            first=first->next;
            if(first==second)
                return true;

        }
        return true;
    }
ListNode *detectCycle(ListNode *head) {
    ListNode*first=head,*second=head;
    ListNode*third=head;
    if(!first)
        return NULL;
    int flag=0;
    while(second){
        second=second->next;
        if(!second)
            return NULL;
        second=second->next;
        if(!second)
            return NULL;
        if(flag)
            third=third->next;
        first=first->next;
        if(first==second){
            flag=1;
        }
        if(first==third)
            return first;
    }
    return NULL;
}
int main(){
    ListNode*a=new ListNode(3);
    ListNode *b=new ListNode(5);
    a->next=b;
    int ret=hasCycle(a);
    return 0;
}
