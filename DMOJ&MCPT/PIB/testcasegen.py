cnt=0
for a in range(0,125):
    for b in range(0,125-a):
        for c in range(0,125-a-b):
            for d in range(0,125-a-b-c):
                for e in range(0,125-a-b-c-d):
                    if a+b+c+d+e==124:
                        # print(a,b,c,d,e)
                        cnt+=1
    print(a)
print(cnt)