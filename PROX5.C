		       /*PROJECT 100 YEAR CALENDAR*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#define MAX 15

typedef struct day
{
	int date ;
	struct day *next;

}day;

typedef struct week
{
	int week_no ;
	struct day *next ;
	struct week *down ;

}week ;

struct Event
{
    int t;
    char event[100];
    struct Event *next;
};
typedef struct Event event;

struct Todo
{
    int day;
    int mon;
    int year;
    event *side;
    struct Todo *next;
};

struct period
{
float t;
char lec[30];
struct period *next;
};

struct day1
{ char d[30];
struct day *down;
struct period *pstart;
struct period *pend;
int noofp;
};

struct ll
{ struct day1 *start;
  int count;
  struct day1 *end;
  };



struct week *create_week(struct week *start ,int zel ,int days_of_month);
struct day *create_day(int z_date,int w_num,int days_of_month);
void drawtriangle(int x1,int y1,int x2,int y2,int x3,int y3,int n);
void rec(int x,int y,int l,int n);
void indicator();
void agecalculator();
void calendar();
void todo1();
void time();
int stack[MAX];
int top=-1;
void push(int item);
int pop();
int isempty();
int isfull();
union REGS i,o;
int ascii,scan;
unsigned int handsize;
typedef struct Todo todo;
void *handimage;
int f[12]={31,28,31,30,31,30,31,31,30,31,30,31};
/*=============================Function Definition============================*/
void getkey()
{
  i.h.ah=0x00;
  int86(0x16,&i,&o);
  ascii=o.h.al;
  scan=o.h.ah;
}
void indicator()
 {
  setcolor(14);
  setlinestyle(0,1,3);
  setfillstyle(1,8);
  line(19,198,23,198);
  line(22,200,29,192);
  line(29,192,38,192);
  line(37,192,37,197);
  line(32,197,54,197);
  line(54,197,54,202);
  line(32,202,54,202);
  line(32,207,42,207);
  line(32,212,42,212);
  line(42,212,42,202);
  line(38,212,38,217);
  line(38,217,14,217);
  handsize=imagesize(14,190,56,220);
  handimage=malloc(handsize);
  getimage(14,190,56,220,handimage);
  cleardevice();
 }

/*=============================================================================================*/
struct week *create_week(struct week *start , int zel ,int days_of_month)
{
	struct week *st , *tmp , *p ;
	int i , w_n , dom ,z_num ;

	st = start ;
	dom = days_of_month ;
	z_num = zel ;	//Zeller number

	for (i = 0; i < 5; i++)
	{
		tmp=(struct week *)malloc(sizeof(struct week));
		tmp->down = NULL;
		tmp->week_no = i+1 ;

		p= st  ;

		if(st==NULL)
		{
			st=tmp;
			tmp->down = NULL ;
		}
		else
		{
			p=st;
			while(p->down!=NULL)
			{
				p=p->down ;
			}

			p->down = tmp ;
			tmp->down = NULL ;
	}

		tmp->next= create_day(z_num,i+1,dom);

	}

	return st ;
}

/*================================================================================*/
struct day *create_day(int zel,int w_num,int days_of_month)
{
	struct day *st , *head , *p ;
	int i , j , k ;
	int zell = zel ;
	int dom = days_of_month ;
	st= NULL ;

