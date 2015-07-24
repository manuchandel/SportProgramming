/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 /*
  *This problem has a lot of corner cases which need to be handled correctly.
  *Let us first talk about the approach. 
  *Given all the intervals, you need to figure out the sequence of intervals which intersect with the given newInterval.
  *Lets see how we check if interval 1 (a,b) intersects with interval 2 (c,d):
  *Overlap case
  *             a-------------------b               
  *                       c------------------d
  *Non overlap case :
  * a--------------------b   c------------------d
  *Note that if max(a,c) > min(b,d), then the intervals do not overlap. Otherwise, they overlap.
  *Once we figure out the intervals ( interval[i] to interval[j] ) which overlap with newInterval, note that we can replace all the overlapping intervals with one interval which would be
  *(min(interval[i].start, newInterval.start), max(interval[j].end, newInterval.end)).
  */



vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   if(newInterval.start > newInterval.end){
    	int temp=newInterval.start;
    	newInterval.start=newInterval.end;
    	newInterval.end=temp;
    }

    int i=0;
    int n=intervals.size();
    int p=-1,q=-1;
   	for(i=0;i<n;i++){
   		if(max(intervals[i].start,newInterval.start)<=min(intervals[i].end,newInterval.end)){
   			if(p<0)
   				p=i;
   			q=i;
   		}
   	}
   	if(p<0){
   		vector<Interval> ::iterator it=intervals.begin();
   		for(i=0;i<n;i++){
   			if(newInterval.start < intervals[i].start){
   				intervals.insert(it,newInterval);
   				return intervals;
   			}
   			++it;
   		}
   		intervals.push_back(newInterval);
   		return intervals;
   	}	
    intervals[p].start=min(intervals[p].start,newInterval.start);
    intervals[p].end=max(intervals[q].end,newInterval.end);
    for(i=1;i<n-q;i++){
    	intervals[p+i].start=intervals[q+i].start;
    	intervals[p+i].end=intervals[q+i].end;

    }
    for(i=n-q+p;i<n;i++)
    	intervals.pop_back();
    return intervals;
}
