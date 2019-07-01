vector<vector<int>> threeSum(vector<int>& nums) {
	if (nums.size() < 3)return {};
	sort(nums.begin(), nums.end());  //nlogn
	vector<vector<int>> ans;
	for (int i = 0; i < nums.size() - 2; i++) {
		threeSum_helper(nums, i + 1, -nums[i], ans);
		while (nums[i] == nums[i + 1] && i + 1 < nums.size() - 2)i++;
	}
	return ans;
}

void threeSum_helper(vector<int>&nums, int start, int target, vector<vector<int>>&ans) {
	int l = start; int r = nums.size() - 1;
	// O(N) look up for a sorted list
	while (l < r) {
		if (nums[l] + nums[r] == target) {
			ans.push_back({ -target,nums[l],nums[r] });
			while (l < r && nums[l + 1] == nums[l])l++;
			while (l < r && nums[r] == nums[r - 1])r--;
			l++; r--;
		}
		else if (nums[l] + nums[r] < target) {
			while (l < r && nums[l + 1] == nums[l])l++;
			l++;
		}
		else if (nums[l] + nums[r] > target) {
			while (l < r && nums[r] == nums[r - 1])r--;
			r--;
		}
	}
}