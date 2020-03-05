#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		auto min = prices[0];
		auto profit = 0;
		for (auto i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1]) {
				profit = max(profit, prices[i] - min);
			}
			else {
				min = std::min(min, prices[i]);;
			}
		}
		return profit;
	}
};

int main()
{
	Solution s;
	vector<int> prices{7,1,5,3,6,4};
	int max = s.maxProfit(prices);
	cout << "max profit: " << max << endl;
}