#Read two lists A and B containing 25 integers each, generate and print a list C of 50
#elements, whose elements are the interleaving of the elements of A and B

def listaAB(n):
    A =[]
    B =[]
    c=[]
    

    for i in range(n):
        A.append(int(input()))
    for i in range(n):
        B.append(int(input()))
    
    for i in range(n):
            c.append(A[i])
            c.append(B[i])
    print(A)
    print(B)
    print(c)

def main():
    listaAB(25)
   
if __name__ == '__main__':
    main()
