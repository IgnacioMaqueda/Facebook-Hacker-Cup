def maximum_without_drilling(N, C, adjacents):
    discovered = [False for _ in range(N)]
    path_to_maximum = [-1 for _ in range(N)]
    maximum = maximum_without_drilling_rec(C, adjacents, discovered, 0, path_to_maximum)
    erase_path(adjacents, path_to_maximum)
    return maximum


def maximum_without_drilling_rec(C, adjacents, discovered, v, path_to_maximum):
    discovered[v] = True
    maximum = 0
    for w in adjacents[v]:
        if not discovered[w]:
            path_w = maximum_without_drilling_rec(C, adjacents, discovered, w, path_to_maximum)
            if path_w > maximum:
                maximum = path_w
                path_to_maximum[v] = w
    return C[v] + maximum


def erase_path(adjacents, path_to_maximum):
    i = 0
    while i != -1:
        C[i] = 0
        j = path_to_maximum[i]
        if j > 0:
            adjacents[i].remove(j)
            adjacents[j].remove(i)
        i = j


def maximum_weight(N, C, adjacents):
    maximum = maximum_without_drilling(N, C, adjacents)
    return maximum + maximum_without_drilling(N, C, adjacents)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        C = [int(x) for x in input().split()]
        adjacents = [[] for _ in range(N)]
        for _ in range(N - 1):
            Ai, Bi = [int(x) for x in input().split()]
            adjacents[Ai - 1].append(Bi - 1)
            adjacents[Bi - 1].append(Ai - 1)
        print(f"Case #{t + 1}: {maximum_weight(N, C, adjacents)}")
