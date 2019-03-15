/**
* 5 semestre - Eng. da Computação - Insper
* 
* Jose Fernando de Melo Cruz
* 
* Vídeo : https://www.youtube.com/watch?v=694ZhQSOKs0
* 
*  
* 
*  
*
* Material :
*  - Kit: ATMEL SAME70-XPLD - ARM CORTEX M7
*/

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/


#define BUZZER_PIO           PIOB
#define BUZZER_PIO_ID        11
#define BUZZER_PIO_IDX       0u
#define BUZZER_PIO_IDX_MASK  (1u << BUZZER_PIO_IDX)

// MUSICA NUMERO 1 : SUPER MARIO TEMA.
#define BUT_PIO           PIOA
#define BUT_PIO_ID        10
#define BUT_PIO_IDX       11u
#define BUT_PIO_IDX_MASK  (1u << BUT_PIO_IDX)

// LED
#define LED_PIO           PIOC                  // periferico que controla o LED
#define LED_PIO_ID        12                    // ID do periférico PIOC (controla LED)
#define LED_PIO_IDX       8u                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1u << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED

// MUSICA NUMERO 2 : HINO NACIONAL BRASILEIRO
#define BUT_PIO2           PIOA
#define BUT_PIO2_ID        10
#define BUT_PIO2_IDX       3u
#define BUT_PIO2_IDX_MASK  (1u << BUT_PIO2_IDX)

// BOTÃO DE PARAR
#define BUT_PIO3           PIOA
#define BUT_PIO3_ID        10
#define BUT_PIO3_IDX       4u
#define BUT_PIO3_IDX_MASK  (1u << BUT_PIO3_IDX)

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

int melody[] = {

NOTE_C4, NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4, NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_FS4,NOTE_G4,0,0,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,
NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4, NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_B4,NOTE_AS4, NOTE_GS4,NOTE_A4,0,NOTE_A4,NOTE_A4, NOTE_AS4,NOTE_A4,0,NOTE_A4,NOTE_AS4,NOTE_A4, NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4, NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,
NOTE_E4,NOTE_D4,0,NOTE_G4,NOTE_G4, NOTE_A4,NOTE_G4,0,NOTE_G4,NOTE_A4,NOTE_G4, NOTE_G4,NOTE_C5,NOTE_B4,NOTE_A4, NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4, NOTE_D4,NOTE_C4,0,NOTE_C4,NOTE_E4,NOTE_G4, NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,
NOTE_AS4,NOTE_AS4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4, NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_FS4,NOTE_G4,0,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,
NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_C5,NOTE_AS4, NOTE_GS4,NOTE_A4,0,0,NOTE_F4, NOTE_G4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_F4, NOTE_F4,NOTE_AS4,NOTE_AS4,0,NOTE_G4, NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_G4,
NOTE_G4,NOTE_C5,NOTE_C5,0,NOTE_A4, NOTE_AS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_A4, NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_G4, NOTE_G4,NOTE_F4,0,NOTE_E4,NOTE_F4,NOTE_G4, NOTE_AS4,NOTE_A4,NOTE_E4,NOTE_F4,NOTE_CS4,NOTE_D4,NOTE_AS4,NOTE_G4, NOTE_G4,NOTE_F4,0,NOTE_G4,NOTE_A4,NOTE_AS4,

NOTE_B4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_D4,NOTE_AS4, NOTE_A4,NOTE_F4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,
NOTE_F4

};

int melody2[] = {
	NOTE_E7, NOTE_E7, 0, NOTE_E7,
	0, NOTE_C7, NOTE_E7, 0,
	NOTE_G7, 0, 0,  0,
	NOTE_G6, 0, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0
};

int noteDurations[] = {
	4,
	6,16,6,16,6,16,6,16,
	3,8,4,4,
	6,16,6,16,6,16,6,16,
	4,4,4,16,8,
	6,16,6,16,6,16,6,16,

	3,8,4,4,
	6,16,6,16,6,16,6,16,
	4,4,4,6,16,
	4,4,8,8,6,16,
	4,2,8,8,
	8,8,8,8,8,8,8,8,

	4,4,4,6,16,
	4,4,8,8,6,16,
	4,2,8,8,
	8,8,8,8,8,8,8,8,
	4,4,8,8,8,8,
	8,8,8,8,8,8,8,8,

	2,4,4,
	6,16,6,16,6,16,6,16,
	3,8,4,4,
	6,16,6,16,6,16,6,16,
	4,4,4,4,
	6,16,6,16,6,16,6,16,

	3,8,4,4,
	6,16,6,16,6,16,6,16,
	4,4,4,8,16,
	6,16,6,16,6,16,6,16,
	3,8,4,8,8,
	6,16,6,16,6,16,6,16,

	3,8,4,8,8,
	6,16,6,16,6,16,6,16,
	4,3,8,8,8,
	4,4,8,8,8,8,
	8,8,8,8,8,8,8,8,
	4,4,8,8,8,8,

	8,8,8,8,4,4,
	4,6,16,4,6,16,
	2

};

