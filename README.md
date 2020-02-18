# CS50
Please note that the assignments of CS50 utilizes CS50's API included in cs50.h

You can visit the content of the API at https://man.cs50.io/

Learn more about the course at https://www.edx.org/course/cs50s-introduction-to-computer-science

## Week 1
The assignments of week 1 include hello, mario and one of cash or credit.

### hello
This program says hello to user.

input: a string (name)\
output: "hello, [input name]"

Example:\
$ ./hello\
What is your name?\
Noah\
hello, Noah

### mario
This program prints based on user input a number of hash signs for bricks arranged like pyramids in classic mario game.\
The program must only take a positive integer less or equal to 8 and must reject illegal input.

input: an integer\
output: a pyramid of input heigh with gap of 2 bricks in the middle

Example:\
$ ./mario\
Height: 2\
&nbsp; \#&nbsp;&nbsp;#\
\##&nbsp;&nbsp;##

$ ./mario\
Height: f\
Height: -2\
Height: 4\
&nbsp; &nbsp; &nbsp; \#&nbsp;&nbsp;#\
&nbsp; &nbsp; \##&nbsp;&nbsp;##\
&nbsp; \###&nbsp;&nbsp;###\
\####&nbsp;&nbsp;####

### cash
This programs returns the minimal number of coins required to give back to a customer when one purchases an item. The available coins are quarters (25 cents), dimes (10 cents), nickels (5 cents) and penny (1 cent). This assignment requires implementation of a greedy algorithm.

input: a number (signifies owed money in dollar)\
output: the minimal number of coins required to give back

Example:\
$ ./cash\
Change owned: -0.41\
Change owned: foo\
Change owned: 0.41\
4

### credit
This program prompts the user for a credit card number and then reports whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format. The program must reject illegal input.

Prefix requirement:
* American Express: starts with 34 or 37
* MasterCard: starts with 51, 52, 53, 54, or 55
* Visa: starts with 4

All credit card numbers' checksum must be checked out by Luhn’s algorithm.

input: a string of numbers\
output: AMEX, MASTERCARD, VISA, or INVALID

Example:\
$ ./credit\
Number: 4003-6000-0000-0014\
Number: foo\
Number: 4003600000000014\
VISA

$ ./credit\
Number: 6176292929\
INVALID

## Week 2
The assignments of week 2 include 2 of Caesar, Vigenère or crack.

### Caesar
Caesar's algorithm encrypts messages by rotating each letter by k positions. More formally, if p[i] is the ith letter of plaintext and c[i] is the ith letter of ciphertext, then c[i] = (p[i] + k) % 26

The input and output must distinguish uppercase and lowercase.

This program takes an input key and a plaintext, encrypts it into ciphertext using Caesar's algorithm. The progrma must reject illegal input.

input: a key (number) and a plaintext\
output: ciphertext output by Caesar's algorithm, ignoring any non-alphabets

Example:\
$ ./caesar 1\
plaintext:  HELLO\
ciphertext: IFMMP

$ ./caesar 13\
plaintext:&nbsp; hello, world\
ciphertext: uryyb, jbeyq

$ ./caesar 13\
plaintext:&nbsp; be sure to drink your Ovaltine\
ciphertext: or fher gb qevax lbhe Binygvar

### Vigenère
Vigenère's algorithm encrypts messages by rotating each letter by a sequence of keys. More formally, if p[i] is the ith letter of plaintext and c[i] is the ith letter of ciphertext, then c[i] = (p[i] + k[j]) % 26, where k[j] is the jth letter of key sequence.
* If the key sequence is shorter than plaintext, the key sequence must be re-used cyclically. 
* The key sequence consists of only alphabets and the alphabets correspond to shift value by A = 0, B = 1, ..., Z = 25.
* The key sequence must not distinguish uppercase or lowercase, but the output must.

This program takes an input key and a plaintext, encrypts it into ciphertext using Vigenère's algorithm. The program must reject illegal input.

input: a sequence of keys (alphabets) and plaintext\
output: ciphertext output by Vigenère's algorithm, ignoring any non-alphabets

Example:\
$ ./vigenere bacon\
plaintext:  Meet me at the park at eleven am\
ciphertext: Negh zf av huf pcfx bt gzrwep oz

### crack
This assignment includes encrypt.c and crack.c

This program cracks a password by brute-force. More specifically, it hashes each possible input and compare it to the hash, if they are the same, the input is the password.
* To simplify the assignment, assume the first 2 letters of the input is the salt.
* Assume that each password is no longer than five characters.
* Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase)

input: a hash\
output: the corresponding password

Example:\
$ ./crack 50cI2vYkF0YU2\
LOL

$ ./crack 508ny6Rw0aRio\
sean

$ ./crack 61v1CDwwP95bY\
hola

## Week 3
The assignments of week 3 include whodunit, one version of resize, and recover
Visit https://docs.cs50.net/2019/x/psets/3/index.html to see more details about the assignment

### whodunit
Given one bmp file, the assignment requests to reveal a hidden message in the file by imposing a filter to it. This assignment introduces the structure of bmp file and provides practices for image manipulation.

input: clue.bmp\
output: verdict.bmp (with hidden message revealed)

See verdict.bmp in the folder for the result.

### resize
This program enlarges 24-bit uncompressed BMPs by a factor of n. n must be an postiive integer less or equal to 100. The program must reject illegal input. This assignemnt introduces the structure of bmp file and provides practices for image manipulation.

input: an image\
output: the image resized by a factor of n

See smiley_large.bmp for the result.

### recover
This program recovers JPEGs from a forensic image.

input: card.raw file\
output: 50 recovered images

## Week 4
The assignments of week 4 include one version of speller (using hash table or trie)

### speller
This program loads a dictionary in the memory (using trie structure) and check word by word to count the number of mispelled words in a file. The assignment includes the implementation of load, check, size and unload function.

input: dictionary and a text file\
output: a list of misspelled words, and performance metrics of the program.

See results folder for the result of each text file.

## Week 6
The assignments of week 6 include 
* hello (in Python)
* mario (in python),
* one of cash or credit (in python)
* one of Caesar, Vigenère or crach (in python)
* bleep (in python)

### bleep
This program censors messages that contain words that appear on a list of supplied banned words.

input: a message\
output: a censored message

Example:\
$ python bleep.py banned.txt\
What message would you like to censor?\
what the heck\
what the ****

## Note
Please be advised that I did not do the assignment for week 5, 7, 8 and 10 (final project) as this part of the course focuses on web development, in which I am not interested.