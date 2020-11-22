def aaa(b):
    return str(b).encode("utf-8").decode("utf-8")


f = open("FFC2","r")
a = map(int,f.readline().split())
a=list(a)
a.sort()
print(len(a))
print(a[0:100])
for i in range(len(a)-1):
    if a[i+1]-a[i]>10:
        print(a[i],a[i+1])
# fobj.write(a)