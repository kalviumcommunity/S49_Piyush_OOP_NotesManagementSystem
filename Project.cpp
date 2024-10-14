#include <iostream>
#include <string>
using namespace std;

class abstractUser{
    public:
    virtual string getUsername() const = 0;
    virtual string getEmail() const = 0;
    virtual void setUsername(string newUsername) = 0;
    virtual void setEmail(string newEmail) = 0;
    virtual void print() const = 0;
    virtual ~abstractUser(){};
};

class User:public abstractUser{
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
    ~User(){
        std::cout<<Username<<" deleted successfully."<<endl; 
    }

    string getUsername() const{
        return Username;
    }
    string getEmail() const{
        return Email;
    }
    void setUsername(string newUsername){
        this->Username = newUsername;
    }
    void setEmail(string newEmail){
        this->Email = newEmail;
    }

    void print() const{
        std::cout<<"User "<<userId<<endl;
        std::cout<<"Username - "<<Username<<endl;
        std::cout<<"Email - "<<Email<<endl;
    }
    static void userCountPrint(){
        std::cout<<"Number of users: "<<numOfUsers<<endl; 
    }
};

int User::numOfUsers = 0;

class abstractNote {
    public:
    virtual string getTopicName() const = 0;
    virtual string getNoteContent() const = 0;
    virtual void setTopicName(string newTopicName) = 0;
    virtual void setNoteContent(string newNoteContent) = 0;
    virtual void print() const = 0;
    virtual ~abstractNote(){};
};

class Note:public abstractNote{
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
    ~Note(){
        std::cout<<TopicName<<" notes deleted successfully."<<endl<<endl; 
    }

    string getTopicName() const{
        return TopicName;
    }
    string getNoteContent() const{
        return NoteContent;
    }
    void setTopicName(string newTopicname){
        this->TopicName = newTopicname;
    }
    void setNoteContent(string newNoteContent){
        this->NoteContent = newNoteContent;
    }

    void print() const{
        std::cout<<"Topic - "<<TopicName<<endl;
        std::cout<<"NoteContent - "<<NoteContent<<endl;
    }
    static void notesCountPrint(){
        std::cout<<"Number of notes: "<<numOfNotes<<endl; 
    }
};

int Note::numOfNotes = 0;

class Roles: public User{
    private:
    string role;

    public:
    Roles(string s,string e,string r):User(s,e){
        this->role = r;
    }    
    void setRole(string r){
        this->role = r;
    } 
    string getRole() const{
        return role;
    }
    void printRole() const{
        std::cout<<"Role - "<<role<<endl;
    }
    void print() const{
        User::print();
        printRole();
    }
};

int main(){
    std::cout<<"New data is being added below:-"<<endl;
    std::cout<<endl;

    const int numOfData = 3;
    abstractUser* userData[numOfData];
    abstractNote* noteData[numOfData];

    string usernames[]={"Piyush","Rutuj","Danny"};
    string emails[]={"piyushb@gmail.com","rutuj@gmail.com","dan@gmail.com"};
    string topics[]={"C++","DBMS","HTML"};
    string noteContents[]={"A programming","Database Management System","Web Development Language"};

    userData[0] = new Roles(usernames[0],emails[0],"Admin");
    for (int i = 1; i < numOfData; i++) {
        userData[i] = new Roles(usernames[i], emails[i],"User");
    }
    for (int i = 0; i < numOfData; i++){
        noteData[i] = new Note(topics[i], noteContents[i]);
    }

    userData[0]->setUsername("Piyush123");
    noteData[0]->setTopicName("Python");

    for (int i=0;i<numOfData;i++){
        userData[i]->print();
        noteData[i]->print();
        std::cout<<endl;
    };
    std::cout<<"Starting Deleting Process..."<<endl<<endl;
    for (int i=0;i<numOfData;i++){
        delete userData[i];
        delete noteData[i];
    };
    std::cout<<"All data deleted Successfully..."<<endl;

    std::cout<<endl;
    std::cout<<"Summmary of all Data - "<<endl;
    User::userCountPrint();
    Note::notesCountPrint();
    std::cout<<endl;
    
    
    return 0; 
}