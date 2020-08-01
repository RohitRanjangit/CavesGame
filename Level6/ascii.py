# b_dict = {}
# for i in range(0,16):
#     for j in range(0,16):
#         t_1 = chr(ord('f')+i)
#         t_2 = chr(ord('f')+j)
#         str1 = t_1 + t_2
#         b_dict[str1] = j+16*i

# plain = 

text = "lhlgmjmkmglqlompmoltmglilqlmlgmh"
password = ""
for i in range(16):
    password = password + chr((ord(text[2*i])-ord('f'))*16 + (ord(text[2*i+1])-ord('f')))
print(password)