# def solution(food_times, k):
#     time_count, index, food_counts = 0, 0, len(food_times)
#     while True:
#         print(food_times, index, time_count)
#         # 더 섭취해야할 음식이 없다면(= food_times의 모든 원소가 0이면)
#         if all(food_time == 0 for food_time in food_times):
#             return -1
#         if time_count == k:
#             return index + 1
#         else:
#             if food_times[index] > 0:
#                 food_times[index] -= 1
#                 time_count += 1
#             index = index + 1 if index < (food_counts-1) else 0
#
# print(solution([1, 3, 5, 2, 3], 15))

# def solution(food_times, k):
#     food_counts = len(food_times)
#
#     if food_counts > k:
#         return k + 1
#     elif sum(food_times) < k:
#         return -1
#     else:
#         loop, remain = divmod(k, food_counts)
#         foods = list(map(lambda x: x - loop, food_times))
#         foods[:remain] = list(map(lambda x: x - 1, foods[:remain]))
#         print(foods)
#
#         food_index = food_counts * (int(k / food_counts) + 1)
#         for food in foods:
#             if food < 0:
#                 food_index += food
#         print(food_index)
#         return (food_index + 1) % food_counts + 1
#
#
# print(solution([3, 1, 2], 5))
# print(solution([1, 0, 3, 2], 5))

# def solution(food_times, k):
#     food_counts = len(food_times)
#
#     if food_counts > k:
#         return k + 1
#     elif sum(food_times) <= k:
#         return -1
#     else:
#         loop_count, prev_time = 1, 0
#         while True:
#             food_times = list(map(lambda x: x - 1, food_times))
#             time = food_counts * loop_count
#             for food_time in food_times:
#                 if food_time < 0:
#                     time += food_time
#             if time == k:
#                 for i in range(food_counts):
#                     if food_times[i] > 0:
#                         return i + 1
#             elif prev_time < k < time:
#                 differ, tmp = k - prev_time, 0
#                 for i in range(food_counts):
#                     if food_times[i] >= 0:
#                         tmp += 1
#                     if tmp == (differ + 1):
#                         return i+1
#             prev_time = time
#             loop_count += 1


def solution(food_times, k):
    food_counts = len(food_times)
    if food_counts > k:
        return k + 1
    else:
        start, end, loop, time = 1, 10000000, 0, 0
        while (end - start) >= 0:
            mid, temp = (start + end) // 2, 0
            last_idx_t = food_counts * mid
            for food_time in food_times:
                differ = food_time - mid
                if differ < 0:
                    last_idx_t += differ
            if last_idx_t <= k:
                loop, time = mid, last_idx_t
                start = mid + 1
            else:
                end = mid - 1
        differ_k = k - time
        food_times = [food_time - (loop + 1) for food_time in food_times]
        for i in range(food_counts):
            if food_times[i] >= 0:
                if differ_k == 0:
                    return i + 1
                else:
                    differ_k -= 1
        return -1

print(solution([3, 1, 2], 5))
print(solution([4, 1, 2, 5], 5))
print(solution([5, 1, 3, 8], 8))
