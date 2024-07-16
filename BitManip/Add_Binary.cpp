#include <algorithm>
#include <string>
using namespace std;

// Roman Olsen
// Leetcode top 150
//  Add Binary

//  Easy Solution

class Solution {
public:
  string addBinarySimple(string a, string b) {
    string res = "";
    int a_ind = a.size() - 1;
    int b_ind = b.size() - 1;
    int carry = 0;

    while (a_ind >= 0 || b_ind >= 0 || carry) {
      if (a_ind >= 0) {
        carry += a[a_ind] - '0';
        a_ind--;
      }
      if (b_ind >= 0) {
        carry += b[b_ind] - '0';
        b_ind--;
      }
      res.push_back((carry % 2) + '0');
      carry /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
  }

  // Optimal Solution

  string addBinaryOptimal(string a, string b) {
    string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      result.push_back((sum % 2) + '0');
      carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
