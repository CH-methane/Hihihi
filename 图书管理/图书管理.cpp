#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct book{
	char num[9],name[18],writer[23],pub[22],mon[10],typ[7],tota[12],now[12],al[12];
	struct book *next;};
struct reader{
	char rnum[9],rname[18],cla[7],rstu[9],rtyp[7],ral[14],rga[5];
	struct reader *rnext;};
struct borrow{
	char bnum1[9],bname[18],bmon[10],bnum2[9];
    struct borrow *bnext;};
void m1(struct book *a,char g[],struct reader *r,struct borrow *bo);
void m2(struct book *a,char g[],struct reader *r,struct borrow *bo);
void m3(struct book *a,char g[],struct reader *r,struct borrow *bo);
void m4(struct book *a,char g[],struct reader *r,struct borrow *bo);
void ad(struct book *a,char g[],struct reader *r,struct borrow *bo);
void search(struct book *b,int n,char g[],struct reader *r,struct borrow *bo);
void B(struct book *b,struct reader *r,struct borrow *bo);
void m1(struct book *a,char g[],struct reader *r,struct borrow *bo){
	FILE *ps;
	char pass[12];
	int choice;
	printf("\n\n1----书籍信息管理\n2----读者信息管理\n3----借阅信息管理\n4----修改密码\n5----退出\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:m2(a,g,r,bo);
		case 2:m3(a,g,r,bo);
		case 3:m4(a,g,r,bo);
		case 4:printf("请输入密码:");
		       scanf("%s",pass);
			   if(!strcmp(pass,g)){
				   ps=fopen("password.text","w");
				   printf("请输入新密码:");
			       scanf("%s",g);
				   fprintf(ps,"%s",g);
				   fclose(ps);
				   printf("修改成功\n\n");
				   m1(a,g,r,bo);}
			   else{
				   printf("密码错误\n");
				   B(a,r,bo);}
        case 5:B(a,r,bo);
		default:printf("无效的选择\n");
				m1(a,g,r,bo);}}
void m2(struct book *a,char g[],struct reader *r,struct borrow *bo){
	struct book *u,*p;
	int choice;
	char name[18];
	u=a;
	printf("书籍信息系统\n1----信息一览\n2----添加信息\n3----修改信息\n4----删除信息\n5----返回\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:search(a,2,g,r,bo);
		case 2:ad(a,g,r,bo);
		case 3:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   printf("1----确认          2----返回\n\n");
					   scanf("%d",&choice);
	                   switch(choice){
			              case 1:printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n%s",u->num);
                                 scanf("%s%s%s%s%s%s%s%s",u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
								 printf("修改成功\n\n");
						  case 2:m2(a,g,r,bo);
						  default:printf("无效的选择\n");
							      m2(a,g,r,bo);}}
				   u=u->next;}
			   printf("无符合条件项\n");
			   m2(a,g,r,bo);
		case 4:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   printf("1----确认          2----返回\n\n");
					   scanf("%d",&choice);
					   switch(choice){
			              case 1:p=a;
							     if(!strcmp(name,a->name)){
									 a=a->next;
								     free(p);
									 p=a;}
								 else {while(strcmp(name,p->next->name))
									       p=p->next;
								       p->next=u->next;
									   free(u);}
								 printf("删除成功\n\n");
						  case 2:m2(a,g,r,bo);
						  default:printf("无效的选择\n");
							      m2(a,g,r,bo);}}
				   	   u=u->next;}
			   printf("无符合条件项\n");
			   m2(a,g,r,bo);
		case 5:m1(a,g,r,bo);					
		default:printf("无效的选择\n");
			    m2(a,g,r,bo);}}
