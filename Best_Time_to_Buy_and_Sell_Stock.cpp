#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    auto pair = minmax_element(nums.begin(), nums.end());
    int result = *pair.second - *pair.first;
    cout << result << endl;
    return 0;
}
// زق يومك متعقدهاش علي نفسك يعم (^_^)
