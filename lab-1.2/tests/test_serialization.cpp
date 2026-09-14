#include <catch2/catch_test_macros.hpp>
#include "csv.hpp"
#include "student.hpp"
#include "instructor.hpp"

TEST_CASE("Student JSON serialization") {
  Student s(10,"Alice","alice@uni.edu",2027, {"CS101","HIST110"});
  auto j = s.to_json();
  CHECK(j.at("role") == "Student");
  CHECK(j.at("name") == "Alice");
  CHECK(j.at("grad_year") == 2027);
}

TEST_CASE("Instructor YAML serialization") {
  Instructor i(11,"Bob","bob@uni.edu","C-210", {"CS101"});
  auto y = i.to_yaml();
  CHECK(y["role"].as<std::string>() == "Instructor");
  CHECK(y["office"].as<std::string>() == "C-210");
}

TEST_CASE("CSV escaping handles commas and quotes") {
  Student s(12,"Eve, \"The Great\"","eve@uni.edu",2028, {"CS,101","AI\"Lab"});
  auto row = s.csv_row();
  REQUIRE(row.find("\"Eve, \"\"The Great\"\"\"") != std::string::npos);
}

TEST_CASE("Validation throws on bad email") {
  REQUIRE_THROWS_AS(Student(13,"Zed","not-an-email",2026), ValidationError);
}

TEST_CASE("JSON round-trips back to the original objects") {
  Student student(20, "Alice", "alice@uni.edu", 2027, {"CS101"});
  Instructor instructor(21, "Bob", "bob@uni.edu", "C-210", {"CS101"});

  CHECK(Student::from_json(student.to_json()).to_json() == student.to_json());
  CHECK(Instructor::from_json(instructor.to_json()).to_json() == instructor.to_json());
}

TEST_CASE("JSON parsing rejects invalid input") {
  auto student_json = Student(22, "Eve", "eve@uni.edu", 2028).to_json();
  student_json["email"] = "not-an-email";
  REQUIRE_THROWS_AS(Student::from_json(student_json), ValidationError);

  auto instructor_json = Instructor(23, "Dan", "dan@uni.edu", "C-210").to_json();
  instructor_json.erase("office");
  REQUIRE_THROWS_AS(Instructor::from_json(instructor_json), ValidationError);
}

TEST_CASE("Polymorphic CSV uses a stable superset header") {
  Student student(24, "Alice", "alice@uni.edu", 2027, {"CS101"});
  Instructor instructor(25, "Bob", "bob@uni.edu", "C-210", {"CS101"});
  const Person* people[] = {&student, &instructor};

  const auto csv = write_people_csv(people);
  CHECK(csv ==
    "role,id,name,email,grad_year,office,courses,teaches\n"
    "Student,24,Alice,alice@uni.edu,2027,,CS101,\n"
    "Instructor,25,Bob,bob@uni.edu,,C-210,,CS101\n");
}