#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<fstream>

int cint( int num) {
   int count =0;
   while (num !=0) {   
      count++;  
      num/=10;
   } 
   return count;
}



struct node {
	int rno;
	char name[50];
	int clas;
	float cgpa;
	
	node *left;
	node *right;	
};

node *root=NULL;
node *ptr=new node;

char nme[50];int cc;float cg;
float avg;
int sum=0;	
int nnn;
///////////////
#define size 100
int array[size];
int front=-1;
int rear=-1;
bool isfull(){
	if(front==0&&rear==(size-1)){
		return true;
	}
	else return false;
}

bool isempty(){
	if(front==-1){
		return true;
	}
	else return false;
}
int cx=0;
void dsh(int k){
	for(int u=front;u<=rear;u++){
		if(k==array[u]){
			cx=1;
		}
	}
	
}

void enqueue(){
	
	dfg:
	cout<<"Enter Bus Number(5 Digits) : "<<endl;
	int tyy;
	if(!(cin>>tyy)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	cout<<"You entered wrong Number. Try Again."<<endl;
    	goto dfg;
	}
	int a=cint(tyy);
	if(a!=5){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto dfg;
	}
	dsh(tyy);
	
	if(cx==1){
		cout<<"Bus already present."<<endl;
		cout<<"Enter Again."<<endl;
		goto dfg;
	}
	
	
	
	if(front==-1&&rear==-1){
		front++;
		rear++;
		array[rear]=tyy;
	}
	else if(isfull()) {
		cout<<"Total Buses are already present."<<endl;
	}
	else if(rear==size-1){
		rear=0;
		array[rear]=tyy;
	}
	else{rear++;
	array[rear]=tyy;}
	
	ofstream obj;
	obj.open("BusNumbers.txt",ios::out|ios::app);
	obj<<tyy<<endl;
	obj.close();
	
	
}

void dequeue(){
/*	
fstream file;
	file.open("BusNumbers.txt",ios::in|ios::app|ios::out);
	file.seekg(0,ios::beg);
	if(!file.eof())
{
	int yy;
	file>>yy;
	file.seekp(0);
	cout<<"Bus Number "<<yy<<" leave uni."<<endl;
	file.close();
	return;
}*/
	
	if(isempty()){
		cout<<"No Buses are Present."<<endl;
	}else if(rear==front){
		cout<<"Bus Number "<<array[rear]<<" leave uni."<<endl;
		front=-1;
		rear=-1;
	}
	else {
		cout<<"Bus Number "<<array[front]<<" leave uni."<<endl;
		front++;
	}
	
}
void edisplay(){
	ifstream file;
	file.open("BusNumbers.txt",ios::in|ios::app);
	int aa;
	cout<<"Buses Already Present are _ "<<endl;
	while(!file.eof()){
	file>>aa;
	if(file.eof()){
	break;
		}
		cout<<"Bus Number : "<<aa<<endl;
		
	}
	file.close();

	
	if(rear==-1&&front==-1){
		cout<<"No Buses Entered After."<<endl;
		return;
	}
	cout<<"Displaying all the Bus Numbers Entered now in the university : "<<endl;
	if(rear<=size-1){
		for(int i=front;i<=rear;i++){
			cout<<"Bus Number : "<< array[i]<<endl;
		}
	}
	else if(rear<front){
		for(int i=front;i<=(size-1);i++){
			cout<<"Bus Number : "<< array[i]<<endl;
		}
		for(int i=0;i<=rear;i++){
			cout<<"Bus Number : "<< array[i]<<endl;
		}
		
	}
	else if(rear==front){
					cout<<"Bus Number : "<< array[rear]<<endl;
	}
}

