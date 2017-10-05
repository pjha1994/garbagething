//Tokens, OPerators, and Expressions

//Lexical elements : 
                   //Tokens:keywords, literal, variables,operators ets.
                     whitespace must be used to separate tokens that would otherwise constitute a single token.'return 0;' not 'return0;'
                     Use extra whitespace for the code to be human readable,parser ignores whitespaces.Parser treats comments as whitespaces.
                     Tokenizer grabs as many characters as it can to build up the next token,being greedy.
                                j = i+++++i;//INVALID
                                j = i++ ++ +i;//INVALID
                                j = i++ + ++i;//VALID

                    //Identifiers:used for names of declared entities such as variables, constants and labels using letters and digits.
                                  Any difference in character within an identifier makes that identifier unique.Case is significant.
                                  Write each identifier in one language--in one known set of characters.Identifiers can be as long as you want.
                                  
                    //Keywords:Language keywords can't be used as identifiers.null,true,flase are literals,not keywords, yet can't be used as
                               an identifier as 12 can't be used as an identifier.can be used in between names. 

                    //Type and Literals:primitive types and reference types.
                                        primitive:boolean,char,byte,short,int,long,float,double.Each has a corresponding class type in 
                                                  java.lang package, called wrapper classes.MIN_VALUE and MAX_VALUE in corresponding
                                                  wrapper classes.Float and double classes have NaN,NEGATIVE_INFINITY,POSITIVE_INFINITY and
                                                  isNaN method.THere is no unsigned integer type.They must be stored in larger signed type.
                                        Reference:class types, interface types and array types
                       Each type has literals, which are the way that consatant values of that type are witten
                                          Reference literals: null,represents an invalid or uncreated object,it has no class,not even Object.
                                          Boolean literals: true and false.
                                          Character literals: in single quotes 'Q'
                                          Integer Literals:strings of cotal,decimal,hexadecimal digits.Leading 0 means octal, leading 0x denotes
                                                           hexadecimal else decimal.They are long if they end in L/l else int.If an int is 
                                                           assigned to short, and it is in the short's range,then its ok else explicit casting 
                                                           necessary.
                                          Floating point literals:an optional decimal point,optionally followed by an exponent.Can be followed 
                                                                  by F/f for single-point precision and by D/d to denote a double-precision
                                                                  constant.Floating-points are type double unless specified by f/F.
                                                                  0.0==-0.0 is true.
                                                                  1d/0d= +infinity and 1d/-0d = -infinity
                                                                  A double constants can't be assigned directly to a float variable,even if the 
                                                                  value of the double is within range of float.Only floats can be assigned.
                                          String Literals:with double quotes, "Some_String".Newlines not allowed in the middle of the string.
                                                          Instead use escape sequence \nReferences an object of type String.Characters in 
                                                          strings can be specified using the octal digit mechanism,but all octal digits must be
                                                          specified."\0116" is eqivalent to "\t6"."\116" is "N".
                                          class literals:Every type there is an associated Class object.




//6.Strings:standard objects,built-in language support.String literals.+ and += concatenation.String objects are immutable.StringBuffer classe
 for mutable strings.Conversion of string to integers and booleans.
    Creating string objects implicitly using string literals or by concatenating strings.Explicitly by calling constructors.
    Two constructors of the class:
                                 public String()-->construct an object with ""-an empty string
                                 public String(String value)-->copy constructor,as String objects are immutable.
    Methods of the class:
                        length()--returns number of characters
                        charAt(i)--returns character at ith position as if String were an array of characters
                             for(int i = 0; i<str.length(); i++)indexes from 0 to length()-1.Else throws IndexOutOfBoundsException  
                                counts[str.charAt(i)]++;
                        length() is a method for String, in contrast to arrays, in which it is a field.
                        If accesed indexes out of bounds, it may throw IndexOutOfBoundsException(in arrays as well,in copying to or from) or StringIndexOutOfBoundsException which takes illegal index as constructor argument and then include it in a detailed message.
                        indexOf(ch)--first occurence of ch.Search forward.
                        lastIndexOf(ch)--last occurence of ch.Search backward.
                        The difference between two character positions is one more than the number of characters in between.
                        indexOf(char ch)--returns index of first position of ch
                        indexOf(char ch, int start)--returns index of first position of ch>=start
                        indexOf(String str)--returns index of first position of str
                        indexOf(String str, int start)--returns index of first position of str>=start
                        lastIndexOf(char ch)--returns index of last position of ch
                        lastIndexOf(char ch, int start)--returns index of last position of ch<=start
                        lastIndexOf(String str)--returns index of last position of str
                        lastIndexOf(String str, int start)--returns index of last position of str<=start
//String comparisons:comapre strings or part of strings
            //internationalisation and localisation issues of full Unicode strings are not addressed with these methods.
            //s1.equals(s2)--true if both have same length and same unicode characters.
             String.equals overrides Object.equals to define equivalence instead of identity.
              s1.equalsIgnoreCase(s2)--compares ignoring case.
              s1.compareTo(s2)--returns an int that is leass than,equal to, or greater than zero when the string on which it is invoked is less than,equal to or greater than the other string.Ordering usd is unicode characters.
               s1.compareToIgnoreCase(s2).
               public boolean regionMatches(int start, String other, int ostart, int count)
               public boolean regionMatches(boolean ignoreCase,int start, String other, int ostart, int count)
               public boolean startsWith(String prefix, int start)//the following three function returns false for invalid indexes
               public boolean startsWith(String prefix)
               public boolean endsWith(String suffix)
               s1==s2 most of the time gives wrong results.It compares if the two references point to the same object, not that both have the same contents.Any two string literals with the same contents will refer to the same String object, always.
               String x="bb";
               String y="bb";
               String z=new String("bb");
               x==y-->true
               x==z-->false
               y==z-->false
               intern()
               hashCode()-->returns hash based conents of the string.
