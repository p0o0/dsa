''' Hashtable using Linear Probing'''
class hashtable:
    def __init__(self):
        self.size=int(input('enter the size of hash table'))
        self.table=list(0 for i in range(self.size))
        self.elementcount=0
        print(self.table)
    def isFull(self):
        if self.elementcount == self.size:
            return True
        else:
            return False
    def hashFunction(self,element):
        index = element % self.size
        return index
    def display(self):
        print ('hash table\n')
        for i in range(self.size):
            print(i,'  ',self.table[i])
    def search_rec(self):
        x=int(input('enter number'))
        position = self.hashFunction(x)
        if (self.table[position] == 0):
            print('element not present')
        else:
            i=position
            flag = 0
            if(self.table[i]==x):
                print('element present')
                flag = 1
            else:
                i = (i+1)%self.size
                while(i!=position and self.table[i]!=0):
                    if(self.table[i]==x):
                        print('element present')
                        flag = 1
                        break
                    else:
                        i = (i+1)%self.size
                if (flag == 0):
                    print('Element not present')
            
    def insertRecord(self,element):
        if self.isFull():
            print('hash Table is full')
            return False
        isStored = False
        position = self.hashFunction(element)
        if self.table[position] == 0 :
            self.table[position] = element
            self.elementcount+=1
            isStored = True
        else:
            print('collision occured')
            while self.table[position]!=0 :
                position = position + 1
                if position >= self.size :
                    position = 0
            self.table[position]=element
            isStored = True
            self.elementcount +=1
            #print(self.table)
        
        
    

h1=hashtable()
#print(h1.hashFunction(13))
h1.insertRecord(13)
h1.insertRecord(12)
h1.insertRecord(23)
h1.insertRecord(33)
h1.display()
print('searching')
h1.search_rec()



