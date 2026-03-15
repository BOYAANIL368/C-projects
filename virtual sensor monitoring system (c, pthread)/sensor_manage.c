void add_Sensor()
{
	Sensor *new=malloc(sizeof(Sensor));
	printf("enter sensor ID and NAME \n");
	scanf("%d %s",&new->id,new->name);

	//cheack id is there or not
	Sensor *p=Head;
	while(p)
	{
		if(p->id == new->id)
		{
			printf("Sensor Already Rigisterd\n");
			free(new);
			return;
		}
		p = p->next;
	}
	//add at end
	new->next=0;
	if(Head==0)
	{
	      Head=new;
	}
	else
	{
		p=Head;
		while(p->next)
		{
			p=p->next;
		}

		p->next=new;
	}
	printf("New Sensor Added\n");
}
void Remove_Sensor()
{
	if(Head==0)
	{
		printf("No Sensors are avalable to Remove\n");
		return;
	}

	int id;
	printf("enter Sensor id to Remove\n");
	scanf("%d",&id);

	Sensor *p=Head,*prev=Head;
	while(p)
	{
		if(id == p->id)
		{
			if(p==Head)
			{
				Head=Head->next;
			}
			else
			{
				prev->next=p->next;
			}
			free(p);
			printf("%d id Sensor was Removed\n",id);
			return;
		}
		prev=p;
		p=p->next;
	}

	printf("No such a Sensor Id to Remove\n");
}
void Display_Sensor()
{
	if(Head==0)
	{
		printf("No sensors are Avalable\n");
		return;
	}

	Sensor *p=Head;

	while(p)
	{
		printf("\033[36mSensor id: %d Name: %s\033[m\n",p->id,p->name);
		p=p->next;
	}
}
void Search_Sensor()
{
	        if(Head==0)
        {
                printf("No Sensors are avalable to Search\n");
                return;
        }

        int id;
        printf("enter Sensor id to Search");
        scanf("%d",&id);

	Sensor *p=Head;

	while(p)
	{
		if(id == p->id)
		{
			printf("%d id Sensor found\n",id);
			printf("id= %d name: %s\n",p->id,p->name);
			return;
		}
		p=p->next;
	}
	printf("%d such id Not Found\n",id);
}
void sensor_regi_manag()
{
	int op;
	while(1)
	{
		printf("\033[32m *******Sensor registration Menu*******\033[m\n");
		printf("1. Add Sensor\n");
		printf("2. Remove Sensor\n");
		printf("3. Display Sensor\n");
		printf("4. search Sensor\n");
		printf("5. Return to Main\n");
		printf("Enter your option: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				add_Sensor();
				break;
			case 2:
				Remove_Sensor();
			        break;
			case 3:
				Display_Sensor();
				break;
			case 4:
				Search_Sensor();
				break;
			case 5:
				return;
			default:printf("unknow option\n");
		}
	}
}
