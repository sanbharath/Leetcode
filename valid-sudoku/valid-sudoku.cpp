class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        
        //Row...
        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=0;j<n;j++){
                if(board[i][j] == '.')
                    continue;
                if(s.count(board[i][j]))
                    return 0;
                s.insert(board[i][j]);
            }
            s.clear();
        }
        
        //Col...
        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=0;j<n;j++){
                if(board[j][i] == '.')
                    continue;
                if(s.count(board[j][i]))
                    return 0;
                s.insert(board[j][i]);
            }
            s.clear();
        }
        
        // Boxes...
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                set<int> s;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(board[i+k][j+l] == '.')
                            continue;
                        if(s.count(board[i+k][j+l]))
                            return 0;
                        s.insert(board[i+k][j+l]);
                    }
                }
                s.clear();
            }
        }
        
        return 1;

    }
};