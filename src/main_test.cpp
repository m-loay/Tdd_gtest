/*
 * TestCase.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: mloay
 */

#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <sstream>
// #include"test_cases.h"
#include "App.h"

using namespace std;

TEST(G1,addTwoNumbers1)
{
    EXPECT_EQ(addTwoNumbers(3,5),8);
}

TEST(G1,addTwoNumbers2)
{
    EXPECT_EQ(addTwoNumbers(4,6),10);
}

TEST(G1,addTwoNumbers3)
{
    EXPECT_EQ(addTwoNumbers(4,6),5);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}