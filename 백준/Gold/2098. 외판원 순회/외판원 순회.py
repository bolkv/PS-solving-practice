# TSP Algorithm
# Traveling Sales Person Algorithm
INF = 9999999999
dp = []
maps = []
N = int(input())

for i in range(N):
    maps.append(list(map(int, input().split())))

dp = [[-1 for _ in range(1 << (N + 1))] for _ in range(N)]


def min(a, b):
    if a > b:
        return b
    else:
        return a


def tsp(current, visited):

    if visited == ((1 << N) - 1):
        if maps[current][0] == 0:
            return 100000
        return maps[current][0]

    # 방문했던 곳은(최적화 된 곳) 리턴
    if dp[current][visited] != -1:
        return dp[current][visited]

    # 방문하지 않은 도시 탐색
    dp[current][visited] = INF

    for i in range(N):
        if visited & 1 << i == (1 << i):
            continue
        if maps[current][i]==0:
            continue
        dp[current][visited] = min(
            dp[current][visited], maps[current][i] + tsp(i, (visited | 1 << i))
        )

    return dp[current][visited]


answer = tsp(0, 1)
print(answer)
