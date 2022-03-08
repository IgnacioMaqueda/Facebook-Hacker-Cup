def get_intersections(N, M, A, B):
    res = [[1 for _ in range(M)] for _ in range(N)]
    res[0][0] = A - (M + N - 2)
    res[0][M - 1] = B - (M + N - 2)
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, M, A, B = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: ", end='')
        if A < N + M - 1 or B < N + M - 1:
            print("Impossible")
        else:
            print("Possible")
            intersections = get_intersections(N, M, A, B)
            for i in range(N):
                print(*intersections[i])
