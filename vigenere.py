import sys
import cs50

if len(sys.argv) != 2:
    print("Usage: python caesar.py alphabets")
    exit(1)

while True:
    if sys.argv[1].isalpha() == True:
        break
    else:
        print("Usage: python caesar.py alphabets")
        exit(1)

key = sys.argv[1].lower()
plaintext = cs50.get_string("plaintext:  ")

ciphertext = []
index_key = 0
key_len = len(key)
for index in range(len(plaintext)):
    offset = ord(key[index_key % key_len]) - ord('a')
    if plaintext[index].isupper() == True:
        ciphertext.append(chr(65 + (ord(plaintext[index]) - ord('A') + offset) % 26))
        index_key += 1
    elif plaintext[index].islower() == True:
        ciphertext.append(chr(97 + (ord(plaintext[index]) - ord('a') + offset) % 26))
        index_key += 1
    else:
        ciphertext.append(plaintext[index])

print("ciphertext: ", end="")
for c in ciphertext:
    print(c, end="")
print()
exit(0)