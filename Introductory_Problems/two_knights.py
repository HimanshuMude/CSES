#Initial Approach

import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
 
dx=[+2,+2,-2,-2,+1,+1,-1,-1]
dy=[+1,-1,+1,-1,-2,+2,+2,-2]
 
def isValid(x,y,n):
	return (x>=0 and x<n and y>=0 and y<n)
 
def solve(n):
	
	moves=0
	for i in range(n):
		for j in range(n):
			invalid=1
			for k in range(8):
				nx=i+dx[k]
				ny=j+dy[k]
				if isValid(nx,ny,n):
					invalid+=1
			moves+=n**2-invalid
 
	print(moves//2)
 
 
if __name__ == '__main__':
	# t=int(input())
	n=int(input())
	for i in range(n):
		solve(i+1)


#Optimized

import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve(n):
	total=(n**2)*(n**2-1)//2
	invalid=4*(n-1)*(n-2) #for l shape we need atleast 2 in x and 1 in y and *4 for all orientations
	print(total-invalid)


if __name__ == '__main__':
	# t=int(input())
	n=int(input())
	for i in range(n):
		solve(i+1)

