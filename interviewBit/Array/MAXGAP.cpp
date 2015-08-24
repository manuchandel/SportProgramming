/*
 *Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *Try to solve it in linear time/space.
 *Return 0 if the array contains less than 2 elements.
*/

/*MIN, MIN + gap, MIN + 2*gap, MIN + 3*gap, ... MIN + (N-1)*gap  put elements in this bucket
 *each bucket caontains two elements smallest and largest
 *now max difference = min[bucket]-max[bucket-1]
 */

int maxVal(int a,int b){
	if(a<b)
		return b;
	return a;
}
int minVal(int a,int b){
	if(b<a)
		return b;
	return a;
}
int Solution::maximumGap(const vector<int> &A) {
int n=A.size();
     if(n<2)
        return 0;
    int i,min=0,max=0,gap=0,bucket=0,pre=0,max_dif=0;
  	vector<int> v1(n,-1); //to store min
  	vector<int> v2(n,-1); //to store max
  	for(i=0;i<n;i++){
  		if(A[max]<A[i])
  			max=i;
  		if(A[min]>A[i])
  			min=i;
  	}
  	gap=A[max]-A[min];
  	gap=gap/(n-1);
  	if(gap==0)
  		return A[max]-A[min];
    for(i=0;i<n;i++){
    	bucket=(int)(A[i]-A[min])/gap;
    	if(v1[bucket]<0){
    		v1[bucket]=A[i];
    		v2[bucket]=A[i];
    	}else{
	    	v1[bucket]=minVal(v1[bucket],A[i]);
	    	v2[bucket]=maxVal(v2[bucket],A[i]);
	    }
  	}
  	max_dif=0;
  	for(i=0;i<n;i++)
  	    if(v1[i]>=0){
  	        max_dif=maxVal(max_dif,v1[i]-v2[pre]);
  	        pre=i;
  	    }
  	return max_dif;

}
