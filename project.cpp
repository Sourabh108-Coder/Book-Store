#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Book
{
private:
    char bookname[30];
    int pages, bookid, year;
    char author[20];
    float price;

public:
    float profit, bill;
    int books;
    char kitab[20];
    int rate;

    Book()
    {
        profit = 0;
        bill = 0;
        books = 0;
    }

public:
    void display();      
    void insert();       
    void deleted();      
    void search();       
    void update();       
    void cart();         
    void display_cart(); 
    void buy();          
    void pro();          
    void billing();
};

void Book::display()
{
    cout << "\n\nBook ID"
         << "\t\tBook Name"
         << "\tAuthor"
         << "\t\tPages"
         << "\t\tPrice"
         << "\t\tYear" << endl;
    ifstream oin("store.txt", ios::in);
    while (!oin.eof())
    {
        char ch = oin.get();
        cout << ch;
    }
    oin.close();
}

void Book::insert()
{
    int id;
    cout << "\n Enter the book ID:";
    cin >> id;
    ifstream oin("store.txt", ios::in);
    while (oin >> bookid >> bookname >> author >> pages >> price >> year)
    {
        if (id == bookid)
        {
            cout << "\n Book ID not available";
            display();
            return;
        }
    }
    bookid = id;
    cout << "\n Enter the Book Name:";
    cin >> bookname;
    cout << "\n Enter the Author of the Book:";
    cin >> author;
    cout << "\n Enter the Pages of the Book:";
    cin >> pages;
    cout << "\n Enter the Price of the Book:";
    cin >> price;
    cout << "\n Enter the Year of Publication:";
    cin >> year;
    ofstream out("store.txt", ios::app);
    out << "\n"
        << bookid
        << "\t\t" << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
    out.close();
    display();
}

void Book::deleted()
{
    char book[30], authorname[20], ch;
    int flag = 0;
    cout << "\n Enter Book Name and Author's Name:";
    cin >> book >> authorname;
    ifstream oin("store.txt", ios::in);
    ofstream out("dukaan.txt", ios::app);
    while (oin >> bookid >> bookname >> author >> pages >> price >> year)
    {
        if (strcmp(book, bookname) == 0 && strcmp(authorname, author) == 0)
        {
            flag = 1;
        }
        else
        {
            out << "\n"
                << bookid << "\t\t"
                << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
        }
    }
    oin.close();
    out.close();
    remove("store.txt");
    rename("dukaan.txt", "store.txt");
    if (flag == 1)
    {
        cout << "\n Record deleted successfully";
    }
    else
    {
        cout << "\n Record not found";
    }
    display();
}

