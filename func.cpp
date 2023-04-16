#include"func.h"

void pause(){
	printf("\n\n\t\t Nhan phim bat ky de tiep tuc hoac ESC de thoat!");
	int ch=getch();
	
	if( ch==KEY_ESC )
		exit(0);
	else {
		system("cls");
	}
}

int makeMenu(int num , char title[],char op[][50]){
	int ch;
	int option=0;
	while(ch!= KEY_ENTER){
		
		printf("\n\t\t%s",title);
		for(int i=0;i<num;i++){
			printf("\n\t\t %s %s",option==i?"> ":" ",op[i]);
		}
		
		ch=getch();
		switch(ch){
			
			case KEY_UP:
			 	if(option>0){
			 		option--;
				}
				else option = num; 
				break;
				
			case KEY_DOWN:
				if(option<num){
					option++;
				}
				else option = 0; 
				break;
				
			default:
				break;
		}
		
		system("cls");
	}
	
	return option+1;
}

void changeStudentInfo(){
	
	
	char ID[20];
	change:
	printf("\n\t\t\t\t***Thay doi thong tin***\n\n");
	printf("\n\t\t Nhap mssv:  ");
//	gets(ID);
	scanf("%s",ID);
		
	if( !checkingID2(ID) ){
		
		printf("\n\t\t Mssv khong hop le!\a");
		sleep(1);
		system("cls");
		goto change;
		
	}
	
	
	list* l=(list*)malloc(sizeof(list));
	creatList(l);
	l=readFromFile(l);
	
	
	node* temp=l->head;
	while( temp != NULL ){
		if( strcmp( temp->data.ID,ID ) == 0){
			system("cls");
			temp->data=enterStudent(temp->data, "Thay doi thong tin");
			writeToFile(l);
			printf("\n\t\t Thay doi thong tin thanh cong!\a");
			return;
		}
	}
	
	printf("\n\t\t Khong tim thay sinh vien!\a");
}


void deleteRegister(){
	
	
	char ID[20];
	dele:
	printf("\n\t\t\t\t***Huy dang ky noi tru***\n\n");

	printf("\n\t\t Nhap mssv:  ");
//	gets(ID);
	scanf("%s",ID);
		
	if( !checkingID2(ID) ){
		printf("\n\t\t Mssv khong hop le!\a");
		sleep(1);
		system("cls");
		goto dele;
	
		
	}
	
	
	list* l=(list*)malloc(sizeof(list));
	creatList(l);
	l=readFromFile(l);
	
	
	node* temp=l->head;
	node* prev=NULL;
	while (temp != NULL) {
        if ( strcmp(temp->data.ID,ID) == 0 ) {
        	
        	printStudent(temp->data,10,5,85,15); 	
			
			char op[][50]={
				"Dong y",
				"Quay lai"
			};
			int selection=makeMenu(2,"\n\n\tXac nhan xoa sinh vien?",op);
			switch (selection){
				case 1:
					break;
				case 2:
					goto dele;
					break;
			}
			
            if (prev == NULL) {
                
                l->head = temp->next;
            } else {
                
                prev->next = temp->next;
            }
            
            free(temp);
            return;
        }
        
        prev = temp;
        temp = temp->next;
    }
	
	printf("\n\t\t Khong tim thay sinh vien!\a");
}

