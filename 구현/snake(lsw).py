'''
초기 세팅~
'''
# 행렬 생성.
n = int(input())
geo = [[0]*(n+1) for _ in range(n+1)]
geo[1][1] = 2

#1은 사과 위치 2는 뱀
k = int(input())
for _ in range(k):
  a, b =map(int, input().split())
  geo[a][b] = 1

l = int(input())
d= dict()
for _ in range(l):
  a, b =map(str, input().split())
  d[int(a)]=b
  
tm = list(d.keys())
tm_p = 0

#print(geo)
#print(d.keys())




def game_out( x, y):
  if x < 1 or x >n or y<1 or y>n:
    return True
  else:
    if geo[y][x] == 2:
      return True


# 서 남 북 동
def change_direction(di, ch):
  if di == 0 and ch =='L':
    return 2
  elif di ==0 and ch =='D':
    return  1
  elif di ==1 and ch =='L':
    return  0
  elif di ==1 and ch =='D':
    return  3
  elif di ==2 and ch =='L':
    return  3
  elif di ==2 and ch =='D':
    return  0
  elif di ==3 and ch =='L':
    return  1
  elif di ==3 and ch =='D':
    return  2

def move_snake():

  pass

x = 1
y = 1

#   서 남 북  동
dx=[1, 0, 0, -1]
dy=[0, 1, -1, 0]
direction =0

snake_pos_x=[x]
snake_pos_y=[y]

cnt = 0
while True:
    
    if cnt == tm[tm_p]:
      direction = change_direction(direction, d[tm[tm_p]])
      nx = x + dx[direction]
      ny = y + dy[direction]
      if len(tm)-1 > tm_p:
        tm_p+=1
      else:
        tm_p =len(tm)-1
    else:
      nx = x + dx[direction]
      ny = y + dy[direction]
    cnt+=1
    
    
    #print(nx,ny,direction,cnt)
    if game_out(nx,ny):
      break

    if geo[ny][nx] == 0:
      geo[snake_pos_y[0]][snake_pos_x[0]]= 0
      del snake_pos_x[0]
      del snake_pos_y[0]
      snake_pos_x.append(nx)
      snake_pos_y.append(ny)
      geo[ny][nx]= 2
    elif geo[ny][nx] == 1:
      snake_pos_x.append(nx)
      snake_pos_y.append(ny)
      geo[ny][nx]=2
    '''
    for i in range(n):
      for j in range(n):
        print(geo[i][j],end=' ')
      print()
    '''

    x =nx
    y =ny


print(cnt)