void m3(struct book *a,char g[],struct reader *r,struct borrow *bo){
	struct reader *u,*add,*p,*h2;
	int choice;
	char rnum[9];
	FILE *f2;
	h2=u=r;
	printf("读者信息系统\n1----信息一览\n2----添加信息\n3----修改信息\n4----删除信息\n5----返回\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:printf(" 借书证号              姓名   班级     学号   类别    已借阅本数 挂失\n");
	           while(u!=NULL){
		           printf("%9s%18s%7s%9s%7s%14s%5s\n",u->rnum,u->rname,u->cla,u->rstu,u->rtyp,u->ral,u->rga);
		           u=u->rnext;}
			       m3(a,g,r,bo);
		case 2:printf("1----输入      2----返回\n\n\n");
	           scanf("%d",&choice);
	           switch(choice){
	               case 1:while(1){
					          add=(struct reader *)malloc(sizeof(struct reader));
	                          while(!u->rnext==NULL)
					              u=u->rnext;			   	 
	                              itoa(atol(u->rnum)+1,add->rnum,10);
	                              printf(" 借书证号              姓名   班级     学号   类别    已借阅本数 挂失\n%s",add->rnum);
                                  scanf("%s%s%s%s%s%s",add->rname,add->cla,add->rstu,add->rtyp,add->ral,add->rga);
                                  u->rnext=add;
	                              add->rnext=NULL;
				                  printf("添加成功\n\n");
	                              printf("1----继续输入          2----返回\n\n");
	                              scanf("%d",&choice);
	                              switch(choice){
				                      case 1:break;
									  case 2:f2=fopen("reader.text","w");
										     while(h2!=NULL){
											     fprintf(f2,"%9s%18s%7s%9s%7s%14s%5s\n",h2->rnum,h2->rname,h2->cla,h2->rstu,h2->rtyp,h2->ral,h2->rga);
											     h2=h2->rnext;}
										     fclose(f2);
										     m3(a,g,r,bo);
									  default:printf("无效的选择\n");
							                  m3(a,g,r,bo);}}
		          case 2:m3(a,g,r,bo);
				  default:printf("无效的选择\n");
						  m3(a,g,r,bo);}
	   case 3:printf("请输入借书证号:");
			   scanf("%s",rnum);
			   while(u!=NULL){
				   if(!strcmp(rnum,u->rnum)){
					   printf(" 借书证号              姓名   班级     学号   类别    已借阅本数 挂失\n");
					   printf("%9s%18s%7s%9s%7s%14s%5s\n",u->rnum,u->rname,u->cla,u->rstu,u->rtyp,u->ral,u->rga);
					   printf("1----确认          2----返回\n\n");
					   scanf("%d",&choice);
	                   switch(choice){
			              case 1:printf(" 借书证号              姓名   班级     学号   类别    已借阅本数 挂失\n%s",u->rnum);
                                 scanf("%s%s%s%s%s%s",u->rname,u->cla,u->rstu,u->rtyp,u->ral,u->rga);
								 printf("修改成功\n\n");
								 f2=fopen("reader.text","w");
			                     while(h2!=NULL){
									 fprintf(f2,"%9s%18s%7s%9s%7s%14s%5s\n",h2->rnum,h2->rname,h2->cla,h2->rstu,h2->rtyp,h2->ral,h2->rga);
									 h2=h2->rnext;}
								 fclose(f2);
						  case 2:m3(a,g,r,bo);
						  default:printf("无效的选择\n");
				                  m3(a,g,r,bo);}}
				   u=u->rnext;}
			   printf("无符合条件项\n");
			   m3(a,g,r,bo);
	    case 4:printf("请输入借书证号:");
			   scanf("%s",rnum);
			   while(u!=NULL){
				   if(!strcmp(rnum,u->rnum)){
					   printf(" 借书证号              姓名   班级     学号   类别    已借阅本数 挂失\n");
					   printf("%9s%18s%7s%9s%7s%14s%5s\n",u->rnum,u->rname,u->cla,u->rstu,u->rtyp,u->ral,u->rga);
					   printf("1----确认          2----返回\n\n");
					   scanf("%d",&choice);
					   switch(choice){
			              case 1:p=h2;
							     if(!strcmp(rnum,h2->rnum)){
									 h2=h2->rnext;
								     free(p);
									 p=h2;}
								 else {while(strcmp(rnum,p->rnext->rnum))
									       p=p->rnext;
								       p->rnext=u->rnext;
									   free(u);}
								 printf("删除成功\n\n");
								 f2=fopen("reader.text","w");
			                     while(h2!=NULL){
									 fprintf(f2,"%9s%18s%7s%9s%7s%14s%5s\n",h2->rnum,h2->rname,h2->cla,h2->rstu,h2->rtyp,h2->ral,h2->rga);
									 h2=h2->rnext;}
								 fclose(f2);
						  case 2:m3(a,g,r,bo);
						  default:printf("无效的选择\n");
							      m3(a,g,r,bo);}}
				   	   u=u->rnext;}
			   printf("无符合条件项\n");
			   m3(a,g,r,bo);
		case 5:m1(a,g,r,bo);
		default:printf("无效的选择\n");
				m3(a,g,r,bo);}}
