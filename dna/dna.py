import csv
import sys
import re

if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

database = sys.argv[1]
sequence = sys.argv[2]
db = []

def main():
    with open(database) as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.append(row)

    with open(sequence) as txt:
        dna = txt.read()
        mysequnece = dna

    text = mysequnece

    AGATC = compute('AGATC', text)
    AATG = compute('AATG', text)
    TATC = compute('TATC', text)
    TTTTTTCT = compute('TTTTTTCT', text)
    TCTAG = compute('TCTAG', text)
    GATA = compute('GATA', text)
    GAAA = compute('GAAA', text)
    TCTG = compute('TCTG', text)

    if sys.argv[1] == 'databases/small.csv':
        for i in range(len(db)):
            for i in range(len(db)):
                if all([db[i]["AGATC"] == str(AGATC), db[i]["AATG"] == str(AATG), db[i]["TATC"] == str(TATC)]):
                    output = db[i]["name"]
                    break
                else:
                    output = "No match"
    else:
        for i in range(len(db)):
            if all([db[i]["AGATC"] == str(AGATC), db[i]["TTTTTTCT"] == str(TTTTTTCT), db[i]["TCTAG"] == str(TCTAG), db[i]["AATG"] == str(AATG),
                    db[i]["GATA"] == str(GATA), db[i]["TATC"] == str(TATC), db[i]["GAAA"] == str(GAAA), db[i]["TCTG"] == str(TCTG)]):
                output = db[i]["name"]
                break
            else:
                output = "No match"

    print(output)

def compute(pattern, dnaSeq):
    match = re.findall(f'(?:{pattern})+', dnaSeq)
    if match == []:
        myresult = 0
        return myresult
    else:
        extractor = max(match, key=len)
        lentgth = len(extractor)
        calculator = round(lentgth / len(pattern))
        return calculator

main()