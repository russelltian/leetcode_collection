vector<vector<int>> permuteUnique(vector<int>& nums) {
	/*
	On top of regular permutation,
	add a look up table which stores the string convertion from a single
	combination, if the string pattern appears, don't push it to the final result
	set, if not, push it
	*/
	vector<vector<int>> ans;
	if (nums.size() == 0)return ans;
	unordered_map<string, bool> lookup;
	vector<int> single;
	vector<bool> used(nums.size(), false);
	permuteUnique_helper(ans, nums, used, single, lookup);
	return ans;
}

void permuteUnique_helper(vector<vector<int>>& ans, vector<int>&nums, vector<bool>&used, vector<int>&single, unordered_map<string, bool> &lookup) {
	if (single.size() == nums.size()) {
		stringstream temp;
		copy(single.begin(), single.end(), std::ostream_iterator<int>(temp, " "));
		if (lookup.find(temp.str()) != lookup.end()) {
			return;
		}
		lookup[temp.str()] = true;
		ans.push_back(single); return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			single.push_back(nums[i]);
			permuteUnique_helper(ans, nums, used, single, lookup);
			used[i] = false;
			single.pop_back();
		}
	}
}