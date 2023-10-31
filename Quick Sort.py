list = []

n = int(input("Enter number of elements: "))
print("Enter the values: ")
for i in range(n):
    elements = int(input(">> "))
    list.append(elements)

def partition(list, low, high):
    pivot = list[high]
    i = low - 1

    for j in range(low, high):
        if list[j] <= pivot:
            i = i + 1

            (list[i], list[j] = list[j], list[i])
    
    (list[i+1], list[high] = list[high], list[i+1])
    
    return i + 1

def quick_sort(list, low, high):
    if low < high:
        temp = partition(list, low, high)
        quick_sort(list, low, temp - 1)
        quick_sort(list, temp + 1, high)

while True:
    print("\n1. Quick Sort\n2. Exit")
    choice = int(input("Enter the choice: "))

    if choice == 1:
        print(quick_sort(list, 0, n - 1))

        for i in list:
            print(i, end=" ")

    elif choice == 2:
        break

    else:
        print("Invalid choice !!") 
