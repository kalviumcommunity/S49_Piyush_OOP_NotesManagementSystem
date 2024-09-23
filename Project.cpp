#include <iostream>
#include <string>
using namespace std;

class User{
    private:
    string Username;
    string Email;
    int userId;
    static int numOfUsers;

    public:
    User(string username,string email){
        this->Username = username;
        this->Email = email;
        numOfUsers++;
        this->userId = numOfUsers;
    }

    string getUsername(){
        return Username;
    }
    string getEmail(){
        return Email;
    }
    void setUsername(string newUsername){
        this->Username = newUsername;
    }
    void setEmail(string newEmail){
        this->Email = newEmail;
    }

    void print(){
        std::cout<<"User "<<userId<<endl;
        std::cout<<"Username - "<<Username<<endl;
        std::cout<<"Email - "<<Email<<endl;
    }
    void changeUsername(string newUsername){
        this->Username = newUsername;
    }
    static void userCountPrint(){
        std::cout<<"Number of users: "<<numOfUsers<<endl; 
    }
};

int User::numOfUsers = 0;

class Note{
    private:
    string TopicName;
    string NoteContent;
    int noteId;
    static int numOfNotes;

    public:
    Note(string topic, string noteContent){ 
        this->TopicName = topic;
        this->NoteContent = noteContent;
        numOfNotes++; 
        this->noteId = numOfNotes;
    }

    string getTopicName(){
        return TopicName;
    }
    string getNoteContent(){
        return NoteContent;
    }
    void setTopicName(string newTopicname){
        this->TopicName = newTopicname;
    }
    void setNoteContent(string newNoteContent){
        this->NoteContent = newNoteContent;
    }

    void print(){
        std::cout<<"Topic - "<<TopicName<<endl;
        std::cout<<"NoteContent - "<<NoteContent<<endl;
    }
    void changeTopic(string newTopic){
        this->TopicName = newTopic;
    }
    static void notesCountPrint(){
        std::cout<<"Number of notes: "<<numOfNotes<<endl; 
    }
};

int Note::numOfNotes = 0;

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

    std::cout<<"Summmary of all Data - "<<endl;
    User::userCountPrint();
    Note::notesCountPrint();
    std::cout<<endl;

    std::cout<<"All data has been deleted";
    return 0; 
}


