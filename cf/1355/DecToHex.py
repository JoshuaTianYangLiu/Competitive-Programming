# Hi you found this. 

def toHex(a):
    return "{0:#0{1}x}".format(a,4)[2:]

def ree(a):
    return '#'+''.join(list(map(toHex,map(int,a.split())))).upper()

out=""
for i in range(16):
    out+=ree(input())+'\n'
print(out)
    