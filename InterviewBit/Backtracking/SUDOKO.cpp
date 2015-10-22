#define FOR(a,b) for(a=0;a<b;a++)
void initialize(bool *seen){
    int i;
    FOR(i,10)
        seen[i]=0;
}
bool validSudoko(int **arr,int row,int col){
    int i,j,n=9;
    bool seen[n+1];
    initialize(seen);
    FOR(i,n){   // checking in same row
        if(arr[row][i]>0 && seen[arr[row][i]])
            return 0;
        else if(arr[row][i]>0)
            seen[arr[row][i]]=1;
    }
    initialize(seen);  //checking in same column
    FOR(i,n){
        if(arr[i][col]>0 && seen[arr[i][col]])
            return 0;
        else if(arr[i][col]>0)
            seen[arr[i][col]]=1;
    }
    initialize(seen);
    int gridr=(int)row/3;
    int gridcol=(int)col/3;
    gridr*=3;
    gridcol*=3;
    FOR(i,3)    //check square
        FOR(j,3){
            if(arr[gridr+i][gridcol+j]>0 && seen[arr[gridr+i][gridcol+j]])
                return 0;
            else if(arr[gridr+i][gridcol+j]>0)
                seen[arr[gridr+i][gridcol+j]]=1;
        }
    return 1;
}
struct Pairs{
    int x,y;
};
Pairs setP(int a,int b){
    Pairs pair{a,b};
    return pair;
}
bool solve(int **a,vector<Pairs> &v,int i){
    if(i==v.size())
        return 1;
    int m=v[i].x,
        n=v[i].y,
        k;
    FOR(k,9){
        a[m][n]=k+1;
        if(validSudoko(a,m,n))
            if(solve(a,v,i+1))
                return 1;
        else a[m][n]=-1;
    }
    a[m][n]=-1;
    return 0;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    int n=9;
    int i,j;
    int **arr=new int *[n];
    vector<Pairs> v;
    FOR(i,n)
        arr[i]=new int[n];
    FOR(i,n)
        FOR(j,n){
            if(A[i][j]=='.'){
                arr[i][j]=-1;
                v.push_back(setP(i,j));
            }
            else arr[i][j]=A[i][j]-'0';
        }
    solve(arr,v,0);
    FOR(i,n)
        FOR(j,n)
            A[i][j]=arr[i][j]+'0';
}
