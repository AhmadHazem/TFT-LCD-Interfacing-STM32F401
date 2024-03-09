#ifndef _SYSTICK_PRIVATE_H_
#define _SYSTICK_PRIVATE_H_

typedef struct
{
	union
	{
		uint32 R;
		struct
		{
			uint32 ENABLE:1;
			uint32 TICKINT:1;
			uint32 CLKSOURCE:1;
			uint32 RESERVED_1:13;
			uint32 COUNTFLAG:1;
			uint32 RESERVED_2:15;
		}B;
	}CTRL;	
	
	union
	{
		uint32 R;
		struct
		{
			uint32 RELOAD:24;
			uint32 RESERVED_3:8;
		}B;
	}LOAD;
	
	union
	{
		uint32 R;
		struct
		{
			uint32 CURRENT:24;
			uint32 RESERVED_3:8;
		}B;
	}VAL;
	
	union
	{
		uint32 R;
		struct
		{
			uint32 TENMS:24;
			uint32 RESERVED_3:6;
			uint32 SKEW:1;
			uint32 NOREF:1;
		}B;
	}CALIB;
}SYSTICK_type;

#define SYSTICK    ((volatile SYSTICK_type*)0xE000E010)

#define SYSTICK_AHB            1u
#define SYSTICK_AHB_DIV_8      2u

#define SYSTICK_NO_INIT        ((uint8)1u)
#define SYSTICK_INIT           ((uint8)2u)

#endif
