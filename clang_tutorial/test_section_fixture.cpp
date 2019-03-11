#include "catch2/catch.hpp"


class DBConnection{
public:
  static DBConnection createConnection(std::string const &dbName){
    return DBConnection();
  }


  bool executeSQL(std::string const &query, int const id,
      std::string const &arg){
    if(arg.length() == 0)
      throw std::logic_error("empty argument of SQL query");
    return true;
  }
};


TEST_CASE("Test DBConnection Class", "[class]"){
  int uniqueID = 0;
  DBConnection testConnection = DBConnection::createConnection("testDB");

  SECTION("create employee"){
    REQUIRE_THROWS(testConnection.executeSQL(
          "INSERT INTO employee (id, name) VALUES (?, ?)", ++uniqueID, ""));
    REQUIRE(testConnection.executeSQL(
          "INSERT INTO employee (id, name) VALUES (?, ?)", ++uniqueID,
          "Jin Heo"));
  }
}

