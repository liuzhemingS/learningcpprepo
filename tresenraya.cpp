#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void movePlayer(char *spaces, char player);
void moveComputer(char *spaces, char computer);
bool checkTie(char *spaces);
bool checkWinner(char *spaces, char player, char computer);

int main()
{
    char player = 'x';
    char computer = 'O';
    bool running = true;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    drawBoard(spaces);
    while(running){
        movePlayer(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        } else if(checkTie(spaces)){
            running = false;
            break;
        }
        moveComputer(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        } else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}

void drawBoard(char *spaces)
{
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  "<< spaces[1] <<"  |  "<< spaces[2] <<" \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  "<< spaces[3] <<"  |  "<< spaces[4] <<"  |  "<< spaces[5] <<"  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  "<< spaces[6] <<"  |  "<< spaces[7] <<"  |  "<< spaces[8] <<"  \n";
    std::cout << "     |     |     \n";
    std::cout << "\n";    
}
void movePlayer(char *spaces, char player)
{
    int num;
    
    do{
        std::cout << "Choose your next move (1-9): ";
        std::cin >> num;
        num--;
        if (spaces[num] == ' ') {
            spaces[num] = player;
            break;
        }; 
    } 
    while (!num > 0 || !num < 8);
    
}
void moveComputer(char *spaces, char computer)
{
    int num;
    srand(time(0));
    while(true){
        num = rand() % 9;
        if (spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }

    }
}
bool checkTie(char *spaces)
{
    for (int i = 0; i<9;i++){
        if (spaces[i] == ' ') return false;
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}
bool checkWinner(char *spaces, char player, char computer)
{
    int winPoss[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8,},{2,4,6},{0,4,8}};
    for (int i = 0; i <= 8; i++){
        int x = winPoss[i][0];
        int y = winPoss[i][1];
        int z = winPoss[i][2];

        if (spaces[x] != ' '&&spaces[x] == spaces[y]&&spaces[y]==spaces[z]){
            if (spaces[x] == player){
                std::cout << "YOU WIN!\n";
                return true;
            } else{
                std::cout << "YOU LOOSE!\n";
                return false;
            }
            break;
        }
    }
    return 0;
}