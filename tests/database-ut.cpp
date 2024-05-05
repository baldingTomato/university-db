#include "../src/database.hpp"

#include <gtest/gtest.h>

class DatabaseTest : public testing::Test {
protected:
    Database db;

    DatabaseTest() {
        std::unique_ptr<Person> ptr1 = std::make_unique<Student>("Scooter", "Alvarez", "123 Tracewsky Street", "55030101193", Sex::Male);
        std::unique_ptr<Person> ptr2 = std::make_unique<Employee>("Kazimierz", "Wielki", "Wyszynskiego 38", "88102074233", Sex::Male);
        std::unique_ptr<Person> ptr3 = std::make_unique<Employee>("Son", "Gohan", "Gora Paozu", "64050362718", Sex::Male);
        std::unique_ptr<Person> ptr4 = std::make_unique<Student>("Izabela", "Lecka", "Al. Ujazdowskich 51", "72101496826", Sex::Female);

        db.addPerson(std::move(ptr1));
        db.addPerson(std::move(ptr2));
        db.addPerson(std::move(ptr3));
        db.addPerson(std::move(ptr4));
    }
};

TEST_F(DatabaseTest, DatabaseHasPeople) {
    EXPECT_EQ(db.isEmpty(), false);
}

TEST_F(DatabaseTest, DatabaseCanSearchForAPersonByLastName) {
    testing::internal::CaptureStdout();
    db.searchByLastName("Wielki");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono osobe:\n3400.00 Kazimierz Wielki Wyszynskiego 38 88102074233 Male\n");
}

TEST_F(DatabaseTest, DatabaseChecksIfPersonExistsWhenSearchingByLastName) {
    testing::internal::CaptureStdout();
    db.searchByLastName("Mały");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Nie ma takiego nazwiska w bazie!\n");
}

TEST_F(DatabaseTest, DatabaseCanSearchForAPersonByPesel) {
    testing::internal::CaptureStdout();
    db.searchByPesel("72101496826");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono osobe:\n399675 Izabela Lecka Al. Ujazdowskich 51 72101496826 Female\n");
}

TEST_F(DatabaseTest, DatabaseChecksIfPersonExistsWhenSearchingByPesel) {
    testing::internal::CaptureStdout();
    db.searchByPesel("72101116826");

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Nie ma takiego peselu w bazie!\n");
}

TEST_F(DatabaseTest, DatabaseCanAddNewPerson) {
    std::unique_ptr<Person> ptr = std::make_unique<Student>("Gimli", "Syn Gloina", "Erebor", "93081688751", Sex::Male);
    testing::internal::CaptureStdout();
    db.addPerson(std::move(ptr));

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Dodano Gimli Syn Gloina do bazy.\n");

    testing::internal::CaptureStdout();
    db.searchByLastName("Syn Gloina");

    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Znaleziono osobe:\n515973 Gimli Syn Gloina Erebor 93081688751 Male\n");
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

TEST_F(DatabaseTest, DatabaseCanRemovePerson) {
    testing::internal::CaptureStdout();
    db.removePerson(305044);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Osoba Scooter Alvarez zostala usunieta z bazy!\n");
}

TEST_F(DatabaseTest, DatabasePrintsOutAllPeopleSortedByPesels) {
    db.removePerson(399675);
    testing::internal::CaptureStdout();
    db.selectWholeDatabase();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "-------------------------------------------------------------------------------------------\n305044 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n3400.00 Son Gohan Gora Paozu 64050362718 Male\n3400.00 Kazimierz Wielki Wyszynskiego 38 88102074233 Male\n-------------------------------------------------------------------------------------------\n");
}

TEST_F(DatabaseTest, DatabasePrintsOutAllPeopleSortedByLastNames) {
    testing::internal::CaptureStdout();
    db.selectAndSortByLastName();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "305044 Scooter Alvarez 123 Tracewsky Street 55030101193 Male\n3400.00 Son Gohan Gora Paozu 64050362718 Male\n399675 Izabela Lecka Al. Ujazdowskich 51 72101496826 Female\n3400.00 Kazimierz Wielki Wyszynskiego 38 88102074233 Male\n");
}
