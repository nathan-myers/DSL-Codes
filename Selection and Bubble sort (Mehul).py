num_list=[]
temp = []

num = int(input("Enter the total number of elements: "))

for i in range(num):
    num1 = int(input("Enter the elements: "))
    num_list.append(num1)

print()
print(num_list)


def selectionSort(num_list, num):
   
    for i in range(num):
        min_index = i

        for j in range(i+1, num):  

            if num_list[j] < num_list[min_index]:

                min_index = j

        num_list[i], num_list[min_index] = num_list[min_index], num_list[i]

    return num_list


def bubbleSort(num_list):

    for i in range(num):
        for j in range(0, num-i-1):
            if num_list[j] > num_list[j+1]:
                num_list[j], num_list[j+1] = num_list[j+1], num_list[j]
    return num_list


while True:

    print("\n 1.Selection Sort\n 2.Bubble sort\n 3. Exit")

    choice=int(input("Enter your choice: "))
    

    if choice == 1:

        print(selectionSort(num_list, num))
        

    elif choice == 2:

        print(bubbleSort(num_list))


    elif choice == 3:

        break

    else:

        print("Invalid Choice")
