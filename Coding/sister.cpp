#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char u[100],p[100];
struct Room
{
  int roomId;
  string roomName;
  int seatingCapacity;
  string comments;
  vector<string> facultyAndStaff;
};
struct Admin
{
int adminId;
string adminName;
string adminpassword;
};

// Function to save the Room details to the file
void saveRoomDetails(vector<Room> &roomDetails)
{
  ofstream outFile("roomDetails.txt");

  for(int i = 0; i < roomDetails.size(); i++)
  {
    outFile << roomDetails[i].roomId << " " << roomDetails[i].roomName << " " << roomDetails[i].seatingCapacity << " " << roomDetails[i].comments << " ";
    for(int j = 0;j < roomDetails[i].facultyAndStaff.size(); j++)
    {
      outFile << roomDetails[i].facultyAndStaff[j] << " ";
    }
    outFile << "\n";
  }
  outFile.close();
}

void savepass()
{
  ofstream test("pass.txt");
  test<<u<<" "<<p;
  test.close();
}
void readpass()
{
  ifstream test("pass.txt");
  test>>u>>p;
  test.close();
}

// Function to load the Room details from the file
void loadRoomDetails(vector<Room> &roomDetails)
{
  ifstream inFile("roomDetails.txt");
  Room tempRoom;
  string tempString;
  while(inFile >> tempRoom.roomId >> tempRoom.roomName >> tempRoom.seatingCapacity >> tempRoom.comments)
  {
    while(inFile >> tempString && tempString != "\n")
    {
      tempRoom.facultyAndStaff.push_back(tempString);
    }
    roomDetails.push_back(tempRoom);
    tempRoom.facultyAndStaff.clear();
  }
  inFile.close();
}

// Function to add a Room
void addRoom(vector<Room> &roomDetails)
{
  Room tempRoom;
  cout << "Enter Room Id: ";
  cin >> tempRoom.roomId;
  cout << "Enter Room Name: ";
  cin >> tempRoom.roomName;
  cout << "Enter Seating Capacity: ";
  cin >> tempRoom.seatingCapacity;
  cout << "Enter Comments: ";
  cin >> tempRoom.comments;
  roomDetails.push_back(tempRoom);
}

// Function to delete a Room
void deleteRoom(vector<Room> &roomDetails)
{
  int roomId;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
      roomDetails.erase(roomDetails.begin() + i);
      break;
    }
  }
}

// Function to add Faculty and Staff
void addFacultyAndStaff(vector<Room> &roomDetails)
{
  int roomId;
  string faculty;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
      cout << "Enter the Faculty and Staff name: ";
      cin >> faculty;
      roomDetails[i].facultyAndStaff.push_back(faculty);
      break;
    }
  }
}

// Function to delete Faculty and Staff
void deleteFacultyAndStaff(vector<Room> &roomDetails)
{
  int roomId;
  string faculty;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
      cout << "Enter the Faculty and Staff name: ";
      cin >> faculty;
      for(int j = 0; j < roomDetails[i].facultyAndStaff.size(); j++)
      {
        if(roomDetails[i].facultyAndStaff[j] == faculty)
        {
          roomDetails[i].facultyAndStaff.erase(roomDetails[i].facultyAndStaff.begin() + j);
          break;
        }
      }
      break;
    }
  }
}

// Function to change the Room details
void changeRoomDetails(vector<Room> &roomDetails)
{
  int roomId;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
      cout << "Enter the new Room Name: ";
      cin >> roomDetails[i].roomName;
      cout << "Enter the new Seating Capacity: ";
      cin >> roomDetails[i].seatingCapacity;
      cout << "Enter the new Comments: ";
      cin >> roomDetails[i].comments;
      break;
    }
  }
}

// Function to display the Room details
void displayRoomDetails(vector<Room> &roomDetails)
{
  cout << "Room Id\tRoom Name\tSeating Capacity\tComments\n";
  cout << "-------\t---------\t---------------\t--------\n";
  for(int i = 0; i < roomDetails.size(); i++)
  {
    cout << roomDetails[i].roomId << "\t" << roomDetails[i].roomName << "\t" << roomDetails[i].seatingCapacity << "\t\t" << roomDetails[i].comments << "\n";
  }
}

