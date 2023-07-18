#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int characterReplacement(string s, int k) {
    int maxF = 0, i = 0, n = s.length(), clean = 0;
    vector<int> count(26);
    for (int j = 0; j < n; ++j) {
        maxF = max(maxF, ++count[s[j] - 'a']);
        if (j - i + 1 > maxF + k)
            --count[s[i + 1] - 'a'], clean++;
    }
    return n - clean;
}

int main() {
    string s = "babaab";
    int k = 2;
    int result = characterReplacement(s, k);
    cout << "Longest Repeating Character Replacement: " << result << endl;
    return 0;
}
