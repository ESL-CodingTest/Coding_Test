from itertools import combinations      # 조합 모듈 import


def solution(N, coins):
    sum_cases = set()       # 원소 중복을 방지하기 위하여 집합(set) 자료형 사용
    # 모든 코인 조합의 합 액수를 sum_cases에 저장
    for i in range(1, N + 1):
        com_cases = list(combinations(coins, i))
        for com_case in com_cases:
            sum_cases.add(sum(com_case))
    print(f'만들 수 있는 금액합의 모든 경우 : {sum_cases}')

    temp = {j for j in range(1, max(sum_cases) + 2)}    # sum_cases의 1 ~ (최댓값 + 1)의 원소를 가지는 임시 집합 정의

    return min(temp - sum_cases)    # 차집합을 통하여 만들 수 없는 금액의 최솟값 산출


print(solution(5, [3, 2, 1, 1, 9]))