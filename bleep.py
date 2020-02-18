from cs50 import get_string
from sys import argv


def load(bleep):
    file = open(argv[1], "r")
    for line in file:
        bleep.add(line.rstrip("\n"))


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    bleep = set()
    load(bleep)
    print("What message would you like to censor?")

    words = get_string("").split(" ")

    for word in words:
        for item in bleep:
            if (word == item or word.lower() == item):
                words.insert(words.index(word), "*" * len(item))
                words.remove(word)
    print(" ".join(words))


if __name__ == "__main__":
    main()
