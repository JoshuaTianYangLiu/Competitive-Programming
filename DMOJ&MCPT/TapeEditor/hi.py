a=2**24-1
cnt=0
for i in range(10,100):
    if a%i==0:
        print(i)
        cnt+=1
print(cnt)