	if(w_num == 1)
	{
		for (i = 0; i < 7; i++)
		{
			p=(struct day *)malloc(sizeof(struct day));

			if(i >= zell -1 )
			{
				p->date = i - zell + 2  ;
			}
			else
			{
				p->date = 0 ;
			}
			p->next=NULL;

			if(st==NULL)
			{
				st= head = p ;
			}
			else
			{
				head->next=p;
				head=p;
			}

		}
	}
	else if(w_num == 2)
	{
		for (i = 0; i < 7; i++)
		{
			p=(struct day *)malloc(sizeof(struct day));

			p->date = zell + 1 + i ;

			p->next=NULL;

			if(st==NULL)
			{
				st= head = p ;
			}
			else
			{
				head->next=p;
				head=p;
			}

		}
	}
	else if(w_num==3)
	{
		for (i = 0; i < 7; i++)
		{
			p=(struct day *)malloc(sizeof(struct day));

			p->date = zell + 8 + i ;

			p->next=NULL;

			if(st==NULL)
			{
				st= head = p ;
			}
			else
			{
				head->next=p;
				head=p;
			}
		}
	}
	else if(w_num == 4)
	{
		for (i = 0; i < 7; i++)
		{
			p=(struct day *)malloc(sizeof(struct day));

			p->date = zell + 15 + i ;

			p->next=NULL;

			if(st==NULL)
			{
				st= head = p ;
			}
			else
			{
				head->next=p;
				head=p;
			}

		}
	}
	else if(w_num == 5)
	{
		for (i = 0; i < 7; i++)
		{
			p=(struct day *)malloc(sizeof(struct day));

			if( days_of_month >= zell + 22 + i)
			{
				p->date = zell + 22 + i ;
			}
			else
			{
				p->date = 0 ;
			}
			p->next=NULL;

			if(st==NULL)
			{
				st= head = p ;
			}
			else
			{
				head->next=p;
				head=p;
			}

		}
	}
return st;

}
/*=======================================================================*/
void *display(struct week *start)
{
	struct week *tmp , *st ;
	struct day *temp , *ptr ;
	int i=0;
	st = start ;
	tmp=st;
	cleardevice();
	setcolor(14);
	line(1,1,630,1);
	line(630,1,630,460);
	line(1,460,630,460);
	line(1,1,1,460);
	line(6,6,625,6);
	line(625,6,625,455);
	line(6,455,625,455);
	line(6,6,6,455);
	setcolor(3);
	settextstyle(1,0,4);
       outtextxy(170,20,"|| CALENDAR ||");
       gotoxy(11,12);
       printf("MON\tTUE\tWED\tTHUR\tFRI\tSAT\tSUN\n");
	for(tmp = start; tmp!= NULL; tmp=tmp->down)
	{
	       gotoxy(13,(15+i));
		for (temp=tmp->next ; temp != NULL ; temp=temp->next)
		{
		    if(temp->date<=9)
		    { if(temp->date==0)
		      printf("\t");
		      else
		      printf("%d\t", temp->date);
		    }
		   else
		   printf("%d\t",temp->date);
		}
		 i=i+2;
		 printf("\n");
	}
}
/*=====================================ZELLAR ALGORITHM========================================================*/

int getZeller(int Month,int Year)
{
	int Day = 1, ZMonth, ZYear, Zeller;
	if(Month < 3)
		ZMonth = Month+10;
	else
		ZMonth = Month-2;
	if(ZMonth > 10)
		ZYear = Year-1;
	else
		ZYear = Year;
	Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
			(int)((ZYear%100)/4)-2*(int)(ZYear/100)+
			(int)(ZYear/400)+77)%7;
	return Zeller;
}

/*=============================================================================================*/
event *create()
{
   event *p,*q,*r,*st;
   int x;
  char  ch='y';
   st=NULL;
   while(ch=='y')
   {
   cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,">>Please Enter The Time Of The Event\n ");
   r=(event *)malloc(sizeof(event));
   gotoxy(32,13);
   scanf("%d",&r->t);
   x=r->t;
   setcolor(3);
   settextstyle(1,0,1);
   outtextxy(20,250,">>Please Enter The Name Of The Event\n ");
   gotoxy(32,20);
   scanf("%s",r->event);
   cleardevice();
   r->next=NULL;
   if(st==NULL||st->t>x)
   {
      r->next=st;
      st=r;
   }
   else
   p=NULL;
   q=st;
   while(q!=NULL)
   {
     if(q->t>x)
     {
       goto end;
     }
     p=q;
     q=q->next;
   }
   p->next=r;
   end:
   p->next=r;
   r->next=q;
   setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(170,20,"|| TO DO LIST ||");
   setcolor(3);
   settextstyle(1,0,1);
   outtextxy(20,300,"* Want To Enter More Events On This Day?\n ");
   fflush(stdin);
   ch=getche();
   cleardevice();
    }
    return st;
    }
