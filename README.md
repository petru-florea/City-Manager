# City Manager
### Revision 1.0

---

<img src="./cityscape-clipart-city-boston-15.png" width='750'>


### Quick summary

Application that can be used for managing buildings and citizens. You can create a settlement which can be a village, a town or a capital, depending on the number and type of buildings. You can also add/remove buildings or people with different statuses in these buildings.

### Input

The lines will be read up to the EOF. A line consists of the following elements:
+ The first word will be the action you want to take. This command can be **add** or **remove**.
+ The second word is what you want to add or delete. Buildings can only be added, not deleted, and people support both commands.
    - If we want to add a building, this second word can be one of the following words **CityHall**, **Hospital**, **PoliceStation**, **House** or **Block**.
    - If we want to add or delete a certain person in a building, this second word can be one of the following words: **coordinator**, **employee** or **citizen**. For each type of building, these words have different meanings as follows:
      + only mayors, homeowners and block administrators can be **coordinators**.
      + only doctors and police officers can be **employees**.
      + **citizens** can only be city hall employees, hospital patients, detainees, residents of houses and residents of blocks.
+ Consider the following possibilities:
  - If we want to add a building, the next entry date will be the name of the building. For houses (House) after the name of the building the next entry will be maximum number of people who can live in that house, and for blocks (Block), after the name of the building, the next entry will be the number of floors and maximum number of people per floor. For example, the line **add ReginaMaria Hospital** must add a hospital named ReginaMaria.
  - If we want to add a person, the next data entry will be the person's name, the person's age, the person's salary, and the name of the building in which we want to add that person. Clearly this depends on the second parameter. As an example, if we have a building called ReginaMaria, this is a hospital, and our line is **add citizen Andrei 23 222.22 ReginaMaria**, it is clear that Andrei will be a patient of the hospital because he has the status of citizen, and the citizens of a hospital are patients, doctors being considered employees. If I wanted the person to be a doctor in the hospital, we would have a line like **add employee Andrei 23 222.22 ReginaMaria**.
  - If we want to delete a person, the next entry data will be the person's name and building name. We will consider that there is no citizen or employee with the same name in the same institution. For example, if we have a command **remove citizen Andrei ReginaMaria**, patient Andrei will be removed from ReginaMaria Hospital.

### Output

The output will consist of a settlement statistic created using these buildings as follows:

**Type**: type of settlement. It can be "Village", "Town" or "Capital". In order to know what type of settlement we have, we will consider:
  + Capital: CityHall >=3, Hospital >= 2, PoliceStation >= 3, House >= 8, Block >= 4.
  + City: CityHall >=2, Hospital >= 1, PoliceStation >= 2, House >= 4, Block >= 1.
  + Village: Anything but the above conditions.

**Number of patients in hospitals**: the total number of patients in all hospitals.

**Average salary for doctors**: the average salary of all doctors in all hospitals.

**Average salary for cops**: the average salary of all police officers in all police stations.

**Average salary for mayors**: the average salary of all mayors in all city halls.

**Average salary for city hall employees**: the average salary of all employees in all city halls.

**Average age of busted in police stations**: average age of all arrested persons in all police stations.

**Number of people in House *house_name***: the number of people in that house, including the owner if any.

**Number of people in Block *block_name***: the number of people in that block, including the administrator if any.

**House and block administrators**: the names of people who are both block and house administrators. If there is no one, the word *Nobody* will be used.
