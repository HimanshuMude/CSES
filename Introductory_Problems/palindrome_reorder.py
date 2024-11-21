import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
	s=input()
	freq={}
	for i in s:
		freq[i]=freq.get(i,0)+1
	p1=[]
	p2=[]
	flag=False
	mid=[]
	for key,val in freq.items():
		if val%2==1 and flag==False:
			flag=True
			mid=key*val
		elif val%2==1 and flag==True:
			print('NO SOLUTION')
			return
		else:
			p1+=[key]*(val//2)
			p2+=[key]*(val//2)
	p1+=mid
	p1+=p2[::-1]
	print("".join(p1))
	

	


if __name__ == '__main__':
	# t=int(input())
	t=1
	while t>0:
		t-=1
		solve()
