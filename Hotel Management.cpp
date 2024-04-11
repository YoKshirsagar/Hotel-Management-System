#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
fstream file;

class manager
{
    string name;
    string password;

public:
    void setpassword()
    {
        cout << "\t\tENTER YOUR NAME" << endl
             << "\t\t";
        cin >> name;
        cout << "\t\tENTER YOUR PASSWORD" << endl
             << "\t\t";
        cin >> password;
    }

    int checkpassword(string s)
    {
        if (password.compare(s) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
class person
{
protected:
    string name;
    long long ph_no;
    string adress;

public:
    person()
    {
        cout << "\t\tEnter Your Name" << endl
             << "\t\t";
        cin >> name;

        cout << "\t\tEnter Your Phone Number" << endl
             << "\t\t";
        cin >> ph_no;

        cout << "\t\tEnter Your Address " << endl
             << "\t\t";
        cin >> adress;
    }

    string return_name()
    {
        return name;
    }

    long long returnph()
    {
        return ph_no;
    }

    string return_adress()
    {
        return adress;
    }

    void putdata()
    {
        cout << "\t\tNAME :- " << name << endl;
        cout << "\t\tPHONE NO :- " << ph_no << endl;
        cout << "\t\tADDRESS :- " << adress << endl;
    }
};
class room
{
protected:
    int no_of_days;
    static int no_of_rooms;
    static int room_count;
    string Ac_NonAc;

public:
    int room_no;
    room()
    {

        if (no_of_rooms > 0)
        {
            no_of_rooms--;

            cout << "\t\tEnter No of days You live in hotel" << endl
                 << "\t\t";
            cin >> no_of_days;

            cout << "\t\tEnter Ac/Non Ac" << endl
                 << "\t\t";
            cin >> Ac_NonAc;
        }
    }

    int returndays()
    {
        return no_of_days;
    }

    string returnac()
    {
        return Ac_NonAc;
    }

    void putdata()
    {
        cout << "\t\tNUMBER OF DAYS :- " << no_of_days << endl;
        cout << "\t\tROOM NUMBER :- " << room_no << endl;
        cout << "\t\tROOM :- " << Ac_NonAc << endl
             << endl;
    }

    friend struct free_room *new_customer(struct node *head, int room, struct free_room *first);
    friend void *display_room(struct free_room *first);
    friend struct node *remove_customer(struct node *head, int id, struct free_room *first);
    friend struct free_room *rooms(struct free_room *first);
};
int room ::no_of_rooms = 5;
int room ::room_count = 1000;
class food
{
protected:
    string s;
    int total_bill_of_food;

public:
    food()
    {
        total_bill_of_food = 0;
    }

    void getdata();
    void calculate();

    void putdata()
    {
        cout << "\t\tFOOD BILL :- " << total_bill_of_food << endl
             << "\t\t";
    }
};
inline void food ::getdata()
{
    cout << "\t\tEnter Food Name" << endl
         << "\t\t";
    cin >> s;
    calculate();
}
inline void food ::calculate()
{
    total_bill_of_food = total_bill_of_food + 100;
    cout << "\t\tBILL = " << total_bill_of_food << endl
         << "\t\t";
}
class cost : public room, public food
{
protected:
    int total_cost;

public:
    void cost_calculate()
    {
        total_cost = total_bill_of_food + (500 * no_of_days);
    }

    void putdata()
    {
        cost_calculate();
        cout << "\t**BILL**" << endl;
        cout << "\t\tROOM RENT  :- " << (500 * no_of_days) << endl;
        cout << "\t\tFOOD BILL  :- " << total_bill_of_food << endl;
        cout << "\t\tTOTAL BILL :- " << total_cost << endl;
    }
};
class customer : virtual public person, public cost
{
    static int count;
    string password;

public:
    int customer_id;

public:
    customer()
    {
        count++;
        customer_id = count;
        cout << "\t\tENTER YOUR PASSWORD" << endl
             << "\t\t";
        cin >> password;
        cout << "\t\tYour id is " << customer_id << endl
             << "\t\t";
    }

    int checkpassword(string s)
    {
        if (s.compare(password) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void getdata1()
    {
        cout << "\t\tID = " << customer_id << endl
             << "\t\t";
    }

    void putdata()
    {
        person::putdata();
        cout << "\t\tCUSTOMER ID :- " << customer_id << endl;
        room::putdata();
    }

    int returnid()
    {
        return customer_id;
    }
};
int customer ::count = 100;

struct free_room
{
    int data;
    struct free_room *next;
};

struct free_room *rooms(struct free_room *first)
{
    struct free_room *p;
    struct free_room *q;
    struct free_room *r;
    struct free_room *s;
    struct free_room *t;
    q = new struct free_room;
    r = new struct free_room;
    s = new struct free_room;
    t = new struct free_room;
    first = new struct free_room;
    p = first;

    p->data = cost::room_count + 1;
    p->next = q;

    q->data = cost::room_count + 2;
    q->next = r;

    r->data = cost::room_count + 3;
    r->next = s;

    s->data = cost::room_count + 4;
    s->next = t;

    t->data = cost::room_count + 5;
    t->next = NULL;

    return first;
}
struct free_room *empty(struct free_room *first)
{
    struct free_room *p;
    p = first;
    while (p != NULL)
    {
        cout << "\t\t" << p->data << endl;
        p = p->next;
    }
    return first;
}

struct node
{
    customer c;
    struct node *next;
};

struct node *new_customer(struct node *head, int room)
{
    if (head == NULL)
    {
        head = new struct node;
        head->c.room_no = room;
        head->next = NULL;
    }
    else
    {
        struct node *p1 = head;
        struct node *ptr1 = new struct node;
        ptr1->c.room_no = room;
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        ptr1->next = p1->next;
        p1->next = ptr1;
    }
    cout << "\t\tcustomer inserted successfully" << endl;
    return head;
}

struct free_room *new_customer(struct node *head, int room, struct free_room *first, int *check)
{
    int room_found;
    struct free_room *p;
    struct free_room *q;
    p = first;
    if (p != NULL)
    {
        if (p->data == room)
        {
            if (p->next == NULL)
            {
                first = NULL;
                free(p);
            }
            else
            {
                first = first->next;
                free(p);
            }
            room_found = 1;
        }
        else
        {
            q = first->next;
            while (q != NULL)
            {
                if (q->data == room)
                {

                    p->next = q->next;
                    free(q);
                    room_found = 1;
                    break;
                }
                else
                {
                    room_found = 0;
                }
                p = p->next;
                q = q->next;
            }
        }

        if (room_found == 1)
        {
            *check = 1;
        }
        else
        {
            *check = 0;
            cout << "\t\tInvalid Room No\n"
                 << endl;
        }
    }
    else
    {
        *check = 0;
        cout << "\t\tRooms Housefull \n"
             << endl;
    }

    return first;
}

struct free_room *remove_customer(struct free_room *first, int room)
{
    struct free_room *p1;
    p1 = first;
    if (p1 == NULL)
    {
        p1 = new struct free_room;
        p1->data = room;
    }
    else
    {

        struct free_room *ptr;
        ptr = new struct free_room;
        ptr->data = room;
        while (p1->next != NULL)
        {

            if (p1->next->data < room)
            {
                ptr->next = p1->next;
                p1->next = ptr;
                break;
            }
            p1 = p1->next;
        }
        if (p1->next == NULL)
        {
            ptr->next = p1->next;
            p1->next = ptr;
        }
    }

    return first;
}

struct node *remove_customer(struct node *head, int id, struct free_room *first, int *check, int &room)
{
    int found_id = 0;
    struct node *p;
    p = head;

    if (head != NULL)
    {
        if (p->c.customer_id == id)
        {
            p->c.cost::putdata();
            getch();
            head = head->next;
            *check = 1;
            free(p);
            cout << "\t\tCUSTOMER REMOVED" << endl
                 << "\t\t";
            goto end;
        }
        while (p != NULL)
        {
            if (p->c.customer_id == id)
            {
                found_id = 1;
                break;
            }
            p = p->next;
        }

        if (found_id == 1)
        {
            struct node *q;
            q = head;
            if (head->next == NULL && head->c.customer_id == id)
            {
                head->c.cost::putdata();
                getch();
                room = head->c.room_no;
                head == NULL;
            }
            else
            {
                while (q->next != p)
                {
                    q = q->next;
                }
                p->c.cost::putdata();
                getch();
                room = p->c.room_no;
                q->next = p->next;
                free(p);
            }
            cout << "\t\tCUSTOMER REMOVED" << endl
                 << "\t\t";
            *check = 1;
        }
        else
        {
            *check = 0;
            cout << "\t\tInvalid Id\n"
                 << endl;
        }
    }
    else
    {
        *check = 0;
        cout << "\t\tEMPTY HOTEL\n"
             << endl;
    }
end:

    return head;
}

struct node *display(struct node *head)
{
    int i = 1;
    struct node *p = head;
    while (p != NULL)
    {
        cout << "\t\t" << i << ") Id = " << p->c.customer_id << endl;
        p = p->next;
        i++;
    }
    return head;
}

struct node *food_order(struct node *head, int id)
{
    string s;
    struct node *p = head;
    while (p != NULL)
    {
        if (p->c.customer_id == id)
        {
            break;
        }
        p = p->next;
    }
    if (p != NULL)
    {
        cout << "\t\tENTER YOUR PASSWORD" << endl
             << "\t\t";
        cin >> s;
        if (p->c.checkpassword(s) == 1)
        {
            p->c.getdata();
        }
        else
        {
            cout << "\t\tWRONG PASSWORD" << endl
                 << "\t\t";
        }
    }
    else
    {
        cout << "\t\tInvalid Customer ID" << endl
             << "\t\t";
    }
    return head;
}

struct node *search(struct node *head, int &id)
{
    struct node *p = head;
    while (p != NULL)
    {
        if (p->c.customer_id == id)
        {
            id = 1;
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        id = 0;
    }

    return head;
}

struct node *search(struct node *head, string name)
{
    struct node *p = head;
    string s;
    while (p != NULL)
    {
        s = p->c.return_name();
        if (s.compare(name) == 0)
        {
            cout << "\t\tCUSTOMER FOUND" << endl;
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\t\tCUSTOMER NOT FOUND" << endl;
    }

    return head;
}

struct node *info(struct node *head, int id)
{
    string s;
    struct node *p = head;
    while (p != NULL)
    {
        if (p->c.customer_id == id)
        {
            cout << "\t\tENTER YOUR PASSWORD" << endl;
            cin >> s;
            system("cls");
            if (p->c.checkpassword(s) == 1)
            {
                p->c.putdata();
            }
            else
            {
                cout << "\t\tWRONG PASSWORD" << endl;
            }
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\t\tINVALID ID" << endl;
    }

    return head;
}

int main()
{
    fstream file;

    manager m;
    string name, pass;
    int a, id, room, check = 0, chk = 0;
    int b, c;
    struct free_room *first;
    first = NULL;
    first = rooms(first);
    struct node *head;
    struct node *f;
    head = NULL;
    system("cls");

    cout << endl
         << endl
         << "\t\t\t\t\t\t\tHOTEL MANAGEMENT SYSTEM" << endl;
    cout << endl
         << endl
         << "\t\tMANAGER LOGIN" << endl;
    m.setpassword();
    do
    {
        cout << "\t\t1.MANAGER" << endl
             << "\t\t2.CUSTOMER" << endl
             << "\t\t3.EXIT" << endl
             << "\t\t";
        cin >> b;
        system("cls");
        switch (b)
        {
        case 1:
            cout << "\t\tHELLO MANAGER" << endl
                 << "\t\tENTER YOUR PASSWORD" << endl
                 << "\t\t";
            cin >> pass;
            system("cls");
            if (m.checkpassword(pass) == 1)
            {
                do
                {
                    printf("1.NEW CUSTOMER \n2.DISPLAY ID \n3.REMOVE CUSTOMER\n4.DISPLAY INFORMATION OF CUSTOMER\n5.Display file\n6.Search in file\n7.BACK\n");
                    scanf("%d", &a);
                    system("cls");
                    if (a == 1)
                    {
                        if (first != NULL)
                        {
                            cout << "\t\tFree Rooms Are :" << endl;
                            first = empty(first);
                            cout << endl
                                 << "\t\tEnter Room No :" << endl
                                 << "\t\t";
                            cin >> room;
                            first = new_customer(head, room, first, &check);
                            if (check == 1)
                            {
                                head = new_customer(head, room);
                                f = head;
                                while (f->next != NULL)
                                {
                                    f = f->next;
                                }
                                file.open("file.csv", ios::in | ios::app | ios::out);
                                file.seekg(0, ios::end);
                                string init = "Customer Id,Customer Name,Phone Number,Address,No of days live in hotel,AC/NON AC,room no";
                                if (file.tellg() == 0)
                                {
                                    file << init << "\n";
                                }

                                file << f->c.customer_id << ",";
                                file << f->c.return_name() << ",";
                                file << f->c.returnph() << ",";
                                file << f->c.return_adress() << ",";
                                file << f->c.returndays() << ",";
                                file << f->c.returnac() << ",";
                                file << room << ",\n";
                                file.close();

                                file.open("file2.txt", ios::in | ios::app | ios::out);

                                file << f->c.customer_id << endl;
                                file << f->c.return_name() << endl;
                                file << f->c.returnph() << endl;
                                file << f->c.return_adress() << endl;
                                file << f->c.returndays() << endl;
                                file << f->c.returnac() << endl;
                                file << room << endl;
                                file.close();
                            }
                            check = 0;
                        }
                        else
                        {
                            printf("\t\tROOMS HOUSEFULL \n");
                        }
                        getch();
                    }
                    if (a == 2)
                    {
                        head = display(head);
                        getch();
                    }
                    if (a == 3)
                    {
                        printf("\t\tEnter Your ID\n");
                        scanf("%d", &id);
                        system("cls");
                        head = remove_customer(head, id, first, &chk, room);
                        if (chk == 1)
                        {
                            first = remove_customer(first, room);
                        }
                        chk = 0;
                        getch();
                    }
                    if (a == 4)
                    {
                        cout << "\t\tEnter ID" << endl
                             << endl
                             << "\t\t";
                        cin >> id;
                        system("cls");
                        head = info(head, id);
                        getch();
                    }
                    if (a == 5)
                    {
                        file.open("file2.txt");
                        while (file.good())
                        {
                            getline(file, name);

                            check = 1;

                            cout << "Customer ID               : " << name << endl;
                            getline(file, name);
                            cout << "NAME                      : " << name << endl;
                            getline(file, name);
                            cout << "PHONE NUMBER              : " << name << endl;
                            getline(file, name);
                            cout << "ADRESS                    : " << name << endl;
                            getline(file, name);
                            cout << "NO OF DAYS STAY IN HOTEL  : " << name << endl;
                            getline(file, name);
                            cout << "ROOM TYPE                 : " << name << endl;
                            getline(file, name);
                            cout << "ROOM NUMBER               : " << room << endl
                                 << endl;
                        }
                        if (check == 0)
                        {
                            cout << "NO DATA FOUND" << endl;
                        }
                        else
                        {
                            check = 0;
                        }
                        file.close();
                        getch();
                    }
                    if (a == 6)
                    {
                        check = 0;
                        cout << "ENTER NAME " << endl;
                        cin >> pass;
                        system("cls");
                        file.open("file2.txt");
                        while (file.good())
                        {
                            getline(file, name);
                            if (pass == name)
                            {
                                check = 1;

                                cout << "NAME                      : " << name << endl;
                                getline(file, name);
                                cout << "PHONE NUMBER              : " << name << endl;
                                getline(file, name);
                                cout << "ADRESS                    : " << name << endl;
                                getline(file, name);
                                cout << "NO OF DAYS STAY IN HOTEL  : " << name << endl;
                                getline(file, name);
                                cout << "ROOM TYPE                 : " << name << endl;
                                getline(file, name);
                                cout << "ROOM NUMBER               : " << room << endl
                                     << endl;
                            }
                        }
                        if (check == 0)
                        {
                            cout << "NO DATA FOUND" << endl;
                        }
                        else
                        {
                            check = 0;
                        }
                        file.close();
                        getch();
                    }

                    system("cls");
                } while (a != 7);
            }
            else
            {
                cout << "\t\tINVALID PASSWORD" << endl
                     << "\t\t";
                getch();
            }
            system("cls");
            break;
        case 2:
            do
            {
                cout << "\t\t1.DISPLAY FREE ROOMS" << endl
                     << "\t\t2.SERVICES" << endl
                     << "\t\t3.BACK" << endl
                     << "\t\t";
                cin >> c;
                system("cls");
                switch (c)
                {
                case 1:
                    first = empty(first);
                    getch();
                    system("cls");

                    break;
                case 2:
                    do
                    {
                        cout << endl
                             << "\t\t1.FOOD ORDER" << endl
                             << "\t\t2.SEARCHING CUSTOMER" << endl
                             << "\t\t3.BACK" << endl
                             << "\t\t";
                        cin >> a;
                        system("cls");
                        switch (a)
                        {
                        case 1:
                            cout << "\t\tEnter Your ID" << endl
                                 << "\t\t";
                            cin >> id;
                            system("cls");
                            head = food_order(head, id);
                            getch();
                            system("cls");
                            break;
                        case 2:
                            cout << "\t\tSearch By :" << endl
                                 << "\t\t1.ID" << endl
                                 << "\t\t2.NAME" << endl
                                 << "\t\t3.BACK" << endl
                                 << "\t\t";
                            cin >> room;
                            system("cls");
                            switch (room)
                            {
                            case 1:
                                cout << "\t\tENTER ID OF CUSTOMER" << endl
                                     << "\t\t";
                                cin >> id;
                                head = search(head, id);
                                if (id == 1)
                                {
                                    cout << "\t\tCUSTOMER FOUND" << endl
                                         << "\t\t";
                                }
                                else if (id == 0)
                                {
                                    cout << "\t\tCUSTOMER  NOT FOUND" << endl
                                         << "\t\t";
                                }
                                getch();
                                system("cls");
                                break;
                            case 2:
                                cout << "\t\tENTER NAME OF CUSTOMER" << endl
                                     << "\t\t";
                                cin >> name;
                                head = search(head, name);
                                getch();
                                system("cls");
                                break;
                            }
                            break;
                        }
                        system("cls");
                    } while (a != 3);
                }
                system("cls");
            } while (c != 3);
            break;
        }
        system("cls");
    } while (b != 3);

    system("cls");
    cout << "\t\tThank You \n\t\tVisit Again\n\n\t\t";
    return 0;
}


