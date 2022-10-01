/*
 Leah Methratta
6/24/22
CS 3520, 2022
kanbanBoard.hpp file - Final Project
*/
#pragma once
#include <iostream>
#include "userProfile.hpp"
#include "task.hpp"
#include "project.hpp"
using namespace std;

class Task;
class UserProfile;


class KanbanBoard
{
private:

UserProfile *current_user; 
Project *current_project;

public:

KanbanBoard() {
  current_user = NULL;
  current_project = NULL;
}

// default constructor
KanbanBoard(UserProfile *u, Project *p) { 
  current_user = u;
  current_project = p;
}

// copy constructor
KanbanBoard(const KanbanBoard& kb) {
  this->current_user = kb.current_user;
  this->current_project = kb.current_project;
}

// copy assignment
KanbanBoard& operator=(const KanbanBoard& kb);

// move assignment
KanbanBoard& operator=(KanbanBoard&& p);

// destructor
~KanbanBoard() {
  this->current_user->get_tasks_assigned().clear();
  this->current_project->get_to_do().clear();
  this->current_project->get_doing().clear();
  this->current_project->get_done().clear();
}

// move constructor
KanbanBoard(KanbanBoard&& kb) {
  this->current_user = kb.current_user;
  //kb.current_user->get_tasks_assigned.clear();
  this->current_project = kb.current_project;
  kb.current_project->get_to_do().clear();
  kb.current_project->get_doing().clear();
  kb.current_project->get_done().clear();
}


// prints a list of the different tasks in this KanbanBoard
void print_tasks_list();

// gets the most recent version of this KanbanBoard
void get_recent_version(string proj_file);

// saves the current project 
void save_project(string proj_file);

//gets the current UserProfile in this KanbanBoard
UserProfile get_current_user();

// gets the current Project in this KanbanBoard
Project get_current_project();  

// sets the inputted Project in this KanbanBoard
void set_current_project(Project p);

// sets the inputted UserProfile in this KanbanBoard
void set_current_user(UserProfile u);
    
};
