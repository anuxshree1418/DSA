# Linear Search
input_list = input("Enter the elements using spaces: ")
num_list = input_list.split()
num_list = [int(item) for item in num_list]

x = int(input("Enter the key: "))

for i in range(len(num_list)):  
    if num_list[i] == x:
        print("at", i, "th index")  
print("-1")