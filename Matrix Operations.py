#Program for performing various matrix operations
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

def addition(A,B):

    result=[[0 for i in range(r)]for j in range(c)]
    for i in range(len(A)):
        for j in range(len(A[0])):
            result[i][j] = A[i][j] + B[i][j]
    print("The Addition of matrix is:")
    for final_mat in result:
        print(final_mat)

def subtraction(A,B):

    result=[[0 for i in range(r)]for j in range(c)]
    for i in range(len(A)):
        for j in range(len(A[0])):
            result[i][j] = A[i][j] - B[i][j]
    print("The Subtraction of matrix is:")
    for final_mat in result:
        print(final_mat)

def transpose(A):
    result = [[0 for i in range(r)] for j in range(c)]
    for i in range(len(A)):
        for j in range(len(A[0])):
            result[j][i] = A[i][j]

        print("TThe Transpose of matrix is: ")
        for final_mat in result:
            print(final_mat)


def multiplication(A,B):
    result = [[0 for i in range(len(A))]for j in range(c)]
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(B[0])):
                result[i][j] = result[i][j]+A[i][j]+B[k][j]

    print("The Multiplication of matrix is: ")
    for final_mat in result:
        print(final_mat)


while True:
    print("1. Addition\n 2. Subtraction\n 3. Transpose\n 4. Multiplication\n 5. Exit\n")
    operation=int(input("Enter your choice: "))


    if operation==1:
        print("Enter elements of matrix A:")
        A=matcreate(r,c)
        for i in A:
            print(i)

        print("Enter elements of matrix A:")
        B=matcreate(r,c)
        for i in B:
            print(i)

        addition(A,B)


    elif operation==2:
        print("Enter elements of matrix A:")
        A=matcreate(r,c)
        for i in A:
            print(i)

        print("Enter elements of matrix B:")
        B=matcreate(r,c)
        for i in B:
            print(i)

        subtraction(A,B)


    elif operation==3:
        print("Enter elements of matrix A:")
        A = matcreate(r,c)
        for i in A:
            print(i)
        print("Transpose of matrix is: ")
        #Calling transpose function
        transpose(A)


    elif operation==4:
        print("Enter elements of matrix A:")
        A=matcreate(r,c)
        for i in A:
            print(i)

        B = matcreate(r,c)
        for i in B:
            print(i)
        #Calling multiplication function
        multiplication(A,B)


    elif operation==5:
        break


    else:
        print("Invalid choice !!")
