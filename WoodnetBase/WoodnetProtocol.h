#pragma once
#include <basetsd.h>
#include "CommonDefines.h"

enum class COMMON_PAKET_ID : INT16
{
	S2C_ERROR = 1,
	S2C_ACCEPT,						// O 
	S2C_HEART_BEAT,
	C2S_HEART_BEAT,
};

enum class LOBBY_PACKET_ID : INT16
{
	C2S_ENTER_LOBBY = 10,
	S2C_ENTER_LOBBY_OK,
	C2S_LEAVE_LOBBY,
	S2C_LEAVE_LOBBY_OK,

	C2S_ENTER_CHAT_SER,
	S2C_ENTER_CHAT_SER_OK,

	S2C_NEW_PLAYER,
	S2C_LEAVE_PLAYER,

	C2S_CHANGE_NAME,
	S2C_CHANGE_NAME_OK,

	C2S_CHAT,
	S2C_CHAT,
	S2C_NOTICE,

	C2S_ENTER_MATCHING,
	S2C_ENTER_MATCHING_OK,
	S2C_SUCCESS_MATCHING,

	C2S_READY_MATCHING,
	S2C_READY_MATCHING_OK,
	S2C_READY_MATCHING_OK_ALL,

	S2C_GAME_KEY,
	C2S_GAME_KEY_OK,
	C2S_ENTER_GAME,
	S2C_ENTER_GAME_OK,

};

enum class GAME_SER_PACKET_ID
{
	C2S_ENTER_ROOM = 100,		// 게임방 접속을 위한 정보를 넘긴다.
	S2C_ENTER_ROOM_OK,			// 게임방 접속에 성공했다고 알린다.

};


#pragma pack(push, 1)

struct PACKET_HEADER
{
	INT16 packet_size;
	INT16 packet_id;
	INT8 seqNum;
};

////////////////////////////////////////////////////////////
#pragma region 테스트 패킷

static const int PACKET_DEV_BUF_SIZE_MAX = 128;
struct PACKET_DEV : PACKET_HEADER
{
	INT8 buffer[PACKET_DEV_BUF_SIZE_MAX];
};

// 클라 -> 서버
struct C2S_PACKET_DEV : PACKET_HEADER
{
	INT8 buffer[PACKET_DEV_BUF_SIZE_MAX];
};

//서버 -> 클라
struct S2C_PACKET_DEV : PACKET_HEADER
{
	INT32 NetID;// 네트워크 아이디를 같이 보내자.
	INT8 buffer[PACKET_DEV_BUF_SIZE_MAX];
};

#pragma endregion

////////////////////////////////////////////////////////////
#pragma region COMMON PAKET
PROTOCOL_DECLARE MSG_S2C_ERROR : PACKET_HEADER
{
	INT8 ErrorCode;
};

PROTOCOL_DECLARE MSG_S2C_ACCEPT : PACKET_HEADER
{
	INT32 NetID;
};

PROTOCOL_DECLARE MSG_S2C_HEART_BEAT : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_C2S_HEART_BEAT : PACKET_HEADER
{

};

#pragma endregion

////////////////////////////////////////////////////////////
#pragma region LOBBY NETWORK

PROTOCOL_DECLARE MSG_C2S_ENTER_LOBBY : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_ENTER_LOBBY_OK : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_C2S_LEAVE_LOBBY : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_LEAVE_LOBBY_OK : PACKET_HEADER
{

};


PROTOCOL_DECLARE MSG_C2S_ENTER_CHAT_SER : PACKET_HEADER
{
	char NickName[MAX_NICKNAME_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_ENTER_CHAT_SER_OK : PACKET_HEADER
{
	bool Result;
};


PROTOCOL_DECLARE MSG_S2C_NEW_PLAYER : PACKET_HEADER
{
	INT32 NetID;
	char NickName[MAX_NICKNAME_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_LEAVE_PLAYER : PACKET_HEADER
{
	INT32 NetID;
	char NickName[MAX_NICKNAME_LEN + 1];
};


PROTOCOL_DECLARE MSG_C2S_CHANGE_NAME : PACKET_HEADER
{
	char NickName[MAX_NICKNAME_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_CHANGE_NAME_OK : PACKET_HEADER
{
	INT32 NetID;
	char NickName[MAX_NICKNAME_LEN + 1];
};


PROTOCOL_DECLARE MSG_C2S_CHAT : PACKET_HEADER
{
	char MSG[MAX_CHATTING_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_CHAT : PACKET_HEADER
{
	INT32 NetID;
	char NickName[MAX_NICKNAME_LEN + 1];
	char MSG[MAX_CHATTING_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_NOTICE : PACKET_HEADER
{
	INT32 NetID;
	char NickName[MAX_NICKNAME_LEN + 1];
	char MSG[MAX_CHATTING_LEN + 1];
};


PROTOCOL_DECLARE MSG_C2S_ENTER_MATCHING : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_ENTER_MATCHING_OK : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_SUCCESS_MATCHING : PACKET_HEADER
{

};


PROTOCOL_DECLARE MSG_C2S_READY_MATCHING : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_READY_MATCHING_OK : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_READY_MATCHING_OK_ALL : PACKET_HEADER
{

};


PROTOCOL_DECLARE MSG_S2C_GAME_KEY : PACKET_HEADER
{
	char KeyStr[GAME_SER_KEY_LEN + 1];
};

PROTOCOL_DECLARE MSG_C2S_GAME_KEY_OK : PACKET_HEADER
{

};


PROTOCOL_DECLARE MSG_C2S_ENTER_GAME : PACKET_HEADER
{

};

PROTOCOL_DECLARE MSG_S2C_ENTER_GAME_OK : PACKET_HEADER
{

};

#pragma endregion

////////////////////////////////////////////////////////////
#pragma	region GAME NETWORK

PROTOCOL_DECLARE MSG_C2S_ENTER_ROOM : PACKET_HEADER
{
	char KeyStr[GAME_SER_KEY_LEN + 1];
};

PROTOCOL_DECLARE MSG_S2C_ENTER_ROOM_OK : PACKET_HEADER
{
	bool Result;
};

#pragma endregion

#pragma pack(pop)

