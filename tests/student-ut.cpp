#include "../src/student.hpp"

#include <gtest/gtest.h>

class StudentTest : public testing::Test {
protected:
    Student student = Student("Scooter", "Alvarez", "123 Tracewsky Street", "55030101193", Sex::Male);
};

TEST_F(StudentTest, StudentHasName) {
    EXPECT_EQ(student.getName(), "Scooter");
}

TEST_F(StudentTest, StudentHasLastName) {
    EXPECT_EQ(student.getLastName(), "Alvarez");
}

TEST_F(StudentTest, StudentHasAddress) {
    EXPECT_EQ(student.getAddress(), "123 Tracewsky Street");
}

TEST_F(StudentTest, StudentHasPesel) {
    EXPECT_EQ(student.getPesel(), "55030101193");
}

TEST_F(StudentTest, StudentHasSex) {
    EXPECT_EQ(student.getSex(), "Male");
}

TEST_F(StudentTest, StudentHasIndex) {
    student.setIndex(224752);

    EXPECT_EQ(student.getIndex(), 224752);
}

TEST_F(StudentTest, StudentCanBePrintedOut) {
    testing::internal::CaptureStdout();
    student.printData();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n");

    student.setIndex(224752);

    testing::internal::CaptureStdout();
    student.printData();
    
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "224752 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n");
}