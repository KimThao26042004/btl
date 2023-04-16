#include"stlib.h"


int cardNumber=1200;

void deleteEnd(char str[]){
	if(str[strlen(str)-1]=='\n'){
		str[strlen(str)-1]='\0';
	}
}

bool checkingMajor(char major[]) {
    char temp[20];
    FILE* fmajor = fopen("major.txt", "r");

    if (fmajor == NULL) {
        printf("\n\t\t * Loi mo file major.txt!\a");
        sleep(1);
        exit(0);
    }
    
    while (fgets(temp, sizeof(temp), fmajor) != NULL) {
        if (strcmp(temp, major) == 0) {
            fclose(fmajor);
            return true;
        }
    }
    
    fclose(fmajor);
    return false;
}

classUnit enterClass(classUnit c){
	
	do{
		printf("\n\t\t Nhap lop:  ");
		fflush(stdin);
		fgets(c.className,sizeof(c.className),stdin);
		strupr(c.className);
	
		if( !checkingMajor(c.className)){
			printf("\n\t\t Khong tim thay ma nganh %s\a",c.className);
			printf("\n\t\t Hay nhap ma nganh hop le!");
		}
	}while( !checkingMajor(c.className));
	
	do{
		printf("\n\t\t Nhap khoa:  ");
		scanf("%d",&c.course);
		
		if( c.course<1 || c.course>63 ){
			printf("\n\t\t Khoa khong hop le!\a");
			fflush(stdin);
			continue;
		}
	}while( c.course<1 || c.course>63 );	
	
	return c;
}

date timeSet(date d){
	time_t rawtime;
   struct tm *timeinfo;

   time(&rawtime);
   timeinfo = localtime(&rawtime);

   d.day = timeinfo->tm_mday;
   d.month = timeinfo->tm_mon + 1;
   d.year = timeinfo->tm_year + 1900;
   return d;
}

void upperString(char str[]){
	for(int i=0;i<strlen(str);i++){
		if(i==0 || (i>0 && str[i-1]==32)){
			if(str[i]>=97 && str[i]<=122){
				str[i]=str[i]-32;
			}
		} else{
			if(str[i]>=65 && str[i]<=90){
				str[i]=str[i]+32;
			}
		}
	}
}

room chooseRoom(char gender[]){
	
	room roomChoice;
	
	FILE* froom=fopen("roomData.dat","rb");
	if(froom==NULL){
		printf("\n\t\t * Khong the mo file roomData.dat!\a");
		exit(0);
	}
	
	room r[20];
	for(int i=0;i<20;i++){
		fread(&r[i],sizeof(room),1,froom);
	}
	
	fclose(froom);
	
	
	typedef struct rnode{
		room data;
		int index;
		rnode* next;
	}rnode;
	
	rnode* head=NULL;

	int gnum = ( strcmp(gender,"Nam" ) == 0 ) ? 1 : 0 ;
	int count= ( gnum==1 ) ? 14 : 8;

	int num=1;
	for(int i=0;i<20;i++){
		
		if(r[i].gender ==gnum || r[i].gender ==2){
			
			rnode* newNode=(rnode*)malloc(sizeof(rnode));
			newNode->data=r[i];
			newNode->index=num;
			newNode->next=NULL;
		
			if(head==NULL){
				head=newNode;

			} else{
				rnode* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
		
				temp->next=newNode;
			}
			
			num++;
		}
	}
	
	int ch;
	int option =1;
	choose:
	while( ch!= KEY_ENTER ){
		
		printf("\n\t\t\t\t***Chon phong %s***\n\n", gender);
		for(rnode* temp=head; temp!=NULL; temp=temp->next){
			printf("\n\t\t %s Phong %s-%d%s: %d/%d nguoi, phong %s", option==temp->index ?">  ":" ",temp->data.range,temp->data.floor,temp->data.roomNumber,temp->data.num,temp->data.max,(temp->data.num<temp->data.max)?"con trong":"da day");
		}
		
		ch=getch();
		switch(ch){
			
			case KEY_UP:
				if(option>1){
					option--;
				}
				break;
				
			case KEY_DOWN:
				if(option<count){
					option++;
				}
				break;
			
			default:
				break;
		}
		
		
		system("cls");
	}
	
	for(rnode* temp=head;temp!=NULL;temp=temp->next){
		if( temp->index==option ){
			if(temp->data.num < temp->data.max){
				roomChoice=temp->data;
				return roomChoice;
			} else {
				printf("\n\t\t Phong da day! Vui long chon phong khac\a");
				sleep(1);
				system("cls");
				goto choose;
			}
		}
	}
	
	while(head != NULL){
		rnode* temp=head;
		head=head->next;
		free(temp);
	}
}

