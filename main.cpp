/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Assignment: 2
Lecture Section : TC1V
Tutorial Section: TT1L
Name of Student #1 : CHO XUAN XIAN
ID of Student #1 : 1201302646
Email of Student #1: 1201302646@student.mmu.edu.my
Phone of Student #1: 011-55086875
Name of Student #2 : INTAN KHAIRINA ADLINA BINTI AHMAD
ID of Student #2 : 1201302263
Email of Student #2: 1201302263@student.mmu.edu.my
Phone of Student #2: 016-7747312
Name of Student #3 : ANGEL PHANG TING TING
ID of Student #3 : 1201302882
Email of Student #3: 1201302882@student.mmu.edu.my
Phone of Student #3: 011-11277520
********************************************/

#include "Mars.h"
#include "Rover.h"
#include <iostream>
#include <iomanip>          // for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>            // for time() in srand( time(NULL) );
#include <windows.h>        // for Sleep()
#define RESET   "\033[0m"   // to reset the colour
#define BLUE    "\033[34m"  // Blue 
#define MAGENTA "\033[35m"  // Magenta 
#define CYAN    "\033[36m"  // Cyan 
#define RED     "\033[31m"  // Red  
#define YELLOW  "\033[33m"  // Yellow 

using namespace std;

const int sz = 5;

char letter_w[5][5]={{'W',' ','W',' ','W'},
                     {'W',' ','W',' ','W'},
                     {'W',' ','W',' ','W'},
                     {'W',' ','W',' ','W'},
                     {' ','W',' ','W',' '}};

char letter_e[5][5]={{'E','E','E','E','E'},
                     {'E',' ',' ',' ',' '},
                     {'E','E','E','E','E'},
                     {'E',' ',' ',' ',' '},
                     {'E','E','E','E','E'}};

char letter_l[5][5]={{'L',' ',' ',' ',' '},
                     {'L',' ',' ',' ',' '},
                     {'L',' ',' ',' ',' '},
                     {'L',' ',' ',' ',' '},
                     {'L','L','L','L','L'}};              

char letter_c[5][5]={{' ','C','C','C','C'},
                     {'C',' ',' ',' ',' '},
                     {'C',' ',' ',' ',' '},
                     {'C',' ',' ',' ',' '},
                     {' ','C','C','C','C'}};

char letter_o[5][5]={{' ','O','O','O',' '},
                     {'O',' ',' ',' ','O'},
                     {'O',' ',' ',' ','O'},
                     {'O',' ',' ',' ','O'},
                     {' ','O','O','O',' '}}; 

char letter_m[5][5]={{' ','M',' ','M',' '},
                     {'M',' ','M',' ','M'},
                     {'M',' ','M',' ','M'},
                     {'M',' ','M',' ','M'},
                     {'M',' ','M',' ','M'}}; 

char letter_t[5][5]={{'T','T','T','T','T'},
                     {' ',' ','T',' ',' '},
                     {' ',' ','T',' ',' '},
                     {' ',' ','T',' ',' '},
                     {' ',' ','T',' ',' '}};

char letter_a[5][5]={{' ','A','A','A',' '},
                     {'A',' ',' ',' ','A'},
                     {'A','A','A','A','A'},
                     {'A',' ',' ',' ','A'},
                     {'A',' ',' ',' ','A'}};

char letter_r[5][5]={{'R','R','R','R','R'},
                     {'R',' ',' ',' ','R'},
                     {'R','R','R','R','R'},
                     {'R',' ',' ','R',' '},
                     {'R',' ',' ',' ','R'}};

char letter_s[5][5]={{'S','S','S','S','S'},
                     {'S',' ',' ',' ',' '},
                     {'S','S','S','S','S'},
                     {' ',' ',' ',' ','S'},
                     {'S','S','S','S','S'}};

void shiftLetter(char matrix[][128])
{
    char ch[sz][8];

    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<8;j++)
        ch[i][j] = matrix[i][j];
    }

    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<120;j++)
        matrix[i][j] = matrix[i][j+8];
    }

    for (int i=0;i<sz;i++)
    {
        for (int j=0;j<8;j++)
        matrix[i][j+120] = ch[i][j];
    }

}

