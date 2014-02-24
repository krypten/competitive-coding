result = [1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103]
for i in range(20):
    tmp = 1
    m = int(input())
    i = 1
    while tmp <= m:
        tmp *= result[i]
        i += 1
    tmp = tmp // result[i-1]
    print (tmp)
    
