#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{
	int i, r, j, wHeight, wWidth, spin, shift;
	struct timespec time1, time2;
	time1.tv_nsec = 100000000L;           //.1 seconds(in nanoSeconds)
	time1.tv_sec = 0;                     //0 seconds
	
	spin = 1;
	shift = 10;
	
	srand(time(NULL));                    //seedRNG with system timer
	
	initscr();                            //start screen
	getmaxyx(stdscr, wHeight, wWidth);    //get terminal width and height
	printf("H%d, W%d, CLOCKS_PER_SEC:%ld", wHeight, wWidth, CLOCKS_PER_SEC);
	//getchar();
	
	start_color();
	cbreak();                             //disable tty char buffer
	
	//WINDOW * win = newwin(20, 20, 0, 0);
	
	refresh(); 
	                          
	for(j=0; j<1000; j++){
	    for(i=0; i<(wHeight*wWidth); i++){
		    r = rand() % 2;
		    if(r == 0)
			    addch(' ');
		    else
			    addch(' ');
			    
			if(((i%shift)&(shift>>2)) == 0){
				if(spin == 1 || spin == 5)
				    addch('|');
				if(spin == 2 || spin == 6)
					addch('/');
				if(spin == 3 || spin == 7)
					addch(ACS_HLINE);
				if(spin == 4)
					addch('\\');
				if(spin == 8){
					addch('\\');
					spin = 0;
				}
				spin++;
			}
	    }
			
		
		
		/*srand(time(NULL));*/    
	    refresh();                        //display output
		nanosleep(&time1, &time2);        //sleep .2 seconds
		clear();                          //clear window
		(shift++)%127;
	}
		
	getchar();
	endwin();                             //set terminal mode back to normal
	return 0;
}

