#이상원 5번 문제 풀이


#조합을 이용해서 문제를 풀어봄~
from itertools import combinations


#data들을 받는 부분
n,k = map(int,input().split())

data = list(map(int,input().split()))

#풀이
# 일단 n개중 2개를 뽑음
res = list(combinations(data,2))

#근데 문제 조건은 중복되는 것을 피하고 싶다고 했으니
#중복되게 뽑히는 것을 제외하면 끝
#ex. 1 3 2 3 2라 할 때 2가지를 뽑는다 하고
# 10가지 조합의 경우의 수에서 (3,3), (2,2)를 제외하면 됨

diff = len(data)-len(set(data))
print(len(res)-diff)
