def minimum_to_win(N, C):
    minimum = N + 1
    for i in range(N):
        possible = True
        if C[i].count('O') > 0:
            possible = False
        spaces = C[i].count('.')
        if possible:
            if spaces < minimum:
                minimum = spaces
                count = 1
            elif spaces == minimum:
                count += 1
    for j in range(N):
        spaces = 0
        possible = True
        for i in range(N):
            if C[i][j] == 'O':
                possible = False
                break
            elif C[i][j] == '.':
                k = i
                spaces += 1
        if possible:
            if spaces < minimum:
                minimum = spaces
                count = 1
            elif spaces == minimum:
                if spaces > 1 or C[k].count('X') < N - 1:
                    count += 1
    if minimum > N:
        return ["Impossible"]
    else:
        return minimum, count


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        C = []
        for i in range(N):
            C.append(input())
        print(f"Case #{t + 1}: ", end='')
        print(*minimum_to_win(N, C))
