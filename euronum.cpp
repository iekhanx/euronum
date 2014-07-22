/*
 * 31/03/2014          @ik
 *
 * Generate Euromillion lottery numbers
 *
 *    Range   1 - 50     for 5 chosen numbers
 *    Rang    1 - 11     for 2 Star numbers
 *
 *    As once complete Euro Million lotto number LINE as follow
 *
 *    20 25 28 30 40  Star number 2 10
 *
 *    Option allows you to create number of LINES of chosen numbers.
 *    
 */

#define EUROMILLION_BALLS       50  // Total balls
#define EUROMILLION_STARS       11  // Total Star balls

#define UK_LOTTERY_BALLS        49  // Total balls 
#define UK_THUNDER_BALLS        49

#define EUROMILLION_BALL_PICK    5  // 5 picks
#define EUROMILLION_STAR_PICK    2  // 2 star pick 

#define UK_LOTTERY_BALL_PICK    6   // 6 picks
#define UK_THUNDER_BALL_PICK    6
#define US_LOTTERY_BALL_PICK    6
#define MX_LOTTERY_BALL_PICK    6   

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "adf_colors.h"
#include <cstring>

using namespace std;

void my_sleep(unsigned msec) {
    struct timespec req, rem;
    int err;
    req.tv_sec = msec / 1000;
    req.tv_nsec = (msec % 1000) * 1000000;
    while ((req.tv_sec != 0) || (req.tv_nsec != 0)) {
        if (nanosleep(&req, &rem) == 0)
            break;
        err = errno;
        // Interrupted; continue
        if (err == EINTR) {
            req.tv_sec = rem.tv_sec;
            req.tv_nsec = rem.tv_nsec;
        }
        // Unhandleable error (EFAULT (bad pointer), 
        // EINVAL (bad timeval in tv_nsec), or 
        // ENOSYS (function not supported))
     break;
    }
}


class CBirthday {
     public:
        int Bday() {
           while (true) {
            cout << "\nEnter Birthday - Day (1 or 31 Days) [0 = Exit]: ";
            getline(cin,input);
	    stringstream myStream(input);
	    if(myStream >> day) {		
              if((day > 1) && (day <= 31)) 
                     break;
            }
	    if(day == 0)
		break;

	    cout << "Invalid Number. Please try again" << endl;	
           };

         return day;
        }

        int Mon()  {
            while(true) {
                cout << "\nEnter Birthday - Month (1 - 12) [0 = Exit]: ";
                getline(cin, input); 
		stringstream myStream(input);
		if(myStream >> mon)
	         if ((mon > 1) && (mon <= 12))
		     break;
                if(mon == 0)
		   break;
             
	        cout << "Invalid Number. Please try again" << endl;	
              } 

          return mon;
        }

        int Year() {
          while(true) {
           cout << "\nEnter Birthday - Year (two digit only 1-50) [0 = Exit]: ";
           getline(cin, input);
	   stringstream myStream(input);
	   if(myStream >> year)
            if ((year > 1) && (year <= 50))
                   break;
           if(year == 0) 
	     break;
        
	    cout << "Invalid Number. Please try again" << endl;	
          } 
        return year;
       }
    protected:
        short day, mon, year;
        string input;
};

class CLuckyNum {
    public:
        int Luckynum()
        {
          while(true) {
             cout <<"\nEnter 1 Lucky Number of your choice (1-50) [0=Exit]: ";
             getline(cin, input);
	     stringstream myStream(input);
	     if(myStream >> anum)	
               if((anum > 1) && (anum < 50))
		   break; 
                if(anum == 0)
		   break;

	       cout << "Invalid Number. Please try again" << endl;	
             } 
          return anum;
        }

    protected:
        int anum;
        string input;
};

class CNumbers {
    public:
	int generateNumbers(const int flag);
        int currentSecond();   // second int value for srand()
	virtual void LoadNumber() =0; 	
};

int CNumbers::generateNumbers(const int flag)
{
       return ((int) (rand()% flag + 1)); 
}

int CNumbers::currentSecond()
{
	time_t   now = time(0);
	tm       *ltm = localtime(&now);
      return ltm->tm_sec;
}

