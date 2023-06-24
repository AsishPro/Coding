T=int(input())
primes = [67,71,73,79,83,89,97,101,103,107,109,113]
final = []
#---------------------------------------------------------------------
def convert(arg):
	output=""
	for i in arg:
		i1=ord(i) ; 
		i2=ord(i) ; 
		j=ord(i)
	if j in primes:
		output+=i
	else:
		while i1 not in primes and i1>67: 
			i1-=1 # i1>67 so that final i1 exists in primes
		while i2 not in primes and i2<113: 
			i2+=1 # i2<113 so that final i2 exists in primes
		if j>113: 
			output+='q' # chr(113) --> 'q'
		elif j-i1 > i2-j or j<67: 
			output+=chr(i2)
		else: output+=chr(i1)
	return output
#-----------------------------------------------
	while T!=0:
		wordLength=input()
		word=str(input())
		final.append(convert(word))
		T-=1
#------------------------------------------
	for i in final:
	print(i)