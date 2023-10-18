'''
1. Check whether given string is palindrome or not.
2. Find frequency of given char in string.
3. Find the longest length word from the string.
4. Find the frequency of each word from given string.
5. Find the index of first substring
'''


def palindrome(str):

    rev_str = ""
    for i in range(len(str), 0, -1):        #for i in range(initial val, final val, incrmt/decrmnt)
        rev_str = rev_str + str[i-1]        #Here [i-1] is taken because index starts from zero
    print("The reverse string is:", rev_str) #Here, 'i' is having integer value


    if rev_str ==  str:
        print("The string ", str, " is a palindrome.")
    else:
        print("The string ", str, " is not a palindrome.")

def char_freq(str):
    count = 0
    char = input("Enter the character: ")
    for i in str:         # Here i is having string type value because we haven't
        if char==i:       # used len(str) function here which has integer type value
            count = count + 1
    print("The ",char, " is printed", count, " times")


def longest_word(str):
    split_str = str.split(" ")
    print(split_str)
    longest_str = ""
    for i in split_str:
        if len(i) > len(longest_str):
            longest_str = i
    print("The longest word is: ", longest_str)


def word_freq(str):
    split_str = (str.split(" "))
    print(split_str)
    new_list=[]
    for i in split_str:
        if i not in new_list:
            new_list.append(i)
    print(new_list)

    for i in range(len(new_list)):
        print("Frequency of ", new_list[i], " is: ", split_str.count(new_list[i]))

def first_substr_index(str):
    sub_str = input("Enter substring to be found: ")

    split_str = list((str.split(" ")))
    print(split_str)
    new_list=[]

    for i in split_str:
        if i not in new_list:
            new_list.append(i)
    print(new_list)

    for i in range(len(new_list)):
        if new_list[i] == sub_str:
            print("The first appearance of ", new_list[i], " is at position ", i)



while True:
    print("\n1. Palindrome\n2. Frequency of given char in string\n3. Longest length word from the string\n"
          "4. Frequency of each word\n5. Index of first substring\n6. Exit\n")
    choice = int(input("Enter the choice: "))


    if choice == 1:
        str = input("Enter the string: ")
        palindrome(str)

    elif choice == 2:
        str = input("Enter the string: ")
        char_freq(str)

    elif choice == 3:
        str = input("Enter the string: ")
        longest_word(str)

    elif choice == 4:
        str = input("Enter the string: ")
        word_freq(str)

    elif choice == 5:
        str = input("Enter the string: ")
        first_substr_index(str)

    elif choice == 6:
        break

    else:
        print("Invalid Input !!")