bool checkingName(char name[]){
	
	for(int i=0;i<strlen(name);i++){
		
		if( isdigit(name[i])) return false;
		if( ispunct(name[i])) return false;
	}
	
	return true;
}

bool checkingID1(char ID[]){
	
    FILE* fID = fopen("student.dat", "rb");

    if (fID == NULL) {
        printf("\n\t\t * Loi mo file student.dat!\a");
        sleep(1);
        exit(0);
    }
    
    
    student st;
    while (fread(&st, sizeof(st),1, fID) == 1) {
    	if( strcmp(ID,st.ID) == 0 ){
    		fclose(fID);
    		return false;
		}
    }
    
    return true;
}

bool checkingID2(char ID[]){
	for(int i=0;i<strlen(ID);i++){
		if( ispunct(ID[i]) || ID[i]=='\0' || ID[i]=='\n'){
			return false;
		}
	}
	
	return true;
}

bool checkingBirthday(date d){

	if (d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year < 1 || d.year > 2023) {
        return false;
    }
    if (d.month == 2) {
        if (d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)) {
            if (d.day > 29) {
                return false;
            }
        } else {
            if (d.day > 28) {
                return false;
            }
        }
    } else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        if (d.day > 30) {
            return false;
        }
    }
	
	
	date nd=timeSet(nd);
	int temp=nd.year-d.year;
	if(temp>65){
		return false;
	}
	
	return true;
}

date enterDate(date d){
	do{
		printf("\n\t\t Nhap ngay thang nam sinh (dd/mm/yyyy):  ");
		scanf("%d%d%d",&d.day,&d.month,&d.year);
		
		if( !checkingBirthday(d) ){
			printf("\n\t\t Hay nhap ngay sinh hop le!\a");
			fflush(stdin);
			continue;
		}
		
	}while( !checkingBirthday(d) );
	
	return d;
}

bool checkingPnumber(char pnumber[]){
	for(int i=0;i<strlen(pnumber);i++){
		if( !isdigit(pnumber[i])) return false;
	}
	
	return true;
}

void updateRoom(room a , char title[]){
	
	int i = ( strcmp(title,"Add") == 0) ? 1 : -1;
	
	FILE* froom=fopen("roomData.dat","rb");
	
	if(froom == NULL){
		printf("\n\t\t * Khong the mo file roomData.dat!\a");
		return;
	}
	
	room r[20];
	for(int i=0;i<20;i++){
		fread(&r[i], sizeof(r[i]), 1, froom);
	}
	
	for(int i=0;i<20;i++){
		if( strcmp(a.range,r[i].range) == 0 && a.floor == r[i].floor && strcmp(a.roomNumber,r[i].roomNumber) ==0 ){
			r[i].num= r[i].num + i;
			fclose(froom);
			break;
		}
	}
	
	froom=fopen("roomData.dat","wb");
	for(int i=0;i<20;i++){
		fwrite(&r[i],sizeof(r[i]),1,froom);
	}
	
	fclose(froom);
}

