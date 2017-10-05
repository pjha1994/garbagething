import java.io.*;
class data{
String name;
int roll;
int age;

public data(String a,int b,int c){
name=a;roll=b;age=c;
}
public void displaydata(){
System.out.println("Name : "+name+" Roll : "+roll+" Age : "+age);
}

public String retname(){
 return name;
}
public int retroll(){
return roll;
}
public int retage(){
return age;
}

}

class Link{
data d;
Link next;

public Link(String a,int b,int c){
  d=new data(a,b,c);
}

public void displayLink(){
d.displaydata();
}

}
class LinkList{
Link first,last;

public void insertfirst(String a,int b,int c){
    Link newLink=new Link(a,b,c);
      if(isEmpty())
         last=first=newLink;
      else{
         newLink.next=first;first=newLink;
          }
}
public void insertlast(String a,int b,int c){
        Link newLink=new Link(a,b,c);
           if(isEmpty())
               first=last=newLink;
           else{
               last.next=newLink;last=newLink;
               }
}
public Link deletefirst(){
    Link temp=first;
      if(first==last)
         first=last=null;
      else
         first=first.next;
   return temp;
}
public boolean isEmpty(){
  return first==null&&last==null;
}
public Link seefirst(){
return first;
}
public void displayList(){
     Link current=first;
       while(current!=null)
       {
       current.displayLink();
       current=current.next;
       }
}
public Link deletelast(){
     Link current,prev;
     prev=current=first;
     while(current.next!=null)
     {
     prev=current;
     current=current.next;
     }
     Link temp=current;
     if(!(first==last)){
         last=prev;last.next=null;
         }
     else
         first=last=null;
   return temp;
}
public void insertbefore(Link before,String a,int b,int c){
          Link newLink=new Link(a,b,c);
          Link m=findprevbefore(before.d.retname());
            if(before==first){
                newLink.next=first;first=newLink;
                }
            else{
            newLink.next=before;m.next=newLink;
                }
}
public void insertafter(Link after,String a,int b,int c){
         Link newLink=new Link(a,b,c);   
              newLink.next=after.next;
              after.next=newLink;
}
public Link findafter(String s){
       Link current=first;
         if(!isEmpty()){
            while(!(current.d.retname()).equals(s))
                if(current.next!=null) 
                      current=current.next;
                else{
                    current=current.next;break;
                    }
            }
     return current;
}
public Link findbefore(String s){

     Link current=first;
         if(!isEmpty()){
           while(!(current.d.retname()).equals(s))
             if(current.next!=null)
                  current=current.next;
             else{
                 current=current.next;break;
                 }   
          }
  return current;
}
public Link findprevbefore(String s){
          Link prev,current=first;
              prev=current;
while(!(current.d.retname()).equals(s)){
   prev=current;
   current=current.next;
   }
  return prev;
}
public Link findprev(Link x){
Link current=first;
   if(x==first)
       return null;
   else{  
      while(current.next!=x)
      current=current.next;
      return current;
        }
}
public void displayLast(){
     Link m=last;
       while(m!=null/*&&m.next!=first*/){
              m.displayLink();
              m=findprev(m);
               
            }
           
}
public Link find(String s){
         Link current=first;
             if(!isEmpty()){
                while(!(current.d.retname().equals(s))){
                    if(current.next!=null) 
                        current=current.next;
                    else{
                        current=current.next;break;
                        }
                      }
                      return current;
               }
            return null;
}
public Link deleteLink(String x){
          if(!isEmpty()){
             Link m=find(x);
                if(m!=null){
                       if(m==first&&m==last)
                           first=last=null;
                       else if(m==first)
                           first=first.next;
                       else if(m==last){
                            Link z=findprevbefore(x);
                            z.next=null;last=z;
                         }
                else{
                    Link z=findprevbefore(x);
                      z.next=m.next;
                    }
                }
             return m; 
            }
return null;
}
public void insertSortedName(String a,int b,int c)
{
Link newLink=new Link(a,b,c);
Link prev=null,current=first;
 if(first==null)
     {first=last=newLink;}
 else
 {
while(current!=null&&current.d.retname().compareTo(a)<0)
  {prev=current;current=current.next;}
     if(current==first)//or prev==null
     {newLink.next=current;first=newLink;}   
     else if(prev==last)
     {prev.next=newLink;last=newLink;}
     else
     {newLink.next=current;prev.next=newLink;}
 }
}
public void insertSortedNumAge(Link x)
     {
    Link current=first,prev=null;
     if(first==null)
          {first=last=x;}
     else
      {
      while(current!=null&&x.d.retage()>current.d.retage())
         {
           prev=current;
           current=current.next;
         }
         if(prev==null)//or current==first
          {
            x.next=first;
            first=x;
          }
         else if(prev==last)
           {
             prev.next=x;
              last=x;
           }
         else
          {
            prev.next=x;
            x.next=current;
          }
       }
      }
 public void insertSortedNumRoll(Link x)
     {
      Link current=first,prev=null;
      if(first==null)
          {first=last=x;}
     else
       {
         while(current!=null&&x.d.retroll()>current.d.retroll())
           {
           prev=current;
           current=current.next;
           }
          
          if(prev==null)
            {
            x.next=first;
            first=x;
            }
          else if(prev==last)
            {
             prev.next=x;
              last=x;
            }
          else
            {
            prev.next=x;
            x.next=current;
            }
        }
     }
public void merge(LinkList a,LinkList b)throws IOException
{
  Link current=b.first, p;
    DataInputStream wow=new DataInputStream(System.in);
           System.out.println("merge : sort by name(enter 1) roll(enter 2)  age (enter except 1 and  2)");
              int m=Integer.parseInt(wow.readLine());
    if(m==1)
      while(current!=null)
      {
      //p=current.next;//No need for extra variable here. You are sending link's data, not the link itself and hence the pointer remains unaffected unlike in other two cases below.
      a.insertSortedName(current.d.retname(),current.d.retroll(),current.d.retage());
      current=current.next;//Proceed as usual.
      }
    else if(m==2) 
     while(current!=null)
      {
      p=current.next;
      a.insertSortedNumRoll(current);
      current=p;
      }
    else
      while(current!=null)
      {
      p=current.next;
      a.insertSortedNumAge(current);
      current=p;
      }
      
 }
public void insert(LinkList k)throws IOException
{
DataInputStream wow=new DataInputStream(System.in);
String loc;
System.out.println("Insert sorted: By name(enter 1) or roll(enter 2)or age(enter 3)?");
                          int i=Integer.parseInt(wow.readLine());
                                          switch(i)
                                          {
                                          case 1:
                                          do  
                                          {
                                          k.insertSortedName(wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                                          System.out.println("Again? Y/y");
                                           loc=wow.readLine();
                                          }while(loc.compareTo("Y")==0||loc.compareTo("y")==0);
                                                 break;
                                          case 2:
                                          do  
                                          {
                                          Link newLink=new Link(wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                                          k.insertSortedNumRoll(newLink);
                                          System.out.println("Again? Y/y");
                                           loc=wow.readLine();
                                          }while(loc.compareTo("Y")==0||loc.compareTo("y")==0);                         
                                                    break;
                                          case 3:
                                           do  
                                          {
                                          Link newLink1=new Link(wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                                          k.insertSortedNumAge(newLink1);
                                          System.out.println("Again? Y/y");
                                           loc=wow.readLine();
                                          }while(loc.compareTo("Y")==0||loc.compareTo("y")==0);  
                                                   break;
                                          }




}
}
class l{
public static void main(String [] args)throws IOException{
        DataInputStream wow=new DataInputStream(System.in);
              String loc,s;int mm,l,i=0;
                    Link z;
               LinkList l1=new LinkList();
                LinkList l2=new LinkList();
                 LinkList l3=new LinkList();
do{
  System.out.println("\n 1.INSERT FIRST \n 2.INSERT LAST \n 3.DELETE FIRST \n 4.DELETE LAST \n 5.DISPLAY FIRST \n 6.INSERT AFTER \n 7.INSERT BEFORE \n 8.DISPLAY LAST \n 9.DELETE LINK \n 10.FIND LINK BY NAME \n 11.INSERT SORTED \n 12.MERGE SORTED \n"+"\n"+"\nEnter a choice bitch!\n");
      int ch=Integer.parseInt(wow.readLine());
      if(ch>=1||ch<=12){
         switch(ch)
         {
          case 1:System.out.println("\nINSERT FIRST\n"+"\nEnter the number of items to insert first\n");
             mm=Integer.parseInt(wow.readLine());             
                 for( i=0;i<mm;i++){
                    if(i==0)
                       System.out.println("Enter Name Roll and Age for the students :");   
                    l1.insertfirst(wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                    }
                    break;
          case 2:System.out.println("\nINSERT LAST\n"+"\nEnter the number of items to insert last\n");
                       mm=Integer.parseInt(wow.readLine());               
                         for(i=0;i<mm;i++){
                            if(i==0)
                       System.out.println("Enter Name Roll and Age for the students :");   
                          l1.insertlast(wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                         }    
                         break;
          case 3:System.out.println("\nDELETE FIRST\n");
                    System.out.println("Enter the number of items to delete");
                l=Integer.parseInt(wow.readLine());
                     i=0;
                  while(i<l&&!l1.isEmpty()){    
                  System.out.println("DELETED FIRST");
                   Link m=l1.deletefirst();
                       if(m!=null)
                          m.displayLink();
                    i++;
                  }
                  break;
          case 4:System.out.println("\nDELETE LAST\n");
                System.out.println("Enter the number of items to delete");
                 l=Integer.parseInt(wow.readLine());
                    i=0;
                 while(i<l&&!l1.isEmpty()){
                    System.out.println("DELETED LAST");
                      Link m=l1.deletelast();
                       if(m!=null)
                         m.displayLink();
                     i++;  
                     }
                     break;

          case 5:System.out.println("DISPLAY FIRST"+"\n Choose 1/2(sorted)/3(sorted) for list 1/2(sorted)/3(sorted)");
                mm=Integer.parseInt(wow.readLine());
                switch(mm)
                {
                case 1:System.out.println("FISRT UNSORTED LIST");
                                l1.displayList();
                                 break;
                case 2:System.out.println("FISRT SORTED LIST");
                             l2.displayList();
                                 break;
                case 3:System.out.println("SECOND SORTED LIST");
                             l3.displayList();
                                 break;
                }
                    break;
          case 6: System.out.println("Insert after a name");
                 if(!l1.isEmpty()){
                           z=l1.findafter(wow.readLine());
                             if(z!=null)
                                l1.insertafter(z,wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                             else
                                System.out.println("NOT FOUND");
                                }
                 else
                   System.out.println("List is empty");
                       break;
          case 7:System.out.println("Insert before a name");
                  if(!l1.isEmpty()){
                          z=l1.findbefore(wow.readLine());
                             if(z!=null)
                                l1.insertbefore(z,wow.readLine(),Integer.parseInt(wow.readLine()),Integer.parseInt(wow.readLine()));
                             else
                               System.out.println("NOT FOUND");
                          }  
                  else
                          System.out.println("LIST EMPTY");    
                           break;
         case 8:System.out.println("DISPLAY LAST"+"\n Choose 1/2(sorted)/3(sorted) for list 1/2(sorted)/3(sorted)");
                mm=Integer.parseInt(wow.readLine());
                switch(mm)
                {
                case 1:System.out.println("FISRT UNSORTED LIST");
                             l1.displayLast();
                                 break;
                case 2:System.out.println("FISRT SORTED LIST");
                             l2.displayLast();
                                 break;
                case 3:System.out.println("SECOND SORTED LIST");
                             l3.displayLast();
                                 break;
                }
                    break;
         case 9:System.out.println("Enter the name to delete");
                   z=l1.deleteLink(wow.readLine());
                         if(z!=null){
                                     System.out.println("DELETED");
                                    z.displayLink();
                                     }  
                          else
                            System.out.println("NOT FOUND");
                                 break;
         case 10:System.out.println("Search a link by name");
              z=l1.find(wow.readLine());
                   if(z!=null){
                     System.out.println("FOUND");
                       z.displayLink();
                      }  
                   else
                       System.out.println("NOT FOUND");
                          break;
        case 11:l2.insert(l2);
                       System.out.println("LIST");
                              l2.displayList();
                              break;
       case 12:System.out.println("MERGE TWO SORTED LISTS");
                  if(l2.first==null)
                     {
                     System.out.println("Enter the first list");
                      l2.insert(l2);
                     }
                     System.out.println("Enter the Second list(Order picked should be same as that of first list else mix up)");
                                      l3.insert(l3);
                                System.out.println("FIRST LIST");

                                     l2.displayList();
                         
                          System.out.println("SECOND LIST");
                       
                                  l3.displayList();
                        System.out.println("Order picked should be same as that of first list else mix up");
                        System.out.println("MERGED LIST:");
                          
                             l2.merge(l2,l3);//Merging L2 in L1.
                                 l2.displayList();
                                     break;
          }      
                        }
                       System.out.println("Again? Y/y");
                         s=wow.readLine();
   }while(s.charAt(0)=='Y'||s.charAt(0)=='y');
}
}


 