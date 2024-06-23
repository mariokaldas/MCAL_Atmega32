/* AVR ATmega32 mapped registers by bit-field
 * AVRIO.h
 *
 *  Created on: Oct 7, 2023
 *      Author: mario kaldas
 */

#ifndef AVRIO_H_
#define AVRIO_H_

#include "../MCAL_Atmega32/std_types.h"

/**************************************************************************
 *                         Risters type declaration
 * ***********************************************************************/

typedef union{

	uint8 Byte;
	struct {
		uint8 PORTA0_bit:1;
		uint8 PORTA1_bit:1;
		uint8 PORTA2_bit:1;
		uint8 PORTA3_bit:1;
		uint8 PORTA4_bit:1;
		uint8 PORTA5_bit:1;
		uint8 PORTA6_bit:1;
		uint8 PORTA7_bit:1;
	}bit;
}PORTA_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 DDRA0_bit:1;
		uint8 DDRA1_bit:1;
		uint8 DDRA2_bit:1;
		uint8 DDRA3_bit:1;
		uint8 DDRA4_bit:1;
		uint8 DDRA5_bit:1;
		uint8 DDRA6_bit:1;
		uint8 DDRA7_bit:1;
	}bit;
}DDRA_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PINA0_bit:1;
		uint8 PINA1_bit:1;
		uint8 PINA2_bit:1;
		uint8 PINA3_bit:1;
		uint8 PINA4_bit:1;
		uint8 PINA5_bit:1;
		uint8 PINA6_bit:1;
		uint8 PINA7_bit:1;
	}bit;
}PINA_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 PORTB0_bit:1;
		uint8 PORTB1_bit:1;
		uint8 PORTB2_bit:1;
		uint8 PORTB3_bit:1;
		uint8 PORTB4_bit:1;
		uint8 PORTB5_bit:1;
		uint8 PORTB6_bit:1;
		uint8 PORTB7_bit:1;
	}bit;
}PORTB_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 DDRB0_bit:1;
		uint8 DDRB1_bit:1;
		uint8 DDRB2_bit:1;
		uint8 DDRB3_bit:1;
		uint8 DDRB4_bit:1;
		uint8 DDRB5_bit:1;
		uint8 DDRB6_bit:1;
		uint8 DDRB7_bit:1;
	}bit;
}DDRB_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PINB0_bit:1;
		uint8 PINB1_bit:1;
		uint8 PINB2_bit:1;
		uint8 PINB3_bit:1;
		uint8 PINB4_bit:1;
		uint8 PINB5_bit:1;
		uint8 PINB6_bit:1;
		uint8 PINB7_bit:1;
	}bit;
}PINB_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 PORTC0_bit:1;
		uint8 PORTC1_bit:1;
		uint8 PORTC2_bit:1;
		uint8 PORTC3_bit:1;
		uint8 PORTC4_bit:1;
		uint8 PORTC5_bit:1;
		uint8 PORTC6_bit:1;
		uint8 PORTC7_bit:1;
	}bit;
}PORTC_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 DDRC0_bit:1;
		uint8 DDRC1_bit:1;
		uint8 DDRC2_bit:1;
		uint8 DDRC3_bit:1;
		uint8 DDRC4_bit:1;
		uint8 DDRC5_bit:1;
		uint8 DDRC6_bit:1;
		uint8 DDRC7_bit:1;
	}bit;
}DDRC_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PINC0_bit:1;
		uint8 PINC1_bit:1;
		uint8 PINC2_bit:1;
		uint8 PINC3_bit:1;
		uint8 PINC4_bit:1;
		uint8 PINC5_bit:1;
		uint8 PINC6_bit:1;
		uint8 PINC7_bit:1;
	}bit;
}PINC_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 PORTD0_bit:1;
		uint8 PORTD1_bit:1;
		uint8 PORTD2_bit:1;
		uint8 PORTD3_bit:1;
		uint8 PORTD4_bit:1;
		uint8 PORTD5_bit:1;
		uint8 PORTD6_bit:1;
		uint8 PORTD7_bit:1;
	}bit;
}PORTD_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 DDRD0_bit:1;
		uint8 DDRD1_bit:1;
		uint8 DDRD2_bit:1;
		uint8 DDRD3_bit:1;
		uint8 DDRD4_bit:1;
		uint8 DDRD5_bit:1;
		uint8 DDRD6_bit:1;
		uint8 DDRD7_bit:1;
	}bit;
}DDRD_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PIND0_bit:1;
		uint8 PIND1_bit:1;
		uint8 PIND2_bit:1;
		uint8 PIND3_bit:1;
		uint8 PIND4_bit:1;
		uint8 PIND5_bit:1;
		uint8 PIND6_bit:1;
		uint8 PIND7_bit:1;
	}bit;
}PIND_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 C_bit:1;
		uint8 Z_bit:1;
		uint8 N_bit:1;
		uint8 V_bit:1;
		uint8 S_bit:1;
		uint8 H_bit:1;
		uint8 T_bit:1;
		uint8 I_bit:1;
	}bit;
}SREG_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 IVCE_bit:1;
		uint8 IVSEL_bit:1;
		uint8 :3;
		uint8 INT2_bit:1;
		uint8 INT0_bit:1;
		uint8 INT1_bit:1;

	}bit;
}GICR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 :5;
		uint8 INTF2_bit:1;
		uint8 INTF0_bit:1;
		uint8 INTF1_bit:1;
	}bit;
}GIFR_R;

