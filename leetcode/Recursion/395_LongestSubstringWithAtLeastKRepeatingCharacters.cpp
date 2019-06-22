/*
92% run time, 
The idea is that every time there is an invalid character in the array, split the array to 
left part and right part. Go into left part do the same thing, the terminate condition is that each
list is all valid characters.
*/
int longestSubstring(string s, int k) {
	if (s.size() < k)return 0;
	int array[26] = {};
	for (char i : s) {
		array[i - 'a']++;
	}
	//cout << breakpoint <<endl;
	bool allValid = true;
	for (int z : array) {
		if (z > 0 && z < k) allValid = false;
	}
	if (allValid)return s.size();

	//iterate the array and find the first invalid one
	int maxLen = 0;
	int count = 0;
	for (int j = 0; j < s.size(); j++) {
		if (array[s[j] - 'a'] > 0 && array[s[j] - 'a'] < k) {
			maxLen = max(maxLen, longestSubstring(s.substr(count, j - count), k));
			count = j + 1;
		}
	}

	return max(maxLen, longestSubstring(s.substr(count), k));
}