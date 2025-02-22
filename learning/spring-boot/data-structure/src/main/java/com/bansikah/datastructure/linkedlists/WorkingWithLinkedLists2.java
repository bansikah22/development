package com.bansikah.datastructure.linkedlists;

import java.util.LinkedList;
import java.util.ListIterator;

public class WorkingWithLinkedLists2 {
    public static void main(String [] args){

        LinkedList<People> linkedList = new LinkedList<>();
        linkedList.add(new People("John", 20));
        linkedList.add(new People("Jane", 25));
        linkedList.add(new People("Noel", 22));
        linkedList.add(new People("Draxler", 30));
        ListIterator<People> listIterator = linkedList.listIterator();
        while (listIterator.hasNext()){
            System.out.println(listIterator.next());
        }

        System.out.println(linkedList.size());
        System.out.println(linkedList.get(2));
        System.out.println(linkedList.contains(new People("John", 20)));

    }
    record People(String name, int age) {}
}
