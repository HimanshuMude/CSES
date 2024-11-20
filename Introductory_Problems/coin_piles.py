

def solve():
	a,b=map(int,input().split())
	x=(2*b-a)/3
	y=(2*a-b)/3
	if x.is_integer() and y.is_integer() and x>=0 and y>=0:
		print('YES')
	else:
		print('NO')
	

if __name__ == '__main__':
	t=int(input())
	while t>0:
		t-=1
		solve()
