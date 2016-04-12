
def count(n):
	global step
	while n!=1:
		if n%2==1:
			n=(3*n+1)/2
		else:
			n=n/2
		step+=1

step=0
n=input()
count(n)
print step

