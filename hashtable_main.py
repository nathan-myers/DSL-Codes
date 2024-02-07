# Implement to display no of comparison in display function & search function. No of comparisons is same for both.

class Hashtable:
    def __init__(self):
        self.size = int(input("Enter the size of table: "))
        self.element_count = 0
        self.comparison = 0
        self.table = list(-1 for i in range(self.size))  # This line can also be written as : self.table = [-1] * self.size

    def is_full(self):
        if self.element_count == self.size:
            return True
        return False

    def hash_function(self, key):
        return key % self.size

    '''
        def insert(self, key):
            if self.is_full():
                print("Table is full. Can't insert more elements !!")
                # return
                # self.comparison = 1
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
    '''

    def insert(self, key):
        if self.is_full():
            print("Table is full. Can't enter more elements.")
            return
        self.comparison = 1

        position = self.hash_function(key)

        while self.table[position] != -1:
            position = (position+1) % self.size
            self.comparison += 1

        self.table[position] = key
        print("Comparisons required: ", self.comparison)
        self.element_count += 1
        # return self.comparison

    def search(self, key):
        # When we enter element that is not present, the code doesn't work properly #
        position = self.hash_function(key)
        initial_position = position
        searches = 1

        while self.table[position] != key and self.table[position] != -1:
            position = (position + 1) % self.size
            searches += 1

        if self.table[position] == key:
            print(f"Key {key} found at index {position} with {searches} comparisons.")
        else:
            print(f"{key} not found in hash table")

    def display(self):
        # Wherever there is vacant space it is indicated by -1
        print("Index \t Key \t Comparisons")
        for i in range(self.size):
            print(f"{i} \t\t {self.table[i]} \t\t {self.comparison}")

    def remove(self, key):
        position = self.hash_function(key)
        original_position = position

        while self.table[position] != -1:
            if self.table[position] == key:
                print(f"{key} deleted from index {position}")
                self.table[position] = -1
                self.element_count = self.element_count - 1
                return
            position = (position+1) % self.size
            self.comparison = self.comparison + 1

        print(f"{key} not found in hash table")


obj = Hashtable()     # Creating object

while True:
    print("1.Insert\n2.Display\n3.Search\n4.Remove\n5.Exit")
    ch = int(input("Enter your choice"))

    if ch == 1:
        key = int(input("Enter the key: "))
        obj.insert(key)

    elif ch == 2:
        obj.display()

    elif ch == 3:
        key = int(input("Enter the key to search: "))
        obj.search(key)

    elif ch == 4:
        key = int(input("Enter the key to remove: "))
        obj.remove(key)

    elif ch == 5:
        break

    else:
        print("Invalid input !!")
