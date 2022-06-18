<<<<<<< HEAD
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, pos)	(REG |= (1 << pos))
#define CLR_BIT(REG, pos) 	(REG &= (~(1 << pos)))
#define TOGGLE_BIT(REG,pos)	(REG ^= (1 << pos))
#define GET_BIT(REG, pos)	((REG >> pos) & 0x01)

#endif
=======
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, pos)	(REG |= (1 << pos))
#define CLR_BIT(REG, pos) 	(REG &= (~(1 << pos)))
#define TOGGLE_BIT(REG,pos)	(REG ^= (1 << pos))
#define GET_BIT(REG, pos)	((REG >> pos) & 0x01)

#endif
>>>>>>> 2a6c3ef532beff1583f6ad6495069c817cbd86a5
