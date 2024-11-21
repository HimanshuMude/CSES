import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	n=int(input())
	for i in range(1<<n):
		print(f'{i^(i>>1):0{n}b}')

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
