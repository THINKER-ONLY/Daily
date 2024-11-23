def Shellsort(n):
    a = len(n)
    gap = a // 2
    while gap > 0:
        for i in range(gap, a) :
            x = n[i]
            j = i
            while j >= gap:
                if x < n[j-gap] :
                    n[j] = n[j-gap]
                else:
                    break;
                j -= gap
            n[j] = x
        print(n)
        gap = gap // 2

n = [25,8,9,6,35,78,663,45,896]
Shellsort(n)
print(n)