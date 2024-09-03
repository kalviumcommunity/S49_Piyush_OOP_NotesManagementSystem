#include <iostream>
#include <string>
using namespace std;

class User{
    public:
    string Username;
    string Email;
    int userId;
    static int numOfUsers;
    User(string username,string email){
        this->Username = username;
        this->Email = email;
        this->userId = numOfUsers;
        numOfUsers++;
    }
    void print(){
        std::cout<<"User "<<userId<<endl;
        std::cout<<"Username - "<<Username<<endl;
        std::cout<<"Email - "<<Email<<endl;
    }
    void changeUsername(string newUsername){
        this->Username = newUsername;
    }
};

int User::numOfUsers = 1;

class Note{
    public:
    string TopicName;
    string NoteContent;
    int noteId;
    static int numOfNotes;
    Note(string topic, string noteContent){ 
        this->TopicName = topic;
        this->NoteContent = noteContent; 
        this->noteId = numOfNotes;
    }
    void print(){
        std::cout<<"Topic - "<<TopicName<<endl;
        std::cout<<"NoteContent - "<<NoteContent<<endl;
    }
    void changeTopic(string newTopic){
        this->TopicName = newTopic;
    }
};

int Note::numOfNotes = 1;

int main(){
    std::cout<<"New data is being added below:-"<<endl;
    std::cout<<endl;

    const int numOfData = 3;
    User* userData[numOfData];
    Note* noteData[numOfData];

    string usernames[]={"Piyush","Rutuj","Danny"};
    string emails[]={"piyushb@gmail.com","rutuj@gmail.com","dan@gmail.com"};
    string topics[]={"C++","DBMS","HTML"};
    string noteContents[]={"A programming","Database Management System","Web Development Language"};


    for(int i=0;i<numOfData;i++){
        userData[i]=new User(usernames[i],emails[i]);
        noteData[i]=new Note(topics[i],noteContents[i]);
    }

    userData[0]->changeUsername("Piyush123");
    noteData[0]->changeTopic("Python");

    for (int i=0;i<numOfData;i++){
        userData[i]->print();
        noteData[i]->print();
        std::cout<<endl;
    };

    for (int i=0;i<numOfData;i++){
        delete userData[i];
        delete noteData[i];
    };

    std::cout<<"All data has been deleted";
    return 0; 
}


