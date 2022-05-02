import json
import os

print("---------------")
cwd = os.getcwd()
files = os.listdir(cwd)
print("Files in %r: %s" % (cwd, files))
print("---------------")

#with open('nome.json', 'r') as openfile:
#    y = json.load(openfile)

file = open('lista.json')
data = json.load(file)
for i in data['games']:
    print(i)

print(data)
file.close()