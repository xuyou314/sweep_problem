//
// Created by xuyou on 19-3-31.
//
#include <iostream>
#include <vector>
#define  MAX 999999
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k=lists.size();
    ListNode **cur=new ListNode*[k];
    for(int i=0;i<k;i++)
        cur[i]=lists[i];
    int flag=1,index,min;
    ListNode *tail=NULL,*head=NULL;
    while(1){
        flag=0;
        min=MAX;
        for(int i=0;i<k;i++){
            if(cur[i]!=NULL)
                flag=1;
            else
                continue;
            if(cur[i]->val<min){
                min=cur[i]->val;
                index=i;
            }
        }
        if(flag==0)
            break;
        if(tail){
            ListNode *nnode=new ListNode(cur[index]->val);
            tail->next=nnode;
            tail=nnode;
        } else{
            ListNode*h=new ListNode(cur[index]->val);
            tail=h;
            head=h;
        }
        cur[index]=cur[index]->next;
    }
    return head;
}
void print_list(ListNode*l){
    ListNode*c=l;
    while (c){
        cout<<c->val;
        c=c->next;
    }
}
int main(){
    vector<ListNode*>list;
    ListNode *h1=new ListNode(5);
    ListNode *h2=new ListNode(3);
    ListNode *h3=new ListNode(2);
    ListNode *res;
    list.push_back(NULL);
    list.push_back(NULL);
    list.push_back(NULL);
    res=mergeKLists(list);
    print_list(res);
    return 0;
}
