
def solve():
	n=int(input())
	arr=list(map(int,input().split()))
	s1=sum(arr)
	s2=n*(n+1)//2
	print(s2-s1)

if __name__ == '__main__':
	# t=int(input())
	t=1

	while t>0:
		t-=1
		solve()
