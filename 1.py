import csv


print("the most specific hypothesis is :[000000]")
a=[]
print("the given training dataset \n")
with open('ws.csv','r') as csvfile:
	reader=csv.reader(csvfile)
	for row in reader:
		a.append(row)
		print(row)

num_attributes=len(a[0])-1
print("the initial value of hypothesis:\n")
hypothesis = ['0']*num_attributes
print (hypothesis)

for j in range (0,num_attributes):
	hypothesis[j]=a[0][j]
print (hypothesis)
print("For finding maximum specific Hypothesis")

for i in range(0,len(a)):
	if a[i][num_attributes]=='yes':
		for j in range(0,num_attributes):
			if a[i][j]!= hypothesis[j]:
				hypothesis[j]='?'

        print("For Learnig Example no",i,"the hypothesis is ",hypothesis)
print("The maximally specific hyptothesis for a given training Egs")
print(hypothesis)
