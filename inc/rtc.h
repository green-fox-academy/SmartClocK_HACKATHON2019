#ifndef RTC_H
#define RTC_H

#include "main.h"

#define RTC_ADDRESS_WRITE_MODE 0xD0
#define RTC_ADDRESS_READ_MODE 0xD1
#define SECONDS_REGISTER 0x00
#define MINUTES_REGISTER 0x01
#define HOURS_REGISTER 0x02
#define DAY_REGISTER 0x03
#define DATE_REGISTER 0x04
#define MONTH_REGISTER 0x05
#define YEAR_REGISTER 0x06
#define CONTROLS_REGISTER 0x07

#define CH 7

typedef struct {

	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
	uint8_t year;


} times_t;

typedef struct {

	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
	uint8_t year;

} time_setting_t;

void rtc_init(void);
void set_time(time_setting_t *time_struct);
void get_time(times_t *time_struct);
void create_time_string(times_t *time_struct, char* time);
void create_date_string(times_t *time_struct, char* date);

#endif /* RTC_H */
