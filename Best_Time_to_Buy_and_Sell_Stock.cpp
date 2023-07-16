#include <iostream>
#include <vector>
using namespace std;
pair<int, int> findBestBuySellDays(const vector<int>& prices) {
      int n = prices.size();
      int buyDay = 0;
      int sellDay = 0;
      int maxProfit = 0;
      int currentProfit = 0;
      int left = 0;
      int right = 0;
      while (right < n) {
            currentProfit += prices[right] - prices[right - 1];
            if (currentProfit <= 0) {
                  left = right;
                  currentProfit = 0;
            }
            if (currentProfit > maxProfit) {
                  buyDay = left;
                  sellDay = right;
                  maxProfit = currentProfit;
            }
            right++;
      }
      return { ++buyDay, ++sellDay };
}
int main() {
      cout << "enter size of array: ";
      int n; cin >> n;
      vector<int> prices(n);
      cout << "Enter the prices of dolls (separated by spaces): ";
      for (int i = 0; i < n; ++i) {
            cin >> prices[i];
      }
      pair<int, int> bestDays = findBestBuySellDays(prices);
      int buyDay = bestDays.first;
      int sellDay = bestDays.second;
      cout << "Best day to buy: " << buyDay << endl;
      cout << "Best day to sell: " << sellDay << endl;
      cout << "Max Profit: " << prices[sellDay - 1] - prices[buyDay - 1] << endl;
      return 0;
}
