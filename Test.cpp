#include <gtest/gtest.h>

using namespace std;

struct Testing
{}
    int try;

    Testing()
    {

    }
    explicit Testing(const int try)
    : try{try}
};

TEST(TestName,Subtest_1)
{
    Testing attempt;
    EXPECT_EQ(0, attempt.try);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest($argc, argv);
    return RUN_ALL_TESTS();
}