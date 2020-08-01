b_dict = {
      'f':'0000',
      'g':'0001',
      'h':'0010',
      'i':'0011',
      'j':'0100',
      'k':'0101',
      'l':'0110',
      'm':'0111',
      'n':'1000',
      'o':'1001',
      'p':'1010',
      'q':'1011',
      'r':'1100',
      's':'1101',
      't':'1110',
      'u':'1111'
  }
key_list = list(b_dict.keys())
value_list = list(b_dict.values())

pas = "password"
pass_cipher = "mnqfjfkpgrrsjgpqfkgkltggrtgrtiro"
# for c in pas:
#     print(b_dict[c],end='')
# print()
cn =0
# for c in pass_cipher:
#     cn = cn +1
#     print(b_dict[c],end='')
#     if(cn == 64):
#         print()

str1 = "11001101101010110000010100011001010110011010011100111000010010110010101111101101011011100000110110011101011111010011110010010100"
for i in range(0,32):
    t = str1[4*i:4*i+4]
    print(key_list[value_list.index(t)],end='')
    # print(chr(int(t,2)))
print()
# print(len(pass_cipher))