void create(int k);
///////
void add(int k){
node *temp=new node;

temp->left=NULL;
temp->right=NULL;
	if(root==NULL)
	{   temp->cgpa=cg;
temp->clas=cc;
strcpy(temp->name, nme);
temp->rno=k;
		root=temp;
		ptr=temp;
	}
	else if(k<ptr->rno){
		if(ptr->left!=NULL)
		{
			ptr=ptr->left;
            add(k);
		}
		else {
temp->cgpa=cg;
temp->clas=cc;
strcpy(temp->name, nme);
temp->rno=k;
			ptr->left=temp;
			ptr=root;
			
		}
	}
		else if(k>ptr->rno){
		if(ptr->right!=NULL)
		{
			ptr=ptr->right;
	        add(k);
		}
		else {
temp->cgpa=cg;
temp->clas=cc;
strcpy(temp->name, nme);
temp->rno=k;
			ptr->right=temp;
			ptr=root;
		
		}
	}	
	else {
		cout<<"This Student Data Is already present."<<endl;
		cout<<"Enter Roll Number again : "<<endl;
		cin>>k;
		create(k);
	}
}

void create(int k){
 	cin.ignore();
	cout<<"Enter Student Name : ";
	gets(nme);
	ash:
	cout<<"Enter Semester (1 to 10) : ";
	
	if(!(cin>>cc)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto ash;
	}
	if(cc<1||cc>10){
		system("cls");
		cout<<"You entered Wrong Number. Enter again."<<endl;
		goto ash;
	}
	cgpa:
	cout<<"Enter CGPA : ";
if(!(cin>>cg)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto cgpa;
	}
	
	if(cg>4||cg<0){
		cout<<"You entered Wrong Number. Enter again."<<endl;
		goto cgpa;
	}
	add(k);
 }

void disp(node *ptr){

	if(root!=NULL){
		if(ptr->left!=NULL){

			disp(ptr->left);
		}
	cout<<left<<setw(20)<<ptr->rno<<left<<setw(20)<<ptr->name<<left<<setw(20)<<ptr->clas<<left<<setw(20)<<ptr->cgpa<<endl;
		if(ptr->right!=NULL){
		
			disp(ptr->right);
		}	
	}
	else {
		cout<<"No Data Currently Present."<<endl;
	}	
}

void disp1(node *ptr){

	if(root!=NULL){
		if(ptr->right!=NULL){

			disp(ptr->right);
		}
		
	cout<<left<<setw(20)<<ptr->rno<<left<<setw(20)<<ptr->name<<left<<setw(20)<<ptr->clas<<left<<setw(20)<<ptr->cgpa<<endl;
		if(ptr->left!=NULL){
		
			disp(ptr->left);
		}
		
	}
	else {
		cout<<"No Data Currently Present"<<endl;
	}
}


node* ret(int k){
    	if(ptr!=NULL){
		if(ptr->rno==k){ 
			return ptr;
		}
		else if(k<ptr->rno){
			ptr=ptr->left;
			ret(k);
		}
		else if(k>ptr->rno){
			ptr=ptr->right;
			ret(k);
		}	}
	else {
		return NULL;
	}
}

