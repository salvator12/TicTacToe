#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define keyUp 72
#define keyDown 80
#define keyLeft 75
#define keyRight 77
#define keyEnter 13
#define ANSI_COLOR_RESET   "\x1b[0m"

int flagExit = 0;

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

void menuGame() {
	if(flagExit == 1) {
		return;
	}
	char menuOption[100][100] = {" Player vs Player", "     ", "  Player vs Bot", "     ","      EXIT"};
	int posCursor = 0;
	system("CLS");
	puts("");
	puts("");
	Hide();
	gotoxy(35,4);
	puts("\t /$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$$$ /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$  /$$$$$$$$");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t|__  $$__/|_  $$_/ /$$__  $$      |__  $$__//$$__  $$ /$$__  $$      |__  $$__//$$__  $$| $$_____/");
		for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   | $$     | $$  | $$  \\__/         | $$  | $$  \\ $$| $$  \\__/         | $$  | $$  \\ $$| $$      ");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   | $$     | $$  | $$               | $$  | $$$$$$$$| $$               | $$  | $$  | $$| $$$$$   ");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   | $$     | $$  | $$               | $$  | $$__  $$| $$               | $$  | $$  | $$| $$__/   ");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   | $$     | $$  | $$    $$         | $$  | $$  | $$| $$    $$         | $$  | $$  | $$| $$      ");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   | $$    /$$$$$$|  $$$$$$/         | $$  | $$  | $$|  $$$$$$/         | $$  |  $$$$$$/| $$$$$$$$");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	}
	puts("\t\t\t\t\t   |__/   |______/ \\______/          |__/  |__/  |__/ \\______/          |__/   \\______/ |________/");
	for(int i = 0 ; i < 100000000 ; i++) {
		;
	} 
	while(true) {
		puts("");
		puts("");
		Hide();
		gotoxy(35,4);
		puts("\t /$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$$$ /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$  /$$$$$$$$");
		puts("\t\t\t\t\t|__  $$__/|_  $$_/ /$$__  $$      |__  $$__//$$__  $$ /$$__  $$      |__  $$__//$$__  $$| $$_____/");
		puts("\t\t\t\t\t   | $$     | $$  | $$  \\__/         | $$  | $$  \\ $$| $$  \\__/         | $$  | $$  \\ $$| $$      ");
		puts("\t\t\t\t\t   | $$     | $$  | $$               | $$  | $$$$$$$$| $$               | $$  | $$  | $$| $$$$$   ");
		puts("\t\t\t\t\t   | $$     | $$  | $$               | $$  | $$__  $$| $$               | $$  | $$  | $$| $$__/   ");
		puts("\t\t\t\t\t   | $$     | $$  | $$    $$         | $$  | $$  | $$| $$    $$         | $$  | $$  | $$| $$      ");
		puts("\t\t\t\t\t   | $$    /$$$$$$|  $$$$$$/         | $$  | $$  | $$|  $$$$$$/         | $$  |  $$$$$$/| $$$$$$$$");
		puts("\t\t\t\t\t   |__/   |______/ \\______/          |__/  |__/  |__/ \\______/          |__/   \\______/ |________/");
		puts("");
		puts("");
		printf("\t\t\t\t\t\t\t\t\t%c", 201);
		
		for(int i = 0 ; i < 30 ; i++) {
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t\t\t\t\t\t%c			       %c\n", 186, 186);
		for(int i = 0 ; i < 5 ; i++) {
			printf("\t\t\t\t\t\t\t\t\t%c", 186);
			if(posCursor == i) {
				printf("  >>");
			} else {
				printf("    ");
			}
			printf("  %s", menuOption[i]);
			int len = strlen(menuOption[i]);
			for(int j = len ; j < 20 ; j++) {
				printf(" ");
			}
			if(posCursor == i) {
				printf("<<");
			} else {
				printf("  ");
			}
			printf("  %c", 186);
			puts("");
		}
		printf("\t\t\t\t\t\t\t\t\t%c			       %c\n", 186, 186);
		printf("\t\t\t\t\t\t\t\t\t%c", 200);
		for(int i = 0; i < 30; i++){
			printf("%c", 205);
		}
		printf("%c\n", 188);
		puts("");
		if(kbhit()){
			char button = getch();
			if(posCursor!= 0 && button == keyUp){
				posCursor -= 2;
			}else if(posCursor != 4 && button == keyDown){
				posCursor += 2;
			}else if(button == keyEnter){
				system("CLS");
				switch(posCursor){
					case 0:
						system("PlayerVsPlayer1.exe");
					break;
					case 2:
						system("PlayingWithBot.exe");
					break;
					case 4:
						flagExit = 1;
						return;
					break;
				}
				system("CLS");
			}
		}
		puts(ANSI_COLOR_RESET);
	}	
}

int main () {
	menuGame();
}
