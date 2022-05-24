#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define keyUp 72
#define keyDown 80
#define keyLeft 75
#define keyRight 77
#define keyEnter 13
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char map[13][30];
int posCursorVerti = 2;
int posCursorHoriz = 2;
bool firstPlayer = true;
bool secondPlayer = false;

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void Hide(){
    printf("\e[?25l");
    COORD Curp;
    Curp.X = 0;
    Curp.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Curp);
}

void printMap() {
	for(int i = 0 ; i < 13 ; i++) {
		gotoxy(80, i+10);
		for(int j = 0 ; j < 30 ; j++) {
			if(map[i][j] == 'X') {
				printf(ANSI_COLOR_BLUE "%c", map[i][j]);
			} else if(map[i][j] == 'O') {
				printf(ANSI_COLOR_RED  "%c", map[i][j]);
			} else {
				printf(ANSI_COLOR_RESET "%c", map[i][j]);
			}
			if(j == 29) {
				printf("\n");
			}
		}
	}
}

void generateMap() {
    for(int i = 0 ; i < 13 ; i++) {
        for(int j = 0 ; j < 30 ; j++) {
            if(i == 0) {
                if(j == 0) {
                    map[i][j] = 201;
                } else if(j == 29){
                    map[i][j] = 187;
                    break;
                } else if(j % 10 == 0) {
                    map[i][j] = 203;
                } else {
                    map[i][j] = 205;
                } 
            } else if(map[i][j] == 'X') {
            	map[i][j] = 'X';
			} else if(map[i][j] == 'O') {
            	map[i][j] == 'O'; 	
			} else if(posCursorVerti == i) {
				if(posCursorHoriz == j) {
                    map[i][j] = '>';
               	} else if(j % 10 == 0) {
                    map[i][j] = 186;
            	} else if(j == 29) {
                    map[i][j] = 186;
                    break;
                } else {
                   	map[i][j] = ' ';
				} 
            } else if((i != 12) && (i % 4 == 0)) {
            	if(j % 10 == 0) {
                    map[i][j] = 186;
                } else if(j == 29) {
                    map[i][j] = 186; 
                    break;
                } else {
                	map[i][j] = 205;
				}
			} else if(i == 12) {
				if(j == 0) {
					map[i][j] = 200;
				} else if(j % 10 == 0) {
                    map[i][j] = 202;
                } else if(j == 29) {
                    map[i][j] = 188;
                    break;
                } else {
                	map[i][j] = 205;
				}
			}else {
                if(j%10 == 0) {
                    map[i][j] = 186;
                } else if(j == 29) {
                    map[i][j] = 186; 
                    break;
                } else {
                    map[i][j] = ' ';
				} 
            }
        }
    }
    printMap();
}

