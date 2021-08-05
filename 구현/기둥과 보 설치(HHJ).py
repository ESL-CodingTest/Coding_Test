#기둥과 보 설치
def possible(result):
    ans = True
    for x,y,a in result:
        if a == 0:   #기둥인 경우
            if y == 0 or [x-1,y,1] in result or [x,y,1] in result or [x,y-1,0] in result:
                ans = True
            else:
                ans = False
                print(x,y,a)
                break
        elif a == 1:    #보인 경우
            if [x,y-1,0] in result or [x+1,y-1,0] in result or ([x-1,y,1] in result and [x+1,y,1] in result):
                ans = True
            else:
                ans = False
                print(x, y, a)
                break
    return ans


def solution(n, build_frame):
    result = []
    for x,y,a,b in build_frame:
        tmp = [x, y, a]
        if b == 1:  #설치인 경우
            result.append(tmp) #일단 설치
            if possible(result) == False:   #설치된 것이 가능한 구조인지 판단
                result.remove(tmp)          #불가능하다면 제거
        if b== 0:   #삭제인 경우
            result.remove(tmp)
            if possible(result) == False:
                result.append(tmp)

    result = sorted(result, key=lambda x : (x[0], x[1]))
    return result

print(possible([[0,0,0],[0,1,1],[1,1,1],[2,0,0]]))
print(solution(5, [[1,0,0,1], [1,1,1,1], [2,1,0,1], [2,2,1,1], [5,0,0,1], [5,1,0,1], [4,2,1,1], [3,2,1,1]]))