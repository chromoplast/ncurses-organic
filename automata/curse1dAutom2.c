#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{
	//INITIALIZE CLOCK AND VARIABLES------------------------------------/
	int i, r, j, k, wHeight, wWidth;
	
	struct timespec time1, time2;
	time1.tv_nsec = 40000000L;                  //.1 seconds(in nanoSeconds)
	time1.tv_sec = 0;                     //0 seconds
	
	
	srand(time(NULL));                    //seedRNG with system timer
	
	
	//CURSES SETUP------------------------------------------------------/
	initscr();                            //start screen
	getmaxyx(stdscr, wHeight, wWidth);    //get terminal width and height
	
	
	printf("H%d, W%d, CLOCKS_PER_SEC:%ld", wHeight, wWidth, CLOCKS_PER_SEC);
	//getchar();
	
	start_color();
	cbreak();                             //disable tty char buffer
	
	//WINDOW * win = newwin(20, 20, 0, 0);
	
	refresh(); 
	
	//ARRAY SETUP-------------------------------------------------------/
	int arr1[wWidth], arr2[wWidth];
	
	for(i=0; i < wWidth; i++){
		r = rand() % 2;
		if(r == 0)
			arr1[i] = 1;
		else
			arr1[i] = 0;
		}
	
	//ARRAY LOGIC AND DISPLAY-------------------------------------------/
	for(i = 0; i < 7000; i++){
		for(j = 0; j < wWidth; j++){
			if(j == 0){
				if((arr1[j+1]) == 1)
					arr2[j] = 0;
				else
					arr2[j] = 1;
			}
			else if(j == (wWidth - 1)){
				if(arr1[j-1] == 1)
					arr2[j] = 0;
				else
					arr2[j] = 1;
			}
			else{
				//printf("!");
				if((arr1[j-1]+arr1[j+1]) == 2)
					arr2[j] = 0;
				else if((arr1[j-1]+arr1[j+1]) == 1)
					arr2[j] = 1;
				else
					arr2[j] = 0;
			}
		}
		for(j = 0; j < wWidth; j++){
			//printf("%d", arr2[j]);
			if(arr2[j] == 0){
				//printf("o");
				move(i%wHeight, j);
				addch(ACS_CKBOARD);
			}
			else
				//printf(" ");
				move(j, i%wWidth);
				addch(' ');
			}
		
		for(j = 0; j < wWidth; j++)
			arr1[j] = arr2[j];
			
		//printf("\n");
		refresh();
		nanosleep(&time1, &time2);
		
	}
	getchar();
	endwin();
}
	
	
