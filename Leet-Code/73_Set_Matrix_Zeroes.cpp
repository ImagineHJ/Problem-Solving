class Solution {
public:
    unordered_map<int, bool> cols, rows;
    void makeRowZero(vector<vector<int>>& matrix, int r){
        for(int i=0; i<matrix[r].size(); i++){
            matrix[r][i] = 0;
        }

    }
    void makeColZero(vector<vector<int>>& matrix, int c){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][c] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for(auto r : rows) if(r.second) makeRowZero(matrix, r.first);
        for(auto c : cols) if(c.second) makeColZero(matrix, c.first);
    }
};
