import cs50

"""
Docstring: This function print mario bricks.
"""
while(True):
    input = cs50.get_int("Height: ")
    if(input > 0 and input < 9):
        break

for x in range(input):
    print(" " * (input - x - 1), end="")
    print("#" * (x + 1), end="")
    print(" " * 2, end="")
    print("#" * (x + 1))