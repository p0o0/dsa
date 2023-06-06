'''hash table using separate chaining''' 
def main():
    print('hello')
    Hash_Table=[[] for _ in range(10)]
    print(Hash_Table)
    Insert_Into_Telephone_Book(Hash_Table)
    display_hash(Hash_Table)
    
    

def Hashing_function(telephone_no,Hash_Table):
    return telephone_no % len(Hash_Table)
def Insert_Into_Telephone_Book(Hash_Table):
    n=int(input('how many records to be inserted'))
    for i in range(n):
        telephone_no=int(input('enter telephone no'))
        name=input('enter name')
        index = Hashing_function(telephone_no,Hash_Table)
        Hash_Table[index].append(name)
        
def display_hash(Hash_Table):
      
    for i in range(len(Hash_Table)):
        print(i, end = " ")
          
        for j in Hash_Table[i]:
            print("-->", end = " ")
            print(j, end = " ")
              
        print()        
    

main()
