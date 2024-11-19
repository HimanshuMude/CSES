import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	n=int(input())
	arr=list(map(int,input().split()))
	if n==1:
		print(0)
	else:
		ops=0
		for i in range(n-1):
			if arr[i]>arr[i+1]:
				ops+=arr[i]-arr[i+1]
				arr[i+1]=arr[i]
		print(ops)

if __name__ == '__main__':
	# t=int(input())
	t=1

	while t>0:
		t-=1
		solve()
