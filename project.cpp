#include<iostream>
#include<ostream>

#include<vector>
using namespace std;
class Person {
private:
    int age;
    int id;
    string name;
    char gender;
protected:
public:
    //default constructor
   Person()
   {
   }
  //parameter constructor
   Person(int a,int i,string n,char g)
   {
   age=a;
   id=i;
   name=n;
   gender=g;
   }
//setter
 void set_age(int age_s)
  {
 age=age_s;
  }
 void set_id(int id_s)
  {
 id=id_s;
  }
void set_name(string name_s)
{
 name=name_s;
}
void set_gender(char gender_s)
{
 gender=gender_s;
}
//getter
int get_age()
{
return age;
}
int get_id()
{
return id;
}
string get_name()
{
return name;
}
char get_gender()
{
return gender;
}

};

class Prof:public Person{
private:
    string degree;
    double salary;
    static Prof* create_object()
    {
        static Prof* obj;
        return obj;
    }
    bool flag;
public:
    Prof* ptr = Prof::create_object();

    void data(string get_degree,double get_salary)
    {
        if(!flag){
            degree=get_degree;
            salary=get_salary;
            flag =true;
        }
    else{
        cout<<"this data is already entered"<<endl;
        }
    }
    Prof()
    {
    }
    Prof(string d,double s)
    {
        degree=d;
        salary=s;
    }

    void set_degree(string degree_f){
  degree=degree_f;
    }
        void set_salary(double salary_f){
  salary=salary_f;
    }

   string get_degree()
{
return degree;
}
double get_salary()
{
return salary;
}

};
class University{
private:

   University(){}
   static University* instance_ptr;
vector <Prof> proffesors;
public:

University(const University&)= delete;

static University* get_instance(){

   if(instance_ptr==NULL)
    {
       instance_ptr=new University();
       return instance_ptr;
    }
  else return instance_ptr;
}
  double update_prof(double salary_p)
       {
    if(proffesors.empty())
      cout<<"there's no update"<<endl;
    else {
      for(int i=0;i<proffesors.size();i++)
     {
        Prof pr2;
        return proffesors.at(i).set_salary(salary_p);
     }
         }
    }
    void delete_prof(int id)
        {
            bool found=false;
         if(auto it=proffessors.begin(); it != proffessors.end(); ++it)
            {
        if (it->get_id() == id) {
            found = true;
            proffessors.erase(it);
            cout << "Professor with ID " << id << " is deleted." << endl;
            break;
        }
            }
    else if (!found)
          {
        cout << "There is no professor with ID " << id << " found." << endl;
          }
        }
};
University* University::instance_ptr = NULL;
int main(){







}
