Number = 1000
Divisor = 1
Dividers = 0.0
Total = 0.0
Current = 0.0
Best = 0.0
Best_Number = 0.0
 
 
 
while Number <= 10000: #Pretty much just put's a stop to it when it hit's a certain number
    while Divisor <=100: #This is the "reset" function. When it hit's 101 it goes down to the reset part
        if 0 == Number % Divisor: # Makes sure there is no remainder and then increments the counters
            #print Number," is Divisible by",Divisor,",",Number/Divisor,"times" #Basic print statement
 
            Divisor += 1
            Dividers += 1
            Total += 1
 
        else: #If else, Increment the other counters
            #print Number, "isn't Divisible by", Divisor
 
            Divisor += 1
            Total += 1
 
    Current = Dividers / Total * 100 #Get's the current score
 
   # print Number, "Is Divisible by", Dividers, "Percent of numbers up to 100\n" # Just basic print statement
 
    if Current > Best: # If the current score is better then the best score, make that the best score
        Best = Dividers
        Best_Number = Number
 
    if Divisor == 101: # I don't really know a way to make this a variable so it's kinda stuck there at the moment
        Number += 1 #reset's all the functions
        Divisor = 1
        Dividers = 0.0 #God this was a headache, initially I just had the reset to 0, but it needed to be 0.0 lol
        Total = 0.0
 
print "The Best Number Under", Number - 1, "was", Best_Number, "With a score of", Best, "Percent" #just a simple print out the best score
