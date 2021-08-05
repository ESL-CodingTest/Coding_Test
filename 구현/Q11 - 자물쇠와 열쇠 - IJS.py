# https://programmers.co.kr/learn/courses/30/lessons/60059
def solution(key, lock):
    k_len = len(key)
    l_len = len(lock)
    answer_key = lock.copy()
    for i in range(l_len):
        for j in range(l_len):
            if answer_key[i][j] == 1:
                answer_key[i][j] = 0
            elif answer_key[i][j] == 0:
                answer_key[i][j] = 1

    key_rotate_90 = rotate_90(key)
    key_rotate_180 = rotate_90(key_rotate_90)
    key_rotate_270 = rotate_90(key_rotate_180)
    key_rotate_list = [key, key_rotate_90, key_rotate_180, key_rotate_270]

    print(f'key : {key}')
    print(f'key 길이 : {k_len}')
    print(f'lock : {lock}')
    print(f'lock 길이 : {l_len}')
    print(f'정답 Key : {answer_key}')
    print('-------------------------------------------------------')
    print(f'원본 키 : {key}')
    print(f'90도 시계방향으로 회전한 키 : {key_rotate_90}')
    print(f'90도 시계방향으로 회전한 키 : {key_rotate_180}')
    print(f'90도 시계방향으로 회전한 키 : {key_rotate_270}')
    print('-------------------------------------------------------')


    for cur_key in key_rotate_list:
        for i in range(l_len * 2 - (l_len - k_len + 1)):
            cur_wide = get_wide(cur_key, k_len, l_len, i)
            for j in range(l_len * 2 - (l_len - k_len + 1)):
                if get_key(cur_wide, l_len) == answer_key:
                    return True
                cur_wide = shift_to_right(cur_wide, l_len)
    return False


def rotate_90(m):
    N = len(m)
    ret = [[0] * N for _ in range(N)]
    for r in range(N):
        for c in range(N):
            ret[c][N - 1 - r] = m[r][c]
    return ret


def get_key(wide, length):
    result = []
    for i in range(length):
        result.append(wide[length + i][length:length * 2])
    return result


def get_wide(key, k_len, l_len, d):
    wide = [[0 for _ in range(l_len * 3)] for _ in range(l_len * 3)]
    for i in range(k_len):
        wide[1 + i + d + (l_len - k_len)][1 + (l_len - k_len):1 + (l_len - k_len) + k_len] = key[i]
    return wide


def shift_to_right(m, l_len):
    for j in range(l_len * 3):
        m[j] = [0] + m[j][:(l_len * 3 - 1)]
    # print(m)
    return m


print(solution([[0, 0, 0],
                [1, 0, 0],
                [0, 1, 1]],

               [[1, 1, 1],
                [1, 1, 0],
                [1, 0, 1]]))


