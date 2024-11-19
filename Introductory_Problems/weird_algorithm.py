
def solve():
	n=int(input())
	res=[str(n)]
	while n!=1:
		if n%2==0:
			n/=2
		else:
			n=n*3+1
		res.append(str(int(n)))
	print(" ".join(res))

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
