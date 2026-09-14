#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end=n+m-1,i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(nums1[i]<=nums2[j]){
                nums1[end--]=nums2[j--];
            }
            else{
                nums1[end--]=nums1[i--];
            }
        }
        if(i<0){
            while(j>=0){
                nums1[j]=nums2[j];
                j--;
            }
        }
    }