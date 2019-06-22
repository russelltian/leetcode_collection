/*
94% run time 
Brute Force O(N^2)
*/

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int> mapAB;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			mapAB[A[i] + B[j]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			int temp = -C[i] - D[j];
			if (mapAB.find(temp) != mapAB.end())
				ans += mapAB[temp];
		}
	}
	return ans;
}
