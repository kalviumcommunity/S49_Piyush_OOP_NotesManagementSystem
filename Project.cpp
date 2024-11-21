#include <iostream>
#include <string>
#include <vector>
using namespace std;

class abstractUser{
    public:
    virtual string getUsername() const = 0;
    virtual string getEmail() const = 0;
    virtual int getUserId() const = 0;
    virtual void setUsername(string newUsername) = 0;
    virtual void setEmail(string newEmail) = 0;
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
    int getUserId() const{
        return userId;
    }
    void setUsername(string newUsername){
        this->Username = newUsername;
    }
    void setEmail(string newEmail){
        this->Email = newEmail;
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
    static void notesCountPrint(){
        std::cout<<"Number of notes: "<<numOfNotes<<endl; 
    }
};

int Note::numOfNotes = 0;

class abstractRole{
    public:
    virtual string getRole() const = 0;
    virtual void printPermissions() const = 0;
    virtual ~abstractRole(){};
};

class adminRole:public abstractRole{
    public:
    string getRole() const override{
        return "Admin";
    }
    void printPermissions() const override{
        std::cout<<"Admin's privilages - Update , Delete , Create and Read."<<endl;
    }
};

class userRole:public abstractRole{
    public:
    string getRole() const override{
        return "User";
    }
    void printPermissions() const override{
        std::cout<<"User's privilages - Create and Read."<<endl;
    }
};


class Roles: public User{
    private:
    abstractRole* role;

    public:
    Roles(string s,string e,abstractRole* r):User(s,e),role(r){}
    ~Roles(){
        delete role;
    }    
    string getRole() const {
        return role->getRole();
    }
    void printPermissions() const{
        role->printPermissions();
    }
};

class userPrinter{
    public:
    static void printUserData(const User& u) {
        std::cout<<"User ID: "<<u.getUserId()<<endl;
        std::cout<<"Username: "<<u.getUsername()<<endl;
        std::cout<<"Email: "<<u.getEmail()<<endl;
    }
};

class notesPrinter{
    public:
    static void printNoteData(const Note& n) {
        std::cout<<"Topic: "<<n.getTopicName()<<endl;
        std::cout<<"Note Content: "<<n.getNoteContent()<<endl;
    }
};

class rolePrinter{
    public:
    static void printRoleData(const Roles& r){
        std::cout<<"Role: "<<r.getRole()<<endl;
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
    string noteContents[]={"A programming Language","Database Management System","Web Development Language"};

    userData[0] = new Roles(usernames[0],emails[0],new adminRole());
    for (int i = 1; i < numOfData; i++) {
        userData[i] = new Roles(usernames[i], emails[i],new userRole());
    }
    for (int i = 0; i < numOfData; i++){
        noteData[i] = new Note(topics[i], noteContents[i]);
    }

    userData[0]->setUsername("Piyush123");
    noteData[0]->setTopicName("Python");

    for (int i = 0; i < numOfData; i++) {
        Roles* role = dynamic_cast<Roles*>(userData[i]); 
        
        userPrinter::printUserData(*role); 
        rolePrinter::printRoleData(*role);
        role->printPermissions();

        Note* note = dynamic_cast<Note*>(noteData[i]);
        notesPrinter::printNoteData(*note); 
        std::cout << endl;
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


