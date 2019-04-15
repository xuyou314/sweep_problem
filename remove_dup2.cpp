//
// Created by xuyou on 19-2-25.
//
#include <stdlib.h>
#include <stdio.h>
struct  ListNode{
    int val;
    struct ListNode*next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication1(ListNode* pHead)
    {
        ListNode*cur,*pre;
        cur=pre=pHead;
        while(cur!=NULL){
            for(ListNode*h=pHead;h!=cur;h=h->next){
                if(h->val==cur->val){
                    pre->next=cur->next;
                    free(cur);
                    cur=pre->next;
                    continue;
                }
            }
            pre=cur;
            cur=cur->next;
        }
        return pHead;
    }
    ListNode* deleteDuplication2(ListNode* pHead){
        ListNode*head=new ListNode(-4);
        ListNode*pphead=new ListNode(-8);
        head->next=pHead;
        pphead->next=head;
        int flag;
        ListNode*cur,*pre,*ppre;
        cur=pHead;
        pre=head;
        ppre=pphead;
        while(cur!=NULL) {
            while (cur!=NULL&&cur->val == pre->val) {
                flag = 1;
                pre->next=cur->next;
                delete cur;
                cur= nullptr;
                cur = pre->next;
            }
            if (flag == 1) {
                ppre->next=cur;

                delete pre;
                pre = nullptr;

                pre = cur;
                if(cur!=NULL)
                    cur = cur->next;
                flag=0;
            } else {
                ppre=pre;
                pre = cur;
                cur = cur->next;
            }
        }
        return head->next;
    }
    ListNode* deleteDuplication(ListNode* pHead){
        ListNode*head=new ListNode(-1);
        ListNode*cur,*pre;
        int flag=0;
        head->next=pHead;
        cur=pHead;
        pre=head;
        while(cur!=NULL){
            while(cur->next!=NULL&&cur->val==cur->next->val){
                flag=1;
                pre->next=cur->next;
                free(cur);
                cur=pre->next;
            }
            if(flag) {
                if(cur!=NULL) {
                    pre->next = cur->next;
                    free(cur);
                    cur=pre->next;
                }
                flag=0;
            } else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head->next;
    }
};
void print_list(ListNode*list){
    ListNode *h=list;
    while (h){
        printf("%d",h->val);
        h=h->next;
    }
    printf("\n");
}
int main(){
    Solution *s=new Solution();
    //ListNode *h=(ListNode*)malloc(sizeof(ListNode));
    ListNode *h=new ListNode(1);
    ListNode *cur=h;
    int val[5]={1,1,2,3,3};
    h->val=1;
    for(int i=0;i<5;i++){
       ListNode *new_node=new ListNode(val[i]);
       cur->next=new_node;
       cur=cur->next;
//       h->val=val[i];
//       h=h->next;
    }
    print_list(h);
    //s->deleteDuplication1(h);
    print_list(s->deleteDuplication(h));
    return 0;
}