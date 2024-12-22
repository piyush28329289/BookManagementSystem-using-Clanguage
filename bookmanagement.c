#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book_management_system {
	int book_id;
	char book_name[20];
	char author_name[20];
	char catagory[10];
	double price;
	float rating;
} Book;
void Add_book(Book*,int,int);
void Display_allbook(Book*,int);
void Remove_book(Book*,int*);
void Serch_book(Book*,int);
void Author_book(Book*,int);
void book_catagories(Book*,int);
void Update_bookdata(Book*,int);
void sort_bookdata(Book*,int);
void swap(Book*,int,int);
char* default_book(Book*,int );

void main() {
	int size1;
	int size2;
	int size3;
	int choice,bookid;
	Book* bookaray = NULL;
	Book* bookaray2 = NULL;
	do {
		printf("===================\n");
		printf("1).add book\n" );
		printf("2).display allbook\n");
		printf("3).remove book\n");
		printf("4).serch book\n");
		printf("5).author book\n");
		printf("6).serch by catagories of book\n");
		printf("7).update data of book\n");
		printf("8).serch by rating and price of book\n");
		printf("0).exit\n");
		printf("enter choice for the above options=>");
		scanf("%d",&choice);
		printf("===================\n");

		switch(choice) {

			case 1:
				printf("**************add newbook****************\n");
				if(bookaray == NULL) {
					printf("\n How many book you want to store=> ");
					scanf("%d",&size1);
					size3=size1;
					bookaray=(Book*)malloc(sizeof(Book)*size1);
				} else {
					printf("\n How many book you want to store=> ");
					scanf("%d",&size2);
					size3=size3+size2;
					bookaray2=(Book*)realloc(bookaray,sizeof(Book)*size3);
					bookaray=bookaray2;
				}
				Add_book(bookaray,size3,(bookaray==bookaray2 ? size3 - size2 :0));

				printf("%d",size3);
				break;
			case 2:
				printf("**************display all book****************\n");
				Display_allbook(bookaray,size3);
				break;
			case 3:
				printf("**************remove book*****************\n");
				Remove_book(bookaray,&size3);
				break;
			case 4:
				printf("**************serch book******************\n");
				Serch_book(bookaray,size3);
				break;
			case 5:
				printf("**************authors book****************\n");
				Author_book(bookaray,size3);
				break;
			case 6:
				printf("**************book catagories************\n");
				book_catagories(bookaray,size3);
				break;
			case 7:
				printf("**************update book****************\n");
				Update_bookdata(bookaray,size3);
				break;
			case 8:
				printf("**************sort book****************\n");
				sort_bookdata(bookaray,size3);
				break;

		}
	} while(choice!=0);

	free(bookaray);
	free(bookaray2);
}

//function def.

void Add_book(Book* bookaray,int size,int start) {
	printf("===========================\n");
	int bid;
	for(int i=start; i<size; i++) {
		printf("enter book id=>");
		scanf("%d",&bid);
		int flag =0;
		for(int j=0; j<size; j++) {
			if(bookaray[j].book_id==bid) {
				flag=1;
				break;
			}
		}

		while(flag==1) {
			printf("id is alredy exist enter new id=>");
			scanf("%d",&bid);
			flag=0;

			for(int j=0; j<size; j++) {

				if(bookaray[j].book_id==bid) {
					flag=1;
					break;
				}
			}
		}
		bookaray[i].book_id=bid;
		fflush(stdin);
		printf("enter book name=>");
		gets(bookaray[i].book_name);
		fflush(stdin);
		printf("enter author name=>");
		fflush(stdin);
		gets(bookaray[i].author_name);
		printf("enter catagories=>");
		gets(bookaray[i].catagory);
		printf("enter price=>");
		scanf("%lf=>",&bookaray[i].price);
		printf("enter rating=>");
		scanf("%f=>",&bookaray[i].rating);
		printf("===========================\n");
	}
}

void Display_allbook(Book* bookaray,int size3) {

	printf("===========================\n");
	for(int i=0; i<size3; i++) {
		printf("------------------------------\n");
		printf("\tbook_id=>%d\n",bookaray[i].book_id);
		printf("\tbook_name=>%s\n",bookaray[i].book_name);
		printf("\tauthoe_name=>%s\n",bookaray[i].author_name);
		printf("\tcatagory=>%s\n",bookaray[i].catagory);
		printf("\tprice=>%lf\n",bookaray[i].price);
		printf("\trating *=>%f\n",bookaray[i].rating);
		printf("------------------------------\n");
	}
	printf("===========================\n");
}

void Remove_book(Book* bookaray, int* size3) {
	printf("===========================\n");
	int id;
	printf("enter book id you want to delete=>\n");
	scanf("%d",&id);
	int found=0;
	for(int i=0 ; i< *size3; i++) {
		if(bookaray[i].book_id == id) {
			found=1;
			for(int j=i; j<*size3-1; j++) {
				bookaray[j]=bookaray[j+1];
			}
			(*size3)--;
			break;
		}
	}
	if(found == 0) {
		printf("invalid id!!!\n");
	}
	printf("===========================\n");
}

