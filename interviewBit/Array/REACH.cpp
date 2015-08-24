/*
 *You are given a sequence of points and the order in which you need to cover the points.
 *Give the minimum number of steps in which you can achieve it.
 *You start from the first point.
 */
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int current_x,current_y;
    int n=X.size();
    int i;
    int steps=0;
    if(n==0)
        return steps;
    current_x=X[0];
    current_y=Y[0];
    for(i=1;i<n;i++){
        X[i]=X[i]-current_x;
        Y[i]=Y[i]-current_y;
        steps+=max(abs(X[i]),abs(Y[i]));
        X[i]+=current_x;
        Y[i]+=current_y;
        current_x=X[i];
        current_y=Y[i];
    }
    return steps;
}
