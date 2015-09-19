vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i=0,j=0,x,y;
    int n=A.size();
    vector<vector<int>> v;
    vector<int> row;
    i=0;j=0;
    while(i<n){
        x=i;y=j;
        while(x<n & y>=0 ){
            row.push_back(A[x][y]);
            x++;y--;
        }
        v.push_back(row);
        row.clear();
        if(j<n-1)
            j++;
        else i++;
    }
    return v;
}
