# C++14 기준 = 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다

N = int(input())

A = list(map(int, input().split()))

op = list(map(int, input().split()))

maximum = -1e9
minimum = 1e9
print(maximum)

def DepthFirstSearch(number, total, plus, minus, multiply, divide):
    global maximum, minimum

    if number == N:
        maximum = max(total, maximum)
        print('max',maximum)
        minimum = min(total, minimum)
        print('min', minimum)

        return 0

    if plus:
        DepthFirstSearch(number + 1, total + A[number], plus - 1, minus, multiply, divide)
        #DepthFirstSearch(2, 7, 0, 0, 1, 0)
    if minus:
        DepthFirstSearch(number + 1, total - A[number], plus, minus - 1, multiply, divide)
    if multiply:
        DepthFirstSearch(number + 1, total * A[number], plus, minus, multiply - 1, divide)
        #DepthFirstSearch(3,35,0,0,0,0)
    if divide:
        DepthFirstSearch(number + 1, int(total / A[number]), plus, minus, multiply, divide - 1)


DepthFirstSearch(1, A[0], op[0], op[1], op[2], op[3])
print('최대값', maximum)
print('최솟값', minimum)