"""
    This program ask the user the string with numbers.
    Then sorting numbers with Bubble_Sort.
"""

import sys # Nedeed for 'exit()'

def main():

    print("Hi! Pleaze, enter some numbers in a row. And I will sort them!")
    # request a string from the user
    numbers = input().split()

    Check_numbers(numbers)

    print("You entered:")
    print(*numbers, sep = ' ')

    Bubble_Sort(numbers)

    print("After sorting:")
    print(*numbers, sep = ' ')


# This function check the string on integer
def Check_numbers(numbers):

    # nedeed to access elements of list
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
def Bubble_Sort(numbers):

    # length list - 1
    n = len(numbers) - 1
    # counter of passage
    counter = 1

    while (counter > 0):
        # zeroing the counter
        counter -= counter

        for i in range(n):

            if numbers[i] > numbers[i + 1]:
                # swap two numbers
                numbers[i], numbers[i + 1] = numbers[i + 1], numbers[i]
                # increase counter
                counter += 1


if __name__=="__main__":
    main()
    
