import sys
num=raw_input()
temp=0
for i in num:
	temp+=ord(i)-ord('0')
sum='%d' %temp

pinyin={'0':'ling','1':'yi','2':'er','3':'san',
		'4':'si','5':'wu','6':'liu','7':'qi','8':'ba','9':'jiu'}

len_sum=len(sum)

i=0
while i<len_sum:
	sys.stdout.write(pinyin[sum[i]])
	i=i+1
	if i!=len_sum:
		print ' ',


