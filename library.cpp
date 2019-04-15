
#include <iostream>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode*first,*second;
        first=second=pListHead;
        for(int i=0;i<k;i++){

            if(first==NULL)
                return first;
            first=first->next;
        }
        while(first){
            first=first->next;
            second=second->next;
        }
        return  second;
    }
};
int main(){
    Solution s;
    ListNode *h=new ListNode(1);
    ListNode *res,*cur=h;
    int val[5]={1,1,2,3,3};
    h->val=1;
    for(int i=0;i<5;i++){
        ListNode *new_node=new ListNode(val[i]);
        cur->next=new_node;
        cur=cur->next;
//       h->val=val[i];
//       h=h->next;
    }
    res=s.FindKthToTail(h,6);
    printf("%d",res->val);
}