/*

void searching(){
	
	char day[][20]{ "D30","D60","D62","7T" };
	
	char D30[][20]={ "D30-001", "D30-002"};
	
	char D60[][20]={ "D60-001", "D60-001"};
	
	char D62[][20]={ "D62-001", "D62-002"};
	
	char D7T[][20]={ "D7T-001", "D7T-002", 
				   	 "D7T-101", "D7T-102", 
					 "D7T-201","D7T-202", 
					 "D7T-301", "D7T-302", 
					 "D7T-401", "D7T-402", 
					 "D7T-501", "D7T-502", 
					 "D7T-601","D7T-602"
					 };
	
	
	int index;
	char op[][20]={" Sinh vien","Phong" };
	int selection=makeMenu(2,"Ban muon tra cuu",op);
	switch(selection){
		
		case 1:
			int selection2 =makeMenu(4,"Chon day",day);
			switch (selection2){
				
				case 1:
					int selection3=makeMenu(2,"Chon phong",D30);
					switch(selection3){
						case 1:
							index=0;
							break;
						case 2:
							index=1;
							break;
					}
					break;
						
				case 2:
					int selection4=makeMenu(2,"Chon phong",D60);
					switch(selection4){
						case 1:
							index=2;
							break;
						case 2:
							index=3;
							break;
					}
					break;
							
				case 3:
					int selection5=makeMenu(2,"Chon phong",D62);
					switch(selection5){
						case 1:
							index=4;
							break;
						case 2:
							index=5;
							break;
					}
					break;
						
				case 4:
					int selection6=makeMenu(14,"Chon phong",D7T);
					switch(selection6){
						case 1:
							index=6;
							break;
						case 2:
							index=7;
							break;
						case 3:
							index=8;
							break;
						case 4:
							index=9;
							break;
						case 5:
							index=10;
							break;
						case 6:
							index=11;
							break;
						case 7:
							index=12;
							break;
						case 8:
							index=13;
							break;
						case 9:
							index=14;
							break;
						case 10:
							index=15;
							break;
						case 11:
							index=16;
							break;
						case 12:
							index=17;
							break;
						case 13:
							index=18;
							break;
						case 14:
							index=19;
							break;
					}
					break;
						
				room r[20];
				FILE* froom=fopen("roomData.dat","rb");
				for(int i=0;i<20;i++){
					fread(&r[i],sizeof(r[i]),1,froom);
				}
				fclose;
				printf("\n\t\t Phong %s-%d%s: %d/%d nguoi, phong %s",r[index].range,r[index].floor,r[index].roomNumber,r[index].num,r[index].max,( r[index].num < r[index].max)?"con trong":"da day");
				break;
			}
			break;
			
			
		case 2:
			char ID[20];
			search:
			printf("\n\t\tNhap mssv can tra cuu\n\t\tMssv:  ");
			gets(ID);
			if( !checkingID2(ID) ){
				printf("\n\t\t Mssv khong hop le!\a");
				sleep(1);
				system("cls");
				goto search;
			}
			
			list* l=(list*)malloc(sizeof(list));
			creatList(l);
			l=readFromFile(l);	
			node* temp=l->head;
			while( temp != NULL ){
				if( strcmp( temp->data.ID,ID ) == 0){
					printStudent(temp->data);
					return;
				}
			}
			printf("\n\t\t Khong tim thay sinh vien!\a");
			break;	
	}
}

*/


void searchingRoom(){
	
	
	char op2[][50]={
			 		 "D30-001", "D30-002",
				   	 "D60-001", "D60-001",
					 "D62-001", "D62-002",
					 "D7T-001", "D7T-002", 
				   	 "D7T-101", "D7T-102", 
					 "D7T-201","D7T-202", 
					 "D7T-301", "D7T-302", 
					 "D7T-401", "D7T-402", 
					 "D7T-501", "D7T-502", 
					 "D7T-601","D7T-602"
					 };
					 
	
	room r[20];
	FILE* froom=fopen("roomData.dat","rb");
	for(int i=0;i<20;i++){
		fread(&r[i],sizeof(r[i]),1,froom);
	}
	fclose;
	
	
	int index = makeMenu(20,"\t\t***Tra cuu phong\n\n",op2);
		printf("\n\t\t Phong %s-%d%s: %d/%d nguoi, phong %s",r[index].range,
			r[index].floor,r[index].roomNumber,r[index].num,r[index].max,
			( r[index].num < r[index].max)?"con trong":"da day");
	
}




void searchingStudent(){
	
	char ID[20];
	search:
	printf("\n\t\t\t\t***Tra cuu sinh vien***\n\n");
	printf("\n\t\t Nhap mssv:  ");
//	gets(ID);
	scanf("%s",ID);

	if( !checkingID2(ID) ){
		printf("\n\t\t Mssv khong hop le!\a");
		sleep(1);
		system("cls");
		goto search;
	}
	
	
	list* l=(list*)malloc(sizeof(list));
	creatList(l);
	l=readFromFile(l);	
	
	node* temp=l->head;
	while( temp != NULL ){
		if( strcmp( temp->data.ID,ID ) == 0){
			printStudent(temp->data,10,5,85,15);
			printf("\n\n"); 
			return;
		}
	}
	
	printf("\n\t\t Khong tim thay sinh vien!\a");
	
}


void searching(){
	
	char op[][50]={" Sinh vien","Phong" };
	
	int selection=makeMenu(2,"\t\t***Menu tra cuu***\n\n",op);
	switch(selection){
		
		case 1:
			searchingStudent();
			break;
			
		case 2:
			searchingRoom();
			break;	
	}
	
}


