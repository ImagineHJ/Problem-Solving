class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size(), len, start, end, offset, temp1, temp2;
        vector<int> v;
        for(int layer=0; layer<(size+1)/2; layer++){
            start = layer; end = size-layer-1;
            len = end-start;
            for(offset = 0; offset<len; offset++){
                temp1 = matrix[start][start+offset];
                temp2 = matrix[start+offset][end];
                matrix[start+offset][end] = temp1; temp1 = temp2;
              
                temp2 = matrix[end][end-offset];
                matrix[end][end-offset] = temp1; temp1 = temp2;
              
                temp2 = matrix[end-offset][start];
                matrix[end-offset][start] = temp1; temp1 = temp2;
              
                matrix[start][start+offset] = temp2;
            }
        }
    }
};
