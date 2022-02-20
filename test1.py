import time

def myadd(a, b):
    return a+b

class Foo(object):
    def __init__(self, a):
        self.a = a
    
    def printme(self):
        print(str(self.a))
        
    def __repr__(self):
        return 'this repr ' + str(self.a)

# test creating a map of word counts from tale of two cities (138k words)
# - load all words into an array 
# - iterate and count into a map

t0 = time.time()
for i in range(10000000):
   pass    
t1 = time.time()
print ('loop 10m pass: ', t1-t0)

t0 = time.time()
for i in range(1000000):
   f = Foo(i)     
t1 = time.time()
print ('1m Foo(): ', t1-t0)

t0 = time.time()
for i in range(1000000):
   j = 1/(i+1)**0.5    
t1 = time.time()
print ('1m 1/sqrt: ', t1-t0)

k = ""
t0 = time.time()
for i in range(500000):
   k += str(i) 
t1 = time.time()
print ('500k concat str: ', t1-t0)
print ('str len '+str(len(k)))

t0 = time.time()
m = {}
for i in range(900000):
    if (m.get(i//10) is None):
        m[i//10] = i
    else:
        m[i//10] += i          
t1 = time.time()
print ('900k make map: ', t1-t0)

t0 = time.time()
f = open("tale-of-two-cities64x.txt", "r")
f.read()
t1 = time.time()
print ('read 11m word file: ', t1-t0)

f = open("tale-of-two-cities.txt", "r")
txt = f.read()
t0 = time.time()
s= sorted(txt)
t1 = time.time()
print ('sort 792k chars: ', t1-t0)

def fib(a):
    if (a in (0,1)):
        return a
    else:
        return fib(a-1) + fib(a-2)

t0 = time.time()
fib(23)
t1 = time.time()
print ('fib 23: ', t1-t0)


t0 = time.time()
for i in range(10000000):
   myadd(i,myadd(1,i))    
t1 = time.time()
print ('loop add-func 10m: ', t1-t0)


t0 = time.time()
for i in range(10000000):
   i+i+1    
t1 = time.time()
print ('loop add-inline 10m: ', t1-t0)


newlist = []
t0 = time.time()
for i in range(1, 1000000):
    if i % 2 == 0:
        newlist.append(i**2)
t1 = time.time()
print ('list 1m: ', t1-t0)

newlist = []
t0 = time.time()
newlist = [i**2 for i in range(1, 1000000) if i%2==0]
t1 = time.time()
print ('listcomp 1m: ', t1-t0)
