# TrackStudio
This is a fictional project that aims to showcase Elder Benassi's technical knowledge as a candidate for the Webtec Visual C++ developer job position.

## Purpose
TrackStudio is a Windows application developed in Visual C++, designed to display a virtual synoptic panel of train compositions on a map. Active trains on the track should be visible on the map, with their positions relative to their actual locations on the track. Object entities should be modeled to handle basic characteristics of locomotives, cars, and their cargo. All dynamic data should be stored in a SQL-like database with corresponding entity-relationship mapping from the class models. Updates to the database records should reflect in the visualization on the synoptic panel.

## Technical Resources
- Dell Latitude PC
- Microsoft Visual Studio 2022 Community Edition
- Trello workspace
- GitHub repository
- Git client app (SourceTree)

## Human Resources and Roles
- Elder Benassi
	* Product Owner
	* Software Architect
	* Software Developer
- Hiring Committee
	* Customer
	* Product Management

## Tasks
Tasks backlog and their progress should be managed using a Kanban panel in Trello [here:](https://trello.com/b/AD9jtz18/wabtec-track-studio-visual-c-developer-demo)
Only the Product Owner (PO) can add tasks to the backlog. Requests for new features should be agreed upon by the PO and PM.

## Standards
Code styling should adhere to the [Google C++ Styleguide](https://google.github.io/styleguide/cppguide.html).

## Schedule 
The maximum labor hours available for this project is 40 hours. All tasks should be planned to fit within this timeframe. 

### Milestones and Estimated Time Share
- Class and Database modeling (30%)
- Application can display the map and enabled train compositions (40%)
- Trains move on the synoptic panel based on updates to their positions in the database records (30%)
- Stretch Goals
	- Show additional information about compositions on mouse hovering
	- Enable automatic composition movement based on speed information rather than position
	- Collision prediction and alert system

### Definition of Done
This project will be considered complete upon the completion of the final milestone. If the last milestone is not completed according to the predetermined schedule, the project should be considered a failure. A report should be written in such a scenario, covering the root cause of the failure and lessons learned.

## Deliverables
The main deliverables of this project are the executable (.exe) application, along with the database records required to run it. The codebase is also considered a deliverable, as it will be used by the hiring committee to evaluate the candidate.

### Acceptance Criteria
The project will be considered accepted by the PO once the following criteria are met:
[ ] The application runs with the proposed features without any exceptions
[ ] The codebase adheres to the defined guidelines
[ ] The database structure follows the defined guidelines

### Access Control
Full access rights to the repository and other tools should be granted to the PO, Architect, and Developer roles. The hiring committee should be granted read-only access to the repository and Kanban panel until one of the following occurs:
- The hiring committee decides not to proceed with the job candidate
- The PO does not receive any communication from the hiring team for more than 5 working days

## Payments and Licensing
Considering this is a demo project for the hiring process only, no payments of any kind should be charged. Similarly, all intellectual property rights of this project belong to the job candidate and should not be copied, modified, or used for any purpose other than the evaluation of the job candidacy.
