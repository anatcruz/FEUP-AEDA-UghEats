#ifndef AEDA_UGHEATS_WORKER_H
#define AEDA_UGHEATS_WORKER_H

#include <string>
#include <vector>
#include "Time.h"
#include "Order.h"
#include "../utils.h"


class Order;
class Delivery;
class Base;

using namespace std;

class Worker {
protected:
    /** Worker's name.
*/
    string name;
    /** Worker's nif.
*/
    int nif;
    /** Worker's date of birth.
*/
    Date birthdate;
    /** Worker's salary.
*/
    double salary;
    /** The Base the Worker works in.
*/
    Base* base;
    /** Bool that represents if the Worker ir currently working or is a former Worker.
*/
    bool working;
public:
    /** Default Constructor.
*/
    Worker();

    /** Constructor of a Worker from the name, nif, date of birth, salary, base and the bool working given.
     */
     Worker(string name, int nif, Date birthdate, double salary, Base *base, bool working);

    //Metodos Set

    /** Sets the name of a Worker.
       * @param name is the parameter you want the new Worker to have.
*/
    void setWorkerName(string name);

    /** Sets the nif of a Worker.
       * @param nif is the parameter you want the new Worker to have.
*/
    void setWorkerNif(int nif);

    /** Sets the date of birth of a Worker.
       * @param birthdate is the parameter you want the new Worker to have.
*/
    void setWorkerBirthdate(Date birthdate);

    /** Sets the salary of a Worker.
       * @param salary is the parameter you want the new Worker to have.
*/
    void setWorkerSalary(double salary);

    /** Sets the base of a Worker.
       * @param base is the parameter you want the new Worker to have.
*/
    void setWorkerBase(Base* base);

    /** Sets the bool working of a Worker.
       * @param working is the parameter you want the new Worker to have.
*/
    void setWorking(bool working);

    //Metodos Get

    /**
      * @return the Worker's name.
*/
    string getWorkerName() const;

    /**
      * @return the Worker's nif.
*/
    int getWorkerNif() const;

    /**
      * @return the Worker's date of birth.
*/
    Date getWorkerBirthdate() const;

    /**
      * @return the Worker's salary.
*/
    double getWorkerSalary() const;

    /**
      * @return the pointer to the Worker's Base.
*/
    Base* getWorkerBase() const;

    /**
     * @return whether the Worker is currently working or not.
*/
    bool getWorking() const;

    //Other Methods
    /** Displays the Worker in a nice format.
      * @param out is the ostream.
     */
    virtual void print(ostream &out) const;
};

class Admin: public Worker {
protected:
    /** The job description of the Admin.
*/
    string description;
public:
    /** Default Constructor.
*/
    Admin() = default;

    /** Constructor of an Admin from the name, nif, date of birth, salary, base, bool working and description given.
*/
    Admin(string name, int nif, Date birthdate, double salary,Base *base, bool working, string description);

    //Metodos Set

    /** Sets the job description of an Admin.
       * @param description is the parameter you want the new Admin to have.
*/
    void setWorkerDescription(string description);

    //Metodos Get

    /**
      * @return the Admin's job description.
*/
    string getWorkerDescription() const;

    //Other Methods
    /** Displays the Admin in a nice format.
      * @param out is the ostream.
      * @param admin is the Admin you want to display.
     */
    friend ostream& operator<<(ostream& out, const Admin &admin);
};

class Deliveryperson: public Worker {
protected:
    /** Each Deliveryperson is assigned a Vehicle for the deliveries.
*/
    string vehicle;
public:
    /** Default Constructor.
*/
    Deliveryperson() = default;

    /** Constructor of a Deliveryperson from the name, nif, date of birth, salary, base, bool working and Vehicle given.
 */
    Deliveryperson(string name, int nif, Date birthdate, double salary,Base* base, bool working, string vehicle);

    //Metodos Set

    /** Sets the Vehicle of a Deliveryperson.
       * @param vehicle is the parameter you want the new Deliveryperson to have.
*/
    void setVehicle(string vehicle);

    //Metodos Get

    /**
      * @return the Deliveryperson's Vehicle.
*/
    string getVehicle() const;

    /**
      * @return all the deliveries done by a Deliveryperson.
*/
    vector<Delivery*> getDeliveries() const;

    /**
      * @return the money the Deliveryperson should receive depending on his deliveries.
*/
    double getDeliveryEarnings() const;

    /**Checks if a Deliveryperson is available or doing a delivery.
      * @return true is the Deliveryperson is available.
*/
    bool isAvailable() const;

    //Other Methods
    /** Displays the Deliveryperson in a nice format.
      * @param out is the ostream.
      * @param deliveryperson is the Deliveryperson you want to display.
     */
    friend ostream& operator<<(ostream& out, const Deliveryperson &deliveryperson);
};

class RepairMan: public Worker{
protected:
    /**
     * Time at which a repairman last started a maintenance job
     */
    Time lastMaintenance;
    /** The licence plate of the Vehicle the Repairman is taking for maintenance.
   */
    string licence_plate;
    /** Number of maintenance the Repairman has done.
*/
    int num_maintenance;
public:
    /** Default Constructor.
*/
    RepairMan() = default;

    /** Constructor of a RepairMan from the name, nif, date of birth, salary, base, bool working, licence plate of the Vehicle, time he became unavailable and the number of maintenance he has done.
 */
    RepairMan(string name, int nif, Date birthdate, double salary,Base* base, bool working,Time lastMaintenance,string licence_plate, int num_maintenance);

    //Metodos Set

    /**
     * Sets time at which Repairman last started a maintenance job.
     * @param lastMaintenance is the time the last maintenance started.
     */
    void setTime(Time lastMaintenance);

    /**
     * Sets the licence plate of the Vehicle of a RepairMan.
     * @param licence_plate is the parameter you want the new RepairMan to have.
     */
    void setLicencePlate(string licence_plate);

    /**
     * Sets the number of maintenance done by a RepairMan.
     * @param num_maintenance is the parameter you want the new RepairMan to have.
     */
    void setNumMaintenance(int num_maintenance);

    //Metodos Get

    /**
      * @return the Time the RepairMan became unavailable.
*/
    Time getTime() const;

    /**
      * @return the RepairMan's Vehicle's licence plate.
*/
    string getLicencePlate() const;

    /**
      * @return the RepairMan's number of maintenance made.
*/
    int getNumMaintenance() const;

    //Other Methods
    /** Displays the RepairMan in a nice format.
      * @param out is the ostream.
      * @param repairman is the RepairMan you want to display.
     */
    friend ostream& operator<<(ostream& out, const RepairMan &repairman);

    /**Checks if a RepairMan is available or doing a maintenance.
      * @return true is the RepairMan is available.
*/
    bool isAvailable() const;

    /**Compares two repairmen. It is used for ordering the priority queue.
     * In case the time of last maintenance is equal than it compares by the number of maintenance.
      * @return true is the RepairMan is available earlier than the Repairman passed as argument.
*/
    bool operator<(RepairMan* repairman);
};

#endif //AEDA_UGHEATS_WORKER_H
