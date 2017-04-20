n = int(input("Pleaze, give positive integer\n"))

def main():
    if n < 0:
        print("Not negativ!!")
        exit(1)
    print(fac(n))

def fac(number):
    if number == 0:
        return 1
    return(number * fac(number - 1))

if __name__ == "__main__":
    main()