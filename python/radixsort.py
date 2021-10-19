

def countingsort(lst,exp1):
    output = [0 for _ in range(len(lst))]
    count = [0 for _ in range(10)]
    for i in range(0,len(lst)):
        idx = lst[i]/exp1
        count[int(idx%10)] += 1
    for i in range(1,10):
        count[i] += count[i-1]
    i = len(lst) -1
    while i >= 0:
        idx = lst[i]/exp1
        output[count[int(idx%10)]-1] = lst[i]
        count[int(idx%10)] -= 1
        i -= 1
    for i in  range(len(lst)):
        lst[i] = output[i]


def radixsort(lst):
    max1 = max(lst)
    exp1 = 1
    while int(max1/exp1) > 0:
        countingsort(lst, exp1)
        exp1 *= 10
    return lst


if __name__ =="__main__":
    lst =[59,79,44,35,76,32,23,98,34,56,78,44,55]
    print(radixsort(lst))
