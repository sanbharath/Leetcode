class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>grid(n,vector<int>(n));
        int top_row = 0 ;
        int left_column = 0 ;
        int bottom_row = n - 1 ;
        int right_column = n - 1 ;
        int C = 1 ; 
        while(top_row <= bottom_row && left_column <= right_column ){
            for(int i = left_column ; i <= right_column ; i ++ ){
                grid[top_row][i] = C++;
            }
            ++top_row ;
            for(int i = top_row ; i <= bottom_row ; i ++ ){
                grid[i][right_column] = C++;
            }
            --right_column;
            for(int i = right_column ; i >= left_column ; i -- ){
                grid[bottom_row][i] = C++ ;
            }
            --bottom_row ;
            for(int i = bottom_row ; i >= top_row ; i -- ){
                grid[i][left_column] = C++;
            }
            ++left_column ;
        }
        return grid ;
    }
};