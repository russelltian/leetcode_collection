bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0 || board[0].size() == 0)return false;
	if (word.size() > board.size()*board[0].size())return false;
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
	bool findit = false;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			wordSearchHelper(board, i, j, word, 0, findit, visited);
			if (findit) return true;
		}
	}
	return false;
}

/*
helper function that seraching for the string,
board: the board
i: current row
j: current col
word: the target word
index: current location on the string
findit: global varaible that illustrates the matching condition
used: a board with the same dimension with `board`, used to track if the grid has been visited
*/
void wordSearchHelper(vector<vector<char>>&board, int i, int j, string& word, int index, bool &findit, vector<vector<bool>>&used) {
	if (findit)return;
	//boarder check
	if (i < 0 || i >= board.size())return;
	if (j < 0 || j >= board[0].size())return;
	//depulicate check
	if (used[i][j]) { return; }
	//mark as visited
	used[i][j] = true;
	//validate char match
	if (board[i][j] == word[index]) {
		// if it is the last character, return
		if (index == word.size() - 1) {
			findit = true;
			return;
		}
		//great, lets try up,down,left,right for the next character 
		wordSearchHelper(board, i - 1, j, word, index + 1, findit, used);
		wordSearchHelper(board, i + 1, j, word, index + 1, findit, used);                                                       wordSearchHelper(board, i, j - 1, word, index + 1, findit, used);
		wordSearchHelper(board, i, j + 1, word, index + 1, findit, used);
	}
	//did not match, or the process is finished so return
	used[i][j] = false;
	return;
}