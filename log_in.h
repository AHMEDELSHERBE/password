#include "../lib/std_types.h"
#ifndef LOG_IN_H_
#define LOG_IN_H_

#define PASSWORD "1234"
#define F_CPU 1000000UL

void Login_voidInit(void);
void Login_voidWelcome(void);
void Login_voidEnterPassword(void);
void Login_voidCheckPassword(void);
u8 Login_u8GetCompareFlag(void);

#endif /* LOG_IN_H_ */
