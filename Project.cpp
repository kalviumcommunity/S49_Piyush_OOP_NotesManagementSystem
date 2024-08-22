#include <iostream>
#include <string>
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
    const int numOfData = 3;
    User user[numOfData] ={
        User("Piyush","piyushb@gmail.com"),
        User("Rutuj","rutuj@gmail.com"),
        User("Danny","dan@gmail.com")
    };

    Note note[numOfData] ={
        Note("C++","A programming"),
        Note("DBMS","Database Management System"),
        Note("HTML","Web Development Language")
    };

    user[0].changeUsername("Piyush123");
    note[0].changeTopic("Python");

    for (int i=0;i<numOfData;i++){
        user[i].print();
        note[i].print();
        std::cout<<endl;
    };
    return 0; 
}


