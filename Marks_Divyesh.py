def average(n):
    sum=0
    avg=0
    for i in range(n):
        if marklist[i] != 'A':
            sum = sum + int(marklist[i])
    print(sum)
    average = sum // n
    print("The average of marks is: ", average)

def absent():
    choice = 0
    for i in range(len(marklist)):
        if marklist[i]=='A':
            choice+=1
    print("Total number of absent students: ", choice)


def highest_marks():
    for i in range(len(marklist)):
        if marklist[i] != 'A':
            highest = marklist[i]
            break

    for i in range(len(marklist)):
        if marklist[i] != 'A':
            if marklist[i] > highest:
                highest = marklist[i]

    print("The highest marks is: ", highest)

def lowest_marks():
    for i in range(len(marklist)):
        if marklist[i] != 'A':
            lowest = marklist[i]
            break

    for i in range(len(marklist)):
        if marklist[i] != 'A':
            if marklist[i] < lowest:
                lowest = marklist[i]

    print("The lowest marks is: ", lowest)

def highest_freq():
    frequency = 0
    count = 0  # initial will be equal to initial value of i from loop
    initial = 0

    for i in range(len(marklist)):
        frequency = marklist.count(marklist[i])
        if frequency > count:
            count = frequency
            initial = i
    print("The highest frequency of ", marklist[initial], " and it occurs ", count, " times.")




marklist=[]
n = int(input("Enter number of students: "))

print("Enter marks of students. Enter 'A' if student is absent.")

for i in range(n):
    marks=input("Enter marks: ")
    marklist.append(marks)
print(marklist)

while True:
    print("1. Average\n 2. Count of absent students\n 3. Lowest marks\n 4. Highest marks\n"
          "5. Marks with highest frequency\n 6. Exit\n")

    choice = int(input("Enter the choice: "))

    if choice==1:
        average(n)

    elif choice==2:
        absent()

    elif choice==3:
        lowest_marks()

    elif choice==4:
        highest_marks()

    elif choice==5:
        highest_freq()

    elif choice==6:
        break


