int Solution::black(vector<string> &A) {
    vector< vector<int> > v;
    vector< vector<int> > graph;
    int i,j,k;
    int vertices=0;
    graph.resize(A.size());
    for(i=0;i<A.size();i++){
        graph[i].resize(A[i].length());
        for(j=0;j<A[i].length();j++){
            if(A[i][j]=='X'){
                graph[i][j]=vertices;
                vertices++;
            }else graph[i][j]=-1;
        }
    }
    v.resize(vertices);
    for(i=0;i<graph.size();i++){
        for(j=0;j<graph[i].size();j++){
            if(graph[i][j]>=0){
               int vertex=graph[i][j];
                // right 
                if(j+1<graph[i].size() and graph[i][j+1]>=0)
                    v[vertex].push_back(graph[i][j+1]);
                // left 
                if(j>0 and graph[i][j-1]>=0)
                    v[vertex].push_back(graph[i][j-1]);
                
                // top
                if(i>0 and graph[i-1][j]>=0)
                    v[vertex].push_back(graph[i-1][j]);
                
                // bottom
                if(i+1<graph.size() and graph[i+1][j]>=0)
                    v[vertex].push_back(graph[i+1][j]);
                
            }
        }
    }
    int ans=0;
    queue<int> Q;
    vector<bool> vis(vertices,false);
    for(i=0;i<vertices;i++){
        if(!vis[i]){
            ans+=1;
            vis[i]=true;
            Q.push(i);
            while(!Q.empty()){
                j=Q.front();
                Q.pop();
                for(k=0;k<v[j].size();k++){
                    if(!vis[v[j][k]]){
                        vis[v[j][k]]=1;
                        Q.push(v[j][k]);
                    }
                }
            }
        }
    }
    return ans;
}
