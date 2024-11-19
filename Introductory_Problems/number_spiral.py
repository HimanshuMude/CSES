import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	x,y=map(int,input().split())

	greater=max(x,y)
	if greater%2==0:
		sx,sy=greater,1
		dif=abs(x-sx)+abs(y-sy)
		ele=greater**2
		ele-=dif
		print(ele)
	else:
		sx,sy=1,greater
		dif=abs(x-sx)+abs(y-sy)
		# print("debug",dif)
		ele=greater**2
		ele-=dif
		print(ele)




if __name__ == '__main__':
	t=int(input())
	while t>0:
		t-=1
		solve()