int noteDurations2[] = {
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	9, 9, 9,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	9, 9, 9,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
};

/************************************************************************/
/* constants                                                            */
/************************************************************************/

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

void init(void);

/************************************************************************/
/* interrupcoes                                                         */
/************************************************************************/

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

void buzz(long frequency, long length) {
	frequency = frequency*2;
	pio_clear(PIOC, LED_PIO_IDX_MASK);
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
	long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
	long numCycles = frequency * length / 600;
	if(frequency ==0){
		pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
		delay_us(length);
	}
	else{
		for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
			pio_clear(PIOC, LED_PIO_IDX_MASK);
			pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			delay_us(delayValue); // wait for the calculated delay value
			pio_set(PIOC, LED_PIO_IDX_MASK);
			pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			delay_us(delayValue);
		}
	}
	pio_set(PIOC, LED_PIO_IDX_MASK);
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

// Função de inicialização do uC


void init(void)
{
	sysclk_init();
	
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pmc_enable_periph_clk(LED_PIO_ID);
	pmc_enable_periph_clk(BUT_PIO_ID);
	pmc_enable_periph_clk(BUT_PIO2_ID);
	pmc_enable_periph_clk(BUT_PIO3_ID);
	
	
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED_PIO, LED_PIO_IDX_MASK, 0, 0, 0);
	pio_set_input(BUT_PIO, BUT_PIO_IDX_MASK, PIO_DEFAULT);
	pio_pull_up(BUT_PIO, BUT_PIO_IDX_MASK, 1);
	pio_set_input(BUT_PIO2, BUT_PIO2_IDX_MASK, PIO_DEFAULT);
	pio_pull_up(BUT_PIO2, BUT_PIO2_IDX_MASK, 1);
	pio_set_input(BUT_PIO3, BUT_PIO3_IDX_MASK, PIO_DEFAULT);
	pio_pull_up(BUT_PIO3, BUT_PIO3_IDX_MASK, 1);
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
	init();

	// super loop
	// aplicacoes embarcadas não devem sair do while(1).
	while (1){
		if(!pio_get(BUT_PIO, PIO_INPUT, BUT_PIO_IDX_MASK)){
			while(!pio_get(BUT_PIO, PIO_INPUT, BUT_PIO_IDX_MASK)){
				delay_ms(100);
			}
			for (int thisNote = 0; thisNote < 79; thisNote++) {
				if (!pio_get(BUT_PIO3, PIO_INPUT, BUT_PIO3_IDX_MASK)){
					while(!pio_get(BUT_PIO3, PIO_INPUT, BUT_PIO3_IDX_MASK)){
						delay_ms(100);
					}
					break;
				}
				else{
					int noteDuration = 1000/noteDurations2[thisNote];
					int pauseBetweenNotes = noteDuration * 1.30;
					buzz(melody2[thisNote]*4, noteDuration);
					delay_us(noteDuration);
					buzz(melody2[thisNote], noteDuration);
					delay_us(pauseBetweenNotes);
				}
					
			}
			pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			pio_clear(PIOC, LED_PIO_IDX_MASK);
		}
		if (!pio_get(BUT_PIO2, PIO_INPUT, BUT_PIO2_IDX_MASK)){
			while(!pio_get(BUT_PIO2, PIO_INPUT, BUT_PIO2_IDX_MASK)){
				delay_ms(100);
			}
			for (int thisNote = 0; thisNote < 200; thisNote++) {
				if (!pio_get(BUT_PIO3, PIO_INPUT, BUT_PIO3_IDX_MASK)){
					while(!pio_get(BUT_PIO3, PIO_INPUT, BUT_PIO3_IDX_MASK)){
						delay_ms(100);
					}
					break;
				}
				else{
					int noteDuration = 1000/noteDurations[thisNote];
					int pauseBetweenNotes = noteDuration * 1.30;
					buzz(melody[thisNote]*4, noteDuration);
					delay_us(noteDuration);
					buzz(melody[thisNote], noteDuration);
					delay_us(pauseBetweenNotes);
				}	
			}
			pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
			pio_clear(PIOC, LED_PIO_IDX_MASK);
		}
	}
	return 0;
}
