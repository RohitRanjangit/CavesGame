from pyfinite import ffield

F = ffield.FField(7,gen=131)

# for i in range(1,127):
#     c = 2
#     for j in range(1,pow(i,3)):
#             c = F.Multiply(c,2)
#     # print(F.Multiply(c,52))
#     if F.Multiply(c,9) == 20:
#             print(i)

for i in [78,85,91]:
    for k in range(0,128):
        c = k
        for j in range(1,pow(i,2)+i):
            c = F.Multiply(c,k)
        # print(c)
        if c == 9:
            print(i,k,sep=",")