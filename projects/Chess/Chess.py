import numpy as np
import matplotlib.pylab as plt

def possible(x,y,board):
    if x<0 or y<0 or x>=N or y>=M:
        return False
    elif x+y*N in board:
        return False
    else:
        return True
def move(x,y,board):
    option={1:[1,-2],
             2:[-1,-2],
             3:[-2,1],
             4:[-2,-1],
             5:[-1,2],
             6:[1,2],
             7:[2,-1],
             8:[2,1]}
    i=0
    while True:
        i+=1
        index=np.random.randint(1,9)
        dx=x+option[index][0]
        dy=y+option[index][1]
        if possible(dx,dy,board):
            break
        elif i>20:
                board=[]
    board.append(dx+N*dy)
    return dx,dy,board
def print_board(board,name):
    x=np.zeros(N*M)
    for i in board:
        x[i]=1.
    x[board[-1]]=2
    x_plot=x.reshape((N,M))
    plt.imshow(x_plot)
    plt.savefig(name)
    plt.close()

N=8
M=8
x,y,board=0,0,[0]

name=0
while len(board)<N*M:
    x,y,board=move(x,y,board)
    #print(board,len(board))
    print_board(board,"images/"+str(name).zfill(3))
    name+=1
    if name==100:
        break
