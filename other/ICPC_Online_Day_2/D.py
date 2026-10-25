import sys
input = sys.stdin.readline

IINF = 10**18

def solve():
    n = int(input())
    CapacityCorolla, PriceCorolla, CapacityVigo, PriceVigo = map(int, input().split())
    a = list(map(int, input().split()))

    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i+1] = prefix[i] + a[i]

    arr0 = [IINF] * (n + 1)
    arr1 = [IINF] * (n + 1)
    arr0[0] = 0

    maxCap = max(CapacityCorolla, CapacityVigo)

    for i in range(1, n + 1):
        pi = prefix[i]
        b0 = IINF
        b1 = IINF

        for j in range(i - 1, -1, -1):
            s = pi - prefix[j]
            if s > maxCap:
                break

            d0 = arr0[j]
            d1 = arr1[j]

            if s <= CapacityCorolla:
                if 2 * s >= CapacityCorolla:
                    c = d0 + PriceCorolla
                    if c < b0: b0 = c
                    c = d1 + PriceCorolla
                    if c < b1: b1 = c
                else:
                    c = d0 + PriceCorolla
                    if c < b1: b1 = c

            if s <= CapacityVigo:
                if 2 * s >= CapacityVigo:
                    c = d0 + PriceVigo
                    if c < b0: b0 = c
                    c = d1 + PriceVigo
                    if c < b1: b1 = c
                else:
                    c = d0 + PriceVigo
                    if c < b1: b1 = c

        arr0[i] = b0
        arr1[i] = b1

    Answer = min(arr0[n], arr1[n])
    print(-1 if Answer >= IINF else Answer)


solve()
