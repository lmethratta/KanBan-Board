/*
Leah Methratta
A program that works as a system  that  mimics  Kanban  Board.
6/24/22
CS 3520, 2022
main.hpp file - Final Project
*/

#pragma once
#include <iostream>
using namespace std;

#include "kanbanBoard.hpp"
#include "userProfile.hpp"





// shows the project menu for the KanbanBoard's current project
void proj_menu(KanbanBoard k, string proj_file) {
  cout<<"User : "<<k.get_current_user().get_username()<<endl;
  cout<<"Project Details: "<<k.get_current_project().get_name()<<endl;
  bool running = true;
  while(running == true) {
    int menu_option_1;
    int menu_option_2;


    cout<<"Please type the number of the menu option you would like to choose, listed below: "<<endl;
    cout<<"1.Task-Related"<<endl;
    cout<<"2. Project-Related"<<endl;
    cout<<"3. Quit the program."<<endl;

    cin>> menu_option_1;

    if(menu_option_1 == 1) {

      cout<<"Please type the number of the menu option you would like to choose, listed below: " << endl;
      cout<<"1. View current status of an assigned task."<<endl;
      cout<<"2. View list of tasks assigned to you and its details."<<endl;
      cout<<"3. Add task to project"<<endl;
      cout<<"4. Assign a task to a specific user"<<endl;
      cout<<"5. View an individual task."<<endl;
      cout<<"6. Update properties of an existing task."<<endl;
      cout<<"7. Update status of task."<<endl;
      cout<<"8. Delete a task"<<endl;

      cin>>menu_option_2;

      int task_number;

      // view current status of an assigned task
      if(menu_option_2 == 1) {

        int count = 1;
        if(k.get_current_user().get_tasks_assigned().size() > 0) {
          for(auto val: k.get_current_user().get_tasks_assigned()) {
          cout<<count<<"."<<val.get_task_id()<<", "<< val.get_description()<<endl;
        }
          cout<<"Please type the number of the task you would like to update.";
          cin>> task_number;

          cout<<k.get_current_user().get_tasks_assigned()[task_number - 1]<<endl;

          cout<<endl;
      }
        

       

      }

      // view list of tasks assigned and its details
      else if(menu_option_2 == 2) {
        if(k.get_current_user().get_tasks_assigned().size() > 0) {
          for(auto val:k.get_current_user().get_tasks_assigned()) {
            cout<<val<<endl;
          }
          cout<<endl;
        }
       
        
      }

      // add task to project
      else if(menu_option_2 == 3) {
        string task_type;
        int task_id;
        int priority;
        string creation_date;
        string due_date;
        int toc;
        string description;
        string comments;

        cout<<"Please input the details of the task.";


        Task new_task;

        cout<<"Task Type: ";
        cin>> task_type;

        cout<<"Task Id: ";
        cin>> task_id;

        if(k.get_current_project().get_to_do().size() > 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            if(task_id == val.get_task_id()) {
              cout<<"This task id is already taken. You will be returned to the main menu.";
              return;
            }
          }
        }
       

        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val: k.get_current_project().get_doing()) {
            if(task_id == val.get_task_id()) {
              cout<<"This task id is already taken. You will be returned to the main menu.";
              return;
              break;
            }
          }
        }
        

        if(k.get_current_project().get_done().size() > 0) {
          for(auto val: k.get_current_project().get_done()) {
            if(task_id == val.get_task_id()) {
              cout<<"This task id is already taken. You will be returned to the main menu.";
              return;
              break;
            }
          }
       
        }

        cout<<"Priority value (on a scale of 1 to 5): ";
        cin>> priority;

        cout<<"Creation Date formatted Mon Date, YYYY(i.e. Jun 30, 2022)";
        getline(cin,creation_date);
        cin.ignore(100, '\n'); 

         cout<<"Due Date formatted Mon Date, YYYY(i.e. Jun 30, 2022)";
        getline(cin,due_date);
        cin.ignore(100, '\n'); 

        cout<<"Estimated Time of Completion (in weeks): ";
        cin>> toc;

        cout<< "Description of Task: ";
        getline(cin, description);
        cin.ignore(100, '\n'); 

        cout<<"Comments for Task: ";
        getline(cin, comments);
        cin.ignore(100, '\n'); 

        vector<UserProfile> people;


        char y_or_n;
        cout<<"Would you like to assign this task to anybody? Type 'Y' for yes and 'N' for no: ";
        cin>> y_or_n;
        if(y_or_n == 'Y') {
          int num_people;
          
          int c = 0;
          cout<<"Please input the number of people you would like to assign this task to.";
          cin>>num_people;
          cout<<"Please input each username, followed by hitting the enter key.";
          while(c<num_people) {
            string user;
            cin>>user;
            if(k.get_current_project().get_proj_workers().size() > 0) {
              for(auto val: k.get_current_project().get_proj_workers()) {
                if(val.get_username().compare(user) == 0) {
                  people.push_back(val);
                  break;
                }
                else {
                  cout<<"User is not working on this project.";
                }
              }
            }
            
            
          }
          k.get_current_project().add_task(task_type, task_id,k.get_current_user(), people, priority,creation_date,due_date,toc,description,comments,"Open",false);

        }

        else if(y_or_n == 'N') {
         k.get_current_project().add_task(task_type, task_id,k.get_current_user(), {}, priority,creation_date,due_date,toc,description,comments,"Open",false);
          cout<<"Your task has been added. You will return to the main menu.";
          
        }
        
       
      }

      // assign task to specific user
      else if(menu_option_2 == 4) {
        string user;
        int task_num;
        Task t;
        string decision;

        cout<<"Which task would you like to assign to either another user or yourself. Please type the task id number";

        if(k.get_current_project().get_to_do().size() > 0) {
          for(auto val:k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
        

        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }

        cin>> task_num;

        if(k.get_current_project().get_done().size() > 0) {
          for(auto val:k.get_current_project().get_to_do()) {
            if(task_num == val.get_task_id()) {
              t = val;
              break;
            }
          }
        }
        
        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val:k.get_current_project().get_doing()) {
            if(task_num == val.get_task_id()) {
              t = val;
              break;
            }
          }
        }

        
        cout<<"Would you like to assign this task to another user or to yourself? Please type 'other' for another user and 'yourself' for yourself.";
        cin>>decision;

        if(decision.compare("other") == 0) {
          cout<<"Please type the username of the user you would like to assign the task to.";
          cin>>user;

          if(k.get_current_project().get_proj_workers().size() > 0) {
            for(auto val: k.get_current_project().get_proj_workers()) {
              if(val.get_username().compare(user) == 0) {
                k.get_current_user().assign_task_to_user(val,t);
                break;
              }
            }
          }
          
          
        }

        else if(decision.compare("yourself") == 0) {
          k.get_current_user().assign_task_to_themself(t);
        }

        else {
          cout<<"Not a valid option. You will be returned to the main menu.";
        }
        
      }

      // view an individual task
      else if(menu_option_2 == 5) {

        int task_id;
        cout<<"Please type the task id of the task you would like to view, listed below.";

        if(k.get_current_project().get_to_do().size() > 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }

        }

        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
        

        if(k.get_current_project().get_done().size() == 0) {
          for(auto val: k.get_current_project().get_done()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }  
        }
        

        cin>> task_id;

        if(k.get_current_project().get_to_do().size() > 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            if(task_id == val.get_task_id()) {
              cout<<val.get_task_id()<<", "<<val.get_description();
              break;
            }
          }
        }
       

        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val: k.get_current_project().get_doing()) {
            if(task_id == val.get_task_id()) {
              cout<<val.get_task_id()<<", "<<val.get_description();
              break;
            }
          }
        }

        if(k.get_current_project().get_done().size() > 0) {
          for(auto val: k.get_current_project().get_done()) {
            if(task_id == val.get_task_id()) {
              cout<<val.get_task_id()<<", "<<val.get_description();
              break;
            }
          }
        }
        

    
      }

      // update task
      else if(menu_option_2 == 6) {
        int task_id;
        string category;
        cout<<"Please type the id number of the task you would like to update and what category it is in(to-do, doing, done): ";

        if(k.get_current_project().get_to_do().size() == 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }

        }

        if(k.get_current_project().get_doing().size() > 0) {
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }

        if(k.get_current_project().get_done().size() > 0) {
          for(auto val: k.get_current_project().get_done()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
       
        
        cout<<"Task ID: ";
        cin>> task_id;

        cout<<"Category: ";
        cin>> category;

        string task_type;
        int priority;
        string creation_date;
        string due_date;
        int toc;
        string description;
        string comments;
        
        cout<<"Please input the updated details of the task. If it is the same, please just input the value as it was before: ";
        cout<<"Task Type: ";
        cin>> task_type;

        cout<<"Priority value (on a scale of 1 to 5): ";
        cin>> priority;

        cout<<"Creation Date formatted Mon Date, YYYY(i.e. Jun 30, 2022)";
        getline(cin,creation_date);

         cout<<"Due Date formatted Mon Date, YYYY(i.e. Jun 30, 2022)";
        getline(cin,due_date);

        cout<<"Estimated Time of Completion (in weeks): ";
        cin>> toc;

        cout<< "Description of Task: ";
        getline(cin, description);

        cout<<"Comments for Task: ";
        getline(cin, comments);

        if(category.compare("To-Do") == 0) {
          if(k.get_current_project().get_to_do().size() > 0) {
            for(auto val: k.get_current_project().get_to_do()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().update_task(k.get_current_user(),val,task_type,task_id, *val.get_user_creator(),
            val.get_assignee(),priority,creation_date,due_date,toc,description,comments,val.get_status(),val.get_deletion_status());
                cout<<"Your task has been updated.";
          }
          

            }
            
          }
        }
        if(category.compare("Doing") == 0) {
          if(k.get_current_project().get_doing().size() > 0) {
            for(auto val: k.get_current_project().get_doing()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().update_task(k.get_current_user(),val,task_type,task_id, *val.get_user_creator(),
            val.get_assignee(),priority,creation_date,due_date,toc,description,comments,val.get_status(),val.get_deletion_status());
                cout<<"Your task has been updated.";

            }
          }
          
            
          }
        }

        if(category.compare("Done") == 0) {
          if(k.get_current_project().get_done().size() > 0) {
            for(auto val: k.get_current_project().get_done()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().update_task(k.get_current_user(),val,task_type,task_id, *val.get_user_creator(),
            val.get_assignee(),priority,creation_date,due_date,toc,description,comments,val.get_status(),val.get_deletion_status());
                cout<<"Your task has been updated.";
                

            }
          }
         
            
          }
        }
      
        
      }

      // update status of task
      else if(menu_option_2 == 7) {
        int task_id;
        string category;
        string status;
        cout<<"Please type the id number of the task which status you would like to update and what category it is in(To-Do, Doing, Done). In addition, please type in the new status of the task(open, in progress, blocked, done, or overdue): ";

        

        if(k.get_current_project().get_to_do().size() == 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }

        if(k.get_current_project().get_doing().size() == 0) {
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }

        if(k.get_current_project().get_done().size() == 0) {
          for(auto val: k.get_current_project().get_done()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
       

        cout<<"Task ID: ";
        cin>> task_id;

        cout<<"Category: ";
        cin>> category;

        cout<<"Updated Status: ";
        cin>> status;

        if(category.compare("To-Do") == 0) {
          if(k.get_current_project().get_to_do().size() == 0) {
            for(auto val: k.get_current_project().get_to_do()) {
              if(task_id == val.get_task_id()) {
                val.update_status(status);
                break;
              }
            }
          }
          
        }

        else if(category.compare("Doing") == 0) {
          if(k.get_current_project().get_doing().size() == 0) {
            for(auto val: k.get_current_project().get_doing()) {
              if(task_id == val.get_task_id()) {
                val.update_status(status);
                break;
              }
            }
          }
        }

        else if(category.compare("Done") == 0) {
          if(k.get_current_project().get_done().size() == 0) {
            for(auto val: k.get_current_project().get_done()) {
              if(task_id == val.get_task_id()) {
                val.update_status(status);
                break;
              }
            }
          }
         
        }
 
      }

      
        

      else if(menu_option_2 == 8) {
        int task_id;
        string category;
        cout<<"Please type the id number of the status of the task you would like to delete and what category it is in(To-Do, Doing, Done): ";

        if(k.get_current_project().get_to_do().size() == 0) {
          for(auto val: k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
        

        if(k.get_current_project().get_doing().size() == 0) {
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }
        }
        

        if(k.get_current_project().get_done().size() == 0) {
          for(auto val: k.get_current_project().get_done()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
          }

        }
        
        cout<<"Task ID: ";
        cin>> task_id;

        cout<<"Category: ";
        cin>> category;

        if(category.compare("To-Do") == 0) {
          if(k.get_current_project().get_to_do().size() == 0) {
            for(auto val: k.get_current_project().get_to_do()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().delete_task(k.get_current_user(), val);
                break;
              }
            }
          }
          
        }

        else if(category.compare("Doing") == 0) {
          if(k.get_current_project().get_doing().size() == 0) {
            for(auto val: k.get_current_project().get_doing()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().delete_task(k.get_current_user(), val);
                break;
              }
            }  
          }
          
        }

        else if(category.compare("Done") == 0) {
          if(k.get_current_project().get_done().size() == 0) {
            for(auto val: k.get_current_project().get_done()) {
              if(task_id == val.get_task_id()) {
                k.get_current_project().delete_task(k.get_current_user(), val);
              
                break;
              }
            }
          }
    
        }

        else {
          cout<<"Invalid category. You will be returning to the main menu.";
        }
        
      }

      
      
    }

    // project-related items
    else if(menu_option_1 == 2) {
      cout<<"1. View a report of the current status and details of the project."<<endl;
      cout<<"2. View all properties of the project (name, description, collaborators)"<<endl;
      cout<<"3. Update properties of an project"<<endl;
      cout<<"4. Add a collaborator to the project"<<endl;
      cout<<"5. Delete member from project."<<endl;
      cout<<"6. Delete project" <<endl;
      cout<<"7. Save project"<<endl;

      cin>> menu_option_2;

      // view a report of the current status and details of the project
      if(menu_option_2 == 1) {

        if(k.get_current_project().get_to_do().size() > 0) {
          cout<<"TO-DO TASK COUNT: "<<k.get_current_project().get_to_do().size()<<endl;
          for(auto val: k.get_current_project().get_to_do()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<", "<< val.get_status()<<endl;
          }
        }

         if(k.get_current_project().get_doing().size() > 0) {
          cout<<"TO-DO TASK COUNT: "<<k.get_current_project().get_doing().size()<<endl;
          for(auto val: k.get_current_project().get_doing()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<", "<< val.get_status()<<endl;
          }
        }

         if(k.get_current_project().get_done().size() > 0) {
          cout<<"TO-DO TASK COUNT: "<<k.get_current_project().get_done().size()<<endl;
          for(auto val: k.get_current_project().get_done()) {
            cout<<val.get_task_id()<<", "<<val.get_description()<<", "<< val.get_status()<<endl;
          }
        }
      }

      // gets the most recent version of the project
      else if(menu_option_2 == 2) {
        k.get_recent_version(proj_file);
      }

      // update aspects of a project
      else if(menu_option_2 == 3){
        int category;
        cout<<"Please chooose what you would like to update" << endl;
        cout<<"1. Update Project Name." << endl;
        cout<<"2. Change Deadline."<< endl;
        cout<<"3. Change Objective."<< endl;
        cout<<"4. Move Task."<< endl;
        cout<<"5. Delete Task."<< endl;   

        cin>>category; 
        

        // update project name
        if (category == 1){
          string new_name;
          cout<<"New Name... " << endl;
          getline(cin, new_name);
          cin.ignore(100, '\n'); 
          k.get_current_project().update_name(k.get_current_user(),  new_name);
        }
        // change deadline
        else if (category == 2) {
          
          string dl;
          cout<<"New Deadline (Ex. Mon Jun 27, 2022)..." << endl;
          getline(cin, dl);
          cin.ignore(100, '\n'); 
          k.get_current_user().change_deadline(k.get_current_project(), dl);
        }
        // change objective
        else if (category == 3){
          string obj;
          cout<<"Update Objective... " << endl;
          getline(cin, obj);
          cin.ignore(100, '\n'); 
          k.get_current_project().update_objective(k.get_current_user(), obj);
        }

        // move task
        else if(category == 4) {

          int task_id;
          cout<<"Please type the Task ID of the task you would like to update the status of: ";

          if(k.get_current_project().get_to_do().size() > 0) {
            for(auto val: k.get_current_project().get_to_do()) {
              cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
            }
          }
          

          if(k.get_current_project().get_doing().size() > 0) {
            for(auto val: k.get_current_project().get_doing()) {
              cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
            }
          }
         

          if(k.get_current_project().get_done().size() > 0) {
            for(auto val: k.get_current_project().get_done()) {
              cout<<val.get_task_id()<<", "<<val.get_description()<<endl;
            }
          }
          

          cin>> task_id;

          if(k.get_current_project().get_to_do().size() > 0) {
            for(auto val: k.get_current_project().get_to_do()) {
             if(task_id == val.get_task_id()) {
               k.get_current_project().move_task(k.get_current_user(),val);
               break;
             }
          }  
           
            
          }

          if(k.get_current_project().get_doing().size() > 0) {
            for(auto val: k.get_current_project().get_doing()) {
              k.get_current_project().move_task(k.get_current_user(),val);
              break;
            }
          }
         

          if(k.get_current_project().get_done().size() > 0) {
            for(auto val: k.get_current_project().get_done()) {
              k.get_current_project().move_task(k.get_current_user(),val);
              break;
            }
          }
          


      } 

      // inviting an user
      else if(menu_option_2 == 4){
        cout<< "Enter the username of the invitee" << endl;
        string un;
        cin >> un;
        if(k.get_current_project().get_proj_workers().size() > 0) {
          for(auto user: k.get_current_project().get_proj_workers()){
            if(un.compare(user.get_username())) {
              k.get_current_project().invite_collaborator(k.get_current_user(), user);
              break;
            }
          }  
        }
        
     }

    else if(menu_option_2 == 5){
      cout<<"Please type 'co-lead' if you want to add a co-lead and 'collaborator' if you want to add a collaborator: ";
      string c;
      cin>> c;

      if(c.compare("co-lead") == 0) {
        cout<< "Enter the username of the user" << endl;
        string un;
        cin >> un;
        if(k.get_current_project().get_proj_workers().size() > 0) {
          for(auto user: k.get_current_project().get_proj_workers()) {
            if(user.get_username().compare(un) == 0) {
              k.get_current_project().add_lead(k.get_current_user(),user);
              break;
            }
          }
        }
      }

      else if(c.compare("collaborator") == 0) {
        cout<< "Enter the username of the user" << endl;
        string un;
        cin >> un;
        if(k.get_current_project().get_proj_workers().size() > 0) {
          for(auto user: k.get_current_project().get_proj_workers()) {
            if(user.get_username().compare(un) == 0) {
              k.get_current_project().add_lead(k.get_current_user(),user);
              break;
            }
          }
        }
      }
      }
      
   
      
    }
        
    else if(menu_option_2 == 6){
      cout<< "Are you sure you want to delete project? (y/n)" <<endl;
      string in;
      cin>> in;
      if(in.compare("y")){
        k.get_current_user().delete_project(k.get_current_project());
      }
    }

    else if(menu_option_2 == 7) {
      k.save_project(proj_file);
      cout<<"Your project has been sucessfully saved.";
    } 
  
}

  

    else if(menu_option_1 == 3) {
        k.save_project(proj_file);
        running = false;
      
    }

    else {
      cout<<"Invalid option, please try again.";
    }
   
  }

  }