typedef union{

	uint8 Byte;
	struct {
		uint8 ISC00_bit:1;
		uint8 ISC01_bit:1;
		uint8 ISC10_bit:1;
		uint8 ISC11_bit:1;
		uint8 SM0_bit:1;
		uint8 SM1_bit:1;
		uint8 SM2_bit:1;
		uint8 SE_bit:1;
	}bit;
}MCUCR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PORF_bit:1;
		uint8 EXTRF_bit:1;
		uint8 BORF_bit:1;
		uint8 WDRF_bit:1;
		uint8 JTRF_bit:1;
		uint8 :1;
		uint8 ISC2_bit:1;
		uint8 JTD_bit:1;
	}bit;
}MCUCSR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 CS00_bit:1;
		uint8 CS01_bit:1;
		uint8 CS02_bit:1;
		uint8 WGM01_bit:1;
		uint8 COM00_bit:1;
		uint8 COM01_bit:1;
		uint8 WGM00_bit:1;
		uint8 FOC0_bit:1;
	}bit;
}TCCR0_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 WGM10_bit:1;
		uint8 WGM11_bit:1;
		uint8 FOC1B_bit:1;
		uint8 FOC1A_bit:1;
		uint8 COM1B_bit:2;
		uint8 COM1A_bit:2;
	}bit;
}TCCR1A_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 CS1_bit:3;
		uint8 WGM12_bit:1;
		uint8 WGM13_bit:1;
		uint8 :1;
		uint8 ICES1_bit:1;
		uint8 ICNC1_bit:1;
	}bit;
}TCCR1B_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 CS20_bit:1;
		uint8 CS21_bit:1;
		uint8 CS22_bit:1;
		uint8 WGM21_bit:1;
		uint8 COM20_bit:1;
		uint8 COM21_bit:1;
		uint8 WGM20_bit:1;
		uint8 FOC2_bit:1;
	}bit;
}TCCR2_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TOIE0_bit:1;
		uint8 OCIE0_bit:1;
		uint8 TOIE1_bit:1;
		uint8 OCIE1B_bit:1;
		uint8 OCIE1A_bit:1;
		uint8 TICIE1_bit:1;
		uint8 TOIE2_bit:1;
		uint8 OCIE2_bit:1;
	}bit;
}TIMSK_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TOV0_bit:1;
		uint8 OCF0_bit:1;
		uint8 TOV1_bit:1;
		uint8 OCF1B_bit:1;
		uint8 OCF1A_bit:1;
		uint8 ICF1_bit:1;
		uint8 TOV2_bit:1;
		uint8 OCF2_bit:1;
	}bit;
}TIFR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 ADPS_bit:3;
		uint8 ADIE_bit:1;
		uint8 ADIF_bit:1;
		uint8 ADATE_bit:1;
		uint8 ADSC_bit:1;
		uint8 ADEN_bit:1;
	}bit;
}ADCSRA_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 MUX_bit:5;
		uint8 ADLAR_bit:1;
		uint8 REFS_bit:2;
	}bit;
}ADMUX_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TCR2UB_bit:1;
		uint8 OCR2UB_bit:1;
		uint8 TCN2UB_bit:1;
		uint8 AS2_bit:1;
		uint8 :4;
	}bit;
}ASSR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 WDP0_bit:1;
		uint8 WDP1_bit:1;
		uint8 WDP2_bit:1;
		uint8 WDE_bit:1;
		uint8 WDTOE_bit:1;
		uint8 :3;
	}bit;
}WDTCR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 MPCM_bit:1;
		uint8 U2X_bit:1;
		uint8 PE_bit:1;
		uint8 DOR_bit:1;
		uint8 FE_bit:1;
		uint8 UDRE_bit:1;
		uint8 TXC_bit:1;
		uint8 RXC_bit:1;
	}bit;
}UCSRA_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TXB8_bit:1;
		uint8 RXB8_bit:1;
		uint8 UCSZ2_bit:1;
		uint8 TXEN_bit:1;
		uint8 RXEN_bit:1;
		uint8 UDRIE_bit:1;
		uint8 TXCIE_bit:1;
		uint8 RXCIE_bit:1;
	}bit;
}UCSRB_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 UBRR_bit:4;
		uint8 :3;
		uint8 URSEL_bit:1;
	}bit;
}UBRRH_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 UCPOL_bit:1;
		uint8 UCSZ_bit:2;
		uint8 USBS_bit:1;
		uint8 UPM_bit:2;
		uint8 UMSEL_bit:1;
		uint8 URSEL_bit:1;
	}bit;
}UCSRC_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 SPI2X_bit:1;
		uint8 :5;
		uint8 WCOL_bit:1;
		uint8 SPIF_bit:1;
	}bit;
}SPSR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 SPR0_bit:1;
		uint8 SPR1_bit:1;
		uint8 CPHA_bit:1;
		uint8 CPOL_bit:1;
		uint8 MSTR_bit:1;
		uint8 DORD_bit:1;
		uint8 SPE_bit:1;
		uint8 SPIE_bit:1;
	}bit;
}SPCR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TWIE_bit:1;
		uint8 :1;
		uint8 TWEN_bit:1;
		uint8 TWWC_bit:1;
		uint8 TWSTO_bit:1;
		uint8 TWSTA_bit:1;
		uint8 TWEA_bit:1;
		uint8 TWINT_bit:1;
	}bit;
}TWCR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TWGCE_bit:1;
		uint8 TWA_bit:7;
	}bit;
}TWAR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 TWPS_bit:2;
		uint8 :1;
		uint8 TWS_bit:5;
	}bit;
}TWSR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 ACIS0_bit:1;
		uint8 ACIS1_bit:1;
		uint8 ACIC_bit:1;
		uint8 ACIE_bit:1;
		uint8 ACI_bit:1;
		uint8 ACO_bit:1;
		uint8 ACBG_bit:1;
		uint8 ACD_bit:1;
	}bit;
}ACSR_R;

