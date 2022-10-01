/*
Leah Methratta
6/24/22
CS 3520, 2022
task.hpp file - Final Project
*/
#pragma once
#include <iostream>
#include <vector>
#include "userProfile.hpp"

using namespace std;

class UserProfile;


class Task {
private:
string task_type;
int task_id;
UserProfile *user_creator;
vector<UserProfile> assignee;
int priority;
string created_date;
string due_date;
int etc;
string description;
string comments;
string status;
bool deletion_status;

public:

 

// default constructors
Task() {
}

Task(string tt, int td, UserProfile *uc, vector<UserProfile> as, int p, string cd, string dd, int ec, string dp, string cm, string st, bool ds) {
  task_type = tt;
  task_id = td;
  user_creator = uc;
  assignee = as;
  priority = p;
  created_date = cd;
  due_date = dd;
  etc = ec;
  description = dp;
  comments = cm;
  status = st;
  deletion_status = ds;
}

// copy constructor
Task(const Task& t) {
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
}

// copy assignment
Task& operator=(const Task& t);

//move assignment
Task& operator=(Task&& t);

  //destructor
~Task() {
  assignee.clear();
}

// move constructor
Task(Task&& t) {
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
}

//gets the Task type
string get_task_type();

//gets the Task id
int get_task_id();

//gets the UserProfile of the Task creator
UserProfile* get_user_creator();

//gets the list of users assigned to this Task
vector<UserProfile> get_assignee();

//gets the priority of this Task
int get_priority();

//gets the date of when this Task was created
string get_created_date();

//gets the due date of this Task
string get_due_date();

//gets the estimated time of completion of this Task
int get_etc();

//gets the description of this Task
string get_description();

//gets the comments of this Task
string get_comments();

//gets the status of this Task
string get_status();

//gets the deletion status of this Task
bool get_deletion_status();

//updates the comments in this Task
void update_comments(string s);

//sets the Task type
void set_task_type(string tt);

//set the Task id
void set_task_id(int ti);

//sets the UserProfile of the Task creator
void set_user_creator(UserProfile uc);

//sets the list of users assigned to this Task
void set_assignee(vector<UserProfile> a);

//sets the priority of this Task
void set_priority(int p);

//sets the date of when this Task was created
void set_created_date(string cd);

//sets the due date of this Task
void set_due_date(string dd);

//sets the estimated time of completion of this Task
void set_etc(int e);

//sets the description of this Task
void set_description(string dp);

//sets the status of this Task
void set_status(string s);

//sets the deletion status of this Task
void set_deletion_status(bool ds);

//updates the status of this Task
void update_status(string us);

//overload extraction operator
friend ostream &operator<<(ostream &ost, Task &ta);

};


