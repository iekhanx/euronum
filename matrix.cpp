/*
 *    01/04/2014    @ik
*/
//#define _EUROMILLION_

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include "adf_colors.h"

using namespace std;

bool IS_COLOR = false;

void checktty(int fd, const char *name)
{
   if(isatty(fd) == 0)
   {
	if(errno == EINVAL || errno == ENOTTY)
           //cout << name << " is not a Terminal" << endl; 
           cout << endl;
	else {
 		//cout << name << "  ";
	   	//perror("isatty");
                cout << endl;
          }
   }
   else 
      //cout << name << " is a Terminal" << endl; 
      cout << endl;
      IS_COLOR = true; 
}

int generateNumber(int maxnum)
{
	return ((int) (rand()%maxnum + 1));
}

void xsort(int list[], int length)
{
	int i=1;
	int j;

	while(i < length ) {
		for(j=i; list[j-1] > list[j]; j--)
		{
			int tmp = list[j];
			list[j] = list[j-1];
			list[j-1] = tmp;
		}
	     i++;
	}
} 


void sort(int list[], int length, int num)
{
	int i, j, k, min;
	int nsort[num];

        i = j = k = min = 0;
	
	for(i=0; i<num; i++)
	   nsort[i] = list[i];   // assign

	for(i=0; i<num; i++) {
	   k = i;
	   min = list[i];
           for(j=0; j<num; j++) {
	      if(list[j] < min) { 
	        min = list[j];
                k = j;
              }
            }
           nsort[i] = min;
           list[k] = 99;
          }
      for(i=0; i<num; i++) 
           list[i] = nsort[i];   
}

int main(int argc, char* argv[]) {
	int **matrix;
	int i, j, count;
	int row;
	int max = 50;
        int col = 5;

	if(argv[1] == '\0') {	    
	     cout << "Please enter at command line number of tickets to be printed?" << endl;
             cout << "\nEnter the number of rows: "; 
	     cin >> row;
	  return 0;
	}

        count = atoi(argv[1]);
	if(count >= 1)
	   row = count;

        checktty(STDIN_FILENO,  "stdin");	// establish color terminal exists?
	checktty(STDOUT_FILENO, "stdout");
	checktty(STDERR_FILENO, "stderr");

#ifdef _EUROMILLION_
	int col = 5;
	int col;
        cout << "\nEnter the number of columns for the matrix: "; 
	cin >> col;
#endif
	int ball[col];
        int str[2];
        int x = 11;
	int y = 2;
        srand(time(NULL));

	matrix = new int *[row];
	for(count = 0; count < row; count++) {
		matrix[count] = new int [col]; }

cout << "Euro Million Lottery Tickets Number                  Star Numbers" << endl;
cout << "-----------------------------------------------------------------" << endl;
cout << "                1       2       3       4       5       1       2" << endl;cout << "=================================================================" << endl; 
	for (i=0; i<row; i++) 
	{
                for(j=0; j<col; j++)
		{
		   ball[j] = generateNumber(max);
		}
               for(y = 0; y < 2; y++)
		  str[y] = generateNumber(x);
		
	       sort(ball,  max, col);
	       sort(str, x, y);

          if(IS_COLOR) {
	       cout << setw(10) << i << ")\t" <<red<< ball[0] <<none<< "\t" 
                    << ball[1] << "\t"green<< ball[2]<<none<< "\t" <<blue<< ball[3] <<none<<
                                  "\t" <<yellow<< ball[4] <<none<< "\t" <<cyan<< str[0] <<none<<
				  "\t" <<magenta<< str[1]<<none <<endl;
           } else {
	       cout << setw(10) << i << ")\t"<< ball[0] << "\t" 
                    << ball[1] << "\t"<< ball[2] << "\t" << ball[3] << 
                                  "\t"<< ball[4] << "\t" << str[0]  <<
				  "\t"<< str[1] << endl;
             }
	}

	for(int count = 0; count < row; count++)
	delete[] matrix[count];
	delete[] matrix;
	matrix = 0;
 
   return 0;
}

