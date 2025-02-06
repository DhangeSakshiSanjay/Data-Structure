#include <iostream>
using namespace std;
class Employee {
    public:
    int id, ch;
    string name;
    string department;
    Employee *lc, *rc;
public:
    void create();
    void insert(Employee *root, Employee *next);
    void display(Employee *root);
    void displaywithoutrecursive(Employee *root);
    void displayleafnode(Employee *root);
    void displayintermidiatenode(Employee *root);
    void displaynodedegree2(Employee *root);
} *root = NULL,*st[100];

void Employee::create() {
    root = new Employee;

    cout << "Enter employee information (Id Name Department):\n";
    cin >> root->id >> root->name >> root->department;
    root->lc = root->rc = NULL;
    
    do{
        cout << "Do you want to add a node (1 for yes, 0 for no):\n";
        cin >> ch;
        if (ch == 1) 
        {
            Employee *next = new Employee;
            cout << "Enter new employee details (Id Name Department):\n";
            cin >> next->id >> next->name >> next->department;
            next->lc = next->rc = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}

void Employee::insert(Employee *root, Employee *next)
 {
    char chr;
    cout << "Enter where you want to insert node (Left(L) or Right(R)) for employee with Id " << root->id << ":\n";
    cin >> chr;

    if (chr == 'L' || chr == 'l') {
        if (root->lc == NULL)
        {
            root->lc = next;
        } else 
        {
            insert(root->lc, next);
        }
    } else if (chr == 'R' || chr == 'r') 
    {
        if (root->rc == NULL) {
            root->rc = next;
        } else {
            insert(root->rc, next);
        }
    }
}

void Employee::display(Employee *root)
 {
    if (root == NULL) 
    {
        return;
    }
    display(root->lc);
    cout << "\nId: " << root->id << "\nName: " << root->name << "\nDepartment: " << root->department << endl;
    display(root->rc);
}
void Employee::displaywithoutrecursive(Employee *root) {
   
    Employee *temp;
     int top=-1;
    temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
                top++;
                st[top]=temp;
                temp=temp->lc;
            
            } 
            if(top!=-1)
            {
                temp=st[top];
                top--;
                  cout << "\nId: " << temp->id << "\nName: " << temp->name << "\nDepartment: " << temp->department << endl;
                  temp=temp->rc;
            }
        }while(top!=-1 || temp!=NULL);
    }
}
void Employee::displayleafnode(Employee *root)
 {
   
    Employee *temp;
     int top=-1;
    temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
                top++;
                st[top]=temp;
                temp=temp->lc;
            
            } if(top!=-1)
            {
                temp=st[top];
                top--;
                if(temp->lc==NULL && temp->rc==NULL)
                {
                  cout << "\nId: " << temp->id << "\nName: " << temp->name << "\nDepartment: " << temp->department << endl;
                }
                  temp=temp->rc;
            }
        }while(top!=-1 || temp!=NULL);
    }
}
void Employee::displayintermidiatenode(Employee *root)
 {
   
    Employee *temp;
     int top=-1;
    temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
                top++;
                st[top]=temp;
                temp=temp->lc;
            
            }
             if(top!=-1)
             {
                temp=st[top];
                top--;
                if(temp->lc!=NULL && temp->rc!=NULL)
                {
                  cout << "\nId: " << temp->id << "\nName: " << temp->name << "\nDepartment: " << temp->department << endl;
                }
                  temp=temp->rc;
            }
        }while(top!=-1 || temp!=NULL);
    }
}

void Employee::displaynodedegree2(Employee *root) 
{
   
    Employee *temp;
     int top=-1;
    temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
                top++;
                st[top]=temp;
                temp=temp->lc;
            
            }
             if(top!=-1)
            {
                temp=st[top];
                top--;
                if(temp->lc!=NULL || temp->rc!=NULL)
                {
                  cout << "\nId: " << temp->id << "\nName: " << temp->name << "\nDepartment: " << temp->department << endl;
                }
                  temp=temp->rc;
            }
        }while(top!=-1 || temp!=NULL);
    }
}

int main() {
    Employee emp;
    int choice;

    do {
        cout << "Employee Management System" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Display Employees without using non recursive " << endl;
        cout << "4. Display leaf node " << endl;
        cout << "5. Display intermidiate node " << endl;
        cout << "6. Display node which having degree 2 " << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.create();
                break;
            case 2:
                emp.display(root);
                break;
                  case 3:
                emp.displaywithoutrecursive(root);
                break;
                   case 4:
                emp.displayleafnode(root);
                break;
                    case 5:
                emp.displayintermidiatenode(root);
                      case 6:
                emp.displaynodedegree2(root);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
