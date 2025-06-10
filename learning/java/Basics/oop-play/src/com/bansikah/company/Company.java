package com.bansikah.company;

import java.util.List;

public class Company{

    private String companyName;
    private List<Department> departments;

    
    public Company(String companyName, List<Department> departments) {
        this.companyName = companyName;
        this.departments = departments;
    }


    public String getCompanyName() {
        return this.companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public List<Department> getDepartments() {
        return this.departments;
    }

    public void setDepartments(List<Department> departments) {
        this.departments = departments;
    }


    @Override
    public String toString() {
        return "{" +
            " companyName='" + getCompanyName() + "'" +
            ", departments='" + getDepartments() + "'" +
            "}";
    }

}