t = int(input())
while t > 0:
 n = int(input())
 arr= list(map(int,input().split()))
 c= arr[0]
 g= arr[0]
 for i in range(1,n):
  c =max(arr[i],arr[i]+c)
  g= max(c,g)
 print(g)
 t=t-1
