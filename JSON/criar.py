import json

data = {
    "name": ["Bianca", "Raissa"],
    "age": [26,26],
    "games": [["Warframe", "Overwatch"],["Warframe", "Overwatch"]]
}

with open("lista.json", "w") as writefile:
    json.dump(data,writefile, indent = 2)


