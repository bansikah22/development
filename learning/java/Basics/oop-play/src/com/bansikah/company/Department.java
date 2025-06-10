package com.bansikah.company;

import java.util.List;

import com.bansikah.employee.Employee;

public class Department{
    //Department attributes
    private String name;
    private List<Employee> employees;

    public Department(String name, List<Employee> employees) {
        this.name = name;
        this.employees = employees;
    }


    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Employee> getEmployees() {
        return this.employees;
    }

    public void setEmployees(List<Employee> employees) {
        this.employees = employees;
    }

    @Override
    public String toString() {
        return "{" +
            " name='" + getName() + "'" +
            ", employees='" + getEmployees() + "'" +
            "}";
    }

    
}