import requests
import json

response = requests.get('https://api.github.com')

if response.status_code == 200:
    print("SUCCESS!")

# Raw Bytes
#print(response.content)

#Convert into string
response.encoding = 'utf-8'
print(response.text)

print("###############################")

dd = response.json() #returna a dict
print(dd)

print("###############################")

print(response.headers)
#Can access it like a dictionary ---> JSON
#response.headers['content-type']



