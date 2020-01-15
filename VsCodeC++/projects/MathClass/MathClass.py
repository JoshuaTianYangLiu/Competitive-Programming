n=int(input())
a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())
if a==c and d==b:
    print("0")
elif (c-a)*(2*e-a-c)==(b-d)*(2*f-d-b):
    print("1")
else:
    print("-1")