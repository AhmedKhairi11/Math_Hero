#include<windows.h>
#ifdef __APPLE__
#else
#endif
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include <time.h>
#include<stdlib.h>




int phyWidth = 600, phyHeight = 600;
int logWidth = 100, logHeight = 100;
int status=0;
bool TimeFlag = 1;
int mouseXX,mouseYY;
int milli_seconds = 5000;
int end_time = 60000;
int sqwidth=10;
int sqhight=40;
bool fileFlag = 1;
bool sqUp=true;
int sqDelta=0;
int maxY=22;
int cx1=50,cy1=30,cx2=50,cy2=50,cx3=50,cy3=70;
char str[10000];
char Newstr[2]={0,0};
int number1,number2;
char operatorr;
char equ[50];
int flag=0;
int check_answer=0;
int step=0;
int score=0;
char str_score[50];
int scoresize = 0;
int array_scores[1000];
int Rank = 0;
char ra[50];
char strr[20];
char H_SCO[10];

using namespace std;

typedef struct Square{
    int cx;
    int cy;
    int sqhight;
    int sqwidth;
    char arithmetic_op[50];
}Square;

typedef struct ans{
    int ans;
    bool state_ans;
}ans;


ans result_mo3dlat[50];
Square sq[50];

void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, logWidth, 0.0, logHeight);
}

void printSome(char *str,int x,int y)
{
    glRasterPos2d(x,y);

    int len = strlen(str);
    for (int i=0;i<len;i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);

    glFlush();
}

void Timer(int value)
{
    glutTimerFunc(200, Timer, value);
    glutPostRedisplay();
}


void Keyboard(unsigned char key, int x, int y)
{
     if(key == (char)13)
     {
        check_answer=atoi(str);
        strcpy(str,"");
     }
     else
     {
         Newstr[0]=key;
        strcat(str,Newstr);
     }
}


void speacial_keyboard(int key,int x,int y)
{
    if(key == GLUT_KEY_F1)
    {
        flag=0;
        status=1;
    }
    else if(key == GLUT_KEY_F2)
        status=0;
}


void mouseClick(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        mouseXX = x;
        mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
        mouseYY = phyHeight - y;
        mouseYY=0.5+1.0*mouseYY*logHeight/phyHeight;
     if( mouseXX>=(cx3-sqhight/2) && mouseXX<=(cx3+sqhight/2) && mouseYY >=(cy3-sqwidth/2) && mouseYY <=(cy3+sqwidth/2))
     {
        status=1;
     }
     if( mouseXX>=(cx2-sqhight/2) && mouseXX<=(cx2+sqhight/2) && mouseYY >=(cy2-sqwidth/2) && mouseYY <=(cy2+sqwidth/2))
     {
        status=2;
     }
     if( mouseXX>=(cx1-sqhight/2) && mouseXX<=(cx1+sqhight/2) && mouseYY >=(cy1-sqwidth/2) && mouseYY <=(cy1+sqwidth/2))
     {
        status=3;
     }
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
     status=0;
    }
     glutPostRedisplay();
    }


    void check()
{
    if(check_answer == result_mo3dlat[step].ans && result_mo3dlat[step].state_ans==0)
    {
        result_mo3dlat[step].state_ans=1;
        score++;
    }
    else if(check_answer == result_mo3dlat[step+1].ans && result_mo3dlat[step+1].state_ans==0)
    {
        result_mo3dlat[step+1].state_ans=1;
        score++;
    }
    else if(check_answer == result_mo3dlat[step+2].ans && result_mo3dlat[step+2].state_ans==0)
    {
        result_mo3dlat[step+2].state_ans=1;
        score++;
    }

    check_answer = 10000;

}

    void drawSquares()
   {

    glColor3f(0.82,0.53,0.64);
    printSome("Ma+h Her0",40,95);
     glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(cx1-sqhight/2,cy1-sqwidth/2);
    glVertex2f(cx1+sqhight/2,cy1-sqwidth/2);
    glVertex2f(cx1+sqhight/2,cy1+sqwidth/2);
    glVertex2f(cx1-sqhight/2,cy1+sqwidth/2);
    glEnd();

    glColor3f(0.16,0.61,1.00);
    printSome("QUIT",45,29);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(cx2-sqhight/2,cy2-sqwidth/2);
    glVertex2f(cx2+sqhight/2,cy2-sqwidth/2);
    glVertex2f(cx2+sqhight/2,cy2+sqwidth/2);
    glVertex2f(cx2-sqhight/2,cy2+sqwidth/2);
    glEnd();

    glColor3f(0.16,0.61,1.00);
    printSome("HIGHSCORES",37,49);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(cx3-sqhight/2,cy3-sqwidth/2);
    glVertex2f(cx3+sqhight/2,cy3-sqwidth/2);
    glVertex2f(cx3+sqhight/2,cy3+sqwidth/2);
    glVertex2f(cx3-sqhight/2,cy3+sqwidth/2);
    glEnd();

    glColor3f(0.16,0.61,1.00);
    printSome("PLAY",45,69);
    glEnd();
}
void drawSquares_2(Square sq,int cx,int cy)
{

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(cx-sqhight/2, (cy-10)-sqwidth/2+sqDelta); // x, y
    glVertex2f(cx+sqhight/2, (cy-10)-sqwidth/2+sqDelta); // x, y
    glVertex2f(cx+sqhight/2, (cy-10)+sqwidth/2+sqDelta); // x, y
    glVertex2f(cx-sqhight/2, (cy-10)+sqwidth/2+sqDelta); // x, y
    glEnd();

    int len=strlen(sq.arithmetic_op);
    glColor3f(0.16,0.61,1.00);
    printSome(sq.arithmetic_op,cx-len+1,(cy-11)+sqDelta);
    glEnd();

}

