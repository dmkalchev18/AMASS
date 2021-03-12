#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"

//CRUD

void init(std::vector<SCHOOL>& schools);

DATE getCurrentDate();

void assignSchoolId(SCHOOL& school);
void assignTeamId(TEAM& team);
void assignRoleId(ROLE& role);
void assignTeacherId(TEACHER& teacher);
void assignStudentId(STUDENT& student);

void findSchoolById(std::vector<SCHOOL>& schools, SCHOOL& school, int id);


void createRole(SCHOOL& school, ROLE role);
void createStudent(SCHOOL& school, STUDENT student);
void createTeacher(SCHOOL& school, TEACHER teacher);
void createTeam(SCHOOL& school, TEAM team);
void createSchool(std::vector<SCHOOL>& schools, SCHOOL school);
void createTeamIdInTeacher(TEACHER& teacher, int teamId);

void deleteStudent(SCHOOL& school, int studentId);
void deleteTeacher(SCHOOL& school, int teacherId);
void deleteRoles(SCHOOL& school, int teamId);
void deleteSchool(std::vector<SCHOOL>& schools, int schoolId);
void deleteTeam(SCHOOL& school, int teamId);
void deleteTeamIdInTeacher(TEACHER& teacher, int teamIdIndex);

void updateStudentFirstName(STUDENT& student, std::string newFirstName);
void updateStudentMiddleName(STUDENT& student, std::string newMiddleName);
void updateStudentSurname(STUDENT& student, std::string newSurname);
void updateStudentGrade(STUDENT& student, std::string newGrade);
void updateStudentEmail(STUDENT& student, std::string newEmail);
void updateTeacherFirstName(TEACHER& teacher, std::string newFirstName);
void updateTeacherMiddleName(TEACHER& teacher, std::string newMiddleName);
void updateTeacherSurname(TEACHER& teacher, std::string newSurname);
void updateTeacherEmail(TEACHER& teacher, std::string newEmail);
void updateTeamIdInTeacher(TEACHER& teacher, int teamIdIndex, int newId);
void updateTeamName(TEAM& team, std::string newName);
void updateTeamDesc(TEAM& team, std::string newDesc);
void updateTeamName(TEAM& team, std::string newName);
void updateTeamDayOfSetUp(TEAM& team, int newDay);
void updateTeamMonthOfSetUp(TEAM& team, int newMonth);
void updateTeamYearOfSetUp(TEAM& team, int newYear);
void updateTeamStatus(TEAM& team, STATUS newStatus);
void updateSchoolName(SCHOOL& school, std::string newName);
void updateSchoolCity(SCHOOL& school, std::string newCity);
void updateSchoolAdress(SCHOOL& school, std::string newAddress);