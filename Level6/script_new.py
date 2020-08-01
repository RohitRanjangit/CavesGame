
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


def getcipher(text):
  defbody['plaintext'] = text
  resp = r.post(url, json=defbody, verify=False)
  return resp.json()['ciphertext']


password = "mgkplijngrluiqlq"
#mgkplijngrluiqlq
decrypted=""
for i in range(0,8):
    for j in range(128):
        plain = decrypted + chr(int(j/16)+ord('f')) + chr(int(j%16)+ord('f')) + "ff"*(7-i)
        cipher = getcipher(plain)
        print(plain,cipher)
        if cipher[2*i:2*i+2] == password[2*i:2*i+2]:
            decrypted = decrypted + plain[2*i:2*i+2]
            break

print(decrypted)
#ktirlqhtlqijmmhq
#lhlgmjmkmglqlompmoltmglilqlmlgmh
# ktirlqhtlqijmmhqmgkplijngrluiqlq
