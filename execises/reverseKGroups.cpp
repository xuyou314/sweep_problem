#include <iostream> 
#include <vector>
#include <string>
using namespace std;
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode():val(0), next(NULL){}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1)
            return head;
        ListNode *cur = head;
        ListNode *curtail = NULL, *nnext = NULL, *ret=head;
        int cur_num, first;
        int len = 0;
        while(cur){
            len++;
            cur = cur->next;
        }
        cur = head;
        int t = len/k;
        //cout<<t;
        while(t){
            first = 1;
            cur_num = 0;
            nnext = NULL;
            while(first||(nnext&&cur_num<k-1)){
                cout<<cur->val<<endl;
                if(!nnext){
                    nnext =  cur->next->next;
                    cur->next->next = cur;
                    cur = cur->next;
                    cur_num++;
                    first = 0;
                }
                else{
                    ListNode *tmp = nnext->next;
                    nnext->next = cur;
                    cur = nnext;
                    nnext = tmp;
                    cur_num++;
                }
            }
            if(curtail){
                ListNode *curhead = curtail->next;
                curtail->next = cur;
                curtail = curhead;
                curtail->next = nnext;
                cur = nnext;
            }
            else{
                ret = cur;
                curtail = head;
                cur = nnext;
                curtail->next = nnext;
            }
            t--;
        }
        return ret;
}
int main(){
	ListNode *tail = NULL,*head = NULL;
	for(int i=0;i<5;i++){
	       ListNode *node = new ListNode;
		node->val = i;
		if(!tail) {tail = node;head = node;continue;}
		tail ->next = node;
		tail = node;
	}
	ListNode *ret =  reverseKGroup(head, 2);
	//ListNode *ret = head;
	while(ret){
		cout<<ret->val<<endl;
		ret = ret->next;
	}
	return 0;	
}
