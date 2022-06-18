/*************************************************************************/
/*************************************************************************/
/********************	 Author:   Ali ElShimy     ***********************/
/********************	 Layer:    MCAL		   	   ***********************/
/********************	 SWC:	   DIO 		   	   ***********************/
/********************	 Version:  1.0			   ***********************/
/********************	 MCU:	   ATMEGA32        ***********************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

#ifndef DIO_INTERFACE.H
#define DIO_INTERFACE.H

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
		if(Copy_u8Direction == 1) {
			SET_BIT(Copy_u8Port, Copy_u8Pin);
		}else if(Copy_u8Direction == 0) {
			CLEAR_BIT(Copy_u8Port, Copy_u8Pin);
		}else {
			return -1; 				//If the direction was neither One nor Zero, return -1.
		}
									//Return 0 if the direction is set Correctly.
		return 0;
	}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
		if(Copy_u8Direction == 1) {
			Copy_u8Port = 0xFF;
		}else if(Copy_u8Direction == 0) {
			Copy_u8Port = 0x00;
		}else {
			return -1;				//If the direction was neither One nor Zero, return -1.
		}
		return 0;					//Return 0 if the direction is set Correctly.
	}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8_Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8_Copyu8Pin, u8* Copy_pu8Value);


#endif