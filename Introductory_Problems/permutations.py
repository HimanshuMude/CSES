import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	n=int(input())
	if n<4 and n!=1:
		print("NO SOLUTION")
	else:
		res=[val for val in range(2,n+1,2)]+[val for val in range(1,n+1,2)]
		print(*res)


if __name__ == '__main__':
	# t=int(input())
	t=1

	while t>0:
		t-=1
		solve()
