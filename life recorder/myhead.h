#ifndef _MYHEAD_H
#define _MYHEAD_H

#include <stdio.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <unistd.h>

#include <strings.h>

#include <stdlib.h>

#include <fcntl.h>

#include <time.h>



#define RED                  "\e[0;31m"
#define CLEAR                "\e[2J"
#define NONE                 "\e[0m"

void input();

void display();

void heart();

void menu();

void time1();

int time_study();

int time_rest();

void delete1();

float consume();

void appraisal1();


#endif
