
def isPower_of_Three(n):
	if (n <= 0):
		return 0
	if (n % 3 == 0):
		return isPower_of_Three(n / 3)
	if (n == 1):
		return 1
	return 0

def isPower_of_Three(n):
	if (n <= 0):
		return 0
	if (n % 3 == 0):
		return isPower_of_Three(n / 3)
	if (n == 1):
		return 1
	return 1


c=0
for i in range(low,high+1):
    if(isPower_of_Three(i) or isPower_of_five(i)):
	   	c=c+1
print(c)