string currentDateTime()
{
	time_t  now = time(0);
	tm      ltm;
	char    buf[80] = {0};

	ltm = *localtime(&now);

	strftime(buf, sizeof(buf), "%d/%m/%Y  Time: %X", &ltm);

     return buf;
}

int OptionQuestion()
{
      int ret= 0;
      char ch[] = {0};
      string input = "";
       while(true) {
        cout << "\nDo you have a BIAS for numbers to be drawn" << endl;
        cout << "i.e such as Date of Birth and Lucky Number? " << endl;
        cout << endl;
        cout << "Please enter yY/nN ";
        getline(cin, input);
	if(input.length() == 1) {
		ch[0] = input[0];
            break;
	  }
       }

   if((ch[0] == 'y') || (ch[0] == 'Y'))
   { 
        input.clear();
        while(true) {
#ifdef _MONO_
        cout << "**************************" << endl;
        cout << "|        Sub Menu        |" << endl;
        cout << "**************************" << endl;
        cout << "|                        |" << endl;
        cout << "|   1 - Birth Day Date   |" << endl;
        cout << "|   2 - Lucky Number     |" << endl;
        cout << "|   3 - Both             |" << endl;
        cout << "|                        |" << endl;
        cout << "|   0 - Exit             |" << endl;
        cout << "|                        |" << endl;
        cout << "**************************" << endl;
        cout << endl << endl;
        cout << "Make your choice .......: ";
 #else
        printf("***************************|\n");
        printf("|        %sSub Menu%s          |\n", cyan, none);
        printf("***************************|\n");
        printf("|                          |\n");
        printf("|   %s1 - Birth Day Date%s     |\n", blue, none);
        printf("|   %s2 - Lucky Number%s       |\n", green, none);
        printf("|   %s3 - Both%s               |\n", red, none);
        printf("|                          |\n");
        printf("|  %s 0 - Exit%s               |\n", magenta, none);
        printf("|                          |\n");
        printf("****************************\n");
        printf("\n\n");
        printf("%sMake your choice ......:%s ", white, none);
#endif
        getline(cin, input);
	stringstream myStream(input); // convert string to number
	if(myStream >> ret)
	   break;
        
	cout << "\nInvalid number entered! Please try again" << endl;
       }
    }
   return ret;
}

int showChoices()
{
     int nval;
     string input = "";
    
     while(true) {	
	printf("%s",cls);
#ifdef _MONO_
	cout << "____________________" << endl;
	cout << "|       MENU       |" << endl;
	cout << "|__________________|" << endl;
	cout << "|                  |" << endl;
	cout << "| 1 EuroMillions   |" << endl;
	cout << "| 2 UK Lottery     |" << endl;
	cout << "| 3 UK Thunder Ball|" << endl;
	cout << "| 4 US Lottery     |" << endl;
	cout << "| 5 Mexico Lottery |" << endl;
	cout << "| 0 Exit           |" << endl;
	cout << "|__________________|" << "Date: " << currentDateTime() << endl;
	cout << "                    " << endl;
	cout << "Enter your Choice (1-5) [0 = Exit] ";
#else
        cout << "                                    Date: " << currentDateTime() << endl;     
	printf("______________________\n");
	printf("|        MENU        |\n");
	printf("|____________________|\n");
	printf("|                    |\n");
	printf("|%s1 EuroMillions      %s|\n", cyan, none);
	printf("|%s2 UK Lottery        %s|\n", red, none);
	printf("|%s3 UK Thunderball    %s|\n", magenta, none);
	printf("|%s4 US Lottery        %s|\n", cyan, none);
	printf("|%s5 Mexico Lottery    %s|\n", green, none);
	printf("|%s0 Exit              %s|\n", white, none);
	printf("|____________________|\n");
	printf("\n\n");
	printf("%sEnter your Choice (1-5) [0 = Exit]: %s", white, none); 
#endif
	getline(cin,input);
	
	stringstream myStream(input);	// convert string to number safely.
	if(myStream >> nval)
	   break;
	cout << "\nInvalid number entered! Please try again\n" << endl;
    }

   return nval; 
}

