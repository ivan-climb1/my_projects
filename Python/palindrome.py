"""
    This program checks the string on the palindrome.
"""
import sys # Nedeed for 'exit'

# request a string from the user
string = input("Hi! Pleaze, give me a string and I will check it on palindrome\n").lower()

# if the user entered an empty string, again request a string from the user
while string == "":
    string = input("Gine me not a null string, pleaze!\n").lower()

# create new string backward from 'string'
backward = string[::-1]

# compare two strings
if backward != string:
    print("NOT PALINDROME\nIt is nice to work with you, bye)")
    sys.exit(1)

print("SUCCESS! You string is a PALINDROME!\nIt is nice to work with you, bye)")

