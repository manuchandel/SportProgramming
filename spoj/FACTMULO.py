t=input()
while t>0:
    count=0
    l=[f(i) for f,i in zip((int, int), raw_input().split())]
    p=l[0]
    n=l[1]
    j=p
    k=1
    while k>0:
        k=int(n/j)
        count+=j*k*(k-1)/2
        s=n-k*j+1
        count+=s*k
        j=p*j
    print count,"\n";
    t-=1
