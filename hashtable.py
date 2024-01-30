# Implement to display no of comparison in display function

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

