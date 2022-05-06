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

response.json()

print(response.headers)



