vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	if (nums.size() == 0)return ans;
	vector<int> single;
	vector<bool> used(nums.size(), false);
	permute_helper(ans, nums, used, single);
	return ans;
}

void permute_helper(vector<vector<int>>& ans, vector<int>&nums, vector<bool>&used, vector<int>&single) {
	if (single.size() == nums.size()) {
		ans.push_back(single); return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			single.push_back(nums[i]);
			permute_helper(ans, nums, used, single);
			used[i] = false;
			single.pop_back();
		}
	}
}