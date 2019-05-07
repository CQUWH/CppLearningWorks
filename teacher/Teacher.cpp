#include <iostream>
#include <string>
using namespace std;

class Teacher
{
  private:
    string id;
    string name;
    string title;
    string major;
    int age;
    double salary;

  public:
    Teacher(){};
    Teacher(string &, string &, string &, string &, int, double);
    Teacher(const Teacher &);

    void setId(string &id) { this->id = id; }
    void setName(string &name) { this->name = name; }
    void setTitle(string &title) { this->title = title; }
    void setMajor(string &major) { this->major = major; }
    void setAge(int age) { this->age = age; }
    void setSalary(double salary) { this->salary = salary; }

    string getId() const { return id; }
    string getName() const { return name; }
    string getTitle() const { return title; }
    string getMajor() const { return major; }
    int getAge() const { return age; }
    double getSalary() const { return salary; }

    Teacher &operator=(const Teacher &);
    friend std::ostream &operator<<(ostream &, const Teacher &);
    friend std::istream &operator>>(istream &, Teacher &);
    bool operator==(const Teacher &) const;
    bool operator>(const Teacher &) const;
    bool operator<(const Teacher &) const;
};

Teacher::Teacher(string &id, string &name, string &title, string &major, int age, double salary)
{
    this->id = id;
    this->name = name;
    this->title = title;
    this->major = major;
    this->age = age;
    this->salary = salary;
}

Teacher::Teacher(const Teacher &other)
{
    this->id = other.getId();
    this->name = other.getName();
    this->title = other.getTitle();
    this->major = other.getMajor();
    this->age = other.getAge();
    this->salary = other.getSalary();
}

Teacher &Teacher::operator=(const Teacher &other)
{
    this->id = other.getId();
    this->name = other.getName();
    this->title = other.getTitle();
    this->major = other.getMajor();
    this->age = other.getAge();
    this->salary = other.getSalary();
    return *this;
}

std::ostream &operator<<(ostream &os, const Teacher &self)
{
    os << "���ţ�" << self.getId() << endl;
    os << "������" << self.getName() << endl;
    os << "ְ�ƣ�" << self.getTitle() << endl;
    os << "רҵ��" << self.getMajor() << endl;
    os << "���䣺" << self.getAge() << endl;
    os << "���ʣ�" << self.getSalary() << endl;
    return os;
}

std::istream &operator>>(istream &is, Teacher &self)
{
    string _id;
    string _name;
    string _title;
    string _major;
    int _age;
    double _salary;
    is >> _id >> _name >> _title >> _major >> _age >> _salary;
    self.setId(_id);
    self.setName(_name);
    self.setTitle(_title);
    self.setMajor(_major);
    self.setAge(_age);
    self.setSalary(_salary);
    return is;
}

bool Teacher::operator==(const Teacher &other) const 
{
    if(this->salary == other.getSalary())
        return true;
    return false;
}

bool Teacher::operator<(const Teacher &other) const 
{
    if(this->salary < other.getSalary())
        return true;
    return false;
}

bool Teacher::operator>(const Teacher &other) const 
{
    if(this->salary > other.getSalary())
        return true;
    return false;
}

int main()
{
    Teacher a;
    Teacher b;
    cout << "�������һ����ʦ��Ϣ��" << endl;
    cin >> a;
    cout << "������ڶ�����ʦ��Ϣ��" << endl;
    cin >> b;
    cout << "��ʦһ��\n"
         << a;
    cout << "��ʦ����\n"
         << b;
    if(a == b)
    {
        cout << "������ʦ�������" << endl;
    }
}
