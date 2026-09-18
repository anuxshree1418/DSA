user_input = input("Enter a list of numbers separated by spaces: ")
num_list = [int(num) for num in user_input.split()]
sorted_list = sorted(num_list)
print("Sorted list:", sorted_list)