/*
Leah Methratta
6/24/22
CS 3520, 2022
userProfile.hpp file - Final Project
*/

#include "userProfile.hpp"
#include <iostream>

using namespace std;

string first_name;
string last_name;
string username;
string password;
string role;
vector<Task> tasks_assigned;

// copy assignment
UserProfile& UserProfile::operator=(const UserProfile& up) { 
  if(this != &up) {
    
    tasks_assigned.clear();
  }

  this-> first_name = up.first_name;
  this-> last_name = up.last_name;
  this -> username = up.username;
  this -> password = up.password;
  this -> role = up.role;
  this ->  tasks_assigned = up.tasks_assigned;

  return *this; 
  
}

// move assignment
UserProfile& UserProfile::operator=(UserProfile&& up) { 
  if(this != &up) {
    tasks_assigned.clear();   
  }

  this-> first_name = up.first_name;
  this-> last_name = up.last_name;
  this -> username = up.username;
  this -> password = up.password;
  this -> role = up.role;
  this ->  tasks_assigned = up.tasks_assigned;
  tasks_assigned.clear();

  return *this;
  
}

// gets the name of this Project
string UserProfile::get_first_name() {
  return first_name;
}

string UserProfile::get_last_name() {
  return last_name;
}

// gets the username of this UserProfile
string UserProfile::get_username() {
  return username;
}

// gets the password of this UserProfile
string UserProfile::get_password() {
  return password;
}

// gets the role of this UserProfile
string UserProfile::get_role() {
  return role;
}

// gets the Tasks assigned for this UserProfile
vector<Task> UserProfile::get_tasks_assigned() {
  return tasks_assigned;
}

// sets the first name of this UserProfile
void UserProfile::set_first_name(string new_first_name) {
  first_name = new_first_name;
}

// sets the last name of this UserProfile
void UserProfile::set_last_name(string new_last_name) {
  last_name = new_last_name;
}

// sets the username of this UserProfile
void UserProfile::set_username(string new_username) {
  username = new_username;
}

// sets the password of this UserProfile
void UserProfile::set_password(string new_password) {
  password = new_password;
}

// sets the role of this UserProfile
void UserProfile::set_role(string new_role) {
  role = new_role;
}


// sets the Tasks assigned for this UserProfile
void UserProfile::set_tasks_assigned(vector<Task> new_tasks_assigned) {
  tasks_assigned = new_tasks_assigned;
}

// changes the deadline of a Project 
void UserProfile::change_deadline(Project p, string new_deadline) {
  if(role.compare("PM") == 0) {
    p.set_deadline(new_deadline);
  }
  else {
    cout<<"Not authorized to change the deadline.";
  }
}

// assigns a task to a User
void UserProfile::assign_task_to_user(UserProfile u, Task t) {
  if(role.compare("PM") == 0) {
    t.get_assignee().push_back(u);
    u.get_tasks_assigned().push_back(t);
  }
  else {
    cout<<"Not authorized to assign task to user.";
  }
}


// assigns a task to themself
void UserProfile::assign_task_to_themself(Task t) {
  if(role.compare("PM") == 0) {
    t.get_assignee().push_back(*this);
    this->get_tasks_assigned().push_back(t);
  }
  else if(role.compare("Dev") == 0 && t.get_assignee().size() == 0) {
    t.get_assignee().push_back(*this);
    this->get_tasks_assigned().push_back(t);
  }
  else {
    cout<<"Not authorized to assign a task."<<endl;
  } 
}

// deletes a Project
void UserProfile::delete_project(Project p) {
  if(role.compare("PM") == 0) {
    p.set_deletion_status(true);

    // clears the list of tasks assigned
    for(auto val: p.get_proj_workers()) {
      val.get_tasks_assigned().clear();
    } 
    p.get_proj_workers().clear();
    p.get_to_do().clear();
    p.get_doing().clear();
    p.get_done().clear();
  }
  else{
    cout<<"Not authorized to delete tasks."<<endl;
  }
}

//overload extraction operator
ostream &operator<<(ostream &ost, UserProfile &up){
  ost<< endl;
  ost<< "User's Name: " + up.get_first_name() + " " + up.get_last_name() << endl;
  ost << "Username: " + up.get_username() <<endl;
  ost << "Role: " + up.get_role() <<endl;
  ost << "List of tasks: "<<endl;
  
  for(auto task: up.get_tasks_assigned()) {
    ost<<task<<endl;
  }
  
  return ost;
}

