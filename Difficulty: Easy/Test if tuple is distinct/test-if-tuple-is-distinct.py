arr = tuple(map(int, input().split()))

########### Write your code below ###############
# Check if the length of the tuple is equal to the length of the set of the tuple
if len(arr) == len(set(arr)):
    print("True")
else:
    print("False")

########### Write your code above ###############