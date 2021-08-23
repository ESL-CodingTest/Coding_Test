#정렬된 배열에서 특정수의 개수 구하기
#N개의 원소, 특정수 x, 수열 array
N, x = map(int, input().split())
array = list(map(int, input().split()))

#오름차순 정렬
array = sorted(array)

#index
start = 0
end = len(array) - 1
mid = 0

#x의 시작점을 찾는 이진탐색
while(start <= end):
    mid = (start + end) // 2
    if array[mid] < x:
        start = mid + 1
    else:
        end = mid - 1

x_s = start

start = 0
end = len(array) - 1

#x의 끝점을 찾는 이진탐색
while(start <= end):
    mid = (start + end) // 2
    if array[mid] <= x:
        start = mid + 1
    else:
        end = mid - 1

x_e = end
print(x_s)
print(x_e)
if x_e - x_s + 1 == 0:
    print(-1)
else:
    print(x_e - x_s + 1)