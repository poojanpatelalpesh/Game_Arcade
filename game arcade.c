#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#include<windows.h>
#include<math.h>
#include<string.h>

#define row 25
#define col 50
#define maxlen (row-2)*(col-2)

// ANSI color codes for console output
#define ANSI_COLOR_RESET        "\x1b[0m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_WHITE        "\x1b[37m"
#define ANSI_COLOR_BRIGHT_RED   "\x1b[91m"
#define ANSI_COLOR_BRIGHT_GREEN "\x1b[92m"
#define ANSI_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_COLOR_BRIGHT_BLUE  "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN   "\x1b[96m"
#define ANSI_COLOR_BOLD         "\x1b[1m"
#define ANSI_COLOR_UNDERLINE    "\x1b[4m"

char bx='-',by='|',point='*',ch;
int lenx=25,leny=13;
int i,j,k,game=1,count=0;
int key,blockx,blocky,x=3,y=2,error=0;
char arr[13][25];
int sol[13][25];

int snakegames = 1;
int score = 0;
char board[row][col];
char snakekey;
int la=3;

typedef struct food{
    int x;
    int y;
    int cons;
}Food;

typedef struct snake{
    int x;
    int y;
}Snake;

typedef struct snakepart{
    int len;
    Snake snakepiece[maxlen];
}Snakepart;

Food food;
Snakepart snake;
Snake buffer;


void err(char **ques,int **ptr){
    for(int a=0;a<9;a++){
        for (int b=0;b<9;b++){
            if(*(ques[a]+b)!='_'){
                if(*(ques[a]+b)!=(char)(*(ptr[a]+b)+48)){
                error++;
                }
            }
        }
    }
}

void solution(){
    
    for(i=1;i<=lenx;i++){
                printf("%c",bx);
            }
            printf("\n");

    for( j=2;j<=leny-1;j++){
        if(j==5 || j==9){
            for(i=1;i<=lenx;i++){
                printf("%c",bx);
            }
            printf("\n");
        }
        else{
        for( k=1;k<=lenx;k++){
            if(k%2==0){
                printf(" ");
            }
            else if(k==3 || k==5 || k==7 || k==11 || k==13 || k==15||k==19 || k==21 || k==23){
                        printf("%d",sol[j][k]);
            }
            else if(k==1|| k==9 || k==17 || k==25){
                printf("%c",by);
            }
        }
        printf("\n");
        }
    }
    for (i=1;i<=lenx;i++){
            printf("%c",bx);
        
        } 
       
    game=0;
}

void generatenew(int ** a){
    int b = rand()%3;
    int c = rand()%3;
    if(b==c){
        if(b==0){b++;}
        else{b--;}
    }
    int m;
    int*temp=(int*)malloc(9*sizeof(int));
    for(m=0;m<9;m++){
        *(temp+m) = *(a[b]+m);
        *(a[b]+m) = *(a[c]+m);
        *(a[c]+m) = *(temp+m);
        }
     b = rand()%3;
     c = rand()%3;
    if(b==c){
        if(b==0){b++;}
        else{b--;}
    }
        for(m=0;m<9;m++){
            *(temp+m) = *(a[m]+b);
            *(a[m]+b) = *(a[m]+c);
            *(a[m]+c) = *(temp+m);
        }
     b = 3+rand()%3;
     c = 3+rand()%3;
    if(b==c){
        if(b==3){b++;}
        else{b--;}
    }
        for(m=0;m<9;m++){
        *(temp+m) = *(a[b]+m);
        *(a[b]+m) = *(a[c]+m);
        *(a[c]+m) = *(temp+m);
        }
        b = 3+rand()%3;
     c = 3+rand()%3;
    if(b==c){
        if(b==3){b++;}
        else{b--;}
    }
         for(m=0;m<9;m++){
            *(temp+m) = *(a[m]+b);
            *(a[m]+b) = *(a[m]+c);
            *(a[m]+c) = *(temp+m);
        }
     b = 6+rand()%3;
     c = 6+rand()%3;
    if(b==c){
        if(b==6){b++;}
        else{b--;}
    }
         for(m=0;m<9;m++){
        *(temp+m) = *(a[b]+m);
        *(a[b]+m) = *(a[c]+m);
        *(a[c]+m) = *(temp+m);
        }
        b = 6+rand()%3;
     c = 6+rand()%3;
    if(b==c){
        if(b==6){b++;}
        else{b--;}
    }
         for(m=0;m<9;m++){
            *(temp+m) = *(a[m]+b);
            *(a[m]+b) = *(a[m]+c);
            *(a[m]+c) = *(temp+m);
        }
        free(temp);
        
}

