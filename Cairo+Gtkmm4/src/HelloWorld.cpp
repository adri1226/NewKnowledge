#include <iostream>

#include "helloworld.hpp"

HelloWorld::HelloWorld()
    : mButton00("Button00"), mButton01("Button01") 
{
    set_title("HelloWorld");
    set_default_size(300, 300);
    mBox.set_margin(10);

    mButton00.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));
    mButton01.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));

    set_child(mBox);

    mBox.insert_child_at_start(mButton00);
    mButton00.set_expand();
    mBox.insert_child_at_start(mButton01);
    mButton01.set_expand();
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
    std::cout << "Hello World" << std::endl;
}