import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
def toh(n,source,dest,aux,moves):
	if n==1:
		moves.append((source,dest))
		return 
	toh(n-1,source,aux,dest,moves)
	moves.append((source,dest))
	toh(n-1,aux,dest,source,moves)
def solve():
	n=int(input())
	moves=[]
	toh(n,1,3,2,moves)
	
	print(len(moves))
	for move in moves:
		print(move[0],move[1])



if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
