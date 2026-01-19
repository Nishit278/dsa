for _ in range(int(input())):
    n, m = map(int, input().split())
    if n > m:
        print("No")
        continue
    if n % 2:
        arr = "1 " * (n - 1) + str(m - n + 1)
        print("Yes")
        print(arr)
        continue
    if m % 2 == 0:
        arr = "1 " * (n - 2) + str((m - n + 2) // 2) + " " + str((m - n + 2) // 2)
        print("Yes")
        print(arr)
        continue
    print("No")