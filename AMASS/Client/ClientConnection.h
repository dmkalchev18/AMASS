#pragma once
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Presentation.h"
asio::ip::tcp::socket connectToServer();

template <typename T>
void sendRequest(SYSTEM_CODE code, T data)
{
	//asio::ip::tcp::socket socket = connectToServer();
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	socket.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket, code);
	data.write(socket);
}
template <typename T>
void readRequest(SYSTEM_CODE code, T& data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_,code);
	readShortInt(socket_,size);
	T t;
	//vector<T> temp;
	for (uint16_t i = 0; i < size; i++)
	{
		t.read(socket_);
		data.push_back(t);
		//data[i].read(socket_);
	}
}

void readRequest(SYSTEM_CODE code, ROLE& role);
void readRequest(SYSTEM_CODE code, STUDENT& student);
void readRequest(SYSTEM_CODE code, TEACHER& teacher);
void readRequest(SYSTEM_CODE code, DATE& date);
void readRequest(SYSTEM_CODE code, TEAM_MEMBER& member);
void readRequest(SYSTEM_CODE code, TEAM& team);
void readRequest(SYSTEM_CODE code, SCHOOL& school);
void readRequest(SYSTEM_CODE code, std::vector<SCHOOL>& schools);

void sendRequest(SYSTEM_CODE code, std::string data);
void sendRequest(SYSTEM_CODE code, bool data);
void sendRequest(SYSTEM_CODE code, int data);
void sendRequest(SYSTEM_CODE code, uint16_t data);

//void processCrtSch()
void requestCrtSch();
void requestReadDB();