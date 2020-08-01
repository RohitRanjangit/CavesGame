import numpy as np

with open ("binary_output", "r") as myfile:
    text=myfile.readlines()

p = np.poly1d([1,0,0,0,0,0,1,0])

with open("input.txt","w") as fw:
    for lines in text:
        for i in range(0,8):
            p1 = []
            inp = lines[8*i:8*i+8]
            for c in inp:
                p1 = p1 + [ord(c) - 48]
            poly = np.poly1d(p1)
            quotient, remainder = np.polydiv(poly, p)
            for e in remainder:
                fw.write(abs(e)%2)
        fw.write("\n")