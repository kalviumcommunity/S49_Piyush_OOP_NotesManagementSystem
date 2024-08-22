#include <iostream>
using namespace std;

class User{
    public:
    string Username;
    string Email;
    User(string username,string email){
        this->Username = username;
        this->Email = email;
    }
    void print(){
        std::cout<<"Username - "<<Username<<endl;
        std::cout<<"Email - "<<Email<<endl;
    }
    void changeUsername(string newUsername){
        this->Username = newUsername;
    }
};

class Note{
    public:
    string TopicName;
    string NoteContent;
    Note(string topic, string noteContent){ 
        this->TopicName = topic;
        this->NoteContent = noteContent; 
    }
    void print(){
        std::cout<<"Topic - "<<TopicName<<endl;
        std::cout<<"NoteContent - "<<NoteContent<<endl;
    }
    void changeTopic(string newTopic){
        this->TopicName = newTopic;
    }
};
int main(){
    User user1("Piyush","piyushb@gmail.com");
    Note note1("C++","A programming");

    User user2("Rutuj","Rutuj@gmail.com");
    Note note2("DBMS","Database Management System");

    user1.print();
    note1.print();
    std::cout<<endl;
    user2.print();
    note2.print();

    user1.changeUsername("Piyush123");
    note1.changeTopic("Python");

    std::cout<<endl;
    user1.print();
    note1.print();
   return 0; 
}
