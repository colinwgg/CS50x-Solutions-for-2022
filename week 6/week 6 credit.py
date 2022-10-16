def sum(card):
    length = len(card)
    sum_of_card = 0
    for i in range(length - 2, -1, -2):
        digit = int(card[i]) * 2
        if digit >= 10:
            sum_of_card += digit % 10 + 1
        else:
            sum_of_card += digit
    for i in range(length - 1, -1, -2):
        sum_of_card += int(card[i])
    return sum_of_card


while True:
    id = input("Number: ")
    if id.isdigit():
        break
    print("Invalid, print again.")

if id.startswith("34") or id.startswith("37"):
    if not (len(id) == 15):
        print("INVALID")

    if sum(id) % 10 == 0:
        print("AMEX")
    else:
        print("INVALID")

elif id.startswith("51") or id.startswith("52") or id.startswith("53") or id.startswith("54") or id.startswith("55"):
    if not (len(id) == 16):
        print("INVALID")

    if sum(id) % 10 == 0:
        print("MASTERCARD")
    else:
        print("INVALID")

elif id.startswith("4"):
    if not (len(id) == 13 or len(id) == 16):
        print("INVALID")

    if sum(id) % 10 == 0:
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")