/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on October 23, 2020, 3:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "divideconquer.h"
#include "sacados.h"

/**
 * test divideconquer grace a la fonction assert
 * @see divideconquer.c
 */
void testDivConq ()
{
    int array[] = {4,5,6,8,10,25,64,70,71,150,151};
    int size_t = 11;
    int value = 151;
    
    assert (find_by_dichotomy(array,size_t, 7) == -1); //reussite
    assert (find_by_dichotomy(array,size_t,6) == 2); //reussite
    assert (find_by_dichotomy(array,size_t,151) == 10); //reussite
    assert (find_by_dichotomy(array,size_t,152) == -1); //reussite
    assert (find_by_dichotomy(array,size_t,4) == 0); //reussite   
    
}

/**
 * test sacados grace a assert
 * @see sacados.c
 */
void testSac ()
{
    int poids[] = {4,4,4,4,4};
    int valeur[] = {2,5,9,1,4};
    int size = 5;
    
    //SacADos (poids[], valeur[], size, poidsMax)
    assert (sacADos(poids,valeur,size,8) == 14); //test tri reussite
    
    assert (sacADos(poids,valeur,size,1) == 0); //test aucun element reussite
    
    assert (sacADos(poids,valeur,size,100) == 21); //trest tous elements reussite
    
    int poids2[] =  {1,2,3,4,5};
    
    assert (sacADos(poids2,valeur,size,14) == 19); //test condition reelle

}

/*
 * 
 */
int main(int argc, char** argv) {
    /**@see testDivConq */
    testDivConq();
    
    /**@see testSac*/
    testSac();
    
    return (EXIT_SUCCESS);
}

