def new_elements(s):
    n= int(input("Enter the number of elemnts in the set "))
    for i in range(n):
        s.add(int(input("Enter the elements: ")))


def display(s):
    print("Elements in the set ")
    print(s)

def remove(s):
    m=set()
    n=int(input("Enter the element you want to remove "))
    for i in s:
        if (i==n):
          pass
        else:
            m.add(i)
    s=m
    print("Set after removing elemnt ")
    display(s)
def is_present(s):
    flag=False
    n=int(input("Enter the element you want to search "))
    for i in s:
        if (i==n):
           flag=True
    if(flag==True):
        print("Element is present ")
    else:
        print("Elemnt not found ")

def set_size(s):
    it=0
    for i in s:
       it=it+1
    print("Size of set is : ",it)

def intersection(s,t):
    r=set()
    for i in s:
        for j in t:
            if i==j:
                r.add(i)
    print("Intersection of two sets")
    print(r)

def union(s,t):
    r= set()
    for i in s:
        r.add(i)
    for i in t:
        r.add(i)

    print("Union of two sets are : ")
    print(r)

def difference(s,t):
     r=set()
     for i in s:
        if i in t:
                pass
        else:
                r.add(i)
     print("Difference in two set ")
     print(r)

def subset(r,s):
    flag =False
    for i in r:
         if i in s:
             pass
         else:
             flag=True
    if(flag==False):
        print("It is subset ")
    else:
        print("Not a subset")
    
def main():
    a= set()
    new_elements(a)
    display(a)
    remove(a)
    is_present(a)
    set_size(a)

    b=set()
    new_elements(b)
    display(b)

    intersection(a,b)
    union(a,b)
    difference(a,b)

    subset(b,a)
    
main()

