/*
Leah Methratta
6/24/22
CS 3520, 2022
task.cpp file - Final Project
*/
#include <iostream>
#include <time.h>
//#include <chrono>
//#include "userProfile.hpp"
#include "task.hpp"

//#include "combined.hpp"

using namespace std;

// copy assignment
Task& Task::operator=(const Task& t) {

  if(this != &t) {
    delete[] this->user_creator;
    assignee.clear();
  }

  this->task_type = t.task_type;
  this->task_id = t.task_id;
  this->user_creator = t.user_creator;
  this->assignee = t.assignee;
  this->priority = t.priority;
  this->created_date = t.created_date;
  this->due_date = t.due_date;
  this->etc = t.etc;
  this->description = t.description;
  this->comments = t.comments;
  this->status = t.status;
  this->deletion_status = t.deletion_status;

  return *this;
  
}

//move assignment
Task& Task::operator=(Task&& t) {
  if(this != &t) {
    assignee.clear();
  }

  this->task_type = t.task_type;
  this->task_id = t.task_id;
  this->user_creator = t.user_creator;
  this->assignee = t.assignee;
  t.assignee.clear();
  
  this->priority = t.priority;
  this->created_date = t.created_date;
  this->due_date = t.due_date;
  this->etc = t.etc;
  this->description = t.description;
  this->comments = t.comments;
  this->status = t.status;
  this->deletion_status = t.deletion_status;
  

  return *this;
}


//gets the Task type
string Task::get_task_type(){
  return task_type;
  
}

//gets the Task id
int Task::get_task_id(){
  return task_id;
}

//gets the UserProfile of the Task creator
UserProfile* Task::get_user_creator(){
  return user_creator;
}

//gets the list of users assigned to this Task
vector<UserProfile> Task::get_assignee(){
  return assignee;
}

//gets the priority of this Task
int Task::get_priority(){
  return priority;
}

//gets the date of when this Task was created
string Task::get_created_date(){
  return created_date;
}

//gets the due date of this Task
string Task::get_due_date(){
  return due_date;
}

//gets the estimated time of completion of this Task
int Task::get_etc(){
  return etc;
}

//gets the description of this Task
string Task::get_description() {
  return description;
}

//gets the comments of this Task
string Task::get_comments() {
  return comments;
}

//gets the status of this Task
string Task::get_status() {
  return status;
}

//gets the deletion status of this Task
bool Task::get_deletion_status() {
  return deletion_status;
}

//updates the comments in this Task
void Task::update_comments(string s) {
  comments = s;
}

//sets the Task type
void Task::set_task_type(string tt){
  task_type = tt;
}

//set the Task id
void Task::set_task_id(int td){
  task_id = td;
}

//sets the UserProfile of the Task creator
void Task::set_user_creator(UserProfile uc){
  user_creator = &uc;
}

//sets the list of users assigned to this Task
void Task::set_assignee(vector<UserProfile> a){
  assignee = a;
}

//sets the priority of this Task
void Task::set_priority(int p){
  priority = p;
}

//sets the date of when this Task was created
void Task::set_created_date(string cd){
  created_date = cd;
}

//sets the due date of this Task
void Task::set_due_date(string d){
  due_date = d;
}

//sets the estimated time of completion of this Task
void Task::set_etc(int e){
  etc = e;
}

//sets the description of this Task
void Task::set_description(string dp){
  description = dp;
}

//sets the status of this Task
void Task::set_status(string s){
  status = s;
}

//sets the deletion status of this Task
void Task::set_deletion_status(bool ds){
  deletion_status = ds;
}

//updates the status of this Task
void Task::update_status(string us){
  status = us;
}



//overload extraction operator
ostream &operator<<(ostream &ost, Task &ta){
  ost<< endl;
  ost<< "Task ID: "<<ta.get_task_id() << endl;
  ost<< "User Creator: "<<ta.get_user_creator()->get_username() << endl;
  ost<< "Task Assignees: " << endl;
  for(auto val: ta.get_assignee()) {
    ost<<val.get_username() <<", ";
  }
  ost<< "Priority: "<<ta.get_priority() << endl;
  ost<< "Created Date : " + ta.get_created_date() << endl;
  ost << "Due Date : " + ta.get_due_date() << endl;
  
  time_t ct=time(0);
  string currenttime = ctime(&ct);
  ost<< "Today's Date: " << currenttime.substr(0, 10) << ", " << currenttime.substr(20, 25) << endl;
  int cd_month;
  //getting the integer value of month for current date date
  if (currenttime.substr(4,6).compare("Jan")){   
    cd_month = 1; 
  }
  else if(currenttime.substr(4,6).compare("Feb")){
    cd_month = 2;
  }
  else if(currenttime.substr(4,6).compare("Mar")){
    cd_month = 3;
  }
  else if(currenttime.substr(4,6).compare("Apr")){
    cd_month = 4;
  }
  else if(currenttime.substr(4,6).compare("May")){
    cd_month = 5;
  }
  else if(currenttime.substr(4,6).compare("Jun")){
    cd_month = 6;
  }
  else if(currenttime.substr(4,6).compare("Jul")){
    cd_month = 7;
  }
  else if(currenttime.substr(4,6).compare("Aug")){
    cd_month = 8;
  }
  else if(currenttime.substr(4,6).compare("Sep")){
    cd_month = 9;
  }
  else if(currenttime.substr(4,6).compare("Oct")){
    cd_month = 10;
  }
    else if(currenttime.substr(4,6).compare("Nov")){
    cd_month = 11;
  }
    else if(currenttime.substr(4,6).compare("Dec")){
    cd_month = 12;
  }
  
  int ta_month;
  //getting the integer value of month for due date
  if (ta.get_due_date().substr(4,6).compare("Jan")){   
    ta_month = 1; 
  }
  else if(ta.get_due_date().substr(4,6).compare("Feb")){
    ta_month = 2;
  }
  else if(ta.get_due_date().substr(4,6).compare("Mar")){
    ta_month = 3;
  }
  else if(ta.get_due_date().substr(4,6).compare("Apr")){
    ta_month = 4;
  }
  else if(ta.get_due_date().substr(4,6).compare("May")){
    ta_month = 5;
  }
  else if(ta.get_due_date().substr(4,6).compare("Jun")){
    ta_month = 6;
  }
  else if(ta.get_due_date().substr(4,6).compare("Jul")){
    ta_month = 7;
  }
  else if(ta.get_due_date().substr(4,6).compare("Aug")){
    ta_month = 8;
  }
  else if(ta.get_due_date().substr(4,6).compare("Sep")){
    ta_month = 9;
  }
  else if(ta.get_due_date().substr(4,6).compare("Oct")){
    ta_month = 10;
  }
    else if(ta.get_due_date().substr(4,6).compare("Nov")){
    ta_month = 11;
  }
    else if(ta.get_due_date().substr(4,6).compare("Dec")){
    ta_month = 12;
  }

  int months_left;
  months_left = ta_month - cd_month;

  int days_left;
  days_left = stoi(ta.get_due_date().substr(24, 25)) - stoi(currenttime.substr(24, 25));
  
  ost<< "Days Left: "<<months_left<<"month(s) and "<< days_left << "day(s) left to complete task." << endl;
   ost<< "Estimated time of completion: " << to_string(ta.get_etc()) << endl;
   ost<< "Description: " << ta.get_description() <<endl;
   ost<< "Comments: " << ta.get_comments() <<endl;
   ost<< "Status: " << ta.get_status() << endl;
  return ost;
  
}
