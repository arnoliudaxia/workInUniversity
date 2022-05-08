// HW7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ringbuffer.hpp"
#include <cassert>



/* A simple map function, which adds an element by 5 */
int add_five(int x) {
    return x + 5;
}
void simpleTest()
{
    RingBuffer<int> rb;


    int i;
    std::vector<int> rbuf(1000), wbuf(1000);



    assert(rb.is_empty());

    /* Write some data */
    for (i = 0; i < 1000; i++)
        wbuf[i] = i + 1;
    assert(rb.write_multi(16, wbuf));

    /* After write, it cannot be empty */
    assert(!rb.is_empty());

    /* Read 10 elements by "multi" */
    assert(rb.read_multi(10, rbuf));
    for (i = 0; i < 10; i++) {
        assert(rbuf[i] == i + 1);
    }
    for (size_t i = 0; i < 16; i++)
    {
        wbuf.erase(wbuf.begin());

    }
    assert(rb.write_multi(1000 - 16, wbuf));

    // read use iterator
    //for(RingBuffer<int>)

    /* Add all elements by 5 */
    rb.map(add_five);


     for (auto x = rb.begin();!(x == rb.end());x++)
    {
         x = x+1;
        std::cout << *x << std::endl;
    }
    for (auto x = __detail::__const_iterator<int>(rb.begin());x != rb.cend();++x)
    {
        x += 1;
        x = x - 1;
        std::cout << *x << std::endl;
    }

    for (i = 0; i < 1000 - 10; i++) {
        int x;
        assert(rb.read(x));
        assert(x == i + 16);
    }

    assert(rb.is_empty());


    /* Test passed */
    printf("Congratulations! You passed the simple test!\n");
}
void floatTest()
{
    RingBuffer<float> rb;
    int i;
    using namespace std;
    vector<float> rbuf(1000), wbuf(1000);



    assert(rb.is_empty());

    /* Write some data */
    for (i = 0; i < 1000; i++)
        wbuf[i] = i + 1;
    assert(rb.write_multi(16, wbuf));

    /* After write, it cannot be empty */
    assert(!rb.is_empty());

    /* Read 10 elements by "multi" */
    assert(rb.read_multi(10, rbuf));
    for (i = 0; i < 10; i++) {
        assert(rbuf[i] == i + 1);
    }
    for (size_t i = 0; i < 16; i++)
    {
        wbuf.erase(wbuf.begin());

    }
    assert(rb.write_multi(1000 - 16, wbuf));

    // read use iterator
    //for(RingBuffer<int>)

    /* Add all elements by 5 */
    rb.map(add_five);


    for (auto x = rb.begin();x != rb.end();++x)
    {
        std::cout << *x << endl;
    }
    for (auto x = rb.cbegin();x != rb.cend();++x)
    {
        std::cout << *x << endl;
    }

    for (i = 0; i < 1000 - 10; i++) {
        float x;
        assert(rb.read(x));
        assert(x == i + 16);
    }

    assert(rb.is_empty());


    /* Test passed */
    printf("Congratulations! You passed the simple test!\n");
}
void myTest()
{
    RingBuffer<float> rb;
    using namespace std;
    vector<float> rbuf, wbuf;



    assert(rb.is_empty());

    /* Write some data */
    wbuf = { 1.4,11.9,22.2,333.3,2233.4,99.99 };
    assert(rb.write_multi(6, wbuf));
    rb.read_multi(3, rbuf);
    rb.write_multi(3, wbuf);
    rb.write(move(2299.09));
    rbuf.push_back(0.0);
    rb.read(rbuf[3]);

    std::cout << "读取的数据为" << std::endl;
    for (auto x : rbuf)
    {
        cout << x << endl;
    }

    std::cout << "ringbuffer里的数据为" << std::endl;
    for (auto x = rb.begin();x != rb.end();++x)
    {
        std::cout << *x << endl;
    }


    return;

   
    printf("Congratulations! You passed My test!\n");
}
class joinc
{
public:
    joinc() :A(0),B(0) {};
    joinc(int a, int b) :
        A(a), B(b)
    {};
    int A = 0;
    int B = 0;
};
void costumClassTest()
{
    RingBuffer<joinc> rb;
    using namespace std;
    vector<joinc> rbuf, wbuf;

    /* Write some data */
    wbuf.push_back(joinc(1, 1));
    wbuf.push_back(joinc(1, 2));
    wbuf.push_back(joinc(1, 3));
    wbuf.push_back(joinc(1, 4));
    wbuf.push_back(joinc(1, 5));
    (rb.write_multi(5, wbuf));
    rb.read_multi(3, rbuf);
    rb.write_multi(3, wbuf);
    rb.write(move(joinc(2,1)));
    //rbuf.push_back(move(joinc(0,0)));
    //rb.read(rbuf[3]);
    rb.read_multi(1, rbuf);


    std::cout << "读取的数据为" << std::endl;
    for (auto x : rbuf)
    {
        cout << x.A<<"\t"<<x.B << endl;
    }
    rb.read_multi(6, rbuf);
    rb.read_multi(2, rbuf);

    std::cout << "ringbuffer里的数据为" << std::endl;
    for (auto x = rb.begin();x != rb.end();++x)
    {
        std::cout << x->A << "\t" << x->B << endl;
    }
}
void singleTest()
{
    RingBuffer<int> rb;

    //rb.write(1231);
    std::cout << "ringbuffer里的数据为" << std::endl;
    for (auto x = rb.begin();x != rb.end();++x)
    {
        std::cout << *x << std::endl;
    }
    std::cout << "ringbuffer里的数据为" << std::endl;

}
int main()
{
    std::cout << "Hello World!\n";
    



    simpleTest();
    //floatTest();
    //myTest();
    //costumClassTest();
    //singleTest();
    return 0;
}
