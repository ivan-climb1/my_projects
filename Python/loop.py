""" This program ask number and out numbers of programmers"""

#get a positive integer
while True:
    n = input("Pleaze, give me positive integer <= 1000:\n")
    if n.isdigit():
        n = int(n)
        break


if n < 0 or n > 1000:
    print("get a coorect number!")

else:
    last = n % 100
    
    if 11 <= last <= 14:
        print(n, "программистов")
    else:
        last %= 10
        if last == 1:
            print(n, "программист")
        elif 2 <= last <= 4:
            print(n, "программиста")
        elif (5 <= last <= 9) or last == 0:
            print(n, "программистов")