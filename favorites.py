import csv

with open("favorites.csv","r") as file:

    reader = csv.DictReader(file)

    scratch, c, python = 0, 0, 0

    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
        Scratch += 1
    elif favorite == "c":
c += 1
elif favorite == "Python"
Python += 1

print(f"Scratch: {Scratch}")
print(f"c: {c}")
print(f"Python: {Python}")