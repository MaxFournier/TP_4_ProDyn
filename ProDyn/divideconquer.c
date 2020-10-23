/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   divideconquer.c
 * Author: student
 *
 * Created on October 23, 2020, 4:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "divideconquer.h"

/*
 * 
 */

/**
* Recherche par dichotomie dans un tableau d'entiers
* @param array The array of values
* @param size_t The size of the array
* @param value The value to find
* @return The position of the value found or -1
*/
int find_by_dichotomy(int array[], int size_t, int value )
{
    int first =0; //premiere position de l'ecart ou peu se trouver la valeur
    int last = size_t ; //derniere position de l'ecart ou peu se trouver la valeur
    int espace = last - first; //espace entre first et last
    int moitie = (last-first)/2 +first; //position moirié tableau
    
    while (espace != 0 && array[moitie] != value)
    {
        moitie = (last-first)/2 +first; // moitie = position entre last et first
         
        //si on a la bonne position on la retourne
        if (array [moitie] == value)
        {
            return moitie;
        }
        else
        {   
            //si la valeur est plus grande que la position a la moitié first = moitie
            if (value > array[moitie])
            {
                first = moitie;
            }
            else //si la valeur est plus petite que la position a la moitié last = moitie
            {
                last = moitie;
            }
            
            //on change la valeur du nombre d'espace a verifier
            if (moitie == 1)
            {
                espace = last - first;
            }
            else
            {
                espace = last - first -1;
            }
            
            //s'il n'y a plus d'espace a verifier la valeur n'est pas dans le tableau
            if (espace == 0)
            {
                return -1;
            }            
        
        }
    
    }
    
    return moitie;

}
