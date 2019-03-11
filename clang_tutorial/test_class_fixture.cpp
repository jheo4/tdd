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


class DBConnectionTestFixture{
private:
  static int uniqueID;
protected:
  DBConnection testConnection;
  DBConnectionTestFixture()
    : testConnection(DBConnection::createConnection("testDB")){}

  int getID(){
    return ++uniqueID;
  }
};

int DBConnectionTestFixture::uniqueID = 0;


TEST_CASE_METHOD(DBConnectionTestFixture, "create nonamed employee",
    "[create]"){
  REQUIRE_THROWS(testConnection.executeSQL(
        "INSERT INTO employee (id, name) VALUES (?, ?)", getID(), ""));
}


TEST_CASE_METHOD(DBConnectionTestFixture, "create named emplyee", "[create]"){
  REQUIRE(testConnection.executeSQL(
        "INSERT INTO employee (id, name) VALUES (?, ?)", getID(), "Jin Heo"));
}

