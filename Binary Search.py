#Python program to perform binary search with recursive & non-recursive method

arr = []

n = int(input("Enter the number of elements: "))

print("Enter the elements in sequential order: ")
for i in range(n):
    elements = int(input(">> "))
    arr.append(elements)
print("\n",arr)


low = 0
high = n-1
mid = (low+high)//2


def binary_recursive(low, high, mid, key):
    
    while(low<=high):     #Use while loop here instead of for loop because for loop executes statements
                          #only under for loop. It doesn't go to function even if we call function. 
        mid = (low + high) // 2    #And becoz we need to call function again & again in recursive we 
                                   #need while loop
        if arr[mid] == key:
            print("The element ", arr[mid], " is at position ", mid)
            break

        elif arr[mid] < key:
            low = mid + 1
            return binary_recursive(low, high, mid, key)

        elif arr[mid] > key:
            high = mid - 1
            return binary_recursive(low, high, mid, key)
    else:
        print("The element is not present !!")
    


def binary_non_recursive(low, high, mid, key):

    for i in range(n):

        mid = (low + high) // 2

        if arr[mid] == key:
            print("The element ", arr[mid], " is at position ", mid)
            break

        elif arr[mid] < key:
            low = mid + 1

        elif arr[mid] > key:
            high = mid - 1

    else:
        print("The element is not present !!")


while True:
    print("\n1. Binary Search (with recursion)\n2. Binary Search (without recursuion)\n3. Exit\n")
    choice = int(input("Enter the choice: "))
    
    if choice == 1:
        key = int(input("Enter the element to find: "))
        binary_recursive(low, high, mid, key)

    elif choice == 2:
        key = int(input("Enter the element to find: "))
        binary_non_recursive(low, high, mid, key)

    elif choice == 3:
        break

    else:
        print("Invalid choice entered !!")
