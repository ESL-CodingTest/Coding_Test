from itertools import combinations


def solution(N, M, balls):
    all_cases = list(combinations(balls, 2))    # 볼링공 2개를 고르는 경우 산출(조합 이용)
    # print(all_cases, len(all_cases))

    for case in all_cases:
        if case[0] == case[1]:      # 볼링공의 무게가 같으면 해당 경우 제거
            all_cases.remove(case)
    return len(all_cases)


print(solution(5, 3, [1, 3, 2, 3, 2]))
print(solution(8, 5, [1, 5, 4, 3, 2, 4, 5, 2]))