/*======================================================================*/
todo *start()
{
   todo *r,*p,*q,*st;
   char ch='y';
   int x,y,z;

   st=NULL;
   fflush(stdin);
   while(ch=='y')
   {
 cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,">>Please Enter The Day | Month | Year\n ");
     r=(todo *)malloc(sizeof(todo));;
     gotoxy(32,13);
     scanf("%d",&r->day);
     outtextxy(30,195,"|");
     gotoxy(32,15);
     scanf("%d",&r->mon);
     outtextxy(30,250,"|");
     gotoxy(32,17);
     scanf("%d",&r->year);
     r->next=NULL;
     r->side=create();
     x=r->day;
     y=r->mon;
     z=r->year;
     if(st==NULL||st->year>z||st->year==z&&st->mon>y||st->year==z&&st->mon==y&&st->day>x)
     {
	r->next=st;
	st=r;
     }
     else
     {
	p=NULL;
	q=st;
	while(q!=NULL)
	{
	   if(q->year>z||q->year==z&&q->mon>y||q->year==z&&q->mon==y&&q->day>x)
	   {
	      goto end;
	   }
	      p=q;
	      q=q->next;

	}
	p->next=r;
	end:
	p->next=r;
	r->next=q;
     }
     cleardevice();//desighning the page;
     setcolor(5);
     line(1,1,630,1);
     line(630,1,630,460);
     line(1,460,630,460);
     line(1,1,1,460);
     line(6,6,625,6);
     line(625,6,625,455);
     line(6,455,625,455);
     line(6,6,6,455);
     setcolor(14);
     settextstyle(1,0,4);
     outtextxy(150,20,"|| TO DO LIST ||");
     setcolor(3);
     settextstyle(1,0,1);
     outtextxy(30,200,"\n * Want To Enter More Event DATES?\n");
     gotoxy(32,17);
     fflush(stdin);
     ch=getche();
     cleardevice();
   }
   return st;
}
/*====================================================================================*/
todo *del(int d,int m,int y,todo *st)
{
  todo *p,*q;
  event *s,*r;
  char ch;
   int i,k;
   end2:
   q=NULL;
for(p=st;p!=NULL;p=p->next)
 {
    if(p->day==d&&p->mon==m&&p->year==y)
    {
       goto end;
    } q=p;   }

 cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,0);
 outtextxy(20,230," *Date Does Not Exist! :( :(\n");
 outtextxy(20,280," *Want To Enter Another Date?\n");
      fflush(stdin);
      ch=getche();
      cleardevice();
      if(ch=='y')
     {
      outtextxy(20,290,"Enter The Day Month Year \n");
      scanf("%d%d%d",&d,&m,&y);
      cleardevice();
      goto end2;
      }
      else
      return p;

    end:
  cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,200,"* Enter Choice:-");
 outtextxy(20,204," 1.Delete All Events on dd|mm|yy.");
 outtextxy(20,206," 2.Delete Single Event on dd|mm|yy.");
 gotoxy(32,13);
 scanf("%d",&i);
  switch(i)
  {
  case 1:

     if(p==st&&st->next==NULL)
     {free(p);
     return NULL;}
     else if(p==st)
     {
      p=st->next;
       free(st);
       st=p;
       return st;}
      else
     {q->next=p->next;
     free(p);
     return st;
     }
     case 2:

      end3:
      s=NULL;
 cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
      setcolor(3);
      settextstyle(1,0,1);
      outtextxy(20,275,"* Enter Time Of Event To be Deleted:-");
      gotoxy(32,20);
      scanf("%d",&k);
      cleardevice();
      for(r=p->side;r!=NULL;r=r->next)
      {
      if(r->t==k)
      { if(r==p->side&&r->next==NULL)
      {free(r);
      return NULL;}
      else if(r==p->side)
      {
       r=p->side->next;
       free(p->side);
       p->side=r;
       return st;
      }else
      {
      s->next=r->next;
      free(r);
      return st;
      } }
       s=r;}}
       cleardevice();//desighning the page;
       setcolor(5);
      line(1,1,630,1);
      line(630,1,630,460);
      line(1,460,630,460);
      line(1,1,1,460);
      line(6,6,625,6);
      line(625,6,625,455);
      line(6,455,625,455);
      line(6,6,6,455);
     setcolor(14);
     settextstyle(1,0,4);
     outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
      outtextxy(20,300,"* Event Doesn't Exist!");
      outtextxy(20,320, "* Want To enter Another Event");
       fflush(stdin);
       ch=getche();
       cleardevice();
       if(ch=='y')
       {
	  goto end3;    }
	  else
       {
       return NULL;}


 }
/*=================================================================================*/
todo *finder(int d,int m,int y,todo *st)
{
  todo *p;
  char ch;
for(p=st;p!=NULL;p=p->next)
 {
    if(p->day==d&&p->mon==m&&p->year==y)
    {
       goto end;
    }    }

      setcolor(3);
      settextstyle(1,0,1);
      outtextxy(20,300,"* Event Doesn't Exist!");
     outtextxy(20,340, "* Want To enter Another Event");
      fflush(stdin);
      ch=getche();
      cleardevice();
    if(ch=='y')
    return st;
    else
    return p;
    end:
    return p;
 }
