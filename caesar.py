import sys
import cs50

if len(sys.argv) != 2:
    print("Usage: python caesar.py number")
    exit(1)

while True:
    if sys.argv[1].isdigit() == True:
        break
    else:
        print("Usage: python caesar.py number")
        exit(1)

key = int(sys.argv[1]) % 26
plaintext = cs50.get_string("plaintext:  ")

ciphertext = []
for index in range(len(plaintext)):
    if plaintext[index].isupper() == True:
        ciphertext.append(chr(65 + (ord(plaintext[index]) - ord('A') + key) % 26))
    elif plaintext[index].islower() == True:
        ciphertext.append(chr(97 + (ord(plaintext[index]) - ord('a') + key) % 26))
    else:
        ciphertext.append(plaintext[index])

print("ciphertext: ", end="")
for c in ciphertext:
    print(c, end="")
print()
exit(0)