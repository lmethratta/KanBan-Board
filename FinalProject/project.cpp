/*
Leah Methratta
6/24/22
CS 3520, 2022
project.cpp file - Final Project
*/

#include <iostream>
#include <ctime>
#include "project.hpp"

using namespace std;


// copy assignment
Project& Project::operator=(const Project& p) {
  if(this != &p) {
    to_do.clear();
    doing.clear();
    done.clear();
    proj_workers.clear();
  }

  this->name = p.name;
  this->objective = p.objective;
  this->prod_customer = p.prod_customer;
  this->to_do = p.to_do;
  this->doing = p.doing;
  this->done = p.done;
  this->proj_workers = p.proj_workers;
  this->deadline = p.deadline;
  this->deletion_status = p.deletion_status;

  return *this;
  
}

// move assignment
Project& Project::operator=(Project&& p) {
  if(this != &p) {
    to_do.clear();
    doing.clear();
    done.clear();
    proj_workers.clear();
  }

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

  return *this;
}

// gets the name of this Project
string Project::get_name() {
  return name;
}

// gets the objective of this Project
string Project::get_objective() {
  return objective;
}

// gets product customer of this Project
string Project::get_prod_customer() {
  return prod_customer;
}

// gets list of Tasks marked as 'to-do'
vector<Task> Project::get_to_do() {
  return to_do;
}

// gets list of Tasks marked as 'doing'
vector<Task> Project::get_doing() {
  return doing;
}

// gets list of Tasks marked as 'done'
vector<Task> Project::get_done() {
  return done;
}

// gets list of UserProfiles working on this Project
vector<UserProfile> Project::get_proj_workers() {
  return proj_workers;
}

// gets the deadline of this Project
string Project::get_deadline() {
  return deadline;
}

// gets the deletion status of this Project
bool Project::get_deletion_status() {
  return deletion_status;
}

// updates the name of this Project
void Project::update_name(UserProfile u, string new_name) {
  if(u.get_role().compare("PM") == 0) {
     name = new_name;
  }

  else {
    cout<<"You are not authorized to update the name.";
  }
 
}

// updates the objective of this Project
void Project::update_objective(UserProfile u, string new_objective) {
  if(u.get_role().compare("PM") == 0) {
     objective = new_objective;
  }

  else {
    cout<<"You are not authorized to update the objective.";
  }
  
}

// sets the name of the Project
void Project::set_prod_customer(UserProfile u, string s){
  if(u.get_role().compare("PM") == 0) {
     prod_customer = s;
  }

  else {
    cout<<"You are not authorized to update the product customer.";
  }
  
}

//sets the list of "to-do" Tasks
void Project:: set_to_do(UserProfile u, vector<Task> vt){
  if(u.get_role().compare("PM") == 0) {
     to_do = vt;
  }

  else {
    cout<<"You are not authorized to update the 'to-do' tasks.";
  }

}

//sets the Tasks are being done
void Project:: set_doing(UserProfile u, vector<Task> vt){
   if(u.get_role().compare("PM") == 0) {
     doing = vt;
  }

  else {
    cout<<"You are not authorized to update the 'doing' tasks.";
  }
  
}

//sets the Tasks that are complete
void Project:: set_done(UserProfile u, vector<Task> vt){
   if(u.get_role().compare("PM") == 0) {
     done = vt;
  }

  else {
    cout<<"You are not authorized to update the 'done' tasks.";
  }

}

void Project::set_proj_workers(UserProfile u, vector<UserProfile> pw) {
   if(u.get_role().compare("PM") == 0) {
     proj_workers = pw;
  }

  else {
    cout<<"You are not authorized to update the list of project workers.";
  }
}

//sets the deadline of this Project
void Project:: set_deadline(string s){
  deadline = s;
}

//sets deletion status of this Project
void Project:: set_deletion_status(bool b){
  deletion_status = b;
}

// invites the collaborator to this Project
void Project::invite_collaborator(UserProfile inviter, UserProfile invitee) {
  if(inviter.get_role().compare("PM") == 0) {
    invitee.set_role("Dev");
    proj_workers.push_back(invitee);
    
    
  }
  else if(inviter.get_role().compare("Dev") == 0) {
    cout<<"Not able to invite a collaborator.";
  }
}

// adds a new lead to this Project
void Project::add_lead(UserProfile inviter, UserProfile invitee) {
  if(inviter.get_role().compare("PM") == 0) {
    invitee.set_role("PM");
    proj_workers.push_back(invitee);
  }
}

// adds a task to this Project
void Project::add_task(string task_type, int task_id, UserProfile user_creator, vector<UserProfile> assignees, int priority, string created_date, string due_date, int etc, string description, string comments, string status, bool deletion_status) {
  Task a;
  a.set_task_type(task_type);
  a.set_task_id(task_id);
  a.set_user_creator(user_creator);
  a.set_assignee(assignees);
  a.set_priority(priority);
  a.set_created_date(created_date);
  a.set_due_date(due_date);
  a.set_etc(etc);
  a.set_description(description);
  a.update_comments(comments);
  a.set_status(status);
  a.set_deletion_status(deletion_status);
  
  to_do.push_back(a);
  
}