typedef union{

	struct{
		uint8 EEAR8_bit:1;
		uint8 EEAR9_bit:1;
		uint8 :6;
	}bit;
}EEARH_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 EERE_bit:1;
		uint8 EEWE_bit:1;
		uint8 EEMWE_bit:1;
		uint8 EERIE_bit:1;
		uint8 :4;
	}bit;
}EECR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 PSR10_bit:1;
		uint8 PSR2_bit:1;
		uint8 PUD_bit:1;
		uint8 ACME_bit:1;
		uint8 :1;
		uint8 ADTS0_bit:1;
		uint8 ADTS1_bit:1;
		uint8 ADTS2_bit:1;
	}bit;
}SFIOR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 SPMEN_bit:1;
		uint8 PGERS_bit:1;
		uint8 PGWRT_bit:1;
		uint8 BLBSET_bit:1;
		uint8 RWWSRE_bit:1;
		uint8 :1;
		uint8 RWWSB_bit:1;
		uint8 SPMIE_bit:1;
	}bit;
}SPMCR_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 SP0_bit:1;
		uint8 SP1_bit:1;
		uint8 SP2_bit:1;
		uint8 SP3_bit:1;
		uint8 SP4_bit:1;
		uint8 SP5_bit:1;
		uint8 SP6_bit:1;
		uint8 SP7_bit:1;
	}bit;
}SPL_R;

typedef union{

	uint8 Byte;
	struct{
		uint8 SP8_bit:1;
		uint8 SP9_bit:1;
		uint8 SP10_bit:1;
		uint8 SP11_bit:1;
		uint8 :4;
	}bit;
}SPH_R;
/**************************************************************************
 *                            Risters definition
 * ************************************************************************/

