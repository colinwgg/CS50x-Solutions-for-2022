def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
        except ValueError:
            print("This is not an integer")
    return n


def main():
    h = get_height()
    for row in range(h):
        for i in range(h - 1 - row, 0, -1):
            print(" ", end="")
        for i in range(row + 1):
            print("#", end="")
        print("  ", end="")
        for i in range(row + 1):
            print("#", end="")
        print()


if __name__ == "__main__":
    main()