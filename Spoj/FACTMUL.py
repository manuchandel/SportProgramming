n=input()
i=1
fact1=1
if n>=373166:
    fact1=0
    i=n+1
p=109546051211


fact=1
while i<=n:
    j=1
    fact=fact*i
    if fact>p:
        fact=fact%p
    fact1=fact1*fact
    if fact1>p:
        fact1=fact1%p
    if fact1==0:
        break
    i+=1
print fact1,"\n"

