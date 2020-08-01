from pyfinite import ffield

F = ffield.FField(7,gen=131)

# for i in range(1,127):
#     c = 2
#     for j in range(1,pow(i,3)):
#             c = F.Multiply(c,2)
#     # print(c)
#     if F.Multiply(c,89) == 33:
#             print(i)

# for i in [66,77,111]:
#     for k in range(0,128):
#         c = k
#         for j in range(1,pow(i,2)+i):
#             c = F.Multiply(c,k)
#         # print(c)
#         if c == 89:
#             print(i,k,sep=",")

input_txt =[]
with open ("input.txt", "r") as myfile:
    input_txt=myfile.readlines()
output_txt =[]
with open ("output.txt", "r") as myfile1:
    output_txt=myfile1.readlines()

e_dict={}
b_dict = {}
for i in range(0,16):
    for j in range(0,16):
        t_1 = chr(ord('f')+i)
        t_2 = chr(ord('f')+j)
        str1 = t_1 + t_2
        b_dict[str1] = j+16*i



e_dict[16]=0
e_dict[50]=0
e_dict[61]=0
for i in range(0,128):
    inp = b_dict[input_txt[i][14:16]]
    out = b_dict[output_txt[i][14:16]]
    print(inp,out)
    for e in [16,50,61]:
        c = inp
        for j in range(1,pow(e,3)):
            c = F.Multiply(c,inp)
        if F.Multiply(c,82) == out:
            e_dict[e] = e_dict[e] + 1
print(e_dict)



# for i in range(1,127):
#     c = 2
#     for j in range(1,pow(i,3)):
#             c = F.Multiply(c,2)
#         if F.Multiply(c,89) == 33:
#                 print(i)