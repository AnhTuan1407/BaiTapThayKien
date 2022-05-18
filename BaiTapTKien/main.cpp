#include<iostream>
#include<list>
#include<fstream>
#include<string>
using namespace std;
class Student{
private:
    string id;
    string name;
public:
    Student();
    Student(const string &id, const string &name) : id(id), name(name) {}
    void output();

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    void editName(char *swapName);

    void editName(string *swapName);
};

Student::Student() {
}

const string &Student::getId() const {
    return id;
}

void Student::setId(const string &id) {
    Student::id = id;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

class StudentService
{
public:
    void display();
    void addStudent();
    void editName();
    list<Student> list;
};

class ReadAndWriteStudent{
public:
    list<Student> readAllStudent(string path);
    void writeAllStudent(string path,list<Student>s);
};
list<Student> ReadAndWriteStudent::readAllStudent(string path) {
    list<Student> list;
    ifstream fi(path,ios_base::in);
    if(fi.is_open()){
        while (1){
            string id;
            string name;
            getline(fi,id,',');
            getline(fi,name);
            if(fi.eof()){
                break;
            }
            Student s(id, name);
            list.push_back(s);
        }
        fi.close();
    } else{
        cout<<"Mo file khong thanh cong"<<endl;
    }
    return list;
}
void ReadAndWriteStudent::writeAllStudent(string path, list<Student> student) {
    ofstream fo(path,ios_base::out);
    if(fo.is_open()){
        for( Student s : student){
            fo<<s.getId()<<","<<s.getName()<<endl;
        }
        fo.close();
    }else{
        cout<<"Ghi file khong thanh cong"<<endl;
    }
}

void StudentService :: addStudent() {
    list = ReadAndWriteStudent().readAllStudent("C:\\Users\\PC\\Desktop\\C++\\BaiTap\\BaiTapThayKien\\BaiTapTKien\\input");
    int j;
    cout<<"Enter Number of Student:";
    cin>>j;
    cin.ignore();
    for(int i=0;i<j;i++){
        int n=list.size();
        string id="DTU000"+ to_string(n);
        string name;
        cout<<"Enter name:";
        getline(cin,name);
        Student s(id,name);
        list.push_back(s);
    }
    ReadAndWriteStudent().writeAllStudent("C:\\Users\\PC\\Desktop\\C++\\BaiTap\\BaiTapThayKien\\BaiTapTKien\\input",list);
}
void Student :: output()
{
    cout << "Id: " << id << ", Name: " << name << endl;
}

void StudentService :: display()
{
    list = ReadAndWriteStudent().readAllStudent("C:\\Users\\PC\\Desktop\\C++\\BaiTap\\BaiTapThayKien\\BaiTapTKien\\input");
    for(Student s : list)
    {
        s.output();
    }
}

void StudentService::editName() {
    string idCheck;
    string swapName;
    cout << "Enter idCheck: ";
    getline(cin, idCheck);

    list = ReadAndWriteStudent().readAllStudent(
            "C:\\Users\\PC\\Desktop\\C++\\BaiTap\\BaiTapThayKien\\BaiTapTKien\\input");
    Student student;
    bool check = true;
    Student *temp;
    for (Student &s: list) {
        if (idCheck == s.getId()) {
            cout << "Swap Name: ";
            getline(cin, swapName);
            s.output();
            temp = &s;
            check = false;
        }
    }
    if (check) {
        cout << "ID is not found!" << endl;
    }else {

        cout << "Swap name: ";
        temp->setName(swapName);
        temp->output();
        ReadAndWriteStudent().writeAllStudent("C:\\Users\\PC\\Desktop\\C++\\BaiTap\\BaiTapThayKien\\BaiTapTKien\\input",list);
    }
}

int main(){
    Student s[100];
    StudentService student;

    while (1)
    {
        int choice;
        cout << "1. Display Student." << endl;
        cout << "2. Add Student." << endl;
        cout << "3. Edit Name." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter your chose: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                student.display();
                break;
            case 2:
                student.addStudent();
                break;
            case 3:
                student.editName();
                break;
            case 4:
                exit(0) ;
                break;
        }
    }



    return 0;
}