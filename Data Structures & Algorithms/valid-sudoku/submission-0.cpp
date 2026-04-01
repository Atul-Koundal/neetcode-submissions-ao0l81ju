class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> st;
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.')
                    continue;
                if (st.count(val)) {
                    return false;
                }
                st.insert(val);
            }
        }

        for (int c = 0; c < 9; c++) {
            unordered_set<char> st;
            for (int r = 0; r < 9; r++) {
                char val = board[r][c];
                if (val == '.')
                    continue;
                if (st.count(val)) {
                    return false;
                }
                st.insert(val);
            }
        }
        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {
                unordered_set<char> st;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[startRow + i][startCol + j];
                        if (val == '.') {
                            continue;
                        }
                        if (st.count(val)) {
                            return false;
                        }
                        st.insert(val);
                    }
                }
            }
        }
        return true;
    }
};