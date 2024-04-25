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

TEST_F(DatabaseTest, DatabaseCanCheckPeselCorrectness) {
    EXPECT_EQ(db.checkPeselCorrectness("72101496826"), true);
    EXPECT_EQ(db.checkPeselCorrectness("72101496827"), false);
    EXPECT_EQ(db.checkPeselCorrectness("80031313353"), true);
    EXPECT_EQ(db.checkPeselCorrectness("8003a313353"), false);
    EXPECT_EQ(db.checkPeselCorrectness("8003131%353"), false);
    EXPECT_EQ(db.checkPeselCorrectness("8003131335"), false);
    EXPECT_EQ(db.checkPeselCorrectness("80031313353234"), false);
    EXPECT_EQ(db.checkPeselCorrectness(""), false);
}

TEST_F(DatabaseTest, DatabaseCanRemoveStudents) {
    testing::internal::CaptureStdout();
    db.removeStudent(1);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Student Kazimierz Wielki zostal usuniety z bazy!\n");
}

TEST_F(DatabaseTest, DatabasePrintsOutAllStudents) {
    db.removeStudent(2);
    db.removeStudent(3);
    testing::internal::CaptureStdout();
    db.selectWholeDatabase();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "-------------------------------------------------------------------------------------------\n0 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n1 Kazimierz Wielki Wyszyńskiego 38 55030101230 Male\n-------------------------------------------------------------------------------------------\n");
}

TEST_F(DatabaseTest, DatabasePrintsOutAllStudentsSortedByLastNames) {
    db.removeStudent(3);
    testing::internal::CaptureStdout();
    db.selectAndSortByLastName();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n2 Son Gohan Góra Paozu 64050362718 Male\n1 Kazimierz Wielki Wyszyńskiego 38 55030101230 Male\n");
}

TEST_F(DatabaseTest, DatabasePrintsOutAllStudentsSortedByPesels) {
    db.removeStudent(3);
    testing::internal::CaptureStdout();
    db.selectAndSortByPesel();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n1 Kazimierz Wielki Wyszyńskiego 38 55030101230 Male\n2 Son Gohan Góra Paozu 64050362718 Male\n");
}
