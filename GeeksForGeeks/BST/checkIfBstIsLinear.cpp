/* 
 *Time =O(n) & extra Space =O(1)
 */
 
/* it is assumed that given array represents bst in pre order so there are no duplicates */
bool bstCheck(int a[],int n){
  int i;
  int current_max=INT_MAX;
  int current_min=INT_MIN;
  for(i=1;i<n;i++){
    if(a[i]<current_min || a[i]> current_max) //if not in range return false
      return false;
    if(a[i]<a[i-1]) //move left
      current_max=a[i-1];
    else        //move right
      current_min=a[i-1];
  }
  return true;
}
