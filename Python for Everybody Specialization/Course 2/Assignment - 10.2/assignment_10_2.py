handle = open("mbox-short.txt")

count = dict()
tmp = list()

for lines in handle:
    if not lines.startswith("From "):
        continue
    from_line = lines.split()
    hour_line = from_line[5].split(":")
    hour = hour_line[0]
    count[hour] = count.get(hour,0) + 1
        
lst = list()
for key, val in count.items():
    newtup = (key, val)
    lst.append(newtup)
    
lst = sorted(lst, reverse=False)

for val,key in lst:
    print(val,key)
