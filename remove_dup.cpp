//
// Created by xuyou on 19-2-25.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct listnode{
    int val;
    struct listnode *next;

}lnode;

lnode* create(int vals[],int num){
    //int num=sizeof(vals)/ sizeof(vals[0]);
    lnode*h,*t;
    h=(lnode*)malloc(sizeof(lnode));
    h->val=vals[0];
    t=h;
    for(int i=0;i<num-1;i++){

        lnode*cur=(lnode*)malloc(sizeof(lnode));
        cur->val=vals[i+1];
        t->next=cur;
        t=cur;
    }
    return h;

}
void prit(listnode* l){
    lnode*h=l;

    while(h)
    {
        printf("%d", h->val);
        h = h->next;
    }
    printf("\n");
}
lnode* delete_node(lnode*list,lnode*target){


    lnode*cur,*pre;
    cur=pre=list;
    if(cur==target){
      list=cur->next;
      free(cur);
      return list;
    }
    while(cur!=target){
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    free(cur);
    return list;
}
void delete_duplicated(lnode*l){
    lnode*t,*pre;
    t=pre=l;
    int visited=0;
    while(t) {
        visited=0;
        for (lnode *h = l; h !=t;h=h->next){
               if(h->val==t->val)
                   visited=1;
        }
        if(visited==1){
            pre->next=t->next;
            t=t->next;
            continue;
        }
        pre=t;
        t=pre->next;
    }
}
int main(){
    int vals[8]={1,2,3,2,5,4,3,3};
    lnode*h=  create(vals,8);
    prit(h);
    //h=delete_node(h,h);
    //prit(h);
    delete_duplicated(h);
    prit(h);
    return 0;
}
