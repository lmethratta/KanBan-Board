/*
 Leah Methratta
6/24/22
CS 3520, 2022
userProfile.hpp file - Final Project
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "task.hpp"

#include "project.hpp"

class Task;
class Project;

using namespace std;

class UserProfile {

private:
string first_name;
string last_name;
string username;
string password;
string role;
vector<Task> tasks_assigned;


public:



// default constructor
UserProfile() {
  
}


UserProfile(string f, string l, string u, string p, string r, vector<Task> ta) {
  first_name = f;
  last_name = l;
  username = u;
  password = p;
  role = r;
  tasks_assigned = ta;
}

// copy constructor
UserProfile(const UserProfile& up) {
  this->first_name = up.first_name;
  this->last_name = up.last_name;
  this->username = up.username;
  this->password = up.password;
  this->role = up.role;
  this->tasks_assigned = up.tasks_assigned;
}

// copy assignment
UserProfile& operator=(const UserProfile& up);
    
// move assignment
UserProfile& operator=(UserProfile&& up);

// destructor
~UserProfile() {
  tasks_assigned.clear();
}

// move constructor
UserProfile(UserProfile&& up) {
  this->first_name = up.first_name;
  this->last_name = up.last_name;
  this->username = up.username;
  this->password = up.password;
  this->role = up.role;
  this->tasks_assigned = up.tasks_assigned;
  up.tasks_assigned.clear();
}

// gets the first name of this UserProfile
string get_first_name();

// gets the last name of this UserProfile
string get_last_name();

// gets the username of this UserProfile
string get_username();

// gets the password of this UserProfile
string get_password();

// gets the role of this UserProfile
string get_role();

// gets the Tasks assigned for this UserProfile
vector<Task> get_tasks_assigned();

// sets the first name of this UserProfile
void set_first_name(string new_name);

// sets the last name of this UserProfile
void set_last_name(string new_last_name);

// sets the username of this UserProfile
void set_username(string new_username);

// sets the password of this UserProfile
void set_password(string new_password);

// sets the role of this UserProfile
void set_role(string new_role);

// sets the Tasks assigned for this UserProfile
void set_tasks_assigned(vector<Task> new_tasks_assigned);

// assigns a task to a User
void assign_task_to_user(UserProfile u, Task t);

// assigns a task to themself
void assign_task_to_themself(Task t);

// deletes a Project
void delete_project(Project p);

// changes the deadline of a Project 
void change_deadline(Project p, string new_deadline);

//overload extraction operator
friend ostream &operator<<(ostream &out, UserProfile &up);

};
