#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = 0;
		int size = nums.size();
		if (size <= 1) {
			len = size;
			return len;
		}
		else {
			int tmp = nums[0];
			len = 1;
			for (unsigned int i = 1; i < size; i++) {
				if (tmp != nums[i]) {
					tmp = nums[i];
					nums[len++] = tmp;
				}
			}
			return len;
		}
	}
};

int main() {
	Solution s;
	vector<int> v = {0,0,1,1,2,2,2};
	int len = s.removeDuplicates(v);
	cout << len << endl;
	for (int i = 0; i < len; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}