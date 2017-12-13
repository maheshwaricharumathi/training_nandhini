#include "organization.h"
#include"queueclass.h"
#include<vector>

//getting details of employee

void organization::employe_details()
{ 
	    cout << "Enter the details of the employee\n";
	
		employ.EmpId.push_back(employ.id);
		
		cout << "Enter the employee name\n";
		cin >> employ.name;

		//calling the function 

		employ.validate_name();
		cout << "Enter the employee year\n";
		cin >> employ.year;
		employ.validate_year();
		cout << "Enter the employee pay\n";
		cin >> employ.pay;
		employ.validate_pay();
		cout << "Enter the employee department\n";
		cin >> employ.department;
		employ.validate_department();
		employ.EmpDepartment.push_back(employ.department);
		
		std::string Id = std::to_string(employ.id);
		Id = employ.value + Id;
		employ.Id.push_back(Id);
		employ.id = employ.id++;
		cqueue.copying_details(employ.EmpId,employ.EmpName,employ.EmpDepartment);
}

//display the employee by the year

void organization::name_by_year()
{
	
	value = 0;
	cout << "Enter the year of joining";
	cin >> Year;
	if (!cin.fail() && Year >= 1900 && Year <= 2017)
	{
		cout << endl;
		for (iterat = 0; iterat < (int)employ.EmpId.size(); iterat++)
		{
			if (employ.EmpYear.at(iterat) == Year)
			{
				cout << employ.EmpName.at(iterat);
				value++;
			}
		}
		if (value == 0)
		{
			cout << "The record is not available\n";

		}
	}
	else
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "input the year correctly";

	}
	
	
}

//display the highest pay by department

void organization::highest_pay()
{
	string Department;
	static float temp = 0.0;
	int index = 0;
	value = 0;
	cout << "Enter the Department of the employee\n";
	cin >> Department;
Department:employ.validate_department();
	cout << endl;
	for (iterat = 0; iterat < (int)employ.EmpId.size(); iterat++)
	{
		

		//checks for the department

		if (employ.EmpDepartment.at(iterat) == Department)
		{
			if (employ.EmpPay.at(iterat)>temp)
			{
				temp = employ.EmpPay.at(iterat);
				index = iterat;
				value++;
			}
			else
			{
				temp = iterat;
				index = temp;
				value++;
			}

		}

	}
			if (value == 0)
			{
				cout << "The record is not available\n";

			}
			if (value != 0)
			{
				cout << employ.Id.at(index);
				cout << endl;
				cout << "\nthe employee name\t";
				cout << employ.EmpName.at(index);
				cout << "\n";
				cout << "the employee year\t";
				cout << employ.EmpYear.at(index);
				cout << "\n";
				cout << "the employee pay\t";
				cout << employ.EmpPay.at(index);
				cout << "\n";
				cout << "the employee department\t";
				cout << employ.EmpDepartment.at(index);
				cout << "\n";
			}
			
}

　
//display details by ascending order

void organization::display_by_ascending_order()
{ 
	
	for (iterat =0; iterat < (int)employ.EmpId.size(); iterat++)
	{
			cout << employ.Id.at(iterat);
			cout << "\nThe employee name\t";
			cout << employ.EmpName.at(iterat);
			cout << "\n";
			cout << "The employee year\t";
			cout << employ.EmpYear.at(iterat);
			cout << "\n";
			cout << "The employee pay\t";
			cout << employ.EmpPay.at(iterat);
			cout << "\n";
			cout << "The employee department\t";
			cout << employ.EmpDepartment.at(iterat);
			cout << "\n";

		
	}
}

//updation of pay by 5%

void organization::update_pay()
{
	int Id=0;
	value = 0;
	cout << "Enter the Id of the employee\n";
	cin >> Id;
	if (!cin.fail() && Id > 100)
	{
		cout << endl;
		for (iterat = 0; iterat < (int)employ.EmpId.size(); iterat++)
		{
			if (employ.EmpId.at(iterat) == Id)
			{
				cout << endl;
				cout << employ.EmpPay.at(iterat);
				employ.EmpPay.at(iterat) = (1.05 * employ.EmpPay.at(iterat));
				cout << endl;
				cout << employ.EmpPay.at(iterat) << endl;
				value++;
			}

		}
		if (value == 0)
		{

		    //if not id not found

			cout << "The Id is not available\n";

		}
	}
	else
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nId invalid";
	}
}
int main()
{

	organization organize;
	char choice;
     	cout << "a.Display employee name by particaular year\nb.Display all details by department with highest pay \nc.Display all details by ascending order\nd.update pay by particaular id\ne.push details\nf.remove and add employee\ng.exit\n";
		while (1)
		{
			cout << "\nEnter the choice\n";
			cin >> choice;
			if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f' || choice == 'g')
			{
				cout << endl;

				switch (choice)
				{
				case 'a':
					organize.employe_details();
					break;
				case 'b':
					organize.name_by_year();
					break;
				case 'c':
					organize.highest_pay();
					break;
				case 'd':
					organize.display_by_ascending_order();
					break;
				case 'e':
					organize.update_pay();
					break;

				case 'f':
					organize.cqueue.push_details();
					break;
				case 'g':
					organize.cqueue.pop_details();
					organize.cqueue.remove_employee();
					organize.cqueue.add_employee();
					organize.cqueue.after_queue();
					break;
				case 'h':
					exit(1);
				default:
					cout << "invalid choice";
					break;
				}

			}

			else
			{
				cout << "invalid choice";
				system("pause");
				
			}
		}
}
