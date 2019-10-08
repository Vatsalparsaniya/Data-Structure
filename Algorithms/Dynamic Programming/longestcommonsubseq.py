def LCS(str1,str2):
	m=len(str1)
	n=len(str2)
	L=[[0]*(n+1) for i in range(m+1)]
	for i in range(0,m+1):
		for j in range(0,n+1):
			if i==0 or j==0:
				L[i][j]=0
			elif str1[i-1]==str2[j-1]:
				L[i][j]=1+L[i-1][j-1]
			else:
				L[i][j]=max(L[i-1][j],L[i][j-1])
	print(L[m][n])
def LCSspace(str1,str2):
	m=len(str1)
	n=len(str2)
	L=[[0]*(n+1) for i in range(m+1)]
	for i in range(0,m+1):
		b=i&1
		for j in range(0,n+1):
			if i==0 or j==0:
				L[b][j]=0
			elif str1[i-1]==str2[j-1]:
				L[b][j]=1+L[1-b][j-1]
			else:
				L[b][j]=max(L[1-b][j],L[b][j-1])
	print(L[b][n])
	
str1="AGGTAB"
str2="GXTXAYB"
LCS(str1,str2)
LCSspace(str1,str2)
	