int GetNumberOfLinesTicket()
{
        string input = "";
	int nval;
	while(true) {
#ifdef _MONO_
	cout << "\nEnter Number of Line(s) of Ticket Number ";
#else
	printf("\n%sEnger Number of Line(s) of Ticket Number%s  ", white, none);
#endif
	getline(cin, input);
	stringstream myStream(input);
	if(myStream >> nval)
	   break;
	cout << "Invalid Number. Please try again" << endl;
      }
  return nval;
}

void doDisplayMsg(string str, int num)
{
	char * mystr = new char [str.length()+1];

	strcpy(mystr, str.c_str());
#ifdef _MONO_
	cout << "\n" << str << "  " << num << endl << endl;
#else
	if(num >= 1)
	    printf("\n%s %s %s %s%02d%s\n", 
		   lgreen,mystr,none,white,num,none);
	else
	    printf("\n%s %s %s\n", white, mystr, none);

#endif
     delete[] mystr;
}

class CLottery : public CNumbers {
     public:
	CLottery(short d, short m, short y, short k, int p, int t) : 
          bDay(d), bMon(m), bYear(y), nLucky(k), play(p), numberOfLines(t) {} ; 
	
	void SetNumber();
	void doHeadingInfo();
	void PickNumber();
	void PickStar();
	void LoadNumber();
	void SortNumbers();
	void SortStars();
	~CLottery() { delete [] nBallPick; delete [] nBallStar; }
    protected:
	short bDay;
	short bMon;
	short bYear;
	short nLucky;

	short numPick;

	int play;
	int numberOfLines; 
     protected:                   // Total number of tickets
	int nBallPick[EUROMILLION_BALL_PICK + 1]; // 5
	int nBallStar[EUROMILLION_STAR_PICK]; // 2	
};

class CLException : public exception {
     virtual const char* what() const throw()
     {
	return "Memory allocation to nBAllPick and nBallStar failed";
     }
} loterr;

void CLottery::SetNumber()
{
	switch(play)
	{
		case 1:{
			numPick = EUROMILLION_BALL_PICK;}
			break;
		case 2:
		case 3:
		case 4:
		case 5:{
			numPick = MX_LOTTERY_BALL_PICK;}
			break;
		default:	
			break;
	}	
}

void CLottery::SortNumbers()
{
    int i, j, k, min;
    int sortNumber[numPick];

  try {
     for(i=0; i < numPick; i++)  // store in temp 
      	 sortNumber[i] = nBallPick[i];
 
      for(i=0; i < numPick; i++)
       {
	   k = i;
	   min = nBallPick[i];
           for(j=0; j < numPick; j++)
	   {
              if(nBallPick[j] < min) 
              {
	        min = nBallPick[j];
	         k = j;
               }
	    }
           sortNumber[i] = min;
           nBallPick[k] = 99; 
          }
          for(i=0; i < numPick; i++)
	     nBallPick[i] = sortNumber[i];        
      }
     catch( exception& e) { 
           cout << e.what() << endl; 
     }
}

void CLottery::SortStars()
{      
    int i, j, k, min; 
    int sortStar[EUROMILLION_STAR_PICK];    
 try {    
    for(i=0; i<EUROMILLION_STAR_PICK; i++)
            sortStar[i] = nBallStar[i];

   	for(i=0; i < EUROMILLION_STAR_PICK; i++) 
   	{
 		k = i;
		min = nBallStar[i];
        	for(j=0; j < EUROMILLION_STAR_PICK; j++)
        	{
            		if(nBallStar[j] < min) 
			{ 
			    min = nBallStar[j]; 
                            k = j; 
                        }
		}
      		sortStar[i] = min;
     		nBallStar[k] = 99;
   	}	
    	for(i=0; i < EUROMILLION_STAR_PICK; i++)
		nBallStar[i] = sortStar[i];
    }
    catch(exception &e) {
         cout << e.what() << endl; }
}