// deletes a Task in this Project
void Project::delete_task(UserProfile deleter,Task t) {
  if(t.get_deletion_status() == false && (deleter.get_role().compare("PM") == 0 || (t.get_user_creator()->get_username().compare(deleter.get_username()) ==0))) {
    t.set_deletion_status(true);

    // deletes task if it is in to-do
    for(int i = 0; i< to_do.size(); i++) {
      if(t.get_task_id() == to_do[i].get_task_id()) {
        to_do.erase(to_do.begin() + i);
        break;
      }
    }

    // deletes task if it is in doing
    for(int i = 0; i< doing.size(); i++) {
      if(t.get_task_id() == doing[i].get_task_id()) {
        doing.erase(doing.begin() + i);
        break;
      }
    }

    // deletes task if it is in done
    for(int i = 0; i< done.size(); i++) {
      if(t.get_task_id() == done[i].get_task_id()) {
        done.erase(done.begin() + i);
        break;
      }
    }

    // removes this task from list of people assigned to this Task
    for(auto user: t.get_assignee()) {
      for(int i = 0; i<user.get_tasks_assigned().size();i++) {
        if(t.get_task_id() == user.get_tasks_assigned()[i].get_task_id()) {
          user.get_tasks_assigned().erase(user.get_tasks_assigned().begin() + i);
          break;
        }
      }
    }
    
  }

  else {
    cout<<"Task deletion is not possible.";
  }
}

// updates a Task in this Project
void Project::update_task(UserProfile u, Task t, string task_type, int task_id, UserProfile user_creator, vector<UserProfile> assignee, int priority, string created_date, string due_date, int etc, string description,string comments,string status, bool deletion_status) {
  if(u.get_role().compare("PM") == 0) {
    t.set_task_type(task_type);
    t.set_task_id(task_id);
    t.set_user_creator(user_creator);
    t.set_assignee(assignee);
    t.set_priority(priority);
    t.set_created_date(created_date);
    t.set_due_date(due_date);
    t.set_etc(etc);
    t.set_description(description);
    t.update_comments(comments);
    t.set_status(status);
    t.set_deletion_status(deletion_status);
  }

  else if((u.get_username().compare(t.get_user_creator()->get_username()) ==0)
          && 
          u.get_role().compare("Dev") == 0) {
    t.update_comments(comments);
    t.set_status(status);
    t.set_description(description);
  }

  else {
    cout<<"Not authorized to update the task.";
  }
  
}

// removes a member from this Project
void Project::remove_member(UserProfile deleting, UserProfile person_deleted) {
  if(deleting.get_role().compare("PM") == 0) {
    for(int i = 0; i<proj_workers.size(); i++) {
      if(proj_workers[i].get_username().compare(person_deleted.get_username()) == 0) {
        proj_workers.erase(proj_workers.begin() + i);
        break;
      }
    }
    person_deleted.get_tasks_assigned().clear();
  }
  else {
    cout<<"You are not authorized to remove this member.";
  }
}

//updates the status of its task
void Project::move_task(UserProfile manager, Task t) {
  if(manager.get_role().compare("PM") == 0){
    if(t.get_status().compare("Doing")){
      for(int i = 0; i<to_do.size(); i++){
        if(to_do[i].get_task_id() == t.get_task_id()){
          to_do.erase(to_do.begin() + i);
          break;
        }
      }
      doing.push_back(t);
    }
      if(t.get_status().compare("Done")){
        for(int i = 0; i<doing.size(); i++){
          if(to_do[i].get_task_id() == t.get_task_id()){
            to_do.erase(doing.begin() + i);
            break;
        }
      }
      done.push_back(t);
    }
  }
  }



//overload extraction operator
inline ostream &operator<<(ostream &ost, Project &pr){
  ost<< endl;
  ost<< "Objective: "<<pr.get_objective() << endl;
  ost<< "Product Owner/Customer: "<<pr.get_prod_customer()<< endl;
  ost<< " Tasks to do: " << endl;
  for(auto task:  pr.get_to_do()) {
    ost<< task.get_task_id() << ": " << task.get_description() << endl;
  }
  ost<< " Tasks being done: "<< endl;
  for(auto task:  pr.get_doing()) {
    ost<< task.get_task_id() << ": " << task.get_description() << endl;
  }
  ost<< " Tasks done: "<< endl;
  for(auto task:  pr.get_done()) {
    ost<< task.get_task_id() << ": " << task.get_description() << endl;
  }
  ost<< "Project Workers: ";
  for(auto worker: pr.get_proj_workers()) {
    ost<<worker.get_username ()<<", " << endl;
  }
  ost<< pr.get_deadline() << endl;
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
  if (pr.get_deadline().substr(4,6).compare("Jan")){   
    ta_month = 1; 
  }
  else if(pr.get_deadline().substr(4,6).compare("Feb")){
    ta_month = 2;
  }
  else if(pr.get_deadline().substr(4,6).compare("Mar")){
    ta_month = 3;
  }
  else if(pr.get_deadline().substr(4,6).compare("Apr")){
    ta_month = 4;
  }
  else if(pr.get_deadline().substr(4,6).compare("May")){
    ta_month = 5;
  }
  else if(pr.get_deadline().substr(4,6).compare("Jun")){
    ta_month = 6;
  }
  else if(pr.get_deadline().substr(4,6).compare("Jul")){
    ta_month = 7;
  }
  else if(pr.get_deadline().substr(4,6).compare("Aug")){
    ta_month = 8;
  }
  else if(pr.get_deadline().substr(4,6).compare("Sep")){
    ta_month = 9;
  }
  else if(pr.get_deadline().substr(4,6).compare("Oct")){
    ta_month = 10;
  }
    else if(pr.get_deadline().substr(4,6).compare("Nov")){
    ta_month = 11;
  }
    else if(pr.get_deadline().substr(4,6).compare("Dec")){
    ta_month = 12;
  }

  int months_left;
  months_left = ta_month - cd_month;

  int days_left;
  days_left = stoi(pr.get_deadline().substr(24, 25)) - stoi(currenttime.substr(24, 25));
  
  ost<< "Days Left: "<<months_left<<"month(s) and "<< days_left << "day(s) left to complete task." << endl;
  return ost;
  
}
