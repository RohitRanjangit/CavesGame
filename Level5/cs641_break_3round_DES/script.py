import requests as r
import string
import sys

# NOT USEFUL APART FROM HELPING US DISCOVER
# THE INPUT OUTPUT MAPPING BY PROVIDING SOME DATA

r.packages.urllib3.disable_warnings()

# url = 'https://172.27.18.8:9999/des'
url = 'https://172.27.26.181:9999/des'
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
  with open ("random.txt", "r") as myfile:
    text=myfile.readlines()
  with open("binary_output.txt","w") as fw:
    for lines in text:
      cipher = getcipher(lines[0:16])
      print(cipher)
      for i in range(0,16):
            fw.write(b_dict[cipher[i]])
      fw.write("\n")
    #   di.setdefault(cipher, [])
    #   di[cipher].append(plaintext)

  for key in di:
    print(key + ': ')
    print(di[key])