/*
Leah Methratta
6/24/22
CS 3520, 2022
Project.hpp file - Final Project
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "task.hpp"


class UserProfile;
class Task;

using namespace std;

class Project {

private:
string name;
string objective;
string prod_customer;
vector<Task> to_do;
vector<Task> doing;
vector<Task> done;
vector<UserProfile> proj_workers;
string deadline;
bool deletion_status;

// add list of assignees, list of project manager
public:

// default constructor
Project(string n, string o, string p_customer, vector<Task> td, vector<Task> doi, vector<Task> don, vector<UserProfile> pw, string d, bool ds) {
  name = n;
  objective = o;
  prod_customer = p_customer;
  to_do = td;
  doing = doi;
  done = done;
  proj_workers = pw;
  deadline = d;
  deletion_status = ds;
}

// copy constructor
Project(const Project& p) {
  this->name = p.name;
  this->objective = p.objective;
  this->prod_customer = p.prod_customer;
  this->to_do = p.to_do;
  this->doing = p.doing;
  this->done = p.done;
  this->proj_workers = p.proj_workers;
  this->deadline = p.deadline;
  this->deletion_status = p.deletion_status;
}

// copy assignment
Project& operator=(const Project& p);

// move assignment
Project& operator=(Project&& p);

// destructor
~Project() {
  to_do.clear();
  doing.clear();
  done.clear();
  proj_workers.clear();
}

// move constructor
Project(Project&& p) {
  this->name = p.name;
  this->objective = p.objective;
  this->prod_customer = p.prod_customer;
  
  this->to_do = p.to_do;
  p.to_do.clear();
  
  this->doing = p.doing;
  p.doing.clear();
  
  this->done = p.done;
  p.done.clear();

  this->proj_workers = p.proj_workers;
  p.proj_workers.clear();

  this->deadline = p.deadline;
  this->deletion_status = p.deletion_status;
}



// gets the name of this Project
string get_name();

// gets the objective of this Project
string get_objective();

// gets product customer of this Project
string get_prod_customer();

// gets list of Tasks marked as 'to-do'
vector<Task> get_to_do();

// gets list of Tasks marked as 'doing'
vector<Task> get_doing();

// gets list of Tasks marked as 'done'
vector<Task> get_done();

// gets list of UserProfiles working on this Project
vector<UserProfile> get_proj_workers();

// gets the deadline of the Project
string get_deadline();

// gets the deletion status of this Project
bool get_deletion_status();


// updates the name of this Project
void update_name(UserProfile u, string new_name);

// updates the objective of this Project
void update_objective(UserProfile u, string new_objective);

// sets product customer of this Project
void set_prod_customer(UserProfile u, string s);

// sets list of Tasks marked as 'to-do'
void set_to_do(UserProfile u, vector<Task> vt);

// sets list of Tasks marked as 'doing'
void set_doing(UserProfile u, vector<Task> vt);

// sets list of Tasks marked as 'done'
void set_done(UserProfile u, vector<Task> vt);

// sets list of UserProfiles working on this Project
void set_proj_workers(UserProfile u, vector<UserProfile> pw);

// sets the deadline of the Project
void set_deadline(string s);

// sets the deletion status of this Project
void set_deletion_status(bool b);

// invites the collaborator of the Project if the inviter is a Project Manager
void invite_collaborator(UserProfile inviter, UserProfile invitee);

// adds a new lead to this Project if the inviter is a Project Manager
void add_lead(UserProfile inviter, UserProfile invitee);

// adds a task to this Project
void add_task(string task_type, int task_id, UserProfile user_creator, vector<UserProfile> assignees, int priority, string created_date, string due_date, int etc, string description, string comments, string status, bool deletion_status);

// deletes a Task in this Project
void delete_task(UserProfile deleter,Task t);

// updates a Task in this Project
void update_task(UserProfile u, Task t, string task_type, int task_id, UserProfile user_creator, vector<UserProfile> assignee, int priority, string created_date, string due_date, int etc, string description,string comments,string status, bool deletion_status);

// removes a member from this Project
void remove_member(UserProfile deleting, UserProfile person_deleted);

//moves task to a different status
void move_task(UserProfile manager, Task t);

//overload extraction operator
friend ostream &operator<<(ostream &ost, Project &pr);

};
