/*
 * File:   ADC.c
 * Author: diegomazariegos
 *
 * Created on February 23, 2021, 12:02 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include "config.h"
#include "pro_adc.h"
#define  _XTAL_FREQ 8000000;

//******************************************************************************
//                              VARIABLES
//******************************************************************************

char adc = 0;

//******************************************************************************
//                     PROTOTIPOS DE FUNCIONES
//******************************************************************************

void setup(void);
void __interrupt () interrupcion(void);
float conv (uint8_t b);
void INTRR (void);

//******************************************************************************
//                           CONFIGURACION
//******************************************************************************

void setup(void){
    
    ANSEL  = 0;
    ANSELH = 0;
    
    TRISA = 0;
    PORTA = 0;
    
    CONF_ADC();
    
}

//******************************************************************************
//                             FUNCION INTRR
//******************************************************************************

void INTRR (void){
    
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
   
}

//******************************************************************************
//                           FUNCION DE INTERRUPCION
//******************************************************************************

void __interrupt () interrupcion(){
    
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
}


void main(void) {
    
    setup();
    
    INTRR();
    
    while(1){
        
        adc   = ADC(0);
        PORTA = adc;
        
    }
}
