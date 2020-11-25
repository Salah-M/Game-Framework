#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include <QString>
#include "account.h"
/**
* \file globalvar.h
* \brief contains global variable defintions
*
*
* This file defines global variables used in the project
*/
extern QString textf;//!< string to store textfile path we are using for level choice
extern QString aud;//!< string to store audio file path we are using for level choice
extern int speedowagon;//!<speed for varrying speed for different levels
extern account *guest;//!< guest account across the whole project
extern bool turnmasta;//!< boolean to determine turn in game 2
#endif // GLOBALVAR_H
