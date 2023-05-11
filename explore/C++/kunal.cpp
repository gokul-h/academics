#include<iostream>
using namespace std;
class employee
{
protected:
    int emp_id;
    string emp_name,gender,designation;
public:
    void get_data()
    {
        cin>>emp_id>>emp_name>>gender>>designation;
    }
    void put_data()
    {
        cout<<emp_id<<"\n"<<emp_name<<"\n"<<gender<<"\n"<<designation<<"\n";
    }
};
class account
{
protected:
    int account_number;
    string account_type;
public:
    void get_info()
    {
    cin>>account_number>>account_type;
    }
    void put_info()
    {
    cout<<account_number<<"\n"<<account_type<<"\n";
    }
};
class payroll :public employee,public account
{
private:
    int basic_pay,DA,HRA,provident_fund,professional_tax,insurance_premium,net_salary;
public:
    void get_details()
    {
        cin>>basic_pay>>DA>>HRA>>provident_fund>>professional_tax>>insurance_premium;
    }
    void calculate()
    {
        get_data();
        get_info();
        get_details();
        net_salary = (basic_pay+DA+HRA)-(provident_fund+professional_tax+insurance_premium);
    }
    void putdata()
    {
       cout<<emp_id<<"\n";
        cout<<emp_name<<"\n";
        cout<<gender<<"\n";
        cout<<designation<<"\n";
        cout<<account_number<<"\n";
        cout<<account_type<<"\n";
        cout<<basic_pay<<"\n";
        cout<<DA<<"\n";
        cout<<HRA<<"\n";
        cout<<provident_fund<<"\n";
        cout<<professional_tax<<"\n";
        cout<<insurance_premium<<"\n";
        cout<<net_salary<<"\n";
    }
};
int main()
{
    payroll p1;
    p1.calculate();
    p1.putdata();
    return 0;
}