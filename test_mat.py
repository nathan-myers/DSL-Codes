#Program for addition of two matrix
r=int(input("Enter no of rows:"))
c=int(input("Enter no of columns"))
def matcreate(r,c):
    out = []
    for i in range(0, r):
        row = []
        for j in range(0, c):
            k = int(input("Enter values:"))
            row.append(k)
        out.append(row)
    return out

def mat_add(A,B):

    result=[[0 for i in range(r)]for j in range(c)]
    for i in range(len(A)):
        for j in range(len(A[0])):
            result[i][j] = A[i][j] + B[i][j]
    print("The Addition of matrix is:")
    for final_mat in result:
        print(final_mat)

def mat_sub(A,B):

    result=[[0 for i in range(r)]for j in range(c)]
    for i in range(len(A)):
        for j in range(len(A[0])):
            result[i][j] = A[i][j] - B[i][j]
    print("The Subtraction of matrix is:")
    for final_mat in result:
        print(final_mat)

while True:
    print("1. Addition\n 2. Subtraction\n 3. Transpose")
    operation=int(input("Enter your choice: "))

    if operation==1:
        A=matcreate(r,c)
        for i in A:
            print(i)

        B=matcreate(r,c)
        for i in B:
            print(i)

        mat_add(A,B)

    elif operation==2:
        A=matcreate(r,c)
        for i in A:
            print(i)

        B=matcreate(r,c)
        for i in B:
            print(i)

        mat_sub(A,B)
    elif operation==3:
        result = [[0 for i in range(r)]for j in range(c)]
        for i in range(len(A)):
            for j in range(len(A[0])):
                result[j][i] = A[i][j]

        print("The transpose of matrix is: ")
        for final_mat in result:
            print(final_mat)



