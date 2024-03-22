// Roman Olsen
// Leetcode top 150
//  Valid Parentheses
//
#include <stack>
#include <string>

class Solution {
public:
/**
 * Returns if a string has valid parenthesis.
 *
 * @param string.
 * @return if string has valid parenthesis.
 */
  bool isValid(std::string s) {
    std::stack<char> stack;
    for (char ch : s) {
      if (ch == '{' || ch == '(' || ch == '[') {
        stack.push(ch);
      } else if (stack.empty()) {
        return false;
      } else {
        char bracket = stack.top();
        stack.pop();
        switch (bracket) {
        case '{':
          if (ch != '}')
            return false;
          break;
        case '(':
          if (ch != ')')
            return false;
          break;
        case '[':
          if (ch != ']')
            return false;
          break;
        }
      }
    }
    return (stack.empty()) ? true : false;
  }
};



