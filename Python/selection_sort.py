"""
    This program ask the user the string with numbers.
    Then sorting numbers with Selection_Sort.
"""

import sys # Nedeed for 'exit()'

def main():

    print("Hi! Pleaze, enter some numbers in a row. And I will sort them!")
    # request a string from the user
    numbers = input().split()

    Check_numbers(numbers)

    print("You entered:")
    print(*numbers, sep = ' ')

    Selection_Sort(numbers)

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
def Selection_Sort(numbers):

    # length of list numbers
    length = len(numbers)
    # in this variable contain the index of
    # the min number from the unsorted list
    index = 0

    # length - 1, because the last number does not need
    # in compare. It will be max
    for i in range(length - 1):

        element = numbers[i]

        swap = False

        # This cycle separate the list on sorted and
        # unsorted part. Move only on unsorted part.
        # i + 1, that not to compare numbers[i] < numbers[i]
        for j in range(i + 1, length):

            # find the min number
            if numbers[j] < element:
                # rewrite the element
                element = numbers[j]
                # remember index
                index = j
                # Therefore need a swap
                swap = True

        # swap, if find the min number
        if swap:
            bufer = numbers[i]
            numbers[i] = element
            numbers[index] = bufer


if __name__=="__main__":
    main()

