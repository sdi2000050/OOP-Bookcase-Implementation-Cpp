#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class book{
    public:
        string title;
        string name;
        int isbn;
        void print();
    
        book(string,string,int);
};

book::book(string btitle = "-",string bname = "-",int bisbn = 0) : title(btitle), name(bname) , isbn(bisbn){
    title = btitle;
    name=bname;
    isbn=bisbn;
}



class base{
    public:
        base();
        ~base();
};

base::base(){
    cout<< "The base of the bookcase was just created"<<"\n";
}

base::~base(){
    cout<< "The base of the bookcase was just destroyed"<<"\n";
}

class shelf{
    private:
        book** books;
        int num;
    public:
        int nmax;
        
        shelf();        
        ~shelf();
        
        void setnmax(int n);
        bool place_book(book *b);
        bool take_book();
        void print();
};


void shelf::setnmax(int n){
    delete[] books;
    nmax=n;
    books=new book* [nmax];
    for(int i=0;i<nmax;i++){
        books[i]=NULL;
    }

}

shelf::shelf(){
    num=0;
    books = new book*[1];
    books[0] = NULL;
    cout<< "A shelf of the bookcase was just created"<<"\n";
}


shelf::~shelf(){
    delete[] books;
    cout<< "A shelf of the bookcase was just destroyed"<<"\n";
}

class closet{
    private:
        shelf s1;
        shelf s2;
    public:

        closet();
        ~closet();

        void setnmax(int n);
        bool place_book(int s,book *b);
        bool take_book(int s);
        void print();
};

closet::closet(){
    cout<< "The closet of the bookcase was just created"<<"\n";
}

void closet::setnmax(int n){
    s1.setnmax(n);
    s2.setnmax(n);
}

closet::~closet(){
    cout<< "The closet of the bookcase was just destroyed"<<"\n";
}


class bookcase{
    private:
        base bs;
        closet cl;
        shelf sl1;
        shelf sl2;
        shelf sl3;
        int C;
    public:   

        bookcase();
        ~bookcase();

        void setnmax(int n);
        bool place_book(int s,book *b);
        bool take_book(int s);
        void print();
};

bookcase::bookcase(){
    C=0;
    cout<< "The bookcase was just created"<<"\n";
}

void bookcase::setnmax(int n){
    cl.setnmax(n);
    sl1.setnmax(n);
    sl2.setnmax(n);
    sl3.setnmax(n);
}


bookcase::~bookcase(){
    cout<< "The bookcase was just destroyed"<<"\n";
}

bool shelf::place_book(book *b){
    if(num<nmax){
        books[num]=b;
        num++;
        return true;
    }
    else{
        cout<<"there is not enough room for the book\n";
        return false;
    }
}

bool closet::place_book(int s,book *b){
    if (s==1){
        if(s1.place_book(b)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(s2.place_book(b)){
            return true;
        }
        else{
            return false;
        }
    }
}

bool bookcase::place_book(int s,book *b){
    if (s==1){
        if(sl1.place_book(b)){
            C++;
            cout<< "placing book in the top bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<< "can not place the book\n";
            return false;
        }
    }
    else if (s==2){
        if(sl2.place_book(b)){
            C++;
            cout<< "placing book in the middle bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<< "can not place the book\n";
            return false;
        }
    }
    else if (s==3){
        if(sl3.place_book(b)){
            C++;
            cout<< "placing book in the bottom bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<< "can not place the book\n";
            return false;
        }
    }
    else if (s==4){
        if(cl.place_book(1,b)){
            C++;
            cout<< "placing book in the top bookcase shelf of the closet" <<"\n";
            return true;
        }
        else{
            cout<< "can not place the book\n";
            return false;
        }
    }
    else{
        if(cl.place_book(2,b)){
            C++;
            cout<< "placing book in the bottom bookcase shelf of the closet" <<"\n";
            return true;
        }
        else{
            cout<< "can not place the book\n";
            return false;
        }
    }
}

bool shelf::take_book(){
    if(num>0){
        books[num]=NULL;
        num--;
        return true;
    }
    else{
        return false;
    }
}

bool closet::take_book(int s){
    if (s==1){
        if(s1.take_book()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(s2.take_book()){
            return true;
        }
        else{
            return false;
        }
    }
}

bool bookcase::take_book(int s){
    if (s==1){
        if(sl1.take_book()){
            C--;
            cout<< "taking book from the top bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<<"there is no book to take\n";
            return false;
        }
    }
    else if (s==2){
        if(sl2.take_book()){
            C--;
            cout<< "taking book from the middle bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<<"there is no book to take\n";
            return false;
        }
    }
    else if (s==3){
        if(sl3.take_book()){
            C--;
            cout<< "taking book from the bottom bookcase shelf" <<"\n";
            return true;
        }
        else{
            cout<<"there is no book to take\n";
            return false;
        }
    }
    else if (s==4){
        if(cl.take_book(1)){
            C--;
            cout<< "taking book from the top bookcase shelf of the closet" <<"\n";
            return true;
        }
        else{
            cout<<"there is no book to take\n";
            return false;
        }
    }
    else{
        if(cl.take_book(2)){
            C--;
            cout<< "taking book from the bottom bookcase shelf of the closet" <<"\n";
            return true;
        }
        else{
            cout<<"there is no book to take\n";
            return false;
        }
    }
}

void book::print(){
    cout << "Title:" << this->title << " Author:" << this->name << " ISBN:" << this->isbn << "\n\n";
}

void shelf::print(){
    int i;
    for(i=0;i<num;i++){
        books[i]->print();
    }
}

void closet::print(){
    cout<<"The books of the top shelf in the closet are: "<<"\n";
    s1.print();
    cout<<"The books of the bottom shelf in the closet are: "<<"\n";
    s2.print();
}

void bookcase::print(){
    cout<<"The books of the top shelf are: "<<"\n";
    sl1.print();
    cout<<"The books of the middle shelf are: "<<"\n";
    sl2.print();
    cout<<"The books of the bottom shelf are: "<<"\n";
    sl3.print();
    cl.print();
}

int main(int argc, char *argv[]){
    int Nmax,L,K1,K2; 

    if (argc!=5)
        return 1;
    Nmax=atoi(argv[1]);
    L=atoi(argv[2]);
    K1=atoi(argv[3]);
    K2=atoi(argv[4]);

    bookcase B;
    B.setnmax(Nmax);
    
    int i,isbn;
    book *barray=new book [L];
    
    cout<<"the books are:\n";
    for (i=0; i<L; i++){
        isbn=rand() %100000;
        book b("title","name",isbn);
        barray[i]=b;
        cout<<"\nTitle: "<<(barray[i]).title<<"   Author: "<< (barray[i]).name<<"   ISBN:"<<(barray[i]).isbn<<"    \n\n";
    }

    for(i=0; i<K1; i++){
        B.place_book(rand()%K1+1,&(barray[rand()%L]));
    }

    for(i=0; i<K2; i++){
        B.take_book(rand()%K2+1);
    }

    B.print();
}