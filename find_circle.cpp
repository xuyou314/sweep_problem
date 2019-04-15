//
// Created by xuyou on 19-2-26.
//
#include <stdlib.h>
#include <stdio.h>
#include "find_dup.h"
struct ListNode{
    int val;
    struct ListNode*next;
    ListNode(int x):val(x),next(NULL){

    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode*first,*second;
        first=second=pHead;
        first=first->next->next;
        second=second->next;
        if(!first||!second){
            return NULL;
        }
        while(first!=second){
            first=first->next;
            if(!first)
                return NULL;
            first=first->next;
            if(!first)
                return NULL;
            second=second->next;
        }
        second=pHead;
        while(first!=second){
            first=first->next;
            second=second->next;

        }
        return first;
    }
};
int main(){
    find_dup *s=new find_dup;
    int temp;
    int a[]={2,3,1,0,2,5,3};
    s->duplicate(a,7,&temp);
    printf("%d",temp);
    return 0;
}