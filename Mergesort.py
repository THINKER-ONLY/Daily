def Merge(n,start,mid,end):
    tmp = []
    l = start
    r = mid + 1
    while l <= mid and r <= end :
        if n[l] <= n[r]:
            tmp.append(n[l])
            l += 1
        else :
            tmp.append(n[r])
            r += 1
    tmp.extend(n[l:mid+1])
    tmp.extend(n[r:end+1])
    for i in range(start, end+1):
        n[i] = tmp[i-start]
    print(start,end,tmp)

def Mergesort(n,start,end):
    if start == end :
        return
    mid = (start + end) // 2
    Mergesort(n, start, mid)
    Mergesort(n, mid+1, end)
    Merge(n, start, mid, end)

n = [16,9,11,4,5,78,26,54,23,3,45,12,6,5]
Mergesort(n,0,len(n)-1)
