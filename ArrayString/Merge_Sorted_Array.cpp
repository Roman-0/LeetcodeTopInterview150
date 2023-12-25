// Roman Olsen
// Leetcode 88 Merge Sorted Vector
//
// Description: Instead of merging from the beginning like usual,
// start from the end to prevent having to shift the values back.
// Classic merge algorithm
//
#include <vector>

using namespace ::std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int idx1 = m - 1;
    int idx2 = n - 1;
    int idx = m + n - 1;

    while (idx1 >= 0 && idx2 >= 0) {
      if (nums1[idx1] > nums2[idx2]) {
        nums1[idx--] = nums1[idx1--];
      } else {
        nums1[idx--] = nums2[idx2--];
      }
    }
    while (idx1 >= 0) {
      nums1[idx--] = nums1[idx1--];
    }
    while (idx2 >= 0) {
      nums1[idx--] = nums2[idx2--];
    }
  }
};
