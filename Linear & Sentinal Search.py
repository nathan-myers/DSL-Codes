roll_list = []

n = int(input("Enter number of students: "))
for i in range(n):
    roll_no = int(input("Enter the roll number: "))
    roll_list.append(roll_no)
print(roll_list)

def linear_search(roll_list, n, key):   #Arguments: (array, no of elements, element to be searched for)
    count = 0
    for i in range(0, n):
        if roll_list[i] == key:
            print("The roll no ", roll_list[i], " is at position ", i)
            count = count + 1

    if count == 0:
        print("The roll no does not exist !!")

#Fix the sentinal part !!!!
def sentinal_search(roll_list, n, key):
    key = int(input("Enter the roll no: "))
    last = roll_list[n-1]
    roll_list[n-1] = key

    i=0

    while(roll_list[i] != key):
        i = i+1

    roll_list[n-1] = last

    if(i<n-1 or roll_list[n-1]):
        print("The roll no ", roll_list[i], " is present at ", i," position")
    else:
        print("The roll no does not exist !!")



while True:
    print("\n1. Linear Search\n 2. Sentinal Search\n 3. Exit\n")
    choice = int(input("Enter the choice: "))

    if choice == 1:
        key = int(input("Enter the roll no to find: "))
        linear_search(roll_list, n, key)

    elif choice == 2:
        sentinal_search(roll_list, n, key)
        

    elif choice == 3:
        break

    else:
        print("Invalid choice entered !!")
