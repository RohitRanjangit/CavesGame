
b_dict = {}
for i in range(0,8):
    for j in range(0,16):
        t_1 = chr(ord('f')+i)
        t_2 = chr(ord('f')+j)
        str1 = t_1 + t_2
        b_dict[j+16*i] = str1
rand_num = [61,63,23,48,126,34,67,34,53,48,110,111]

# with open ("input.txt", "w") as inp:
#     for i in range(128):
#         for j in range(128):
#             data = [0,0,0,0,0,0,0,0]
#             for k in range(0,8):
#                 if k == 2:
#                     data[k] = i
#                 elif k==4:
#                     data[k] = j
#                 else :
#                     data[k] = rand_num[k]
#             for e in data:
#                 inp.write(b_dict[e])
#             inp.write("\n")

with open ("input.txt", "w") as inp:
    for i in range(128):
        data = [0,0,0,0,0,0,0,0]
        data[7]  = i
        for e in data:
            inp.write(b_dict[e])
        inp.write("\n")


        
