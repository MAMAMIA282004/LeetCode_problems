#include <iostream>
#include <climits>
using namespace std;
const int no_of_chars = 26;
string findSubString(string str, string pat) {
    int len1 = str.length();
    int len2 = pat.length();
    // Check if the length of the string is smaller than the length of the pattern
    // If the length is smaller, there is no possible substring window
    if (len1 < len2) {
        cout << "String length is smaller than pattern length!" << "\n\n";
        return "";
    }
    // Create arrays to store the frequency of characters in the pattern and the string
    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };
    // Store the frequency of characters in the pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i] - 'a']++;
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0; // Number of matched characters
    // Start scanning the string
    for (int j = 0; j < len1; j++) {
        // Update the frequency of characters in the string
        hash_str[str[j] - 'a']++;
        // If the character in the string matches the character in the pattern, increase the count
        if (hash_str[str[j] - 'a'] <= hash_pat[str[j] - 'a'])
            count++;
        // If all characters have been matched
        if (count == len2) {
            // Try to minimize the size of the window
            while (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'] || hash_pat[str[start] - 'a'] == 0) {
                if (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'])
                    hash_str[str[start] - 'a']--;
                start++;
            }
            // Update the size of the window
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    // If no window is found
    if (start_index == -1) {
        cout << "No valid window found!" << "\n\n";
        return "";
    }
    // Return the substring starting from start_index with length min_len
    return str.substr(start_index, min_len);
}
int main() {
    string str = "abcedeca";
    string pat = "ace";
    if(findSubString(str, pat) != "")
    cout << "Substring 1: " << findSubString(str, pat) << "\n\n";

    string str2 = "ab";
    string pat2 = "abc";
    if(findSubString(str2, pat2) != "")
        cout << "Substring 2: " << findSubString(str2, pat2) << "\n\n";

    string str3 = "abcdef";
    string pat3 = "era";
    if(findSubString(str3, pat3) != "")
    cout << "Substring 3: " << findSubString(str3, pat3) << "\n\n";

    return 0;
}
