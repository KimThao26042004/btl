#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<conio.h>
#include"stlib.h"
#include"li.h"
#include"acc.h"
#include"func.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void comeBackMenu();
void managementMenu(int x, int y, int w, int h);
void studentMenu();
void start();

int main(){
	start();
	return 0;
}

void logInMenu(){
//	int ch;
//	int option=1;
//	
//	while(ch!=KEY_ENTER){
//		printf("\n\t\t\t\t***Dang nhap***\n\n");
//		printf("\n\t\t %s Dang ky",option==1?"> ":" ");
//		printf("\n\t\t %s Dang nhap",option==2?"> ":" ");
//		printf("\n\t\t %s Thoat",option==3?"> ":" ");
//		
//		ch=getch();
//		
//		switch(ch){
//			
//			case KEY_UP:
//				if(option>1){
//					option--;
//				}
//				break;
//				
//			case KEY_DOWN:
//				if(option<3){
//					option++;
//				}
//				break;
//			default:
//				break;
//		}
//		
//		system("cls");
//	}

	char op[][50]={ "Dang ky", "Dang nhap","Quay lai"};
	logIn:
	int option=makeMenu(3,"\t\t***Dang nhap***\n\n",op);
	
	int num;
	
	switch(option){
		case 1:
			signUp();
			break;
		case 2:
//			num=logIn();
			if( !logIn() ){
				goto logIn;
				break;
			} else {
				system("cls");
				managementMenu(50,6,30,4);
			}
			break;
//		default :
//			start();
//			break;
	}
}

//void studentMenu(){
	
//	int ch;
//	int option=1;
//	
//	while ( ch!=KEY_ENTER){
//		
//		printf("\n\t\t\t\t***Menu sinh vien***\n\n");
//		printf("\n\t\t %s Dang ky noi tru",option==1?"> ":" ");
//		printf("\n\t\t %s Quay lai",option==2?"> ":" ");
//		
//		ch=getch();
//		switch(ch){
//			
//			case KEY_UP:
//				if(option>1){
//					option--;
//				}
//				break;
//				
//			case KEY_DOWN:
//				if(option<2){
//					option++;
//				}
//				break;
//			default:
//				break;
//				
//		}
//		
//		system("cls");
//	}
void studentMenu(){
	
	char op[][50]= { "Dang ky noi tru","Quay lai"};
	
	int option=makeMenu(2,"\t\t***Menu sinh vien***\n\n",op);
	
	switch(option){
		
		case 1:
			boardingRegister();
			break;
		case 2:
			
			start();
			break;
			
	}
}

void start(){
//	 int ch = 0;
//   int option = 1;
//   while (ch != KEY_ENTER) {
//      printf("\n\t\t\t\tBan la ai?\n\n");
//      printf("\n\t\t %s Ban quan li", option == 1 ? "> " : " ");
//      printf("\n\t\t %s Sinh vien", option == 2 ? "> " : " ");
//      ch = getch();
//      switch(ch) {
//      	
//         case KEY_UP:
//            if (option > 1) {
//               option--;
//            }
//            break;
//            
//         case KEY_DOWN:
//            if (option < 3) {
//               option++;
//            }
//            break;
//         default:
//            break;
//            
//      }
//      
//      system("cls");
//   }
   
   char op[][50]={ "Ban quan li","Sinh vien"};
   
   int option=makeMenu(2,"\t\tBan la ai?\n\n",op);
   
   switch(option){
   		case 1:
   			logInMenu();
   			break;
   		case 2:
   			studentMenu();
   			break;
   }
}

