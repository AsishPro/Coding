#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count=0;
class student{
    public:
    int roll_no;
    string name;
    int marks[5];
}s[100];

void add_student(){
    cout<<"Enter roll number: ";
    cin>>s[count].roll_no;
    cout<<"Enter name: ";
    cin>>s[count].name;
    for(int i=0; i<5; i++){
        cout<<"Enter marks for subject "<<i+1<<": ";
        cin>>s[count].marks[i];
    }
    count++;
}

void view_student(){
    for(int i=0; i<count; i++){
        cout<<"\nRoll Number: "<<s[i].roll_no<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        for(int j=0; j<5; j++){
            cout<<"Marks for subject "<<j+1<<": "<<s[i].marks[j]<<endl;
        }
    }
}

void save_student(){
    ofstream outFile;
    outFile.open("student.txt");
    for(int i=0; i<count; i++){
        outFile<<s[i].roll_no<<' '<<s[i].name<<' ';
        for(int j=0; j<5; j++){
            outFile<<s[i].marks[j]<<' ';
        }
        outFile<<"\n";
    }
    outFile.close();
}
void read_student(){
    ifstream inp;
    inp.open("student.txt");
    count=0;
    while(inp>>s[count].roll_no){
        inp>>s[count].name;
        for(int i=0;i<5;i++){
        inp>>s[count].marks[i];
        } 
        count++;       
    }
    inp.close();
}

void view_subject_list(){
    int roll_no;
    cout<<"Enter roll number: ";
    cin>>roll_no;
    cout<<"Subject List\n";
    for(int i=0; i<count; i++){
        if(s[i].roll_no == roll_no){
            for(int j=0; j<5; j++){
                cout<<"Subject "<<j+1<<s[i].marks[j]<<endl;
            }
            break;
        }
    }
}

void view_academic_performance(){
    int roll_no;
    cout<<"Enter roll number: ";
    cin>>roll_no;
    int no;
    for(int i=0; i<count; i++){
        if(s[i].roll_no == roll_no){
            int total = 0;
            for(int j=0; j<5; j++){
                total += s[i].marks[j];
            }
            cout<<"Total marks: "<<total<<endl;
            cout<<"Percentage: "<<(total/5.0)<<endl;
            break;
        }
    }
}


int main(){
    int choice, role,sub;
    read_student();
    cout<<"Enter role (1 - admin, 2 - student): ";
     cin>>role;
     while(1){
            if(role == 1){
                cout<<endl;
                cout<<"1. Add Student\n2. View Student\n3. Save Student\n4. Quit\n";
                cout<<"Enter choice: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        add_student();
                        break;
                    case 2:
                        view_student();
                        break;
                    case 3:
                        save_student();
                        break;
                    case 5:{
                        cout<<"Enter the Student number to add subject names :";
                        cin>>sub;
                    }
                    case 4:
                        save_student();
                        return 0;
                    default:
                        cout<<"Invalid choice\n";
                }
            }
            else if(role == 2){
                cout<<"1. View Subject List\n2. View Academic Performance\n3. Quit\n";
                cout<<"Enter choice: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        view_subject_list();
                        break;
                    case 2:
                        view_academic_performance();
                        break;
                    case 3:
                        return 0;
                    default:
                        cout<<"Invalid choice\n";
                }
            }
            else{
                cout<<"Invalid role\n";
            }
     }
        return 0;
    }