import sys
inp = input().split(' ')
N = int(inp[0])
K = int(inp[1])
ans=1
for i in range(1,N+K):
    ans*=i
for j in range(1,K+1):
    ans/=j
for j in range(1,N):
    ans/=j
print (int(ans))