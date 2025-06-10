package com.bansikah.employee;

public class Intern extends Employee {
    private String university;
    private int internshipDuration;

    public Intern(String name, int age, String department, double salary, String university, int internshipDuration) {
        super(name, age, department, salary);
        this.university = university;
        this.internshipDuration = internshipDuration;
    }


    public String getUniversity() {
        return this.university;
    }

    public void setUniversity(String university) {
        this.university = university;
    }

    public int getInternshipDuration() {
        return this.internshipDuration;
    }

    public void setInternshipDuration(int internshipDuration) {
        this.internshipDuration = internshipDuration;
    }


    @Override
    public String toString() {
        return "{" +
            " university='" + getUniversity() + "'" +
            ", internshipDuration='" + getInternshipDuration() + "'" +
            "}";
    }

}