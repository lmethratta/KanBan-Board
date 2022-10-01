/*
Leah Methratta
6/24/22
CS 3520, 2022
kanbanBoard.cpp file - Final Project
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "kanbanBoard.hpp"

// copy assignment
KanbanBoard& KanbanBoard::operator=(const KanbanBoard& kb) {
  if(this != &kb) {
    delete [] this -> current_user;
    delete [] this -> current_project;  
  }

  this->current_user = kb.current_user;
  this->current_project = kb.current_project;

  return *this;  
}

// move assignment
KanbanBoard& KanbanBoard::operator=(KanbanBoard&& kb) {
  if(this != &kb) {
    delete [] this -> current_user;
    delete [] this -> current_project;  
  }

  this->current_user = kb.current_user;
  this->current_project = kb.current_project;

  return *this;
}

// prints a list of the different tasks in this KanbanBoard
void KanbanBoard::print_tasks_list() {
  
  for(auto val: current_project->get_to_do()) {
    cout<<val<<endl;
  }
  
  for(auto val: current_project->get_doing()) {
    cout<<val<<endl;
  } 

  for(auto val: current_project->get_done()) {
    cout<<val<<endl;
  }
  
}

// gets the most recent version of this KanbanBoard
void KanbanBoard::get_recent_version(string proj_file) {
  ifstream read_file(proj_file);
  string proj_details;
  string line;

  if(!read_file) {
    cout<<"Can't read the file.";
  }

  else {

    while(getline(read_file, line)) {
      stringstream ss(line);
      proj_details+= line+ "\n";
    }

    cout<<proj_details;
    
  }
  
}

// saves the current project to a file
void KanbanBoard::save_project(string proj_file) {
  
 
  string proj_details;
  
  ofstream file(proj_file);
  if(!file) {
    cout<<"Can't open the Passenger List File.";
  }

  else {
    proj_details+= "PROJECT NAME: " + current_project->get_name() + "\n";
    proj_details+="OBJECTIVE: " + current_project->get_objective() + "\n";

    proj_details+= "PRODUCT CUSTOMER: " + current_project->get_prod_customer() + "\n";

    proj_details+= "TO-DO: \n";
    for(auto val: current_project->get_to_do()) {
      proj_details+= to_string(val.get_task_id()) + ", " + val.get_description() + ", " + val.get_status() + "\n";
    }

    proj_details+= "DOING: \n";
    for(auto val: current_project->get_doing()) {
       proj_details+= to_string(val.get_task_id()) + ", " + val.get_description() + ", " + val.get_status() + "\n";
    }

    proj_details+= "DONE: \n";
    for(auto val: current_project->get_done()) {
       proj_details+= to_string(val.get_task_id()) + ", " + val.get_description() + ", " + val.get_status() + "\n";
    }

    proj_details+= "DEADLINE: " + current_project-> get_deadline() + "\n";

    proj_details+= "DELETION STATUS: " + to_string(current_project->get_deletion_status()) + "\n";

    file<<proj_details<<endl;
  
  }

}

//gets the current UserProfile in this KanbanBoard
UserProfile KanbanBoard::get_current_user() {
  return *current_user;
  
}

// gets the current Project in this KanbanBoard
Project KanbanBoard::get_current_project() {
  return *current_project;
  
}

// sets the inputted Project in this KanbanBoard
void KanbanBoard::set_current_project(Project p) {
  current_project = &p;
}

// sets the inputted UserProfile in this KanbanBoard
void KanbanBoard::set_current_user(UserProfile u) {
  current_user = &u;
}
