import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	s=input()
	maxLen=1
	i=0
	j=1
	while j<len(s):
		if s[i]==s[j]:
			j+=1
		else:
			maxLen=max(maxLen,j-i)
			i=j
			j+=1

	maxLen=max(maxLen,j-i)
	print(maxLen)

if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
