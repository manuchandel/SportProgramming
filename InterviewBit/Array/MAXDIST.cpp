/*
 *Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
 *If there is no solution possible, return -1.
 */


struct Box{
	int a;
	int b;
};
/* function that sorts struct Box on b */
bool acompare(Box b1,Box b2){
	if(b2.b>b1.b)
		return true;
	else if(b1.b==b2.b){
		if(b1.a<b2.a)
			return true;
	}
	return false;
}

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int n=A.size();
    if(n==0)
    	return -1;
    int i;
    vector<Box> myindex;  //vector of A[i] with
    for(i=0;i<n;i++){
    	Box box;
    	box.a=i;
    	box.b=A[i];
    	myindex.push_back(box);
    }
    sort(myindex.begin(),myindex.end(),acompare); 
    int max_diff=0,min_element=myindex[0].a;
    /* find maximum difference between myindex[i].a when it is sorted on b*/
    for(i=0;i<n;i++){
    	if(myindex[i].a<min_element)
    		min_element=myindex[i].a;
    	if(myindex[i].a-min_element>max_diff){
    		max_diff=myindex[i].a-min_element;
    	}
    }
    return max_diff;
}
