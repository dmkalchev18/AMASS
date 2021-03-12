#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);

DATE getCurrentDate();

bool isStringInputValid(std::string input);
int tryReadInt();

void assignSchoolId(SCHOOL& school);
void assignTeamId(TEAM& team);
void assignRoleId(ROLE& role);
void assignTeacherId(TEACHER& teacher);
void assignStudentId(STUDENT& student);

void findSchoolById(vector<SCHOOL>& schools, SCHOOL& school, int id);


void createRole(SCHOOL& school, ROLE role);
void createStudent(SCHOOL& school, STUDENT student);
void createTeacher(SCHOOL& school, TEACHER teacher);
void createTeam(SCHOOL& school, TEAM team);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);
void createTeamIdInTeacher(TEACHER& teacher, int teamId);

void deleteStudent(SCHOOL& school, int studentId);
void deleteTeacher(SCHOOL& school, int teacherId);
void deleteRoles(SCHOOL& school, int teamId);
void deleteSchool(vector<SCHOOL>& schools, int schoolId);
void deleteTeam(SCHOOL& school, int teamId);
void deleteTeamIdInTeacher(TEACHER& teacher, int teamIdIndex);

void updateStudentFirstName(STUDENT& student, string newFirstName);
void updateStudentMiddleName(STUDENT& student, string newMiddleName);
void updateStudentSurname(STUDENT& student, string newSurname);
void updateStudentGrade(STUDENT& student, string newGrade);
void updateStudentEmail(STUDENT& student, string newEmail);
void updateTeacherFirstName(TEACHER& teacher, string newFirstName);
void updateTeacherMiddleName(TEACHER& teacher, string newMiddleName);
void updateTeacherSurname(TEACHER& teacher, string newSurname);
void updateTeacherEmail(TEACHER& teacher, string newEmail);
void updateTeamIdInTeacher(TEACHER& teacher, int teamIdIndex, int newId);
void updateTeamName(TEAM& team, string newName);
void updateTeamDesc(TEAM& team, string newDesc);
void updateTeamName(TEAM& team, string newName);
void updateTeamDayOfSetUp(TEAM& team, int newDay);
void updateTeamMonthOfSetUp(TEAM& team, int newMonth);
void updateTeamYearOfSetUp(TEAM& team, int newYear);
void updateTeamStatus(TEAM& team, STATUS newStatus);
void updateSchoolName(SCHOOL& school, string newName);
void updateSchoolCity(SCHOOL& school, string newCity);
void updateSchoolAdress(SCHOOL& school, string newAddress);