void generatespaces(int ** a,char ** b){
    int w;
    char x='-',y='>';
    printf(ANSI_COLOR_CYAN ANSI_COLOR_BOLD"Enter difficulty level:\n");
    printf("1-Easy\n2-Medium\n3-Hard\n"ANSI_COLOR_RESET);
    printf("%c%c",x,y);
    scanf("%d",&w);
    int r,t,f,g,h4,h1,h2,h3,p,q;
    char**temp=(char**)malloc(9*sizeof(char*));
    
    for(r=0;r<9;r++){
        temp[r]=(char*)malloc(9*sizeof(char));
    }
    
    for(r=0;r<9;r++){
        for(t=0;t<9;t++){
            *(temp[r]+t)='_';
        }
    }
   
    if(w==1){
        f=rand()%9;
        for(r=0;r<9;r++){
            if(r==f){
                continue;
            }
            else{
                g=rand()%2;
                if(g==0){
                    h1 = rand()%9;
                    h2 = rand()%9;
                    while(h2==h1){
                        h2 = rand()%9;
                    }
                    h3 = rand()%9;
                    while(h3==h1 || h3==h2){
                        h3=rand()%9;
                    }
                   *(temp[h1]+r) = (char)(*(a[h1]+r)+48);
                   *(temp[h2]+r) = (char)(*(a[h2]+r)+48);
                   *(temp[h3]+r) = (char)(*(a[h3]+r)+48);

                }
                if(g==1){
                    h1 = rand()%9;
                    h2 = rand()%9;
                    while(h2==h1){
                        h2 = rand()%9;
                    }
                    h3 = rand()%9;
                    while(h3==h1 || h3==h2){
                        h3=rand()%9;
                }
                    h4 = rand()%9;
                    while(h4==h1||h4==h2||h4==h3){
                        h4=rand()%9;
                    }
                     *(temp[h1]+r) = (char)(*(a[h1]+r)+48);
                   *(temp[h2]+r) = (char)(*(a[h2]+r)+48);
                   *(temp[h3]+r) = (char)(*(a[h3]+r)+48);
                   *(temp[h4]+r) = (char)(*(a[h4]+r)+48);    
            }
        }
    }
  }
 
  else if(w==2){
      f=rand()%9;
      for(r=0;r<9;r++){
          if(r==f){
              continue;
          }
          else{
               h1 = rand()%9;
               h2 = rand()%9;
               while(h2==h1){
                        h2 = rand()%9;
                    }
               h3 = rand()%9;
               while(h3==h1 || h3==h2){
                        h3=rand()%9;
                    }
                   *(temp[h1]+r) = (char)(*(a[h1]+r)+48);
                   *(temp[h2]+r) = (char)(*(a[h2]+r)+48);
                   *(temp[h3]+r) = (char)(*(a[h3]+r)+48);

          }
      }
  }
   else{
       f=rand()%9;
       p=rand()%9;
       while(p==f){
           p=rand()%9;
       }
       q=rand()%9;
       while(q==p||q==f){
           q=rand()%9;
       }
       for(r=0;r<9;r++){
           if(r==f){
               continue;
           }
           else if(r==p||r==q){
               h1=rand()%9;
               h2=rand()%9;
               while(h2==h1){
                   h2=rand()%9;
               }
                *(temp[h1]+r) = (char)(*(a[h1]+r)+48);
                *(temp[h2]+r) = (char)(*(a[h2]+r)+48);
           }
           else{
               h1 = rand()%9;
               h2 = rand()%9;
               while(h2==h1){
                        h2 = rand()%9;
                    }
               h3 = rand()%9;
               while(h3==h1 || h3==h2){
                        h3=rand()%9;
                    }
                   *(temp[h1]+r) = (char)(*(a[h1]+r)+48);
                   *(temp[h2]+r) = (char)(*(a[h2]+r)+48);
                   *(temp[h3]+r) = (char)(*(a[h3]+r)+48);

           }
       }
   }
   
   for(r=0;r<9;r++){
       for(t=0;t<9;t++){
           *(b[r]+t) = *(temp[r]+t);
       }
   }
   free(temp);
   
}    

