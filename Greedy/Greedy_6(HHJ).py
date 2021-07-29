#6 무지의 먹방 라이브
#각 음식을 먹는데 필요한 시간
food_times = list(map(int, input().split()))
#장애가 발생한 시간
k = int(input())

idx = 0
length = len(food_times)
num = 0

for i in range(0, k):
    print(idx)
    food_times[idx] -= 1
    print(food_times)
    for j in range(0, length):
        idx = (idx + 1) % length
        if(food_times[idx] != 0):
            break
        else:
            num += 1
            print(num)
    if(num == length):
        result = -1
        break


print(result)