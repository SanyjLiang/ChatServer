#include <iostream>
#include <functional>

using namespace std;

int add(int a,int b)
{
    return a+b;
}

void display(const std::string &msg,int count)
{
    for(int i=0;i<count;i++)
    {
        cout<<msg<<endl;
    }
}

void print(int a,int b,int c)
{
    cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
}

class Calcalute
{
public:
    int multiply(int a,int b)
    {
        return a*b;
    }
};

//bind就是把一个函数的某些参数进行绑定一个具体值
//未绑定的值就是当作正常参数进行传参即可
void test1()
{
    //placeholders::_1  表示有一个参数没有绑定，这个参数进行传参，就是一个占位符
    auto new_add=bind(add,10,placeholders::_1);

    //相当于把新生成函数new_add的第一个参数扔到add函数的第2个参数的位置
    cout<<new_add(5)<<endl;     //相当于调用add(10,5)
}

void test2()
{
    auto sayHello=bind(display,"hello",placeholders::_1);

    //相当于把新生成函数sayHello的第一个参数扔给display的第二个参数位置
    sayHello(3);    //相当于调用display("hello",3);

    auto sayTwice=bind(display,placeholders::_1,2);

    //相当于把新生成函数sayTwice的第一个参数扔给display的第一个参数位置
    sayTwice("Hi");     //相当于调用display("Hi",2);
}

void test3()
{
    //相当于把新生成函数new_print的第三个参数传给print函数的第一个参数的位置
                               //第二个参数传递给print函数的第二个参数的位置
                               //第一个参数传递给print函数的第3个参数的位置
    auto new_print=bind(print,placeholders::_3,placeholders::_2,placeholders::_1);
    new_print(1,2,3);
}

//bind绑定类的成员函数
//注意：bind在绑定类的时候会有隐式的绑定参数，就是类对象，比如下面的cal
//这就是为什么明明原来的类函数multiply只有两个参数，但这里绑定cal对象的原因
void test4()
{
    Calcalute cal;
    auto new_cal=bind(&Calcalute::multiply,cal,5,placeholders::_1);
    cout<<"5 * 3 = "<<new_cal(3)<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}