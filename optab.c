/**********************************************************************/
/* lab 1 DVG C01 - Operator Table OBJECT                              */
/**********************************************************************/

/**********************************************************************/
/* Include files                                                      */
/**********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**********************************************************************/
/* Other OBJECT's METHODS (IMPORTED)                                  */
/**********************************************************************/
#include "keytoktab.h"

/**********************************************************************/
/* OBJECT ATTRIBUTES FOR THIS OBJECT (C MODULE)                       */
/**********************************************************************/
#define NENTS 4

static int optab[][NENTS] = {
   {'+', integer, integer, integer},
   {'+', real,    real,    real},
   {'+', integer, real,    real},
   {'+', real,    integer, real},
   {'*', integer, integer, integer},
   {'*', real,    real,    real},
   {'*', integer, real,    real},
   {'*', real,    integer, real},
   {'$', undef,   undef,   undef}
   };

/**********************************************************************/
/*  PRIVATE METHODS for this OBJECT  (using "static" in C)            */
/**********************************************************************/
static void p_optabLine(int index)
{
    printf("\n%10s %10s %10s %10s", tok2lex(optab[index][0]), tok2lex(optab[index][1]), tok2lex(optab[index][2]), tok2lex(optab[index][3]));
}

/**********************************************************************/
/*  PUBLIC METHODS for this OBJECT  (EXPORTED)                        */
/**********************************************************************/
/**********************************************************************/
/* display the op tab                                                 */
/**********************************************************************/
void p_optab()
{
    int i = 0;
    printf("\n____________________________________________________________");
    printf("\n  THE OPERATOR TABLE");
    printf("\n____________________________________________________________");
    printf("\n%10s %10s %10s %10s", "operator", "arg1", "arg2", "result");
    printf("\n____________________________________________________________");
    while(optab[i][0] != '$')
    {
        p_optabLine(i++);
    }
    printf("\n____________________________________________________________\n\n");
}

/**********************************************************************/
/* return the type of a binary expression op arg1 arg2                */
/**********************************************************************/
int get_otype(int op, int arg1, int arg2)
{  int i = 0;
   while(optab[i][0] != '$')
   {
       if(op == optab[i][0] && arg1 == optab[i][1] && arg2 == optab[i][2])
       {
           return optab[i][3];
       } 
       i++;
   }
    return optab[i][3];
}

/**********************************************************************/
/* End of code                                                        */
/**********************************************************************/