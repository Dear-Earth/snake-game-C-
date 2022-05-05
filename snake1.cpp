#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width=60;
const int height=20;
int x,y,fruitX,fruitY,score=0;// head position variable,fruit position variable,score:
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;// dir hold the direction of snake:
void Setup(){
    gameOver=false;
    dir=STOP;//snake stop initially until we not give any command:
    x=width/2;
    y=height/2;//snakehead is centered on the map;
    fruitX=rand()%width;
    fruitY=rand()%height;// random position of fruit in 20by20; 
    score=0;

}
void Draw(){
    system("CLS");// to clear the screen:
    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;

    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j <width; j++)
        {
            if (j==0)
                cout<<"#";
            if (i==y && j==x)
                cout<<"O";
            else if(i==fruitY &&j==fruitX)
                cout<<"F";
            else{
                bool print=false;
                for (int k = 0; k <nTail; k++)
                {
                  
                    if (tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                    
                    
                    
                }
                if (!print)
                    cout<<" ";
                    
            
                  
            }    
            if(j==width-1)
                cout<<"#";
            
        }
        cout<<endl;
        
    }
    



    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;
    cout<<"Score:"<<score<<endl;
}
void Input(){
    // we include conio.h because we have to include functions synchronous- they don't block the program: its a function for getting a character from a console window; _Kbhit means if keyboard key press:
    if(_kbhit()){
        // if keyboard character key is pressed it return a positive number i.e ASCII value of character:
        // if no key is pressed then it return 0 zero;
        switch(_getch()){
            case 'a':
                 dir=LEFT;
                 break;
            case 'd':
                 dir=RIGHT;
                 break;
            case 'w':
                 dir=UP;
                 break;
            case 's':
                 dir=DOWN;
                 break;
            case 'x':
                 gameOver=true;
                 break;

                
        }
    }
}
void Logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for (int i = 1; i <nTail; i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    // if(x>width || x<0 || y>height || y<0)
    //     gameOver=true;
    if(x>=width) x=0; else if(x<0) x=width-1;
    if(y>=height) y=0; else if(y<0) y=height-1;
    for (int i = 0; i <nTail; i++)
         if (tailX[i]==x && tailY[i]==y)
            gameOver=true;
    
    
    
    
        
    if(x==fruitX && y== fruitY){
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;
        nTail++;

    }
}

int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(10);

    }
    return 0;
}