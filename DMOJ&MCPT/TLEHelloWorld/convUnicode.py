fileName="weightIH"

f = open(fileName,"r")
b = list(map(chr,map(int,f.readline().split())))
fw = open(fileName+"Unicode","w",encoding="utf-16")
fw.write(''.join(b))
fw.close()
print(''.join(b))