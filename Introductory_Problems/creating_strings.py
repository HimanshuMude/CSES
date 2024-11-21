import sys
from itertools import permutations
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	s=input()
	s=sorted(s)
	d=[]
	li=set(permutations(s))
	
	print(len(li))
	for i in li:
		print(''.join(i))

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()


