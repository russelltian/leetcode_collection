void setZeroes(vector<vector<int>>& matrix) {
	// we can easily come up with a O(m+n) space complexity solution
	if (matrix.size() == 0)return;
	bool isrow = false; bool iscol = false;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0; matrix[i][0] = 0;
				if (i == 0)isrow = true; if (j == 0)iscol = true;
			}
		}
	}
	for (int i = 1; i < matrix.size(); i++) {
		if (matrix[i][0] == 0) {
			for (int j = 0; j < matrix[i].size(); j++) {
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < matrix[0].size(); i++) {
		if (matrix[0][i] == 0) {
			for (int j = 0; j < matrix.size(); j++) {
				matrix[j][i] = 0;
			}
		}
	}
	if (isrow) {
		for (int i = 0; i < matrix[0].size(); i++) {
			matrix[0][i] = 0;   
		}
	}
	if (iscol) {
		for (int i = 0; i < matrix.size(); i++) {
			matrix[i][0] = 0;
		}
	}
}