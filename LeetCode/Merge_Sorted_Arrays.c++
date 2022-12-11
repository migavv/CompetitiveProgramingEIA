#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, index = m+n-1;
    
    while (i >= 0 && j >= 0){
        if (nums1[i] >= nums2[j]){

            nums1[index--] = nums1[i--];
        }
        else{
            nums1[index--] = nums2[j--];
        }
    }

    while (j>=0){
        nums1[index--] = nums2[j--];
    }

    int index2 = n+m;

    for (int h=0; h<nums1.size();h++){
        printf("%d",nums1.capacity());
        printf("\n");
        printf("%d", nums1[h]);
    }
}

int main(){
    vector <int> nums1 = {1,2,3};
    vector <int> nums2 = {3,4,5};
    int n = 3;
    int m = 3;

    merge(nums1,m,nums2,n);

}