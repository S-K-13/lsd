#___PYTHON PROGRAM TO PERFORM MATRIX OPERATIONS___

r1=int(input("Enter the no of rows in M1:"))
c1=int(input("Enter the no of columns in M1:"))
r2=int(input("Enter the no of rows in M2:"))
c2=int(input("Enter the no of columns in M2:"))

print("Enter Matrix 1:\n")
M1 = [[0 for j in range (c1)] for i in range (r1)]
for i in range (0,r1):
    for j in range (0,c1):
        M1[i][j]=int(input(f"Enter the value for index [{i}][{j}]="))
print(M1)

print("Enter Matrix 2:\n")
M2 = [[0 for j in range (c2)] for i in range (r2)]
for i in range (0,r2):
    for j in range (0,c2):
        M2[i][j]=int(input(f"Enter the value for index [{i}][{j}]="))
print(M2)


def addition():
    if (r1==r2 and c1==c2):
        R = [[0 for j in range (c1)] for i in range (r1)]
        for i in range (0,r1):
            for j in range (0,c1):
                R[i][j] = M1[i][j] + M2[i][j]
        print("ADDITION OF MATRIX IS :")
        print(R)
    else:
        print("Addition cannot be done !!!")
        
            
def subtraction():
    if (r1==r2 and c1==c2):
        R = [[0 for j in range (c1)] for i in range (r1)]
        for i in range (0,r1):
            for j in range (0,c1):
                R[i][j] = M1[i][j] - M2[i][j]
        print("SUBTRACTION OF MATRIX IS :")
        print(R)
    else:
        print("Subtraction cannot be done !!!")
        
        
def multiplication():
    if (c1 != r2):
        print("Multiplication cannot be done because the number of columns in M1 is not equal to the number of rows in M2!")
    else:
        result = [[0 for j in range(c2)] for i in range(r1)]
        
        for i in range(r1):
            for j in range(c2):
                for k in range(c1):
                    result[i][j] += M1[i][k] * M2[k][j]
                    
        print("MULTIPLICATION OF MATRIX IS:")
        for row in result:
            print(row)


def transpose():
    matrix_choice = int(input("Enter 1 to transpose Matrix 1 or 2 to transpose Matrix 2: "))
    if (matrix_choice == 1):
        rows, cols = r1, c1
        matrix = M1
    elif (matrix_choice == 2):
        rows, cols = r2, c2
        matrix = M2
    else:
        print("Invalid choice!")
    
    T = [[0 for j in range(rows)] for i in range(cols)]
    for i in range(rows):
        for j in range(cols):
            T[j][i] = matrix[i][j]
    
    print("TRANSPOSED MATRIX:")
    print(T)

    
i=1
while(i==1):
    print("_ _ _Python Program To Perform Matrix Operations_ _ _")
    print("1.Addition of matrix.")
    print("2.Subtraction of matrix.")
    print("3.Multiplication of matrix.")
    print("4.Transpose of matrix.")
    
    ch=int(input("Enter your choice code:"))
    
    if(ch==1):
        addition()
    
    elif(ch==2):
        subtraction()
        
    elif(ch==3):
        multiplication()
        
    elif(ch==4):
        transpose()
    
    else:
        print("YOU ENTERED A WRONG CHOICE !!!")
        
    i=int(input("PRESS _1_ TO CONTINUE OR PRESS _0_ TO STOP:"))


