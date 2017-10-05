#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


const int ANTAL_BOKSTAVER = 26;  //A-Z
//int antal_arr[ANTAL_BOKSTAVER] = {};

void berakna_histogram_abs(string user_Text_Ref,int antal_arr[ANTAL_BOKSTAVER]);

int main()
{
    string user_Text; // användarens text
    string &user_Text_Ref = user_Text; // referense till funktionen berakna_histogram_abs()
    char alfa_arr[ANTAL_BOKSTAVER] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int antal_arr[ANTAL_BOKSTAVER] = {};
    cout << "Vänligen mata in text: " << endl;
    cin >> user_Text;
    berakna_histogram_abs(user_Text_Ref, antal_arr);
    int i;
    cout << "DEBUG out of function" << endl;
    for(i = 0; i < ANTAL_BOKSTAVER;i++)
    {
         cout << alfa_arr[i] << " : " << antal_arr[i] << endl;
    }
return 0;
}
void berakna_histogram_abs(string user_Text_Ref, int antal_arr[])
{
    char alfa_arr[ANTAL_BOKSTAVER] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i, j;
    for(i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        for(j = 0;j < user_Text_Ref.length() ; j++)
        {
            if(alfa_arr[i] == user_Text_Ref[j])
            {
                antal_arr[i] += 1;  // <----- Here be problem
                //cout << alfa_arr[i] << " : " << antal_arr[i] << endl; 
            }
            else
            {
                continue;
            }
        }
    }
    cout << "DEBUG in function" << endl;
    for(i = 0; i < ANTAL_BOKSTAVER;i++)
    {
        cout << alfa_arr[i] << " : " << antal_arr[i] << endl; // <----- and here.
    }
    //return antal_arr;
}