void value(char ** ques,int ** ptr){
    for (int u=0;u<9;u++){
        x=3;
        for (int v=0;v<3;v++){
            if(x==3 || x==5 || x==7){
                arr[y][x]= *(ques[u]+v);
                x=x+2;
            }
        }    
        x=11;
        for (int v=3;v<6;v++){    
             if(x==11 || x==13 || x==15){
                arr[y][x]= *(ques[u]+v);
                x=x+2;
            }
        }
        x=19;
        for (int v=6;v<9;v++){    
            if(x==19 || x==21 || x==23){
                arr[y][x]= *(ques[u]+v);
                x=x+2;
            }   
        }
        y++;
        if(y==5 || y==9 || y==13){  
            y=y+1;
        }
        
    }
    
    x=3,y=2;
    
    for (int u=0;u<9;u++){
        x=3;
        for (int v=0;v<3;v++){
            if(x==3 || x==5 || x==7){
                sol[y][x]= *(ptr[u]+v);
                x=x+2;
            }
        }    
        x=11;
        for (int v=3;v<6;v++){    
             if(x==11 || x==13 || x==15){
                sol[y][x]= *(ptr[u]+v);
                x=x+2;
            }
        }
        x=19;
        for (int v=6;v<9;v++){    
            if(x==19 || x==21 || x==23){
                sol[y][x]= *(ptr[u]+v);
                x=x+2;
            }   
        }
        y++;
        if(y==5 || y==9 || y==13){  
            y=y+1;
        }
        else{
            y=y;
        }
    }
    x=3,y=2;
}

void boundary(){
    system("cls");
    for(i=1;i<=lenx;i++){
                printf("%c",bx);
            }
            printf("\n");

    for( j=2;j<=leny-1;j++){
        if(j==5 || j==9){
            for(i=1;i<=lenx;i++){
                printf("%c",bx);
            }
            printf("\n");
        }
        else{
        for( k=1;k<=lenx;k++){
            if(k%2==0){
                printf(" ");
            }
            else if(k==3 || k==5 || k==7 || k==11 || k==13 || k==15||k==19 || k==21 || k==23){
                if(k==blockx && j==blocky){
                    if(arr[j][k]!='_'){
                        printf("%c",arr[j][k]);
                    
                    }
                    else if(arr[j][k]=='_'){
                       printf("%c",point);     
                    }
                }
                else{
                printf("%c",arr[j][k]);
                }
                
            }
            else if(k==1|| k==9 || k==17 || k==25){
                printf("%c",by);
            }
        }
        printf("\n");
        }
    }
        
    for (i=1;i<=lenx;i++){
            printf("%c",bx);
        
        }     
        printf("\n");  
    printf(ANSI_COLOR_RED"\nPress A For Left : D = Right : W For Up : S For Down\n ");

    printf(ANSI_COLOR_MAGENTA"\n\nPress X to exit!\n");  
    printf("Press Z for solution!\n"ANSI_COLOR_RESET)  ;
}

void pointer(){
    blockx=x;
    blocky=y;
}

void input(){
    
        switch (getch()) {
	
		case 'a': key=1;
		       break;
		case 'd': key=2;
			 break;
		case 'w': key=3;
			break;
        case 's': key=4 ;
            break;   
		case 'n':key=5;
            break;
        case 'x': key=6;
            break;    
        case 'z':key=7;
            break;    
        default:key=0;
		break;
	    }
	} 

void logic(){

    switch(key){
		case 1:if (x>3 && x<lenx){
                 if(x==11|| x==19) x-=4;
                 else x-=2;
                }
		break;
		case 2:if (x>1 && x<lenx-2){ 
                 if(x==7 || x==15) x+=4;
                else  x+=2;
                }   
		break;
		case 3:if (y>2 && y<leny) {
                if(y== 6 || y== 10) y-=2;            
               else y-=1;
            }
		break;
        case 4:if (y>1 && y<leny-1){
               if(y== 4 || y== 8) y+=2;     
                else  y+=1;
             }
		break;
        case 5: ch=getch();
                if(arr[y][x]=='_'){
                    if(ch<='9' && ch>='0'){
                    arr[y][x]=ch;
                     }   
                }
        break;
        case 6: game=0;
            break;
        case 7:  solution();
            break;  
		default:x=x ;
                y=y;
		break;
	    }
	
    }



