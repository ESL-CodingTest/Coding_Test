#6 무지의 먹방 라이브
#각 음식을 먹는데 필요한 시간
food_times = list(map(int, input().split()))
#장애가 발생한 시간
k = int(input())

idx = 0
length = len(food_times)
for i in range(0, k):
    food_times[idx] -= 1
    while(True):
        idx += 1
        if idx >= length:
            idx %= length
        if food_times[idx] == 0:
            continue
        else:
            break

print(idx+1)