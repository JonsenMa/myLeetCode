/*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int currMaxSum = 0;
		int maxSum = nums[0];

		for (unsigned int i = 0; i < nums.size(); i++) {
			currMaxSum = max(currMaxSum + nums[i], nums[i]);
			maxSum = max(currMaxSum, maxSum);
		}

		return maxSum;
	}
};

int main() {
	Solution s;
	vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
	int sum = s.maxSubArray(v);
	cout << sum;
	return 0;
}