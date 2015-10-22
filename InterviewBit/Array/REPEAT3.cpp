/*
 *You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
 *If so, return the integer. If not, return -1.
 *If there are multiple solutions, return any one.
 */
 
/*
 It is important to note that if at a given time, you have 3 distinct element from the array, if you remove them from the array, your answer does not change.
 *Assume that we maintain 2 elements with their counts as we traverse along the array.
 *When we encounter a new element, there are 3 cases possible :
 *We don’t have 2 elements yet. So add this to the list with count as 1.
 *This element is different from the existing 2 elements. As we said before, we have 3 distinct numbers now. Removing them does not change the answer. 
 *So decrement 1 from count of 2 existing elements. If their count falls to 0, obviously its not a part of 2 elements anymore.
 *The new element is same as one of the 2 elements. Increment the count of that element.
 *Consequently, the answer will be one of the 2 elements left behind. If they are not the answer, then there is no element with count > N / 3.
 */


int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int element1=INT_MAX,element2=INT_MAX;
    int count1=0,count2=0,i;
    for(i=0;i<n;i++){
    	if(count1>0 && A[i]==element1){
    		count1+=1;
    	}else if(count2>0 && A[i]==element2){
    		count2+=1;
    	}else if(count1==0){
    		element1=A[i];
    		count1=1;
    	}else if(count2==0){
    		element2=A[i];
    		count2=1;
    	}else{
    		count1--;
    		count2--;
    	}
    }
   int check,freq=0;
    if(count1==0 && count2==0)
    	return -1;
    else check=element1;
	for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>n/3)
    	return check;
    check=element2;
    freq=0;
    for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>n/3)
    	return check;
    return -1;
}
  
