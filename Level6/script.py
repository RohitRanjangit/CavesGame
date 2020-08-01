import requests as r
import string
import sys

# NOT USEFUL APART FROM HELPING US DISCOVER
# THE INPUT OUTPUT MAPPING BY PROVIDING SOME DATA

r.packages.urllib3.disable_warnings()

# url = 'https://172.27.18.8:9999/des'
url = 'https://172.27.26.181:9998/eaeae'
defbody = {'teamname': 'Bullshot', 'password': '826f9aa3e6f378f57dbc7d60607fbb02'}

# Change this to get items in bulk
userinput = False
di = {  }

def getcipher(text):
  defbody['plaintext'] = text
  resp = r.post(url, json=defbody, verify=False)
  return resp.json()['ciphertext']

if userinput:
  while True:
    text = input()
    print(text + ': ' + getcipher(text))
    sys.stdout.flush()
else:
  # text = 'c'*1000
  # alphas = list(string.ascii_lowercase)
  # alphas.extend(list(string.ascii_uppercase))
  # alphas.extend(list(range(10)))
  text = []
  # b_dict = {}
  # for i in range(0,8):
  #   for j in range(0,16):
  #     t_1 = chr(ord('f')+i)
  #     t_2 = chr(ord('f')+j)
  #     str1 = t_1 + t_2
  #     b_dict[str1] = j+16*i
  #     print(str1,j+16*i )
  with open ("input.txt", "r") as myfile:
    text=myfile.readlines()
  with open("output.txt","w") as fw:
    for lines in text:
      cipher = getcipher(lines[0:16])
      # print(cipher)
      # for i in range(0,8):
      #       fw.write(str(b_dict[cipher[2*i:2*i+2]]))
      #       fw.write(" ")
      fw.write(cipher)
      fw.write("\n")
    #   di.setdefault(cipher, [])
    #   di[cipher].append(plaintext)
      

  for key in di:
    print(key + ': ')
    print(di[key])