/*
=/=
=/=             Tic Tac Toe (v1.0)
=/=
=/=           ~ Rakshit Singh Gaira
=/=
=/=
*/
#include <iostream>

//Who's in turn
void playercount(int counter, std::string first_turn, std::string player1, std::string player2)
{
    if(counter % 2 ==0)
    {
        std::cout << "Player of current turn : " << first_turn << "\n";
    }
    else
    {
        if(first_turn == player1)
        {
            std::cout << "Player of current turn : " << player2 << "\n";
        }
        else
        {
            std::cout << "Player of current turn : " << player1 << "\n";
        }

    }

}

void placements(int rows, int columns, std::string playground[20][20],std::string player1,std::string player2,bool &p1)
{
    int i,j;

        if(p1)
        {

            for(i=0; i<3; i++)
                {
                    for(j=0; j< 3; j++)
                    {
                        playground[rows][columns]="X";
                        std::cout << playground[i][j] << "\t";
                    }
                    std::cout << "\n";
                }

        }


        else
        {
            for(i=0; i<3; i++)
                {
                    for(j=0; j< 3; j++)
                    {
                        playground[rows][columns]="O";
                        std::cout << playground[i][j] << "\t";
                    }
                    std::cout << "\n";
                }

        }
    p1=!p1; //for alternating

}

//PRINCIPLE DIAGONAL
int checkprime(std::string playground[20][20], std::string player1, std::string player2, std::string first_turn)
{

    if(playground[0][0]=="X"&&playground[1][1]=="X"&&playground[2][2]=="X")
    {
        std::cout << "*Game is over* \n";
        std::cout << std::endl;
        std::cout << first_turn << " WINS! \n";
        return true;
    }
    if(playground[0][0]=="O"&&playground[1][1]=="O"&&playground[2][2]=="O")
    {
        std::cout << "*Game is over* \n";
        std::cout << std::endl;

            std::cout << player2<< " WINS! \n";
            return true;

    }
}

//SECONDARY DIAGONAL
int checksec(std::string playground[20][20], std::string player1, std::string player2, std::string first_turn)
{

    if(playground[0][2]=="X"&&playground[1][1]=="X"&&playground[2][0]=="X")
    {
        std::cout << "*Game is over* \n";
        std::cout << std::endl;
        std::cout << first_turn << " WINS! \n";
        return true;
    }
    if(playground[0][2]=="O"&&playground[1][1]=="O"&&playground[2][0]=="O")
    {
        std::cout << "*Game is over* \n";
        std::cout << std::endl;
        std::cout << player2<< " WINS! \n";
            return true;
    }
}

//ALL ROWS

int checkrows(std::string playground[20][20], std::string player1, std::string player2, std::string first_turn)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(playground[i][0]=="X"&&playground[i][1]=="X"&&playground[i][2]=="X")
        {
            std::cout << "*Game is over* \n";
            std::cout << std::endl;
            std::cout << first_turn << " WINS!";
            return true;
        }
         if(playground[i][0]=="O"&&playground[i][1]=="O"&&playground[i][2]=="O")
        {
            std::cout << "*Game is over* \n";
            std::cout << std::endl;
            std::cout << player2<< " WINS! \n";
            return true;
        }
    }
}

//ALL COLUMNS

int checkcolumns(std::string playground[20][20], std::string player1, std::string player2, std::string first_turn)
{
    int j;
    for(j=0; j<3 ;j++)
    {
        if(playground[0][j]=="X"&&playground[1][j]=="X"&&playground[2][j]=="X")
        {
            std::cout << "*Game is over* \n";
            std::cout << std::endl;
            std::cout << first_turn << " WINS!";
            return true;
        }
        if(playground[0][j]=="O"&&playground[1][j]=="O"&&playground[2][j]=="O")
        {
            std::cout << "*Game is over* \n";
            std::cout << std::endl;
            std::cout << player2<< " WINS! \n";
            return true;
        }
    }
}

int main()
{
    std::string player1, player2,first_turn;
    std::cout << "Enter a name for the X player : ";
    std::cin >> player1;
    std::cout << "Enter a name for the O player : ";
    std::cin >> player2;
    int counter=0;

    //Player registration
    while(true)
    {
        std::cout << "Who plays first, " << player1 << " or " << player2 << "? : ";
        std::cin >> first_turn;
        if((first_turn!=player1)&&(first_turn!=player2))
        {
            std::cout << first_turn << " is not a registered player. \n";
        }
        else
        {
            break;
        }
    }
    bool p1;
     if(first_turn==player1) //FOR PLACEMENTS
        {
            p1=true;
        }
        else
        {
            p1=false;
        }

    std::cout << std::endl;


    //The playground
    while(true)
    {
        std::string playground[20][20];
        int rows, columns,i=0,j=0,turns;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                playground[i][j]=".";
                std::cout << playground[i][j] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
        playercount(counter,first_turn,player1,player2);
        counter+=1; //This code is so bad but it works...


        std::cout << std::endl;

        //Let the games begin



        for(turns=1; turns < 10; turns++)
        {
            std::cout << "Turn : " << turns << "\n";

            //Positioning

            while(true)
            {
                std::cout << "Choose a row number (0 to 2) : ";
                std::cin >> rows;
                if((rows!=0)&&(rows!=1)&&(rows!=2))
                {
                    std::cout << rows << " is not a valid row. \n";
                    continue;
                }
                else
                {

                    std::cout << "Choose a column number (0 to 2) : ";
                    std::cin >> columns;
                    if(columns!=0&&columns!=1&&columns!=2)
                    {
                        std::cout << columns << " is not a valid column. \n";
                        continue;
                    }
                    if(playground[rows][columns]=="O"||playground[rows][columns]=="X")
                    {
                        std::cout << "ERROR! SLOT ALREADY OCCUPIED \n";
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            std::cout << std::endl;

            //Placements
            placements(rows, columns, playground, player1,player2,p1);



            std::cout << std::endl;

            //CHECKING FOR WIN

            int cp=false,cs=false,cr=false,cc=false;
            cp=checkprime(playground,player1,player2,first_turn);
            cs=checksec(playground,player1,player2,first_turn);
            cr=checkrows(playground,player1,player2,first_turn);
            cc=checkcolumns(playground,player1,player2,first_turn);

            if(cp==true||cs==true||cr==true||cc==true)
            break;

            if(turns==9)
            {
                std::cout << "It's a Tie!";
                break;
            }

            playercount(counter,first_turn,player1,player2);
            counter+=1; //This code is so bad but it works.


        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::string decision;
        std::cout << "Would you like to play again? (Y/N) : ";
        std::cin >> decision;
        if(decision=="Y"||decision=="YES"||decision=="yes"||decision=="yeah"||decision=="y")
        {
            continue;
        }
        else
        {
            std::cout << "=> Thanks for playing! \n => If you liked the game, follow me on instagram, @frostbyte007";
            break;
        }

    }

}
