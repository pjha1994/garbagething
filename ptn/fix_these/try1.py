def main(z):
    x=int(z)
    p=1
    s=0
    while(x!=0):
     s=s+p*(x%2)
     p=p*10
     x=int(x/2)
    return(s)
    
#main((input("Enter a decimal number to convert to binary")))
def bin():
    i=0
    while(i<=55):
        print(main(i))
        i=i+1
bin()
