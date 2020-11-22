import math

def solution(area):
    ret=[]
    while area!=0:
        a=math.floor(math.sqrt(area))
        a*=a
        ret.append(a)
        area-=a
    print(str(ret)[1:-1].replace(' ',''))
    # Your code here

solution(15324)