void CLottery::PickNumber()
{
    int j;
  try {
    for(j=0; j < numPick; j++) 
               nBallPick[j] = generateNumbers(EUROMILLION_BALLS);

 
      	     	if((bDay >= 1) && (bDay <= 31)) {
	  		nBallPick[0] = bDay; }
      	

     		if((bMon >= 1) && (bMon <= 12)) {
	 		nBallPick[1] = bMon; }
    

     		if((bYear >= 1) && (bYear <= 50)) {
	 		nBallPick[2] = bYear; }
      		
		               
     		if((nLucky >= 1) && (nLucky <= 50)) {
	 		nBallPick[3] = nLucky;  }

              SortNumbers();
      }
     catch(exception& e)
     {
	cout << e.what() << endl;
    }
}

void CLottery::PickStar()
{
     int k;
    try {
        for(k=0;  k < EUROMILLION_STAR_PICK; k++)
            nBallStar[k] = generateNumbers(EUROMILLION_STARS);

       SortStars();
    }
    catch(exception& e)
   {
        cout << e.what() << endl;
  }
}

void CLottery::LoadNumber()
{
     int i;
     char ch[] = {0};
     string str = ""; 
     string lottonum = currentDateTime();
   
  try {
       ofstream numfile("lottonum.txt", ios::in|ios::ate);
       numfile.is_open();
       
    
       switch(play)
	{
	   case 1:	
           numfile << "Euro Million Lottery Tickets     Date " << currentDateTime() << endl;
             break;
	   case 2:
          numfile << "UK Lottery Tickets numbers       Date " << currentDateTime() << endl;
             break;
	   case 3:
           numfile << "UK Thunder Ball Lottery Ticket   Date " << currentDateTime() << endl;
	     break;
	   case 4:
           numfile << "US Lotter Tickets numbers        Date " << currentDateTime() << endl;
	    break;
	  case 5:
          numfile << "Mexico City  Lottery Tickets     Date " << currentDateTime() << endl;
            break;
         }

       numfile << "=================================================================="<< endl;  

       doHeadingInfo();

       srand(time(NULL));

       for (i=0; i < numberOfLines; i++)
       {
	    PickNumber();
	    
	    if(play == 1) 
	    {
               PickStar();

 	       cout << setw(10) << i << ")\t" <<
		     nBallPick[0] << "\t" <<
		     nBallPick[1] << "\t" <<
		     nBallPick[2] << "\t" <<
		     nBallPick[3] << "\t" <<
		     nBallPick[4] << "\t" <<
		     nBallStar[0] << "\t" <<
		     nBallStar[1] << endl; 

	    numfile << setw(10) << i << ")\t" <<
                     nBallPick[0] << "\t" <<
		     nBallPick[1] << "\t" <<
		     nBallPick[2] << "\t" <<
		     nBallPick[3] << "\t" <<
		     nBallPick[4] << "\t" <<
		     nBallStar[0] << "\t" <<
		     nBallStar[1] << endl; 
	    }
	     else {
	        cout << setw(10) << i << ")\t" <<
		     nBallPick[0] << "\t" <<
		     nBallPick[1] << "\t" <<
		     nBallPick[2] << "\t" <<
		     nBallPick[3] << "\t" <<
		     nBallPick[4] << "\t" <<
		     nBallPick[5] << endl;
	     numfile << setw(10) << i << ")\t" <<
		     nBallPick[0] << "\t" <<
		     nBallPick[1] << "\t" <<
		     nBallPick[2] << "\t" <<
		     nBallPick[3] << "\t" <<
		     nBallPick[4] << "\t" <<
		     nBallPick[5] << endl;
            }
     }

     numfile << "===================================================================="<< endl;
     numfile.close();
	    
    str.append("Enter q/Q to quit to main menu");
    doDisplayMsg(str, 0);

    while(true) {
        getline(cin, str);

        if(str.length() == 1)
            ch[0] = str[0]; 

        if((ch[0] == 'q') || (ch[0] == 'Q'))
            break;
      }
   }
   catch(exception& e)
  {
	cout << e.what() << endl;
  } 
}

