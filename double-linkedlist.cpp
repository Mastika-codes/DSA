#include<iostream>
using namespace std;
struct bookType{
    string bookAuthor;
    string bookTitle;
    string bookISBN;
    string bookEdition;
    double bookPrice;
    bookType*prev;
    bookType*next;
};
bookType*head=NULL,*tail=NULL;
void AddBookAtTheStart(){
    bookType*temp= new bookType;
    cout<<"enter the name of Author ";
    cin>>temp->bookAuthor;
    cout<<"enter the title of the Book ";
    cin>>temp->bookTitle;
    cout<<"enter the book's ISBN ";
    cin>>temp->bookISBN;
    cout<<"enter the book's Edition ";
    cin>>temp->bookEdition;
    cout<<"enter the book price ";
    cin>>temp->bookPrice;
    temp->next=NULL;
    temp->prev=NULL;
if(head==NULL){
    head=temp;
    tail=temp;
}
else{
    temp->next=head;
    head->prev=temp;
    head=temp;

}
cout<<"\n Data is succesfully at the beginning ";
}
void AddBookAtTheEnd(){
bookType*temp=new bookType;
    cout<<"enter the name of Author ";
    cin>>temp->bookAuthor;
    cout<<"enter the title of the Book ";
    cin>>temp->bookTitle;
    cout<<"enter the book's ISBN ";
    cin>>temp->bookISBN;
    cout<<"enter the book's Edition ";
    cin>>temp->bookEdition;
    cout<<"enter the book price ";
    cin>>temp->bookPrice;
temp->next=NULL;
temp->prev=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
            temp->prev=tail,
            tail->next=temp;
            tail=temp;
    }
    cout<<"\n Data is successfully stored at the end ";
}
void AddBookAtSpecificPosition(int pos){
	 bookType* temp=new bookType;
    cout<<"enter the name of Author ";
    cin>>temp->bookAuthor;
    cout<<"enter the title of the Book ";
    cin>>temp->bookTitle;
    cout<<"enter the book's ISBN ";
    cin>>temp->bookISBN;
    cout<<"enter the book's Edition ";
    cin>>temp->bookEdition;
    cout<<"enter the book price ";
    cin>>temp->bookPrice;
    temp->next=NULL;
    if(head==NULL){
        head=temp;

    }
    else{
        bookType*prev,*curr;
        int i=1;
        curr=head;
        while(i<pos){
            prev=curr;
            curr=curr->next;
            i++;

        }
        temp->next=curr;
        prev->next=temp;

    }
    cout<<"\n Data is succesfully added at specific position ";
}
void RemoveBookFromTheStart(){
	bookType*temp;
	if(head==NULL){
		cout<<"the list is empty ";
	}
	else{
		temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
		cout<<"\n data is successfully removed from the beginning of the list";
	}
}
void RemoveBookFromTheEnd(){
    bookType*temp;
    if(head==NULL){
        cout<<"\n list is empty";
    }
    else{
            temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete temp;
    }
    cout<<"\n data is succesfully removed from end ";

    }
void RemoveBookAtSpecificPosition(int pos){
	 if(head==NULL){
        cout<<"\n list is empty";
    }
    else{
    bookType*prev=NULL,*curr=head;
    int i=1;
    while(curr != NULL && i<pos){
        prev=curr;
        curr=curr->next;
        i++;
    }
    prev->next=curr->next;
    delete curr;
    cout<<"\n data is succesfully removed at specific position ";
}
}
void PrintBookInformation(){
	if(head==NULL){
            cout<<"the list empty ";
        }
    else{
            bookType*current=head;
            cout<<"Book Author"<<"\t"<<"Book Title"<<"\t"
			<<"Book ISBN"<<"\t"<<"Book Edition"<<"\t"<<"Book Price: "<<"\n";
    while(current!=NULL){
       cout<<current->bookAuthor<<"\t\t"<<current->bookTitle
	   <<"\t\t"<<current->bookISBN<<"\t\t"<<current->bookEdition<<"\t\t"
	   <<current->bookPrice<<"\n";
       current=current->next;
    }
}
}
void PrintInformation_InReverse(){
  if(tail==NULL){
            cout<<"the list empty ";

        }
        else{
            bookType*current;
            current=tail;
            cout<<"Book Author"<<"\t"<<"Book Title"<<"\t"
			<<"Book ISBN"<<"\t"<<"Book Edition"<<"\t"<<"Book Price: "<<"\n";
       while(current!=NULL){
       cout<<current->bookAuthor<<"\t\t"<<current->bookTitle
	   <<"\t\t"<<current->bookISBN<<"\t\t"<<current->bookEdition<<"\t\t"
	   <<current->bookPrice<<"\n";
        current=current->prev;
    }
}	
}
void SearchBookByName(string Name)
  {
  	bookType*current;
if(head==NULL){
cout<<"\n list is empty ";}
else{
    current=head;
    int pos=1;
    while(current!=NULL){
            if(current->bookAuthor==Name){
                cout<<"\n Book is found at index: "<<pos;
                break;
            }
            pos++;
            current=current->next;
    }
}
}
int main(){
    char op;
    int pos;
    string Name;
menu:
	cout<<"\n 1.Add Book At The Start";
    cout<<"\n 2.Add Book At The end";
    cout<<"\n 3.Add Book At The Specific position";
    cout<<"\n 4.Remove Book From The biginning";
    cout<<"\n 5.Remove Book From The end";
    cout<<"\n 6.Remove Book From a specific position";
    cout<<"\n 7.Print The Book Information ";
    cout<<"\n 8.Print the Book Information in reverese";
    cout<<"\n 9.Search Book By Name ";
    cout<<"\n 0. EXIT ";
    cout<<"\n choose the operation: ";
    cin>>op;
switch(op){
case '1':
    AddBookAtTheStart();
    break;
case '2':
    AddBookAtTheEnd();
    break;
case '3':
    cout<<"\n enter the position: ";
    cin>>pos;
    AddBookAtSpecificPosition(pos);
    break;
case '4':
    RemoveBookFromTheStart();
    break;
case '5':
    RemoveBookFromTheEnd();
    break;
case '6':
    cout<<"\n enter the position: ";
    cin>>pos;
    RemoveBookAtSpecificPosition(pos);
    break;
case '7':
    PrintBookInformation();
    break;
case '8':
	PrintInformation_InReverse();
	break;	
case '9':
    cout<<"\n Enter the name to be searched: ";
    cin>>Name;
	SearchBookByName(Name);
    break;
case '0':
    return 0;
    break;
default:
    cout<<"enter valid operation ";
    }
    goto menu;	
}

