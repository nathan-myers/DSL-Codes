# FIX THE SELECTION SORT !!!!!!!!!

list = []

n = int(input("Enter number of elements: "))
print("Enter the values: ")
for i in range(n):
    elements = int(input(">> "))
    list.append(elements)

print("\n", list)

def selection_sort(list, n):
    for i in range(n):
        min_index = i

        for j in range(i+1, n):
            if list[j] < list[min_index]:
                min_index = j

            list[i], list[min_index] = list[min_index], list[i]
            # list[i] = list[min_index]
            # list[min_index] = list [i]
    
    return list

def bubble_sort(list, n):
    for i in range(n):
        for j in range(n-i-1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
    return list


print("Enter your choice: ")
while True:
    print("\n1. Selection Sort\n2. Bubble Sort\n3. Exit")
    choice = int(input("Enter the choice: "))

    if choice == 1:
        print(selection_sort(n, list))

    if choice == 2:
        print(bubble_sort(list, n))
    
    elif choice == 3:
        break

    else:
        print("Invalid choice entered !!")
