# Implement add, substract, subset functions using contain() function.
# You've done with different method
# Also try implementing all outputs with display() function


class Set:
    def __init__(self):
        self.set = []

    def display_set(self):
        print("Set:", self.set)

    def contain(self, element):
        return element in self.element

    def union_sets(self, other_set):
        union_set = list(self.set)
        for element in other_set:
            if element not in union_set:
                union_set.append(element)
        return union_set

    '''
        def union_sets(self, other_set):
            union_set = Set(self)           # Tried to iterate it by creating object but ain't working
            for element in other_set:
                if element not in union_set:
                    union_set.append(element)
            return union_set
    '''

    def intersection_sets(self, other_set):
        intersection_set = [element for element in self.set if element in other_set]
        return intersection_set

    def add_element(self, element):
        if element not in self.set:
            self.set.append(element)
            print(f"Element {element} added to the set.")
        else:
            print(f"Element {element} already exists in the set.")

    def subtract_sets(self, other_set):
        subtracted_set = [element for element in self.set if element not in other_set]
        return subtracted_set

    def contain(self, element):
        if element in other_set:
            return true
        else:
            return false

    def is_subset(self, other_set):
        for element in other_set:
            if element not in self.set:
                return False
        return True

    def remove_element(self, element):
        if element in self.set:
            self.set.remove(element)
            print(f"Element {element} removed from set.")
        else:
            print(f"Element {element} doesn't exist in set !!")

    def size(self):
        size = len(self.set)
        return size



def input_set():
    num_elements = int(input("Enter the number of elements: "))
    elements = []
    for i in range(num_elements):
        element = input("Enter an element: ")
        elements.append(element)
    return elements


set1 = Set()
set2 = Set()
set1.set = input_set()
set2.set = input_set()


while True:
    print("\nSet 1:")
    set1.display_set()
    print("\nSet 2:")
    set2.display_set()

    print("\nOptions:")
    print("1. Union")
    print("2. Intersection")
    print("3. Add Element to Set 1")
    print("4. Subtract Sets (Set 1 - Set 2)")
    print("5. Check if Set 1 is Subset of Set 2")
    print("6. Remove element form Set 1")
    print("7. Size of Set 1")
    print("8. Quit")

    ch = int(input("Enter the choice: "))

    if ch == 1:
        result = set1.union_sets(set2.set)
        print("Union of Set 1 and Set 2:", result)

    elif ch == 2:
        result = set1.intersection_sets(set2.set)
        print("Intersection of Set 1 and Set 2:", result)

    elif ch == 3:
        element = input("Enter an element to add to Set 1: ")
        set1.add_element(element)

    elif ch == 4:
        result = set1.subtract_sets(set2.set)
        print("Set 1 - Set 2:", result)

    elif ch == 5:
        is_subset = set2.is_subset(set1.set)
        print("Set 1 is a subset of Set 2:", is_subset)

    elif ch == 6:
        element = input("Enter an element to remove: ")
        set1.remove_element(element)

    elif ch == 7:
        size = set1.size()
        print(f"Size of Set 1 is: {size}")

    elif ch == 8:
        break

    else:
        print("Invalid choice. Please try again.")
