#include "main.h"


void rtc_init(void) {

	uint8_t settings;

	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_WRITE_MODE, SECONDS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &settings, 1, 100);
	settings &= (~(1 << CH));
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, SECONDS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &settings, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_WRITE_MODE, HOURS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &settings, 1, 100);
	settings |= (0b01000000);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, HOURS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &settings, 1, 100);

}

void rtc_set(time_setting_t *time_struct) {

	uint8_t sec, min, hour, weekday, date, month, year;

	sec = ((time_struct->seconds / 10) << 4) | (time_struct->seconds % 10);
	min = ((time_struct->minutes / 10) << 4) | (time_struct->minutes % 10);
	hour = ((time_struct->hours / 10) << 4) | (time_struct->hours % 10);
	weekday = ((time_struct->weekday / 10) << 4) | (time_struct->weekday % 10);
	date = ((time_struct->date / 10) << 4) | (time_struct->date % 10);
	month = ((time_struct->month / 10) << 4) | (time_struct->month % 10);
	year = ((time_struct->year / 10) << 4) | (time_struct->year % 10);

	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, SECONDS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &sec, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, MINUTES_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &min, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, HOURS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &hour, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, DAY_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &weekday, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, DATE_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &date, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, MONTH_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &month, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDRESS_WRITE_MODE, YEAR_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &year, 1, 100);

}

void rtc_get(times_t *time_struct) {

	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, SECONDS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->seconds, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, MINUTES_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->minutes, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, HOURS_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->hours, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, DAY_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->weekday, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, DATE_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->date, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, MONTH_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->month, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDRESS_READ_MODE, YEAR_REGISTER,
	I2C_ADDRESSINGMODE_7BIT, &time_struct->year, 1, 100);

}

void create_time_string(times_t *time_struct, char* time) {

	time[8] = '\0';
	time[7] = 48 + (time_struct->seconds & 0b00001111);
	time[6] = 48 + ((time_struct->seconds & 0b01110000) >> 4);
	time[5] = ':';
	time[4] = 48 + (time_struct->minutes & 0b00001111);
	time[3] = 48 + ((time_struct->minutes & 0b01110000) >> 4);
	time[2] = ':';
	time[1] = 48 + (time_struct->hours & 0b00001111);
	time[0] = 48 + ((time_struct->hours & 0b00110000) >> 4);

}

void create_date_string(times_t *time_struct, char* date) {

	date[10] = '\0';
	date[9] = 48 + (time_struct->date & 0b00000111);
	date[8] = 48 + ((time_struct->date & 0b00110000) >> 4);
	date[7] = '-';
	date[6] = 48 + (time_struct->month & 0b00001111);
	date[5] = 48 + ((time_struct->month & 0b00010000) >> 4);
	date[4] = '-';
	date[3] = 48 + (time_struct->year & 0b00001111);
	date[2] = 48 + ((time_struct->year & 0b11110000) >> 4);
	date[1] = '0';
	date[0] = '2';

}