#define PORTA_R (*(volatile PORTA_R* const)0x3B)
#define DDRA_R (*(volatile DDRA_R* const)0x3A)
#define PINA_R (*(volatile const PINA_R* const)0x39)

#define PORTB_R (*(volatile PORTB_R* const)0x38)
#define DDRB_R (*(volatile DDRB_R* const)0x37)
#define PINB_R (*(volatile const PINB_R* const)0x36)

#define PORTC_R (*(volatile PORTC_R* const)0x35)
#define DDRC_R (*(volatile DDRC_R* const)0x34)
#define PINC_R (*(volatile const PINC_R* const)0x33)

#define PORTD_R (*(volatile PORTD_R* const)0x32)
#define DDRD_R (*(volatile DDRD_R* const)0x31)
#define PIND_R (*(volatile const PIND_R* const)0x30)

#define SREG_R (*(volatile SREG_R* const)0x5F)
#define GICR_R (*(volatile GICR_R* const)0x5B)
#define GIFR_R (*(volatile GIFR_R* const)0x5A)

#define MCUCR_R (*(volatile MCUCR_R* const)0x55)
#define MCUCSR_R (*(volatile MCUCSR_R* const)0x54)
#define TCCR0_R (*(volatile TCCR0_R* const)0x53)
#define TCCR1A_R (*(volatile TCCR1A_R* const)0x4F)
#define TCCR1B_R (*(volatile TCCR1B_R* const)0x4E)
#define TCCR2_R (*(volatile TCCR2_R* const)0x45)
#define TCNT0_R (*(volatile uint8* const)0x52)
#define TCNT1_R (*(volatile uint16* const)0x4C)
#define TCNT2_R (*(volatile uint8* const)0x44)
#define OCR0_R (*(volatile uint8* const)0x5C)
#define OCR1A_R (*(volatile uint16* const)0x4A)
#define OCR1B_R (*(volatile uint16* const)0x48)
#define OCR2_R (*(volatile uint8* const)0x43)
#define TIMSK_R (*(volatile TIMSK_R* const)0x59)
#define TIFR_R (*(volatile TIFR_R* const)0x58)

#define ICR1_R (*(volatile uint16* const)0x46)
#define ADC_R (*(volatile const uint16* const)0x24)
#define ADCSRA_R (*(volatile ADCSRA_R* const)0x26)
#define ADMUX_R (*(volatile ADMUX_R* const)0x27)
#define ASSR_R (*(volatile ASSR_R* const)0x42)
#define ACSR_R (*(volatile ACSR_R* const)0x28)

#define WDTCR_R (*(volatile WDTCR_R* const)0x41)

#define UDR_R (*(volatile uint8* const)0x2C)
#define UCSRA_R (*(volatile UCSRA_R* const)0x2B)
#define UCSRB_R (*(volatile UCSRB_R* const)0x2A)
#define UBRRL_R (*(volatile uint8* const)0x29)
#define UBRRH_R (*(volatile UBRRH_R* const)0x40)
#define UCSRC_R (*(volatile UCSRC_R* const)0x40)

#define SPDR_R (*(volatile uint8* const)0x2F)
#define SPSR_R (*(volatile SPSR_R* const)0x2E)
#define SPCR_R (*(volatile SPCR_R* const)0x2D)

#define TWCR_R (*(volatile TWCR_R* const)0x56)
#define TWDR_R (*(volatile uint8* const)0x23)
#define TWAR_R (*(volatile TWAR_R* const)0x22)
#define TWSR_R (*(volatile TWSR_R* const)0x21)
#define TWBR_R (*(volatile uint8* const)0x20)

#define EEARL_R (*(volatile uint8* const)0x3E)
#define EEDR_R (*(volatile uint8* const)0x3D)
#define EEARH_R (*(volatile EEARH_R* const)0x3F)
#define EECR_R (*(volatile EECR_R* const)0x3C)

#define SFIOR_R (*(volatile SFIOR_R* const)0x50)

#define OSCCAL_R (*(volatile uint8* const)0x51)
#define OCDR_R (*(volatile uint8* const)0x51)

#define SPMCR_R (*(volatile SPMCR_R* const)0x57)

#define SPL_R (*(volatile SPL_R* const)0x5D)
#define SPH_R (*(volatile SPH_R* const)0x5E)

#endif /* AVRIO_H_ */
