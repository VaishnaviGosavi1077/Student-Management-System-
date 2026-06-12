#include<iostream>
#include<fstream>
#include<string>
 using namespace std;
 struct student
 {
    int age;
    string name;
    int roll;
 };
 void addstudent()
 {
     student s;
     ofstream file("student.txt",ios::binary|ios::app);
     cout<<"enter students name";
     cin>>s.name;
     cout<<"enter roll number";
     cin>>s.roll;
     cout<<"enter students age";
     cin>>s.age;

     file.write((char*)&s,sizeof(s));
     file.close();

     cout<<"Student added successfully!\n";
 }
 void displaystudent()
 {
    student s;
    ifstream file("student.txt",ios::binary);
    
    cout<<"\n---student record---\n";
    while(file.read((char*)&s,sizeof(s)))
    {
        cout<<"Roll no:"<<s.roll<<endl;
        cout<<"name"<<s.name<<endl;
        cout<<"Age:"<<s.age<<endl;
        cout<<"------------------------------\n";
    }
    file.close();
 }
 void updatestudent()
 {
    student s;
    int rollno;
    bool found=false;
    fstream file("student.txt",ios::binary|ios::in|ios::out);

    cout<<"Enter roll number to update";
    cin>>rollno;

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.roll==rollno)
        {
        cout<<"enter new name:";
         cin>>s.name;
         cout<<"enter new age";
         cin>>s.age;

         file.seekp(-sizeof(s),ios::cur);
         file.write((char*)&s,sizeof(s));
         found=true;
         break;
        }
    }
    file.close();
    if(found)
    cout<<"record updated succesfully\n";
    else
    cout<<"student noot found";
 }
 void deletestudent()
 {
     student s;
     int rollno;
     bool found=false;
     ifstream file("student.txt",ios::binary);
     ofstream temp("temp.txt",ios::binary);

     cout<<"enter roll number";
     cin>>rollno;
     while(file.read((char*)&s,sizeof(s)))
     {
     if(s.roll=rollno)
     {
        temp.write((char*)&s,sizeof(s));
     }
     else{
        found=true;
     }
    }
    file.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(found)
    cout<<"record deleted syccesfully\n";
    else
    cout<<"student not found\n";
 }
 int main()
 {
    int choice;
    do
    {
        cout<<"\n======STUDENT MANAGEMENT======\n";
        cout<<"1.Add student\n";
        cout<<"2.Display student\n";
        cout<<"3.Update student\n";
        cout<<"4.Delete student\n";
        cout<<"5.exit\n";
        cout<<"enter choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
            addstudent();
            break;
            case 2:
            displaystudent();
            break;
            case 3:
            updatestudent();
            break;
            case 4:
            deletestudent();
            break;
            case 5:
            cout<<"THANKYOU!\n";
            break;
            default:
            cout<<"Invalid choice\n";
            break;
        }
    }
    while(choice!=5);
    return 0;
 }