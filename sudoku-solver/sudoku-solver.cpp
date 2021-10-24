class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        //int cnt = 0;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    //++cnt;
                    for(char val='1';val<='9';val++){                                
                        if(isValid(board,i,j,val)){
                            board[i][j] = val;
                        
                            if(solve(board))
                                return 1;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return 0;     
                }  

            }
            
        }
        
        return 1;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
       bool fl = solve(board);
    }
};