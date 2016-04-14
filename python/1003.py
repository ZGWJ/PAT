
n=input()
i=1
while i<=n:
	index=0
	count_P=0
	count_T=0
	sign_P=0
	sign_T=0
	sign=0
	sign_end=0
	string=raw_input()
	for j in string:
		index+=1
		if j!='P' and j!='A' and j!='T':
			print "NO"
			sign_end=1
			break

		if j=='P':
			sign_P=index
			count_P+=1
			sign=1

		if j=='T':
			if sign==0:
				print "NO"
				sign_end=1
				break
			sign_T=index
			count_T+=1
			if sign_T-sign_P==1:
				print "NO"
				sign_end=1
				break
	if sign_end==0:
		a=sign_P-1
		num_a=sign_T-sign_P-2
		if count_P==1 and count_T ==1:
			if (num_a+1)*a<=(index-sign_T):
				print "YES"
			else:
				print "NO"
		else:
			print "NO"
	i+=1

