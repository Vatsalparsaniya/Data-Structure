# include<stdio.h>
# define MAX 5
int deque_arr[10];
int left = -1;
int right = -1;

/*Begin of insert_right*/
void insert_right()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	cout<<"Queue Overflow\n";
		return;}
	if (left == -1)  /* if queue is initially empty */
	{	left = 0;
		right = 0;}
	else
	if(right == MAX-1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	cout<<"Input the element for adding in queue : ";
	cin>>added_item;
	deque_arr[right] = added_item ;
}
/*End of insert_right*/

/*Begin of insert_left*/
void insert_left()
{	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	cout<<"Queue Overflow\n";
		return;	 }
	if (left == -1)/*If queue is initially empty*/
	{	left = 0;
		right = 0;	 }
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	cout<<"Input the element for adding in queue : ";
	cin>>added_item;
	deque_arr[left] = added_item ;
 }
/*End of insert_left*/

/*Begin of delete_left*/
void delete_left()
{	if (left == -1)
	{	cout<<"Queue Underflow\n";
		return ;	}
	cout<<"Element deleted from queue is : "<<deque_arr[left];
	if(left == right) /*Queue has only one element */
	{	left = -1;
		right=-1;	 }
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
}
/*End of delete_left*/

/*Begin of delete_right*/
void delete_right()
{if (left == -1)
	{cout<<"Queue Underflow\n";
		return ;	 }
	cout<<"Element deleted from queue is : "<<deque_arr[right];
	if(left == right) /*queue has only one element*/
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;	}
/*End of delete_right*/
/*Begin of input_que*/
void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	cout<<"Queue is empty\n";
		return;	 }
	cout<<"Queue elements :\n";
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	cout<<deque_arr[front_pos];
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	cout<<deque_arr[front_pos];
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	cout<<deque_arr[front_pos];
			front_pos++;
		}
	}
	cout<<endl;
}
/*End of display_queue*/
/*Begin of input_que*/
void input_que()
{	int choice;
	do
	{	cout<<"1.Insert at right\n";
		cout<<"2.Delete from left\n";
		cout<<"3.Delete from right\n";
		cout<<"4.Display\n";
		cout<<"5.Quit\n";
		cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice)
		{	case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
            break;
		 default:
			cout<<"Wrong choice\n";
		}
	}while(choice!=5);
}
/*End of input_que*/

/*Begin of output_que*/
void output_que()
{	int choice;
	do
	{	cout<<"1.Insert at right\n";
		cout<<"2.Insert at left\n";
		cout<<"3.Delete from left\n";
		cout<<"4.Display\n";
		cout<<"5.Quit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
			break;
		 default:
			cout<<"Wrong choice\n";
		}
	}while(choice!=5);
}
/*End of output_que*/

/*Begin of main*/
main()
{	int choice;
	cout<<"1.Input restricted dequeue\n";
	cout<<"2.Output restricted dequeue\n";
	cout<<"Enter your choice : ";
	cin>>&choice);
	switch(choice)
	{
	 case 1 :
		input_que();
		break;
	 case 2:
		output_que();
		break;
	 default:
		cout<<"Wrong choice\n";
	}
}
/*End of main*/
