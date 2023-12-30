// Roman Olsen
// Leetcode top 150
//  Remove Duplicates from Sorted Array
//
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int k = 1; // Initialize the count of unique elements to 1
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[k] = nums[i]; // Overwrite the next unique element
        k++;
      }
    }

    return k;
  }
};
