from itertools import permutations


def solution(n, weak, dist):

    weak_len = len(weak)

    for i in range(weak_len):
        weak.append(weak[i] + n)

    answer = len(dist)
   #  print(answer)
    for i in range(weak_len):
        start = [weak[j] for j in range(i, i + weak_len)]  # 시작 지점

        friends = permutations(dist, len(dist))

        for k in friends:           # 탐색 시작
            friend_num = 0
            friends_count = 1
            max_len = start[0] + k[friend_num]  # 친구 하나가 확인할 수 있는 최대 거리
            print('start',start)
            #print('start[0]',start[0])
            print('k',k)
            print('k2',k[friend_num])
            print('max_len',max_len)

            for x in range(weak_len):
                if start[x] > max_len:      # check가능한 최대 거리를 넘을 경우
                    friend_num +=1          # 다음 친구로
                    #print('friend_num', friend_num)
                    if friends_count > len(k):      # 친구가 남아있지 않는 경우
                        break
                    friends_count +=1
                    max_len = start[x]+ k[friend_num]       # 최대 거리 업데이트

            answer = min(answer, friends_count)

    if answer > len(dist):
        return -1

    return answer




print(solution(12, [1, 5, 6, 10], [1, 2, 3, 4]))