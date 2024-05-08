#include "../src/employee.hpp"

#include <gtest/gtest.h>

class EmployeeTest : public testing::Test {
protected:
    Employee employee = Employee("Scooter", "Alvarez", "123 Tracewsky Street", "55030101193", Sex::Male);
};

TEST_F(EmployeeTest, EmployeeHasName) {
    EXPECT_EQ(employee.getName(), "Scooter");
}

TEST_F(EmployeeTest, EmployeeHasLastName) {
    EXPECT_EQ(employee.getLastName(), "Alvarez");
}

TEST_F(EmployeeTest, EmployeeHasAddress) {
    EXPECT_EQ(employee.getAddress(), "123 Tracewsky Street");
}

TEST_F(EmployeeTest, EmployeeHasPesel) {
    EXPECT_EQ(employee.getPesel(), "55030101193");
}

TEST_F(EmployeeTest, EmployeeHasSex) {
    EXPECT_EQ(employee.getSex(), "Male");
}

TEST_F(EmployeeTest, EmployeeDoesNotHaveIndex) {
    employee.setIndex(224752);

    EXPECT_EQ(employee.getIndex(), 0);
}

TEST_F(EmployeeTest, EmployeeHasEarnings) {
    EXPECT_EQ(employee.getEarnings(), 3400.00);
}

TEST_F(EmployeeTest, EmployeeCanBePrintedOut) {
    testing::internal::CaptureStdout();
    employee.printData();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "3400.00 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n");

    employee.setEarnings(5001.00);

    testing::internal::CaptureStdout();
    employee.printData();
    
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "5001.00 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n");
}