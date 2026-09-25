#include<string>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {//两个指针在相交前走过的路程是一样的
        if(headA==NULL||headB==NULL){return NULL;}
        ListNode* p=headA;
        ListNode* q=headB;
        while(p!=q){
            if(p==NULL){p=headB;}
            else{p=p->next;}
            if(q==NULL){q=headA;}
            else{q=q->next;}
        }
        return p;      
    }


// 好难想到.......