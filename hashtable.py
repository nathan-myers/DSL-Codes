class HashTable:
    def __init__(self):
        self.size = int(input("ENTER SIZE OF HASH TABLE "))
        self.table = [-1] * self.size
        self.element_count = 0
        self.comparison = 0

    def is_full(self):
        return self.element_count == self.size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        if self.is_full():
            print("Hash table is full. Cannot insert more elements.")
            return
        self.comparison=1

        position = self.hash_function(key)

        while self.table[position] != -1:
            position = (position + 1) % self.size
            self.comparison += 1

        self.table[position] = key
        print("Comparisons Required:", self.comparison)
        self.element_count += 1

    def search(self, key):
        position = self.hash_function(key)
        initial_position = position
        searches = 1

        while self.table[position] != key and self.table[position] != -1:
            position = (position + 1) % self.size
            searches += 1

        if self.table[position] == key:
            print(f"Key {key} found at index {position} with {searches} comparisons.")
        else:
            print(f"Key {key} not found in the hash table.")

    def delete(self, key):
        position = self.hash_function(key)
        original_position = position

        while self.table[position] != -1:
            if self.table[position] == key:
                print(f"Key {key} deleted from index {position}.")
                self.table[position] = -1
                self.element_count -= 1
                return
            position = (position + 1) % self.size
            self.comparison += 1

        print(f"Key {key} not found in the hash table.")

    def display(self):
        print("Hash Table:")
        for i, value in enumerate(self.table):
            print(f"Index {i}: {value}")


HT = HashTable()

while True:
    print("1. INSERT")
    print("2. DISPLAY")
    print("3. SEARCH")
    print("4. DELETE")
    print("5.EXIT")

    CHOICE = int(input("Enter your choice: "))

    if CHOICE == 1:
        key = int(input("Enter the key: "))
        HT.insert(key)
    elif CHOICE == 2:
        HT.display()
    elif CHOICE == 3:
        key = int(input("Enter the key to search: "))
        HT.search(key)
    elif CHOICE == 4:
        key = int(input("Enter the key to delete: "))
        HT.delete(key)
    elif CHOICE == 5:
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a valid option.")




#The commented part is the code which I had originally typed. The code above is modified by someone in the lab
'''

# Implement to display no of comparison in display function
# Also implement search and delete

class Hashtable:
    def __init__(self):
        self.size = int(input("Enter the size of table: "))
        self.element_count = 0
        self.comparison = 0
        # self.comparison_count = 1
        self.table = list(-1 for i in range(self.size))

    def is_full(self):
        if self.element_count == self.size:
            return True
        return False

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        if self.is_full():
            print("Table is full !!")
        else:
            position = self.hash_function(key)
            self.comparison += 1

            if self.table[position] == -1:
                self.table[position] = key
                self.element_count += 1
            else:
                print("Collision occurs !!")

                while self.table[position] != -1:
                    position = (position + 1) % self.size
                    if position >= self.size:
                        position = 0              # This statement takes back the loop back to 0th index
                        self.table[position] = key
                        self.element_count += 1
                        self.comparison += 1
                        # self.comparison_count = self.comparison
                        # return self.comparison_count

    def display(self):
        # Wherever there is vacant space it is indicated by -1
        print("Index \t Key \t Comparisons")
        for i in range(self.size):
            print(f"{i} \t\t {self.table[i]} \t\t {self.comparison}")


obj = Hashtable()     # Creating object

while True:
    print("1.Insert\n2.Display\n3.Exit")
    ch = int(input("Enter your choice"))

    if ch == 1:
        key = int(input("Enter the key: "))
        obj.insert(key)

    elif ch == 2:
        obj.display()

    elif ch == 3:
        break

    else:
        print("Invalid input !!")

'''
