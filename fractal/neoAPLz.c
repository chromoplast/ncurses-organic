#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{
	int i, r, j, k, wHeight, wWidth;
	struct timespec time1, time2;
	time1.tv_nsec = 50000000L;           //.1 seconds(in nanoSeconds)
	time1.tv_sec = 0;                     //0 seconds
	
	
	srand(time(NULL));                    //seedRNG with system timer
	
	initscr();                            //start screen
	getmaxyx(stdscr, wHeight, wWidth);    //get terminal width and height
	printf("H%d, W%d, CLOCKS_PER_SEC:%ld", wHeight, wWidth, CLOCKS_PER_SEC);
	//getchar();
	
	start_color();
	cbreak();                             //disable tty char buffer
	
	//WINDOW * win = newwin(20, 20, 0, 0);
	
	refresh(); 
	                          
	
	for(i = 0, k = 0; i<1000; i++){
		for(j=0; j<(wWidth*wHeight); j++, k++){
			move( ((k&(i>>2)%wHeight)), ((k&(i>>2)%wWidth)));
			addch(/*k%127*/ACS_CKBOARD);
		}
		refresh();
		nanosleep(&time1, &time2);
		//clear();
	}
		
			
		
	getchar();
	endwin();                             //set terminal mode back to normal
	return 0;
}

