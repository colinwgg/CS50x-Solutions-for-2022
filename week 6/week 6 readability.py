text = input("Text: ")
ctl = ctw = cts = 0
for i in range(len(text)):
    if text[i].isalnum():
        ctl += 1
    if text[i].isspace():
        ctw += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        cts += 1
ctw += 1
L = ctl / ctw * 100.0
S = cts / ctw * 100.0
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")