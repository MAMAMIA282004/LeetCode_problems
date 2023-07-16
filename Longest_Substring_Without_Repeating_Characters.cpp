#include <iostream>
#include <unordered_set>
// #include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
      unordered_set<char> uniqueChars;
      int maxLength = 0;
      int left = 0, right = 0;
      while (right < s.length()) {
            if (uniqueChars.find(s[right]) == uniqueChars.end()) {
                  uniqueChars.insert(s[right]);
                  maxLength = max(maxLength, right - left + 1);
                  right++;
            }
            else {
                  uniqueChars.erase(s[left]);
                  left++;
            }
      }
      return maxLength;
}
int main() {
      string s;
      cout << "Enter a string: ";
      cin >> s;
      int longestLength = lengthOfLongestSubstring(s);
      cout << "Length of the longest substring without repeating characters: " << longestLength << endl;
      return 0;
}