/*===================================================================================================*/
event *inserte(event *st)
{
  event *p,*q,*r;
  int x;
  char ch='y';
  fflush(stdin);
  while(ch=='y')
  {
  cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
  r=(event *)malloc(sizeof(event));
  setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,200," *Enter Choice:-");
 outtextxy(20,230,"(1)Delete All Events on dd|mm|yy");
 outtextxy(20,250,"(2)Delete Single Event on dd|mm|yy");
 gotoxy(32,13);
  cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
  outtextxy(20,210," *Enter Time");
  gotoxy(32,15);
  scanf("%d",&r->t);
  outtextxy(20,230," *Enter The Name Of The Event");
  gotoxy(32,25);
  scanf("%s",r->event);
  cleardevice();
  r->next=NULL;
  x=r->t;
  if(st==NULL||st->t>x)
  {
     r->next=st;
     st=r;

  }
  else
{  p=NULL;
  q=st;
  while(q!=NULL)
  {
     if(q->t>x)
     {
	goto end;
     }
     p=q;
     q=q->next;
  }
  p->next=r;

  end:

  p->next=r;
  r->next=q;}
  cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
  setcolor(3);
  settextstyle(1,0,1);
  outtextxy(20,180,"*Want To Insert More Event?");
  fflush(stdin);
  ch=getche();
  cleardevice();
  }
   return st;
}
/*=======================================================================================*/
todo *insertt(int x,int y,int z,todo *st)
{
   todo *r,*p,*q;
   int count=0;
   char ch='y';
   if(st==NULL)
   return st;
   fflush(stdin);
   while(ch=='y')
   {
     r=(todo *)malloc(sizeof(todo));
     if(count!=0)
    { setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
  settextstyle(1,0,4);
  outtextxy(150,20,"|| TO DO LIST ||");
   outtextxy(20,170,"Please Enter The Day | Month | Year");
    gotoxy(32,12);
   scanf("%d%d%d",&r->day,&r->mon,&r->year);  }
    if(count==0)
    { r->day=x;
     r->mon=y;
     r->year=z;
     }

     r->next=NULL;
     r->side=create();
     if(st->year>z||st->year==z&&st->mon>y||st->year==z&&st->mon==y&&st->day>x)
     {
	r->next=st;
	st=r;
     }
     else
     {
	p=NULL;
	q=st;
	while(q!=NULL)
	{
	   if(q->year>z||q->year==z&&q->mon>y||q->year==z&&q->mon==y&&q->day>x)
	   {
	      goto end;
	   }
	      p=q;
	      q=q->next;

	}
	p->next=r;
	end:
	p->next=r;
	r->next=q;
     }
	setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
  settextstyle(1,0,4);
  outtextxy(150,20,"|| TO DO LIST ||");
       setcolor(3);
       settextstyle(1,0,1);
	outtextxy(20,150,"* Want To Insert More Event DATES?");
	fflush(stdin);
	ch=getche();
	cleardevice();
	count++;
   }
   return st;
}
/*=============================================================================================*/
void displaye(todo *st)
{  int e,j=0,k=0;
  todo *p;
  event *q;
  cleardevice();
  setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
  settextstyle(1,0,4);
  outtextxy(200,20,"|| TO DO LIST ||");
  for(p=st;p!=NULL;p=p->next)
  {  e=0;
   gotoxy(29,(12+k+j));
   printf(">> %d|%d|%d",p->day,p->mon,p->year);
   for(q=p->side;q!=NULL;q=q->next)
   {
      ++e;
      gotoxy(29,(11+j+6));
      printf("* Event%d:-",e);
      printf("  Time  %d\t",q->t);
      printf("  %s",q->event);
      j=j+2;
   }
   k=k+4;
}
getch();
}
/*===============================================================================================*/
 void addp(struct day1 *day,struct period *p)
  {
    if(day->noofp==0)
    {
     day->pstart=day->pend=p;
     }
    else
    { day->pend->next=p;
     day->pend=p;
     }
    day->noofp++;
  }
/*================================================================================================*/
void intial(struct ll *s)
{
s->start=NULL;
 s->count=0;
  s->end=NULL;
  }
/*================================================================================================*/
 void createday(struct day1 *day)
 { int m=0;
   gotoxy(13,(10+m));
   printf("enter day name");
   scanf("%s",day->d);
   day->down=NULL;
   day->pstart=NULL;
   m=m+5;
   }
/*===============================================================================================*/
 void createperiod(struct period *p)
 {
 int l=0;
 fflush(stdin);
 gotoxy(13,(10+l));
 printf("enter time");
 scanf("%f",&p->t);
 printf("enter lname");
 scanf("%s",p->lec);
 l=l+6;
 }
/*=================================================================================================*/
 void addday(struct ll *tt,struct day1 *day)
 {
 if(tt->count==0)
  { tt->start=tt->end=day;
  }
  else
  { tt->end->down=day;
   tt->end=day;
   }
   tt->count++;
  }
/*===================================================================================================*/


