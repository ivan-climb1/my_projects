"""
    This program ask the user the string with numbers.
    Then sorting numbers with Insertion_Sort.
"""

import sys # Nedeed for 'exit()'

def main():

    print("Hi! Pleaze, enter some numbers in a row. And I will sort them!")
    # request a string from the user
    numbers = input().split()

    Check_numbers(numbers)

    print("You entered:")
    print(*numbers, sep = ' ')

    Insertion_Sort(numbers)

    print("After sorting:")
    print(*numbers, sep = ' ')


# This function check the string on integer
def Check_numbers(numbers):

    # nedeed to access list element
    i = 0
    for number in numbers:
        # if number not integer then exit() the programm
        if not number.isdigit():
            print("You must enter only the integer!")
            sys.exit(1)
        else:
            # change data type on int
            numbers[i] = int(number)
            i += 1


# This function sorting the list for O(n^2)
def Insertion_Sort(numbers):

    # create the variable equal a length numbers[]
    length = len(numbers)

    for i in range(length):

        # in a variable element write numbers[i]
        element = numbers[i]
        # counter for shift
        j = i

        # go to the top of the list
        while j > 0 and numbers[j - 1] > element:
            # if the number of the left is greater than element
            # then shift the number to the right
            numbers[j] = numbers[j - 1]
            # reduce j
            j -= 1

        # place the elment in the sorted part of the list
        numbers[j] = element


if __name__=="__main__":
    main()

