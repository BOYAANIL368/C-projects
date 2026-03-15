void *thread_to_alert_system(void *p1)
{
	Sensor *p=Head;
	FILE *fp=fopen("alerts.log","a");
	if(fp==0)
	{
		perror("fopen");
	}

	while(1)
	{
		pthread_mutex_lock(&m2);
		p=Head;

		while(p)
		{
			if(p->alert_active)
			{
				if(strcmp(p->name,"temparature")==0)
					fprintf(fp,"sytem alert :High temparature\n");

				if(strcmp(p->name,"speed")==0)
					fprintf(fp,"sytem alert :over speed ditected\n");

				if(strcmp(p->name,"humidity")==0)
					fprintf(fp,"sytem alert :High humidity\n");
				
				if(strcmp(p->name,"gas")==0)
					fprintf(fp,"sytem alert :gas leak\n");

				if(strcmp(p->name,"vibration")==0)
					fprintf(fp,"sytem alert :Vibration ditected\n");
				
				if(strcmp(p->name,"pressure")==0)
					fprintf(fp,"sytem alert :Pressure Abnormal\n");

				if(strcmp(p->name,"motion")==0)
					fprintf(fp,"sytem alert :motion ditected\n");
			}

			p=p->next;
		}
		if(Head!=0)
		fprintf(fp,"-----------------------\n");
		sleep(5);
		pthread_mutex_unlock(&m1);
	}
}
