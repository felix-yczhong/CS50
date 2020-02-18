import cs50

input = cs50.get_float("Change owed: ")
while(input < 0):
    print("Change owed: ", end="")
    input = cs50.get_float()

dividend = input
coin = [0.25, 0.1, 0.05, 0.01]
count = []

"""
divident = divisor * quotient + remainder
"""

for i in range(len(coin)):
    remainder = round(dividend % coin[i], 2)
    count.append((int)(round((dividend - remainder) / coin[i], 0)))
    dividend = remainder

print(sum(count[:]))