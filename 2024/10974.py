def solve(cur):
    if(cur == N):
        print(" ".join(str(i) for i in arr))
        return
    for i in range(1, N + 1):
        if check[i] != 0: continue
        check[i] = 1
        arr[cur] = i
        solve(cur + 1)
        check[i] = 0

N = int(input())
arr = [0 for _ in range(0, N)]
check = [0 for _ in range(0, N + 1)]
solve(0)
