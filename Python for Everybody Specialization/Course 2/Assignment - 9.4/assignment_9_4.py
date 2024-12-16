handle = open("mbox-short.txt")

count = dict()

for lines in handle:
    if not lines.startswith("From "):
        continue
    line = lines.split()
    email = line[1]
    count[email] = count.get(email,0) + 1

bigword = None    
bigcount = None
    
for k,v in count.items():
    if bigcount is None or v > bigcount:
        bigword = k
        bigcount = v

print(bigword, bigcount)
