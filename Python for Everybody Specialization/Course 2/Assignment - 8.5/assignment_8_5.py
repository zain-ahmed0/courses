fh = open("mbox-short.txt")

count = 0

for line in fh:
    line = line.rstrip()
    if not line.startswith("From "):
        continue
    count = count + 1
    sep = line.split()
    print(sep[1])
    
print("There were", count, "lines in the file with From as the first word")
