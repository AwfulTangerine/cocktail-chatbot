# cocktail-chatbot
A simple chatbot for my C++ programming final project in 2018. This application scene was inspired by my first internship/part-time job as a cocktail salesperson using AI chatbot to act as a virtual cocktail bartender, directly talking to Wechat followers.  

Here is my original introduction document on this basic project:  


1 Program Function Introduction  
1.1 Purpose  
>To enable the user to create a virtual character and to chat with different robots about cocktail related topics.  

1.2 Features  
>1.2.1 Initialization  
>>Read the user information from "user.txt" and put it into an array to record the user name and password.  


>1.2.2 Registration  
>>The user types in the user name and password, makes sure the user name is not duplicated with the existing user, and then writes it to the file.  


>1.2.3 Login function (record the number of errors)  
>>The user types in the user name and password, and if the match is confirmed in the user list, the login is displayed successfully; the next chat operation can be performed. If you make a mistake, you will be banned from logging in and exit the system after counting more than three times.  


>1.2.4 Chat function (select bots to chat)  
>>There are two bots in the system, Jerry and Whiskey. build the robot human and record its basic information. The user can select a different bot for a conversation. Using the life value measurement, if the user mentions the corresponding keyword, the conversation can continue; if the keyword is not in the scope of the bot, the bot will learn and the life value doubles.  


1.3 Design environment  
>IDE program: Xcode 9.4  
>Operating platform: Mac OS X High Sierra  