void Serch_book(Book* bookaray,int size3) {
	printf("===========================\n");
	int id;
	char bookname[20];
	int ch;
	printf("if you want to serch by id type 1=>\n");
	printf("if you want to serch by book name type 2=>\n");

	scanf("%d",&ch);
	if(ch==1) {
		printf("enter book id=>");
		scanf("%d",&id);
		int flag=0;
		for(int i=0; i<size3; i++) {
			if(bookaray[i].book_id==id) {
				flag++;
				printf("===================================\n");
				printf("author name=> %s\n",bookaray[i].author_name);
				printf("book name=> %s\n",bookaray[i].book_name);
				printf("book catogary=> %s\n",bookaray[i].catagory);
				printf("price=> %lf\n",bookaray[i].price);
				printf("rating=> %f\n",bookaray[i].rating);
				printf("===================================\n");
			}
		}

	} else {
		printf("enter bookname");
		scanf("%s",&bookname);
		int flag=0;
		for(int i=0; i<size3; i++) {
			flag++;
			if(strcmp(bookaray[i].book_name,bookname)==0) {
				printf("book id=> %d\n",bookaray[i].book_id);
				printf("author name=> %s\n",bookaray[i].author_name);
				printf("book name=> %s\n",bookaray[i].book_name);
				printf("book catogary=> %s\n",bookaray[i].catagory);
				printf("price=>%lf\n",bookaray[i].price);
				printf("rating=>%f\n",bookaray[i].rating);
			}
		}
	}
}

void Author_book(Book* bookaray,int size3) {
	printf("===================================\n");
	char author_name[20];
	printf("enter author name=>");
	scanf("%s",author_name);
	int flag=0;
	for (int i=0; i<size3; i++) {
		if(strcmp(bookaray[i].author_name,author_name)==0) {
			flag ++;
			printf("book id=> %d\n",bookaray[i].book_id);
			printf("author name=> %s\n",bookaray[i].author_name);
			printf("book name=> %s\n",bookaray[i].book_name);
			printf("book catogary=> %s\n",bookaray[i].catagory);
			printf("price=>%lf\n",bookaray[i].price);
			printf("rating=>%f\n",bookaray[i].rating);
			printf("------------------------------------\n");

		}
		if(flag=0) {
			printf("author not found!!\n");
		}

		printf("===================================\n");
	}
}

void book_catagories(Book* bookaray,int size3) {
	printf("===================================\n");
	char catagories[10];
	printf("enter catagories you want to serch");
	scanf("%s",catagories);
	int flag=0;
	for(int i=0; i<size3; i++) {
		flag++;
		if(strcmp(bookaray[i].catagory,catagories)==0) {
			printf("book id=> %d\n",bookaray[i].book_id);
			printf("author name=> %s\n",bookaray[i].author_name);
			printf("book name=> %s\n",bookaray[i].book_name);
			printf("book catogary=> %s\n",bookaray[i].catagory);
			printf("price=> %lf\n",bookaray[i].price);
			printf("rating=> %f\n",bookaray[i].rating);

		}
		if(flag==0) {
			printf("invalid catagory!!\n");
		}

	}



	printf("===================================\n");
}

void Update_bookdata(Book* bookaray, int size3) {

	int a;
	printf("for price update press=> 1 \n");
	printf("for ratings update press=> 2 \n");
	scanf("%d",&a);
	int id;
	printf("enter id of book you want to update =>");
	scanf("%d",&id);


	if(a==1) {
		for(int i=0; i<size3; i++) {
			if(bookaray[i].book_id==id) {
				double newprice;
				printf("enter new price=>");
				scanf("%d",&newprice);
				bookaray[i].price=newprice;
			}
		}
	} else {
		for(int i=0; i<size3; i++) {

			if(bookaray[i].book_id==id) {

				float newrating;
				printf("enter new rating=>");
				scanf("%f",&newrating);
				bookaray[i].rating=newrating;
			}
		}
	}
}

void sort_bookdata(Book* bookaray,int size3) {

	printf("if you want to sort by price enter 1=>\n");
	printf("if you want to sort by rating enter 2=>\n");
	int a;
	scanf("%d",&a);
	printf("%d",size3);
	if(a==1) {
		printf("hear the list of books price highest to lowest");
		for(int i=0 ; i<size3 ; i++) {
			for (int j=0; j<size3-1; j++) {
				if (bookaray[j].price < bookaray[j+1].price) {
					swap(bookaray,j,j+1);
				}
			}
		}
	} else {
		printf("here the list of books rating highest to lowest");

		for(int i=0 ; i<size3; i++) {
			for (int j=0; j<size3-1; j++) {
				if (bookaray[j].rating < bookaray[j+1].rating) {
					swap(bookaray,j,j+1);
				}
			}
		}
	}
	Display_allbook(bookaray,size3);
}

void swap(Book* bookaray,int a,int b) {
	printf("%d  %d",a,b);
	Book temp;
	temp=bookaray[a];
	bookaray[a]=bookaray[b];
	bookaray[b]=temp;
}










