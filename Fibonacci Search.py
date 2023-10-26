arr = []

n = int(input("Enter number of elements: "))

print("Enter the values: ")
for i in range(n):
    elements = int(input(">> "))
    arr.append(elements)
print("\n", arr)

key = int(input("Enter element to search: "))

def fibonacci(arr, key, n):
    offset = -1  # i.e start
    fn = 0
    f1 = 1
    f2 = 1

    while(f2 < n):
        fn = f1
        f1 = f2
        f2 = f1 + fn

        while(f2 > 1):
            i = min(offset + fn, n-1)

            if arr[i] < key:
                f2 = f1
                f1 = fn
                fn = f2 - f1
                offset = i
            
            elif arr[i] > key:
                f2 = fn
                f1 = f1 - fn
                fn = f2 - f1
            
            else:
                return i
        
        if f2 == 1 and arr[-1] == key:
            return i
    

while True:
    print("\n1. Fibonacci Search\n2. Exit\n")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        result = fibonacci(arr, key, n)
        print("\nThe element", key, " is present at index ", result)

    elif choice == 2:
        break

    else:
        print("Invalid choice !!")
