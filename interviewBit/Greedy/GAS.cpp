int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n=gas.size(),i,j,temp;
    int sum=0;
    int begin=0;
    int tank=0;
    for(i=0;i<n;i++){
        sum+=(gas[i]-cost[i]);
        tank+=(gas[i]-cost[i]);
        if(tank<0){
            tank=0;
            begin=i+1;
        }
    }
    if(begin <n && sum >=0) 
        return begin;
    return -1;
}

