import random
import time
import matplotlib.pyplot as plt
def prat(a,l,u):
    pivot=a[l]
    i=l
    j=u
    while(i<j):
        while(a[i]<pivot):
            i+=1
        while(a[j]>pivot):
            j-=1
        if(i<j):
            a[i],a[j]=a[j],a[i]
    a[j],pivot=pivot,a[j]
    return j

def qs(a,l,u):
    if(l<u):
        t=prat(a,l,u)
        qs(a,l,t-1)
        qs(a,t+1,u)

def partition(arr, l, u):
    pivot = arr[l]
    i = l
    j = u
    while i < j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[j],pivot= pivot,arr[j]
    return j
def quicksort(arr, l, u):
    if l < u:
        c = partition(arr, l, u)
        quicksort(arr, l, c - 1)
        quicksort(arr, c + 1, u) 

print("enter tne size")
n=int(input())
l=[]
for i in range(1,n+1):
    k=[]
    for j in range(0,i):
        k.append(random.randint(1,1000000000))
    l.append(k)

print(l)
t=[]
num=[]
for i in range(0,n):
    a=time.perf_counter()
    qs(l[i],0,i)
    b=time.perf_counter()
    t.append(b-a)
    num.append(i+1)
print(l)

plt.plot(num,t)

plt.show()
