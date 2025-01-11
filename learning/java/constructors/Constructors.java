public class Constructors{
    public static void main(String[] args){
        Student s1 = new Student("John Doe", 18);
        System.out.println(s1.getName() + " " + s1.getAge());

        Student s2 = new Student("Jane Smith", 22);
        System.out.println(s2.getName() + " " + s2.getAge());
    }
}