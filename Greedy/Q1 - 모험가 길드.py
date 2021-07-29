def solution(N, fears):
    fears_set = set(fears)      # 중복을 제거한 공포도 집합 정의
    group_count = 0
    for fear in fears_set:
        # 각 공포도 수치를 가진 모험가가 공포도 수치 이상일 경우
        if fears.count(fear) >= fear:
            group_count += 1
    return group_count


print(solution(5, [2, 3, 1, 2, 2]))
