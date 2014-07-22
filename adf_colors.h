/******************************************************************************
 * 
 * <COPYRIGHT_TAG>
 * 
 *****************************************************************************/

/******************************************************************************
 * @file adf_config.h
 *
 * @description
 * This is the header file for the ADF user/config executable.
 * This file also contains function prototypes for the user space
 * executable as well as struct and variable definitions.
 *****************************************************************************/

#ifndef ADF_COLORS_H
#define ADF_COLORS_H


/* make it pretty  */
#define lblack      "\033[0;30m"     /* Black  normal */
#define lblue       "\033[0;34m"     /* Blue          */
#define lgreen      "\033[0;32m"     /* Green         */
#define lcyan       "\033[0;36m"     /* Cyan          */
#define lred        "\033[0;31m"     /* Red           */
#define lpurple     "\033[0;35m"     /* Purple normal */
#define lbrown      "\033[0;33m"     /* Brown         */
#define lgray       "\033[0;37m"     /* Gray          */


#define red        "\033[1;31m"     /* 0 -> normal ;  31 -> red */
#define cyan       "\033[1;36m"     /* 1 -> bold ;    36 -> cyan */
#define green      "\033[1;32m"     /* 4 -> underline;32 -> green */
#define blue       "\033[1;34m"     /* 9 -> strike ;  34 -> blue */

#define black      "\033[1;30m"
#define brown      "\033[1;33m"
#define magenta    "\033[1;35m"
#define gray       "\033[1;37m"
#define white      "\033[1;37m"      /* White color on the Black */
#define yellow     "\033[1;33m"

#define cls        "\033[2J\033[1;1H"   /* Clear the screen */

#define none       "\033[0m"            /* to flush the previous property */


#define onpurple     "\033[45m"          /* Background colors */
#define onblack      "\033[40m"          /* Black background */
#define onred        "\033[41m"          /* on the Red */
#define ongreen      "\033[42m"          /* on green   */
#define onyellow     "\033[43m"          /* on yellow  */
#define onblue       "\033[44m"          /* on blue    */
#define oncyan       "\033[46m"          /* on cyan    */
#define onwhite      "\033[47m"          /* on white   */

#endif   /* end Of ADF_COLORS_H */