void main()
{
 int gd=DETECT,gm;
 int x1=50,y1=10,x2=10,y2=80,x3=110,y3=80,n=6;
 int x4=590,y4=10,x5=530,y5=80,x6=630,y6=80,p=6;
 int x7=50,y7=400,x8=10,y8=470,x9=110,y9=470,q=6;
 int x10=590,y10=400,x11=530,y11=470,x12=630,y12=470,s=6;
 int x13=200,y13=20,x14=350,y14=20,x15=570,y15=180,x16=570,y16=255,x17=200,y17=420,x18=350,y18=420,x19=35,y19=180,x20=35,y20=255,l=30;
 int xa=0,ya=0,xb=635,yb=0,xc=635,yc=475,xd=0,yd=475,a;
 int item,i,j,k,data,dat,mon,yea;
 static int c=1;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 line(xa,ya,xb,yb);
 line(xb,yb,xc,yc);
 line(xc,yc,xd,yd);
 line(xd,yd,xa,ya);
 drawtriangle(x1,y1,x2,y2,x3,y3,n);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(100,15,"2015");
 rec(x13,y13,l,n);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(250,15,"2014");
 rec(x14,y14,l,n);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(420,15,"2013");
 drawtriangle(x4,y4,x5,y5,x6,y6,p);
 setcolor(14);
 settextstyle(1,90,0);
 outtextxy(560,85,"1995");
 rec(x15,y15,l,p);
 rec(x16,y16,l,p);
 setcolor(14);
 settextstyle(1,90,0);
 outtextxy(560,300,"1994");
 drawtriangle(x10,y10,x11,y11,x12,y12,q);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(100,415,"1885");
 rec(x17,y17,l,q);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(250,415,"1884");
 rec(x18,y18,l,q);
 setcolor(14);
 settextstyle(1,0,0);
 outtextxy(420,415,"1883");
 drawtriangle(x7,y7,x8,y8,x9,y9,s);
 setcolor(14);
 settextstyle(1,90,0);
 outtextxy(30,85,"1773");
 rec(x19,y19,l,s);
 rec(x20,y20,l,s);
 setcolor(14);
 settextstyle(1,90,0);
 outtextxy(30,300,"1774");
 setcolor(3);
 settextstyle(1,0,6);
 outtextxy(190,150,"100 YEAR");
 outtextxy(200,200,"CALENDAR");
 setcolor(9);
 settextstyle(0,0,1);
 outtextxy(200,335,"loading....");
 for(a=200;a<=500;a=a+10)
 {
 bar(a,350,a,360);
 delay(200);
 }
 cleardevice();
 line(xa,ya,xb,yb);//creator page desighning;
 line(xb,yb,xc,yc);
 line(xc,yc,xd,yd);
 line(xd,yd,xa,ya);
 line(xa+5,ya+5,xb-5,yb+5);
 line(xb-5,yb+5,xc-5,yc-5);
 line(xc-5,yc-5,xd+5,yd-5);
 line(xd+5,yd-5,xa+5,ya+5);
 setcolor(14);
 settextstyle(1,0,5);
 outtextxy(200,20,"|| CREATORS ||");
 setcolor(4);
 settextstyle(1,0,1);
 outtextxy(20,150," 1. HRISHIKESH SINGH");
 outtextxy(20,170," 2. VAIBHAV GROVER");
 outtextxy(20,190," 3. SHIVAN TRIVEDI");
 outtextxy(20,210," 4. ABHINAV SHARMA");
 setcolor(14);
 settextstyle(1,0,1);
 outtextxy(350,140,"You will never FIND ");
 outtextxy(360,170,"time for anything.");
 outtextxy(350,200,"If you want time,you");
 outtextxy(360,230,"must make it.");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(430,250,"- Charles Broxton");
 setcolor(9);
 settextstyle(1,0,1);
 outtextxy(200,350,"PRESS esc TO EXIT  <<--");
 outtextxy(260,375,"OR");
 outtextxy(200,410,"PRESS any key TO ENTER -->>");
 getkey();
 if(ascii==27) //esc
 {
 cleardevice();
setcolor(4);
line(1,1,630,1);//desighning the end page;
line(630,1,630,460);
line(1,460,630,460);
line(1,1,1,460);
line(6,6,625,6);
line(625,6,625,455);
line(6,455,625,455);
line(6,6,6,455);
setcolor(5);
settextstyle(1,0,6);
outtextxy(160,150,"THANK YOU");
outtextxy(120,210,"FOR VISITING !!!");
setcolor(14);
circle(60,60,30);
circle(75,50,5);
circle(45,50,5);
arc(60,70,180,360,10);
circle(300,60,30);
circle(315,50,5);
circle(285,50,5);
arc(300,70,180,360,10);
circle(570,60,30);
circle(585,50,5);
circle(555,50,5);
arc(570,70,180,360,10);
circle(570,230,30);
circle(585,220,5);
circle(555,220,5);
arc(570,240,180,360,10);
circle(570,400,30);
circle(585,390,5);
circle(555,390,5);
arc(570,410,180,360,10);
circle(300,400,30);
circle(315,390,5);
circle(285,390,5);
arc(300,410,180,360,10);
circle(60,400,30);
circle(75,390,5);
circle(45,390,5);
arc(60,410,180,360,10);
circle(60,230,30);
circle(75,220,5);
circle(45,220,5);
arc(60,240,180,360,10);
getch();
exit(0);}
  cleardevice();
  indicator();
  cleardevice();
   //home page desighning is done ahead;
    home:
      while(1)
      {
	cleardevice();
	setcolor(WHITE);
	c=1;
	line(1,1,630,1);
	line(630,1,630,460);
	line(1,460,630,460);
	line(1,1,1,460);
	line(6,6,625,6);
	line(625,6,625,455);
	line(6,455,625,455);
	line(6,6,6,455);
	setcolor(14);
	settextstyle(1,0,5);
	outtextxy(200,20,"|| TASK ||");
	settextstyle(1,0,3);
	putimage(130,175,handimage,OR_PUT);
	setcolor(4);
	outtextxy(180,180,"VIEW CALENDAR");
	setcolor(5);
	outtextxy(180,230,"TO DO LIST :)");
	outtextxy(180,280,"AGE CALCULATOR");
	outtextxy(180,330,"TIME MANAGER");
	outtextxy(180,380,"EXIT....");
	getkey();
	if(ascii==27)
	exit(0);
	 if(ascii==13)
	   calendar();
	   else if(((scan==80)||(scan==72))&&(c==1))
	   {
	     b:       setcolor(5);
		    putimage(130,175,handimage,OR_PUT);
		    settextstyle(1,0,3);
		    outtextxy(180,230,"TO DO LIST :)");
		    outtextxy(180,280,"AGE CALCULATOR");
		    outtextxy(180,330,"TIME MANAGER");
		    outtextxy(180,380,"EXIT....");
		    setcolor(4);
		    outtextxy(180,180,"VIEW CALENDAR");
		    c++;
		    getkey();
		    if(ascii==13) {calendar();goto home;}
		    if(scan==72) {c=5;goto g;}
		    else if((scan==80)&&(c==2))
		    {
		d:          setcolor(5);
			putimage(130,225,handimage,OR_PUT);
			settextstyle(1,0,3);
			outtextxy(180,180,"VIEW CALENDAR");
			outtextxy(180,280,"AGE CALCULATOR");
			outtextxy(180,330,"TIME MANAGER");
			outtextxy(180,380,"EXIT....");
			setcolor(4);
			outtextxy(180,230,"TO DO LIST :)");
			c++;
			getkey();
			if(ascii==13) todo1();
			else if(scan==72) {c-=2;goto b;}
			if((scan==80)&&(c==3))
			{
		  e:          setcolor(5);
			  putimage(130,275,handimage,OR_PUT);
			  settextstyle(1,0,3);
			  outtextxy(180,180,"VIEW CALENDAR");
			  outtextxy(180,230,"TO DO LIST :)");
			  outtextxy(180,330,"TIME MANAGER");
			  outtextxy(180,380,"EXIT....");
			  setcolor(4);
			  outtextxy(180,280,"AGE CALCULATOR");
			  c++;
			  getkey();
			  if(ascii==13) agecalculator();
			   if(scan==72) { c=-2;goto d;}
			  if((scan==80)&&(c==4))
			  {
		     f:        setcolor(5);
			  putimage(130,325,handimage,OR_PUT);
			  settextstyle(1,0,3);
			  outtextxy(180,180,"VIEW CALENDAR");
			  outtextxy(180,230,"TO DO LIST :)");
			  outtextxy(180,280,"AGE CALCULATOR");
			  outtextxy(180,380,"EXIT....");
			  setcolor(4);
			  outtextxy(180,330,"TIME MANAGER");
			  c++;
			  getkey();
			  if(ascii==13) time();
			  else if(scan==72) { c-=2; goto e;}
			  else if((scan==80)&&(c==5))
			  {
		  g:           setcolor(5);
			  putimage(130,375,handimage,OR_PUT);
			  settextstyle(1,0,3);
			  outtextxy(180,180,"VIEW CALENDAR");
			  outtextxy(180,230,"TO DO LIST :)");
			  outtextxy(180,280,"AGE CALCULATOR");
			  outtextxy(180,330,"TIME MANAGER");
			  setcolor(4);
			  outtextxy(180,380,"EXIT....");
			  c++;
			  getkey();
			  if(ascii==13){
			  cleardevice();
			  setcolor(4);
			  line(1,1,630,1);//desighning the end page;
			  line(630,1,630,460);
			  line(1,460,630,460);
			  line(1,1,1,460);
			  line(6,6,625,6);
			  line(625,6,625,455);
			  line(6,455,625,455);
			  line(6,6,6,455);
			  setcolor(5);
			  settextstyle(1,0,6);
			  outtextxy(160,150,"THANK YOU");
			  outtextxy(120,210,"FOR VISITING !!!");
			  setcolor(14);
			  circle(60,60,30);
			  circle(75,50,5);
			  circle(45,50,5);
			  arc(60,70,180,360,10);
			  circle(300,60,30);
			  circle(315,50,5);
			  circle(285,50,5);
			  arc(300,70,180,360,10);
			  circle(570,60,30);
			  circle(585,50,5);
			  circle(555,50,5);
			  arc(570,70,180,360,10);
			  circle(570,230,30);
			  circle(585,220,5);
			  circle(555,220,5);
			  arc(570,240,180,360,10);
			  circle(570,400,30);
			  circle(585,390,5);
			  circle(555,390,5);
			  arc(570,410,180,360,10);
			  circle(300,400,30);
			  circle(315,390,5);
			  circle(285,390,5);
			  arc(300,410,180,360,10);
			  circle(60,400,30);
			  circle(75,390,5);
			  circle(45,390,5);
			  arc(60,410,180,360,10);
			  circle(60,230,30);
			  circle(75,220,5);
			  circle(45,220,5);
			  arc(60,240,180,360,10);
			  getch();
			  break;}
			  else if(scan==72) { c-=2; goto f;}
			  else if((scan==80))
			  { c=1; goto b;}
			  }//g
			 }//f
			}//e
		       }//d
		      }//b
		     }//while
   closegraph();
   getch();
}

