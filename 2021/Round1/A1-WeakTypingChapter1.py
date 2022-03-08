def minimum_switches(W):
    res = -1
    current = 'F'
    for c in W:
        if c != current and c != 'F':
            current = c
            res += 1
    return max(res, 0)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        W = input()
        print(f"Case #{t + 1}: {minimum_switches(W)}")