void managementMenu(int x, int y, int w, int h){
//	
//	char op[][50]={
//		"Sua doi thong tin sinh vien noi tru",
//		"Huy dang ky noi tru",
//		"Tra cuu thong tin",
//		"Thoat"
//	};
	
//	int ch = 0;
//   int option = 1;
//   while (ch != 13) {
//   		printf("\n\t\t\t\t***Ban quan li***\n\n");
//        printf("\n\t\t %s Sua doi thong tin sinh vien noi tru", option == 1 ? "> " : " ");
//        printf("\n\t\t %s Huy dang ky noi tru", option == 2 ? "> " : " ");
//        printf("\n\t\t %s Tra cuu thong tin", option == 3 ? "> " : " ");
//        printf("\n\t\t %s Thoat", option == 4 ? "> " : " ");
//        ch = getch();
//        switch(ch) {
//            case KEY_UP:
//            	if (option > 1) {
//                option--;
//            	}
//            	break;
//            case KEY_DOWN:
//            	if (option < 4) {
//                option++;
//            	}
//            	break;
//            default:
//            	break;
//      	}
//      	
//		system("cls");
//   }
   
//   int option=makeMenu(4,"\t\t***Ban quan li***\n\n",op);
//   
//   switch(option){
//   		case 1:
//   			changeStudentInfo();
//   			break;
//   		case 2:
//   			deleteRegister();
//   			break;
//   		case 3:
//   			searching();
//   			break;
//   		case 4:
//   			return;
//   }
	

   	int ch;
	int option=1;
	while(ch!=13){
		nBox_4(50,6,43,4,4); 
		if(option == 1){
			gotoXY(x-10,y+2);
			printf("%s",">>>"); 
		}
		else if(option == 2){
			gotoXY(x-10,y+6);
			printf("%s",">>>"); 
		} 
		else if(option == 3){
			gotoXY(x-10,y+10);
			printf("%s",">>>"); 
		} 
		else{
			gotoXY(x-10,y+14);
			printf("%s",">>>"); 
		} 
			
		ch=getch();
		
		switch(ch){
			
			case KEY_UP:
				if(option>1){
					option--;
				}
				else option = 4; 
				break; 
			case KEY_DOWN:
				if(option<4){
					option++;
				}
				else option = 1; 
			default:
				break;
		}
		
		system("cls");
	}
	  
   switch(option){
   		case 1:
   			changeStudentInfo();
   			break;
   		case 2:
   			deleteRegister();
   			break;
   		case 3:
   			searching();
   			break;
   		case 4:
   			return;
   }
	
}

list* readFromFile(list* l){
    FILE *f = fopen("student.dat", "rb");
    if (f == NULL){
        printf("\n\t\t * Loi mo file student.dat!\a");
        exit(0);
    }
    
    student st;
    while (fread( &st, sizeof(st), 1, f) == 1){
    	node* newNode=makeNode(st);
        pushBack(l,newNode);
    }
    
    fclose(f);
    return l;
}

void writeToFile(list* l){
	FILE* fnode=fopen("student.dat","wb");
	if(fnode==NULL){
		printf("\n\t\t * Loi mo file student.dat!\a");
		sleep(1);
		exit(0);
	}
	
	node* temp=l->head;
    while ( temp != NULL){
        fwrite( &(temp->data), sizeof(temp->data), 1, fnode);
        temp=temp->next;
    }
    
    fclose(fnode);
}


void boardingRegister(){

	list* l=(list*)malloc(sizeof(list));
	creatList(l);
	l=readFromFile(l);
	student st=enterStudent(st, "Dang ky noi tru");
	node* newNode=makeNode(st);
	pushBack(l,newNode);
	writeToFile(l);
	printf("\n\t\t\tDang ky noi tru thanh cong!\a");
	free(l);
}

void SET_COLOR(int color)
{
	WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gotoXY(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
} 

void box(int x, int y, int w, int h){
	if(w<=1 || h<=1) 
		return;
	SET_COLOR(6);
	for(int ix=x; ix<=x+w; ix++){
		gotoXY(ix,y);
		printf("%c",char(171));  
		gotoXY(ix,y+h);
		printf("%c",char(187)); 
	}
	for(int iy=y; iy<=y+h; iy++){
		gotoXY(x,iy);
		printf("%c",char(94));
		gotoXY(x+w,iy);
		printf("%c",char(94));
	}
	gotoXY(x,y); printf("%c",char(139));
	gotoXY(x+w,y); printf("%c", char(139));
	gotoXY(x,y+h); printf("%c", char(155));
	gotoXY(x+w,y+h); printf("%c", char(155));
} 

void nBox_4(int x, int y, int w, int h, int sl){
	for(int i=0; i<sl; i++){
		box(x,y+(i*4),w,h); // i=0 => (x,y), i=1 => (x,y+4)
	}
	SET_COLOR(7);	
	for(int j=2; j<=14; j+=4){
		gotoXY(x+1,y+j);
		switch(j){
			case 2:
				printf("\tSua doi thong tin sinh vien");
				break;
			case 6:
				printf("\t\tHuy dang ky noi tru");
				break;
			case 10:
				printf("\t\tTra cuu thong tin");
				break;
			case 14:
				printf("\t\t\tThoat");
				break; 
		}
	}
}
//
//void nBox_2(int x, int y, int w, int h, int sl){
//	for(int i=0; i<sl; i++){
//		box(x,y+(i*4),w,h); // i=0 => (x,y), i=1 => (x,y+4)
//	}
//	SET_COLOR(7);	
//	for(int j=2; j<=6; j+=4){
//		gotoXY(x+1,y+j);
//		switch(j){
//			case 2:
//				printf("\tDang ky noi tru");
//				break;
//			case 6:
//				printf("\t\tThoat");
//				break;
//		}
//	}
//}
