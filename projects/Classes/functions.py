
def suma(a,b):
    a=2.*a
    return a+b
def Doble(a):
    a=2.*a
def ap(x,b):
    x.append(b)
def g(x0,a):
    return a*x0+b

import numpy as np
x=np.array([2])
print(x)
suma(x,5)
print(x)


li=[1,2,3]

print(li)
ap(li,3)
print(li)

a=2
b=4


x=np.linspace(0,10,100)
y=g(x,10)

a=1
print(type(a))
a=1.
print(type(a))
a='1'
print(type(a))
a={1:1}
print(type(a))
a=[1]
print(type(a))
