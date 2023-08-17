#include <iostream>
#include <vector>
using namespace std;

class Student:public Person
{
private:
    float gpa;
    int level;

public:

    //default constructor
    Student() {}

    //parameterized constructor
    Student(float gpa, int level)
    {
        this->gpa = gpa;
        this->level = level;
    }
 Student(int id, string student_name,string student_gender, int age, float gpa, int level)
    {

        this->gpa = gpa;
        this->level = level;
        this->age = age;
        this->student_gender = student_gender;
        this->id = id;
        this->student_name = student_name;

    }

    //setter and getter
    void set_gpa(float gpa)
    {
        this->gpa = gpa;
    }
    float get_gpa()
    {
        return gpa;
    }
    void set_level(int level)
    {
        this->level = level;
    }
    int get_level()
    {
        return level;
    }

};
//department

class Department
{
private:

    std::string department_name;
    int capacity;
    float required_gpa;

public:
    //default constructor
    Department() {}
    //parameterized constructor
    Department(std::string department_name, int capacity, float required_gpa )
    {
        this->department_name= department_name;
        this->capacity = capacity;
        this->required_gpa = required_gpa;
        //setters and getters
    }
    void set_department_name(string department_name)
    {
        this->department_name = department_name;
    }
    std::string get_department_name()
    {
        return department_name;
    }

    void set_capacity(int capacity)
    {
        this->capacity = capacity;
    }
    int get_capacity()
    {
        return capacity;
    }
    void set_required_gpa(float required_gpa)
    {
        this->required_gpa = required_gpa;
    }
    float get_required_gpa()
    {
        return required_gpa;
    }


};

class University
{

private:

    vector<Department> departments;
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    static University *uni_ptr;
    University() {}
public:
//ADD
    void add_Student(int id, string student_name,string student_gender, int age, float gpa, int level)
    {
        if(gpa > 4 || level> 400)
            cout<<"error"<<endl;

                else
            {
                Student student_obj(id, student_name,student_gender, gpa,level);
                students.push_back(student_obj);
            }
    }
    void add_Department(string department_name, int capacity, float required_gpa)
    {
        // assuming max capacity in department = 1000
        if(capacity >1000|| required_gpa>4)
        cout<<"error"<<endl;


            else
        {
            Department department_obj(string department_name, int capacity, float required_gpa);
                departments.push_back(department_obj);
            }
    }
    bool update_department(string department_name, float required_gpa)
    {

        if(required_gpa>4 || required_gpa<0 ||department_name == "" )

            cout<<"error"<<endl;

        else
        {
            for(int i = 0; i<= departments.size() ; i++)
            {
                if(departments[i].get_department_name == department_name)
                {
                    departments[i].set_required_gpa(required_gpa);
                    return true;

                }

            }
            else{
                return false;
            }

        }

    }

    bool update_student(string student_name, float gpa)
    {
        if(required_gpa>4 || required_gpa<0 ||student_name == "")
            cout<<"error"<<endl
        else
        {
             for(int i = 0; i<= students.size() ; i++)
                {
                 if(students[i].get_student_name == student_name)
                    {
                    students[i].set_gpa(gpa);
                    return true;
                 }
             }
             else{
                return false;
             }
        }
    }

    bool delete_student(int id)
    {
        if (id == "")
        {
            cout<<"invalid id";

        }
        else{
            for(int i = 0; i<students.size(); i++)
            {
                students.erase(students.begin()+i);
                cout<<"student deleted successfully";
                return true;
            }
            else{
                cout<<"student not found";
                return false;
            }
        }
    }


    bool delete_department(int department_name)
    {
        if (department_name == "")
        {
            cout<<"invalid department";

        }
        else{
            for(int i = 0; i<departments.size(); i++)
            {
                departments.erase(departments.begin()+i);
                cout<<"department deleted successfully";
                return true;
            }
            else{
                cout<<"department not found";
                return false;
            }
        }
    }



    University(const University& obj) = delete;
    static University *getInstance()
    {
        if(uni_ptr == NULL)
        {
            uni_ptr = new University();
            return uni_ptr;
        }
        else
        {
            return uni_ptr;
        }
    }


};


University * University::uni_ptr = NULL;
int main()
{

}