void Book::search()
{
    int ch, flag = 0;
    cout << "\n Search By-";
    cout << "\n\t 1. Author's Name";
    cout << "\n\t 2. Book Title";
    cout << "\n\t 3. Book Price";
    cout << "\n\t 4. Year of Publication";

    cout << "\n\n Enter your choice:";
    cin >> ch;
    ifstream oin("store.txt", ios::in);

    switch (ch)
    {
    case 1:
        char auth[20];
        cout << "\n Enter Author's Name:";
        cin >> auth;
        cout << "\n\nBook ID"
             << "\t\tBook Name"
             << "\t\tAuthor"
             << "\t\tPages"
             << "\t\tPrice"
             << "\t\tYear" << endl;
        while (oin >> bookid >> bookname >> author >> pages >> price >> year)
        {
            if (strcmp(auth, author) == 0)
            {
                cout << "\n " << bookid << "\t\t"
                     << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "\n SORRY !! BOOK OF THIS AUTHOR IS NOT AVAILABLE IN THE STORE";
        }
        break;

    case 2:
        char nam[20];
        cout << "\n Enter Book Name:";
        cin >> nam;
        cout << "\n\nBook ID"
             << "\t\tBook Name"
             << "\t\tAuthor"
             << "\t\tPages"
             << "\t\tPrice"
             << "\t\tYear" << endl;
        while (oin >> bookid >> bookname >> author >> pages >> price >> year)
        {
            if (strcmp(nam, bookname) == 0)
            {
                cout << "\n " << bookid << "\t\t"
                     << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "\n SORRY !! BOOK OF THIS NAME IS NOT AVAILABLE IN THE STORE";
        }
        break;

    case 3:
        int rate;
        cout << "\n Enter Book Price:";
        cin >> rate;
        cout << "\n\nBook ID"
             << "\t\tBook Name"
             << "\t\tAuthor"
             << "\t\tPages"
             << "\t\tPrice"
             << "\t\tYear" << endl;
        while (oin >> bookid >> bookname >> author >> pages >> price >> year)
        {
            if (rate == price)
            {
                cout << "\n " << bookid << "\t\t"
                     << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "\n SORRY !! BOOK OF THIS PRICE IS NOT AVAILABLE IN THE STORE";
        }
        break;

    case 4:
        int saal;
        cout << "\n Enter Year of Publication:";
        cin >> saal;
        cout << "\n\nBook ID"
             << "\t\tBook Name"
             << "\t\tAuthor"
             << "\t\tPages"
             << "\t\tPrice"
             << "\t\tYear" << endl;
        while (oin >> bookid >> bookname >> author >> pages >> price >> year)
        {
            if (saal == year)
            {
                cout << "\n " << bookid << "\t\t"
                     << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "\n SORRY !! BOOK OF THIS YEAR IS NOT AVAILABLE IN THE STORE";
            return;
        }
        break;

    default:
        cout << "\n ENTER A VALID CHOICE PLEASE :::";
    }
    char c;
    cout << "\n\n Do you want to add a book into the cart?";
    cout << "\n If Yes then enter Y";
    cout << "\n If No then enter N";
    cout << "\n Enter your choice:";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        cart();
    }
}

void Book::update()
{
    char book[30], authorname[20], ch;
    int flag = 0;
    cout << "\n Enter Book Name and Author's Name:";
    cin >> book >> authorname;
    ifstream oin("store.txt", ios::in);
    ofstream out("dukaan.txt", ios::app);

    while (oin >> bookid >> bookname >> author >> pages >> price >> year)
    {
        if (strcmp(book, bookname) == 0 && strcmp(authorname, author) == 0)
        {
            cout << "\n Book Found::Enter updated record";
            cout << "\n\n Book ID:";
            cin >> bookid;
            cout << "\n Book name:";
            cin >> bookname;
            cout << "\n Author of the book:";
            cin >> author;
            cout << "\n Pages of the book:";
            cin >> pages;
            cout << "\n Price of the book:";
            cin >> price;
            cout << "\n Year of publication:";
            cin >> year;
            out << "\n"
                << bookid << "\t\t"
                << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
            flag = 1;
        }
        else
        {
            out << "\n"
                << bookid << "\t\t"
                << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
        }
    }
    oin.close();
    out.close();
    remove("store.txt");
    rename("dukaan.txt", "store.txt");
    if (flag == 0)
    {
        cout << "\n Record not found";
    }
    display();
}

void Book::cart()
{
    int id, flag = 0;
    float bookprice = 0;
    cout << "\n\n Enter the Book ID to add to cart:";
    cin >> id;
    ifstream oin("store.txt", ios::out);
    ofstream out("cart.txt", ios::app);
    while (oin >> bookid >> bookname >> author >> pages >> price >> year)
    {
        if (id == bookid)
        {
            out << "\n"
                << bookid
                << "\t\t" << bookname << "\t\t" << author << "\t\t" << pages << "\t\t" << price << "\t\t" << year;
            flag = 1;
        }
    }

    if (flag == 1)
    {
        cout << "\n\t BOOKS ARE ADDED TO THE CART SUCCESS FULLY";
    }

    if (flag == 0)
    {
        cout << "\n SORRY !! BOOK OF THIS ID IS NOT AVAILABLE IN THE STORE";
    }
}

void Book::display_cart()
{
    char c;
    cout << "\n\nBook ID"
         << "\t\tBook Name"
         << "\t\tAuthor"
         << "\t\tPages"
         << "\t\tPrice"
         << "\t\tYear" << endl;
    ifstream oin("cart.txt", ios::in);
    while (!oin.eof())
    {
        char ch = oin.get();
        cout << ch;
    }
}

void Book::buy()
{
    display_cart();
    ifstream oin("cart.txt", ios::in);
    ofstream out1("bill.txt", ios ::app);
    while (oin >> bookid >> bookname >> author >> pages >> price >> year)
    {
        bill += price;
        books++;
        out1 << "\t\t" << bookname << "\t\t" << price;
    }
    ifstream oip("profit.txt", ios::in);
    int temp;
    oip >> profit;
    temp = profit;
    profit = temp + bill;
    oip.close();
    remove("profit.txt");
    ofstream oup("profit.txt", ios::out);
    oup << profit;
    ofstream out("temp.txt");
    oin.close();
    out.close();
    remove("cart.txt");
    rename("temp.txt", "cart.txt");
    cout << "\n\n\n THANK YOU FOR PURCHASING!";
}

void Book::pro()
{
    int n1, n2;
    ifstream oin("profit.txt");
    oin.close();
    cout << "\n TOTAL AMOUNT" << profit;
}

void Book::billing()
{
    int n1, n2;
    ifstream oin("bill.txt", ios::in);

    cout << "\n--------------------------------------------";
    cout << "\n\t********GENERATING BILL************";
    cout << "\n--------------------------------------------";

    cout << "\n\n-----------------------------------------------------";

    cout << "\n NAME\t\t PRICE\t\t TIME";

    while (oin >> bookname >> price)
    {
        srand(time(0));
        n1 = (rand() % 12) + 1;
        n2 = rand() % 60;
        cout << "\n"
             << bookname << "\t\t" << price << "\t\t"
             << n1 << ":" << n2 << "P.M";
    }
}

int main()
{
    Book B;
    int id, n, ch, i = 0, j = 3;
    int lid = 6284; // Customer ID
    int oid = 9988; // Manager ID
    char pass[] = "SSSS";
    char p[10];
start:
    system("cls");
    cout << "\n\t\t------------------------------------------------------------";
    cout << "\n\t\t\t    *******WELCOME TO LOGIN PAGE*******";
    cout << "\n\t\t------------------------------------------------------------";
    do
    {
        j--;
        cout << "\n\n\n ENTER USER ID:";
        cin >> id;
        cout << " ENTER PASSWORD:";
        i = 0;
        while (1)
        {
            char c = getch();
            if (c == 13)
            {
                break;
            }
            else if (c == 8)
            {
                cout << "\b \b";
                i--;
            }
            else
            {
                p[i] = c;
                cout << "*";
                i++;
            }
        }
        p[i] = '\0';
        n = strcmp(pass, p);

        if ((n == 0) && (lid == id || id == oid))
        {
            break;
        }
        else
        {
            cout << "\n\n\t#################################";
            cout << "\n\t\t FAILED TO LOGIN :(";
            cout << "\n\t#################################";
        }
    } while (j != 0);
    if ((n != 0) || (lid != id && oid != id))
    {
        return 0;
    }

    if (lid == id)
    {
        cout << "\n\n LOGIN SUCCESSFULLY :)";
        cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
        getch();
        do
        {
            system("cls");
            cout << "\n\t\t------------------------------------------------------------";
            cout << "\n\t\t\t    ***********WELCOME TO CUSTOMER PAGE**********";
            cout << "\n\t\t------------------------------------------------------------";
            cout << "\n\n\t\t\t~~~~~~~~~~~********************~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\n\t\t\t   WELCOME TO BOOK STORE MANAGEMENT SYSTEM";
            cout << "\n\n\t\t\t~~~~~~~~~~~********************~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\n\t\t   !!!!!~~~AVAILABLE FUNCTIONALITIES ARE~~~!!!!!!";

            cout << "\n\n\n 1. Display all the Books";
            cout << "\n 2. Search the books";
            cout << "\n 3. Display the Cart";
            cout << "\n 4. Buy all the Books from the cart";
            cout << "\n 5. Check out Bill";
            cout << "\n 6. Go back to the Login page";
            cout << "\n 7. Exit";

            cout << "\n\n Enter your choice:";
            cin >> ch;
            system("cls");

            switch (ch)
            {
            case 1:
                B.display();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 2:
                B.search();
                cout << "\n\n\t\t\n\n\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 3:
                B.display_cart();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 4:
                B.buy();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 5:
                B.billing();
                cout << "\n\n Number of Books bought: " << B.books;
                cout << "\n\n TOTAL AMOUNT: "
                     << "|" << B.bill << "|";
                cout << "\n-----------------------------------------------------";
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 6:
                goto start;
                break;

            case 7:
                cout << "\n !! EXITING !! \n    THANKU :)";
                break;

            default:
                cout << "\n WRONG CHOICE ENTERED";
            }
            getch();
        } while (ch != 7);
    }
    else
    {
        cout << "\n LOGIN SUCCESSFULLY :)";
        cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
        getch();
        do
        {
            system("cls");
            cout << "\n\t\t------------------------------------------------------------";
            cout << "\n\t\t\t    ***********WELCOME TO MANAGER PAGE**********";
            cout << "\n\t\t------------------------------------------------------------";
            cout << "\n\n\t\t\t~~~~~~~~~~~********************~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\n\t\t\t   WELCOME TO BOOK STORE MANAGEMENT SYSTEM";
            cout << "\n\n\t\t\t~~~~~~~~~~~********************~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\n\t\t   !!!!!~~~AVAILABLE FUNCTIONALITIES ARE~~~!!!!!!";

            cout << "\n\n\n 1. Add the Book into the Store";
            cout << "\n 2. Display all the Books";
            cout << "\n 3. Delete the Books";
            cout << "\n 4. Search the Books";
            cout << "\n 5. Update the Book";
            cout << "\n 6. See the Profit";
            cout << "\n 7. Go back to Login page";
            cout << "\n 8. Exit";

            cout << "\n\n Enter your choice:";
            cin >> ch;
            system("cls");

            switch (ch)
            {
            case 1:
                B.insert();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 2:
                B.display();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 3:
                B.deleted();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 4:
                B.search();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 5:
                B.update();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 6:
                cout << "\n Profit till now:";
                B.pro();
                cout << "\n\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE";
                break;

            case 7:
                goto start;
                break;

            case 8:
                cout << "\n !! EXITING !! \n    THANKU :)";
                cout << "\n PRESS ANY KEY TO CLOSE YOUR PROGRAM";
                break;

            default:
                cout << "\n WRONG CHOICE ENTERED";
            }
            getch();

        } while (ch != 8);
    }

    return 0;
}