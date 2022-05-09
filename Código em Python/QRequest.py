import requests

#Search for Requests
response = requests.get('https://api.github.com/search/repositories', params={'q': 'requests+language:python'},)

#Inspect
dd = response.json()
repository = dd['items'][0]
print(f'Nome: {repository["name"]}')
print(f'Des: {repository["description"]}')