void print(int k){
	ptr=root;
	node *ptr1=ret(k);
	if(ptr1!=NULL){
		
		cout<<left<<setw(20)<<ptr->rno<<left<<setw(20)<<ptr->name<<left<<setw(20)<<ptr->clas<<left<<setw(20)<<ptr->cgpa<<endl;
	
	}
	else {
		cout<<"No Data Present."<<endl;;
	}
}
node* findmin(node *ptr){
	ptr=NULL;
	while(ptr->left!=NULL){
		ptr=ptr->left;
	}
	return ptr;
}
node* del(node *p,int k){
	if(root==NULL){
		return p ;
	}
		//element tk
else	if(k<p->rno){
		del(p->left,k);
	}
	else if(k>p->rno){
		del(p->right,k);
	}
	else if(k==p->rno){
	///	No Element
	if(p->left==NULL&&p->right==NULL){
		delete p;
		p=NULL;
		cout<<"Data with no elements deleted"<<endl;
		return p;
	}
	//one element
    else if(p->left==NULL&&p->right!=NULL){
		node *temp=p;
		p=p->right;
		delete temp;
		cout<<"Data with one right elements deleted"<<endl;
		return p;
		
	}
	else if( p->right==NULL&&p->left!=NULL){
		node *temp=p;
		p=p->left;
		delete temp;
		cout<<"Data with one left elements deleted"<<endl;
		return p;
		
	}
		//two elements
	else
    {
	node *temp=findmin(p->right);
	p=temp;
	del(p->right,temp->rno);
	return p;
	}	
	}	
}
void edit(node *ptr,int k)
{
	ptr=ret(k);
	if(ptr==NULL){
		return;
	}
	cin.ignore();
	cout<<"Enter Student Name : ";
	gets(ptr->name);
	uug:
	cout<<"Enter Semester (1 to 10) : ";
	if(!(cin>>ptr->clas)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto uug;
	}
	if(ptr->clas<1||ptr->clas>10){
		system("cls");
		cout<<"You entered Wrong Number. Enter again."<<endl;
		goto uug;
	}
	
	ter:
	cout<<"Enter CGPA (0 - 4): ";
	if(!(cin>>ptr->cgpa)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto ter;
	}
		if(cg>4||cg<0){
		cout<<"You entered Wrong Number. Enter again."<<endl;
		goto ter;
	}
}
int count(node *tree)
{
           
    if (tree ==NULL)
        return 0;
    else
    {
       return(count(tree->left)+1+count(tree->right));
    }
}
void calc(node *ptr){
	if(root!=NULL){
		if(ptr->right!=NULL){

			calc(ptr->right);
		}
		
	sum=sum+ptr->cgpa;
		if(ptr->left!=NULL){
		
			calc(ptr->left);
		}
		
	}
	else {
		cout<<"No Data Currently Present"<<endl;
	}
}

//////////////////

struct nod {
	int per;
	char name[50];
    int rr;
	nod* link;
};

nod *tail=NULL;
nod *head=NULL;

int qwa=0;
void ss(int k){
	nod *temp=head;
	while(temp!=NULL){
		if(k==temp->rr){
			qwa=1;
		}
		temp=temp->link;
		
	}
}


void in(){

	nod *tem=new nod;
	cin.ignore();	cout<<"Enter Name Of Student : ";
	gets(tem->name);
	wew:
	cout<<"Enter Board Roll No ( 6 Digits): ";
	if(!(cin>>tem->rr)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto wew;
	}
	int dyp;
dyp=cint(tem->rr);
if(dyp!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto wew;
	}
	
	ss(tem->rr);
	if(qwa==1){
		cout<<"Roll Number Already Present."<<endl;
		cout<<"Enter Again."<<endl;
			qwa=0;
		goto wew;
	}
	
	per:
	cout<<"Enter Percentage of Exam : ";
	if(!(cin>>tem->per)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto per;
	}
	if(tem->per>100||tem->per<0){
		cout<<"You entered Incorrect Percentage. Try Again."<<endl;
		goto per;
	}
if(head==NULL){ 
tem->link=NULL;
head=tem;
tail=tem;
}
else { 
tem->link=NULL;
tail->link=tem;
tail=tem;
}

}


void ou(){
	nod *temp=head;
	cout<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Roll Number"<<left<<setw(20)<<"Percentage"<<endl;
	while(temp!=NULL){
		cout<<left<<setw(20)<<temp->name<<left<<setw(20)<<temp->rr<<left<<setw(20)<<temp->per<<endl;
		temp=temp->link;
	}
}

