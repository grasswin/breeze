 
#ifndef _PROTOLOGIN_H_ 
#define _PROTOLOGIN_H_ 
 
 
const unsigned short ID_Heartbeat = 0; //心跳包  
struct Heartbeat //心跳包  
{ 
    unsigned int timeStamp; //服务器当前UTC时间戳  
    unsigned int timeTick; //服务器当前tick时间戳 毫秒, 服务启动时刻为0  
    Heartbeat() 
    { 
        timeStamp = 0; 
        timeTick = 0; 
    } 
    static const unsigned short GetProtoID() { return 0;} 
    static const std::string GetProtoName() { return "ID_Heartbeat";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const Heartbeat & data) 
{ 
    ws << data.timeStamp;  
    ws << data.timeTick;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, Heartbeat & data) 
{ 
        rs >> data.timeStamp;  
        rs >> data.timeTick;  
    return rs; 
} 
 
const unsigned short ID_HeartbeatEcho = 1; //心跳包需要立刻回复  
struct HeartbeatEcho //心跳包需要立刻回复  
{ 
    unsigned int timeStamp; //服务器当前UTC时间戳  
    unsigned int timeTick; //服务器当前tick时间戳 毫秒, 服务启动时刻为0  
    HeartbeatEcho() 
    { 
        timeStamp = 0; 
        timeTick = 0; 
    } 
    static const unsigned short GetProtoID() { return 1;} 
    static const std::string GetProtoName() { return "ID_HeartbeatEcho";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const HeartbeatEcho & data) 
{ 
    ws << data.timeStamp;  
    ws << data.timeTick;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, HeartbeatEcho & data) 
{ 
        rs >> data.timeStamp;  
        rs >> data.timeTick;  
    return rs; 
} 
 
const unsigned short ID_PlatAuthReq = 2; //平台认证  
struct PlatAuthReq //平台认证  
{ 
    std::string account; //用户名  
    std::string token; //令牌  
    static const unsigned short GetProtoID() { return 2;} 
    static const std::string GetProtoName() { return "ID_PlatAuthReq";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const PlatAuthReq & data) 
{ 
    ws << data.account;  
    ws << data.token;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, PlatAuthReq & data) 
{ 
        rs >> data.account;  
        rs >> data.token;  
    return rs; 
} 
 
const unsigned short ID_PlatAuthAck = 3; //认证结果, 包含该用户的所有用户/角色数据  
struct PlatAuthAck //认证结果, 包含该用户的所有用户/角色数据  
{ 
    unsigned short retCode;  
    BaseInfoArray users; //该帐号下的所有用户信息  
    PlatAuthAck() 
    { 
        retCode = 0; 
    } 
    static const unsigned short GetProtoID() { return 3;} 
    static const std::string GetProtoName() { return "ID_PlatAuthAck";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const PlatAuthAck & data) 
{ 
    ws << data.retCode;  
    ws << data.users;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, PlatAuthAck & data) 
{ 
        rs >> data.retCode;  
        rs >> data.users;  
    return rs; 
} 
 
const unsigned short ID_CreateUserReq = 4; //创建一个新的用户数据  
struct CreateUserReq //创建一个新的用户数据  
{ 
    std::string nickName; //昵称  
    int iconID; //头像  
    CreateUserReq() 
    { 
        iconID = 0; 
    } 
    static const unsigned short GetProtoID() { return 4;} 
    static const std::string GetProtoName() { return "ID_CreateUserReq";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const CreateUserReq & data) 
{ 
    ws << data.nickName;  
    ws << data.iconID;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, CreateUserReq & data) 
{ 
        rs >> data.nickName;  
        rs >> data.iconID;  
    return rs; 
} 
 
const unsigned short ID_CreateUserAck = 5; //创建结果和所有用户数据  
struct CreateUserAck //创建结果和所有用户数据  
{ 
    unsigned short retCode;  
    BaseInfoArray users; //该帐号下的所有用户信息  
    CreateUserAck() 
    { 
        retCode = 0; 
    } 
    static const unsigned short GetProtoID() { return 5;} 
    static const std::string GetProtoName() { return "ID_CreateUserAck";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const CreateUserAck & data) 
{ 
    ws << data.retCode;  
    ws << data.users;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, CreateUserAck & data) 
{ 
        rs >> data.retCode;  
        rs >> data.users;  
    return rs; 
} 
 
const unsigned short ID_SelectUserReq = 6; //获取需要登录用户的所在服务器和认证令牌  
struct SelectUserReq //获取需要登录用户的所在服务器和认证令牌  
{ 
    unsigned long long uID;  
    SelectUserReq() 
    { 
        uID = 0; 
    } 
    static const unsigned short GetProtoID() { return 6;} 
    static const std::string GetProtoName() { return "ID_SelectUserReq";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SelectUserReq & data) 
{ 
    ws << data.uID;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SelectUserReq & data) 
{ 
        rs >> data.uID;  
    return rs; 
} 
 
const unsigned short ID_SelectUserAck = 7; //获取需要登录用户的所在服务器和认证令牌  
struct SelectUserAck //获取需要登录用户的所在服务器和认证令牌  
{ 
    unsigned short retCode;  
    unsigned long long uID;  
    std::string token;  
    std::string ip;  
    unsigned short port;  
    SelectUserAck() 
    { 
        retCode = 0; 
        uID = 0; 
        port = 0; 
    } 
    static const unsigned short GetProtoID() { return 7;} 
    static const std::string GetProtoName() { return "ID_SelectUserAck";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SelectUserAck & data) 
{ 
    ws << data.retCode;  
    ws << data.uID;  
    ws << data.token;  
    ws << data.ip;  
    ws << data.port;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SelectUserAck & data) 
{ 
        rs >> data.retCode;  
        rs >> data.uID;  
        rs >> data.token;  
        rs >> data.ip;  
        rs >> data.port;  
    return rs; 
} 
 
const unsigned short ID_AttachLogicReq = 10; //挂到logic服务器上  
struct AttachLogicReq //挂到logic服务器上  
{ 
    unsigned long long uID;  
    std::string token;  
    AttachLogicReq() 
    { 
        uID = 0; 
    } 
    static const unsigned short GetProtoID() { return 10;} 
    static const std::string GetProtoName() { return "ID_AttachLogicReq";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const AttachLogicReq & data) 
{ 
    ws << data.uID;  
    ws << data.token;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, AttachLogicReq & data) 
{ 
        rs >> data.uID;  
        rs >> data.token;  
    return rs; 
} 
 
const unsigned short ID_AttachLogicAck = 11; //挂到logic服务器上  
struct AttachLogicAck //挂到logic服务器上  
{ 
    unsigned short retCode;  
    AttachLogicAck() 
    { 
        retCode = 0; 
    } 
    static const unsigned short GetProtoID() { return 11;} 
    static const std::string GetProtoName() { return "ID_AttachLogicAck";} 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const AttachLogicAck & data) 
{ 
    ws << data.retCode;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, AttachLogicAck & data) 
{ 
        rs >> data.retCode;  
    return rs; 
} 
 
#endif 
