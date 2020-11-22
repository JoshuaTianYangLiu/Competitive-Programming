a=0
for i in range(1,18):
    for j in range(i,18):
        for k in range(j,18):
            if i+j>k and i+k>j and j+k>i and i+j+k<18 and i!=j!=k:
                print(i,j,k)
                a+=1
print(a)