void m4(struct book *a,char g[],struct reader *r,struct borrow *bo){
	struct borrow *o;
	int choice;
	o=bo;
	printf("借阅信息系统\n1----信息一览\n2----返回\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:while(o!=NULL){
		           printf("     编号              书名      金额 借书证号\n");
			       printf("%9s%18s%10s%9s\n",o->bnum1,o->bname,o->bmon,o->bnum2);
				   o=o->bnext;}
		case 2:m1(a,g,r,bo);
		default:printf("无效的选择\n");
			    m4(a,g,r,bo);}}
void ad(struct book *a,char g[],struct reader *r,struct borrow *bo){
	struct book *add,*u;
	int choice;
	printf("1----输入      2----返回\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:	u=a;
	            add=(struct book *)malloc(sizeof(struct book));
	            while(!u->next==NULL)
					u=u->next;			   	 
	            itoa(atol(u->num)+1,add->num,10);
	            printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n%s",add->num);
                scanf("%s%s%s%s%s%s%s%s",add->name,add->writer,add->pub,add->mon,add->typ,add->tota,add->now,add->al);
                u->next=add;
	            add->next=NULL;
				printf("添加成功\n\n");
	            printf("1----继续输入          2----返回\n\n");
	            scanf("%d",&choice);
	            switch(choice){
				    case 1:ad(a,g,r,bo);
		            case 2:m2(a,g,r,bo);
					default:printf("无效的选择\n");
							ad(a,g,r,bo);}
		case 2:m2(a,g,r,bo);
		default:printf("无效的选择\n");
				ad(a,g,r,bo);}}
void search(struct book *b,int n,char g[],struct reader *r,struct borrow *bo){
	struct book *u;
	int choice;
	u=b;
	printf("1----书籍\n2----期刊\n3----报刊\n4----全部\n5----返回\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
			   while(u!=NULL){
			       if(!strcmp("书籍",u->typ)){
				       printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);}
			       u=u->next;}
			   search(b,n,g,r,bo);
		case 2:printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
			   while(u!=NULL){
			       if(!strcmp("期刊",u->typ)){
				       printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);}
			       u=u->next;}
			   search(b,n,g,r,bo);
		case 3:printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
			  while(u!=NULL){
			       if(!strcmp("报刊",u->typ)){
				       printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);}
			       u=u->next;}
			   search(b,n,g,r,bo);
		case 4:printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
			   while(u!=NULL){
				   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
				   u=u->next;}
			   search(b,n,g,r,bo);
		case 5:if(n==1)
				   B(b,r,bo);
			   else
				   m2(b,g,r,bo);
		default:printf("无效的选择\n");
				search(b,n,g,r,bo);}}