void sudokugame(){
    system("cls");
    game=1,count=0;
     key=0,x=3,y=2,error=0;

    int q;
     int ** ptr;
    int a;
    char guess,lol;
    ptr=(int**)malloc(9*sizeof(int*));
    char ** ques=(char**)malloc(9*sizeof(char*));
    for(a=0;a<9;a++){
        ptr[a]=(int*)malloc(9*sizeof(int));
        ques[a]=(char*)malloc(9*sizeof(char));
    }
    int sudoku[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    for(a=0;a<9;a++){
        ptr[a]=sudoku[a];
    }
       
    srand(time(NULL));

    for(a=0;a<1;a++){
    generatenew(ptr);
    }
    
    generatespaces(ptr,ques);
    value(ques,ptr);
    
    for( q=0;game!=0 ;q++){
        pointer();
        boundary();
        input();
        logic();
    } 
    q=0;
    for(a=0;a<3;a++){
      *(ques[a]+0)= arr[a+2][3];
      *(ques[a]+1)= arr[a+2][5];
      *(ques[a]+2)= arr[a+2][7];
      *(ques[a]+3)= arr[a+2][11];
      *(ques[a]+4)= arr[a+2][13];
      *(ques[a]+5)= arr[a+2][15];
      *(ques[a]+6)= arr[a+2][19];
      *(ques[a]+7)= arr[a+2][21];
      *(ques[a]+8)= arr[a+2][23];
    }
    for(a=3;a<6;a++){
      *(ques[a]+0)= arr[a+3][3];
      *(ques[a]+1)= arr[a+3][5];
      *(ques[a]+2)= arr[a+3][7];
      *(ques[a]+3)= arr[a+3][11];
      *(ques[a]+4)= arr[a+3][13];
      *(ques[a]+5)= arr[a+3][15];
      *(ques[a]+6)= arr[a+3][19];
      *(ques[a]+7)= arr[a+3][21];
      *(ques[a]+8)= arr[a+3][23];
    }
    for(a=6;a<9;a++){
      *(ques[a]+0)= arr[a+4][3];
      *(ques[a]+1)= arr[a+4][5];
      *(ques[a]+2)= arr[a+4][7];
      *(ques[a]+3)= arr[a+4][11];
      *(ques[a]+4)= arr[a+4][13];
      *(ques[a]+5)= arr[a+4][15];
      *(ques[a]+6)= arr[a+4][19];
      *(ques[a]+7)= arr[a+4][21];
      *(ques[a]+8)= arr[a+4][23];
    }
    
    err(ques,ptr);
    printf("\nNo. Of Errors:%d",error);
    free(ptr);
    free(ques);
    
}



int arr2048[4][4]={0};
// Function to generate random numbers on the board
void randomgeneration(int grr[4][4]){
    int i,j;
    for(int k=0;k<2;k++){
    do{
        i=rand()%4;
        j=rand()%4;

    }while(grr[i][j]!=0);
    grr[i][j]=2;
    }
}

// Function to generate a random number after each move
void randomaftermove(int grr[4][4]){
    int i,j;
    
    do{
        i=rand()%4;
        j=rand()%4;

    }while(grr[i][j]!=0);
    grr[i][j]=2;
    
}

// Function to print the game board
void printmatrix(int grr[4][4]) {
    printf(ANSI_COLOR_BOLD ANSI_COLOR_BRIGHT_YELLOW"\n========== 2048 Game Board ==========\n\n"ANSI_COLOR_RESET);

    for (int i = 0; i < 4; i++) {
        printf("+------+------+------+------+\n|");
        for (int j = 0; j < 4; j++) {
            if (grr[i][j] == 0) {
                printf(ANSI_COLOR_BLUE "      " ANSI_COLOR_RESET "|");
            } else {
                switch (grr[i][j]) {
                    case 2:
                        printf(ANSI_COLOR_RED " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 4:
                        printf(ANSI_COLOR_GREEN " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 8:
                        printf(ANSI_COLOR_YELLOW " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 16:
                        printf(ANSI_COLOR_BLUE " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 32:
                        printf(ANSI_COLOR_MAGENTA " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 64:
                        printf(ANSI_COLOR_CYAN " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 128:
                        printf(ANSI_COLOR_BRIGHT_RED " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 256:
                        printf(ANSI_COLOR_BRIGHT_GREEN " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 512:
                        printf(ANSI_COLOR_BRIGHT_YELLOW " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 1024:
                        printf(ANSI_COLOR_BRIGHT_BLUE " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    case 2048:
                        printf(ANSI_COLOR_BRIGHT_MAGENTA " %-4d " ANSI_COLOR_RESET "|", grr[i][j]);
                        break;
                    default:
                        printf(" %-4d |", grr[i][j]);
                        break;
                }
            }
        }
        printf("\n");
    }
    printf("+------+------+------+------+\n\n");
}


// Function to move tiles to the left
void moveleft2048(int grr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grr[i][j] == 0) {
                for (int k = j + 1; k < 4; k++) {
                    if (grr[i][k] != 0) {
                        grr[i][j] = grr[i][k];
                        grr[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (grr[i][j] == grr[i][j + 1]) {
                grr[i][j] *= 2;
                grr[i][j + 1] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grr[i][j] == 0) {
                for (int k = j + 1; k < 4; k++) {
                    if (grr[i][k] != 0) {
                        grr[i][j] = grr[i][k];
                        grr[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    randomaftermove(grr);
}


// Function to move tiles to the up
void moveup2048(int grr[4][4]) {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (grr[i][j] == 0) {
                for (int k = i + 1; k < 4; k++) {
                    if (grr[k][j] != 0) {
                        grr[i][j] = grr[k][j];
                        grr[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (grr[i][j] == grr[i + 1][j]) {
                grr[i][j] *= 2;
                grr[i + 1][j] = 0;
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (grr[i][j] == 0) {
                for (int k = i + 1; k < 4; k++) {
                    if (grr[k][j] != 0) {
                        grr[i][j] = grr[k][j];
                        grr[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    randomaftermove(grr);
}

// Function to move tiles to the down
void movedown2048(int grr[4][4]) {
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i >= 0; i--) {
            if (grr[i][j] == 0) {
                for (int k = i - 1; k >= 0; k--) {
                    if (grr[k][j] != 0) {
                        grr[i][j] = grr[k][j];
                        grr[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            if (grr[i][j] == grr[i - 1][j]) {
                grr[i][j] *= 2;
                grr[i - 1][j] = 0;
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 3; i >= 0; i--) {
            if (grr[i][j] == 0) {
                for (int k = i - 1; k >= 0; k--) {
                    if (grr[k][j] != 0) {
                        grr[i][j] = grr[k][j];
                        grr[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    randomaftermove(grr);
}


// Function to move tiles to the right
void moveright2048(int grr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            if (grr[i][j] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (grr[i][k] != 0) {
                        grr[i][j] = grr[i][k];
                        grr[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (grr[i][j] == grr[i][j - 1]) {
                grr[i][j] *= 2;
                grr[i][j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            if (grr[i][j] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (grr[i][k] != 0) {
                        grr[i][j] = grr[i][k];
                        grr[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    randomaftermove(grr);
}

// Function to check if the player has won the game
int check(int grr[4][4]){
    for(int i=0;i<4;i++){ 
        for(int j=0;j<4;j++){
          if(grr[i][j]==2048){
            system("cls");
            printf("YOU WON THE GAME \n");
            printf("Congratulation\n");
            return 1;
            }  
        }
    }
    return 0;
}

// Function to check if the game can continue
int cancontinue(int grr[4][4]) {
   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grr[i][j] == 0) {
                return 1; 
            }
        }
    }

    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((j + 1 < 4 && grr[i][j] == grr[i][j + 1]) || 
                (i + 1 < 4 && grr[i][j] == grr[i + 1][j])) {
                return 1; 
            }
        }
    }

    return 0; 
}


//function to play game by pressing appropriate input
void play(int arr[4][4]){
    printf(ANSI_COLOR_RED">* CONTROLS\n"); 
	printf(" FOR MOVES:- 'W','S','A','D'\n"ANSI_COLOR_RESET); 
    char key;
    int validInput = 0; 

    do {
        key=getch();
        if (key == 'W' || key == 'w' || key == 'S' || key == 's' ||
            key == 'A' || key == 'a' || key == 'D' || key == 'd') {
            validInput = 1;  
        } else {
            printf(ANSI_COLOR_RED"Enter Valid key\n"ANSI_COLOR_RESET);
        }
       
    } while (!validInput);

    if (key == 'W' || key == 'w') {
        system("cls");
        moveup2048(arr);
        printmatrix(arr);
    } else if (key == 'S' || key == 's') {
        system("cls");
        movedown2048(arr);
        printmatrix(arr);
    } else if (key == 'A' || key == 'a') {
        system("cls");
        moveleft2048(arr);
        printmatrix(arr);
    } else if (key == 'D' || key == 'd') {
        system("cls");
        moveright2048(arr);
        printmatrix(arr);
    }
}

void game2048(){
    system("cls");
    
    srand(time(NULL));
     int q;
    printf(ANSI_COLOR_BOLD ANSI_COLOR_BRIGHT_YELLOW"===============2048==============\n"); 
    printf(ANSI_COLOR_BOLD ANSI_COLOR_BRIGHT_YELLOW"WELCOME TO PUZZLE 2048\n\n"ANSI_COLOR_RESET); 
    printf(ANSI_COLOR_RED">* CONTROLS\n"); 
    printf(ANSI_COLOR_RED" FOR MOVES:- 'W','S','A','D'\n"ANSI_COLOR_RESET); 
    
    randomgeneration(arr2048);
    
    printf(ANSI_COLOR_BRIGHT_GREEN"\nPress any key to start game\n"ANSI_COLOR_RESET);
    scanf("%d",&q);
    
    system("cls");
    printmatrix(arr2048); 

    do{
        play(arr2048);
        if(check(arr2048)==1){
            return ;
        }
    } while(cancontinue(arr2048)==1);
    Sleep(1000);
    if(cancontinue(arr2048)!=1){
        printf(ANSI_COLOR_BRIGHT_YELLOW"Game Over!! Try again...\n"ANSI_COLOR_RESET);
    }
    
}

void clear_screen() {
    system("cls");
}

void sleep_ms(int milliseconds) {
    Sleep(milliseconds);
}

int sideselection() {
    srand(time(NULL));
    return 1+(rand()%4);
}

void printmaze(int size, char maze[size][size]) {
    for(int i = 0; i < size; i++) {
        if(i == 0)
            printf("\n\n\n");

        printf("                                                ");

        for(int j = 0; j < size; j++) {
            if(maze[i][j]=='B' || maze[i][j]=='F' || maze[i][j]==' '){
                printf("%c",maze[i][j]);
            }
            else{
             printf("\033[1;36m%c\033[0m", 219);
            }
            fflush(stdout);
            Sleep(10); // Sleep for 100 milliseconds
        }

        printf("\n");
        Sleep(100); // Sleep for 100 milliseconds
    }
}



void print_during_play(int size, char maze[size][size]) {
    for(int i=0; i<size; i++) {
        if(i==0)
        printf("\n\n\n\n");

        printf("                                                ");

        for(int j=0; j<size; j++) {
            if(maze[i][j]=='B' || maze[i][j]=='F' || maze[i][j]==' '){
                printf("%c",maze[i][j]);
            }

            else{
                 printf("\033[1;36m%c\033[0m", 219);
                
            }
             
        }

        printf("\n");
    }
}

void backtracking(int size, char art[size][size], char grr[size][size], int x, int y) {
    int movement = 1+(rand()%4);

    while (grr[x - 1][y - 1] == 'u' || grr[x][y - 1] == 'u' || grr[x + 1][y - 1] == 'u' ||
           grr[x - 1][y] == 'u' || grr[x][y] == 'u' || grr[x + 1][y] == 'u' ||
           grr[x - 1][y + 1] == 'u' || grr[x][y + 1] == 'u' || grr[x + 1][y + 1] == 'u') {
        
        movement=1+(rand()%4);
        
        if (movement == 1) {

            if ((x > 1) && (grr[x - 2][y] == 'u')) {
                
                x--;
                art[x][y] = ' ';
                grr[x][y] = ' ';
                x--;
                grr[x][y] = ' ';
                backtracking(size, art, grr, x, y);
                x += 2;
            }

            else if (grr[x - 2][y] != 'u') {

                grr[x - 1][y] = '#';

            }
        }
        
        else if (movement == 2) {

            if ((x < size - 2) && (grr[x + 2][y] == 'u')) {

                x++;
                art[x][y] = ' ';
                grr[x][y] = ' ';
                x++;
                grr[x][y] = ' ';
                backtracking(size, art, grr, x, y);
                x -= 2;

            }
            
            else if (grr[x + 2][y] != 'u') {

                grr[x + 1][y] = '#';

            }
        }

        else if (movement == 3) {

            if ((y > 1) && (grr[x][y - 2] == 'u')) {

                y--;
                art[x][y] = ' ';
                grr[x][y] = ' ';
                y--;
                grr[x][y] = ' ';
                backtracking(size, art, grr, x, y);
                y += 2;

            }

            else if (grr[x][y - 2] != 'u') {

                grr[x][y - 1] = '#';

            }
        }

        else if(movement == 4) {

            if ((y < size - 2) && (grr[x][y + 2] == 'u')) {

                y++;
                art[x][y] = ' ';
                grr[x][y] = ' ';
                y++;
                grr[x][y] = ' ';
                backtracking(size, art, grr, x, y);
                y -= 2;

            }

            else if (grr[x][y + 2] != 'u') {

                grr[x][y + 1] = '#';

            }
        }
    }
}

void movemazeleft(int size, char maze[size][size]) {
    int position_x, position_y;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'B') {
                position_x = i;
                position_y = j;
            }
        }
    }

    if (position_y > 0 && maze[position_x][position_y - 1] != '#') {
        maze[position_x][position_y] = ' ';
        maze[position_x][position_y - 1] = 'B';
    }
}

void movemazeright(int size, char maze[size][size]) {
    int position_x, position_y;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'B') {
                position_x = i;
                position_y = j;
            }
        }
    }

    if (position_y < size - 1 && maze[position_x][position_y + 1] != '#') {
        maze[position_x][position_y] = ' ';
        maze[position_x][position_y + 1] = 'B';
    }
}

void movemazedown(int size, char maze[size][size]) {
    int position_x, position_y;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'B') {
                position_x = i;
                position_y = j;
            }
        }
    }

    if (position_x < size - 1 && maze[position_x + 1][position_y] != '#') {
        maze[position_x][position_y] = ' ';
        maze[position_x + 1][position_y] = 'B';
    }
}

void movemazeup(int size, char maze[size][size]) {
    int position_x, position_y;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'B') {
                position_x = i;
                position_y = j;
            }
        }
    }

    if (position_x > 0 && maze[position_x - 1][position_y] != '#') {
        maze[position_x][position_y] = ' ';
        maze[position_x - 1][position_y] = 'B';
    }
}

int ending_condition(int size, char maze[size][size]) {
    int position_x, position_y;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'B') {
                position_x = i;
                position_y= j;
            }
        }
    }
    
    if(position_x==(size-2) && position_y==(size-2)){
        return 1;
    }
    return 0;
}

int playmaze(int size, char maze[size][size]) {
    printf(ANSI_COLOR_RED">* CONTROLS\n");
    printf(" FOR MOVES:- 'W','S','A','D'\n"ANSI_COLOR_RESET);
    char key;
    int validInput = 0;
        key=getch();
        if (key == 'W' || key == 'w' || key == 'S' || key == 's' ||
            key == 'A' || key == 'a' || key == 'D' || key == 'd') {
            validInput = 1;
        } else {
            printf(ANSI_COLOR_RED"Enter Valid key\n"ANSI_COLOR_RESET);
        }

    system("cls"); // Clear the screen before printing maze after each move

    if (key == 'A' || key == 'a') {
        movemazeleft(size, maze);
    } else if (key == 'D' || key == 'd') {
        movemazeright(size, maze);
    } else if (key == 'W' || key == 'w') {
        movemazeup(size, maze);
    } else if (key == 'S' || key == 's') {
        movemazedown(size, maze);
    }

    print_during_play(size, maze); // Print the maze after each move

    // Check if the player has reached the finish point
    return ending_condition(size, maze);
}

void wall_org(int size, char maze[size][size]) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(i==0 || i==size-1 || j==0 || j==size-1){
                maze[i][j]='#';
            } else if(j%2==1 && i%2==1){
                maze[i][j]=' ';
            } else{
                maze[i][j]='#';
            }
            if(i==1 && j==1){
                maze[i][j]='B';
            }
            if(i==size-2 && j==size-2){
                maze[i][j]='F';
            }
        }
    }
}

void wall_checking(int size, char grr[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                grr[i][j] = '#';
            } else if(i % 2 == 1 || (i % 2 == 0 && j % 2 == 1)) {
                grr[i][j] = 'u';
            } else {
                grr[i][j] = '#';
            }

            if(i == 1 && j == 1) {
                grr[i][j] = 'B';
            }
        }
    }
}

void generate(int size, char maze[size][size], char grr[size][size]) {
    int x=1;
    int y=1;
    backtracking(size,maze,grr,x,y);
    printmaze(size,maze);
}

void gamemaze(){
    system("cls");
    int size;
    printf(ANSI_COLOR_GREEN ANSI_COLOR_BOLD"Enter the size of Maze: "ANSI_COLOR_RESET);

    do {
        scanf("%d", &size);

        if(size <= 4) {
            printf(ANSI_COLOR_RED"Enter valid size: "ANSI_COLOR_RESET);
            
        }
    } while(size <= 4); //have to manage grid size also

    if(size % 2 == 0) {
        size++;
    }

    char maze[size][size];
    char grr[size][size];
    wall_checking(size, grr);
    wall_org(size, maze);
    generate(size, maze, grr);

    time_t start_time, end_time;
    start_time = time(NULL);

    while(1) {
        if(playmaze(size, maze) == 1) {
            end_time = time(NULL);
            printf(ANSI_COLOR_MAGENTA"\n\nCongratulations! You have completed the maze.\n");
            break;
        }
    }

    double time_taken = difftime(end_time, start_time);
    printf("Time taken: %.2f seconds\n\n"ANSI_COLOR_RESET, time_taken);

    
}


void foodgenerate(){
     do{
            food.x = rand()%row;
            food.y = rand()%col;
            food.cons = 0;
        }while(board[food.x][food.y] != ' ');
        board[food.x][food.y] = 'f';

}

void movesnake(int dx,int dy){
        buffer = snake.snakepiece[snake.len-1];
        for(int i = snake.len-1;i>0;i--){
            snake.snakepiece[i] = snake.snakepiece[i-1];
        }
        snake.snakepiece[0].x += dx;
        snake.snakepiece[0].y += dy;
}

void keyboard(){

    if(kbhit()){
    snakekey = getch();
    switch(snakekey){
        case 'w' : la=1;break;
        case 's' : la=2;break;
        case 'd' : la=3;break;
        case 'a' : la=4;break;
        defualt  : printf("Invalid input...!");keyboard();
    }
    }
    Sleep(30);
    switch(la){
        case 1:movesnake(-1,0);break;
        case 2:movesnake(1,0);break;
        case 3:movesnake(0,1);break;
        case 4:movesnake(0,-1);break;
    }
}

void fillboard(){
    int i;
    int j;
    int k;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            board[i][j] = ' ';
            if(i == 0 || j == 0 || i == row-1 || j == col-1){
                board[i][j] = '#';
            }
            
            else if(i == food.x && j == food.y){
                    board[i][j] = 'f';
            }
            for(k = 0;k<snake.len;k++){
                if(i == snake.snakepiece[k].x && j == snake.snakepiece[k].y){
                    if(k == 0)board[i][j] = '@';
                    else board[i][j] = '*';
                }
            }
        }
    }
}

void print(){
    int colorIndex = 0; // To alternate between green and dark green colors
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] == ' ') {
                printf("\033[1;36m%c\033[0m", 219); // cyan square for empty space
            } else if (board[i][j] == '#') {
                printf("\033[0;32m%c\033[0m", 219); // Dark green square for snake head
                
            } else if (board[i][j] == 'f') {
                printf("\033[1;31m%c\033[0m", 219); // Red square for food
            } else if (board[i][j] == '@') {
               printf("\033[1;34m%c\033[0m", 219); // Blue square for borders
            } else {
                if (colorIndex % 2 == 0) {
                    printf("\033[0;32m%c\033[0m", 219); // Dark green square for odd segments of the snake
                } else {
                    printf("\033[1;32m%c\033[0m", 219); // Light green square for even segments of the snake
                }
                colorIndex++;
            }
        }
        printf("\n");
    }
}


int eatfood(){
    int check = 0;
    if(board[snake.snakepiece[0].x][snake.snakepiece[0].y] == 'f'){
        check = 1;
        score++;
    }
    if(check == 1){
        do{
            food.x = rand()%row;
            food.y = rand()%col;
            food.cons = 1;
        }while(board[food.x][food.y] != ' ');
    }
    board[food.x][food.y] = 'f';
    return check;
}

void increaselen(){

    if(eatfood() == 1){
        snake.len++;
        snake.snakepiece[snake.len-1] = buffer;
    }
}

void gameover(){
if(board[snake.snakepiece[0].x][ snake.snakepiece[0].y] != 'f' && board[snake.snakepiece[0].x][ snake.snakepiece[0].y] != ' ')
    {
        snakegames = 0;
    }
else snakegames = 1;
}

void snakegame(){
     game = 1;
     score = 0;
     board[row][col];
    key;
    int a=3;
    int move = 0;
    snake.len = 1;
    snake.snakepiece[0].x = 2;
    snake.snakepiece[0].y = 2;

    for(move;snakegames == 1;move++){
        system("cls");
        fillboard();
        if(move == 0)foodgenerate();
        print();
        keyboard();
        eatfood();
        increaselen();
        gameover();
        
    }
    printf(ANSI_COLOR_RED"\nGame over!!! \n"ANSI_COLOR_RESET);
    
}

int main(){
    char h='0';
    
    // Print top border
    printf("\033[1;33m                                                                    -----------------\n");
    printf("\033[1;33m                                                                   /                 \\\n");
    printf("\033[1;33m                                                                  |  \033[1;1;36mMy Awesome Games \033[1;33m|\n");
    printf("\033[1;33m                                                                   \\                 /\n");
    printf("\033[1;33m                                                                    -----------------\n\033[0m");
    
    printf("\n\nWhich game do you want to play :  \n\n");
    printf("\033[1;34m\033[3m[A] Maze Runner\n\n");
    printf("[B] Sudoku Solving\n\n");
    printf("[c] Mighty 2048\n\n");
    printf("[D] Snake Game\n\n\033[0m");
    scanf("%c",&h);
    switch(h){
        case 'C':game2048();
              break;
        case 'A':gamemaze();
            break;
        case 'B':sudokugame();
            break;
        case 'D': game=1;
                snakegame();
            break;    
        
    } 
    Sleep(2000);
    system("cls");     
    
    return 0;
}
