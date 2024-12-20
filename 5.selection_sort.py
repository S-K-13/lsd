# Python program to perform Selection_sort:

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        
        min_idx = i
        
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        arr[i], arr[min_idx] = arr[min_idx], arr[i]


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        
        for j in range(0, n - i - 1):
            
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def print_top_five(arr):
    n = len(arr)
    print("Top 5 scores are:")
    for i in range(n - 1, n - 6, -1):
        if i >= 0: 
            print(arr[i])

def main():
    n = int(input("Enter the number of students: "))
    percentages = []
    print("Enter the percentages of students:")
    for i in range(n):
        percentage = float(input("Student " + str(i + 1) + ": "))
        percentages.append(percentage)
        
    selection_sorted = percentages[:]
    selection_sort(selection_sorted)
    print("Sorted list using Selection Sort:")
    for i in range(n):
        print(selection_sorted[i])

    bubble_sorted = percentages[:]
    bubble_sort(bubble_sorted)
    print("Sorted list using Bubble Sort:")
    for i in range(n):
        print(bubble_sorted[i])

    print_top_five(bubble_sorted)

if __name__ == "__main__":
    main()





