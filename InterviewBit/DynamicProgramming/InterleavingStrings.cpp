
bool foo1(string &s1, string &s2, string &s3, int x,int y,int z,vector<vector<vector<int>>> &v);
bool foo(string &s1, string &s2, string &s3, int x,int y,int z,vector<vector<vector<int>>> &v){
    if(x<0 && y>=0 && z>=0)
      return s3.substr(0,z+1)==s2.substr(0,y+1);
    if(x>=0 && y<0 && z>=0)
        return s3.substr(0,z+1)==s1.substr(0,x+1);
    if(z<0 && (x>=0 || y>=0))
        return false;
    if(z>=0 && x<0 && y<0)
        return false;
    if(z<0 && x<0 && y<0)
        return true;
    if(v[x][y][z]==-1){
        if(foo1(s1,s2,s3,x,y,z,v))
            v[x][y][z]=1;
        else v[x][y][z]=0;
    }
    if(v[x][y][z]==1)
        return true;
    return false;
}
bool foo1(string &s1, string &s2, string &s3, int x,int y,int z,vector<vector<vector<int>>> &v){
    
    if(x<0 && y>=0 && z>=0)
      return s3.substr(0,z+1)==s2.substr(0,y+1);
    if(x>=0 && y<0 && z>=0)
        return s3.substr(0,z+1)==s1.substr(0,x+1);
    if(z<0 && (x>=0 || y>=0))
        return false;
    if(z>=0 && x<0 && y<0)
        return false;
    if(z<0 && x<0 && y<0)
        return true;
    if(s2[y]==s1[x] && s1[x]==s3[z])
        return foo(s1,s2,s3,x-1,y,z-1,v)|| foo(s1,s2,s3,x,y-1,z-1,v);
    else if(s2[y]==s3[z])
        return foo(s1,s2,s3,x,y-1,z-1,v);
    else if(s1[x]==s3[z])
        return foo(s1,s2,s3,x-1,y,z-1,v);
    return false;
}
int Solution::isInterleave(string A, string B, string C) {
    int i,j;
    int x=A.length(),y=B.length(),z=C.length();
    vector<vector<vector<int>>> v;
    vector<vector<int>> vbar;
    for(i=0;i<y;i++){
       vector<int> r(z,-1);
       vbar.push_back(r);
    }
    for(i=0;i<x;i++)
       v.push_back(vbar);
    
    if(foo1(A,B,C,x-1,y-1,z-1,v))
        return 1;
    return 0;
}
