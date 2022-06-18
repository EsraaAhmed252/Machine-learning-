<<<<<<< HEAD
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Encoder_interface.h"
#include "Encoder_registers.h"

u8 SetInterrupt0(u8 Mode)
{
	SET_BIT(GICR, INT0);
	switch(Mode)
	{
	case LOW:	 CLR_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
	case CHANGE: SET_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
	case FALLING:CLR_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
	case RISING: SET_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
	default: return 1;
	}
}

u8 SetInterrupt1(u8 Mode)
{
	SET_BIT(GICR, INT1);
		switch(Mode)
		{
		case LOW:	 CLR_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
		case CHANGE: SET_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
		case FALLING:CLR_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
		case RISING: SET_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
		default: return 1;
		}
}
=======
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Encoder_interface.h"
#include "Encoder_registers.h"

u8 SetInterrupt0(u8 Mode)
{
	SET_BIT(GICR, INT0);
	switch(Mode)
	{
	case LOW:	 CLR_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
	case CHANGE: SET_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
	case FALLING:CLR_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
	case RISING: SET_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
	default: return 1;
	}
}

u8 SetInterrupt1(u8 Mode)
{
	SET_BIT(GICR, INT1);
		switch(Mode)
		{
		case LOW:	 CLR_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
		case CHANGE: SET_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
		case FALLING:CLR_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
		case RISING: SET_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
		default: return 1;
		}
}
>>>>>>> 2a6c3ef532beff1583f6ad6495069c817cbd86a5
