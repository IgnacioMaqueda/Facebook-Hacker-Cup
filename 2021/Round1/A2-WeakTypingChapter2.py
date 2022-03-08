def sum_minimum_switches(N, S):
    res = 0
    current = 'F'
    previous_index = -1
    for i in range(N):
        if S[i] != 'F':
            if S[i] != current:
                res += (previous_index + 1) * (N - i)
                current = S[i]
            previous_index = i
    return res % 1000000007


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        S = input()
        print(f"Case #{t + 1}: {sum_minimum_switches(N, S)}")
