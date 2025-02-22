package com.bansikah.datastructure.sets;

import java.util.HashSet;
import java.util.Set;

public class WorkingWithSets2 {
    public static void main(String [] args) {
      Set<Ball> balls = Set.of(
              new Ball("Red"),
              new Ball("Blue"),
              new Ball("Blue"),// added on purpose to show that it will not be added to the set
              new Ball("Green")
      );

        for (Ball ball : balls) {
            System.out.println(ball);
        }

        System.out.println(balls.size());

        System.out.println(balls.contains(new Ball("Red")));

        // Using HashSet
        Set<Ball> balls2 = new HashSet<>();
        balls2.add(new Ball("Red"));
        balls2.add(new Ball("Blue"));
        balls2.add(new Ball("Green"));

        for (Ball ball : balls2) {
            System.out.println(ball);
        }
    }

    //if we want to add something into the sets then we need to override the equals and hashcode method in our class
    public static class Ball{
        String color;

        public Ball(String color){
            this.color = color;
        }

        @Override
        public boolean equals(Object o){
            if(this == o) return true;
            if(o == null || getClass() != o.getClass()) return false;
            Ball ball = (Ball) o;
            return color.equals(ball.color);
        }

        @Override
        public String toString(){
            return "Ball{" +
                    "color='" + color + '\'' +
                    '}';
        }
    }

   // record Ball(String color) {}
}
