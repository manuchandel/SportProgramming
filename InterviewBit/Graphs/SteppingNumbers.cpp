
vector<int> Solution::stepnum(int A, int B) {
    int i,j,k,p,q;
    vector<long long> v;
    for(i=1;i<10;i++){
        v.push_back(i);
    }
    p=0;
    for(k=2;k<=11;k++){
        q=v.size();
        
        if(p==q)
            break;
        for(j=p;j<q;j++){
            long long last=v[j];
            long long lastdigit=v[j]%10;
            if(lastdigit<=8 and lastdigit>=1){
                if(last*10+(lastdigit+1)>0)
                    v.push_back(last*10+(lastdigit-1));
                if(last*10+(lastdigit-1))
                    v.push_back(last*10+(lastdigit+1));
            }
            else if(lastdigit==0){
                if(last*10+1>0)
                    v.push_back(last*10+1);
            }
            else {
                if(last*10-1>0)
                    v.push_back(last*10+8);
            }
            
        }
        p=q;

    }
    v.push_back(0);
    sort(v.begin(),v.end());
    vector<int> ans;
    for(i=0;i<v.size();i++){
        if(v[i]>=(long long)A and v[i]<=(long long)B)
            ans.push_back((int)v[i]);
    }
    return ans;
}
