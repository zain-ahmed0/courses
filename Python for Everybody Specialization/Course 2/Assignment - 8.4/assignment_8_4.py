fh = open("romeo.txt")
lst = list()

for line in fh:
    words = line.rstrip().split()
    for word in words:
        if word not in lst: 
            x = lst.append(word)

lst.sort()
sort_lst = sorted(lst)
print(sort_lst)
