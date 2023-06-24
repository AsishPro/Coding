#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count=0;
class student{
    public:
    int roll_no;
    string name,course_id,course,club_id,club_name;
    int marks[5];
}s[100],c[100],cl[100];

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

void add_course(){
    cout<<"Enter Course id: ";
    cin>>c[count].course_id;
    cout<<"Enter Course name: ";
    cin>>c[count].course;
    count++;
}

void view_course(){
    for(int i=0; i<count; i++){
        cout<<"\n Course id: "<<c[i].course_id<<endl;
        cout<<"Course name: "<<c[i].course<<endl;    
    }
}

void save_course(){
    ofstream outFile;
    outFile.open("course.txt");
    for(int i=0; i<count; i++){
        outFile<<c[i].course_id<<' '<<c[i].course<<endl;
    }
    outFile.close();
}
void read_course(){
    ifstream inp;
    inp.open("course.txt");
    count=0;
    while(inp>>c[count].course_id){
        inp>>c[count].course;
        for(int i=0;i<5;i++){
        inp>>s[count].marks[i];
        } 
        count++;       
    }
    inp.close();
}


void add_club(){
    cout<<"Enter Club id: ";
    cin>>cl[count].club_id;
    cout<<"Enter Club name: ";
    cin>>cl[count].club_name;
    count++;
}

void view_club(){
    for(int i=0; i<count; i++){
        cout<<"\n Club id: "<<cl[i].club_id<<endl;
        cout<<"Club name: "<<cl[i].club_name<<endl;
    }
}

void save_club(){
    ofstream outFile;
    outFile.open("club.txt");
    for(int i=0; i<count; i++){
        outFile<<cl[i].club_id<<' '<<cl[i].club_name<<endl;
    }
    outFile.close();
}
void read_club(){
ifstream inp;
    inp.open("club.txt");
    count=0;
    while(inp>>s[count].club_id){
        inp>>s[count].club_name;
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
    int choice, role;
    read_student();
    read_course();
    read_club();

    cout<<"Enter role (1 - admin, 2 - student): ";
     cin>>role;
     while(1){
            if(role == 1){
                cout<<endl;
                cout<<"1. Add Student\n2. View Student\n3. Save Student\n4. Add Course\n5. View Course\n6. Save Course\n7. Add Club\n8. View Club\n9. Save Club\n10. View Performance\n11. exit\n";
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
                    case 4:
                        add_course();
                        break;
                    case 5:
                        view_course();
                        break;
                    case 6:
                        save_course();
                        break;
                    case 7:
                        add_club();
                        break;
                    case 8:
                        view_club();
                        break;
                    case 9:
                        save_club();
                        break;
                    case 10:
                        view_academic_performance();
                        break;
                    case 11:
                        main();
                        break;
                    default:
                        cout<<"Invalid choice\n";
                }
            }
            else if(role == 2){
                cout<<"1. View Subject List\n2. View Club\n3. View Academic Performance\n4. Quit\n";
                cout<<"Enter choice: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        view_subject_list();
                        break;
                    case 2:
                        view_club();
                        break;
                    case 3:
                        view_academic_performance();
                        break;
                    case 4:
                        main();
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