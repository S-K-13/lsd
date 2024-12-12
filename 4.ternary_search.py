#Python program to perform "Ternary_search":

def ternary_search(arr, l, r, x):
    if r >= l:
        
        mid1 = l + (r - l) // 3
    
        mid2 = r - (r - l) // 3

        if arr[mid1] == x:
            return mid1
        if arr[mid2] == x:
            return mid2

    
        if x < arr[mid1]:
            return ternary_search(arr, l, mid1 - 1, x)
        
        elif x > arr[mid2]:
            return ternary_search(arr, mid2 + 1, r, x)

        else:
            return ternary_search(arr, mid1 + 1, mid2 - 1, x)

    
    return -1


def main():
    n = int(input("Enter the number of members: "))

    arr = []
    print("Enter the sorted roll numbers of " + str(n) + " members:")
    for i in range(n):
        num = int(input())
        arr.append(num)


    x = int(input("Enter the roll number to be searched: "))

    result = ternary_search(arr, 0, n - 1, x)


    if result != -1:
        print("Roll number " + str(x) + " is present at index " + str(result) + ".")
    else:
        print("Roll number " + str(x) + " is not present in the list.")

if __name__ == "__main__":
    main()
