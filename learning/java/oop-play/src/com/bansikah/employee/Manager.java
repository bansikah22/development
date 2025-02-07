package com.bansikah.employee;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Manager extends Employee{

private int officeNumber;
ArrayList<Employee> subordinates;

public Manager(String name, int age, String department, double salary, int officeNumber) {
    super(name, age, department, salary);
    this.officeNumber = officeNumber;
    this.subordinates = new ArrayList<>();  
}


    public int getOfficeNumber() {
        return this.officeNumber;
    }

    public void setOfficeNumber(int officeNumber) {
        this.officeNumber = officeNumber;
    }

    public ArrayList<Employee> getSubordinates() {
        return this.subordinates;
    }

    public void setSubordinates(List<Employee> subordinates2) {
        this.subordinates = (ArrayList<Employee>) subordinates2;
    }

    public Manager officeNumber(int officeNumber) {
        setOfficeNumber(officeNumber);
        return this;
    }

    public Manager subordinates(ArrayList<Employee> subordinates) {
        setSubordinates(subordinates);
        return this;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Manager)) {
            return false;
        }
        Manager manager = (Manager) o;
        return officeNumber == manager.officeNumber && Objects.equals(subordinates, manager.subordinates);
    }

    @Override
    public int hashCode() {
        return Objects.hash(officeNumber, subordinates);
    }

    @Override
    public String toString() {
        return "{" +
            " officeNumber='" + getOfficeNumber() + "'" +
            ", subordinates='" + getSubordinates() + "'" +
            "}";
    }
   

}