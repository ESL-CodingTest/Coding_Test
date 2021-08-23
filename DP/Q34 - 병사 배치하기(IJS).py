from itertools import combinations


def check_sort(l):
    if l == sorted(l, reverse=True):   # nlogn
        # print(l, sorted(l, reverse=True))
        return True
    else:
        return False


N = int(input())
soldiers = list(map(int, input().split()))

# print(N, soldiers)

for i in range(1, N):   # n
    perms = list(combinations(soldiers, N - i))     # 2^n
    # print(perms)
    for perm in perms:  # n
        if check_sort(list(perm)):
            print(i)
            quit()
