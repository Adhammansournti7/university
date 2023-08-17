#include <iostream>
#include <vector>
using namespace std;
/*
to avoid depandancies apply this sequance
dept  ,,, person ,,, students ,,, profs ,,, course ,,, universty





*/
class Course
{
private:
    string course_name;
    int course_hour;
    string course_code;
    string professor;
    //vector<Student>
    vector <string> students;
    vector <Course> courses;
public:

    //default constructor for course class
    Course()
    {

    }
    Course(string course_name,int course_hour,string course_code,string professor, vector<Course> pre,vector <string>stds)
    {
        this->course_name=course_name;
        this->course_hour=course_hour;
        this->course_code=course_code;
        this->professor=professor;
        this->students=stds;
        this->courses=pre;
    }

    //course name setter
    void set_course_name(string name)
    {
        course_name=name;
    }
    //course name getter
    string get_course_name()
    {
        return course_name;
    }
    //professor name setter
    void set_professor(string name)
    {
        professor=name;
    }
    //professor name setter
    string get_professor()
    {
        return professor;
    }

    void set_course_hour(int hours)
    {
        professor=hours;
    }
    //professor name setter
    int get_course_hour()
    {
        return course_hour;
    }

    //professor name setter
    void set_course_code(string code)
    {
        course_code=code;
    }
    //professor name setter
    string get_course_code()
    {
        return course_code;
    }


};

class Universty
{

private:
    static Universty *instancePtr;
    Universty() {};
    vector<Course> courses;
public:

    Universty(const Universty& obj) = delete;
    static Universty *getInstance()
    {
        if(instancePtr == NULL)
        {
            instancePtr = new Universty();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    void add_course(string name,int hours,string code,string professor, vector<Course> pre,vector<string> stds )

    {
        if( name=="" || (hours<=0 || hours>=3) || code=="" || professor=="" )
        {
            cout<<"error in data";
        }
        else
        {
            Course course(name,hours,code,professor,pre,stds);
            courses.push_back(course);
        }
    }





    bool update_course(string code,int hours)
    {

        if(code=="")
        {
            cout<<"invalid course code";
        }
        else
        {
            for(int i=0; i<courses.size(); i++)
            {
                if (courses[i].get_course_code() == code)
                {
                    courses[i].set_course_hour(hours);
                    cout<<"course hours changed successfully";
                    return true;
                }
            }
            if(code=="")
        {cout<<"invalid course code";}
        else
        {   Course course;
            string temp=course.get_course_code();
            for(int i=0;i<courses.size();i++)
            {
               if (courses[i].get_course_code() == code)
               {
                   courses[i].set_course_hour(hours);
                   cout<<"course hours changed successfully";
                   return 1;
               }
                  cout<<"course not found";
                    return 0;

          }
            }
        }
    }


    bool delete_course(string code)
    {
        if(code=="")
        {
            cout<<"invalid course code";
        }
        else
        {
            for(int i=0; i<courses.size(); i++)
            {
                if (courses[i].get_course_code() == code)
                {
                    courses.erase(courses.begin()+i);
                    cout<<"course deleted successfully";
                    return true ;
                }
                else
                {

                }

            }
             cout<<"course not found";
                    return false;
        }

    }


};
Universty* Universty::instancePtr = NULL;
int main()
{

    return 0;
}
