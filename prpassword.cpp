/*
=/=
=/=            Pseudo-Random Password Generator (v2.0)
=/=
=/=           ~ Rakshit Gaira
=/=
=/=          #Pseudo Elements
=/=         -> The password has min length of 12 and max 32.
=/=         -> Password always starts with lower case and ends with
=/=            uppercase.
=/=         -> At least 2 lower case alphabets, 2 upper case alphabets, 1
=/=            number and 1 special character is mandatory.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

//The randomisation
char random(char assets[],int strlen)
{
    return assets[rand()%strlen];
}

//For the size of password (12<password<32)
int limit()
{
    while(true)
    {
        int length;
        length=(rand()%33)+1; //+1 to randomize it a bit more
        if(length>=12)
        {
            return length;
            break;
        }
        else
        {
            continue;
        }

    }
}

int main()
{
    srand(time(NULL));
    int length;
    std::cout << "**Random Password Generator** \n";
    char assets[]="0123456789" "!@#$%&*^" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; //arsenal
    int strlen=sizeof(assets)-1;
    length= 12;// limit();

    int i,j=0,digit;
    char x,special,first;
    std::string pass[length];
    for(i=0; i<length; i++)
    {
        //lowercase at the starting
        if(i==0)
        {
                //(max-min + 1) + max => to get the random digit between two values
                x=rand()%(122-97 + 1) + 97;
                first=x;

            pass[0]= first;
        }

        //uppercase at the last
        else if (i==length-1)
        {

                x=rand()%(90-65 + 1) + 65;

            pass[length-1]=x;
        }

        //two lowercase
        else if(i==4||i==7)
        {
            x=rand()%(122-97 + 1) + 97;
                first=x;

            pass[i]=x;
        }

        //two uppercase
        else if(i==5||i==10)
        {
            x=rand()%(90-65 + 1) + 65;

            pass[i]=x;
        }

        // a digit
        else if(i==6)
        {
             j=rand()%(57-48 + 1) + 48;

            pass[i]= j;
        }

        //a special character
        else if(i==3)
        {
            x=rand()%(39-33 + 1) + 33;
            special = x;
            pass[i]=special;
        }

        else
        {
            x=random(assets,strlen);
            pass[i]=x;
        }

    }

    //End result

    std::cout << "The length is : " << length <<std::endl;

    std::cout << "The password is : ";
    for(i=0; i<length; i++)
    {
       std::cout << pass[i];
    }

    std::cout << std::endl;

}