/*================================Function Definition================================*/
void drawtriangle(int x1,int y1,int x2,int y2,int x3,int y3,int n)
{
 int v1,v2,v3,v4,v5,v6;
 setcolor(4);
 if(n==1)
 {
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x1,y1,x3,y3);
 }else{
 v1=(x1+x2)/2;
 v2=(y1+y2)/2;
 v3=(x2+x3)/2;
 v4=(y2+y3)/2;
 v5=(x1+x3)/2;
 v6=(y1+y3)/2;
 drawtriangle(x1,y1,v1,v2,v5,v6,n-1);//using recursion;
 drawtriangle(v1,v2,x2,y2,v3,v4,n-1);
 drawtriangle(v5,v6,v3,v4,x3,y3,n-1);
 }
 }
/*=======================================================================================*/
 void rec(int x,int y,int l,int n)
 {
  setcolor(5);
  if(n==1)
  {
   rectangle(x,y,x+l,y+l);
   }
   else{
      rec(x,y,l/3,n-1);         // using recursion;
       rec(x+((2*l)/3),y,l/3,n-1);
	rec(x,y+((2*l)/3),l/3,n-1);
	 rec(x+((2*l)/3),y+((2*l)/3),l/3,n-1);
	  rec(x+l/3,y+l/3,l/3,n-1);
	  }
	  }
