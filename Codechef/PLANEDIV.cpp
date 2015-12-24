#include <bits/stdc++.h>
using namespace std;
int gcd(int A,int B){
    if(B==0)
        return A;
    else return gcd(B,A%B);
}
 
int main(){
    int T;
    scanf("%d",&T);
    int A,B,C,N;
    int cf;
    int card;
    double c;
    
    while(T--){
        unordered_map<int,unordered_map<int,unordered_map<double,int>>> mymap;
        card=1;
        scanf("%d",&N);
        while(N--){
            scanf("%d%d%d",&A,&B,&C);
            cf=gcd(max(abs(A),abs(B)),min(abs(A),abs(B)));
            A/=cf;
            B/=cf;
            c=(double)C/cf;
            if(B <0){
                A=0-A;
                B=0-B;
                c=0-c;
            }
            else if(B==0 && A<0){
                A=0-A;
                c=0-c;
            }
 
            if(mymap[A][B].find(c)==mymap[A][B].end()){
                mymap[A][B][c]=1;
            }else mymap[A][B][c]+=1;
        }
        for(auto it=mymap.begin();it!=mymap.end();++it){
            for(auto jt=mymap[it->first].begin();jt!=mymap[it->first].end();++jt)
                card=max((int)mymap[it->first][jt->first].size(),card);
        }
        printf("%d\n",card);
    }
} 