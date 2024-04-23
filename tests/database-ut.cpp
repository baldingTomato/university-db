#include "../src/database.hpp"

#include <gtest/gtest.h>

class DatabaseTest : public testing::Test {
protected:
    Database db;

    DatabaseTest() {
        db.addStudent("Scooter", "Alvarez", "123 Tracewsky Street", "55030101193", Sex::Male);
        db.addStudent("Kazimierz", "Wielki", "Wyszyńskiego 38", "55030101230", Sex::Male);
        db.addStudent("Son", "Gohan", "Góra Paozu", "64050362718", Sex::Male);
        db.addStudent("Izabela", "Łęcka", "Al. Ujazdowskich 51", "72101496826", Sex::Female);
    }
};

TEST_F(DatabaseTest, DatabaseHasStudents) {
    EXPECT_EQ(db.isEmpty(), false);
}

TEST_F(DatabaseTest, DatabaseCanSearchForAStudentByLastName) {
    testing::internal::CaptureStdout();
    db.searchByLastName("Wielki");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono studenta:\n1 Kazimierz Wielki Wyszyńskiego 38 55030101230 Male\n");
}

TEST_F(DatabaseTest, DatabaseChecksIfStudentExistsWhenSearchingByLastName) {
    testing::internal::CaptureStdout();
    db.searchByLastName("Mały");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Nie ma takiego nazwiska w bazie!\n");
}

TEST_F(DatabaseTest, DatabaseCanSearchForAStudentByLastPesel) {
    testing::internal::CaptureStdout();
    db.searchByPesel("72101496826");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono studenta:\n3 Izabela Łęcka Al. Ujazdowskich 51 72101496826 Female\n");
}

TEST_F(DatabaseTest, DatabaseChecksIfStudentExistsWhenSearchingByPesel) {
    testing::internal::CaptureStdout();
    db.searchByPesel("72101116826");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Nie ma takiego peselu w bazie!\n");
}

TEST_F(DatabaseTest, DatabaseCanAddNewStudents) {
    testing::internal::CaptureStdout();
    db.addStudent("Gimli", "Syn Gloina", "Erebor", "93081688751", Sex::Male);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Dodano studenta do bazy.\n");

    testing::internal::CaptureStdout();
    db.searchByLastName("Syn Gloina");

    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono studenta:\n4 Gimli Syn Gloina Erebor 93081688751 Male\n");
}
