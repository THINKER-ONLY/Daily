import random
def Quicksortpivot(n,start,end):
    index = random.randint(start,end)
    n[start],n[index] = n[index],n[start]
    pivot = start
    j = start + 1
    for i in range(start+1, end+1):
        if n[i] <= n[pivot] :
            n[i] , n[j] = n[j] , n[i]
            j += 1
    n[pivot] , n[j-1] = n[j-1] , n[pivot]
    pivot = j - 1
    print(n[pivot], n[start:pivot] , n[pivot+1: end+1])
    return pivot

def Quicksort(n,start,end):
    if start >= end:
        return
    pivot = Quicksortpivot(n,start,end)
    Quicksort(n,start,pivot-1)
    Quicksort(n,pivot+1,end)

n = [78,56,9,5,3,6,5,89,63,44,55]
Quicksort(n,0,len(n)-1)
print(n)