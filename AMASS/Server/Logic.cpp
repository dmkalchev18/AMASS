#include "Logic.h"
#include "AdvancedFileOperations.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
	TEACHER t2 = { 1,"Gosho","Dizela","Petrov","dizela@gmail.com" };
	TEACHER t3 = { 2,"Vankata","Dunera","Vulchev","ILYDuner@abv.bg" };
	TEACHER t4 = { 3,"Eren","Grisha","Jaeger","fighter@titan.bg" };
	TEACHER t5 = { 4,"Levi","Kenny","Ackermann","scouts@titan.com" };

	STUDENT s1 = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { 1,"Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { 2,"Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { 3,"Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { 4,"Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { 5,"Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}} };

	ROLE r1 = { 0, "Scrum Master" };
	ROLE r2 = { 1, "Backend Developer" };
	ROLE r3 = { 2, "Frontend Developer" };
	ROLE r4 = { 3, "QA" };
	ROLE r5 = { 4, "Documentation" };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };
	vector<ROLE> roles = { r1,r2,r3,r4,r5 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ 0,5, name, city, address, teachers, teams, students };

	schools.push_back(school);
}

void createStudent(SCHOOL& school, STUDENT student)
{
	school.students.push_back(student);
}

void createTeacher(SCHOOL& school, TEACHER teacher)
{
	school.teachers.push_back(teacher);
}

void createTeam(SCHOOL& school, TEAM team)
{
	school.teams.push_back(team);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school)
{
	schools.push_back(school);
	saveDataBase(schools);
}

void createRole(SCHOOL& school, ROLE role)
{
	school.roles.push_back(role);
}

void createTeamIdInTeacher(TEACHER& teacher, int teamId)
{
	teacher.teamIds.push_back(teamId);
}

void deleteStudent(SCHOOL& school, int studentId)
{
	for (size_t i = 0; i < school.students.size(); i++)
	{
		if (school.students[i].id == studentId)
		{
			school.students.erase(school.students.begin() + i);
			return;
		}
	}
}

void deleteTeacher(SCHOOL& school, int teacherId)
{
	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		if (school.teachers[i].id == teacherId)
		{
			school.teachers.erase(school.teachers.begin() + i);
			return;
		}
	}
}

void deleteRoles(SCHOOL& school, int roleId)
{

	for (size_t i = 0; i < school.roles.size(); i++)
	{
		if (school.roles[i].id == roleId)
		{
			school.roles.erase(school.roles.begin() + i);
			return;
		}
	}
}

void deleteSchool(vector<SCHOOL>& schools, int schoolId)
{

	for (size_t i = 0; i < schools.size(); i++)
	{
		if (schools[i].id == schoolId)
		{
			schools.erase(schools.begin() + i);
		}
	}
	saveDataBase(schools);
}

void deleteTeam(SCHOOL& school, int teamId)
{

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].id == teamId)
		{
			school.teams.erase(school.teams.begin() + i);
		}
	}
}

void deleteTeamIdInTeacher(TEACHER& teacher, int teamIdIndex)
{
	teacher.teamIds.erase(teacher.teamIds.begin() + teamIdIndex);
}

// STUDENT

void updateStudentFirstName(STUDENT& student, string newFirstName)
{
	student.firstName = newFirstName;
}

void updateStudentMiddleName(STUDENT& student, string newMiddleName)
{
	student.middleName = newMiddleName;
}

void updateStudentSurname(STUDENT& student, string newSurname)
{
	student.surname = newSurname;
}

void updateStudentGrade(STUDENT& student, string newGrade)
{
	student.grade = newGrade;
}

void updateStudentEmail(STUDENT& student, string newEmail)
{
	student.email = newEmail;
}

// TEACHER

void updateTeacherFirstName(TEACHER& teacher, string newFirstName)
{
	teacher.firstName = newFirstName;
}

void updateTeacherMiddleName(TEACHER& teacher, string newMiddleName)
{
	teacher.middleName = newMiddleName;
}

void updateTeacherSurname(TEACHER& teacher, string newSurname)
{
	teacher.surname = newSurname;
}

void updateTeacherEmail(TEACHER& teacher, string newEmail)
{
	teacher.email = newEmail;
}

void updateTeamIdInTeacher(TEACHER& teacher, int teamIdIndex, int newId)
{
	teacher.teamIds[teamIdIndex] = newId;
}

// TEAM

void updateTeamName(TEAM& team, string newName)
{
	team.name = newName;
}

void updateTeamDesc(TEAM& team, string newDesc)
{
	team.desc = newDesc;
}

void updateTeamDayOfSetUp(TEAM& team, int newDay)
{
	team.dateOfSetUp.day = newDay;
}

void updateTeamMonthOfSetUp(TEAM& team, int newMonth)
{
	team.dateOfSetUp.month = newMonth;
}

void updateTeamYearOfSetUp(TEAM& team, int newYear)
{
	team.dateOfSetUp.year = newYear;
}

void updateTeamStatus(TEAM& team, STATUS newStatus)
{
	team.status = newStatus;
}

// SCHOOL

void updateSchoolName(SCHOOL& school, string newName)
{
	school.name = newName;
}

void updateSchoolCity(SCHOOL& school, string newCity)
{
	school.city = newCity;
}

void updateSchoolAdress(SCHOOL& school, string newAddress)
{
	school.address = newAddress;
}

