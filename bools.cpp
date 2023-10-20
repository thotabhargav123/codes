#include <bits/stdc++.h>
using namespace std;
class books
{
private:
    string author, title, publisher;
    int noofcopies;
    float price;

public:
    void setdata();
    void edit(int choice);
    int search(string heading, string writer);
    void billing();
    void details();
};
void books::setdata()
{
    cout << "Enter the details of the book to store" << endl;
    cout << "Name of the book: ";
     cin.ignore();
     title = " ";
     getline(cin, title);
     // cout << title<<endl;
     cout << "Enter author of the book: ";
     getline(cin, author);
     // cout<<author<<endl;
     cout << "Enter the publisher: ";
     getline(cin, publisher);
     cout << "Enter no of copies of the book avaliable: ";
     cin >> noofcopies;
     // cout<<noofcopies << endl;
     cout << "Enter the price of the book avaliable: ";
     cin >> price;
     // cout<<price << endl;
}
void books::edit(int choice)
{
    cin.ignore();
    if (choice == 0)
    { 
        
        cout << "Name of the book: ";
         
         title = " ";
         getline(cin, title);
         // cout << title<<endl;
         cout << "Enter author of the book: ";
         getline(cin, author);
         // cout<<author<<endl;
         cout << "Enter the publisher: ";
         getline(cin, publisher);
         cout << "Enter no of copies of the book avaliable: ";
         cin >> noofcopies;
         // cout<<noofcopies << endl;
         cout << "Enter the price of the book avaliable: ";
         cin >> price;
         // cout<<price << endl;
    }
    if (choice == 1)
    {
        cout << "Name of the book: ";
        // cin.ignore();
        getline(cin, title);
    }
    if (choice == 2)
    {
        cout << "Enter author of the book: ";
        getline(cin, author);
        // cout<<author<<endl;
    }
    if (choice == 3)
    {
        cout << "Enter the publisher: ";
        getline(cin, publisher);
    }
    if (choice == 4)
    {
        cout << "Enter no of copies of the book avaliable: ";
        cin >> noofcopies;
        // cout<<noofcopies << endl;
    }
    if (choice == 5)
    {
        cout << "Enter the price of the book avaliable: ";
        cin >> price;
        // cout<<price << endl;
    }
}
int books::search(string heading, string writer)
{
    if (heading == title and writer == author)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void books::details()
{
    cout << "Details of the Book You want are:" << endl;
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << price;
    cout << "\nStock Position: " << noofcopies;
}
void books::billing()
{
    cout << "Enter the number of Books want to purchase" << endl;
    int copies;
    cin >> copies;
    if (copies > noofcopies)
    {
        cout << "Sorry, Unfortunately we dont have this many copies" << endl;
        return;
    }
    else
    {
        noofcopies = noofcopies - copies;
        cout << "Total Price is: ";
        cout << float(copies * price) << endl;
    }
}
int main()
{
    // books o1;
    // o1.setdata();
    books o[10];
    int bookindex = 0;
    int t, choice;
    string heading, writer;
    while (true)
    {
        cout << "\n\n\t\tMENU"
             << "\n1. Entry of New Book"
             << "\n2. Buy Book"
             << "\n3. Search For Book"
             << "\n4. Edit Details Of Book"
             << "\n5. Exit"
             << "\n\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            o[bookindex].setdata();
            bookindex++;
            break;
        case 2:
            cin.ignore();
            cout << "Enter the Title: ";
            getline(cin, heading);
            cout << "Enter Author: ";
            getline(cin, writer);
            for (int t = 0; t < bookindex; t++)
            {
                if (o[t].search(heading, writer) == 1)
                {
                    cout << "Book is found successfully" << endl;
                   
                    o[t].billing();
                    break;
                }
            }
            if (t == bookindex)
            {
                cout << "Sorry, we can't find the book You want. please, You may check details correctly" << endl;
            }
            break;
        case 3:
            cin.ignore();
            cout << "enter title: ";
            getline(cin, heading);
          
            cout << "Enter author: ";
            getline(cin, writer);
          
            for (int t = 0; t < bookindex; t++)
            {
                if (o[t].search(heading, writer) == 1)
                {
                    cout << "Book is found successfully" << endl;
                    cout << "Loading details ......." << endl;
                    o[t].details();
                    break;
                }
            }
            if (t == bookindex)
            {
                cout << "Sorry, we can't find the book You want. please, You may check details correctly" << endl;
            }
            break;
        case 4:
             cin.ignore();
            cout << "Enter the Title: ";
            getline(cin, heading);
            cout << "Enter Author: ";
            getline(cin, writer);
            int opt;
            cout << "\n\n\t\tEDIT MENU"
                 << "\n0. Change All Details"
                 << "\n1. Change Title"
                 << "\n2. Chane author"
                 << "\n3. change publisher"
                 << "\n4. Change Price"
                 << "\n5. Change No of copies Available"
                 << "\n\nEnter your Choice: ";
            cin >> opt;
            for (int t = 0; t < bookindex; t++)
            {
                if (o[t].search(heading, writer) == 1)
                {
                    cout << "Book is found successfully" << endl;
                    // cout<<"Loading details ......."<<endl;
                    o[t].edit(opt);
                    break;
                }
            }
            if (t == bookindex)
            {
                cout << "Sorry, we can't find the book You want. please, You may check details correctly" << endl;
            }
            break;

        case 5:
            exit(0);
        default:
            cout << "\nInvalid Choice Entered";
        }
    }
}