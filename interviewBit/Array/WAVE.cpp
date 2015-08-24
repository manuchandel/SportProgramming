/*Given an array of integers, sort the array into a wave like array and return it, 
 *In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
 */
void swap(int& a,int &b){
	int c=a;
	a=b;
	b=c;
}
vector<int> Solution::wave(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.begin()+n);  //sort elements
    for(int i=0;i<n-1;i+=2)
    	swap(A[i],A[i+1]);  //swap elements in pairs
    return A;
    
}
