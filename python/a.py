from array import array
def go():
   test_case=int(input(""))
   i=0
   while(i<test_case):
      bottles_of_paint=int(input(""))
      print("")
      j=0
      D=set()
      while(j<bottles_of_paint):
          D.add(int(input("")))
          j=j+1
      i=i+1
      tattoo_num=int(input(""));
      D=sorted(D)
      k=0
      res=set()
      while(k<tattoo_num):
         print("");
	 a=[]
         print("going raw")
	 x=raw_input()
	 a=x.split()
         #for z in a:
            
         #L=int(input(""))
         #R=int(input(""))
         k=k+1
         i=1
         s=0
         for e in D:
              if(L<=e and e<=R):
                 s=s+i*e
                 i=i+1
                
         print(s)
go()
