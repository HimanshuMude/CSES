import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")



def solve():
	n=int(input())
	sum=n*(n+1)//2
	if sum%2==1:
		print('NO')
	else:
		req=sum//2
		li=[]
		nli=[]
		for i in range(n,0,-1):
			if req>=i:
				req-=i
				li.append(i)
			else:
				nli.append(i)
			
		print('YES')
		print(len(li))
		print(*li)
		print(n-len(li))
		print(*nli)
		


if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