/*===========================================================*/
 void push(int item)
 {
  if(isfull())
  {
  printf("stack overflown");
  }
  top=top+1;
  stack[top]=item;
 }
 /*==============================================================*/
 int pop()
 {
  int item;
  if(isempty())
  {
  printf("stack underflown");
  }
  item=stack[top];
  top=top-1;
  return item;
 }
 /*========================================================================*/
 int isempty()
 {
  if(top==-1)
  return 1;
  else
  return 0;
 }

 int isfull()
 {
  if(top==MAX-1)
  return 1;
  else
  return 0;
 }
 /*==============================================================================*/
 void agecalculator()
 {
 int date,month,year,stc,k,y,count=0,j,data;
 long int sum=0;
 cleardevice();//desighning the page;
 setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| AGE CALCULATOR ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,">>Enter the date of birth in following order: ");
 outtextxy(30,190,"* Enter the date:");
 gotoxy(32,13);
 scanf("%d",&date);
 outtextxy(30,230,"* Enter the month:");
 gotoxy(32,16);
 scanf("%d",&month);
 outtextxy(30,270,"* Enter the year:");
 gotoxy(32,18);
 scanf("%d",&year);
		stc=f[month-1]-date;
		push(stc); //pushing no of remaining day(using stack data structures);
	for(k=month;k<12;k++)
	{
		push(f[k]);//pushing no of remaining days in that year(using stack data structures);
	}

	//calculating the no of days of the remaining years till 1 jan 2015;
	y=(2015-(year+1))*365;

	push(y);
	//calculating the years including leap year;
	for(k=year+1;k<2015;k++)
	{
		if(((k%4==0)||(k%400==0))&&(k%100!=0))
		{
			count++;
		}
	}

	push(count);
	//suming up the total days the user has lived till today;
	 for(j=top;j>=0;j--)
	{
		data=pop();  //popping and suming using stack data structures;
		sum=sum+data;
	 }
   setcolor(5);
   settextstyle(1,0,1);
   outtextxy(20,310,"* The number of days you have lived till 1 JAN 2015 are:");
   gotoxy(32,23);
   printf("%ld",sum);
   getch();
   cleardevice();
   }
