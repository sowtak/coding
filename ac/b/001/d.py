N=int(input())
V=[0]*10000
for i in range(N):
    s,e=map(int,input().split('-'))
    s-=s%5
    e+=(5-e%5)%5
    if e%100==60:
        e=e-60+100
    V[s]+=1
    V[e]-=1
v=0
for i in range(10000):
    if v==0 and V[i]>0:
         s = 1
    if v>0 and v+V[i]==0:
        print(f"%04d-%04d"%(s,i))

    v+=V[i]
