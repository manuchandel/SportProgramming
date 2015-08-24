/* 
 *Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
 *All elements in the array are in the range [0, N-1]
 *N * N does not overflow for a signed integer 
 */
 
 /*
  *Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
  *Divide every element by N.
  */
void arrange(vector<int> &Vec) {
    int N = Vec.size();
    for(int i = 0; i < N; ++i) {
        Vec[i] = Vec[i] + (Vec[Vec[i]]%N) * N;
    }

    for(int i = 0; i < N; ++i) {
        Vec[i] = Vec[i] / N;
    }
}
