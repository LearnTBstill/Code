#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* deleteDuplicates(ListNode* head) {
        int nval=0;
        ListNode* ans=head;
        while(head!=NULL&&head->next!=NULL)
        {
            nval=head->next->val;
            if(head->val==nval)
            {
              head->next=head->next->next;
              continue;
            }
            head=head->next;//我居然写成head++了！
        }
        return ans;
    }