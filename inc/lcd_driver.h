#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include "main.h"


#define LCD_ADDRESS 0x4E



void lcd_init (void);

void lcd_send_cmd (char cmd);

void lcd_send_data (char data);

void lcd_send_string (char *str);

void send_string(char *str);

void new_line(void);

void clear_display(void);


#endif /* LCD_DRIVER_H */
