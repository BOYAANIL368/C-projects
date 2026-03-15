#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

typedef struct sensor_info
{
	int id;
	char name[20];
	int value;
	char par[20];

	int alert_active;
	struct sensor_info *next;
}Sensor;

Sensor *Head=NULL;
void Sensor_regi_manag(void);
void add_Sensor(void);
void Display_Sensor(void);
void Remove_Sensor(void);
void Search_Sensor(void);

/* event structure */
struct event
{
    int sensor_id;
    char msg[50];
    struct event *next;
};