// Function to display the Faculty and Staff details
void displayFacultyAndStaffDetails(vector<Room> &roomDetails)
{
  int roomId;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  cout << "Faculty and Staff\n";
  cout << "----------------\n";
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
      for(int j = 0; j < roomDetails[i].facultyAndStaff.size(); j++)
      {
        cout << roomDetails[i].facultyAndStaff[j] << "\n";
      }
      break;
    }
  }
}
// function to display Timetable.
void displayTimeTable(vector<Room> &roomDetails)
{
  int roomId;
  cout << "Enter the Room Id: ";
  cin >> roomId;
  cout << "Time Table\n";
  cout << "----------\n";
  for(int i = 0; i < roomDetails.size(); i++)
  {
    if(roomDetails[i].roomId == roomId)
    {
       cout << "Room ID: " << roomDetails[i].roomId << "\n";
      cout << "Room Name: " << roomDetails[i].roomName << "\n";
      cout << "Seating Capacity: " << roomDetails[i].seatingCapacity << "\n";
      cout << "Faculty and Staff: ";
      for(int j = 0; j < roomDetails[i].facultyAndStaff.size(); j++)
      {
        cout << "  " << roomDetails[i].facultyAndStaff[j] << "\n";
      }
      break;
    }
  }
}
// Function to create a new Admin
void createAdmin(vector<Admin> &adminDetails)
{
  Admin tempAdmin;
  cout << "Enter Admin Id: ";
  cin >> tempAdmin.adminId;
  cout << "Enter Admin Name: ";
  cin >> tempAdmin.adminName;
  cout << "Enter Password: ";
  cin >> tempAdmin.adminpassword;
  adminDetails.push_back(tempAdmin);
}
//Function to change the password 
void changepassword()
{
    char setnew[30],cnew[20],ch;
   int i=0;
   

cout<<"Set new password";

do
{
  ch=getch();
  if(ch!=13)
  {
    setnew[i]=ch;
    cout<<"*";
    i++;
  }
  else
  {
    setnew[i]='\0';
  }
} while (ch!=13);

cout<<"\nConfrim new password";

i=0;
do
{
  ch=getch();
  if(ch!=13)
  {
    cnew[i]=ch;
    cout<<"*";
    i++;
  }
  else
  {
    cnew[i]='\0';
  }
} while (ch!=13);
//cin.getline(cnew,20);
if(strcmp(setnew,cnew)==0 )
{
  cout<<"\nPassword matched.....!!!";
  strcpy(p,setnew);
  cout<<p<<' '<<setnew<<endl;
  savepass();
}
else
{
  cout<<"\nUnortherized access...!!!";
}
}
// Admin dashboard
void admin()
{
    vector<Room> roomDetails;
    vector<Admin> adminDetails;
  loadRoomDetails(roomDetails);
  int choice;
  do
  {
    cout << "1. Add Room\n";
    cout << "2. Delete Room\n";
    cout << "3. Add Faculty and Staff\n";
    cout << "4. Delete Faculty and Staff\n";
    cout<<"5.Add admin\n";
    cout << "6. Change Room Details\n";
    cout << "7. Display Room Details\n";
    cout << "8. Display Faculty and Staff Details\n";
    cout<<  "9.display timetable\n";
    cout<< "10.Change password\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
      case 1: addRoom(roomDetails);
              break;

      case 2: deleteRoom(roomDetails);
              break;

      case 3: addFacultyAndStaff(roomDetails);
              break;
      
      case 4: deleteFacultyAndStaff(roomDetails);
              break;

      case 5: createAdmin(adminDetails);
              break;

      case 6: changeRoomDetails(roomDetails);
              break;

      case 7: displayRoomDetails(roomDetails);
              break;

      case 8: displayFacultyAndStaffDetails(roomDetails);
              break;

      case 9: displayTimeTable(roomDetails);
              break;
      case 10:
            changepassword();
            break;
      
    }
  }
  while(choice != 11);
  saveRoomDetails(roomDetails);
}
// Faculty dashboard
void faculty()
{
    vector<Room> roomDetails;
  loadRoomDetails(roomDetails);
  int choice;
  do
  {
    cout << "1. Add Room\n";
    cout << "2. Delete Room\n";
    cout << "3. Add Faculty and Staff\n";
    cout << "4. Delete Faculty and Staff\n";
    cout << "5. Change Room Details\n";
    cout << "6. Display Room Details\n";
    cout << "7. Display Faculty and Staff Details\n";
    cout<<  "8.display timetable\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
      case 1: addRoom(roomDetails);
              break;

      case 2: deleteRoom(roomDetails);
              break;

      case 3: addFacultyAndStaff(roomDetails);
              break;

      case 4: deleteFacultyAndStaff(roomDetails);
              break;

      case 5: changeRoomDetails(roomDetails);
              break;

      case 6: displayRoomDetails(roomDetails);
              break;

      case 7: displayFacultyAndStaffDetails(roomDetails);
              break;

      case 8: displayTimeTable(roomDetails);
              break;
      
    }
  }
  while(choice != 9);
  saveRoomDetails(roomDetails);
}





int main()
{
   readpass();
    // int y=1;
    // if(y=1)
    // system("CLS");
    // y++;
    cout<<"Classroom and Lab management system\n\n";
    cout<<"**Main menu**\n\n";
    cout<<"1.Admin\n\n";
    cout<<"2.Faculty\n\n";
    cout<<"3.exit\n\n";
     cout<<"Enter the choise..\n\n";
    int ch;
    cin>>ch;
    // Login portol.
    switch(ch)
    {
        case 1:
        char name[100],password[100];
        cout<<"Enter the login details:\n\n";
        cout<<"Username: ";
        cin>>name;
        cout<<"\n";
        cout<<"Password: ";
        cin>>password;
        cout<<"\n";
        if((strcmp(name,u)==0 && strcmp(password,p)==0))
        {
            cout<<"Login Successfully...!!!";
            system("CLS");
            cout<<"Welcome Admin...!!!";
            admin();

        }
        else
        {
            cout<<"Login Failed..!";
            system("CLS");
            cout<<"Try again..!";
            main();
        }
        break;
        case 2:
        
        cout<<"Enter the login details:";
        cout<<"Username:";
        cin>>name;
        cout<<"\n";
        cout<<"Password:";
        cin>>password;
        cout<<"\n";
        if(strcmp(name,"Faculty")==0 && strcmp(password,"Faculty234")==0)
        {
            cout<<"Login Successfully...!!!";
            system("CLS");
            cout<<"Welcome Faculty..!!";
            faculty();
        }
        else
        {
            cout<<"Login Failed..!";
            system("CLS");
            cout<<"Try again..!";
            main();
        }
        case 3: exit(0);
        default:cout<<"Choose the correct option..!";


    }
    

}