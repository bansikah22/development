package com.bansikah.employee;

import java.util.ArrayList;

public class Developer extends Employee {

    private String programmingLanguage;
    ArrayList<String> projects;

    public Developer(String name, int age, String department, double salary, String programmingLanguage) {
        super(name, age, department, salary);
        this.programmingLanguage = programmingLanguage;
        this.projects = new ArrayList<>();
    }


    public String getProgrammingLanguage() {
        return this.programmingLanguage;
    }

    public void setProgrammingLanguage(String programmingLanguage) {
        this.programmingLanguage = programmingLanguage;
    }

    public ArrayList<String> getProjects() {
        return this.projects;
    }

    public void setProjects(ArrayList<String> projects) {
        this.projects = projects;
    }

    @Override
    public String toString() {
        return "{" +
            " programmingLanguage='" + getProgrammingLanguage() + "'" +
            ", projects='" + getProjects() + "'" +
            "}";
    }

}