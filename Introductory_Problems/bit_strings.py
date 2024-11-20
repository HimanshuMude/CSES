import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
mod=int(1e9+7)
def binpowmod(a,b):
	res=1
	while b>0:
		if b&1:
			res=(res*a)%mod
		a=(a*a)%mod
		b>>=1
	return res

def solve():
	n=int(input())
	print(binpowmod(2,n))

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
