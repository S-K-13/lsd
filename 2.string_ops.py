#PYTHON PROGRAM OF STRING OPERATIONS

def longestword(string):
    string = string.split()
    print(max(string, key=len))

def freq_of_char(str):
    allfreq = {}
    for char in str2:
        if char in allfreq:
            allfreq[char] += 1
        else:
            allfreq[char] = 1
    print(str(allfreq))

def palindrome(string):
    reversed_str = ""
    for char in string:
        reversed_str = char + reversed_str
    if string == reversed_str:
        print("The string is Palindrome.")
    else:
        print("The string is not Palindrome.")

def substring(string):
    substring = input("Enter the word:")
    if string.find(substring) == -1:
        print("The substring is not present")
    else:
        print("Substring found at index:", string.find(substring))

def occ_of_word(string):
    word_count = {}
    for word in string.lower().split():
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    print("Word count:", word_count)
    s = input("Enter the word to find its occurrence: ").lower()
    if s in word_count:
        print(f"The word '{s}' occurs {word_count[s]} times.")
    else:
        print(f"The word '{s}' does not occur in the given string.")

i=1

while (i==1):
    print("___Python Program to compute String Operations___")
    print("1.To display word with the longest length.")
    print("2.To determine the frequency of occurrence of particular character in the string.")
    print("3.To check whether the string is palindrome or not.")
    print("4.To display index of first appearance of the substring.")
    print("5.To count the occurrences of each word in a given string.")

    ch=int(input("Enter the choice code:"))

    if (ch==1):
        string=input("Enter the string:")
        print("Longest word in the string:")
        longestword(string)

    elif (ch==2):
        str2=input("Enter the string:")
        print("Frequency of occurrence of each character in the string:")
        freq_of_char(str)

    elif (ch==3):
        string=input("Enter the string:")
        palindrome(string)

    elif (ch==4):
        string=input("Enter the string:")
        substring(string)

    elif (ch==5):
        string=input("Enter the string:")
        print("Count the occurrences of each word in a given string:")
        occ_of_word(string)

    else:
        print("You have entered a wrong choice !!!")
        
    i=int(input("PRESS '1' TO CONTINUE OR PRESS '0' TO STOP:"))
