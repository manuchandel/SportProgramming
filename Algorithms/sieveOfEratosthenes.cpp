/*
 * Complexity is O(NloglogN)
 */
void sieve(int N){  //finds all prime numbers upto N
  bool isprime[N+1];
  for(int i=0;i<n;i++)
    isprime[i]=true;
  isprime[0]=isprime[1]=false;
  for(int i=2;i<=sqrt(N);i++)
    for(int j=i*i;j<=N && isprime[i];j+=i)
      isprime[j]=false;
  //All numbers whose isprime[i]==true are prime
}
