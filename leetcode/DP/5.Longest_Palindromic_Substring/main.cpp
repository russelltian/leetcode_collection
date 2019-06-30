string longestPalindrome(string s) {
	/*
	Base: s[i] == s[i], s[i] == s[i+1] ? 2 : 1
	then find max length
	*/
	if (s.empty())return "";
	vector<vector<bool>> isValid(s.size(), vector<bool>(s.size(), false));
	for (int i = 0; i < s.size(); i++)isValid[i][i] = true;
	int maxLen = 1; int start = 0;
	int len = 2; int size = s.size();
	for (int i = 0; i < size - 1; i++) {
		if (s[i] == s[i + 1]) {
			isValid[i][i + 1] = true;
			start = i;
			maxLen = 2;
		}
	}
	//every thing >= size
	for (; len <= size; len++) {
		for (int i = 0; i < size - len; i++) {
			if (s[i] == s[len + i] && isValid[i + 1][len + i - 1]) {
				isValid[i][len + i] = true;
				if (len >= maxLen) {
					maxLen = len + 1;
					start = i;
				}
			}
		}
	}
	return s.substr(start, maxLen);
}