void mo3dlat(int index,char *equ,int number1,int number2,char operatorr){

    result_mo3dlat[index].state_ans=0;

    if(operatorr == '+')
    {
        result_mo3dlat[index].ans=number1+number2;
    }
    else if(operatorr == '-')
    {
        result_mo3dlat[index].ans=number1-number2;
    }
    else if(operatorr == '*')
    {
        result_mo3dlat[index].ans=number1*number2;
    }
    sprintf(equ,"%d %c %d",number1,operatorr,number2);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquares();
    glClear(GL_COLOR_BUFFER_BIT);

                if(status==0)
                {
                        glClearColor(0,0,0,0);
                        drawSquares();

                }
                else if(status==1)
            {

                if(flag==0)
                {
                    int s=0;
                    char arr[3]={'+','-','*'};
                    for(int i=0;i<50;i++)
                    {
                        sq[i].cx=50;
                        sq[i].cy=80-s;
                        sq[i].sqhight=sqhight;
                        sq[i].sqwidth=sqwidth;
                        number1=rand()%4;
                        number2=rand()%4;
                        operatorr=arr[rand()%3];
                        mo3dlat(i,equ,number1,number2,operatorr);
                        strcpy(sq[i].arithmetic_op,equ);
                        s+=35;
                    }

                    flag=1;
                    sqDelta=0;
                    score=0;
                    check_answer = 100000;
                }

                if(TimeFlag)
                {
                    end_time += clock();
                    TimeFlag = 0;
                    score = 0;
                }

                  if(clock() >= end_time)
                {

                    status=4;
                    fileFlag = 1;

                    FILE *file = fopen("D:\AAST Semesters\S.8\CC416 - Computer Graphics\Graphics\mathhero\Mathheroproj\\file.txt","a");
                    fprintf(file,"%d\n",score);
                    fclose(file);

                    int i = 0;

                    file = fopen("D:\AAST Semesters\S.8\CC416 - Computer Graphics\Graphics\mathhero\Mathheroproj\\file.txt","r");
                    while(~fscanf(file,"%d",&array_scores[i])){i++;}
                    fclose(file);

                    scoresize = i;

                    sort(array_scores, array_scores+scoresize);

                    Rank = upper_bound(array_scores, array_scores+scoresize, score) - array_scores;
                    Rank = scoresize - Rank +1;
                }

                glClearColor( 0.8, 0.8, 0.8, 0.8); // COLOR BACKGROUND

                glColor3f(1,1,1); // line
                glBegin(GL_POLYGON);
                glVertex2f(48.5,0); // x, y
                glVertex2f(51.5,0); // x, y
                glVertex2f(51.5,100); // x, y
                glVertex2f(48.5,100); // x, y
                glEnd();


                for(int i=0;i<50;i++)
                {
                    drawSquares_2(sq[i],sq[i].cx,sq[i].cy);
                }

                sqDelta++;

                if(sq[step].cy+sqDelta >102)
                {
                    step++;
                }

                check();

                glColor3f(1,1,1); //
                sprintf(str_score,"Score : %d",score);
                printSome(str_score,5,90);
                glEnd();


                if (abs(sqDelta)>maxY) sqUp=!sqUp ;
                if (sqUp) sqDelta+=1; //else sqDelta-=1;}

            }

            else if(status==2)
            {
                glColor3f(1.0,1.0,1.0);
                printSome("HIGHSCORES",40,90);
                glEnd();


                if(fileFlag)
                {
                    int i = 0;

                    FILE *scores = fopen("C:\\Users\\Ahmed Khairi\\Desktop\\Scores.txt","r");
                    while(~fscanf(scores,"%d",&array_scores[i])){i++;}
                    fclose(scores);

                    scoresize = i;

                    sort(array_scores, array_scores+scoresize, greater<int>());

                    fileFlag = 0;
                }

                glColor3f(1.0,1.0,1.0);
                sprintf(H_SCO,"  %d",array_scores[0]);
                glColor3f(1,1,1);
                printSome("1 -",5,70);
                printSome(H_SCO,10,70);
                sprintf(H_SCO,"  %d",array_scores[1]);
                printSome("2 -",5,60);
                printSome(H_SCO,10,60);
                sprintf(H_SCO,"  %d",array_scores[2]);
                printSome("3 -",5,50);
                printSome(H_SCO,10,50);
                sprintf(H_SCO,"  %d",array_scores[3]);
                printSome("4 -",5,40);
                printSome(H_SCO,10,40);
                sprintf(H_SCO,"  %d",array_scores[4]);
                printSome("5 -",5,30);
                printSome(H_SCO,10,30);
            }

            else if(status==3)
            {
                exit(1);
            }

            else if(status==4)
            {
                 glClearColor(0.74,0.69,0.86,0); // COLOR BACKGROUND
                 glColor3f(1,1,1);
                 sprintf(strr,"Your Score : %d",score);
                 printSome(strr,31,65);
                 sprintf(ra,"Your Rank is : %d",Rank);
                 printSome(ra,31,35);
                 glEnd();
            }


        glEnd();
        glutSwapBuffers();
        glFlush();
    }


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition (logWidth, logHeight);
    glutInitWindowSize (phyWidth , phyHeight);
    glutCreateWindow ("Ma+h Her0");
    init2D(0.0,0.0,0.0);
    glutDisplayFunc(display);
    Timer(0);
     glutKeyboardFunc(Keyboard);
    glutSpecialFunc(speacial_keyboard);
    glutMouseFunc(mouseClick);
    glutMainLoop();

}
