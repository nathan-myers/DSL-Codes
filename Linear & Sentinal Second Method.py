# Code for reference which shows another method to approach the problem. Fix the errors too....

roll_num =[]

n=int(input("Enter number of students: "))
for i in range(n):
    num = int(input("Enter roll no: "))
    roll_num.append(num)
print(roll_num)

no=int(input("Enter the roll no to find: "))

def linear_search(n, key, roll_list):
    for i in range(0,n):
        if roll_list[i]==key:
            return i    
    return -1



def sentinal_search(roll_num,n,no):
    last = roll_num[n-1]
    roll_num[n-1] = no
    i = 0
    while(roll_num[i] != no):
        i += 1
    roll_num[n-1] = last
    if(i<n-1 or roll_num[n-1]==no):
        print("The roll no is present at ", i, " position")
    else:
        print("Roll number is not present")




while True:
    print("\n1. Linear Search\n2. Sentinal Search\n3. Exit")
    choice = int(input("Enter the choice: "))

    if choice == 1:
        result = linear_search(roll_num,no,n)
        if result == -1:
            print("Roll number is not present !!")
        else:
            print("Roll no ", roll_num[i], " is present at position ", i)    

    
    if choice == 2:
        sentinal_search(roll_num,n,no)


    if choice == 3:
        break