void sou(){
		nod *temp=head;
	cout<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Roll Number"<<left<<setw(20)<<"Percentage"<<endl;
	while(temp!=NULL){
		if(temp->per>=80){
		
		cout<<left<<setw(20)<<temp->name<<left<<setw(20)<<temp->rr<<left<<setw(20)<<temp->per<<endl;
		}temp=temp->link;
	}
	
}
void copy(){
	nod *temp=head;int ii;
	wer:
	cout<<"Enter Roll No : ";
		if(!(cin>>ii)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto wer;
	}
	int dyp;
dyp=cint(ii);
if(dyp!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto wer;
	}
	while(temp!=NULL){
		if(temp->rr==ii){
				cin.ignore();	cout<<"Enter Name Of Student : ";
	gets(temp->name);
	zxc:
	cout<<"Enter Percentage : ";
	if(!(cin>>temp->per)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto zxc;
	}
		if(temp->per>100||temp->per<0){
		cout<<"You entered Incorrect Percentage. Try Again."<<endl;
		goto zxc;
	}
	return;
		}
		temp=temp->link;
	}
cout<<"Record Not Found."<<endl;
	
}

/////////////////////
int main(){
	menu :
	cout<<"\t\t************************************"<<endl;
    cout<<"\t\t***University Management System  ***"<<endl;
    cout<<"\t\t***1-Student Information Portal  ***"<<endl;
    cout<<"\t\t***2-Transport Information Portal***"<<endl;
    cout<<"\t\t***3-Admission Form              ***"<<endl;
   	cout<<"\t\t************************************"<<endl;
    int hhj;
    if(!(cin>>hhj)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto menu;
	}
    system("cls");
    switch(hhj){
	case 1 :
		point1 :
	cout<<"\t\t**********************************************************"<<endl;
	cout<<"\t\t**********************************************************"<<endl;
	cout<<"\t\t****Student Information Portal                        ****"<<endl;
	cout<<"\t\t****1-Add Data Of Student                             ****"<<endl;
	cout<<"\t\t****2-Display Data Of all Students in ascending order ****"<<endl;
	cout<<"\t\t****3-Display Data of Particular Student              ****"<<endl;
	cout<<"\t\t****4-Delete Student Data                             ****"<<endl;
	cout<<"\t\t****5-Edit Data of Student                            ****"<<endl;
	cout<<"\t\t****6-Display Data Of all Students in decending order ****"<<endl;
	cout<<"\t\t****7.Average CGPA of Students in University          ****"<<endl;
	cout<<"\t\t****8-Go Back                                         ****"<<endl;
	cout<<"\t\t**********************************************************"<<endl;
	cout<<"\t\t**********************************************************"<<endl;
    int n;if(!(cin>>n)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto point1;
	}
	system("cls");
switch(n){
	
	case 1 :
		qqq:
	cout<<"How many Students data do you want to enter ? ";
	int q;if(!(cin>>q)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto qqq;
	}
	system("cls");
	for(int i=0;i<q;i++){
	int p;
	ttt:
	cout<<"*********Data of Student "<<i+1<<"*********"<<endl;
	cout<<"Enter Roll Number Of Student (6 Digits): ";
   	if(!(cin>>p)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto ttt;
	}
int dpp;
dpp=cint(p);
  if(dpp!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto ttt;
	}
	create(p);
	}
	
	break;
	case 2 :
	cout<<"**********Displaying All The data of Students**********"<<endl;
	cout<<left<<setw(20)<<"RollNumber"<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Semester"<<left<<setw(20)<<"CGPA"<<endl;
	disp(root);
	
	break;	
	case 3:
		if(root==NULL){
				cout<<"No Data Currently Present."<<endl;
				getch();
system("cls");
goto point1;}
		ddd:
	cout<<"Enter the Roll Number of Student : "<<endl;int dd;
if(!(cin>>dd)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto ddd;
	}
 
int dyp;
dyp=cint(dd);
if(dyp!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto ddd;
	}
	cout<<left<<setw(20)<<"RollNumber"<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Semester"<<left<<setw(20)<<"CGPA"<<endl;
	print(dd);
	
	break;
	case 4:
		if(root==NULL){
				cout<<"No Data Currently Present."<<endl;
				getch();
system("cls");
goto point1;}
		dq:
	cout<<"Enter the Roll Number of Student : "<<endl;
	if(!(cin>>dd)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto dq;
	}
		int dps;
dps=cint(dd);
if(dps!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto dq;
	}
     root=del(root,dd);
	
	break;
	case 5 :
		tre:
			if(root==NULL){
				cout<<"No Data Currently Present."<<endl;
				getch();
system("cls");
goto point1;}
	cout<<"Enter the Roll Number of Student : "<<endl;
	if(!(cin>>dd)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto tre;
	}

dyp=cint(dd);
if(dyp!=6){
		cout<<"You entered wrong Number. Try Again."<<endl;
    	goto tre;
	}
	edit(root,dd);	
	break;
	case 6:
	cout<<"**********Displaying All The data of Students**********"<<endl;
	cout<<left<<setw(20)<<"RollNumber"<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Semester"<<left<<setw(20)<<"CGPA"<<endl;
	disp1(root);
	break;
	case 7:	
	calc(root);	
	if(sum==0){
		break;
	}
    nnn=count(root);
	avg=sum/nnn;
	sum=0;
	cout<<"Average of CGPA of Students is "<<avg<<endl;
	break;
	
	case 8:
	system("cls");
     goto menu;
	default :
		cout<<"You Entered Wrong Number.Try Again"<<endl;
		
	
}
getch();
system("cls");
goto point1;
break;
	case 2 :
		point2 :
		cout<<"\t\t***************************************************"<<endl;
		cout<<"\t\t***************************************************"<<endl;
		cout<<"\t\t*****Transport Management System              *****"<<endl;
		cout<<"\t\t*****1-Arrive Busses                          *****"<<endl;
		cout<<"\t\t*****2-Leaving Bus                            *****"<<endl;
		cout<<"\t\t*****3-Display all buses present in university*****"<<endl;
		cout<<"\t\t*****4-Go Back.                               *****"<<endl;
        cout<<"\t\t***************************************************"<<endl;
		cout<<"\t\t***************************************************"<<endl;
		int qwe;if(!(cin>>qwe)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto point2;
	}
	switch(qwe){
			case 1 :
			    	enqueue();
			    	break;
			case 2 :
					dequeue();
					break;
					
			case 3 :
					edisplay();
					break;
				case 4 :
	system("cls");
goto menu;	
					break;
						default :
		cout<<"You entered wrong key."<<endl;
						
		}
	getch();
system("cls");
goto point2;
	break;
	case 3:
		point3 :
		cout<<"\t\t**************************************"<<endl;
		cout<<"\t\t**************************************"<<endl;
     	cout<<"\t\t*****1-Apply                     *****"<<endl;
		cout<<"\t\t*****2-List of All application   *****"<<endl;
		cout<<"\t\t*****3-List of Selected Students *****"<<endl;
		cout<<"\t\t*****4-Edit Your Data            *****"<<endl;
		cout<<"\t\t*****5-Go Back                   *****"<<endl;
			cout<<"\t\t**************************************"<<endl;
		cout<<"\t\t**************************************"<<endl;
		int iop;
		if(!(cin>>iop)){
    	cin.clear();
    	cin.ignore(100,'\n');
    	Sleep(500);
    	system("cls");
    	goto point3;
	}
		system("cls");
		switch(iop){
		case 1 :
			in();
		break;	
		case 2 :
			cout<<"\t\tList of All Students."<<endl;
			cout<<endl;
			ou();
		break;
		case 3 :
			cout<<"\t\tList of Selected Students."<<endl;
			cout<<endl;
			sou();
		break;
		case 4 :
			copy();
		break;
		case 5 :
	    system("cls");
        goto menu;	
		break;
		default : 
		cout<<"You entered wrong key."<<endl;
		}
    getch();
    system("cls");
    goto point3;
	break;
	
	default :
		cout<<"You entered wrong key."<<endl;
		getch();
       system("cls");
       goto menu;
}

}

