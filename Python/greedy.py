import cs50
coinsNominals = [25, 10, 5, 1]
index = 0
count = 0
g1 = 0
dollar = -1
while dollar < 0:
    print("O hai! How mach change is owed?")
    dollar = cs50.get_float()
cent = dollar * 100
while cent > 0:
    if cent >= coinsNominals[index]:
        cent -= coinsNominals[index]
        count += 1
        continue
    index += 1
print(count)