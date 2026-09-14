#pragma once
#include "person.hpp"
#include <span>
#include <string>
#include <algorithm>

inline std::string csv_escape(std::string s) {
  bool need_quotes = s.find_first_of(",\"\n") != std::string::npos;
  if (need_quotes) {
    std::string t; t.reserve(s.size()+2);
    for (char c: s) {
      if (c == '"') {
        t += "\"\"";
      } else {
        t += c;
      }
    }
    return "\"" + t + "\"";
  }
  return s;
}

inline std::string join_json_list(const nlohmann::json& json, const char* key) {
  std::string result;
  if (!json.contains(key)) return result;

  for (const auto& item : json.at(key)) {
    if (!result.empty()) result += ';';
    result += item.get<std::string>();
  }
  return result;
}

inline std::string write_people_csv(std::span<const Person*> people) {
  std::string csv = "role,id,name,email,grad_year,office,courses,teaches\n";

  for (const Person* person : people) {
    const auto json = person->to_json();

    csv += csv_escape(json.at("role").get<std::string>()) + ",";
    csv += std::to_string(json.at("id").get<int>()) + ",";
    csv += csv_escape(json.at("name").get<std::string>()) + ",";
    csv += csv_escape(json.at("email").get<std::string>()) + ",";
    if (json.contains("grad_year")) {
      csv += std::to_string(json.at("grad_year").get<int>());
    }
    csv += ",";
    if (json.contains("office")) {
      csv += csv_escape(json.at("office").get<std::string>());
    }
    csv += ",";
    csv += csv_escape(join_json_list(json, "courses"));
    csv += ",";
    csv += csv_escape(join_json_list(json, "teaches"));
    csv += "\n";
  }

  return csv;
}