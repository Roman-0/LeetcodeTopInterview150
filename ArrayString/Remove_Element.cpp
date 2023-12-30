// Roman Olsen
// Leetcode top 150
//  Remove Element
//  Easy (1/10)
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
        idx++;
      }
    }
    return idx;
  }
};
