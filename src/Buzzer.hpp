/*
 * Buzzer.hpp
 *
 *  Created on: 12 mar 2018
 *      Author: darek
 */

#ifndef BUZZER_HPP_
#define BUZZER_HPP_
#include "../../@RPi_Tools@/wiringPi/wiringPi.h"
#include "../../@RPi_Tools@/wiringPi/softTone.h"
#include <iostream>

class Buzzer {
public:
	enum Frequency {
		C_1		=	32,
		Ci_1	=	34,
		D_1		=	36,
		Di_1	=	38,
		E_1		=	41,
		F_1		=	43,
		Fi_1	=	46,
		G_1		=	48,
		Gi_1	=	51,
		A_1		=	54,
		Ai_1	=	58,
		H_1		=	61,
		C		=	65,
		Ci		=	69,
		D		=	73,
		Di		=	77,
		E		=	82,
		F		=	87,
		Fi		=	92,
		G		=	97,
		Gi		=	103,
		A		=	110,
		Ai		=	116,
		H		=	123,
		c		=	130,
		ci		=	138,
		d		=	146,
		di		=	155,
		e		=	164,
		f		=	174,
		fi		=	184,
		g		=	195,
		gi		=	207,
		a		=	220,
		ai		=	233,
		h		=	246,
		c1		=	261,
		ci1		=	277,
		d1		=	293,
		di1		=	311,
		e1		=	329,
		f1		=	349,
		fi1		=	369,
		g1		=	391,
		gi1		=	415,
		a1		=	440,
		ai1		=	466,
		h1		=	493,
		c2		=	523,
		ci2		=	554,
		d2		=	587,
		di2		=	622,
		e2		=	659,
		f2		=	698,
		fi2		=	739,
		g2		=	783,
		gi2		=	830,
		a2		=	880,
		ai2		=	932,
		h2		=	987,
		c3		=	1046,
		ci3		=	1108,
		d3		=	1174,
		di3		=	1244,
		e3		=	1318,
		f3		=	1396,
		fi3		=	1479,
		g3		=	1567,
		gi3		=	1661,
		a3		=	1760,
		ai3		=	1864,
		h3		=	1975,
		c4		=	2093,
		ci4		=	2217,
		d4		=	2349,
		di4		=	2489,
		e4		=	2637,
		f4		=	2793,
		fi4		=	2959,
		g4		=	3135,
		gi4		=	3322,
		a4		=	3520,
		ai4		=	3729,
		h4		=	3951,
		c5		=	4186,
	};
	Buzzer();
	virtual ~Buzzer();
};

#endif /* BUZZER_HPP_ */
