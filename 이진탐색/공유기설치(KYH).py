N, C = map(int, input().split())  #집 개수 # 공유기


house = []   #집 리스트

for _ in range(N):
    house.append(int(input()))

house.sort()
start = 1
end = house[-1] - house[0]
result = 0

while(start <= end):
    mid = (start+end)//2
    value = house[0]
    count = 1

    for i in range(1, len(house)):
        if house[i] >= value + mid:
            count += 1
            value = house[i]
    if count >= C:
        start = mid+1
        result = mid
    else:
        end = mid-1
print(result)


