#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int NUMCOURSE = 2;
struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
//Student *sortStudent(Student *head, int asc);

Student *makeStudent(int N)
{
    ifstream ifs;
    Student *temp, *head, *prev;

    ifs.open("students.txt");
    if(!ifs) {
        cerr << "FILE COOKED" << endl;
        exit(0);
    }

    for(int i = 0; i < N; i++) {
        temp = new Student;
        ifs >> temp->id >> temp->name >> temp->score[0] >> temp->score[1];
        temp->sum = temp->score[0] + temp->score[1];
        temp-> avg = temp->sum / NUMCOURSE;
        if(i == 0) {
            head = temp;
        }
        else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}

void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;
}

int getLength(Student *head)
{
    Student *ptr = head;
    int cnt = 0;
    while(ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    
    return cnt;
}

/*Student *sortStudent(Student *head, int asc)
{
    
    return head;
} */
