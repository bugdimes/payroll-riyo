class Employee
{
private:
    int id;
    string firstName, lastName;
    float rate, hours;

public:
    Employee(
            int id = 0,
            string firstName = "John",
            string lastName = "Doe",
            float rate = 0.0,
            float hours = 0
    ) {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->rate = rate;
        this->hours = hours;
    }

    void setId(int id) {
        this->id = id;
    }

    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setRate(float rate) {
        this->rate = rate;
    }

    void setHours(float hours) {
        this->hours = hours;
    }

    int getId() {
        return this->id;
    }

    string getFirstName() {
        return this->firstName;
    }

    string getLastName() {
        return this->lastName;
    }

    float getRate() {
        return this->rate;
    }

    float getHours() {
        return this->hours;
    }

    float getWage() {
        return this->rate * this->hours;
    }

    friend bool operator == (Employee& emp1, Employee& emp2) {
        if (emp1.getId() == emp2.getId()
            && emp1.getFirstName() == emp2.getFirstName()
            && emp1.getLastName() == emp2.getLastName()
            && emp1.getRate() == emp2.getRate()
            && emp1.getHours() == emp2.getHours())
            return true;
        else
            return false;
    }

    friend bool operator != (Employee& emp1, Employee& emp2) {
        return emp1 == emp2;
    }

    friend istream& operator >> (istream& in, Employee employee) {
        int id;
        string firstName, lastName;
        float rate, hours;
        in>>id>>firstName>>lastName>>rate>>hours;
        employee.setId(id);
        employee.setFirstName(firstName);
        employee.setLastName(lastName);
        employee.setRate(rate);
        employee.setHours(hours);
        return in;
    }

    friend ostream& operator << (ostream& cout, Employee employee) {
        cout << employee.getId()
             << '\t' << employee.getFirstName()
             << '\t' << employee.getLastName()
             << '\t' << employee.getRate()
             << '\t' << employee.getHours()
             << '\t' << employee.getWage() << endl;
        return cout;
    }
};