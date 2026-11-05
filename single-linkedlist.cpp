#include<iostream>
using namespace std;
struct bookType{
    string bookAuthor;
    string bookTitle;
    string bookISBN;
    string bookEdition;
    double bookPrice;
    bookType* next;
};
bookType*head=NULL;
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

if(head==NULL){
    temp->next=NULL;
}
else{
    temp->next=head;

}
head=temp;
cout<<"\n Data is succesfully at the beginning ";
}
void AddBookAtTheEnd(){
bookType*temp=new bookType;
bookType*current;
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
        current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
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
        cout<<"\n list is empty";
    }
    else{
        temp=head;
        head=head->next;
        delete temp;
        cout<<"\n data is succesfully removed from the beginning ";

    }
}
void RemoveBookFromTheEnd(){
    if(head==NULL){
        cout<<"\n list is empty";
    }
    else{
            bookType*prev,*curr;
    curr=head;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    delete curr;
    cout<<"\n data is succesfully removed from end ";

    }
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
}}
void PrintBookInformation(){
bookType*current;
if(head==NULL){
cout<<"\n list is empty ";}
else{
    current=head;
    cout<<"Book Author"<<"\t"<<"Book Title"<<"\t"<<"Book ISBN"<<"\t"<<"Book Edition"<<"\t"<<"Book Price: "<<"\n";
    while(current!=NULL){
            cout<<current->bookAuthor<<"\t\t"<<current->bookTitle<<"\t\t"<<current->bookISBN<<"\t\t"<<current->bookEdition<<"\t\t"<<current->bookPrice<<"\n";
       current=current->next;
    }
    cout<<"\n data is succefully printed ";
}
}
void SearchBookByName(string name){
  bookType*current;
if(head==NULL){
cout<<"\n list is empty ";}
else{
    current=head;
    int pos=1;
    while(current!=NULL){
            if(current->bookAuthor==name){
                cout<<"\n Book is found at index: "<<pos;
                break;
            }
            pos++;
            current=current->next;
             

    }
}}


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
    cout<<"\n 8.Search Book By Name ";
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