student enterStudent(student st, char title[]){
	
	int temp = ( strcmp(title,"Dang ky noi tru") == 0 ) ? 1 : 0;
	
	char action[4];
	( temp ==1 ) ? strcpy(action, "Add") : strcpy(action, "Sub");
	
	loop:
	printf("\n\t\t\t\t***%s***\n\n", title);
	
	do{
		printf("\n\t\t Nhap ten sinh vien:  ");
		fflush(stdin);
		fgets(st.name,sizeof(st.name),stdin);
		deleteEnd(st.name);
		upperString(st.name);
		
		if( !checkingName(st.name) ){
			printf("\n\t\t Hay nhap ten hop le!\a");
			
		}
	} while( !checkingName(st.name) );
	
	
	do{
		printf("\n\t\t Nhap mssv:  ");
		gets(st.ID);
		
		if( !checkingID1(st.ID) ){
			printf("\n\t\t Ban da dang ky roi!\a");
			sleep(1);
			system("cls");
			goto loop;
		}
		
		if( !checkingID2(st.ID) ){
			printf("\n\t\t Mssv khong hop le!\a");
		}
		
	} while( !checkingID2(st.ID) );
	


	st.cData=enterClass(st.cData);
	
	
	do{
		printf("\n\t\t Gioi tinh:  ");
		scanf("%s",st.gData);
		upperString(st.gData);
		
		if(strcmp(st.gData,"Nam")!=0 && strcmp(st.gData,"Nu")!=0){
			printf("\n\t\t Gioi tinh khong hop le!\a");
		}
	} while(strcmp(st.gData,"Nam")!=0 && strcmp(st.gData,"Nu")!=0);
	getchar();
	
	
	do{
		printf("\n\t\t Nhap so dien thoai:  ");
		fflush(stdin);
		scanf("%s",st.pNumber);
		
		if( !checkingPnumber(st.pNumber) ){
			printf("\n\t\t Hay nhap so dien thoai hop le!\a");
		}
	}while( !checkingPnumber(st.pNumber) );
	
	
	do{
		printf("\n\t\t Nhap ngay thang nam sinh (dd/mm/yyyy):  ");
		scanf("%d%d%d",&st.birthday.day,&st.birthday.month,&st.birthday.year);
		
		if( !checkingBirthday(st.birthday) ){
			printf("\n\t\t Hay nhap ngay sinh hop le!\a");
			fflush(stdin);
			continue;
		}
	}while( !checkingBirthday(st.birthday) );
	
	
	cardNumber++;
	st.cardNum=cardNumber;
	
	
	system("cls");
	st.rData=chooseRoom(st.gData);
	st.dormitoryFee=st.rData.price;
	
	
	st.dateRegister=timeSet(st.dateRegister);
	
	
	system("cls");
//	printf("\n\t\t\t\t***Phieu dang ky noi tru***\n\n");
	printStudent(st,10,5,85,15);
	
	int ch;
	
	box(20,25,30,2);
	box(70,25,20,2);
	gotoXY(21,26);
	printf("An ENTER de xac nhan dang ky");
	gotoXY(71,26);
	printf("An ESC de quay lai");
	
	confirm:
	ch=getch();
	switch(ch){
		case KEY_ENTER:
			updateRoom(st.rData, action);
			return st;
			break;
		case KEY_ESC:
			system("cls");
			goto loop;
			break;
		default:
			goto confirm;
			break;
	}
	
} 

void printDate(date d){
	
	if(d.day<10 && d.month<10)
		printf("0%d / 0%d / %d",d.day,d.month,d.year);
	
	else if(d.day<10 && d.month>10)	
		printf("0%d / %d / %d",d.day,d.month,d.year);
	
	else if(d.day>10 && d.month<10)
		printf("%d / 0%d / %d",d.day,d.month,d.year);
	
	else printf("%d / %d / %d",d.day,d.month,d.year);
	
}

void printClass(classUnit c){
	printf("\n Lop %s khoa %d",c.className,c.course);
}


void printStudent(student st, int x, int y, int w, int h){
	box(10,5,90,16);
	gotoXY(x+((90-28)/2),y+1);
	printf("___PHIEU DANG KY NOI TRU___");
	for(int i=3 ;i<=13; i+=2){
		gotoXY(x+2,y+i);
		switch(i){
			case 3:
				printf("Ten: %-50s",st.name);
				break;
			case 5:
				printf("Lop: %s",st.cData.className);
				break;
			case 7:
				printf("Khoa: %d",st.cData.course);
				break;
			case 9:
				printf("Ngay sinh: ");
				printDate(st.birthday);
				break;
			case 11:
				printf("So the: %d",st.cardNum);
				break;		
		}
		gotoXY(x+50,y+i);
			switch(i){
				case 3:
					printf("Gioi tinh: %-5s",st.gData);
					break;
				case 7:
					printf("MSSV: %-20s",st.ID);
					break;
				case 9:
					printf("So dien thoai: %-20s",st.pNumber);
					break;
				case 11:
					printf("Phong: %s-%d%s",st.rData.range,st.rData.floor,st.rData.roomNumber);
					break;
			}
	}
	gotoXY(w-25,y+13);
	printf("Ngay dang ky noi tru: ");
	printDate(st.dateRegister);
	
	gotoXY(w-10,y+15);
	printf("Le phi: %ld Vnd/thang",st.dormitoryFee);
}

