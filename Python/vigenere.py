import sys # this is library for take arguments of first command
import cs50 # this is labrary for take strings from users

# encryption fynction
def encryption(letText, letKey, number):
    # formula for encryption
    buf = ((ord(letText) - number) + letKey) % 26 + number
    # ad global varibale "out"
    global out
    #add letter to out text
    out += chr(buf)

# if arguments not equally 2, print mistake and exit programm
if len(sys.argv) != 2:
    print("Usage: /home/cs50/pset2/vigenere <keyword>")
    exit(1)
    
# second argument is a key for encryption
key = sys.argv[1]

# if key consist not of letters, print error and exit programm
if not key.isalpha():
    print("Keyword must only contain letters A-Z and a-z")
    exit(1)
    
# change key to uppercase
key = key.upper()

# counter for repeate key
count = 0

# get from users string with text and convert it to list
text = list(cs50.get_string())

# create empty string for out text
out = ""

# go on text
for i in text:
    
    # repeate key
    count %= len(key)
    
    # create letterKey and zero it, for encryption 
    letKey = ord(key[count]) - 65
    
    # if symbol uppercase
    if i.isupper():
        # add couunter
        count += 1
        # function encryption
        encryption(i, letKey, 65)
    # if sumbol lowercase
    elif i.islower():
        # add counter
        count += 1
        #formula encryption
        encryption(i, letKey, 97)
    else:
        # add symbol to out text
        out += i
print(out)