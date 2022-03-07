def floyd_min_paths(paths):
    for k in range(26):
        for i in range(26):
            for j in range(26):
                paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j])


def minimum_seconds(S, paths):
    letters = [0 for _ in range(26)]
    for c in S:
        letters[ord(c) - ord('A')] += 1
    objective = [0 for _ in range(26)]
    for o in range(26):
        for i in range(26):
            if letters[i] > 0:
                if paths[i][o] == 50:
                    objective[o] = 5000
                    break
                else:
                    objective[o] += paths[i][o] * letters[i]
    res = min(objective)
    return -1 if res == 5000 else res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        S = input()
        K = int(input())
        paths = [[50 for _ in range(26)] for _ in range(26)]
        for i in range(26):
            paths[i][i] = 0
        for i in range(K):
            AB = input()
            Ai = ord(AB[0]) - ord('A')
            Bi = ord(AB[1]) - ord('A')
            paths[Ai][Bi] = 1
        floyd_min_paths(paths)
        print(f"Case #{t + 1}: {minimum_seconds(S, paths)}")
