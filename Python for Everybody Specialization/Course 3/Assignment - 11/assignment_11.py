import re

sample_data = open("regex_sum_42.txt")
actual_data = open("regex_sum_1734145.txt")
test_data = open("test.txt")

total = 0

for line in actual_data:
    line = line.rstrip()
    numbers = re.findall('[0-9]+', line)
    for num in numbers:
        num = int(num)
        total = num + total
print(total)