void B(struct book *b,struct reader *r,struct borrow *bo){
	FILE *ps,*cl1;
	int choice;
	char pass[12],g[12],name[18],rnum[9];
	struct book *u;
	struct reader *p;
	struct borrow *o,*add;
	ps=fopen("password.text","r");
	fscanf(ps,"%s",g);
	fclose(ps);
	u=b;
	p=r;
	o=bo;
	printf("1----借出书籍\n2----归还书籍\n3----续借书籍\n4----书籍一览\n5----查找书籍\n6----退出\n\n\n7----管理员登陆\n\n\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   printf("1----确认          2----返回\n\n");
				       scanf("%d",&choice);
	                   switch(choice){
			              case 1:printf("请登记借书证号:");
							     scanf("%s",rnum);
								 while(p!=NULL){
									 if(!strcmp(rnum,p->rnum)){
	                                     add=(struct borrow *)malloc(sizeof(struct borrow));
	                                     while(!o->bnext==NULL)
					                         o=o->bnext;
										 strcpy(add->bnum1,u->num);
										 strcpy(add->bname,u->name);
										 strcpy(add->bmon,u->mon);
										 strcpy(add->bnum2,p->rnum);
										 o->bnext=add;
										 add->bnext=NULL;
										 itoa(atol(p->rnum)+1,p->rnum,10);
										 itoa(atol(u->now)-1,u->now,10);
					                     itoa(atol(u->al)+1,u->al,10);
										 printf("借出成功！\n\n");
										 cl1=fopen("borrow.text","w");
										 while(o!=NULL){
											   fprintf(cl1,"%9s%18s%10s%9s\n",o->bnum1,o->bname,o->bmon,o->bnum2);
											   o=o->bnext;}
										 fclose(cl1);
										 B(b,r,bo);}
									 p=p->rnext;}
								 printf("该借书证号不存在\n");
						  case 2:B(b,r,bo);
						  default:printf("无效的选择\n");
				                  B(b,r,bo);}}
				   u=u->next;}
			     printf("无符合条件项\n");
				 B(b,r,bo);
		case 2:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   printf("1----确认          2----返回\n\n");
				       scanf("%d",&choice);
	                   switch(choice){
			              case 1:printf("请登记借书证号:");
							     scanf("%s",rnum);
								 while(p!=NULL){
									 if(!strcmp(rnum,p->rnum)){
										 while(o!=NULL){
											 if((!strcmp(name,o->bname))&&(!strcmp(rnum,o->bnum2))){
												 itoa(atol(p->rnum)-1,p->rnum,10);
												 itoa(atol(u->now)+1,u->now,10);
												 itoa(atol(u->al)-1,u->al,10);
												 add=bo;
												 if((!strcmp(name,bo->bname))&&(!strcmp(rnum,bo->bnum2))){
													 bo=bo->bnext;
													 free(add);
													 add=bo;}
												 else {while(!((!strcmp(name,add->bnext->bname))&&(!strcmp(rnum,add->bnext->bnum2))))
													       add=add->bnext;
												       add->bnext=o->bnext;
									                   free(o);}
										         printf("还书成功！\n\n");
										         B(b,r,bo);}
											 o=o->bnext;}
										 printf("无匹配的借书记录\n");
										 B(b,r,bo);}
									 p=p->rnext;}
								 printf("该借书证号不存在\n");
						  case 2:B(b,r,bo);
						  default:printf("无效的选择\n");
				                  B(b,r,bo);}}
				   u=u->next;}
			    printf("无符合条件项\n");
			    B(b,r,bo);
		case 3:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   printf("1----确认          2----返回\n\n");
				       scanf("%d",&choice);
	                   switch(choice){
			              case 1:printf("请登记借书证号:");
							     scanf("%s",rnum);
								 while(p!=NULL){
									 if(!strcmp(rnum,p->rnum)){
										 while(o!=NULL){
											 if((!strcmp(name,o->bname))&&(!strcmp(rnum,o->bnum2))){
												 printf("续借成功！\n\n");
												 B(b,r,bo);}
											 o=o->bnext;}
										 printf("无匹配的借书记录\n");
										 B(b,r,bo);}
									 p=p->rnext;}
								 printf("该借书证号不存在\n");
						  case 2:B(b,r,bo);
						  default:printf("无效的选择\n");
				                  B(b,r,bo);}}
				   u=u->next;}
			    printf("无符合条件项\n");
			    B(b,r,bo);
	    case 4:search(b,1,g,r,bo);
        case 5:printf("请输入书名:");
			   scanf("%s",name);
			   while(u!=NULL){
				   if(!strcmp(name,u->name)){
					   printf("     编号              书名                   作者                出版社      金额   类别  总入库数量  当前库存量  已借出本数\n");
					   printf("%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",u->num,u->name,u->writer,u->pub,u->mon,u->typ,u->tota,u->now,u->al);
					   B(b,r,bo);}
					   u=u->next;}
			   printf("无符合条件项\n");
			   B(b,r,bo);
		case 6:cl1=fopen("book.text","w");
			   while(b!=NULL){
				   fprintf(cl1,"%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",b->num,b->name,b->writer,b->pub,b->mon,b->typ,b->tota,b->now,b->al);
				   b=b->next;}
				fclose(cl1);
			   exit(0);
        case 7:printf("请输入密码:");
		       scanf("%s",pass);
			   if(!strcmp(pass,g))
				   m1(b,g,r,bo);
			   else{
				   printf("密码错误\n");
				   B(b,r,bo);}
		case 8:int n;
			   for(n=0;u->al[n]!=NULL;n=n++)
				   printf("%c",u->al[n]);
				   u=u->next;
		default:printf("无效的选择\n");
				B(b,r,bo);}}
