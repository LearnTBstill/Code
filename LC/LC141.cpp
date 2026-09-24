#include<string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
        ListNode* low=head;
        ListNode* high=head;
        while(high!=NULL&&high->next!=NULL){
            if(high->next==low){
                return true;
            }
           low=low->next;
           high=high->next->next;
        }
        return false;
    }