void spaces(char matrix[][128], int row, int &column){
    for (int i=0;i<3;i++)
            matrix[row][column++]=' ';
}

void setLetter(char matrix[][128]){
    for (int i=0;i<sz;i++)
    {
        int col=0;

        for (int j=0;j<sz;j++)
            matrix[i][col++] = ' ';
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_w[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++]= letter_e[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++]= letter_l[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_c[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_o[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_m[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_e[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = ' ';
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_t[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_o[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = ' ';
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_m[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_a[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_r[i][j];
        spaces(matrix,i,col);
        for (int j=0;j<sz;j++)
            matrix[i][col++] = letter_s[i][j];
        spaces(matrix,i,col);
    }
}

void sleep(int s){
    Sleep(s*300);
    system("cls");
}

void printLetter(char matrix[][128], int size, int time){
        
    system("cls");
    setLetter(matrix);
    for (int i=0; i<=size;i++)
    {   
        sleep(time);
        for (int i=0;i<sz;i++)
        {
            for (int j=0; j<128; j++)
                cout << MAGENTA << matrix[i][j];
            cout << endl;
        }
        shiftLetter(matrix);
    }
}

// --------- aboves are to print out a horizontal shifting words for 'welcome to mars' ----------

void printInstructions()
{
    char hill = 178;
    cout << "------------------------------------------------------------\n";
    cout << "| Mission : Get all the GOLDs and do not fall in TRAPs !!! |" << endl;
    cout << "|----------------------------------------------------------|\n";
    cout << "| L = Turn Left ; R = Turn Right ; M = Move ; Q = Quit     |" << endl;
    cout << "| $ = Gold[G] ; " << hill << " = Hills ; # = Trap"<< setw(24) << "|" << endl;
    cout << "------------------------------------------------------------\n\n";
}

void userSetting(int& x, int& y, int& golds)
{
    cout << "Please input values of x for coloumns and y for rows of the map. \n";
    cout << "Lets Explore Mars....\n";
    cout << "Mars dimension X => ";
    cin >> x;
    cout << "Mars dimemsion Y => ";
    cin >> y;
    cout << "No. of golds => ";
    cin >> golds;
}

void printScoreBoard(int& Com_Seq, int& commands, int& golds_found, int& total_golds, int& total_Score)
{
    cout << "Total Command Sequences [S] = " << Com_Seq << endl;
    cout << "Total Commands [C] = " << commands << endl;
    cout << "Total Golds [G] = " << golds_found << " out of " << total_golds << endl;
    cout << "Total Score = [G] x 50 - [S] x 5 - [C] x 1 = " << total_Score << endl;
}

void getCommand(string& command)
{
    cout << "\nExample Command Sequences: MMLLRMMRMLQ\n";
    cout << "Enter command sequences => ";
    cin >> command;
}

bool showMap()
{
    bool T_F = false;
    string YESorNO;

    do{
    cout << "Do you want to see the Map of Mars? (y/n) => ";
    cin >> YESorNO;
    }while(YESorNO != "y" && YESorNO != "Y" &&
           YESorNO != "n" && YESorNO != "N" );

    if ( YESorNO == "y" || YESorNO == "Y")
        T_F = true;
    else 
        T_F = false;
    
    return T_F;
}

void marsRover()
{
    int x,y;
    int total_num_golds;
    bool showTreassure = false;
    int total_Com_Seq = 0, total_Com = 0, golds_found = 0, total_Score = 0;

    userSetting(x,y,total_num_golds);

    Mars mars(x,y);
    mars.resize();

    Rover explore;

    explore.generateGolds(mars,total_num_golds);
    explore.land(mars);
    explore.displayMapper(mars);

    int time = 3;
    string command;
    char c;

    do
    {
        if(explore.getGameOver())
            break;
        mars.display();
        printInstructions();
        total_Score = (golds_found * 50) - (total_Com_Seq * 5) - (total_Com * 1);
        printScoreBoard(total_Com_Seq, total_Com, golds_found, total_num_golds, total_Score);
        getCommand(command);

        for(int i=0;i<command.length();i++)
        {
            if(explore.getGameOver())
                break;
            mars.display();
            c = command[i];

            switch(c)
            {
                case 'm':
                case 'M':
                {
                    cout << "Command = " << command[i] << " ..." << endl;
                    sleep(time);
                    explore.move(mars);
                    if(explore.getGameOver())
                    {
                        mars.display();

                        printInstructions();
                        printScoreBoard(total_Com_Seq, total_Com, golds_found, total_num_golds, total_Score);
                        cout << "\nROVER IS TRAPPED !!! Mission Failed !!!" << endl << endl;
                        break;
                    }
                    explore.displayMapper(mars);
                    mars.display();
                    cout << "Command = " << command[i] << " [executed]";
                    sleep(time);
                }
                break;
                case 'l':
                case 'L':
                {
                    cout << "Command = " << command[i] << " ..." << endl;
                    sleep(time);
                    explore.turnLeft(mars);
                    explore.displayMapper(mars);
                    mars.display();
                    cout << "Command = " << command[i] << " [executed]";
                    sleep(time);
                }
                break;
                case 'r':
                case 'R':
                {
                    cout << "Command = " << command[i] << " ..." << endl;
                    sleep(time);
                    explore.turnRight(mars);
                    explore.displayMapper(mars);
                    mars.display();
                    cout << "Command = " << command[i] << " [executed]";
                    sleep(time);
                }
                break;
                case 'q':
                case 'Q':
                {
                    mars.display();
                    printInstructions();
                    printScoreBoard(total_Com_Seq, total_Com, golds_found, total_num_golds, total_Score);
                    cout << endl
                         << "Quitted!! Mission Failed!!!" << endl << endl;
                }
                break;
                default :
                {
                    cout << "Command = " << command[i] << " ..." << endl;
                    sleep(time);
                    mars.display();
                    cout << "Command = " << command[i] << " [failed to execute...]";
                    sleep(time);
                }
            }
        }

        total_Com_Seq += 1;
        total_Com = total_Com + command.length();
        golds_found = explore.goldCollection();

        if (golds_found == total_num_golds)
        {
            explore.displayMapper(mars);
            mars.display();

            total_Score = (golds_found * 50) - (total_Com_Seq * 5) - (total_Com * 1);
            printInstructions();
            printScoreBoard(total_Com_Seq, total_Com, golds_found, total_num_golds, total_Score);
            cout << "\nCongratz, Mission ACCOMPLISHED!!" << endl << endl;
            break;
        }

    } while (c != 'Q' && c != 'q');

    showTreassure = showMap();
    if (showTreassure)
    {
        cout << endl;
        mars.displayTreassure();
    }
}

bool playAgn()
{

    bool TorF = false;
    string YESorNO;

    do
    {
    cout << "Do you want to PLAY AGAIN (y/n) ? => ";
    cin >> YESorNO;
    }while(YESorNO != "y" && YESorNO != "Y" &&
           YESorNO != "n" && YESorNO != "N" );

    if (YESorNO == "y" || YESorNO == "Y")
        TorF = true;
    else
        TorF = false;

    return TorF;
}

int main()
{
    int tm=1;
    int numOfWords=16;
    char welcome[sz][128];    // 80 for the letters and 48 for spaces

    printLetter(welcome,numOfWords,tm);
    cout << RESET << endl;
    system("pause");

    bool playAgain = false;

    do
    {
        system("cls");
        srand( time(NULL) );

        marsRover();

        playAgain = playAgn();

    } while(playAgain);

    cout <<          "\n ---------------------------\n";
    cout << BLUE  << "   Departing from MARS... \n";
    cout << RESET << " ---------------------------\n"; 
    cout << CYAN  << "      T H A N K   Y O U   \n";
    cout << BLUE  << "            A N D \n";
    cout << CYAN  << "        G O O D B Y E    \n";
    cout << RESET << " ---------------------------";

    Sleep(3000);

    return 0;
}