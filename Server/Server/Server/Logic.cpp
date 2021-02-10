#include "Logic.h"

using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { "Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
	TEACHER t2 = { "Gosho","Dizela","Petrov","dizela@gmail.com" };
	TEACHER t3 = { "Vankata","Dunera","Vulchev","ILYDuner@abv.bg" };
	TEACHER t4 = { "Eren","Grisha","Jaeger","fighter@titan.bg" };
	TEACHER t5 = { "Levi","Kenny","Ackermann","scouts@titan.com" };

	STUDENT s1 = { "Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { "Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { "Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { "Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { "Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { "Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{0, "GG@abv.bg", 1},{0, "SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{1, "IUM@abv.bg", 1},{1, "SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{2, "III@abv.bg", 1},{2, "MMM@abv.bg", 2}} };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ name,city,address,teachers,teams,students };

	schools.push_back(school);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school)
{
	schools.push_back(school);
	//saveData(schools);
}

string statusToString(STATUS status)
{
	switch (status)
	{
		// may change the string later
		case pendingApproval:
			return "Pending Approval";
		case inUse:
			return "In Use";
		case notActive:
			return "Not Active";
		case notArchived:
			return "Not Archived";
		default:
			return "";
	}
}

void displaySchool(SCHOOL school, int id)
{
	cout << "School " << id << " details:" << endl;
	cout << "Name: " << school.name << endl;
	cout << "City: " << school.city << endl;
	cout << "Adress: " << school.address << endl;
	cout << "List of the teachers: " << endl;
	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		cout << "Teacher " << i + 1 << ":" << endl;
		cout << "First Name: " << school.teachers[i].firstName << endl;
		cout << "Middle  Name: " << school.teachers[i].middleName << endl;
		cout << "Surname: " << school.teachers[i].surname << endl;
		cout << "E-mail: " << school.teachers[i].email << endl;
		cout << "List of team ids he participates: " << endl;

		for (size_t j = 0; j < school.teachers[i].teamIds.size(); j++)
		{
			cout << school.teachers[i].teamIds[j] << endl;
			// display team's name by its id
		}
	}

	cout << "List of the teams:" << endl;

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		cout << "Team's id: " << school.teams[i].id << endl;
		cout << "Name: " << school.teams[i].name << endl;
		// make description on several lines, instead of 1
		cout << "Description: " << school.teams[i].desc << endl;
		cout << "Date of set up:" << endl;
		// may change the format later
		cout << school.teams[i].dateOfSetUp.day << "/"
			<< school.teams[i].dateOfSetUp.month << "/"
			<< school.teams[i].dateOfSetUp.year <<
			" (dd/mm/yyyy)" << endl;
		cout << "Status: " << statusToString(school.teams[i].status) << endl;

		cout << "List of team members:" << endl;
		for (size_t j = 0; j < school.teams[i].members.size(); j++)
		{
			cout << "Student " << j + 1 << ":" << endl;
			cout << "Email: " << school.teams[i].members[j].studentEmail << endl;
			// display student's role by id
		}
	}
}