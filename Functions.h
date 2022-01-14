//
//  Functions.h
//  rikaiChatSystem
//
//  Created by 马婕慧 on 2018/6/20.
//  Copyright © 2018年 马婕慧. All rights reserved.
//

#ifndef Functions_h
#define Functions_h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Robot //机器人类
{
private: //创建对象
    string _name; //机器人名
    string _gender;
    int _age;

    
public:
    Robot();
    
    Robot(string name, string gender, int age) //定义函数
    {
        //调用对象
        _name=name;
        _gender=gender;
        _age=age;
        
    }
};

class User //用户类
{
private://创建对象
    string _name;//用户名
    string _pwd;//密码
    string _gender;//性别
    int errorTimes;//登录错误计数器
    
public:
    User();
    
    User(string name, string pwd, string gender)//定义函数
    {
        //调用对象
        _name=name;
        _pwd=pwd;
        _gender=gender;
    }
    
    string getName()//获得用户名
    {
        return _name;//返回用户名
    }
    string getPassword()//获得用户密码
    {
        return _pwd;//返回密码
    }
    
    string toString()const
    {
        //将用户名和密码组合成匹配的一行字符串
        string userInfo;
        userInfo = _name+_pwd;
        return userInfo;//返回
    }
    
    string getGender()//获得用户性别
    {
        return _gender;//返回性别
    }
    
    int getErrorTimes()//获得错误次数
    {
        return errorTimes;//计数器
    }
    
    void setPassword(string pwd)//将注册的新密码放入pwd空间中
    {
        _pwd = pwd;
    }
    
    bool isValid(string inPwd)//比对
    {
        if (_pwd==inPwd)//用户名和密码均符合，登录成功，isValid返回True
        {
            return true;
        }
        else //若否，则累加错误次数，isValid返回False
        {
            errorTimes++;
            return false;
        }
    }

};

#endif /* Functions_h */
