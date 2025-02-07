package com.bansikah;

import java.util.ArrayList;
import java.util.List;

import com.bansikah.company.Company;
import com.bansikah.company.Department;
import com.bansikah.employee.Employee;
import com.bansikah.employee.Manager;
import com.bansikah.employee.Developer;
import com.bansikah.employee.Intern;


public class Main{
    public static void main(String[] args) throws Exception {
        
        //create employees
       Employee empl1 = new Developer("Noel", 30,"IT", 50000, "Java");
       Employee emp2 = new Developer("Bob", 28, "IT", 48000, "Python");
       Employee emp3 = new Intern("Charlie", 22, "IT", 20000, "MIT", 6);
       Manager manager = new Manager("David", 40, "IT", 70000, 101);

       // creating a department and adding employees
       List<Employee> itEmployees = new ArrayList<Employee>();
       itEmployees.add(empl1);
       itEmployees.add(emp2);
       itEmployees.add(emp3);

       // create a list of departments
       List<Department> departments = new ArrayList<Department>();

       // create a company
       Company company = new Company("Bansikah Corp", departments);

       // print the company details
       System.out.println(company);

      //add employeees as surbordinates to the manager
        List<Employee> subordinates = new ArrayList<Employee>();
        subordinates.add(empl1);
        subordinates.add(emp2);
        subordinates.add(emp3);

        // Assign subordinates to manager
        manager.setSubordinates(subordinates);

        // Print manager details
        System.out.println(manager);


    }
}