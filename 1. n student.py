#Python program to store marks scored in Fundamental of Data Structure by N students in class:

import array as arr
marks = arr.array('i', [])
n = int(input("Enter the number of students: "))
for i in range(n):
    element = int(input("Enter marks of the student: "))
    marks.append(element)


def absent_stu(marks):
    count = 0
    for mark in marks:
        if mark == -1:
            count += 1
    print(f"Number of absent students: {count}")


def avg_stu(marks):
    total = 0
    count = 0
    absent_count = 0
    for mark in marks:
        if mark != -1:
            total += mark
            count += 1
        else:
            absent_count += 1
    if count > 0:
        average = total / count
        print(f"Average score of the class: {average:.2f}")
    else:
        print("No valid marks available to calculate average.")


def highest(marks):
    highest_mark = -999
    for mark in marks:
        if mark != -1 and mark > highest_mark:
            highest_mark = mark
    if highest_mark != -999:
        print(f"Highest marks scored: {highest_mark}")
    else:
        print("No valid marks available to determine the highest score.")


def lowest(marks):
    lowest_mark = 999
    for mark in marks:
        if mark != -1 and mark < lowest_mark:
            lowest_mark = mark
    if lowest_mark != 999:
        print(f"Lowest marks scored: {lowest_mark}")
    else:
        print("No valid marks available to determine the lowest score.")


def highest_scorers(marks):
    highest_mark = -999
    count = 0
    for mark in marks:
        if mark != -1 and mark > highest_mark:
            highest_mark = mark
    for mark in marks:
        if mark == highest_mark:
            count += 1
    if highest_mark != -999:
        print(f"Number of students who scored the highest mark ({highest_mark}): {count}")
    else:
        print("No valid marks available to count highest scorers.")


i = 1
while i == 1:
    print("\n--- Python program to store marks scored in Fundamental of Data Structure by N students in class ---")
    print("1. Total number of absent students.")
    print("2. Average score of the class.")
    print("3. Highest mark among N students.")
    print("4. Lowest mark among N students.")
    print("5. Total number of students who scored the highest mark.")

    ch = int(input("Enter the choice code: "))

    if ch == 1:
        absent_stu(marks)
    elif ch == 2:
        avg_stu(marks)
    elif ch == 3:
        highest(marks)
    elif ch == 4:
        lowest(marks)
    elif ch == 5:
        highest_scorers(marks)
    else:
        print("Entered a wrong choice.")

    i = int(input("PRESS '1' TO CONTINUE OR PRESS '0' TO STOP: "))

