# import sys
#
# n = int(sys.stdin.readline())
# cards = []
# for i in range(n):
#     cards.append(int(sys.stdin.readline()))
# cards.sort()
#
# cur_num, accumulate = 0, 0
# if n == 1:
#     print(0)
# elif n > 1:
#     for i in range(n):
#         cur_num = cur_num + cards[i]
#         if i >= 1:
#             accumulate += cur_num
#             # print(accumulate)
#
#     print(accumulate)

import sys
import heapq

N, cards = int(sys.stdin.readline()), []       # 카드의 수, 카드 리스트
for _ in range(N):
    heapq.heappush(cards, int(sys.stdin.readline()))        # 카드 개수 입력
# print(cards)
accumulate = 0   # 누적 카드 비교횟수

if N == 1:  # 카드의 개수가 1개일 경우, 카드 뭉치를 비교할 필요가 없으니 0 출력
    print(0)
else:
    while True:
        # 개수가 가장 적은 2개의 카드 뭉치를 pop
        min1 = heapq.heappop(cards)
        min2 = heapq.heappop(cards)
        accumulate += min1 + min2  # 누적 카드 비교횟수 갱신
        heapq.heappush(cards, min1 + min2)  # 현재의 카드 비교횟수 push
        print(cards)
        if len(cards) == 1:   # 남은 카드 뭉치개수가 1이면 카드 뭉치를 비교할 수 없으므로 break
            print(accumulate)
            break

