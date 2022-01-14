//
//  main.cpp
//  rikaiChatSystem
//
//  Created by 马婕慧 on 2018/6/20.
//  Copyright © 2018年 马婕慧. All rights reserved.
//

//姓名：马婕慧
//学号：1667141
//程序功能：写入用户列表，进行用户注册登录操作，登录失败3次以上强制退出，登录成功后可以选择不同的机器人聊天。

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Functions.h"

//定义User的Vector数组
vector<User>users;



using namespace std;

//设置查找用户指针
User* findUser(string name)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getName() == name)
        {
            return &users[i];
        }
    }
    return nullptr;
}

//设置新增用户
void addUser(string name, string pwd, string gender)
{
    
    if (findUser(name) == nullptr)//确保用户名不重复
    {
        User newUser(name, pwd, gender);
        users.push_back(newUser); //添加新用户
    }
    else
    {
        cout << "用户已存在～"<<endl;
    }
    
}




int main()
{
   
    //初始化，读取user列表
    ifstream userList("user.txt");
    if(userList.is_open())
        cout << "User list is opened successfully!" << endl;//显示读取成功
        string name;
        string pwd;
        string gender;
        while (!userList.eof())//全部遍历文件后
        {
            userList >> name >> pwd >> gender;//按空格读取用户名，密码，性别
            User tmp(name, pwd, gender);
            users.push_back (tmp);
        }
    
    
    
    cout<< "~~~~~~欢迎进入Jerry的聊天室！~~~~~~"<< endl; //欢迎界面
    cout<<"0-登录，1-注册，q-退出程序"<< endl;
    cout<<"请选择：";   //选择操作
    bool loginFlag = false;     //登录成功标志
    int errorTimes=0;      //错误次数
    int maxErrorTimes = 3;      //最大错误次数
    char cha;   //选择指针
    cin >> cha;     //输入选择指针
    string nameGroup[5]={"Zoey","Lisa","Alan","John","Dana"};
    string pwdGroup[5]={"tcrnm121","tcrnm122","tcrnm123","tcrnm124","tcrnm125"};
    switch (cha)
    {
        case '0': //登录操作
            while(true)
            {
                
                for(int i=0; i<5; i++)
                {
                    if(errorTimes>=maxErrorTimes)//累计用户名或密码登录错误，超过三次退出
                    {
                        cout << "输错三次啦，自罚三杯！" << endl;
                        exit(-1);
                    }
                    //输入用户名和密码
                    cout << "你的用户名是？" << endl;
                    cin >> name;
                    cout << "你的密码是？" << endl;
                    cin >> pwd;
                    //查找用户名，是否和密码匹配；如果用户名和密码匹配，则显示登录成功
                    if (nameGroup[i] == name && pwdGroup[i]==pwd)   //查找是否匹配数组
                    {
                        loginFlag = true;   //匹配成功，loginFlag指针状态改变
                        cout << "登录成功，快来和Jerry，Whiskey聊天吧！" << endl;    //提示登录成功
                        break;
                    }
                    else   //用户名或密码不匹配，即登录失败
                    {
                        cout << "用户名似乎不太对哦。想再试一次？y or n" << endl;
                        errorTimes++; //错误次数累计
                        char chYesOrNo;
                        cin>> chYesOrNo;
                        if(chYesOrNo=='n')
                        {
                            break;
                        }
                }
            }
                break;
                
                
        case '1': //注册操作
                {
                    cout << "你叫什么？" << endl;
                    cin >> name;
                    cout << "你的密码是？";
                    cin >> pwd;
                    cout << "你是男生or女生";
                    cin >> gender;
                    addUser(name, pwd, gender);//新增数组
                    cout<<"注册成功～"<< endl;
                    break;
                }
                
     
        case 'q': //退出系统
                cout << "这么快就想离开吗，好吧，下次见～" << endl;
                break;
            }
    }
    
    
    
    while(loginFlag==true)//登录成功时进行操作
    {
        Robot jerryRobot("Jerry", "男", 35);//Jerry机器人
        Robot whiskeyRobot("Whiskey", "牧羊犬", 2);//Whiskey机器人
        int lifeValueJerry=0;//Jerry初始生命值
        int lifeValueWhiskey=0;//Whiskey初始生命值
        char ch;//选择按钮
        
        while (true)//可以无限循环聊天
        {
            cout << "请选择聊天机器人:1-Jerry,2-Whiskey" << endl;
            cin >> ch;//进行选择
            switch (ch)
            {
                case '1'://进入Jerry聊天
                {
                    cout << "Hello, I'm Jerry, you can talk anything about cocktails with me"<< endl;
                    string answer;//初始化用户的回答
                    cout << "I:";
                    cin >> answer;//用户输入回答；
                    string::size_type pos = answer.find("cocktail");//包含cocktail的回答
                    if(pos == string::npos)//如果不包含
                    {
                        cout << "Wait a sec. Let me think about it";
                        cout << "But now I got it, thanks!";
                        lifeValueJerry=lifeValueJerry+2;//Jerry学习了人类的语言，生命值+2
                    }
                    else //如果包含关键字
                    {
                        cout << "Which one do u like best? Mojito or Gin&Tonic?" << endl;//选择想了解的鸡尾酒
                        cin >> answer;//直接输入答案关键字
                        if(answer=="Mojito")//关键字为莫吉托
                        {
                            cout << "Ok, here's the receipe for Mojito, calm down and have a try!";
                            cout << "You need vodka, rum and lime juice."<< endl;//获得莫吉托的配方
                            lifeValueJerry=lifeValueJerry+1;//Jerry生命值+1
                        }
                        if(answer=="Gin&Tonic")//关键字为金汤力
                        {
                            cout << "A receipe for Gin&Tonic, just take a drink with Jerry!";
                            cout << "The receipe is easy. You only need a cup of gin and tonic water." << endl;//获得金汤力的配方
                            lifeValueJerry=lifeValueJerry+1;//Jerry生命值+1
                        }
                        else // 如都不包含，则Jerry需学习
                        {
                            cout << "Sorry, I'll be busy for a while. Bye~" ;
                            cout << "Thanks for your chat with me !" << endl;
                            lifeValueJerry=lifeValueJerry+2;//学习时生命值+2
                        }
                        
                    }
                    cout << "Jerry's life value:" << lifeValueJerry << endl;//输出最终生命值
                    cout << "Thank you! Bye~" << endl; //结束第一段聊天
                    break;
                }
                    
                case '2'://选择Whiskey，注释同上
                {
                    cout << "Woof Woof!"<< endl;
                    string answerWhiskey;
                    cin >> answerWhiskey;
                    if(answerWhiskey != "Who are you?")
                    {
                        cout << "This is the first time that Whiskey came across human words he doesn't understand." << endl;
                        cout << "Thank you very much!" << endl;
                        lifeValueWhiskey=lifeValueWhiskey+4;
                    }
                    else
                    {
                        cout << "Actually I am Jerry's dog. Do you want to have some Whiskey Highball or Whiskey Sour?" << endl;
                        cin>> answerWhiskey;
                        if(answerWhiskey=="Highball" || answerWhiskey=="the first one")
                        {
                            cout << "I like it too! Woof!" << endl;
                            cout << "Then Whiskey gives you a receipe:" << endl;
                            lifeValueWhiskey=lifeValueWhiskey+2;
                        }
                        if(answerWhiskey=="Sour" || answerWhiskey=="the second")
                        {
                            cout << "Woof, Jerry likes it, I dont." << endl;
                            cout << "Jerry will tell you the receipe. Bye...";
                            lifeValueWhiskey=lifeValueWhiskey+2;
                        }
                        else
                        {
                            cout << "Whiskey will understand humans words more in the future!" << endl;
                            cout << "Jerry: 'Whiskey, Let's go to the bar." << endl;
                            lifeValueWhiskey=lifeValueWhiskey+4;
                        }
                    }
                    cout << "Whiskey's life value:" << lifeValueWhiskey << endl;
                    cout << "Thank you! Bye~" << endl;
                    break;
                }
                    
                default://其他输入
                    
                    break;//退出
            }
        }
    }
    return 0;
}
