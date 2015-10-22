/*
 * Given an array of Numbers and an integer K.
 *Find the total number of Distinct Elements in the contiguous sub-arrays of size K each.
 *Time O(n) & space O(k)
 */
#include <iostream>
#include <unordered_map>
using namespace std;
void printDistinctElements(int *arr,int n,int k){
	unordered_map<int,int> mymap;
	int i,p;
	int distinct=0;
	for(i=0;i<k;i++){
		if(mymap.find(arr[i])==mymap.end()){
				mymap[arr[i]]=1;
			distinct+=1;
		}
		else mymap[arr[i]]+=1;
	}
	p=0;
	for(;i<n;i++){
		if(mymap[arr[p]]==1){
			distinct-=1;
			mymap.erase(arr[p]);
		}
		else mymap[arr[p]]-=1;
		if(mymap.find(arr[i])==mymap.end()){
			mymap[arr[i]]=1;
			distinct+=1;
		}else mymap[arr[i]]+=1;
		p++;
		cout<<distinct<<endl;
	}
}
int main()
{
  int n;
	int k;
	cin>>n;
	int *array=new int[n];
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	cin>>k;
	printDistinctElements(array,n,k);
}
