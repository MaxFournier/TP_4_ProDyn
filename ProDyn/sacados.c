/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "sacados.h"

/**
 * 
 * @param poids
 *      array des poids des oblets
 * @param valeur
 *      array des valeurs des objet
 * @param size
 *      taille des array valeur et poids
 * @param poidsMax
 *      poids maximum du sac
 * 
 * @return 
 *      valeur maximum portée par le sac
 */
int sacADos (int poids[], int valeur[],int size ,int poidsMax)
{
    //variable tri
    int i, j, RatioMax;
    float stock;
    
    //variable sac
    int poidsPorte =0;
    int valeurTotale =0;
    
    //algorithme tri par selection pour avoir le plus grand ratio position 0 et le plus petit position size-1
    for (i = 0; i < size - 1; i++) {
        //on commence le tri au rang i
        RatioMax = i;

        for (j = i; j < size; j++) {
            //le rang du plus grand ratio est stocké
            if (valeur[RatioMax]/poids[RatioMax] < valeur[j]/poids[j]) {
                RatioMax = j;
            }
        }

        //invertion des valeurs, le plus grand ratio prend la position i
        stock = poids[RatioMax];
        poids[RatioMax] = poids[i];
        poids[i] = stock;
        
        stock = valeur[RatioMax];
        valeur[RatioMax] = valeur[i];
        valeur[i] = stock;
    }
    
    //on ajoute en priorité les valeurs avec la meilleur ration valeur/poids sans depasser le poids max
    for (int i =0 ; i<size;i++)
    {
        if (poids[i]+poidsPorte <= poidsMax)
        {
            poidsPorte += poids[i];
            valeurTotale += valeur[i]; 
        }
    }
    
    return valeurTotale;
    
    

}