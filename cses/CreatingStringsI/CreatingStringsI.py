import itertools
a=[i for i in input()]
a=list(set(list(itertools.permutations(a))))
print(len(a))
a.sort()
for i in a:
    print(''.join(i))