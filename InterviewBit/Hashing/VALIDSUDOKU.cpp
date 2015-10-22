/*
 *Determine if a Sudoku is valid
 */
int Solution::isValidSudoku(const vector<string> &A) {
    unordered_map <int,int> cols[9];
    int n=9;
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j]!='.'){
                if(cols[i].find(A[i][j]-'0')!=cols[i].end())
                    return 0;
                else cols[i][A[i][j]-'0']=i;
            }
        }
    }
    for(i=0;i<n;i++)
        cols[i].clear();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j]!='.'){
                if(cols[j].find(A[i][j]-'0')!=cols[j].end())
                    return 0;
                else cols[j][A[i][j]-'0']=i;
            }
        }
    }
    for(i=0;i<n;i++)
        cols[i].clear();
     for(i=0;i<n;i++){
        k=(int)i/3;
        k=k*3;
        for(j=0;j<3;j++){
            if(A[i][j]!='.'){
                if(cols[k+j/3].find(A[i][j]-'0')!=cols[k+j/3].end())
                    return 0;
                else cols[k+j/3][A[i][j]-'0']=i;
            }
        }
        for(j=3;j<6;j++){
            if(A[i][j]!='.'){
                if(cols[k+j/3].find(A[i][j]-'0')!=cols[k+j/3].end())
                    return 0;
                else cols[k+j/3][A[i][j]-'0']=i;
            }
        }
        for(j=6;j<9;j++){
            if(A[i][j]!='.'){
                if(cols[k+j/3].find(A[i][j]-'0')!=cols[k+j/3].end())
                    return 0;
                else cols[k+j/3][A[i][j]-'0']=i;
            }
        }
    }
    return 1;
        
}
