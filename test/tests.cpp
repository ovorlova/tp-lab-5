#include "gtest/gtest.h"
#include "Dean.h"
#include "Group.h"
#include "Student.h"

TEST(lab5, test1)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	for (int i = 0; i < 5; i++) {
		IMIKN.addMarkToStudent("Ivanov Ivan", "18PMI-1", 10);
		IMIKN.addMarkToStudent("Petrov Petr", "18PMI-1", 5);
		IMIKN.addMarkToStudent("Vasiliev Vasiliy", "18PMI-1", 0);
	}
	EXPECT_EQ(IMIKN.expelStudentsByAverageMark(4), 1);
}
TEST(lab5, test2)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.createGroup("18PMI-2", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	EXPECT_EQ(IMIKN.trasferStudentToNewGroup("Ivanov Ivan", "18PMI-1", "18PMI-2")->getGroupName(), "18PMI-2");
}