/*=============================================================================*/
 void calendar()
 {
  int dd , mm , yyyy , zel , days_of_month ;
  struct week *start=NULL ;
	cleardevice();
	setcolor(14);
	line(1,1,630,1);
	line(630,1,630,460);
	line(1,460,630,460);
	line(1,1,1,460);
	line(6,6,625,6);
	line(625,6,625,455);
	line(6,455,625,455);
	line(6,6,6,455);
	setcolor(5);
 settextstyle(1,0,4);
 outtextxy(200,20,"|| CALENDAR ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(30,190,">>Enter the navigation date: DD MM YYYY ");
 gotoxy(32,18);
	scanf("%d%d%d",&dd,&mm,&yyyy);

	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
	{
		days_of_month = 31 ;
	}
	else if(mm==4||mm==6||mm==9||mm==11)
	{
		days_of_month = 30 ;
	}
	else if(mm==2)
	{
		if(yyyy%4==0)
		{
			days_of_month = 29 ;
		}
		else
		{
			days_of_month = 28;
		}
	}

	zel = getZeller(mm,yyyy);

	start = create_week(start,zel,days_of_month);

       display(start) ;
      getch();
      cleardevice();
  }
/*================================================================================*/
void todo1()
{
 todo *st,*p;
 event *i;
 char ch;
 int d,m,y,k;
 cleardevice();
st=start();
displaye(st);
cleardevice();
setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,"* Want to update events:");
fflush(stdin);
ch=getche();
cleardevice();
if(ch=='y')
{
do{
  cleardevice();
  setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150," * Select Options:-");
 outtextxy(20,170," 1. Insertion Of Events (press 1)");
 outtextxy(20,190," 2. Deletion Of Events (press 2)");
 gotoxy(32,20);
  scanf("%d",&k);
  cleardevice();
  switch(k)
  {
  case 1:
  cleardevice();
  setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,">>Enter date : ");
 gotoxy(32,13);
 scanf("%d",&d);
 outtextxy(30,230,">>Enter the month:");
 gotoxy(32,16);
 scanf("%d",&m);
 outtextxy(30,270,">>Enter the year:");
 gotoxy(32,18);
 scanf("%d",&y);
p=finder(d,m,y,st);
if(p==NULL||p->day!=d||p->mon!=m||p->year!=y)
{p=insertt(d,m,y,p);
  if(p!=NULL)
  displaye(p);
  else
  displaye(st);
}else
{p->side=inserte(p->side);
displaye(st);
}
break;

case 2:
ch='y';
fflush(stdin);
while(ch=='y')
{ cleardevice();
setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TO DO LIST ||");
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,150,">>Enter date : ");
 gotoxy(32,13);
 scanf("%d",&d);
 outtextxy(30,230,">>Enter the month:");
 gotoxy(32,16);
 scanf("%d",&m);
 outtextxy(30,270,">>Enter the year:");
 gotoxy(32,18);
 scanf("%d",&y);
st=del(d,m,y,st);
outtextxy(30,320,"* Want To Delete More Events?");
fflush(stdin);
ch=getche();   }
displaye(st);
break;
}
 setcolor(3);
 settextstyle(1,0,1);
 outtextxy(20,340,"* Want To Update More Events?");
fflush(stdin);
ch=getche();
}while(ch=='y');}
getch();
cleardevice();
}
/*=================================================================================*/
void time()
{
  int i,j,n,m=0;
  struct ll *tt;
  struct day1 *day;
  struct period *p;
  tt=(struct ll*)malloc(sizeof(struct ll));
  cleardevice();
setcolor(5);
 line(1,1,630,1);
 line(630,1,630,460);
 line(1,460,630,460);
 line(1,1,1,460);
 line(6,6,625,6);
 line(625,6,625,455);
 line(6,455,625,455);
 line(6,6,6,455);
 setcolor(14);
 settextstyle(1,0,4);
 outtextxy(150,20,"|| TIME MANAGER ||");
  for(i=0;i<=7;i++)
  {
  createday(day);
  addday(tt,day);
  gotoxy(13,(15+m));
  printf("enter no of period");
  scanf("%d",&n);
  for(j=0;j<n;j++)
  {
  createperiod(p);
  addp(day,p);
  }
  m=m+2;
  }
 }
/*===================================================================================*/