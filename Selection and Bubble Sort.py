list = []

n = int(input("Enter number of elements: "))
print("Enter the values: ")
for i in range(n):
    elements = int(input(">> "))
    list.append(elements)

print("\n", list)


# FIX THIS SORT
def selection_sort(list, n):
    for i in range(n-1):
        min_index = i

        for j in range(i+1, n):
            if list[i] < list[min_index]:
                min_index = j

            #list[i], list[min_index] = list[min_index], list[i]
            list[i] = list[min_index]
            list[min_index] = list [i]
    
    return list

print("Enter your choice: ")
while True:
    print("\n1. Selection Sort\n2. Bubble Sort\n3. Exit")
    choice = int(input("Enter the choice: "))

    if choice == 1:
        selection_sort(n, list)
    
    elif choice == 3:
        break
