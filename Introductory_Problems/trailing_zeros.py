import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	n=int(input())
	zeros=0
	while n>0:
		zeros+=n//5
		n=n//5
	print(zeros)

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
