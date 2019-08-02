bool canJump(vector<int>& nums) {
	int limit = 0; //furthest can reach
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		if (i > limit)return false;
		int can_reach = i + nums[i];
		limit = limit < can_reach ? can_reach : limit;
		if (limit >= size - 1)return true;
	}
	return false;
}