int sol(vector<int> &ratings){
    int n=ratings.size(),count=0,i;
    if(n==1)
        return 1;
    vector<int> candies(n,-1);
    for(i=1;i<n-1;i++)
        if(ratings[i]<=ratings[i+1] && ratings[i]<=ratings[i-1])
            candies[i]=1;
    if(ratings[0]<=ratings[1])
        candies[0]=1;
    if(ratings[n-1]<=ratings[n-2])
        candies[n-1]=1;
    for(i=1;i<n-1;i++){
        if(candies[i]==-1){
            if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1])
                candies[i]=1+candies[i-1];
        }
    }
    if(ratings[n-1]>ratings[n-2])
        candies[n-1]=1+candies[n-2];
     for(i=n-2;i>0;i--){
        if(candies[i]==-1){
            if(ratings[i]>ratings[i+1] && ratings[i]<=ratings[i-1])
                candies[i]=1+candies[i+1];
        }
    }
    if(candies[0]==-1)
        candies[0]=1+candies[1];
    for(i=1;i<n-1;i++){
        if(candies[i]==-1)
            candies[i]=1+max(candies[i+1],candies[i-1]);
    }
    for(i=0;i<n;i++)
        count+=candies[i];
    return count;
}
int Solution::candy(vector<int> &ratings) {
    return sol(ratings);
  }

