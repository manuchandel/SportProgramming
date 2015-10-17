table =[]
for i in range (0,502):
    table.append(-1)
table[0]=1
def po2(n):
    if(table[n]!=-1):
        return table[n]
    table[n]=po2(n-1)<<1
    return table[n]
t=int(input())
for i in range (0, t):
    n=int(input())
    print((po2(n+1)-1)%1298074214633706835075030044377087)
