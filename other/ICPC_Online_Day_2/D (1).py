import sys
input = sys.stdin.readline


infinity = float('inf')

def solve():

    n = int(input())

    CapacityCorolla, PriceCorolla, CapacityVigo, PriceVigo = map(int, input().split())
    
    a = list(map(int, input().split()))

    prefix = [0] * (n + 1)


    for i in range(n):
        prefix[i+1] = prefix[i] + a[i]

    arr = [[infinity, infinity] for _ in range(n + 1)]
    arr[0][0] = 0

    for i in range(1, n + 1):
        for j in range(i):

            s = prefix[i] - prefix[j]
            for Capacity, Price in [(CapacityCorolla, PriceCorolla), (CapacityVigo, PriceVigo)]:

                if s > Capacity:
                    continue


                if s >= Capacity // 2:    

                    if arr[j][0] < infinity: arr[i][0] = min(arr[i][0], arr[j][0] + Price)
                    if arr[j][1] < infinity: arr[i][1] = min(arr[i][1], arr[j][1] + Price)


                else:                         
                    if arr[j][0] < infinity: arr[i][1] = min(arr[i][1], arr[j][0] + Price)




    Answer = min(arr[n][0], arr[n][1])

    print(-1 if Answer == infinity else Answer)
    

solve()