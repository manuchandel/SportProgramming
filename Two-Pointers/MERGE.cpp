/*
 *Given two sorted integer arrays A and B, merge B into A as one sorted array.
 */

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int n=A.size();
    int m=B.size();
    int p=0,q=0;
    for(p=0;p<n;p++)
        C.push_back(A[p]);
    for(p=0;p<n;p++)
        A.pop_back();
     p=0;   
    while(p<n && q<m){
        if(C[p]<=B[q]){
            A.push_back(C[p]);
            p++;
        }else {
            A.push_back(B[q]);
            q++;
        }
    }
    while(p<n){
        A.push_back(C[p]);
        p++;
    }
     while(q<m){
        A.push_back(B[q]);
        q++;
    }
}
