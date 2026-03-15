
/* queue pointers */
struct event *front = NULL;
struct event *rear  = NULL;
int check_id(int id)
{
	Sensor *p=Head;
	while(p)
	{
		if(id == p->id)
			return 1;
		p=p->next;
	}
	return 0;
}
int check_dupli(char *s)
{
   struct event *p = front;
    while(p)
    {
        if(strcmp(s,p->msg)==0)
		return 0;
	p=p->next;
    }
    return 1;
}
void generate_event_automatic(Sensor *p,char *s)
{
    struct event *node = malloc(sizeof(struct event));

    if(node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    if(check_dupli(s))
    {
    node->sensor_id =p->id;

    strcpy(node->msg,s);

    node->next = NULL;

    /* queue insertion */
    if(front == NULL)
    {
        front = rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
    }
    //printf("Event Generated\n");
}


/* generate event */
void generate_event()
{
    int id;

    printf("Enter Sensor ID: ");
    scanf("%d",&id);

    /* check if sensor exists */
    if(check_id(id) == 0)
    {
        printf("Event Rejected: Sensor not registered\n");
        return;
    }

    struct event *node = malloc(sizeof(struct event));

    if(node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    node->sensor_id = id;

    getchar();  // clear newline

    printf("Enter Event Message: ");
    scanf("%[^\n]",node->msg);

    node->next = NULL;

    /* queue insertion */
    if(front == NULL)
    {
        front = rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }

    printf("Event Generated\n");
}


/* process event */
void process_event()
{
    if(front == NULL)
    {
        printf("No events to process\n");
        return;
    }

    struct event *temp = front;

    printf("\nProcessing Event\n");
    printf("Sensor ID: %d\n",temp->sensor_id);
    printf("Message: %s\n",temp->msg);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}


/* display pending events */
void display_events()
{
    if(front == NULL)
    {
        printf("No pending events\n");
        return;
    }

    struct event *p = front;

    printf("\nPending Events:\n");

    while(p)
    {
        printf("Sensor ID: %d | Message: %s\n",p->sensor_id,p->msg);
        p = p->next;
    }
}


/* event queue menu */
void Event_queue()
{
    int op;

    while(1)
    {
        printf("\n****** Event Queue Menu ******\n");
        printf("1 Generate Event\n");
        printf("2 Process Event\n");
        printf("3 Show Pending Events\n");
        printf("4 Back\n");

        printf("Enter option: ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                generate_event();
                break;

            case 2:
                process_event();
                break;

            case 3:
                display_events();
                break;

            case 4:
                return;

            default:
                printf("Unknown option\n");
        }
    }
}