void CLottery::doHeadingInfo()
{
   string  str = "";

  if(play == 1) {
    str.append("Euro Million Lottery Tickets Number                  Star Numbers");   

   doDisplayMsg(str, 0);
cout << "-----------------------------------------------------------------" << endl;
cout << " No Of Columns  1       2       3       4       5       1       2" << endl;
cout << "=================================================================" << endl;
 } 
 else {
    str.append("Lottery Tickets Number                                    "); 

    doDisplayMsg(str, 0);
cout << "-----------------------------------------------------------------" << endl;
cout << " No Of Columns  1       2       3       4       5       6        " << endl;
cout << "=================================================================" << endl;
  }
}

void doDisplayChoice(int d, int m, int y, int lk, int num)
{
	   string str = "";

           str.append("Entered Values Day: ");
           doDisplayMsg(str, d);  
           str.clear();
           str.append("Month ............: "); 
           doDisplayMsg(str, m);
           str.clear();
           str.append("Year .............: ");
           doDisplayMsg(str,  y);
           str.clear();
           str.append("Lucky Num ........: ");
           doDisplayMsg(str, lk);
           str.clear();
           str.append("Total Tickets :.. : ");
           doDisplayMsg(str, num);  
	  
}
void doLoadData(int d, int m, int y, int lk, int type, int num)
{
	CLottery * pLotto = new CLottery(d, m, y, lk, type, num);
	
        pLotto->SetNumber(); // will set the number picks
	pLotto->LoadNumber();
}	
void doLottery(int ltype)
{
	int rval, num;
	string str = "";   
	short day, mon, year, lucky;      
	day = mon = year = lucky = 0;
                
	num = GetNumberOfLinesTicket();
	
        if(num >= 1)
        {  
	   if(ltype == 1) 
	        str.append("You chose EUROMILLION LOTTERY. Number of Tickets: ");

	   else if(ltype == 2) 
		str.append("You chose UK LOTTERY. Number of Tickets: ");

	   else if(ltype == 3) 
		str.append("You chose UK THUNDER BALL. Number of Tickets: "); 

	   else if(ltype == 4) 
		str.append("You chose US LOTTERY. Number of Tickets: ");
	
	   else if(ltype == 5) 
		str.append("You chose MEXICO LOTTERY. Number of Tickets: ");
	    else
		str = "";

           doDisplayMsg(str, num);

            rval = OptionQuestion();

	   if((rval >= 1))
            {
	       CBirthday * pDay = new CBirthday;
	       CLuckyNum * pLucky = new CLuckyNum;

	      switch(rval)
	       {
		case 1:
                     {
		        day = pDay->Bday(); // Get date
                        mon = pDay->Mon(); 
			year = pDay->Year();
		        break; 
                     }
		case 2: {
			 lucky = pLucky->Luckynum();
			 break; 
			}
		case 3: {
			 day = pDay->Bday(); 
			 mon = pDay->Mon();
			 year = pDay->Year(); 
			 lucky = pLucky->Luckynum();
			 break;
			}
		default:
			break;
	        }
 	        delete pDay;
	        delete pLucky;                  
           }  
	  doDisplayChoice(day, mon, year, lucky, num);
	  
	  doLoadData(day, mon, year, lucky, ltype, num);
     }
     else {
           str.clear();
           str.append("But not selected number of tickets!");
           doDisplayMsg(str, 0);
           my_sleep(5);
         } 
}

 
/*******************************************************************
 *  EuroMillion and UK Lottery Number generator program
 *
 *  @ik    11/04/2014
 *
 * Program main rutine start.
 *******************************************************************/
int main ()
{
   int choice;

   do {		
        choice = showChoices();
		
	switch(choice)
	{
		case 1:
			doLottery(choice);
			break; 
		case 2:
			doLottery(choice);
			break;
		case 3:
			doLottery(choice);
			break;
		case 4:
			doLottery(choice);
			break;
		case 5:	
			doLottery(choice);	       
                        break;

		case 0:{cout << "Exiting  " << choice << endl; } break;

		default:
			cout << "Invalid input or choice" << endl;
	}
      } while (choice != 0);

   return 0;
}  
