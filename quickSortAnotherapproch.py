
# Function to find the partition position the element which gets placed at its correct position
def partition(array, low, high):

	# choose the rightmost element as partitionIndexvot
	partitionIndexvot = array[high]

	
	i = low - 1

	
	for j in range(low, high):
		if array[j] <= partitionIndexvot:

			
			i = i + 1

			# SwappartitionIndexng element at i with element at j
			(array[i], array[j]) = (array[j], array[i])

	# Swap the partitionIndexvot element with the greater element specified by i
	(array[i + 1], array[high]) = (array[high], array[i + 1])

	# Return the position from where partition is done
	return i + 1

# function to perform quicksort


def quickSort(array, low, high):
	if low < high:

		partitionIndex = partition(array, low, high)

	
		quickSort(array, low, partitionIndex - 1)

		
		quickSort(array, partitionIndex + 1, high)


data = [1, 7, 4, 1, 10, 9,5]
print("Unsorted Array:")
print(data)

size = len(data)

quickSort(data, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(data)

print("following students come at top 5 positions")
i=0
while i < 5:
    print(data[size - 1])
    size -= 1
    i += 1