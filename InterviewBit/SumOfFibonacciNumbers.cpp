#define ll long long
int Solution::fibsum(int A) {
    vector<ll> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    fibo[1]=1;
    fibo[2]=1;
    ll prev=1,last_prev=1;
    ll new_ppl=2;
    while(new_ppl<INT_MAX){
        fibo.push_back(new_ppl);
        last_prev=prev;
        prev=new_ppl;
        new_ppl=last_prev+prev;
    }
    
    int steps=0;
    int i=fibo.size()-1;
    ll B=A;
    while(B>0){
        if(fibo[i]>B)
            i--;
        else{
            B=B-fibo[i];
            steps++;
        }
    }
    return steps;
}
