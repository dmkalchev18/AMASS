#pragma once
#include "Libraries.h"
#include <asio.hpp>

enum SYSTEM_CODE
{
	ok = 0,
	sendRole = 101,
	sendStudent = 102,
	sendTeacher = 103,
	sendDate = 104,
	sendTeamMember = 105,
	sendTeam = 106,
	sendSchool = 107,
	sendString = 108,
	sendInt = 109,
	sendBool = 110,
	sendShortInt = 111,
	receiveRole=201,
	receiveStudent = 202,
	receiveTeacher = 203,
	receiveDate = 204,
	receiveTeamMember = 205,
	receiveTeam = 206,
	receiveSchool = 207,
	receiveString = 208,
	receiveInt = 209,
	receiveBool = 210,
	receiveShortInt = 211,
	errorConnection = 401,
	createRole = 501,
	createStudent = 502,
	createTeacher = 503,
	createDate = 504,
	createTeamMember = 505,
	createTeam = 506,
	createSchool = 507,
	readRole = 601,
	readStudent = 602,
	readTeacher = 603,
	readDate = 604,
	readTeamMember = 605,
	readTeam = 606,
	readSchool = 607,
	updateRole = 701,
	updateStudent = 702,
	updateTeacher = 703,
	updateDate = 704,
	updateTeamMember=705,
	updateTeam = 706,
	updateSchool = 707,
	deleteRole = 801,
	deleteStudent = 802,
	deleteTeacher = 803,
	deleteDate = 804,
	deleteTeamMember = 805,
	deleteTeam = 806,
	deleteSchool = 807
};

enum STATUS
{
	pendingApproval,
	inUse,
	notActive,
	notArchived
};

struct ROLE
{
	int id = -1;
	std::string name = "teamless";
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

// Name and surname, class, role which the student prefers to carry out in the team, email.
struct STUDENT
{
	int id;
	std::string firstName;
	std::string middleName;
	std::string surname;
	// As in class
	std::string grade;
	std::string email;
	bool isInTeam = false;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct TEACHER
{
	int id;
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string email;
	// The teams' ids will be compared instead of wasting space for TEAM structs
	std::vector<int> teamIds = {};
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct DATE
{
	int day;
	int month;
	int year;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct TEAM_MEMBER
{
	std::string studentEmail;
	int roleId;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct SCHOOL
{
	int id;
	int maxMemberCountPerTeam;
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
	std::vector<ROLE> roles;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

void writeShortInt(asio::ip::tcp::socket& socket, uint16_t num);
void writeStr(asio::ip::tcp::socket& socket, std::string str);
void writeInt(asio::ip::tcp::socket& socket, int integer);
void writeBool(asio::ip::tcp::socket& socket, bool a);
void writeVec(asio::ip::tcp::socket& socket, std::vector<int> vec);
void writeVec(asio::ip::tcp::socket& socket, std::vector<std::string> vec);
void readStr(asio::ip::tcp::socket& socket, std::string& str);
void readInt(asio::ip::tcp::socket& socket, int& num);
void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num);
void readBool(asio::ip::tcp::socket& socket, bool& a);
void readVec(asio::ip::tcp::socket& socket, std::vector<std::string>& vec);
void readVec(asio::ip::tcp::socket& socket, std::vector<int>& vec);

template <typename T>
void writeRequest(asio::ip::tcp::socket& socket, SYSTEM_CODE code, T data)
{
	writeInt(socket,code);
	if(code>=101 and code<=107)
		data.write(socket);
	else {
		switch (code)
		{
		case 108: writeStr(socket, data); break;
		case 109: writeInt(socket, data); break;
		case 110: writeBool(socket, data); break;
		case 111: writeShortInt(socket, data); break;
		}
	}
}

template <typename T>
void readRequest(asio::ip::tcp::socket& socket, SYSTEM_CODE& code, T& data)
{
	int temp;
	readInt(socket, temp);
	code = static_cast<SYSTEM_CODE>(temp);
	if (code >= 201 and code <= 207)
		data.read(socket);
	else {
		switch (code)
		{
		case 208: readStr(socket, data); break;
		case 209: readInt(socket, data); break;
		case 210: readBool(socket, data); break;
		case 211: readShortInt(socket, data); break;
		}
	}
}