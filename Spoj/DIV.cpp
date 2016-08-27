#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
#define mod 1000000007
using namespace std;

int main(){
    int i,j,k;
    int *num=new int [MAX];
    bool *prime=new bool[MAX];
    int *divi=new int [MAX];
    for(i=0;i<MAX;i++){
        num[i]=i;
        prime[i]=true;
        divi[i]=1;
    }
    vector<int>pr;
    prime[0]=prime[1]=false;
    for(i=2;i*i<MAX;i++){
        if(prime[i]){
            for(j=i+i;j<MAX;j+=i){
                prime[j]=0;
                if(num[j]%i==0){
                    int power=1;
                    while(num[j]%i==0){
                        num[j]/=i;
                        power++;
                    }
                    divi[j]=divi[j]*power;
                }
            }
            pr.push_back(i);
        }
    }
    for(i=0;i<MAX;i++){
        if(num[i]!=1){
            divi[i]=divi[i]*2;
        }
    }
    int n=pr.size();
    for(i=0;i<MAX;i++){
        prime[i]=false;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pr[i]*pr[j]>=MAX){
                break;
            }
            prime[pr[i]*pr[j]]=1;
        }
    }
    k=0;
    for(int i=0;i<MAX;i++){
        if(prime[divi[i]]){
            k++;
            if(k%9==0)
                printf("%d\n",i);

        }
    }

}
