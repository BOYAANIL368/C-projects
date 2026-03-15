void Sensor_data_storage()
{
        FILE *fp=fopen("data_log","a");

        if(fp==0)
        {
                printf("file not present\n");
                return;
        }

        Sensor *p=Head;

        while(p)
        {
                fprintf(fp,"%d   %s  %d%s\n",p->id,p->name,p->value,p->par);

                p=p->next;
        }
	if(Head!=0)
	fprintf(fp,"-----------------------\n");

        fclose(fp);
}
void *thread_to_generate_values(void *p1)
{
        //if sensors are there then onlt it will generate
        srand(getpid());
        while(1)
        {
		pthread_mutex_lock(&m1);
                Sensor *p=Head;
                while(p)
                {
                        //printf(" rand fun");
                        if(strcmp(p->name,"temparature")==0)
                        {
                                p->value=rand()% 70 + 0;
                                strcpy(p->par,"C");
				if(p->value >40 && p->alert_active==0)
				{
					generate_event_automatic(p,"High Temparature");
					p->alert_active=1;
				}
				else if(p->value < 40)
				{
					p->alert_active=0;
				}
                        }
                        else if(strcmp(p->name,"pressure")==0)
                        {
                                p->value=rand()% 600 + 800;
                                strcpy(p->par,"hPa");

				if((p->value < 850 || p->value >1150) && p->alert_active==0)
				{
					generate_event_automatic(p,"Pressure Abnormal");
					p->alert_active=1;
				}
				else if(p->value > 850 && p->value < 1150)
				{
					p->alert_active=0;
				}
                        }
                        else if(strcmp(p->name,"humidity")==0)
                        {
                                p->value=rand()% 200 + 0;
                                strcpy(p->par,"%");
				
				if(p->value >80 && p->alert_active==0)
				{
					generate_event_automatic(p,"High Humidity");
					p->alert_active=1;
				}
				else if(p->value < 80)
				{
					p->alert_active=0;
				}
                        }
                        else if(strcmp(p->name,"speed")==0)
                        {
                                p->value=rand()% 200 + 0;
                                strcpy(p->par,"km/h");
				
				if(p->value > 120 && p->alert_active == 0)
				{
					generate_event_automatic(p,"Over speed");
					p->alert_active=1;
				}
				else if(p->value < 120)
				{
					p->alert_active=0;
				}
                        }
                        else if(strcmp(p->name,"gas")==0)
                        {
                                p->value=rand()% 1000 + 0;
                                strcpy(p->par,"ppm");
				
				if(p->value > 700 && p->alert_active==0)
				{
					generate_event_automatic(p,"Gas leak");
					p->alert_active=1;
				}
				else if(p->value < 700)
				{
					p->alert_active=0;
				}
                        }
                        else if(strcmp(p->name,"vibration")==0)
                        {
                                p->value=rand()% 11 + 0;
                                strcpy(p->par,"mm/s");
				
				if(p->value >7 && p->alert_active==0)
				{
					generate_event_automatic(p,"Vibration");
					p->alert_active=1;
				}
				else if(p->value <= 7)
				{
					p->alert_active=0;
				}

                        }
                        else if(strcmp(p->name,"motion")==0)
                        {
                                p->value=rand()% 2 + 0;
                                if(p->value && p->alert_active==0)
				{
                                      strcpy(p->par,"motion ditected");
				      generate_event_automatic(p,"motion ditected");
				      p->alert_active=1;
				}
                                else if(p->value==0)
				{
                                 strcpy(p->par,"no motion");
				 p->alert_active=0;
				}
                        }
                        p=p->next;
                }

                Sensor_data_storage();
                sleep(2);  //after every 5 seconds values are generated
		pthread_mutex_unlock(&m2);
        }
}
