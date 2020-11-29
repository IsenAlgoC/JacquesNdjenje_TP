#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50


int initTab(int*, int);
int afficheTab(int*, int, int);
int* ajoutElementDansTableau(int*, int*, int*, int);