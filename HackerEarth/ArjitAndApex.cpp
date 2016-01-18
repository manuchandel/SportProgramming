#include <bits/stdc++.h>
using namespace std;
struct S{
    int pr,sc;
    
};
int main()
{
    int T,M,N,i,j,G,H,g,h,sc,pr;
    scanf("%d",&T);
    
    while(T--){
        map< int,map<int,int> > interns;
        scanf("%d%d",&M,&N);
        S emp[N];
        for(i=0;i<M;i++){
            scanf("%d%d",&sc,&pr);
            if(interns[sc].find(pr)==interns[sc].end())
                interns[sc][pr]=1;
            else interns[sc][pr]+=1;
        }
        for(i=0;i<N;i++)
            scanf("%d%d",&emp[i].sc,&emp[i].pr);
            
        h=0;g=0;
        scanf("%d%d",&G,&H);
        for(i=0;i<N;i++){
            sc=emp[i].sc;
            pr=emp[i].pr;
            if(interns.find(sc)!=interns.end())
                if(interns[sc].find(pr)!=interns[sc].end()){
                    h++;
                    g++;
                    emp[i].sc=-1;
                    emp[i].pr=-1;
                    interns[sc][pr]-=1;
                    if(interns[sc][pr]==0){
                        interns[sc].erase(pr);
                        if(interns[sc].size()==0)
                            interns.erase(sc);
                    }
            }else{
                emp[i].sc=-1;
                emp[i].pr=-1;
            }
        }
        map<int, map<int,int> > ::iterator it=interns.begin();
        map<int,int> :: iterator jt;
        int arr[10001];
        memset(arr,0,sizeof(arr));
        for(;it!=interns.end();it++){
            for(jt=interns[it->first].begin();jt!=interns[it->first].end();jt++)
                arr[it->first]+=(jt->second);
        }
        for(i=0;i<N;i++){
            sc=emp[i].sc;
            if(sc>0 && arr[sc]>0){
                g+=1;
                arr[sc]-=1;
            }
        }
            
          
        if(g>=G && h>=H)
            printf("Great\n");
        else if(g>=G)
            printf("Good\n");
        else printf(":(\n");
        
    }
}
