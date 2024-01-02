// Roman Olsen
// Leetcode top 150
//  Jump Game
//
//
//  as long as youre not stuck at 0, you win
// iterate through the list, checking if each element is 0
// if 0, check if you can get past it. nums[i-x] > x where x is distance from 0
#include <vector>
class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    bool canjump = true;
    // check edge cases
    if (nums.size() == 1)
      return true;

    if (nums[0] == 0)
      return false;
    // iterate forward in list
    //  i < nums.size()-1 because checking the last index doesnt matter
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == 0) {
        // set canjump to false, to be reverted by the loop
        canjump = false;
        // iterate backwards from the 0
        for (int j = i - 1; j >= 0; j--) {
          if (nums[j] > (i - j))
            canjump = true;
        }
        if (canjump == false) {
          return canjump;
        }
      }
    }
    return canjump;
  }
};
