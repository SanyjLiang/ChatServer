#include "json.hpp"
using json=nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#if 0
//json序列化示例1
void func1()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhangsan";
    js["to"]="lisi";
    js["msg"]="hello ,what are u doing";

    string sendBuf=js.dump();
    cout<<sendBuf.c_str()<<endl;
}

//json序列化示例2
void func2()
{
    json js;
    //添加数组
    js["id"]={1,2,3,4,5};
    //添加kry-value
    js["name"]="zhang san";
    //添加对象
    js["msg"]["zhang san"]="hello world";
    js["msg"]["liu shuo"]="hello china";
    //上面等同于下面这句一次性添加数组对象
    js["msg"]={{"zhang san","hello world"},{"liu shuo","hello china"}};
    cout<<js<<endl;
}

//json序列化示例3
void func3()
{
    json js;

    //直接序列化一个vector容器
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    js["list"]=v;

    //直接序列化一个map容器
    map<int,string>m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});
    js["path"]=m;

    string sendBuf=js.dump();   //json数据对象 =》序列化成 json字符串
    cout<<sendBuf<<endl;
}

int main()
{
    //数据序列化后的样子
    func1();
    func2();
    func3();
    return 0;
}
#endif 


//下面是演示反序列化！！！！！！！！！！！！！！！！！！！！！！！


//json序列化示例1
string func1()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhangsan";
    js["to"]="lisi";
    js["msg"]="hello ,what are u doing";

    string sendBuf=js.dump();
    return sendBuf;
}

//json序列化示例2
string func2()
{
    json js;
    //添加数组
    js["id"]={1,2,3,4,5};
    //添加kry-value
    js["name"]="zhang san";
    //添加对象
    js["msg"]["zhang san"]="hello world";
    js["msg"]["liu shuo"]="hello china";
    //上面等同于下面这句一次性添加数组对象
    js["msg"]={{"zhang san","hello world"},{"liu shuo","hello china"}};
    return js.dump();
}

//json序列化示例3
string func3()
{
    json js;

    //直接序列化一个vector容器
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    js["list"]=v;

    //直接序列化一个map容器
    map<int,string>m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});
    js["path"]=m;

    string sendBuf=js.dump();   //json数据对象 =》序列化成 json字符串
    return sendBuf;
}

int main()
{
    //数据反序列化后的样子

    #if 0
    string recvBuf=func1();
    // 数据的反序列化  json字符串 =》反序列化 数据对象 （看作容器，方便访问）
    json jsBuf=json::parse(recvBuf);
    cout<<jsBuf["msg_type"]<<endl;
    cout<<jsBuf["from"]<<endl;
    cout<<jsBuf["to"]<<endl;
    cout<<jsBuf["msg"]<<endl;
    #endif

    #if 0
    string recvBuf=func2();
    json jsBuf=json::parse(recvBuf);

    cout<<jsBuf["id"]<<endl;
    auto arr=jsBuf["id"];
    cout<<arr[2]<<endl;

    auto msgjs=jsBuf["msg"];
    cout<<jsBuf["msg"]["zhang san"]<<endl;
    cout<<msgjs["zhang san"]<<endl;
    cout<<msgjs["liu shuo"]<<endl;

    #endif

    string recvBuf=func3();
    json jsbuf=json::parse(recvBuf);
    cout<<jsbuf["list"]<<endl;
    auto arr=jsbuf["list"];
    cout<<arr[1]<<endl;

    vector<int>vec=jsbuf["list"];
    for(int &v:vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;

    cout<<"==========="<<endl;

    cout<<jsbuf["path"][1]<<endl;
    auto msgjs2=jsbuf["path"];
    cout<<msgjs2[2]<<endl;

    map<int,string>mymap=jsbuf["path"];
    for(auto &p:mymap)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    return 0;
}