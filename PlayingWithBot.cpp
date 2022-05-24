#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
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
				printf(ANSI_COLOR_CYAN "%c", map[i][j]);
			} else if(map[i][j] == 'O') {
				printf(ANSI_COLOR_GREEN  "%c", map[i][j]);
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

void playerTurn(int player) {
	gotoxy(0,5);
	if(firstPlayer) {
		printf(ANSI_COLOR_CYAN "$$$$$$$\\  $$\\                                         \n");
		printf(ANSI_COLOR_CYAN "$$  __$$\\ $$ |                                        \n");
		printf(ANSI_COLOR_CYAN "$$ |  $$ |$$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$\\ \n");
		printf(ANSI_COLOR_CYAN "$$$$$$$  |$$ | \\____$$\ $$ |  $$ |$$  __$$\\ $$  __$$\\ \n");
		printf(ANSI_COLOR_CYAN "$$  ____/ $$ | $$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|\n");
		printf(ANSI_COLOR_CYAN "$$ |      $$ |$$  __$$ |$$ |  $$ |$$   ____|$$ |      \n");
		printf(ANSI_COLOR_CYAN "$$ |      $$ |\\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      \n");
		printf(ANSI_COLOR_CYAN "\\__|      \\__| \\_______| \\____$$ | \\_______|\\__|      \n");
		printf(ANSI_COLOR_CYAN "                        $$\\   $$ |                    \n");
		printf(ANSI_COLOR_CYAN "                        \\$$$$$$  |                    \n");
		printf(ANSI_COLOR_CYAN "                         \\______/                     \n");
		puts("");
		puts("");		
		printf(ANSI_COLOR_CYAN "                          $$\\                         \n");
		printf(ANSI_COLOR_CYAN "                        $$$$ |                        \n");
		printf(ANSI_COLOR_CYAN "                        \\_$$ |                        \n");
		printf(ANSI_COLOR_CYAN "                          $$ |                        \n");
		printf(ANSI_COLOR_CYAN "                          $$ |                        \n");
		printf(ANSI_COLOR_CYAN "                          $$ |                        \n");
		printf(ANSI_COLOR_CYAN "                        $$$$$$\                       \n");
		printf(ANSI_COLOR_CYAN "                        \\______|                      \n");
		puts("");
		puts("");
	} else if(secondPlayer){
		printf(ANSI_COLOR_GREEN "$$$$$$$\\  $$\\                                         \n");
		printf(ANSI_COLOR_GREEN "$$  __$$\\ $$ |                                        \n");
		printf(ANSI_COLOR_GREEN "$$ |  $$ |$$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$\\ \n");
		printf(ANSI_COLOR_GREEN "$$$$$$$  |$$ | \\____$$\ $$ |  $$ |$$  __$$\\ $$  __$$\\ \n");
		printf(ANSI_COLOR_GREEN "$$  ____/ $$ | $$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|\n");
		printf(ANSI_COLOR_GREEN "$$ |      $$ |$$  __$$ |$$ |  $$ |$$   ____|$$ |      \n");
		printf(ANSI_COLOR_GREEN "$$ |      $$ |\\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      \n");
		printf(ANSI_COLOR_GREEN "\\__|      \\__| \\_______| \\____$$ | \\_______|\\__|      \n");
		printf(ANSI_COLOR_GREEN "                        $$\\   $$ |                    \n");
		printf(ANSI_COLOR_GREEN "                        \\$$$$$$  |                    \n");
		printf(ANSI_COLOR_GREEN "                         \\______/                     \n");
		puts("");
		puts("");
		printf(ANSI_COLOR_GREEN "                         $$$$$$\\                      \n");
		printf(ANSI_COLOR_GREEN "                        $$  __$$\\                     \n");
		printf(ANSI_COLOR_GREEN "                        \\__/  $$ |                    \n");
		printf(ANSI_COLOR_GREEN "                         $$$$$$  |                    \n");
		printf(ANSI_COLOR_GREEN "                        $$  ____/                     \n");
		printf(ANSI_COLOR_GREEN "                        $$ |                          \n");
		printf(ANSI_COLOR_GREEN "                        $$$$$$$$\                     \n");
		printf(ANSI_COLOR_GREEN "                        \\________|                    \n");
		puts("");
		puts("");
	}
}
	
int selectPlayer() {
	int CursorSelect = 0;
	printf("%d\n", CursorSelect);
	while(true) {
		Hide();
		char selectOption[50][50] = {" 1", "     ", " 2"};
		gotoxy(35,10);
		printf("Select Your Player\n\n");
		printf("\t\t\t\t   %c", 201);
		for(int i = 0 ; i < 17 ; i++) {
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t   %c                 %c\n",186, 186);
		for(int i = 0 ; i < 3 ; i++) {
			printf("\t\t\t\t   %c", 186);
			if(CursorSelect == i) {
				printf("  >>");
			} else {
				printf("    ");
			}
			printf("   %s", selectOption[i]);
			int len = strlen(selectOption[i]);
			for(int j = len ; j < 5 ; j++) {
				printf(" ");
			}
			if(CursorSelect == i) {
				printf(" <<");
			} else {
				printf("   ");
			}
			printf("  %c", 186);
			puts("");
		}
		printf("\t\t\t\t   %c                 %c\n",186, 186);
		printf("\t\t\t\t\   %c", 200);
		for(int i = 0 ; i < 17 ; i++) {
			printf("%c", 205);
		}
		printf("%c\n", 188);
		if(kbhit()) {
			char button = getch();
			if(CursorSelect != 0 && button == keyUp) {
				CursorSelect -= 2;
			} else if(CursorSelect != 2 && button == keyDown) {
				CursorSelect += 2;
			} else if(button == keyEnter) {
				switch(CursorSelect) {
					case 0:
						return 1;
						break;
					case 2:
						return 2;
						break;
				}	
			}
		}
	}	
}

void StartPlay() {
	
	int coordinate[9][2] = {{2,2}, {2,12}, {2,22}, {6,2}, {6,12}, {6,22}, {10,2}, {10,12}, {10,22}};
	int player = selectPlayer();
	int bot;
	if(player == 1) {
		bot = 2;
	} else if(player == 2){
		bot = 1;
	}
	system("CLS");
	while(true) {
		srand(time(0));
		puts("");
		puts("");
		Hide();
		generateMap();
		bool finish = winningSolution();
		if(finish) {
			break;
		}
		playerTurn(player);
		if(firstPlayer && player == 1) {
			gotoxy(0,27);
			printf(ANSI_COLOR_CYAN "                      [YOUR TURN]                         \n");
		} else if(firstPlayer && bot == 1){
			gotoxy(0,27);
			printf(ANSI_COLOR_CYAN "                       [BOT TURN]                         \n");
		} else if(secondPlayer && player == 2){
			gotoxy(0,27);
			printf(ANSI_COLOR_GREEN "                      [YOUR TURN]                         \n");
		} else if(secondPlayer && bot == 2){
			gotoxy(0,27);
			printf(ANSI_COLOR_GREEN "                       [BOT TURN]                         \n");
		}
		if(kbhit()) {
			char button = getch();
			if(firstPlayer && bot == 1) {
				while(true) {
					int coorRand = rand() % 9;
					if(map[coordinate[coorRand][0]][coordinate[coorRand][1]+2] == ' ') {
						firstPlayer = false;
						secondPlayer = true;
						map[coordinate[coorRand][0]][coordinate[coorRand][1]+2] = 'X';
						generateMap();
						break;
					}
				}
			} else if(secondPlayer && bot == 2) {
				while(true) {
					int coorRand = rand() % 9;
					if(map[coordinate[coorRand][0]][coordinate[coorRand][1]+2] == ' ') {
						firstPlayer = true;
						secondPlayer = false;
						map[coordinate[coorRand][0]][coordinate[coorRand][1]+2] = 'O';
						generateMap();
						break;
					}
				}
			} else if(posCursorVerti != 2 && button == keyUp) {
				posCursorVerti -= 4;
			} else if(posCursorVerti != 10 && button == keyDown) {
				posCursorVerti += 4;
			} else if(posCursorHoriz != 2 && button == keyLeft) {
				posCursorHoriz -= 10;
			} else if(posCursorHoriz != 22 && button == keyRight) {
				posCursorHoriz += 10;
			} else if(button == keyEnter) {
				if(firstPlayer && player == 1) {
					if(map[posCursorVerti][posCursorHoriz+2] == ' ') {
						firstPlayer = false;
						secondPlayer = true;
						map[posCursorVerti][posCursorHoriz+2] = 'X';
					}
				} else if(secondPlayer && player == 2) {
					if(map[posCursorVerti][posCursorHoriz+2] == ' ') {
						firstPlayer = true;
						secondPlayer = false;
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
	StartPlay();
    return 0;
}
