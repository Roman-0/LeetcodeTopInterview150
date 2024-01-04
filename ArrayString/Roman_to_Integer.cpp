// Roman Olsen
// Leetcode top 150
//  Roman to Integer
//
#include <climits>
#include <string>
#include <unordered_map>

class Solution {
private:
  std::unordered_map<char, int> tbl;

public:
  Solution() {
    tbl['I'] = 1;
    tbl['V'] = 5;
    tbl['X'] = 10;
    tbl['L'] = 50;
    tbl['C'] = 100;
    tbl['D'] = 500;
    tbl['M'] = 1000;
  }

  int romanToInt(std::string s) {
    int total = 0;
    int lastNum = INT_MAX;
    int curNum;
    for (char numeral : s) {
      curNum = tbl[numeral];

      if (curNum > lastNum) {
        total -= lastNum;
        total += (curNum - lastNum);
      } else {
        total += curNum;
      }
      lastNum = curNum;
    }
    return total;
  }
};
