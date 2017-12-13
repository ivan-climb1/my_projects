"""
    This program ask the user enter a positive integer,
    then calculates the factorial of a number.
"""
def main():

    # request a string from the user
    number = input("Hi! Pleaze, give me a positive integer\n")

    # if the string consist not only of digits,
    # then again request a string from the user
    while not(number.isdigit()):
        number = input("Give me only a positive integer\n")

    # get an integer number from a string
    number = int(number)

    # call the function fac(number), and print factorial
    print("The factorial of this number", fac(number))


def fac(number):

    if number == 0:
        return 1

    # recursively call the function fac(number - 1)
    return(number * fac(number - 1))


if __name__ == "__main__":
    main()