int main() {
  bool running = true;
  string p_name;
  string user_in;
  string pass;
  UserProfile u;

  // for project 1
  UserProfile pooja("Pooja","Swami","pswami","987654","PM",{});
  UserProfile kartik("Kartik", "Viswanathan", "karvis","123456","PM", {});
  
  Task create_seat_array;
  create_seat_array.set_description("Build");
  create_seat_array.set_task_id(1);
  create_seat_array.set_user_creator(pooja);
  create_seat_array.set_assignee({});
  create_seat_array.set_created_date("Mon Jun 27, 2022");
  create_seat_array.set_due_date("Fri Jul 1, 2022");
  create_seat_array.set_description("Creating a seat array");
  create_seat_array.update_comments("Use 9x8 array");
  create_seat_array.set_status("Open");
  create_seat_array.set_deletion_status(false);


  Task debug_seating_chart;
  debug_seating_chart.set_description("Debug");
  debug_seating_chart.set_task_id(2);
  debug_seating_chart.set_user_creator(kartik);
  debug_seating_chart.set_assignee({});
  debug_seating_chart.set_created_date("Mon Jun 27, 2022");
  debug_seating_chart.set_due_date("Fri Jul 1, 2022");
  debug_seating_chart.set_description("Debugging seat array");
  debug_seating_chart.update_comments("use GNU debugger and test it on Linux server");
  debug_seating_chart.set_status("Open");
  debug_seating_chart.set_deletion_status(false);
  
  UserProfile tim("Tim","Allen","tallen","456789","Dev",{debug_seating_chart});
  debug_seating_chart.get_assignee().push_back(tim);
  UserProfile john("John","Kim","jkim","57892","Dev",{debug_seating_chart});
  debug_seating_chart.get_assignee().push_back(john);
  UserProfile bob("Bob","Marley","bmarley","102938","Dev",{create_seat_array, debug_seating_chart});
  debug_seating_chart.get_assignee().push_back(bob);
  create_seat_array.get_assignee().push_back(bob);
  
  UserProfile carol("Carol","Baskin","cbaskin","92365","Dev",{create_seat_array});
  create_seat_array.get_assignee().push_back(carol);

   Project proj_1("Airplane", "Simulate booking of flight seat", "Delta",{create_seat_array,debug_seating_chart},{},{},{pooja,kartik,tim,john,bob,carol},"Tue Jun 28, 2022",false);



  // for project 2
  UserProfile tanvi("Tanvi","Rue","true","352749","PM",{});
  UserProfile chidima("Chidima","Alps","calps","203529","PM",{});
  UserProfile anushka("Anushka","Barto","abarto","394725","PM",{});

  Task build_grid;
  build_grid.set_description("Build");
  build_grid.set_task_id(4);
  build_grid.set_user_creator(tanvi);
  build_grid.set_assignee({});
  build_grid.set_created_date("Mon Jun 27, 2022");
  build_grid.set_due_date("Fri Jul 8, 2022");
  build_grid.set_description("Build grid for doodlebugs and ants");
  build_grid.update_comments("Use 100x100 grid");
  build_grid.set_status("Open");
  build_grid.set_deletion_status(false);  

  Task debug_program;
  debug_program.set_description("Build");
  debug_program.set_task_id(5);
  debug_program.set_user_creator(chidima);
  debug_program.set_assignee({});
  debug_program.set_created_date("Mon Jun 27, 2022");
  debug_program.set_due_date("Tues Jul 5, 2022");
  debug_program.set_description("Debugging doodlebug game");
  debug_program.update_comments("Test in Linux server and use debugger");
  debug_program.set_status("Open");
  debug_program.set_deletion_status(false);  
  

  UserProfile omar("Omar","Jasto","ojasto","548612","Dev",{build_grid});
  build_grid.get_assignee().push_back(omar);
  
  UserProfile hiba("Hiba","Sayan","hsayan","301863","Dev",{debug_program});
  debug_program.get_assignee().push_back(hiba);
  
  UserProfile juan("Juan","Carlos","jcarlos","142604","Dev",{build_grid,debug_program});
  build_grid.get_assignee().push_back(juan);
  debug_program.get_assignee().push_back(juan);
  
  UserProfile anusha("Anusha","Mato","amato","136924","Dev",{debug_program});
  debug_program.get_assignee().push_back(anusha);
  
  UserProfile abbey("Abbey","Garden","agarden","346129","Dev",{build_grid});
  build_grid.get_assignee().push_back(abbey);
  
  Project proj_2("Doodlebug", "Simulate Doodlebug game", "Marvel",{build_grid, debug_program},{},{},{tanvi, chidima, anushka, omar, hiba, juan, anusha, abbey},"7/28/2022",false);


  while(running) {

    // display the menu options
    int menu_option;
    cout<<"Please choose one of the following projects below. In order to select a project, please type in the name exactly as spelled, with appropriate casing. If you would like to quit the program, please type 'quit': "<<endl;
    cout<<"1."<<proj_1.get_name()<<endl;
    cout<<"2."<<proj_2.get_name()<<endl;
    cout<<"3."<<"Quit the program"<<endl;

    cin>>p_name;

    if(p_name.compare(proj_1.get_name()) == 0) {
      cout<<"Please input your username: ";
      cin>> user_in;

      cout<<"Please input your password: ";
      cin>> pass;

      bool in_proj = false;;
      for(auto val: proj_1.get_proj_workers()) {
        
        if((val.get_username().compare(user_in) == 0) && (val.get_password().compare(pass)) ==0) {
          in_proj = true;
          u = val;
          break;
        }
      }

      if(in_proj == true) {
        cout<<"You have been successfully logged in."<<endl;
        KanbanBoard kanban;
        kanban.set_current_project(proj_1);
        kanban.set_current_user(u);
        proj_menu(kanban, "proj1.txt");
        
      }
      else {
        cout<<"You are not authorized to log in. Please try again.";
      }

      
    }
    else if(p_name.compare(proj_2.get_name()) == 0) {
      cout<<"Please input your username: ";
      cin>> user_in;

      cout<<"Please input your password: ";
      cin>> pass;

      bool in_proj = false;;
      for(auto val: proj_2.get_proj_workers()) {
        if((val.get_username().compare(user_in) == 0) && (val.get_password().compare(pass)) ==0) {
          
          in_proj = true;
          u = val;
          
          break;
        }
      }

      if(in_proj == true) {
        cout<<"You have been successfully logged in.";
        KanbanBoard kanban;
        kanban.set_current_project(proj_2);
        kanban.set_current_user(u);
        proj_menu(kanban, "proj2.txt");
        
      }
      else {
        cout<<"You are not authorized to log in. Please try again.";
      }

      
    }

    else if(p_name.compare("quit") == 0) {
      running = false;
      
    }
   
    else {
      cout<<"Project name invalid, please your spelling and try again.";
    }
   
    }      
  }


