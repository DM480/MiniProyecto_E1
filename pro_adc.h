
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_PRO_H
#define	ADC_PRO_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdint.h> // Esta libreria se incluye para poder crear funciones unit8_t

void CONF_ADC ();
uint8_t ADC(uint8_t x);

#endif	/* ADC_PRO_H */

