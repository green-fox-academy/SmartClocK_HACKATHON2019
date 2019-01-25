#include "lcd_driver.h"

void lcd_send_cmd(char cmd) {

	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd & 0xf0);
	data_l = ((cmd << 4) & 0xf0);
	data_t[0] = data_u | 0x0C;
	data_t[1] = data_u | 0x08;
	data_t[2] = data_l | 0x0C;
	data_t[3] = data_l | 0x08;
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDRESS, (uint8_t *) data_t, 4, 100);

}

void lcd_send_data(char data) {

	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data & 0xf0);
	data_l = ((data << 4) & 0xf0);
	data_t[0] = data_u | 0x0D;
	data_t[1] = data_u | 0x09;
	data_t[2] = data_l | 0x0D;
	data_t[3] = data_l | 0x09;
	HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDRESS, (uint8_t *) data_t, 4, 100);

}

void lcd_init(void) {

	HAL_Delay(50);
	lcd_send_cmd(0x28);
	lcd_send_cmd(0x0C);
	lcd_send_cmd(0x01);
	lcd_send_cmd(0x80);

}

void send_string(char *str) {

	while (*str) lcd_send_data (*str++);

}

void new_line(void) {

	lcd_send_cmd(0xC0);

}

void clear_display(void) {

	lcd_send_cmd(0x01);
	lcd_send_cmd(0x80);

}
