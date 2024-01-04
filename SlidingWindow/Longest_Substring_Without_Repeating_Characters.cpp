// Roman Olsen
// Leetcode top 150
//  Longest Substring Without Repeating Characters
//
#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string str) {
    std::unordered_set<char> charSet;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < str.length(); right++) {
      char currentChar = str[right];

      // While character in character set
      while (charSet.find(currentChar) != charSet.end()) {
        // Remove Leftmost element from the set
        charSet.erase(str[left]);
        ++left;
      }

      // Expand the window to the right
      charSet.insert(currentChar);
      maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};