int main(){
	FILE *f1,*f2,*f3;
	struct book *h1,*pn1,*en1,*u1;
	struct reader *h2,*pn2,*en2,*u2;
	struct borrow *h3,*pn3,*en3,*u3;
	f1=fopen("book.text","r");
	pn1=(struct book *)malloc(sizeof(struct book));
	fscanf(f1,"%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",pn1->num,pn1->name,pn1->writer,pn1->pub,pn1->mon,pn1->typ,pn1->tota,pn1->now,pn1->al);
	u1=h1=en1=pn1;
	while(!feof(f1)){	
		pn1=(struct book *)malloc(sizeof(struct book));
		fscanf(f1,"%9s%18s%23s%22s%10s%7s%12s%12s%12s\n",pn1->num,pn1->name,pn1->writer,pn1->pub,pn1->mon,pn1->typ,pn1->tota,pn1->now,pn1->al);
		en1->next=pn1;	
		en1=pn1;}
	fclose(f1);
	en1->next=NULL;
	f2=fopen("reader.text","r");
	pn2=(struct reader *)malloc(sizeof(struct reader));
	fscanf(f2,"%9s%18s%7s%9s%7s%14s%5s\n",pn2->rnum,pn2->rname,pn2->cla,pn2->rstu,pn2->rtyp,pn2->ral,pn2->rga);
	u2=h2=en2=pn2;
	while(!feof(f2)){	
		pn2=(struct reader *)malloc(sizeof(struct reader));
     	fscanf(f2,"%9s%18s%7s%9s%7s%14s%5s\n",pn2->rnum,pn2->rname,pn2->cla,pn2->rstu,pn2->rtyp,pn2->ral,pn2->rga);
		en2->rnext=pn2;	
		en2=pn2;}
	fclose(f2);
	en2->rnext=NULL;
	f3=fopen("borrow.text","r");
	pn3=(struct borrow *)malloc(sizeof(struct borrow));
	fscanf(f3,"%9s%18s%10s%9s\n",pn3->bnum1,pn3->bname,pn3->bmon,pn3->bnum2);
	u3=h3=en3=pn3;
	while(!feof(f3)){	
		pn3=(struct borrow *)malloc(sizeof(struct borrow));
	    fscanf(f3,"%9s%18s%10s%9s\n",pn3->bnum1,pn3->bname,pn3->bmon,pn3->bnum2);
		en3->bnext=pn3;	
		en3=pn3;}
	fclose(f3);
	en3->bnext=NULL;
	B(u1,u2,u3);
	return 0;}
