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

// Optimized
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col_0=1;
         
        // find zeros
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j==0){
                        col_0=0;
                    }
                    else{
                        matrix[0][j]=0;
                    }
                }
            }
        }
 
        // fill zeros (except row 0 and col 0)
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        // row 0
        if(matrix[0][0]==0){
            for(int j=0; j<matrix[0].size(); j++) {
                matrix[0][j]=0;
            }
        }
        // col 0
        if(col_0==0){
            for(int i=0; i<matrix.size(); i++) {
                matrix[i][0]=0;
            }
        }
    }
};