bool winningSolution() {
	gotoxy(70, 25);
	if(map[2][4] == 'X' && map[2][14] == 'X' && map[2][24] == 'X') { // Horizontal dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][4] == 'X' && map[6][14] == 'X' && map[10][24] == 'X') { // Diagonal dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][4] == 'X' && map[6][4] == 'X' && map[10][4] == 'X') { // Vertical dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][14] == 'X' && map[6][14] == 'X' && map[10][14] == 'X') { // vertical dari tengah atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][24] == 'X' && map[6][24] == 'X' && map[10][24] == 'X') { // vertical dari kanan atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][24] == 'X' && map[6][14] == 'X' && map[10][4] == 'X') { // diagonal dari kanan atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[6][4] == 'X' && map[6][14] == 'X' && map[6][24] == 'X') { // horizontal dari kiri tengah
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[10][4] == 'X' && map[10][14] == 'X' && map[10][24] == 'X') { // horizontal dari tengah atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 1 WIN!!!");
		return true;
	} else if(map[2][4] == 'O' && map[2][14] == 'O' && map[2][24] == 'O') { // Horizontal dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[2][4] == 'O' && map[6][14] == 'O' && map[10][24] == 'O') { // Diagonal dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[2][4] == 'O' && map[6][4] == 'O' && map[10][4] == 'O') { // Vertical dari kiri atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[2][14] == 'O' && map[6][14] == 'O' && map[10][14] == 'O') { // vertical dari tengah atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[2][24] == 'O' && map[6][24] == 'O' && map[10][24] == 'O') { // vertical dari kanan atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[2][24] == 'O' && map[6][14] == 'O' && map[10][4] == 'O') { // diagonal dari kanan atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[6][4] == 'O' && map[6][14] == 'O' && map[6][24] == 'O') { // horizontal dari kiri tengah
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if(map[10][4] == 'O' && map[10][14] == 'O' && map[10][24] == 'O') { // horizontal dari tengah atas
		printf(ANSI_COLOR_YELLOW "\t\t\tPLAYER 2 WIN!!!");
		return true;
	} else if((map[2][4] == 'X' || map[2][4] == 'O') && (map[2][14] == 'X' || map[2][14] == 'O') && (map[2][24] == 'X' || map[2][24] == 'O') && (map[6][4] == 'X' || map[6][4] == 'O') && (map[6][14] == 'X' || map[6][14] == 'O') && (map[6][24] == 'X' || map[6][24] == 'O') && (map[10][4] == 'X' || map[10][4] == 'O') && (map[10][14] == 'X' || map[10][14] == 'O') && (map[10][24] == 'X' || map[10][24] == 'O')) {
		printf(ANSI_COLOR_YELLOW "\t\t\t    DRAW");
		return true;
	}
	return false;
}

void playerTurn() {
	gotoxy(0,5);
	if(firstPlayer) {
		printf(ANSI_COLOR_BLUE "$$$$$$$\\  $$\\                                         \n");
		printf(ANSI_COLOR_BLUE "$$  __$$\\ $$ |                                        \n");
		printf(ANSI_COLOR_BLUE "$$ |  $$ |$$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$\\ \n");
		printf(ANSI_COLOR_BLUE "$$$$$$$  |$$ | \\____$$\ $$ |  $$ |$$  __$$\\ $$  __$$\\ \n");
		printf(ANSI_COLOR_BLUE "$$  ____/ $$ | $$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|\n");
		printf(ANSI_COLOR_BLUE "$$ |      $$ |$$  __$$ |$$ |  $$ |$$   ____|$$ |      \n");
		printf(ANSI_COLOR_BLUE "$$ |      $$ |\\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      \n");
		printf(ANSI_COLOR_BLUE "\\__|      \\__| \\_______| \\____$$ | \\_______|\\__|      \n");
		printf(ANSI_COLOR_BLUE "                        $$\\   $$ |                    \n");
		printf(ANSI_COLOR_BLUE "                        \\$$$$$$  |                    \n");
		printf(ANSI_COLOR_BLUE "                         \\______/                     \n");
		puts("");
		puts("");		
		printf(ANSI_COLOR_BLUE "                          $$\\                         \n");
		printf(ANSI_COLOR_BLUE "                        $$$$ |                        \n");
		printf(ANSI_COLOR_BLUE "                        \\_$$ |                        \n");
		printf(ANSI_COLOR_BLUE "                          $$ |                        \n");
		printf(ANSI_COLOR_BLUE "                          $$ |                        \n");
		printf(ANSI_COLOR_BLUE "                          $$ |                        \n");
		printf(ANSI_COLOR_BLUE "                        $$$$$$\                       \n");
		printf(ANSI_COLOR_BLUE "                        \\______|                      \n");
		puts("");
	} else {
		printf(ANSI_COLOR_RED "$$$$$$$\\  $$\\                                         \n");
		printf(ANSI_COLOR_RED "$$  __$$\\ $$ |                                        \n");
		printf(ANSI_COLOR_RED "$$ |  $$ |$$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$\\ \n");
		printf(ANSI_COLOR_RED "$$$$$$$  |$$ | \\____$$\ $$ |  $$ |$$  __$$\\ $$  __$$\\ \n");
		printf(ANSI_COLOR_RED "$$  ____/ $$ | $$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|\n");
		printf(ANSI_COLOR_RED "$$ |      $$ |$$  __$$ |$$ |  $$ |$$   ____|$$ |      \n");
		printf(ANSI_COLOR_RED "$$ |      $$ |\\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      \n");
		printf(ANSI_COLOR_RED "\\__|      \\__| \\_______| \\____$$ | \\_______|\\__|      \n");
		printf(ANSI_COLOR_RED "                        $$\\   $$ |                    \n");
		printf(ANSI_COLOR_RED "                        \\$$$$$$  |                    \n");
		printf(ANSI_COLOR_RED "                         \\______/                     \n");
		puts("");
		puts("");
		printf(ANSI_COLOR_RED "                         $$$$$$\\                      \n");
		printf(ANSI_COLOR_RED "                        $$  __$$\\                     \n");
		printf(ANSI_COLOR_RED "                        \\__/  $$ |                    \n");
		printf(ANSI_COLOR_RED "                         $$$$$$  |                    \n");
		printf(ANSI_COLOR_RED "                        $$  ____/                     \n");
		printf(ANSI_COLOR_RED "                        $$ |                          \n");
		printf(ANSI_COLOR_RED "                        $$$$$$$$\                     \n");
		printf(ANSI_COLOR_RED "                        \\________|                    \n");
		puts("");
	}
}

void operate() {
	while(true) {
		puts("");
		puts("");
		Hide();
		
		generateMap();
		bool finish = winningSolution();
		if(finish) {
			break;
		}
		playerTurn();
		
		if(kbhit()) {
			char button = getch();
			if(posCursorVerti != 2 && button == keyUp) {
				posCursorVerti -= 4;
			} else if(posCursorVerti != 10 && button == keyDown) {
				posCursorVerti += 4;
			} else if(posCursorHoriz != 2 && button == keyLeft) {
				posCursorHoriz -= 10;
			} else if(posCursorHoriz != 22 && button == keyRight) {
				posCursorHoriz += 10;
			} else if(button == keyEnter) {
				if(firstPlayer) {
					if(map[posCursorVerti][posCursorHoriz+2] == ' ') {
						firstPlayer = false;
						secondPlayer = true;
						map[posCursorVerti][posCursorHoriz+2] = 'X';
					}
				} else if(secondPlayer) {
					if(map[posCursorVerti][posCursorHoriz+2] == ' ') {
						secondPlayer = false;
						firstPlayer = true;
						map[posCursorVerti][posCursorHoriz+2] = 'O';
					}
				}
			}
		}
		puts("");
    	puts("");
	}
	getchar();
	system("CLS");
}

int main () {
	system("CLS");
	operate();
    return 0;
}
