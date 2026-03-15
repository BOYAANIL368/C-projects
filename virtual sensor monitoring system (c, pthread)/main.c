#include"sensor.h"
pthread_mutex_t m1,m2;
#include"sensor_manage.c"
#include"Event_queue.c"
#include"monitor.c"
#include"alert_system.c"
void main()
{

	pthread_t t1,t2;

	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);

	pthread_mutex_lock(&m2);

	if(pthread_create(&t1,NULL,thread_to_generate_values,NULL)!=0)
	{
		printf("Thread creation failed\n");
	}
	if(pthread_create(&t2,NULL,thread_to_alert_system,NULL)!=0)
	{
		printf("Thread creation failed\n");
	}
	int op;
	while(1)
	{
		printf("\033[32m ******* Back ground Applications *******\033[m\n");
		printf("1 Generating Sensor values\n");
		printf("2 logs sensor data\n");
	        printf("3 Event Queue generating\n");
		printf("4 Alart System\n\n");

		printf("\033[33m *******Main Menu*******\033[m\n");
		printf("1. Sensor Registration System\n");
		printf("2. Event Queue\n");
		printf("3. Exit\n");
		printf("Enter your option: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				sensor_regi_manag();
				break;
			case 2:
				Event_queue();
				break;
			case 3:
				exit(0);
				break;
			defualt:printf("unknow option\n");
		}
	}
}
