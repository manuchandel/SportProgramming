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
    bool *isN=new bool[MAX];
    for(i=0;i<MAX;i++){
        num[i]=i;
        prime[i]=true;
        divi[i]=1;
    }
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
        }
    }
    for(i=0;i<MAX;i++){
        if(num[i]!=1){
            divi[i]=divi[i]*2;
        }
    }
    for(i=0;i<MAX;i++){
        num[i]=i;
        prime[i]=true;
        isN[i]=1;
    }
    isN[0]=isN[1]=isN[2]=isN[3]=0;
    for(i=2;i<MAX;i++){
            for(j=i;j<MAX;j+=i){
                if(!(divi[j]%divi[i]==0 && divi[j]>=3)){
                    isN[j]=false;
            }        
        }  
    }
    k=0;
    for(i=0;i<MAX;i++){
        if(isN[i]){
            k++;
            if(k%108==0)
                printf("%d\n",i);
        }
    }

}
